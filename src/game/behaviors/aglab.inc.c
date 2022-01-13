void bhv_gate_rotat_ctl_init(void)
{
    f32 d;
    o->oGateCtlRotat = cur_obj_find_nearest_object_with_behavior(bhvGateRotat, &d);
    obj_scale(o->oGateCtlRotat, 1.2f);
    o->oGateCtlRotat->oFaceAngleYaw = (0x10000 / 3) * 2;
    o->oGateCtlState = 2;
}

extern Gfx mat_ccm_dl_f3d_material_002[];
extern Texture gate_draw_s1[];
extern Texture gate_draw_s2[];
extern Texture ccm_dl_default_rgba16[];

static Texture* sTextures[] = { gate_draw_s1, gate_draw_s2, ccm_dl_default_rgba16 };

void bhv_gate_rotat_ctl_loop(void)
{
    if (!o->oAction)
    {
        if (gMarioObject->platform == o)
        {
            cur_obj_play_sound_2(SOUND_GENERAL2_ROTATING_BLOCK_CLICK);
            cur_obj_shake_screen(1);
            o->oAction = 1;
            obj_scale_xyz(o, 1.f, 0.1f, 1.f);
            o->oGateCtlState++;
            o->oGateCtlState %= 3;
            o->oGateCtlRotat->oFaceAngleYaw = (0x10000 / 3) * o->oGateCtlState;
            Texture** texture = segmented_to_virtual(mat_ccm_dl_f3d_material_002);
            texture[11] = sTextures[o->oGateCtlState];
        }
    }
    else
    {
        if (o->oTimer < 10)
            return;

        if (gMarioObject->platform != o)
        {
            o->oAction = 0;
            obj_scale_xyz(o, 1.f, 1.f, 1.f);
        }
    }
}

void bhv_gate20_loop()
{
    int cnt = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);
    if (cnt >= 20)
        o->activeFlags = 0;
}

extern Gfx mat_totwc_dl__auto_9_f3d[];
void bhv_rainbow_ctl_loop()
{
    u8* envc = segmented_to_virtual(mat_totwc_dl__auto_9_f3d) + 12 * 8 + 7;
    *envc = (1.5f + sins(o->oTimer * 937)) * 0x40;
}

void bhv_bitfs_thing_loop()
{
    o->oPosY = o->oHomeY - (1 + sins(o->oTimer * 300)) * 70.f;
}

void bhv_bobomb_fight_ctl_init()
{
    f32 d;
    o->oBobombCtlMain = cur_obj_find_nearest_object_with_behavior(bhvKingBobomb, &d);
}

void bhv_bobomb_fight_ctl_loop()
{
    o->oBobombCtlTimer++;
    struct Object* b = o->oBobombCtlMain;

    if (0 == o->oAction)
    {
        b->oInteractionSubtype |= INT_SUBTYPE_NOT_GRABBABLE;
        if (b->oAction == 2 && b->oKingBobombShouldStomp == 2 && b->oHealth == 3)
        {
            o->oAction = 1;
        }
    }
    if (1 == o->oAction)
    {
        f32 dtc = b->oPosX * b->oPosX + b->oPosZ * b->oPosZ;
        if (dtc < 800.f * 800.f)
        {
            b->oPosZ += 40.f;
        }
        else
        {
            o->oAction = 2;
        }
    }
    if (2 == o->oAction)
    {
        if (o->oTimer > 0x5f)
        {
            b->oInteractionSubtype &= ~INT_SUBTYPE_NOT_GRABBABLE;
            o->oAction = 3;
            return;
        }
        if ((o->oTimer % 0x20) == 0)
        {
            int i = o->oTimer / 0x20;
            struct Object** fakes = &o->oBobombCtlFake1;
            fakes[i] = spawn_object(b, 0xf3, bhvKingBobombFaker);
            fakes[i]->oAction = 2;
            fakes[i]->oKingBobombShouldStomp = 2;
            fakes[i]->oInteractionSubtype |= INT_SUBTYPE_NOT_GRABBABLE;
        }
        o->oFaceAngleYaw += 0x200;
        b->oFaceAngleYaw = o->oFaceAngleYaw;
        b->oPosX = 800.f * sins(b->oFaceAngleYaw);
        b->oPosZ = 800.f * coss(b->oFaceAngleYaw);
    }
    if (3 == o->oAction)
    {
        if (b->oHealth == 2 && (o->oTimer % 20) == 0)
        {
            struct Object* flameObj = spawn_object(b, MODEL_RED_FLAME, bhvBouncingFireballFlame);
            f32 scale = 6.f;

            obj_scale(flameObj, scale);
            obj_become_tangible(flameObj);
        }
        if (b->oHealth == 1)
        {
            struct Object** fakes = &o->oBobombCtlFake1;
            for (int i = 0; i < 4; i++)
            {
                if (fakes[i])
                {
                    fakes[i]->oInteractionSubtype &= ~INT_SUBTYPE_GRABS_MARIO;
                    fakes[i]->oInteractType = 0;
                    push_mario_out_of_object(gMarioStates, fakes[i], -5.0f);
                }
            }
        }
        if (b->oAction == 8)
        {
            struct Object** fakes = &o->oBobombCtlFake1;
            for (int i = 0; i < 4; i++)
            {
                if (fakes[i])
                {
                    fakes[i]->activeFlags = 0;
                    struct Object *explosion = spawn_object(fakes[i], MODEL_EXPLOSION, bhvExplosion);
                    explosion->oGraphYOffset += 100.0f;
                }
            }
            o->activeFlags = 0;
        }
    }
}

