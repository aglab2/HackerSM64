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

s32 gIsKingBuffed = 0;
void bhv_bobomb_fight_ctl_init()
{
    f32 d;
    o->oBobombCtlMain = cur_obj_find_nearest_object_with_behavior(bhvKingBobomb, &d);
    gIsKingBuffed = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) > 50;
}

void bhv_bobomb_fight_ctl_loop()
{
    o->oBobombCtlTimer++;

    if (3100 == o->oBobombCtlTimer)
    {
        seq_player_fade_out(0, 100);
    }
    if (3130 == o->oBobombCtlTimer)
    {
        seq_player_play_sequence(0, SEQ_F2, 0);
        o->oBobombCtlTimer = 0;
    }
    
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
    if (0 == o->oTimer)
    {
        gMarioStates->numCoins = 0;
    }

    if (0 == o->oAction)
    {
        f32 dx = o->oPosX - gMarioObject->oPosX;
        f32 dz = o->oPosZ - gMarioObject->oPosZ;
        f32 dtm = dx*dx + dz*dz;
        if (o->oTimer > 30 && dtm > 250000.f)
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
extern Gfx mat_ccm_dl_side61_layer1[];
extern Gfx mat_ccm_dl_f3d_material_005[];
void bhv_warp_gate_block_loop()
{
    if (0 == o->oTimer)
    {
        gEnvironmentRegions[6] = -435.f;
    }

    f32 off = (1 + sins(o->oTimer * 0x200));
    u8 envcolor = off * 45;
    u8 envcolor2 = off * 30;
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
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl_side61_layer1) + 21 * 8 + 7;
        *envc = envcolor;
    }
    {
        u8* envc = (u8*) segmented_to_virtual(mat_ccm_dl_f3d_material_005) + 12 * 8 + 7;
        *envc = 30 + envcolor2;
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

extern Gfx mat_bbh_dl__auto_9_f3d_layer1[];
void bhv_wall_ctl_c5_loop()
{
    u8* envc = (u8*) segmented_to_virtual(mat_bbh_dl__auto_9_f3d_layer1) + 36 * 8;
    f32 off = (1.f + sins(0x100 * o->oTimer));
    envc[4] = 43 / 2 * off;
    envc[5] = 207 / 2 * off;
    envc[6] = 156 / 2 * off;
}

extern void bhv_pipe_raiser_init()
{
    f32 d;
    o->oPipeRaiserPipe = cur_obj_find_nearest_object_with_behavior(bhvWarpPipe, &d);
}

extern void bhv_pipe_raiser_loop()
{
    int isEndStarObtained = save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(COURSE_BOB)) & 0x4;
    int isSpawnedAtMidpoint = gCurrActNum == 4 || gCurrActNum == 5;

    if (isEndStarObtained && !isSpawnedAtMidpoint)
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

#define CREDITS_SIZE 10
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

extern struct SaveBuffer gSaveBuffer;
static char sGameTime[] = "Game Time: 0:00:00'00";

void bhv_peach_ending_cs_loop()
{
    gCamera->cutscene = CUTSCENE_INTRO_PEACH;
    if (gMarioObject) 
        gMarioObject->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;

    gHudDisplay.flags = HUD_DISPLAY_NONE;
    gMarioStates->health = 0x880;

    if (0 == o->oTimer)
    {
        s32 timeLeft = gSaveBuffer.files[gCurrSaveFileNum - 1][0].timer;
        s32 f = 1.666666666666666f * (timeLeft % 60);
        s32 s = (timeLeft / 60) % 60;
        s32 m = (timeLeft / 60 / 60) % 60;
        s32 h = timeLeft / 60 / 60 / 60;

        sprintf(sGameTime + 10, "%02d", h);
        if (sGameTime[10] == '0')
            sGameTime[10] = ' ';

        sGameTime[12] = ':';
        sprintf(sGameTime + 13, "%02d", m);
        sGameTime[15] = ':';
        sprintf(sGameTime + 16, "%02d", s);
        sGameTime[18] = '\'';
        sprintf(sGameTime + 19, "%02d", f);
    }

    if (o->oTimer < 45)
    {
        set_text(0, "ESCAPE FROM THE JAIL", -1, 1, 160, 100);
        set_text(3, sGameTime, -1, 1, 160, 20);
        fade_in_text(0);
        fade_in_text(3);
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
        set_text(0, "TOOLS USED", -1, 1, 160, 80);
        fade_in_text(0);
    }
    else if (o->oTimer < 450)
    {
        set_text(1, "HackerSM64", -1, 0, 80, 100);
        fade_in_text(1);
        set_text(2, "Blender", -1, 0, 80, 120);
        fade_in_text(2);
        set_text(3, "Sketchup", -1, 2, 220, 100);
        fade_in_text(3);
        set_text(4, "Fast64", -1, 2, 220, 120);
        fade_in_text(4);
        set_text(5, "seq64", -1, 0, 80, 140);
        fade_in_text(5);
        set_text(6, "Anvil Studio", -1, 2, 220, 140);
        fade_in_text(6);
    }
    else if (o->oTimer < 500)
    {
        fade_out_all();
    }
    else if (o->oTimer < 530)
    {
        set_text(0, "TESTING", -1, 1, 160, 80);
        fade_in_text(0);
    }
    else if (o->oTimer < 600)
    {
        set_text(1, "ZenonX", -1, 0, 80, 100);
        fade_in_text(1);
        set_text(2, "Crash", -1, 2, 220, 100);
        fade_in_text(2);
        set_text(3, "TheReverserOfTime", -1, 0, 80, 140);
        fade_in_text(3);
        set_text(4, "GTM", -1, 2, 220, 140);
        fade_in_text(4);
        set_text(5, "Mushie64", -1, 0, 80, 120);
        fade_in_text(5);
        set_text(6, "Arthurtilly", -1, 2, 220, 120);
        fade_in_text(6);
    }
    else if (o->oTimer < 650)
    {
        fade_out_all();
    }
    else if (o->oTimer < 680)
    {
        set_text(0, "SPECIAL THANKS", -1, 1, 160, 80);
        fade_in_text(0);
    }
    else if (o->oTimer < 750)
    {
        set_text(1, "scuttlebug raiser", -1, 0, 30, 100);
        fade_in_text(1);
        set_text(2, "ArcticJaguar", -1, 0, 30, 120);
        fade_in_text(2);
        set_text(3, "ToasterKetchup", -1, 2, 270, 100);
        fade_in_text(3);
        set_text(4, "octaviosidoni", -1, 2, 270, 120);
        fade_in_text(4);
        set_text(5, "Yoshi Milkman", -1, 0, 30, 140);
        fade_in_text(5);
        set_text(6, "HackerSM64 discord", -1, 2, 270, 140);
        fade_in_text(6);
        set_text(7, "Dog Collab", -1, 0, 30, 160);
        fade_in_text(7);
        set_text(8, "The Lads", -1, 2, 270, 160);
        fade_in_text(8);
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
        if (o->oTimer == 1060)
        {
            seq_player_fade_out(0, 1000);
        }
        fade_out_all();
    }
}

#define CLAMP(x, low, high)  (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
extern Gfx mat_bbh_dl__auto_6_f3d_layer1[];
extern Gfx mat_bbh_dl______layer1[];
void bhv_sand_color_ctl_loop()
{
    {
        // X -6000, -580
        f32 val = -(gMarioStates->pos[0] + 580.f) / (6000.f - 580.f);
        f32 dist = CLAMP(val, 0.f, 1.f);
        u8* data = (u8*) segmented_to_virtual(mat_bbh_dl______layer1) + 21 * 8;
        data[4] = 255 - (255 - 254) * dist;
        data[5] = 255 - (255 - 159) * dist;
        data[6] = 255 - (255 - 152) * dist;
    }
    {
        // Z 13500, 8800
        f32 val = (13500.f - gMarioStates->pos[2]) / (13500.f - 8800.f);
        f32 dist = CLAMP(val, 0.f, 1.f);
        u8* data = (u8*) segmented_to_virtual(mat_bbh_dl__auto_6_f3d_layer1) + 21 * 8;
        data[4] = 255 - (255 - 230) * dist;
        data[5] = 255 - (255 - 193) * dist;
        data[6] = 255 - (255 - 254) * dist;
    }
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

        if (0 != o->oTimer)
            load_object_collision_model();
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
        load_object_collision_model();
    }
    else
    {
        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;
        obj_scale(o, 0.1f * (10 - o->oTimer));
        if (9 == o->oTimer)
        {
            cur_obj_become_intangible();
        }
        else if (10 == o->oTimer)
        {
            o->oAction = 0;
            o->oPosY -= 10.f;
        }
        else
        {
            load_object_collision_model();
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

extern const Trajectory pss_area_1_spline_sillycurve[];
s32 gSillyWilly = 0;
void bhv_silly_willy_loop()
{
    gSillyWilly = o->oAction ? 1 + (o->oPathedPrevWaypoint - o->oPathedStartWaypoint) : 0;

    if (0 == o->oAction)
    {
        if (o->oDistanceToMario < 500.f)
        {
            o->oAction = 1;
            o->oPathedPrevWaypointFlags = 0;
            struct Waypoint* path = segmented_to_virtual(pss_area_1_spline_sillycurve);
            o->oPathedStartWaypoint = o->oPathedPrevWaypoint = path;
            o->oForwardVel = 60.f;
        }
    }
    else
    {
        if (o->oTimer == 20)
            play_sound(SOUND_MARIO_MAMA_MIA, gMarioStates->marioObj->header.gfx.cameraToObject);

        if (cur_obj_follow_path() == PATH_REACHED_END)
        {
            // reset to the initial state
            o->oAction = 0;
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
        }
        else
        {
            // update self - initial values memery
            if (o->oTimer == 0)
            {
                o->oMoveAngleYaw   = o->oPathedTargetYaw;
                o->oMoveAnglePitch = o->oPathedTargetPitch;
            }

            // reset timer to fix point
            if (o->oSubAction != gSillyWilly)
            {
                if (gSillyWilly == 3 || gSillyWilly == 4 || gSillyWilly == 9)
                {
                    o->oPosX = (o->oPathedPrevWaypoint)->pos[0];
                    o->oPosY = (o->oPathedPrevWaypoint)->pos[1];
                    o->oPosZ = (o->oPathedPrevWaypoint)->pos[2];
                    o->oMoveAngleYaw   = o->oPathedTargetYaw;
                    o->oMoveAnglePitch = o->oPathedTargetPitch;
                }
            }
            o->oSubAction = gSillyWilly;

            // turn the object
            o->oMoveAngleYaw   = (s16) approach_s16_symmetric(o->oMoveAngleYaw,   (s16) o->oPathedTargetYaw, 0x800);
            o->oMoveAnglePitch = (s16) approach_s16_symmetric(o->oMoveAnglePitch, (s16) o->oPathedTargetPitch, 0x600);
            cur_obj_set_pos_via_transform();

            // update mao
            gMarioStates->action = ACT_BUTT_SLIDE;
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY;
            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->faceAngle[0] = o->oMoveAnglePitch;
            gMarioStates->faceAngle[1] = o->oMoveAngleYaw;
            gMarioStates->slideYaw = o->oMoveAngleYaw;
            gMarioStates->slideVelX = o->oVelX;
            gMarioStates->slideVelZ = o->oVelZ;
        }
    }
}

static u8 sTimerColors[] = {
    0x26, 0xFF, 0x66,
    0x27, 0xA1, 0xFF,
    0xFF, 0x86, 0x36,
};

extern Gfx mat_pss_dl_time_layer1[];
extern Gfx mat_pss_dl_arrow_layer1[];
extern u8 sPssSlideStarted;
void bhv_time_thing_loop()
{
    if (sPssSlideStarted)
    {
        u8* ptr = segmented_to_virtual(mat_pss_dl_arrow_layer1);
        u8* colors = ptr + 22 * 8 + 4;
        int off = (o->oTimer / 8) % 3;
        colors[0] = sTimerColors[off + 0];
        colors[1] = sTimerColors[off + 1];
        colors[2] = sTimerColors[off + 2];
        
        ptr = segmented_to_virtual(mat_pss_dl_time_layer1);
        colors = ptr + 22 * 8 + 4;
        off = (off + 1) % 3;
        colors[0] = sTimerColors[off + 0];
        colors[1] = sTimerColors[off + 1];
        colors[2] = sTimerColors[off + 2];
    }
    else
    {
        u8* ptr = segmented_to_virtual(mat_pss_dl_arrow_layer1);
        u8* colors = ptr + 22 * 8 + 4;
        colors[0] = 0x10;
        colors[1] = 0x10;
        colors[2] = 0x10;

        ptr = segmented_to_virtual(mat_pss_dl_time_layer1);
        colors = ptr + 22 * 8 + 4;
        colors[0] = 0x10;
        colors[1] = 0x10;
        colors[2] = 0x10;
    }
}

// tube half length = 1133
// tube radius = 1058
extern const BehaviorScript bhvTubeCommon[];
extern const BehaviorScript bhvStar[];
void bhv_ronpa_init()
{
    o->oRonpaCurr = spawn_object(o, MODEL_TUBE1, bhvTubeCommon);
    o->oRonpaCurr->oPosX = o->oPosX;
    o->oRonpaCurr->oPosY = o->oPosY + 1058.f;
    o->oRonpaCurr->oPosZ = o->oPosZ;
    
    o->oRonpaNext = spawn_object(o, MODEL_TUBE1, bhvTubeCommon);
    o->oRonpaNext->oPosX = o->oPosX;
    o->oRonpaNext->oPosY = o->oPosY + 1058.f;
    o->oRonpaNext->oPosZ = o->oPosZ + 2 * 1133.f;

    f32 d;
    o->oRonpaStar = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    o->oRonpaStar->oPosZ = 14000.f;
    
    // mario stupidity
    o->oPosY -= 307.f;
    o->oHomeY -= 307.f;
    obj_scale_xyz(o, 1.f, 1.f, 10.f);
}

static u16 gActiveMasks[] = 
{ 0x0, 0x0, 0x0, 0x0, 
  0b0000001001001001,
  0x0, 
  0b0100100100100100,
  0b1101101101101101,
  0b1001001001001001,
  0b0110110110110110,
  0b1001001001001001,
  0b0110110110110110,
  0b0100100100100100,
  0b1101101101101101,
  0b0000001001001001,
  0x0, 
  0x0, 
  0x0, 
  0xff, 
  0xff, 
};

extern Gfx mat_jrb_dl_sand_ded[];
void bhv_ronpa_loop()
{
    if (0 == o->oAction)
    {
        u8* alpha = (u8*)segmented_to_virtual(mat_jrb_dl_sand_ded) + 8 * 19 + 7;
        if (gMarioStates->pos[2] > -4500.f)
        {
            o->oAction = 1;
            *alpha = 0;
        }
        else
        {
            f32 pos = 1.f - (gMarioStates->pos[2] + 7000.f) / 2500.f;
            pos = CLAMP(pos, 0.f, 1.f);
            *alpha = pos * 255;
        }
    }
    else if (1 == o->oAction)
    {
        if (gMarioStates->pos[2] > -4500.f)
            load_object_collision_model();
    
        gMarioStates->pos[0] = o->oPosX;
        if (gMarioStates->pos[2] > o->oHomeZ)
        {
            o->oAction = 2;
        }
    }
    else if (2 == o->oAction)
    {
        s16 angleSpd = atan2s(1058.f, gMarioStates->vel[0]);
        if (gMarioStates->vel[2] < 0.f)
            gMarioStates->vel[2] = 0.f;
        
        o->oRonpaDist += gMarioStates->vel[2];
        o->oRonpaStar->oPosZ -= gMarioStates->vel[2];
        
        // the objects are moving the other way to do trickery
        o->oRonpaCurr->oPosZ = o->oHomeZ - o->oRonpaDist;
        o->oRonpaCurr->oFaceAngleRoll -= angleSpd;
        
        // next and prev are inheriting the stats of curr but with an offset
        o->oRonpaNext->oPosZ = o->oRonpaCurr->oPosZ + 2 * 1133.f;
        o->oRonpaNext->oFaceAngleRoll = o->oRonpaCurr->oFaceAngleRoll;
        if (o->oRonpaPrev)
        {
            o->oRonpaPrev->oPosZ = o->oRonpaCurr->oPosZ - 2 * 1133.f;
            o->oRonpaPrev->oFaceAngleRoll = o->oRonpaCurr->oFaceAngleRoll;
        }
        
        // clamp angle to 12 direction values
        s16 turnAngle = (o->oRonpaCurr->oFaceAngleRoll + 0x10000 / 24) % (0x10000 / 12);
        if (turnAngle < 0)
            turnAngle += 0x10000 / 12;

        turnAngle -= 0x10000 / 24;
        f32 h = sins(turnAngle) * sins(turnAngle) * 1058.f;

        u16 turnNum = o->oRonpaCurr->oFaceAngleRoll + 0x10000 / 24;
        turnNum /= (0x10000 / 12);

        o->oPosY = o->oHomeY - h / 2 + 10.f;
        // this is causing really weird stutters on the camera so whatever
        // o->oFaceAngleRoll = turnAngle;
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[2] = o->oPosZ;

        s32 turnStep = o->oSubAction * 2 + (o->oRonpaDist > 0);
        //print_text_fmt_int(20, 20, "%d", turnStep);
        //print_text_fmt_int(20, 40, "%d", turnNum);
        //print_text_fmt_int(20, 60, "%d", gActiveMasks[turnStep] & (1 << turnNum));
        s32 inactive = gActiveMasks[turnStep] & (1 << turnNum);

        if (!inactive || o->oRonpaDist < -1033.f || o->oRonpaDist > 1033.f || (-100.f < o->oRonpaDist && o->oRonpaDist < 100.f))
        {
           load_object_collision_model();
        }
        
        if (o->oRonpaDist > 1133.f)
        {
            o->oSubAction++;
            if (o->oRonpaPrev)
            {
                o->oRonpaPrev->activeFlags = 0;
            }
            o->oRonpaPrev = o->oRonpaCurr;
            o->oRonpaCurr = o->oRonpaNext;
            int tubeNumber = o->oSubAction < 4 ? MODEL_TUBE1 + o->oSubAction : MODEL_TUBE4 - o->oSubAction + 4;
            o->oRonpaNext = spawn_object(o, tubeNumber >= MODEL_TUBE1 ? tubeNumber : 0, bhvTubeCommon);
            o->oRonpaNext->oPosX = o->oRonpaCurr->oPosX;
            o->oRonpaNext->oPosY = o->oRonpaCurr->oPosY;
            o->oRonpaNext->oPosZ = o->oRonpaCurr->oPosZ + 2 * 1133.f;
            o->oRonpaDist -= 2 * 1133.f;
        }
    }
}

extern u8 bob_dl__2_ci4_pal_rgba16[]; // 14 colors
extern u8 bob_dl__5_ci4_pal_rgba16[]; // 10 colors
void bhv_troll_ctl_loop()
{
    struct Surface* floor = gMarioStates->floor;
    if (!floor)
        return;

    int type = floor->type;
    if (48 == type)
    {

    }
    if (35 == type)
    {
        // kill color
        if (!o->oTrollOffset)
        {
            o->oTrollOffset = 1;
            cur_obj_play_sound_2(SOUND_OBJ_BOO_LAUGH_LONG);
        }
        u8* ptr0 = segmented_to_virtual(bob_dl__2_ci4_pal_rgba16);
        u8* ptr1 = segmented_to_virtual(bob_dl__5_ci4_pal_rgba16);
        int off0 = o->oTimer % 14;
        int off1 = o->oTimer % 10;
        u8* bapart = &ptr0[2 * off0 + 1];
        *bapart &= ~1;
        bapart = &ptr1[2 * off1 + 1];
        *bapart &= ~1;
    }
}

static struct Object *cur_obj_find_nearest_object_with_behavior_y_biased(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;
    struct Object *closestObj = NULL;
    f32 minDist = 0x200000000;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
        ) {
            f32 dx = o->oPosX - obj->oPosX;
            f32 dy = o->oPosY - obj->oPosY;
            f32 dz = o->oPosZ - obj->oPosZ;
            f32 objDist = dx*dx + 10*dy*dy + dz*dz;
            if (objDist < minDist) {
                closestObj = obj;
                minDist = objDist;
            }
        }

        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
}

void bhv_red_coin_radar_loop()
{
    if (gPlayer1Controller->buttonPressed & 32)
    {
        if (obj_is_hidden(o))
        {
            cur_obj_unhide();
        }
        else
        {
            cur_obj_hide();
        }
    }
    
    obj_scale(o, 0.3f);
    struct Object* red = cur_obj_find_nearest_object_with_behavior_y_biased(bhvRedCoin);
    if (!red)
    {
        o->activeFlags = 0;
        return;
    }

    o->oPosX = gMarioStates->pos[0];
    o->oPosY = gMarioStates->pos[1] + 150.f;
    o->oPosZ = gMarioStates->pos[2];

    f32 dx = o->oPosX - red->oPosX;
    f32 dy = o->oPosY - red->oPosY;
    f32 dz = o->oPosZ - red->oPosZ;
    f32 l = sqrtf(dx*dx + dz*dz);

    s16 yaw = atan2s(dz, dx) + 0x8000;
    s16 pitch = atan2s(l, dy);
    o->oFaceAngleYaw = yaw;
    o->oPosX += sins(yaw) * 80.f;
    o->oPosZ += coss(yaw) * 80.f;
    o->oFaceAnglePitch = pitch;
}

void bhv_gg_loop()
{
    struct Surface* floor = gMarioStates->floor;
    if (!floor)
        return;

    int type = floor->type;
    if (SURFACE_HARD == type)
    {
        if ((gMarioStates->pos[1] < o->oPosY) && !(gMarioStates->flags & MARIO_VANISH_CAP))
        {
            print_text_centered(160, 20, "BAD ENDING CLEAR");
        }
    }
}

void bhv_music_switcher_loop()
{
    if (0 == o->oAction)
    {
        if (1500 == o->oTimer)
        {
            seq_player_fade_out(0, 100);
        }
        if (1530 == o->oTimer)
        {
            seq_player_play_sequence(0, 0x37, 0);
            o->oAction = 1;
        }
    }
    if (1 == o->oAction)
    {
        if (1200 == o->oTimer)
        {
            seq_player_fade_out(0, 100);
        }
        if (1230 == o->oTimer)
        {
            seq_player_play_sequence(0, 0x38, 0);
            o->oAction = 2;
        }
    }
    if (2 == o->oAction)
    {
        if (1500 == o->oTimer)
        {
            seq_player_fade_out(0, 100);
        }
        if (1530 == o->oTimer)
        {
            seq_player_play_sequence(0, 0x39, 0);
            o->oAction = 3;
        }
    }
    if (3 == o->oAction)
    {
        if (1300 == o->oTimer)
        {
            seq_player_fade_out(0, 100);
        }
        if (1330 == o->oTimer)
        {
            print_text_centered(160, 20, "SKILL ISSUE");
            seq_player_play_sequence(0, 0x2b, 0);
            o->oAction = 0;
        }
    }
}

void bhv_chiaki_init()
{
    o->oFaceAnglePitch = 0x4000;
    f32 d;
    o->oChiakiStar = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    o->oChiakiStar->oPosX = o->oPosX;
    o->oChiakiStar->oPosY = o->oPosY;
    o->oChiakiStar->oPosZ = o->oPosZ + 500.f;    
}

static f32 sChiakiStartMove[] = 
{
    10000.f, 4778.f, 0.f, -4844.f, -9638.f, -14454.f, -20000.f
};

static f32 sChiakiStopMove[] = 
{
    4004.f, -800.f, -5600.f, -10400.f, -15204.f, -16700.f, -20000.f
};

void bhv_chiaki_loop()
{
    if (0 == o->oSubAction)
    {
        if (sChiakiStartMove[o->oAction] > gMarioStates->pos[2])
        {
            o->oSubAction = 1;
        }
    }
    else
    {
        if (sChiakiStopMove[o->oAction] < o->oPosZ)
        {
            o->oPosZ -= 100.f;
        }
        else
        {
            o->oPosZ = sChiakiStopMove[o->oAction];
            o->oAction++;
        }
    }
    o->oChiakiStar->oPosZ = o->oPosZ + 500.f;
}

void bhv_tree_init(void)
{
    o->oHDTree = 1;
    if (gIsConsole)
    {
        if (gCurrCourseNum == COURSE_TOTWC || gCurrCourseNum == COURSE_COTMC)
            o->oHDTree = 0;
    }

    o->oDrawingDistance = (gCurrCourseNum == COURSE_BOB && gCurrAreaIndex == 1) ? 3000.f : 6000.f;
    if (gCurrCourseNum == COURSE_TOTWC) o->oDrawingDistance = 3500.f;

    if (o->oHDTree)
    {
        gCurrentObject->oFaceAngleYaw = random_u16();
        obj_scale_xyz(gCurrentObject, 0.7f + random_float() * 0.3f, 0.97f + 0.06f * random_float(), 0.7f + random_float() * 0.3f);
    }
    else
    {
        gCurrentObject->header.gfx.node.flags |= GRAPH_RENDER_BILLBOARD;
    }
}

void bhv_fireplace_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSmallPenguin, &d);
    struct Object* flame = spawn_object(o, MODEL_RED_FLAME, bhvFlame);
    obj_scale(o, 0.4f);
    o->oPosY += 20.f;
    flame->oPosY += 40.f;
}

void bhv_fireplace_loop()
{
    if (0 == o->oAction)
    {
        f32 dx = o->oPosX - o->parentObj->oPosX;
        f32 dy = o->oPosY - o->parentObj->oPosY;
        f32 dz = o->oPosZ - o->parentObj->oPosZ;
        f32 d = dx*dx + dy*dy + dz*dz;
        if (d < 3000.f)
        {
            mario_drop_held_object(gMarioStates);
            o->parentObj->activeFlags = 0;
            spawn_object(o, MODEL_BOWSER_FLAMES, bhvBowserBombExplosion);
            create_sound_spawner(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION);
            set_camera_shake_from_point(SHAKE_POS_LARGE, o->oPosX, o->oPosY, o->oPosZ);
            o->oAction = 1;
        }
    }
}

void sparkler_loop()
{
    if (0 == (o->oTimer % 4))
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX += random_f32_around_zero(100.f);
        spark->oPosY += random_f32_around_zero(100.f);
        spark->oPosZ += random_f32_around_zero(100.f);
    }
}

