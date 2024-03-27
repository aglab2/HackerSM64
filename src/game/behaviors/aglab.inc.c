#include <game/print.h>

#define MAX_POWER 120
#define MIN_POWER 20

#define Y_PROBE_LENGTH 50.f
#define Y_PROBE_COUNT 10
#define Y_PROBE_HEIGHT 200.f

static int gCurrentHole = 0;
static int gPower = (MAX_POWER + MIN_POWER) / 2;
static int gAmountOfShots = 0;

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

static int applyPowerToVisuals()
{
    Vtx* vtx = segmented_to_virtual(powerbar_Plane_mesh_vtx_0);
    vtx[0].v.ob[2] = 4005 + (23205 - 4005) * gPower / MAX_POWER;
    vtx[3].v.ob[2] = 4005 + (23205 - 4005) * gPower / MAX_POWER;
    
    vtx[0].v.tc[1] = 8176 + (-16 - 8176) * gPower / MAX_POWER;
    vtx[3].v.tc[1] = 8176 + (-16 - 8176) * gPower / MAX_POWER;
}

extern struct LakituState gLakituState;
extern Vtx powerbar_Plane_mesh_vtx_0[4];
void bhv_ctl_init()
{
    obj_scale(o, 0.02f);
    applyPowerToVisuals();
}

extern s16 s8DirModeBaseYaw;
extern s16 s8DirModeYawOffset;
void bhv_ctl_loop()
{
    int allowedButtons = L_CBUTTONS | R_CBUTTONS | JPAD_BUTTONS | R_TRIG;
    int zTrigPressed = gMarioStates->controller->buttonPressed & Z_TRIG;
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

    if (0 == o->oAction)
    {
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

        if (zTrigPressed)
        {
            o->oAction = 1;
            set_mario_action(gMarioStates, ACT_DIVE, 0);
            gMarioStates->forwardVel = gPower;
        }
    }
    else if (1 == o->oAction)
    {
        if (gMarioStates->action == ACT_IDLE)
        {
            o->oAction = 0;
        }
    }
}
