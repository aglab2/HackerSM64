// #define NO_HP
// #define PRINT_DEBUG

extern s32 set_camera_mode_fixed(struct Camera *c, s16 x, s16 y, s16 z);

extern s16 s8DirModeBaseYaw;
extern s32 gTatums;
extern s16 sHandheldShakeRoll;
extern const BehaviorScript bhvBat[];
extern const BehaviorScript bhvBatStatic[];
extern Gfx mat_castle_courtyard_dl_f3dlite_material_layer1_area1[];

static int sTimer;
extern f32 gBaseDist;
extern f32 gRangeDist;
extern s16 gRangePitch;
extern Vec3f sFixedModeBasePosition;
extern f32 sAspectRatio;
extern struct CameraFOVStatus sFOVState;
extern s16 gPitch;

s8 sBatsJump;

void ctl_reset()
{
    s8DirModeBaseYaw = 0;
    sTimer = 0;
    gTatums = 0;
    gBaseDist = 1000.f;
    gRangeDist = 400.f;
    gRangePitch = 0x900;
    sAspectRatio = 4.f / 3.f;
    sFOVState.fov = 45;
    gPitch = 0x05B0;
    sBatsJump = 0;
}

void reset_init()
{
    save_file_load_all();
    ctl_reset();
    gSaveFileModified = 1;
    gMainMenuDataModified = 1;
    save_file_do_save(0);

    for (int i = 0; i < 10; i++)
    {
        struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBatStatic);
        bat->oPosX = random_f32_around_zero(1000.f);
        bat->oPosY = 30.f;
        bat->oPosZ = random_f32_around_zero(1000.f);
        f32 dx = bat->oPosX - 11.f;
        f32 dz = bat->oPosZ - 741.f;
        f32 d = dx*dx + dz*dz;
        if (d < 1000.f)
            bat->activeFlags = 0;
    }
}

void reset_loop()
{
    random_u16();
}

void ctl_init()
{
    ctl_reset();
    for (int i = 0; i < 70; i++)
    {
        struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBat);
        bat->oPosX = random_f32_around_zero(5000.f);
        bat->oPosY = 30.f;
        bat->oPosZ = -5000.f + 32.f * i;
        bat->oVelZ = random_u16() & 1 ? 32.f : 40.f;
    }

    // o->oAction = 17;
}