extern u8 gAllowPausing;
#define RING_BUFFER_SIZE 8
struct SafePositionsPos
{
    f32 x;
    f32 y;
    f32 z;
};

static struct SafePositionsRingBuffer
{
    u32 timer;
    struct SafePositionsPos positions[RING_BUFFER_SIZE];
} sSafePositionsRingBuffer;

extern u8 gAllowPausing;

void bhv_death_trigger_init()
{
    sSafePositionsRingBuffer.timer = 0;
    for (int i = 0; i < RING_BUFFER_SIZE; i++)
    {
        sSafePositionsRingBuffer.positions[i].x = gMarioStates->pos[0];
        sSafePositionsRingBuffer.positions[i].y = gMarioStates->pos[1] - 100.f;
        sSafePositionsRingBuffer.positions[i].z = gMarioStates->pos[2];
    }
}

static s32 in_safe_square()
{
    // (1360, 4215) - (10062, 295)
    f32 x = gMarioStates->pos[0];
    f32 z = gMarioStates->pos[2];
    return 1360.f < x && x < 10062.f && 295.f < z && z < 4215.f;
}

void bhv_death_trigger_loop()
{
    struct SafePositionsRingBuffer* rb = &sSafePositionsRingBuffer;
    struct Surface* floor = gMarioStates->floor;
    if (0 == o->oAction)
    {
        u32 rbTimerPrev = (rb->timer - 1 + RING_BUFFER_SIZE) % 8;
        f32 lastY = rb->positions[rbTimerPrev].y;
        if (gMarioStates->action == ACT_LAVA_BOOST && !(gMarioStates->flags & MARIO_METAL_CAP) && !in_safe_square() && lastY > 1740.f)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
            gAllowPausing = 0;
            o->oAction = 1;
        }
        else
        {
            // print_text_fmt_int(20, 20, "%d", (int) floor->type);
            if (floor && gMarioStates->floorHeight == gMarioStates->pos[1] && (floor->type == SURFACE_NOT_SLIPPERY || floor->type == SURFACE_HARD || floor->type == SURFACE_HARD_NOT_SLIPPERY || floor->type == 0))
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
            gMarioStates->squishTimer = 0;
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
        }
        if (o->oTimer == 13)
        {
            reset_camera(gCamera);
        }
        if (o->oTimer == 14)
        {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0,0,0);
            gAllowPausing = 1;
            o->oAction = 0;
        }
    }
}

