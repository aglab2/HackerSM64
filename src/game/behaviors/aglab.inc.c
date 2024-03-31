#include <game/print.h>
#include <game/emutest.h>

#define MAX_POWER 160
#define MIN_POWER 20

#define Y_PROBE_LENGTH 50.f
#define Y_PROBE_COUNT 12
#define Y_PROBE_HEIGHT 250.f

#define CTL_SHOOT 0
#define CTL_WAIT_FOR_SHOOTING 1
#define CTL_NEXT_HOLE 2
#define CTL_WAIT_FOR_RESPAWN 3
#define CTL_CREDITS 4
#define CTL_HOLE_CLEAR 5

#define TUT_INIT 0
#define TUT_MOVE_CAMERA 1
#define TUT_MOVE_POWER 2
#define TUT_SHOOT 3

#define MAX_FREEROAM_FRAMES 2000
#define MAX_NO_SPEED_FRAMES 200

// #define DEBUG_INFO
// #define TEST_SET_HOLE 6
// #define TEST_CREDITS

const int kParShots[] = { 0, 3, 2, 3, 3, 5, 4, 3, 3, 3, 1 };
int gScoreboard[16] = { 0 };

int gCurrentHoleNum = 0;
unsigned char gTutorialTransparencies[8] = { 255, 0 };
u8 gRollCredits = 0;
u8 gHideHoleName = 0;
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
extern Vtx powerbar_Plane_mesh_vtx_1[4];
static void applyPowerToVisuals()
{
    // change positions and UVs scaled by gPower
    {
        Vtx* vtx = segmented_to_virtual(powerbar_Plane_mesh_vtx_0);
        vtx[0].v.ob[2] = 4005 + (23205 - 4005) * gPower / MAX_POWER;
        vtx[3].v.ob[2] = 4005 + (23205 - 4005) * gPower / MAX_POWER;
        
        vtx[0].v.tc[1] = 8176 + (-16 - 8176) * gPower / MAX_POWER;
        vtx[3].v.tc[1] = 8176 + (-16 - 8176) * gPower / MAX_POWER;
    }
    {
        Vtx* vtx = segmented_to_virtual(powerbar_Plane_mesh_vtx_1);
        vtx[0].v.ob[2] = 3184 + (4005 + (23205 - 4005) * gPower / MAX_POWER);
        vtx[1].v.ob[2] = 889 + (4005 + (23205 - 4005) * gPower / MAX_POWER);
        vtx[2].v.ob[2] = 1524 + (4005 + (23205 - 4005) * gPower / MAX_POWER);
        vtx[3].v.ob[2] = 889 + (4005 + (23205 - 4005) * gPower / MAX_POWER);

        for (int i = 0; i < 4; i++)
            vtx[i].v.tc[1] = 8176 + 40 + (-16 - 8176) * gPower / MAX_POWER;
    }
}

extern struct LakituState gLakituState;
void bhv_ctl_init()
{
    obj_scale_xyz(o, gIsConsole ? 0.04f : 0.02f, 0.02f, 0.02f);
    applyPowerToVisuals();
    gMarioStates->faceAngle[1] = gLakituState.yaw + 0x8000;
    o->oFaceAngleYaw = gLakituState.yaw + 0x8000;

#ifdef TEST_SET_HOLE
    gCurrentHoleNum = TEST_SET_HOLE;
    o->oAction = CTL_NEXT_HOLE;
#endif
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

#define FRAMES_PER_LETTER 2
// this is not the same as other printFancy, this one uses deferred printing
static void printFancy(int yoff, const char* str, int renderLimit)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    int symbolLen = 11;
    int x = 160 - len * symbolLen / 2;
    for (int i = 0; i < len; i++)
    {
        if ((renderLimit -= FRAMES_PER_LETTER) < 0)
            break;

        int yoff2 = sins(gGlobalTimer * 0x400 + i * 0x700) * 5;

        if (' ' == str[i])
        {
            continue;
        }

        char strProcessed[2] = { str[i], '\0' };
        print_text_centered(x + i * symbolLen, 200 + yoff2 - (yoff ? 20 : 0), strProcessed);
    }
}

