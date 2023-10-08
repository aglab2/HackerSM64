// controllable_platform.inc.c

static s8 sControllablePlatformDirectionState = 0;

void controllable_platform_act_1(void) {
    o->oParentRelativePosY -= 4.0f;
    if (o->oParentRelativePosY < 41.0f) {
        o->oParentRelativePosY = 41.0f;
        o->oAction = 2;
    }
}

static const int sWhenActives[5] = { 2, 4, 7, 10, 15 };

void controllable_platform_act_2(void) {
    if (o->oBehParams2ndByte == sControllablePlatformDirectionState) {
        return;
    }

    o->oParentRelativePosY += 4.0f;
    if (o->oParentRelativePosY > 51.0f) {
        o->oParentRelativePosY = 51.0f;
        o->oAction = 0;
    }
}

void bhv_controllable_platform_sub_loop(void) {
    if (gMarioStates->numStars >= sWhenActives[o->oBehParams2ndByte - 1])
    {
        switch (o->oAction) {
            case 0:
                if (o->oTimer < 30) {
                    break;
                }

                if (gMarioObject->platform == o) {
                    sControllablePlatformDirectionState = o->oBehParams2ndByte;
                    o->parentObj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                    o->oAction = 1;
                    cur_obj_play_sound_2(SOUND_GENERAL_MOVING_PLATFORM_SWITCH);
                }
                break;

            case 1:
                controllable_platform_act_1();
                break;

            case 2:
                controllable_platform_act_2();
                break;
        }
        cur_obj_unhide();
    }
    else
    {
        cur_obj_hide();
    }

    o->oVelY = o->parentObj->oVelY;

    if (o->parentObj->activeFlags == ACTIVE_FLAG_DEACTIVATED) {
        o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
    }
}

void bhv_controllable_platform_init(void) {
    struct Object *sp34;

    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM1, bhvControllablePlatformSub,
                                      0, 51, -204, 0, -0x8000, 0);
    sp34->oBehParams2ndByte = 1;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM2, bhvControllablePlatformSub,
                                     -204, 51, 0, 0, -0x4000, 0);
    sp34->oBehParams2ndByte = 2;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM3, bhvControllablePlatformSub,
                                     0, 51, 204, 0, 0, 0);
    sp34->oBehParams2ndByte = 3;
    sp34 = spawn_object_rel_with_rot(o, MODEL_HMC_METAL_ARROW_PLATFORM4, bhvControllablePlatformSub,
                                      204, 51, 0, 0, 0x4000, 0);
    sp34->oBehParams2ndByte = 4;

    sControllablePlatformDirectionState = 0;

    o->oControllablePlatformInitPosY = o->oPosY;
}

void controllable_platform_hit_wall(s8 nextDirection) {
    o->oControllablePlatformWallHitDirection = nextDirection;
    o->oTimer = 0;
    sControllablePlatformDirectionState = 5;

    cur_obj_play_sound_2(SOUND_GENERAL_QUIET_POUND1);
#if ENABLE_RUMBLE
    queue_rumble_data(50, 80);
#endif
}

void controllable_platform_check_walls() {
    if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 400)) {
        sControllablePlatformDirectionState = 6;
        o->oControllablePlatformIsFarFromMario = 1;
        o->oTimer = 0;
    }
}

void controllable_platform_shake_on_wall_hit(void) {
    if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 400)) {
        sControllablePlatformDirectionState = 6;
        o->oTimer = 0;
    }
}

void controllable_platform_tilt_from_mario(void) {
    s16 dx = gMarioObject->header.gfx.pos[0] - o->oPosX;
    s16 dz = gMarioObject->header.gfx.pos[2] - o->oPosZ;

    if (gMarioObject->platform == o
        || gMarioObject->platform == cur_obj_nearest_object_with_behavior(bhvControllablePlatformSub)) {
        o->oFaceAnglePitch = dz * 4;
        o->oFaceAngleRoll = -dx * 4;
        if (sControllablePlatformDirectionState == 6) {
            sControllablePlatformDirectionState = 0;
            o->oTimer = 0;
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        }
    }
}

void bhv_controllable_platform_loop(void) {
    s8 wallDisplacement[3];
    Vec3f dist1, dist2, dist3;

    o->oAngleVelRoll = 0;
    o->oAngleVelPitch = 0;
    o->oVelY = 0;

    switch (sControllablePlatformDirectionState) {
        case 0:
            o->oFaceAnglePitch /= 2;
            o->oFaceAngleRoll /= 2;
            if (o->oControllablePlatformIsFarFromMario == 1 && o->oTimer > 30) {
                sControllablePlatformDirectionState = 6;
                o->oTimer = 0;
            }
            break;

        case 1:
            controllable_platform_check_walls();
            if (o->oPosY > 1600.f)
            {
                sControllablePlatformDirectionState = 5;
            }
            else
            {
                o->oVelY = 60.0f;
            }
            break;

        case 2:
            controllable_platform_check_walls();
            if (o->oPosY > 3200.f)
            {
                sControllablePlatformDirectionState = 5;
            }
            else
            {
                o->oVelY = 60.0f;
            }
            break;

        case 3:
            controllable_platform_check_walls();
            if (o->oPosY > 4800.f)
            {
                sControllablePlatformDirectionState = 5;
            }
            else
            {
                o->oVelY = 60.0f;
            }
            break;

        case 4:
            controllable_platform_check_walls();
            if (o->oPosY > 6400.f)
            {
                sControllablePlatformDirectionState = 5;
            }
            else
            {
                o->oVelY = 60.0f;
            }
            break;

        case 5:
            controllable_platform_shake_on_wall_hit();
            break;

        case 6:
            if (o->oPosY > 0)
                o->oVelY = -60.f;
            else
                o->oPosY = 0;

            break;
    }

    controllable_platform_tilt_from_mario();
    o->oPosY += o->oVelY;
    if (0 != o->oVelY) {
        cur_obj_play_sound_1(SOUND_ENV_ELEVATOR2);
    }
}