void bhv_fight_ctl_loop()
{
    if (0 == o->oAction)
    {
        f32 dx = o->oPosX - gMarioObject->oPosX;
        f32 dz = o->oPosZ - gMarioObject->oPosZ;
        f32 dtm = dx*dx + dz*dz;
        if (o->oTimer > 100 && dtm > 250000.f)
        {
            o->oAction = 1;
        }
    }
    else if (1 == o->oAction)
    {
        int timeLeft = 3600 - o->oTimer;
        if (0 == timeLeft)
        {
            level_trigger_warp(gMarioStates, 19);
            o->activeFlags = 0;
        }
        if (gMarioStates->action == ACT_FALL_AFTER_STAR_GRAB)
        {
            o->oFightCtlTimerLeft = timeLeft;
            o->oAction = 2;
        }
        int f = 3 * (timeLeft % 30);
        int s = (timeLeft / 30) % 60;
        int m = timeLeft / 60 / 30;
        
        print_text_fmt_int(120, 20, "%d", m);
        print_text_fmt_int(140, 20, "%02d", s);
        print_text_fmt_int(170, 20, "%02d", f);
    }
    else if (2 == o->oAction)
    {
        int timeLeft = o->oFightCtlTimerLeft;
        int f = 3 * (timeLeft % 30);
        int s = (timeLeft / 30) % 60;
        int m = timeLeft / 60 / 30;
        
        print_text_fmt_int(120, 20, "%d", m);
        print_text_fmt_int(140, 20, "%02d", s);
        print_text_fmt_int(170, 20, "%02d", f);
    }
}

extern Gfx mat_ccm_dl___f3d_layer1[];
extern Gfx mat_ccm_dl__2_f3d_layer1[];
extern Gfx mat_ccm_dl__3_f3d_layer1[];
extern Gfx mat_ccm_dl__1_f3d_layer1[];
extern Gfx mat_ccm_dl__10_f3d_layer1[];
extern Gfx mat_ccm_dl__12_f3d_layer1[];
void bhv_warp_gate_block_loop()
{
    u8 envcolor = (1 + sins(o->oTimer * 0x200)) * 30;
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl___f3d_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl__2_f3d_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl__3_f3d_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl__1_f3d_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl__10_f3d_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl__12_f3d_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    if (gEnvironmentRegions[6] > 0.0f)
    {
        if (gMarioStates->pos[0] > o->oPosX)
        {
            gMarioStates->pos[0] = o->oPosX;
        }
        cur_obj_unhide();
    }
    else
    {
        cur_obj_hide();
    }
}

extern Gfx mat_jrb_dl_f3d_material[];
void bhv_wall_ctl_loop()
{
    s16 coll = gMarioStates->floor ? gMarioStates->floor->type : 0;
    u8* envc = segmented_to_virtual(mat_jrb_dl_f3d_material) + 19 * 8 + 7;
    
    if (o->oWallCtlLastFrameColl != coll)
        o->oWallCtlPrevColl = o->oWallCtlLastFrameColl;

    o->oWallCtlLastFrameColl = coll;

    if (coll == SURFACE_HARD || (o->oWallCtlPrevColl == SURFACE_HARD && coll == SURFACE_BURNING))
    {
        *envc = 0;
    }
    else
    {
        *envc = 0xff;
    }
}