void ctl_loop()
{
#ifdef PRINT_DEBUG
    print_text_fmt_int(20, 20, "M %d", gTatums);
    print_text_fmt_int(20, 40, "T %d", o->oTimer);
    print_text_fmt_int(20, 60, "A %d", o->oAction);
    print_text_fmt_int(20, 80, "R %d", s8DirModeBaseYaw);
    print_text_fmt_int(20, 100, "P %d", gPitch);
    print_text_fmt_int(20, 120, "F %d", (int) (sFOVState.fov * 10));
    print_text_fmt_int(20, 140, "W %d", (int) (sAspectRatio * 100));
#endif

    sHandheldShakeRoll = 0;
    gMarioStates->pos[2] = 0.f;

    if (gTatums < 67000)
    {
        sTimer++;
        s32 spawn = (6400 < gTatums && gTatums < 60000) ? (0 == (sTimer % 3)) : (0 == (sTimer % 2));
        if (spawn)
        {
            struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBat);
            bat->oPosX = random_f32_around_zero(5000.f);
            bat->oPosY = 30.f;
            bat->oPosZ = -5000.f;
            bat->oVelZ = random_u16() & 1 ? 32.f : 40.f;
        }
    }

    if (0 == o->oAction)
    {
        if (gTatums > 1948)
        {
            o->oAction = 1;
            return;
        }
    }

    if (1 == o->oAction)
    {
        u8* vptr = (u8*) segmented_to_virtual(mat_castle_courtyard_dl_f3dlite_material_layer1_area1);
        if (o->oTimer < 80)
        {
            u8 v = 240 - 3 * o->oTimer;
            vptr[9*8 + 4] = v;
            vptr[9*8 + 5] = v;
            vptr[9*8 + 6] = v;
        }
        else
        {
            vptr[9*8 + 4] = 0;
            vptr[9*8 + 5] = 0;
            vptr[9*8 + 6] = 0;
        }

        if (gTatums > 6250)
        {
            o->oAction = 2;
            return;
        }
    }

    if (2 == o->oAction)
    {
        u8* vptr = (u8*) segmented_to_virtual(mat_castle_courtyard_dl_f3dlite_material_layer1_area1);
        if (o->oTimer < 20)
        {
            sHandheldShakeRoll = o->oTimer * (0x10000 / 20);
            o->oSubAction = 0;
            u8 v = 12 * o->oTimer;
            o->oSubAction = 0;
            vptr[9*8 + 4] = v;
            vptr[9*8 + 5] = v;
            vptr[9*8 + 6] = v;
        }
        else
        {
            sHandheldShakeRoll = o->oSubAction * 0x100;
            vptr[9*8 + 4] = 255;
            vptr[9*8 + 5] = 255;
            vptr[9*8 + 6] = 255;
        }

        if (gTatums > 7100)
        {
            if (o->oSubAction < 0x20)
                o->oSubAction++;
        }
        if (gTatums > 8000)
        {
            if (o->oSubAction < 0x40)
                o->oSubAction++;
        }
        if (gTatums > 9800)
        {
            if (o->oSubAction < 0x60)
                o->oSubAction++;
        }
        if (gTatums > 10700)
        {
            if (o->oSubAction < 0x80)
                o->oSubAction++;
        }

        if (gTatums > 13000)
        {
            if (o->oSubAction < 0xC0)
                o->oSubAction += 4;
        }
        if (gTatums > 13400)
        {
            if (o->oSubAction < 0x100)
                o->oSubAction += 4;
        }

        if (gTatums > 13800)
        {
            if (o->oSubAction < 0x200)
                o->oSubAction += 0x10;
        }

        if (gTatums > 15600 && 0 == sBatsJump)
        {
            sBatsJump = 1;
            return;
        }
        if (1 == sBatsJump)
        {
            sBatsJump = 2;
        }

        if (gTatums > 17300)
        {
            o->oAction = 3;
            return;
        }
    }

    if (3 == o->oAction)
    {
        if (o->oTimer < 100)
        {
            gBaseDist -= 10.f;
            sHandheldShakeRoll = 0x4000 / 100 * o->oTimer;
        }
        else
        {
            sHandheldShakeRoll = 0x4000;
        }

        if (gTatums > 20500)
        {
            o->oAction = 4;
            return;
        }
    }

    if (4 == o->oAction)
    {
        if (o->oTimer < 100)
        {
            gBaseDist += 30.f;
            sHandheldShakeRoll = 0x4000 + 0x4000 / 100 * o->oTimer;
        }
        else
        {
            sHandheldShakeRoll = 0x8000;
        }

        if (gTatums > 24200)
        {
            o->oAction = 5;
            return;
        }
    }

    if (5 == o->oAction)
    {
        if (o->oTimer < 100)
        {
            s8DirModeBaseYaw += 0x8000 / 100;
            sHandheldShakeRoll = 0x8000 + 0x4000 / 100 * o->oTimer;
        }
        else
        {
            sHandheldShakeRoll = 0xC000;
        }

        if (gTatums > 27400)
        {
            o->oAction = 6;
            return;
        }
    }

    if (6 == o->oAction)
    {
        if (o->oTimer < 100)
        {
            gBaseDist -= 20.f;
            s8DirModeBaseYaw += 0x8000 / 100;
            sHandheldShakeRoll = 0xc000 + 0x4000 / 100 * o->oTimer;
        }
        else
        {
            sHandheldShakeRoll = 0;
        }

        if (gTatums > 31000)
        {
            o->oAction = 7;
            set_camera_mode_fixed(gCamera, gCamera->pos[0], gCamera->pos[1], gCamera->pos[2]);
            gLakituState.mode = CAMERA_MODE_FIXED;
            return;
        }
    }

    if (7 == o->oAction)
    {
        set_camera_mode_fixed(gCamera, sFixedModeBasePosition[0], sFixedModeBasePosition[1], sFixedModeBasePosition[2] + 32.f);
        if (gTatums > 31630)
        {
            o->oAction = 8;
            set_camera_mode_fixed(gCamera, gCamera->pos[0], gCamera->pos[1], -5000.f);
            return;
        }
    }

    if (8 == o->oAction)
    {
        set_camera_mode_fixed(gCamera, sFixedModeBasePosition[0], sFixedModeBasePosition[1], sFixedModeBasePosition[2] + 32.f);
        if (gTatums > 33270)
        {
            o->oAction = 9;
            set_camera_mode_fixed(gCamera, gCamera->pos[0], gCamera->pos[1], 4500.f);
            return;
        }
    }

    if (9 == o->oAction)
    {
        set_camera_mode_fixed(gCamera, sFixedModeBasePosition[0], sFixedModeBasePosition[1], sFixedModeBasePosition[2] - 32.f);
        if (gTatums > 35050)
        {
            o->oAction = 10;
            set_cam_angle(CAM_ANGLE_MARIO);
            // gCameraMovementFlags &= ~CAM_MOVE_ZOOMED_OUT;
            return;
        }
    }

    if (10 == o->oAction)
    {
        if (gTatums > 36736)
        {
            o->oAction = 11;
            set_cam_angle(CAM_ANGLE_LAKITU);
            gCamera->mode = CAMERA_MODE_8_DIRECTIONS;
            gLakituState.mode = CAMERA_MODE_8_DIRECTIONS;
            // gCameraMovementFlags |= CAM_MOVE_ZOOMED_OUT;
            return;
        }
    }

    if (11 == o->oAction)
    {
        if (gTatums > 37800)
        {
            gRangeDist = 0.f;
            gRangePitch = -100;
            o->oAction = 12;
            sBatsJump = 0;
            return;
        }
    }
    
    if (12 == o->oAction)
    {
        if (gTatums > 38150 && 0 == sBatsJump)
        {
            sBatsJump = 1;
            return;
        }
        if (1 == sBatsJump)
        {
            sBatsJump = 2;
            return;
        }

        if (gTatums > 39500 && 2 == sBatsJump)
        {
            sBatsJump = 3;
            return;
        }
        if (3 == sBatsJump)
        {
            sBatsJump = 4;
        }

        if (gTatums > 44600)
        {
            gRangeDist = 2500.f;
            gRangePitch = 0x900;
            o->oAction = 13;
            return;
        }
    }

    if (13 == o->oAction)
    {
        if (gTatums > 47000)
        {
            gRangeDist = 400.f;
            gRangePitch = 0x900;
            o->oAction = 14;
            return;
        }
    }

    if (14 == o->oAction)
    {
        if (gTatums > 48850)
        {
            o->oAction = 15;
            return;
        }
    }

    if (15 == o->oAction)
    {
        s8DirModeBaseYaw += 0x8000 / 55;
        sAspectRatio = 2.0f + 1.6f * sins(-709 * o->oTimer - DEGREES(0.42978f / 3.1415926f * 180.f));
        if (gTatums > 50480)
        {
            o->oAction = 16;
            return;
        }
    }

    if (16 == o->oAction)
    {
        if (gTatums > 52300)
        {
            o->oAction = 17;
            return;
        }
    }

    if (17 == o->oAction)
    {
        s8DirModeBaseYaw += 0x8000 / 160;
        sFOVState.fov = 1.1f * 50.f + 1.1f * 25.f * sins(849 * o->oTimer - DEGREES(0.20136f / 3.1415926f * 180.f));
        if (gTatums > 53936)
        {
            o->oAction = 18;
            return;
        }
    }

    if (18 == o->oAction)
    {
        if (gTatums > 55600)
        {
            o->oAction = 19;
            return;
        }
    }

    if (19 == o->oAction)
    {
        s8DirModeBaseYaw -= 0x8000 / 160;
        gPitch += 100;
        gBaseDist += 15.f;
        if (gTatums > 57360)
        {
            o->oAction = 20;
            return;
        }
    }

    if (20 == o->oAction)
    {
        if (gTatums > 59030)
        {
            o->oAction = 21;
            return;
        }
    }

    if (21 == o->oAction)
    {
        if (s8DirModeBaseYaw < 0)
            s8DirModeBaseYaw -= 0x8000 / 90;
        else
            s8DirModeBaseYaw = 0x7fff;
        
        sFOVState.fov += (45.f    - sFOVState.fov) * 0.07f;
        sAspectRatio  += (4.f/3.f - sAspectRatio ) * 0.05f;

        if (gTatums > 60750)
        {
            o->oAction = 22;
            return;
        }
    }

    if (22 == o->oAction)
    {
        s8DirModeBaseYaw = 0x7fff;
        sFOVState.fov = 45;
        sAspectRatio = 4.f / 3.f;

        if (gTatums > 62430)
        {
            o->oAction = 23;
            return;
        }
    }

    if (23 == o->oAction)
    {
        gPitch = 0x05B0;
        if (gTatums > 64128)
        {
            o->oAction = 24;
            return;
        }
    }

    if (24 == o->oAction)
    {
        s8DirModeBaseYaw = 0;
        gBaseDist = 1000.f;

        if (gTatums > 68000)
        {
            gMarioStates->usedObj = o;
            level_trigger_warp(gMarioStates, WARP_OP_TELEPORT);
            o->oAction = 25;
        }
    }
}

