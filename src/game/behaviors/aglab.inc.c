#include <game/print.h>

#define MAX_POWER 160
#define MIN_POWER 20

#define Y_PROBE_LENGTH 40.f
#define Y_PROBE_COUNT 12
#define Y_PROBE_HEIGHT 200.f

#define CTL_SHOOT 0
#define CTL_WAIT_FOR_SHOOTING 1
#define CTL_NEXT_HOLE 2

#define TUT_INIT 0
#define TUT_MOVE_CAMERA 1
#define TUT_MOVE_POWER 2
#define TUT_SHOOT 3

#define TEST_SET_HOLE 4

static const int kParShots[] = { 2, 2, 1, 1, 1, 1, 1, 1, 1 };

int gCurrentHoleNum = 0;
unsigned char gTutorialTransparencies[8] = { 255, 0 };
static int gPower = (MAX_POWER + MIN_POWER) / 2;
static int gAmountOfShots = 0;
static int gTutorialProgress = 0;

extern s16 s8DirModeBaseYaw;
extern s16 s8DirModeYawOffset;

void bhv_hole_init()
{

}

void bhv_hole_loop()
{

}

void bhv_start_init()
{

}

void bhv_start_loop()
{

}

extern Vtx powerbar_Plane_mesh_vtx_0[4];
static void applyPowerToVisuals()
{
    Vtx* vtx = segmented_to_virtual(powerbar_Plane_mesh_vtx_0);
    vtx[0].v.ob[2] = 4005 + (23205 - 4005) * gPower / MAX_POWER;
    vtx[3].v.ob[2] = 4005 + (23205 - 4005) * gPower / MAX_POWER;
    
    vtx[0].v.tc[1] = 8176 + (-16 - 8176) * gPower / MAX_POWER;
    vtx[3].v.tc[1] = 8176 + (-16 - 8176) * gPower / MAX_POWER;
}

extern struct LakituState gLakituState;
void bhv_ctl_init()
{
    obj_scale(o, 0.02f);
    applyPowerToVisuals();
    gMarioStates->faceAngle[1] = gLakituState.yaw + 0x8000;
    o->oFaceAngleYaw = gLakituState.yaw + 0x8000;

}

static struct Object* find_object_with_bparam2(const BehaviorScript *behavior, int bparam2)
{
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj->oBehParams2ndByte == bparam2
        ) {
            return obj;
        }

        obj = (struct Object *) obj->header.next;
    }

    return NULL;
}

static struct Object* find_hole_object_with_bparam2(int bparam2)
{
    return find_object_with_bparam2(bhvHole, bparam2);
}

static struct Object* find_init_object_with_bparam2(int bparam2)
{
    return find_object_with_bparam2(bhvInit, bparam2);
}

static void handle_tutorial(int x, int y, int pressedButtons)
{
    if (pressedButtons & Z_TRIG)
    {
        gCurrentHoleNum = 1;
        return;
    }

    if (TUT_INIT == gTutorialProgress)
    {
        if (o->oTimer > 30)
        {
            gTutorialProgress = TUT_MOVE_CAMERA;
        }
    }

    if (TUT_MOVE_CAMERA == gTutorialProgress)
    {
        gTutorialTransparencies[1] = CLAMP(gTutorialTransparencies[1] + 8, 0, 255);
        if (pressedButtons & (L_CBUTTONS | R_CBUTTONS | JPAD_BUTTONS | R_TRIG))
        {
            gTutorialProgress = TUT_MOVE_POWER;
            gTutorialTransparencies[1] = 255;
        }
    }

    if (TUT_MOVE_POWER == gTutorialProgress)
    {
        gTutorialTransparencies[0] = CLAMP(gTutorialTransparencies[0] - 16, 0, 255);
        gTutorialTransparencies[2] = CLAMP(gTutorialTransparencies[2] + 8, 0, 255);
        if (y > 10 || y < -10)
        {
            gTutorialProgress = TUT_SHOOT;
            gTutorialTransparencies[0] = 0;
            gTutorialTransparencies[2] = 255;
        }
    }

    if (TUT_SHOOT == gTutorialProgress)
    {
        gTutorialTransparencies[3] = CLAMP(gTutorialTransparencies[3] + 8, 0, 255);
    }
}