void bhv_trunk_init()
{
    o->oDrawingDistance = 4000.f;
    obj_scale(o, 0.6f);
    for (int i = 0; i < 3; i++)
    {
        struct Object* root = spawn_object(o, MODEL_TREE_ROOT, bhvC1TrunkRoot);
        s16 angle = 16000 + 21845 * i;
        root->oPosX += sins(angle) * 600.f;
        root->oPosZ += coss(angle) * 600.f;
        root->oFaceAngleYaw = angle;
        root->oBehParams2ndByte = i;
    }
}

void bhv_trunk_loop()
{

}

void bhv_trunk_root_init()
{
    struct Object* shadow = spawn_object(o, MODEL_TREE_ROOT_SHADOW, bhvStaticObject);
    shadow->oDrawingDistance = 3300.f;
    o->oDrawingDistance = 3300.f;
    o->oPosY += 5.f;
}

void bhv_trunk_root_loop()
{
    if (o->oAction == 0)
    {
        o->oPosY += 6.f;
        if (o->oTimer >= 54)
        {
            o->oAction = 1;
        }
    }
    else
    {
        int timeFrameStart = 5 + o->oBehParams2ndByte * 10;
        int timeFrameEnd = 15 + o->oBehParams2ndByte * 10;
        if (timeFrameStart <= o->oTimer && o->oTimer <= timeFrameEnd)
        {
            o->oPosY -= 30.f;
        }

        if (timeFrameStart + 5 == o->oTimer)
        {
            if (o->oDistanceToMario < 3000.f)
                cur_obj_play_sound_2(SOUND_OBJ_THWOMP);
        }

        if (o->oTimer > 40)
        {
            o->oAction = 0;
        }
    }
}

