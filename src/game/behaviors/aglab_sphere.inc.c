#include "game/color.h"

void bhv_sphere_init()
{
    f32 d;
    o->oGolfSphereStar = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
}


extern Gfx mat_sphere_sphere__8_f3d_layer1[]; // +13
extern Gfx mat_sphere_sphere__3_f3d_layer1[];
extern Gfx mat_sphere_sphere__4_f3d_layer1[];
extern Gfx mat_sphere_sphere__7_f3d_layer1[];
extern Gfx mat_sphere_sphere__6_f3d_layer1[];
extern Gfx mat_sphere_sphere__9_f3d_layer1[];
extern Gfx mat_sphere_sphere__10_f3d_layer1[];
extern Gfx mat_sphere_sphere__11_f3d_layer1[];
extern Gfx mat_sphere_sphere___f3d_layer1[];
extern Gfx mat_sphere_sphere__1_f3d_layer1[];

static void sphere_set_color(void* vptr, rgb* color)
{
    u8* ptr = (u8*) segmented_to_virtual(vptr) + 8*13 + 4;
    ptr[0] = color->r;
    ptr[1] = color->g;
    ptr[2] = color->b;
    ptr[3] = color->a;
}

static void sphere_set_all_colors(rgb* color)
{
    sphere_set_color(mat_sphere_sphere__8_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__3_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__4_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__7_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__9_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__10_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__11_f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere___f3d_layer1, color);
    sphere_set_color(mat_sphere_sphere__1_f3d_layer1, color);
}

extern s16 s8DirModeYawOffset;

u8 gNoInputs = 0;

static s32 sphere_modulate(s16 v)
{
    if (v < 0)
    {
        return -v / 340;
    }
    else
    {
        return v / 340;
    }
}

void bhv_sphere_loop()
{
    if (gMarioStates->action == ACT_STAR_DANCE_EXIT || gMarioStates->action == ACT_FALL_AFTER_STAR_GRAB)
    {
        o->activeFlags = 0;
        return;
    }

    if (0 == o->oAction)
    {
        o->oAction = 1;
    }
    else if (1 == o->oAction)
    {
        gNoInputs = 0;
        o->oFaceAngleYaw += 5 * gPlayer1Controller->stickX;
        o->oFaceAnglePitch += 5 * gPlayer1Controller->stickY;

        o->oGolfSphereStar->oPosX = 2250.f * sins(o->oFaceAngleYaw) * coss(-o->oFaceAnglePitch);
        o->oGolfSphereStar->oPosY = 2250.f                          * sins(-o->oFaceAnglePitch);
        o->oGolfSphereStar->oPosZ = 2250.f * coss(o->oFaceAngleYaw) * coss(-o->oFaceAnglePitch);
        
        u8 yawc = sphere_modulate((s16) o->oFaceAngleYaw);
        u8 pitchc = sphere_modulate((s16) o->oFaceAnglePitch);
        rgb color = { 200 - yawc, 200 - pitchc, yawc + pitchc, 0 };
        sphere_set_all_colors(&color);

        if (gPlayer1Controller->buttonPressed & L_TRIG)
        {
            o->oAction = 2;
            gMarioStates->pos[0] = 0.f;
            gMarioStates->pos[1] = 400.f + find_floor_height(0.f, 9000.f, 0.f); 
            gMarioStates->pos[2] = 0.f;
            gMarioStates->faceAngle[1] = 0.f;
        }
        if (!gCurrCreditsEntry)
            print_text_centered(160, 20, "L TO TRY");
    }
    else if (2 == o->oAction)
    {
        gNoInputs = 1;
        if (gPlayer1Controller->buttonPressed & L_TRIG)
        {
            o->oAction = 1;
            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                o->oAction = 1;
                gMarioStates->pos[0] = 0.f;
                gMarioStates->pos[1] = 550.f;
                gMarioStates->pos[2] = 5211.f;
                gMarioStates->vel[0] = 0.f;
                gMarioStates->vel[1] = 0.f;
                gMarioStates->vel[2] = 0.f;
                gMarioStates->forwardVel = 0;
                drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
                s8DirModeYawOffset = 0;
            }
        }
        print_text_centered(160, 20, "L TO RESET");
    }
}