static void handle_content(int x, int y, int pressedButtons)
{
    print_text_fmt_int(20, 60, "ACT %x", gMarioStates->action);
    print_text_fmt_int(20, 80, "P %d", gMarioStates->forwardVel);

    print_text_fmt_int(20, 40, "PAR %d", kParShots[gCurrentHoleNum]);
    print_text_fmt_int(20, 20, "SHOT %d", gAmountOfShots + 1);
    if (CTL_SHOOT == o->oAction)
    {
        struct Object* hole = find_hole_object_with_bparam2(gCurrentHoleNum);
        if (hole)
        {
            if (gMarioStates->pos[1] < hole->oPosY && hole->oDistanceToMario < 100.f)
            {
                o->oAction = CTL_NEXT_HOLE;
            }
        }

        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        o->oPosX = gMarioStates->pos[0];
        o->oPosY = gMarioStates->pos[1];
        o->oPosZ = gMarioStates->pos[2];
        
        gMarioStates->faceAngle[1] = gLakituState.yaw + 0x8000;
        o->oFaceAngleYaw = gLakituState.yaw + 0x8000;

        // iterate for amount of probes
        int baseY = o->oPosY + 130.f;
        for (int i = 0; i < Y_PROBE_COUNT; i++)
        {
            f32 y = find_floor_height(o->oPosX + (1 + i) * Y_PROBE_LENGTH * sins(o->oFaceAngleYaw)
                                    , o->oPosY + Y_PROBE_HEIGHT
                                    , o->oPosZ + (1 + i) * Y_PROBE_LENGTH * coss(o->oFaceAngleYaw));

#if 0
            struct Object* spark = spawn_object(o, MODEL_SPARKLES, bhvSparkle);
            spark->oPosX = o->oPosX + (1 + i) * Y_PROBE_LENGTH * sins(o->oFaceAngleYaw);
            spark->oPosY = y;
            spark->oPosZ = o->oPosZ + (1 + i) * Y_PROBE_LENGTH * coss(o->oFaceAngleYaw);
#endif

            y += 10.f;
            if (y > baseY)
            {
                baseY = y;
            }
        }
        o->oPosY = baseY;

        int yoff = y / 10;
        gPower = CLAMP(gPower + yoff, MIN_POWER, MAX_POWER);
        applyPowerToVisuals();

        if (pressedButtons & Z_TRIG)
        {
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            o->oAction = 1;
            set_mario_action(gMarioStates, ACT_DIVE, 0);
            gMarioStates->forwardVel = gPower;
        }
    }
    else if (CTL_WAIT_FOR_SHOOTING == o->oAction)
    {
        if (gMarioStates->action == ACT_STOMACH_SLIDE_STOP
        || gMarioStates->action == ACT_IDLE)
        {
            gAmountOfShots++;
            o->oAction = 0;
        }
    }
    else if (CTL_NEXT_HOLE == o->oAction)
    {
#ifdef TEST_SET_HOLE
        gCurrentHoleNum = TEST_SET_HOLE;
#else
        gCurrentHoleNum++;
#endif
        struct Object* init = find_init_object_with_bparam2(gCurrentHoleNum);
        if (init)
        {
            gMarioStates->pos[0] = init->oPosX;
            gMarioStates->pos[1] = init->oPosY;
            gMarioStates->pos[2] = init->oPosZ;
            s8DirModeYawOffset = init->oFaceAngleYaw;
        }

        gAmountOfShots = 0;
        o->oAction = 0;
    }
}

void bhv_ctl_loop()
{
    // print_text_fmt_int(20, 20, "A %x", gMarioStates->action);
    int allowedButtons = L_CBUTTONS | R_CBUTTONS | JPAD_BUTTONS | R_TRIG;
    int buttonPressed = gMarioStates->controller->buttonPressed;
    int x = gMarioStates->controller->stickX;
    int y = gMarioStates->controller->stickY;

    gMarioStates->input = 0;
    gMarioStates->controller->rawStickX = 0;
    gMarioStates->controller->rawStickY = 0;
    gMarioStates->controller->stickX = 0;
    gMarioStates->controller->stickY = 0;
    gMarioStates->controller->stickMag = 0;
    gMarioStates->controller->buttonDown &= allowedButtons;
    gMarioStates->controller->buttonPressed &= allowedButtons;
    gMarioStates->health = 0x880;

    if (0 == gCurrentHoleNum)
    {
        handle_tutorial(x, y, buttonPressed);
    }

    handle_content(x, y, buttonPressed);
}