extern void bhv_pipe_raiser_init()
{
    f32 d;
    o->oPipeRaiserPipe = cur_obj_find_nearest_object_with_behavior(bhvWarpPipe, &d);
}

extern void bhv_pipe_raiser_loop()
{
    if (gCurrActNum == 6)
    {
        o->oPipeRaiserPipe->oPosX = o->oPosX;
        o->oPipeRaiserPipe->oPosY = o->oPosY;
        o->oPipeRaiserPipe->oPosZ = o->oPosZ;
        o->oAction = 1;
    }

    if (0 == o->oAction)
    {
        if (o->oDistanceToMario > 500.f)
            return;

        if (gMarioStates->action == ACT_EMERGE_FROM_PIPE)
        {
            o->oAction = 1;
            o->oPipeRaiserPipe->oPosX = o->oPosX;
            o->oPipeRaiserPipe->oPosZ = o->oPosZ;
        }
    }
    else
    {
        o->oPipeRaiserPipe->oPosY += 10.f;
        if (o->oPipeRaiserPipe->oPosY > o->oPosY)
        {
            o->oPipeRaiserPipe->oPosY = o->oPosY;
            o->activeFlags = 0;
        }
    }
}

#define CREDITS_SIZE 8
extern const char* gCreditsStr[CREDITS_SIZE];
extern int gCreditsLength[CREDITS_SIZE];
extern int gCreditsAlign[CREDITS_SIZE];
extern u8 gCreditsEnvColor[CREDITS_SIZE];
extern int gCreditsPosX[CREDITS_SIZE];
extern int gCreditsPosY[CREDITS_SIZE];
extern s32 gCreditsLastSize;

void bhv_peach_ending_cs_init()
{
    gCamera->cutscene = CUTSCENE_INTRO_PEACH;
}

static void fade_in_text(int i)
{
    if (gCreditsEnvColor[i] < 240)
    {
        gCreditsEnvColor[i] += 10;
    }
    else
    {
        gCreditsEnvColor[i] = 250;
    }
}

static void fade_out_text(int i)
{
    if (gCreditsEnvColor[i] > 10)
    {
        gCreditsEnvColor[i] -= 10;
    }
    else
    {
        gCreditsEnvColor[i] = 0;
    }
}

static void fade_out_all()
{
    for (int i = 0; i < 8; i++)
    {
        fade_out_text(i);
    }
}

static void set_text(int i, const char* line, int length, int align, int x, int y)
{
    gCreditsStr[i] = line;
    gCreditsLength[i] = length;
    gCreditsAlign[i] = align;
    gCreditsPosX[i] = x;
    gCreditsPosY[i] = y;
}

// couple spaces for laziness
static const char sThanksYou[] = "Thank you for playing      ";

static void fade_in_text_fast(int i)
{
    if (gCreditsEnvColor[i] < 225)
    {
        gCreditsEnvColor[i] += 25;
    }
    else
    {
        gCreditsEnvColor[i] = 250;
    }
}