extern struct Object* gSpoofedWarpRequester;
static void handle_content(int x, int y, int pressedButtons)
{
    {
        struct Surface* floor = gMarioStates->floor;
        if (floor && floor->type == SURFACE_HARD_VERY_SLIPPERY)
        {
            gMarioStates->forwardVel = 70.f;
            f32 slideVelLen = sqrtf(gMarioStates->slideVelZ * gMarioStates->slideVelZ + gMarioStates->slideVelX * gMarioStates->slideVelX);
            if (slideVelLen > 1.f)
            {
                gMarioStates->slideVelX = gMarioStates->slideVelX / slideVelLen * 70.f;
                gMarioStates->slideVelZ = gMarioStates->slideVelZ / slideVelLen * 70.f;
            }
        }
    }

#ifdef DEBUG_INFO
    print_text_fmt_int(20, 100, "HOLE %d", gCurrentHoleNum);
    print_text_fmt_int(20, 60, "ACT %x", gMarioStates->action);
    print_text_fmt_int(20, 80, "P %d", gMarioStates->forwardVel);
#endif
    if (gCurrentHoleNum <= 10)
    {
        print_text_fmt_int(20, 40, "PAR %d", kParShots[gCurrentHoleNum ? gCurrentHoleNum : 1]);
        print_text_fmt_int(20, 20, "SHOT %d", gAmountOfShots ?: 1);
    }
    
    if (gMarioStates->pos[1] > 5000.f)
    {
        x = 0; y = 0; gPower = 160;
    }

    if (CTL_SHOOT == o->oAction)
    {
        o->oPosX = gMarioStates->pos[0];
        o->oPosY = gMarioStates->pos[1];
        o->oPosZ = gMarioStates->pos[2];

        struct Object* hole = find_hole_object_with_bparam2(gCurrentHoleNum);
        if (hole)
        {
            if (gMarioStates->pos[1] < hole->oPosY && hole->oDistanceToMario < 100.f)
            {
                play_sound(SOUND_GENERAL2_RIGHT_ANSWER, gGlobalSoundSource);
                o->oAction = CTL_HOLE_CLEAR;
                return;
            }
        }

        if (0 == o->oTimer)
        {
            gAmountOfShots++;
        }

        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;

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

            y += (gCurrentHoleNum == 3 ? 30.f : 10.f);
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
            gHideHoleName = 1;
            o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
            o->oAction = 1;
            set_mario_action(gMarioStates, ACT_DIVE, 0);
            gMarioStates->forwardVel = gPower;
        }
    }
    else if (CTL_WAIT_FOR_SHOOTING == o->oAction)
    {
        if (gMarioStates->forwardVel == 0)
        {
            o->oSubAction++;
        }
        else
        {
            o->oSubAction = 0;
        }
        
        f32 distToHole;
        struct Object* hole = find_hole_object_with_bparam2(gCurrentHoleNum);
        if (gMarioObject && hole)
        {
            distToHole = dist_between_objects(gMarioObject, hole);
        }
        else
        {
            distToHole = 0.f;
        }

#ifdef DEBUG_INFO
        print_text_fmt_int(20, 120, "DIST %d", (int)distToHole);
#endif

        int veryFar = gCurrentHoleNum > 9 ? 0 : distToHole > 8100.f;
        int maxFreeroam = gCurrentHoleNum == 9 ? 1200 : MAX_FREEROAM_FRAMES;
        int freeroaming = o->oTimer > maxFreeroam;
        int nospdframes = o->oSubAction > MAX_NO_SPEED_FRAMES;
        if (gMarioStates->action == ACT_STOMACH_SLIDE_STOP
         || gMarioStates->action == ACT_IDLE
         || freeroaming || nospdframes || veryFar)
        {
            struct Surface* floor = gMarioStates->floor;
            if (freeroaming || nospdframes || veryFar || (floor && floor->type != SURFACE_MOVING_QUICKSAND && floor->type != SURFACE_VERY_SLIPPERY && floor->type != SURFACE_NO_CAM_COLLISION && floor->type != SURFACE_SWITCH))
            {
                gSpoofedWarpRequester = o;
                gMarioStates->usedObj = o;
                o->oBehParams = 0xf4 << 16;
                o->oBehParams2ndByte = 0xf4;
                o->oAction = CTL_WAIT_FOR_RESPAWN;
                level_trigger_warp(gMarioStates, WARP_OP_WARP_DOOR);
                play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
            }
            else
            {
                o->oHomeX = gMarioStates->pos[0];
                o->oHomeY = gMarioStates->pos[1];
                o->oHomeZ = gMarioStates->pos[2];
                o->oAction = CTL_SHOOT;
            }
        }
    }
    else if (CTL_NEXT_HOLE == o->oAction)
    {
        gScoreboard[gCurrentHoleNum] = gAmountOfShots;
        gAmountOfShots = 0;
        gHideHoleName = 0;

        gCurrentHoleNum++;
        struct Object* init = find_init_object_with_bparam2(gCurrentHoleNum);
        if (init)
        {
            gMarioStates->pos[0] = init->oPosX;
            gMarioStates->pos[1] = init->oPosY;
            gMarioStates->pos[2] = init->oPosZ;
            if (gCurrentHoleNum == 10)
            {
                if (set_cam_angle(0) == CAM_ANGLE_LAKITU) {
                    set_cam_angle(CAM_ANGLE_LAKITU);
                }
                reset_camera(gCamera);
                // tournament credits song
                seq_player_play_sequence(0, 4, 0);
            }
            s8DirModeYawOffset = init->oFaceAngleYaw;
        }

        if (gCurrentHoleNum == 11)
        {
            gRollCredits = 1;
            gCamera->cutscene = CUTSCENE_GG;
            o->oAction = CTL_CREDITS;
        }
        o->oAction = 0;
    }
    else if (CTL_WAIT_FOR_RESPAWN == o->oAction)
    {
        if (o->oTimer > 20)
        {
            o->oAction = CTL_SHOOT;
            s8DirModeYawOffset = 0x8000 + o->oFaceAngleYaw;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw;
            gMarioStates->pos[1] = find_floor_height(gMarioStates->pos[0], gMarioStates->pos[1], gMarioStates->pos[2]);
        }
    }
    else if (CTL_CREDITS == o->oAction)
    {
        gRollCredits = 1;
        gCamera->cutscene = CUTSCENE_GG;
    }
    else if (CTL_HOLE_CLEAR == o->oAction)
    {
        {
            const char* text;
            if (1 == gAmountOfShots)
            {
                text = "HOLE IN ONE";
            }
            else
            {
                char line[30];
                int diff = CLAMP(3 + kParShots[gCurrentHoleNum] - gAmountOfShots, 0, 6);
                if (0 == diff)
                {
                    sprintf(line, "%d STROKES", gAmountOfShots);
                    text = line;
                }
                else
                {
                    static const char* sTexts[] = {
                        "",
                        "DOUBLE BOGEY",
                        "BOGEY",
                        "PAR",
                        "BIRDIE",
                        "EAGLE",
                        "ALBATROSS",
                    };
                    text = sTexts[diff];
                }
            }
            printFancy(0, text, o->oTimer);
        }
        {
            char line[30];
            int rawDiff = gAmountOfShots - kParShots[gCurrentHoleNum];
            if (rawDiff > 0)
            {
                sprintf(line, "%d OVER PAR", rawDiff);
            }
            else
            {
                sprintf(line, "%d UNDER PAR", -rawDiff);
            }

            if (rawDiff)
                printFancy(1, line, o->oTimer);
        }
        if (o->oTimer >= 50)
        {
            int canWarp = TRUE;
            {
                f32 d;
                struct Object* chuckyaAnchor = cur_obj_find_nearest_object_with_behavior(bhvChuckya, &d);
                if (chuckyaAnchor)
                {
                    canWarp = 0 == chuckyaAnchor->oCommonAnchorAction;
                }
            }

            if (canWarp)
            {
                play_sound(SOUND_MENU_ENTER_HOLE, gMarioStates->marioObj->header.gfx.cameraToObject);
                o->oAction = CTL_NEXT_HOLE;
            }
        }
    }
}