static struct ObjectHitbox sBlarrgHitBox = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 72,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 42,
    /* hurtboxHeight:     */ 40,
};

static struct ObjectHitbox sBlarrgHitBox2 = {
    /* interactType:      */ INTERACT_BOUNCE_TOP,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 1,
    /* radius:            */ 112,
    /* height:            */ 50,
    /* hurtboxRadius:     */ 82,
    /* hurtboxHeight:     */ 40,
};

void bhv_blarrg_loop_sub()
{
    obj_set_hitbox(o, &sBlarrgHitBox2);
    o->oInteractStatus = INT_STATUS_NONE;
    o->oPosX = o->parentObj->oPosX + sins(o->parentObj->oMoveAngleYaw) * 120.f;
    o->oPosY = o->parentObj->oPosY + 20.f;
    o->oPosZ = o->parentObj->oPosZ + coss(o->parentObj->oMoveAngleYaw) * 120.f;
}

extern const BehaviorScript bhvBlarrgSub[];
void bhv_blarrg_init()
{
    spawn_object(o, MODEL_NONE, bhvBlarrgSub);
}

void bhv_blarrg_loop()
{
    obj_set_hitbox(o, &sGoombaHitbox);
    cur_obj_init_animation_with_sound(0);
    o->oInteractStatus = INT_STATUS_NONE;
    o->oMoveAngleYaw += 0x257;
    if (0 == o->oBehParams2ndByte)
    {
        o->oPosX = o->oHomeX + 200.f * sins(-0x4000 + o->oMoveAngleYaw);
        o->oPosZ = o->oHomeZ + 200.f * coss(-0x4000 + o->oMoveAngleYaw);
    }
    if (1 == o->oBehParams2ndByte)
    {
        o->oPosX = o->oHomeX + 200.f * sins(-0x4000 + o->oMoveAngleYaw);
        o->oPosZ = o->oHomeZ + 200.f * sins(-0x4000 + o->oMoveAngleYaw);
    }
}