void bat_init()
{

}

static int interval_intersect(f32 s1, f32 e1, f32 s2, f32 e2) 
{
    return !(e1 < s2 || e2 < s1);
}

static void bat_dmg()
{
    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);
    if (interval_intersect(gMarioStates->pos[1], gMarioStates->pos[1] + 140.f, o->oPosY - 50.f, o->oPosY + 50.f))
    {
        f32 dx = gMarioStates->pos[0] - o->oPosX;
        f32 dz = gMarioStates->pos[2] - o->oPosZ;
        f32 d = dx*dx/2.f + dz*dz;
        if (d < 5000.f && gMarioStates->health > 0x80)
        {
#ifndef NO_HP
            if (sWarpDest.nodeId == 11)
                gMarioStates->health -= 0x200;
            else
                gMarioStates->health = 0x80;
#endif

            spawn_mist_particles();
            o->activeFlags = 0;
        }
    }
}

void bat_loop()
{
    if (gTatums > 65600)
    {
        o->oVelZ += 2.f;
    }

    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);

    if (1 == sBatsJump || 3 == sBatsJump)
    {
        o->oVelY = 30.f;
    }

    o->oPosZ += o->oVelZ;
    o->oPosY += o->oVelY;
    if (o->oPosY < o->oHomeY - 5.f)
    {
        o->oVelY = 0;
        o->oPosY = o->oHomeY;
    }
    else
    {
        o->oVelY -= 2.f;
    }

    if (o->oPosZ > 5000.f)
    {
        o->activeFlags = 0;
    }

    bat_dmg();
    
    if (gTatums > 66900)
    {
        spawn_mist_particles();
        o->activeFlags = 0;
    }
}

void bat_static_loop()
{
    bat_dmg();
}
