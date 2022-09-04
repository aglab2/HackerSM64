static f32 sSpiderHawk0Start[] = { 3215.f, 213.f, 523.f };
static f32 sSpiderHawk0End[]   = { 4818.f, 213.f, 3394.f };
static f32 sSpiderHawk1Start[] = { -3771.f, 149.f, -3177.f };
static f32 sSpiderHawk1End[]   = { -3839.f, 117.f, -5505.f };
static f32 sSpiderHawk2Start[] = { -6808.8, 59.f, -8710.f };
static f32 sSpiderHawk2End[]   = { -6418.f, 1383.f, -6442.f };
static f32 sSpiderHawk3Start[] = { -5143.f, 1483.f, -5056.f };
static f32 sSpiderHawk3End[]   = { -4992.f, 3450.f, -5477.f };
static f32 sSpiderHawk4Start[] = { -1910.f, -471.f, -5175.f };
static f32 sSpiderHawk4End[]   = { -1490.f, 2344.f, -2564.f };
static f32 sSpiderHawk5Start[] = { -9939.f, 1366.f, 4669.f };
static f32 sSpiderHawk5End[]   = { -10134.f, 811.f, 5362.f };

static f32* sSpiderHawkStarts[] = {
    sSpiderHawk0Start,
    sSpiderHawk1Start,
    sSpiderHawk2Start,
    sSpiderHawk3Start,
    sSpiderHawk4Start,
    sSpiderHawk5Start,
};

static f32* sSpiderHawkEnds[] = {
    sSpiderHawk0End,
    sSpiderHawk1End,
    sSpiderHawk2End,
    sSpiderHawk3End,
    sSpiderHawk4End,
    sSpiderHawk5End,
};

#define RING_BUFFER_SIZE 8
struct SpiderSafePositionsPos
{
    f32 x;
    f32 y;
    f32 z;
};

struct SpiderSafePositionsRingBuffer
{
    u32 timer;
    struct SpiderSafePositionsPos positions[RING_BUFFER_SIZE];
};

STATIC_ASSERT(sizeof(struct SpiderSafePositionsRingBuffer) <= sizeof(aglabScratch), "Yes");

void bhv_spiders_hawk_init()
{
    if (5 == o->oBehParams2ndByte)
    {
        cur_obj_become_intangible();
    }
    else
    {
        cur_obj_become_tangible();
    }
    o->oSpidersHawkAct = 0;
    f32* start = sSpiderHawkStarts[o->oBehParams2ndByte];
    o->oPosX = start[0];
    o->oPosY = start[1];
    o->oPosZ = start[2];
}

void bhv_spiders_hawk_loop()
{
    if (5 == o->oBehParams2ndByte && o->oDistanceToMario < 200.f && (-1 == o->oIntangibleTimer))
    {
        if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK 
            && cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_044)) {
            set_mario_npc_dialog(MARIO_DIALOG_STOP);
            cur_obj_become_tangible();
        }
    }

    if (0 == o->oAction)
    {
        o->oMoveAngleYaw = approach_s16_symmetric(o->oMoveAngleYaw, o->oAngleToMario, 0x140);
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        if (o->oInteractStatus)
        {
            o->oAction = 1;
            o->oSubAction = 0;
        }
        else
        {
            o->oTimer = 0;
        }

        if (o->oBehParams2ndByte == 4 && gMarioStates->pos[1] < 1315.f)
        {
            f32* start = sSpiderHawkStarts[o->oBehParams2ndByte];
            o->oPosX = start[0];
            o->oPosY = start[1];
            o->oPosZ = start[2];
            o->oSpidersHawkAct = 0;
        }
        if (o->oBehParams2ndByte == 0 && gMarioStates->pos[0] > 4200.f && gMarioStates->pos[2] > 0.f)
        {
            f32* end = sSpiderHawkEnds[o->oBehParams2ndByte];
            o->oPosX = end[0];
            o->oPosY = end[1];
            o->oPosZ = end[2];
            o->oSpidersHawkAct = 1;
        }
        if (o->oBehParams2ndByte == 3 && gMarioStates->pos[1] < 2500.f)
        {
            f32* end = sSpiderHawkStarts[o->oBehParams2ndByte];
            o->oPosX = end[0];
            o->oPosY = end[1];
            o->oPosZ = end[2];
            o->oSpidersHawkAct = 0;
        }
    }
    else
    {
        if (!o->oInteractStatus)
        {
            o->oSubAction = 1;
        }

        f32 frac = o->oTimer / 60.f;
        f32* start;
        f32* end;
        if (0 == o->oSpidersHawkAct)
        {
            start = sSpiderHawkStarts[o->oBehParams2ndByte];
            end   = sSpiderHawkEnds  [o->oBehParams2ndByte];
        }
        else
        {
            start = sSpiderHawkEnds  [o->oBehParams2ndByte];
            end   = sSpiderHawkStarts[o->oBehParams2ndByte];
        }
        o->oPosX = frac * end[0] + (1 - frac) * start[0];
        o->oPosY = frac * end[1] + (1 - frac) * start[1];
        o->oPosZ = frac * end[2] + (1 - frac) * start[2];
        o->oMoveAngleYaw = atan2s(end[2] - start[2], end[0] - start[0]);

        if (o->oTimer > 60) 
        {
            o->oSpidersHawkAct = !o->oSpidersHawkAct;
            if (0 == o->oSubAction)
                gMarioObject->oInteractStatus |= INT_STATUS_MARIO_DROP_FROM_HOOT;

            o->oAction = 0;
        }
    }
}

void bhv_spiders_death_trigger_init()
{
    struct SpiderSafePositionsRingBuffer* rb = (struct SpiderSafePositionsRingBuffer*) aglabScratch;
    rb->timer = 0;
}

void bhv_spiders_death_trigger_loop()
{
    struct SpiderSafePositionsRingBuffer* rb = (struct SpiderSafePositionsRingBuffer*) aglabScratch;
    struct Surface* floor = gMarioStates->floor;
    if (0 == o->oAction)
    {
        if (gMarioStates->pos[1] < o->oPosY)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
            o->oAction = 1;
        }
        else
        {
            if (floor && gMarioStates->floorHeight == gMarioStates->pos[1] && (floor->type == SURFACE_NOT_SLIPPERY || floor->type == 0))
            {
                u32 rbTimer = rb->timer % 8;
                rb->positions[rbTimer].x = gMarioStates->pos[0];
                rb->positions[rbTimer].y = gMarioStates->pos[1];
                rb->positions[rbTimer].z = gMarioStates->pos[2];
                rb->timer++;
            }
        }
    }
    else
    {
        if (o->oTimer == 12)
        {
            u32 rbTimerLast = rb->timer % 8;
            gMarioStates->pos[0] = rb->positions[rbTimerLast].x;
            gMarioStates->pos[1] = rb->positions[rbTimerLast].y + 100.f;
            gMarioStates->pos[2] = rb->positions[rbTimerLast].z;
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
        }
        if (o->oTimer == 13)
        {
            reset_camera(gCamera);
        }
        if (o->oTimer == 14)
        {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0,0,0);
            o->oAction = 0;
        }
    }
}

void bhv_spiders_gate_switch_loop()
{
    if (0 == o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            o->oAction = 1;
            play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
            obj_scale_xyz(o, 1.f, 0.1f, 1.f);
        }
    }
}

void bhv_spiders_cage_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSpidersGateSwitch, &d);
}

void bhv_spiders_cage_loop()
{
    if (1 == o->parentObj->oAction)
    {
        o->activeFlags = 0;
    }
}
