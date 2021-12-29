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
        if (b->oAction == 8)
        {
            for (int i = 0; i < 4; i++)
            {
                struct Object** fakes = &o->oBobombCtlFake1;
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
        if (o->oTimer > 100 && o->oDistanceToMario > 500.f)
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

void bhv_warp_gate_block_loop()
{
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