void bhv_iceblock_init()
{
    o->oTimer = o->oPosX;
    obj_scale_xyz(o, 0.3f, 0.015f, 0.3f);
}

void bhv_iceblock_loop()
{
    f32 volume = 0.3f * 0.015f * 0.3f;
    f32 t = (sins(o->oTimer * 460) + 1.f) / 2.f;
    f32 xz = 0.09f + t * 0.26f;
    f32 y = volume / xz / xz;
    obj_scale_xyz(o, xz, y, xz);
}

void bhv_iceblock_init_small()
{
    o->oTimer = o->oPosX;
    obj_scale_xyz(o, 0.3f, 0.015f, 0.3f);
}

void bhv_iceblock_loop_small()
{
    f32 volume = 0.3f * 0.015f * 0.3f;
    f32 t = (sins(o->oTimer * 460) + 1.f) / 2.f;
    f32 xz = 0.1f + t * 0.1f;
    f32 y = volume / xz / xz;
    obj_scale_xyz(o, xz, y, xz);
}

void bhv_bitfsplate_init()
{
    o->parentObj = spawn_object(o, MODEL_BULLY, bhvSmallBully);
    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosY = o->oPosY;
    o->parentObj->oPosZ = o->oPosZ;
    o->oHomeY = o->oPosY;
}

