// 2048 - first beep
// 6350 - second beep
// 7100 - turn 1
// 8200 - turn 2
// 9200 - turn 3
// 10100 - turn 3
// 14000 - drop
// 17200 - go closer
// 20730 : 22000 - go far
// 24000 - go
// 27500 - go
// 31000 - ?
// 31800 - bam rotate
// 33360 - bam rotate
// 35000 - bam rotate
// 37000 - bam rotate
// 37900 - bam rotate
// 38500 - cam down

// 48000 - drop
// 50600 - stop
// 52400 : 54100 - swoosh
// 55800 : 57400 - swoosh
// 59000 : 60700 - swoosh
// 62600 - slight turn
// 64300 - slight turn

extern s32 set_camera_mode_fixed(struct Camera *c, s16 x, s16 y, s16 z);

extern s16 s8DirModeBaseYaw;
extern s32 gTatums;
extern s16 sHandheldShakeRoll;
extern const BehaviorScript bhvBat[];
extern Gfx mat_castle_courtyard_dl_f3dlite_material_layer1_area1[];

static int sTimer;
extern f32 gBaseDist;
extern f32 gRangeDist;
extern s16 gRangePitch;
extern Vec3f sFixedModeBasePosition;
extern f32 sAspectRatio;
extern struct CameraFOVStatus sFOVState;

void ctl_reset()
{
    s8DirModeBaseYaw = 0;
    sTimer = 0;
    gTatums = 0;
    gBaseDist = 1000.f;
    gRangeDist = 400.f;
    gRangePitch = 0x900;
    sAspectRatio = 4.f / 3.f;
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
    print_text_fmt_int(20, 20, "M %d", gTatums);
    print_text_fmt_int(20, 40, "T %d", o->oTimer);
    print_text_fmt_int(20, 60, "A %d", o->oAction);

    sHandheldShakeRoll = 0;
    gMarioStates->pos[2] = 0.f;

    sTimer++;
    s32 spawn = gTatums > 6400 ? (0 == (sTimer % 3)) : (0 == (sTimer % 2));
    if (spawn)
    {
        struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBat);
        bat->oPosX = random_f32_around_zero(5000.f);
        bat->oPosY = 30.f;
        bat->oPosZ = -5000.f;
        bat->oVelZ = random_u16() & 1 ? 32.f : 40.f;
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
        if (gTatums > 31680)
        {
            o->oAction = 8;
            set_camera_mode_fixed(gCamera, gCamera->pos[0], gCamera->pos[1], -5000.f);
            return;
        }
    }

    if (8 == o->oAction)
    {
        set_camera_mode_fixed(gCamera, sFixedModeBasePosition[0], sFixedModeBasePosition[1], sFixedModeBasePosition[2] + 32.f);
        if (gTatums > 33380)
        {
            o->oAction = 9;
            set_camera_mode_fixed(gCamera, gCamera->pos[0], gCamera->pos[1], 4500.f);
            return;
        }
    }

    if (9 == o->oAction)
    {
        set_camera_mode_fixed(gCamera, sFixedModeBasePosition[0], sFixedModeBasePosition[1], sFixedModeBasePosition[2] - 32.f);
        if (gTatums > 35088)
        {
            o->oAction = 10;
            set_cam_angle(CAM_ANGLE_MARIO);
            // gCameraMovementFlags &= ~CAM_MOVE_ZOOMED_OUT;
            return;
        }
    }

    if (10 == o->oAction)
    {
        if (gTatums > 36816)
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
            return;
        }
    }
    
    if (12 == o->oAction)
    {
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
        if (gTatums > 48940)
        {
            o->oAction = 15;
            return;
        }
    }

    if (15 == o->oAction)
    {
        s8DirModeBaseYaw += 0x8000 / 60;
        sAspectRatio = 2.0f + 1.6f * sins(-759 * o->oTimer - DEGREES(0.42978f / 3.1415926f * 180.f));
        if (gTatums > 50716)
        {
            o->oAction = 16;
            return;
        }
    }

    if (16 == o->oAction)
    {
        if (gTatums > 52352)
        {
            o->oAction = 17;
            return;
        }
    }

    if (17 == o->oAction)
    {
        s8DirModeBaseYaw += 0x8000 / 150;
        sFOVState.fov = 50.f + 25.f * sins(999 * o->oTimer - DEGREES(0.20136f / 3.1415926f * 180.f));
        if (gTatums > 54016)
        {
            o->oAction = 18;
            return;
        }
    }

    print_text_fmt_int(20, 80, "R %d", sHandheldShakeRoll);
}

void bat_init()
{

}

void bat_loop()
{
    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);
    o->oPosZ += o->oVelZ;
    if (o->oPosZ > 5000.f)
    {
        o->activeFlags = 0;
    }
    
    if (gMarioStates->pos[1] < 140.f)
    {
        f32 dx = gMarioStates->pos[0] - o->oPosX;
        f32 dz = o->oPosZ;
        f32 d = dx*dx/2.f + dz*dz;
        if (d < 5000.f && gMarioStates->health > 0x80)
        {
            // gMarioStates->health -= 0x100;
            spawn_mist_particles();
            o->activeFlags = 0;
        }
    }
}