void bhv_peach_ending_cs_loop()
{
    gCamera->cutscene = CUTSCENE_INTRO_PEACH;
    if (gMarioObject) 
        gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;

    gHudDisplay.flags = HUD_DISPLAY_NONE;
    gMarioStates->health = 0x880;

    if (o->oTimer < 45)
    {
        set_text(0, "ESCAPE FROM THE JAIL", -1, 1, 160, 100);
        fade_in_text(0);
    }
    else if (o->oTimer < 90)
    {
        set_text(1, "DEFINITIVE EDITION", -1, 1, 160, 120);
        fade_in_text(1);
    }
    else if (o->oTimer < 150)
    {
        set_text(2, "Made by aglab2", -1, 1, 160, 140);
        fade_in_text(2);
    }
    else if (o->oTimer < 200)
    {
        fade_out_all();
    }
    else if (o->oTimer < 230)
    {
        set_text(0, "ORIGINAL HACK", -1, 1, 160, 110);
        fade_in_text(0);
    }
    else if (o->oTimer < 300)
    {
        set_text(1, "TheGael95", -1, 1, 160, 130);
        fade_in_text(1);
    }
    else if (o->oTimer < 350)
    {
        fade_out_all();
    }
    else if (o->oTimer < 370)
    {
        set_text(0, "TOOLS USED", -1, 1, 160, 100);
        fade_in_text(0);
    }
    else if (o->oTimer < 450)
    {
        set_text(1, "HackerSM64", -1, 0, 80, 120);
        fade_in_text(1);
        set_text(2, "Blender", -1, 0, 80, 140);
        fade_in_text(2);
        set_text(3, "Sketchup", -1, 2, 220, 120);
        fade_in_text(3);
        set_text(4, "Fast64", -1, 2, 220, 140);
        fade_in_text(4);
    }
    else if (o->oTimer < 500)
    {
        fade_out_all();
    }
    else if (o->oTimer < 530)
    {
        set_text(0, "TESTING", -1, 1, 160, 110);
        fade_in_text(0);
    }
    else if (o->oTimer < 600)
    {
        set_text(1, "ZenonX", -1, 0, 80, 130);
        fade_in_text(1);
        set_text(3, "Crash", -1, 2, 220, 130);
        fade_in_text(3);
    }
    else if (o->oTimer < 650)
    {
        fade_out_all();
    }
    else if (o->oTimer < 680)
    {
        set_text(0, "SPECIAL THANKS", -1, 1, 160, 100);
        fade_in_text(0);
    }
    else if (o->oTimer < 750)
    {
        set_text(1, "scuttlebug raiser", -1, 0, 30, 120);
        fade_in_text(1);
        set_text(2, "ArcticJaguar", -1, 0, 30, 140);
        fade_in_text(2);
        set_text(3, "ToasterKetchup", -1, 2, 270, 120);
        fade_in_text(3);
        set_text(4, "octaviosidoni", -1, 2, 270, 140);
        fade_in_text(4);
        set_text(5, "Yoshi Milkman", -1, 0, 30, 160);
        fade_in_text(5);
        set_text(6, "HackerSM64 discord", -1, 2, 270, 160);
        fade_in_text(6);
    }
    else if (o->oTimer < 820)
    {
        fade_out_all();
    }
    else if (o->oTimer < 1010)
    {
        int segTimer = o->oTimer - 820;
        int curLetter = segTimer / 9;
        if (0 == (segTimer % 9))
            gCreditsEnvColor[1] = 0;

        set_text(0, sThanksYou, curLetter, 0, 100, 120);
        set_text(1, sThanksYou + curLetter, 1, 0, 100 + gCreditsLastSize, 120);
        gCreditsEnvColor[0] = 250;
        
        if (0 != (segTimer % 9))
            fade_in_text_fast(1);
    }
    else if (o->oTimer < 1050)
    {
        if (save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= 50)
        {
            set_text(2, "and getting all the stars!", -1, 1, 160, 140);
            fade_in_text(2);
        }
    }
    else
    {
        fade_out_all();
    }
}

extern Gfx mat_bbh_dl__auto_6_f3d[];
void bhv_sand_color_ctl_loop()
{

}

// Only 15 colors here for whatever reason lol
extern u8 wf_dl__11_ci4_pal_rgba16[];
extern u8 wf_dl__09_stone00_2_ci4_pal_rgba16[];
void bhv_snow_color_ctl_init()
{
    // Clear all colors
    {
        u8* ptr = segmented_to_virtual(wf_dl__11_ci4_pal_rgba16);
        for (int i = 0; i < 15; i++)
        {
            ptr[2 * i + 1] &= ~1;
        }
    }
    {
        u8* ptr = segmented_to_virtual(wf_dl__09_stone00_2_ci4_pal_rgba16);
        for (int i = 0; i < 16; i++)
        {
            ptr[2 * i + 1] &= ~1;
        }
    }
}

extern Gfx mat_wf_dl__11_f3d_layer1[];
extern Gfx mat_wf_dl_wall2_layer1[];