void bhv_bitfsplate_loop()
{
    o->oFaceAngleYaw += 0x68;
    struct Object* ctl = o->oBitfsPlatformCtl;
    if (ctl->oAction < 3)
    {
        o->oFaceAngleYaw += 0xA0;
    }
    if (ctl->oAction < 2)
    {
        o->oPosY = o->oHomeY + 100.f * (1 - coss(0x234 * ctl->oBitfsCtlTimer));
    }

    f32 r = 1200.f;
    o->oPosX = r * sins(o->oFaceAngleYaw);
    o->oPosZ = r * coss(o->oFaceAngleYaw);

    if (0 == o->oAction)
    {
        if (o->parentObj->oAction <= 1)
        {
            o->parentObj->oPosX = o->oPosX;
            o->parentObj->oPosY = o->oPosY;
            o->parentObj->oPosZ = o->oPosZ;
        }
        else
        {
            o->oAction = 1;
        }
    }
    else if (1 == o->oAction)
    {
        if (o->parentObj->oAction == OBJ_ACT_LAVA_DEATH)
        {
            ctl->oAction--;
            o->oAction = 2;
        }
    }
    else
    {
        // -
    }
}

static struct SpawnParticlesInfo sMistParticles = {
    /* behParam:        */ 2,
    /* count:           */ 20,
    /* model:           */ MODEL_MIST,
    /* offsetY:         */ 0,
    /* forwardVelBase:  */ 40,
    /* forwardVelRange: */ 5,
    /* velYBase:        */ 30,
    /* velYRange:       */ 20,
    /* gravity:         */ 252,
    /* dragStrength:    */ 30,
    /* sizeBase:        */ 330.0f,
    /* sizeRange:       */ 10.0f,
};