extern void seq_player_play_sequence(u8 player, u8 seqId, u16 arg2);
void bhv_ctl_loop()
{
    // print_text_fmt_int(20, 20, "A %x", gMarioStates->action);
    int allowedButtons = L_CBUTTONS | R_CBUTTONS | JPAD_BUTTONS | R_TRIG;
    if (gMarioStates->pos[1] > 5000.f && CTL_SHOOT == o->oAction)
    {
        allowedButtons = Z_TRIG;
    }
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

#ifdef TEST_CREDITS
    o->oAction = CTL_CREDITS;
    gCurrentHoleNum = 11;
    if (0 == o->oTimer)
        seq_player_play_sequence(0, 4, 0);
#endif

    if (0 == gCurrentHoleNum)
    {
        handle_tutorial(x, y, buttonPressed);
    }

    handle_content(x, y, buttonPressed);
}

void bhv_roll_log_init()
{
    obj_scale_xyz(o, 1.2f, 1.2f, 1.f);
    o->oPosY += 10.f;
}

void bhv_roll_log_loop()
{
    if (gCurrentHoleNum >= 4)
        o->oDrawingDistance = 30000.f;

    if (gMarioStates->pos[1] < -700.f)
    {
        o->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }
    else
    {
        o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        load_object_collision_model();
    }
}