void bhv_snow_color_ctl_loop()
{
    {
        u8* ptr = segmented_to_virtual(mat_wf_dl__11_f3d_layer1) + 36 * 8 + 4;
        ptr[0] = 58 / 5 * (1 + sins(o->oTimer * 0x400));
        ptr[1] = 35 / 4 * (1 + sins(o->oTimer * 0x400));
        ptr[2] = 76 / 3 * (1 + sins(o->oTimer * 0x400));
    }
    {
        u8* ptr = segmented_to_virtual(mat_wf_dl_wall2_layer1) + 36 * 8 + 4;
        ptr[0] = 58 / 6 * (1 + sins(o->oTimer * 0x400));
        ptr[1] = 35 / 5 * (1 + sins(o->oTimer * 0x400));
        ptr[2] = 76 / 4 * (1 + sins(o->oTimer * 0x400));
    }

    // do color thingy
    if (48 == (o->oTimer % 64))
    {
        for (int i = 0; i < 4; i++)
        {
            {
                u8* ptr = segmented_to_virtual(wf_dl__11_ci4_pal_rgba16);
                int off = random_u16() % 15;
                u8* bapart = &ptr[2 * off + 1];
                // flip bit, this is slightly scuffed but i cant think of a better way to do this
                u8 bit = *bapart & 1;
                bit ^= 1;
                *bapart &= ~1;
                *bapart |= bit;
            }
            {
                u8* ptr = segmented_to_virtual(wf_dl__09_stone00_2_ci4_pal_rgba16);
                int off = random_u16() % 16;
                u8* bapart = &ptr[2 * off + 1];
                u8 bit = *bapart & 1;
                bit ^= 1;
                *bapart &= ~1;
                *bapart |= bit;
            }
        }
    }
}

extern const Trajectory jrb_area_1_spline_trimo_1[];
extern const Trajectory jrb_area_1_spline_trimo_2[];
void bhv_trimo_init()
{
    o->oForwardVel = 50.f;
}

void bhv_trimo_loop()
{
    if (0 == o->oAction)
    {
        if (o->oTimer == 0)
        {
            struct Waypoint* path = segmented_to_virtual(jrb_area_1_spline_trimo_2);
            path += o->oBehParams2ndByte;
            // very nice culprit
            o->oBehParams2ndByte = 0;
            o->oPathedPrevWaypointFlags = 0;
            o->oPathedStartWaypoint = o->oPathedPrevWaypoint = path;
            o->oPosX = path->pos[0];
            o->oPosZ = path->pos[2];
        }

        cur_obj_follow_path();
        o->oPosY += 10.f / 25.f;
        
        // lazy lmfao
        cur_obj_rotate_yaw_toward(o->oPathedTargetYaw, 10000);
        cur_obj_rotate_face_angle_using_vel();
        obj_scale(o, 0.04f * o->oTimer);
        if (25 == o->oTimer)
            o->oAction = 1;
    }
    else if (1 == o->oAction)
    {
        int status = cur_obj_follow_path();
        if (status == PATH_REACHED_END)
        {
            o->oAction = 2;
        }
        
        cur_obj_rotate_yaw_toward(o->oPathedTargetYaw, 3000);
        cur_obj_rotate_face_angle_using_vel();
        cur_obj_compute_vel_xz();

        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;
    }
    else
    {
        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;
        obj_scale(o, 0.1f * (10 - o->oTimer));
        if (10 == o->oTimer)
        {
            o->oAction = 0;
            o->oPosY -= 10.f;
        }
    }
}

void bhv_trimo_init2()
{
    o->oForwardVel = 50.f;
    o->oPosY += 10.f;
}

void bhv_trimo_loop2()
{
    if (0 == o->oAction)
    {
        if (o->oTimer == 0)
        {
            struct Waypoint* path = segmented_to_virtual(jrb_area_1_spline_trimo_1);
            path += o->oBehParams2ndByte;
            // very nice culprit
            o->oBehParams2ndByte = 0;
            o->oPathedPrevWaypointFlags = 0;
            o->oPathedStartWaypoint = o->oPathedPrevWaypoint = path;
            o->oPosX = path->pos[0];
            o->oPosZ = path->pos[2];
        }

        cur_obj_follow_path();
        o->oAction = 1;
    }
    else
    {
        if (cur_obj_follow_path() == PATH_REACHED_END)
        {
            o->oAction = 0;
        }
    }
    
    cur_obj_rotate_yaw_toward(o->oPathedTargetYaw, 3000);
    cur_obj_rotate_face_angle_using_vel();
    cur_obj_compute_vel_xz();

    o->oPosX += o->oVelX;
    o->oPosZ += o->oVelZ;
}