static void spawn_mist_particles_variable_ranged(s32 count, s32 offsetY, f32 size, f32 range) {
    sMistParticles.sizeBase = size;
    sMistParticles.sizeRange = range;
    sMistParticles.offsetY = offsetY;

    if (count == 0) {
        sMistParticles.count = 20;
    } else if (count > 20) {
        sMistParticles.count = count;
    } else {
        sMistParticles.count = 4;
    }

    cur_obj_spawn_particles(&sMistParticles);
}

void bhv_bitfs_fight_init()
{
    for (int i = 0; i < 3; i++)
    {
        s32 angle =  0x10000 / 3 * i;
        f32 r = 1200.f;
        o->oPosX = r * sins(angle);   
        o->oPosZ = r * coss(angle);
        spawn_mist_particles_variable_ranged(10, 0, 46.0f, 100.f);

        struct Object* plate = spawn_object(o, MODEL_BITFS_PLATFORM_ON_TRACK, bhvBitfsPlate);
        plate->oFaceAngleYaw = 0x10000 / 3 * i;
        plate->oBitfsPlatformCtl = o;
    }
    o->oAction = 3;
    
    o->oPosX = 0;
    o->oPosZ = 0;
    cur_obj_play_sound_2(SOUND_OBJ_BOWSER_LAUGH);
}

void bhv_bitfs_fight_loop()
{
    if (1 == o->oAction)
    {
        o->oBitfsCtlTimer++;
    }
    if (0 == o->oAction && 0 == o->oSubAction)
    {
        spawn_default_star(0.f, 3700.f, 0.f);
        o->oSubAction = 1;
    }
}

void bhv_running_star_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    o->oPosY = o->parentObj->oPosY = find_ceil(o->oPosX, 0.f, o->oPosZ, &o->oFloor) - 10.f;
}

void bhv_running_star_loop()
{
    if (0 == o->parentObj->activeFlags)
    {
        o->activeFlags = 0;
    }

    if (o->oPosZ < 0.f)
    {
        o->activeFlags = 0;
        return;
    }

    f32 afterSlide = o->oPosZ > 1100.f;
    f32 afterSlope = o->oFloor && o->oFloor->normal.y < -0.5f;
    f32 td = afterSlide ? 300.f : 500.f;
    if (o->oDistanceToMario < td)
    {
        if (afterSlide)
        {
            o->oPosZ -= 10.f;
        }
        else
        {
            o->oPosZ -= 30.f;
        }
        f32 y = find_ceil(o->oPosX, 0.f, o->oPosZ, &o->oFloor);
        if (o->oFloor)
        {
            o->oPosY = y - (afterSlope ? (600.f - o->oPosZ) : 10.f);
        }
    }
    
    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosZ = o->oPosZ;
    if (o->oPosY > o->parentObj->oPosY)
    {
        o->parentObj->oPosY += 10.f;
    }
    else
    {
        o->parentObj->oPosY = o->oPosY;
    }
    o->parentObj->oFloor = NULL;
}
