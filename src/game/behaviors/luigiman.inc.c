void luigiman_rings_init()
{

}

extern const Collision luigiman_rings_collision[];
void luigiman_rings_loop(void) {
    o->oMoveAngleYaw += 0x2F;

    load_object_collision_model();
}

void luigiman_spinning_holes1_init()
{

}

extern const Collision luigiman_spinning_holes1_collision[];
void luigiman_spinning_holes1_loop(void) {
    o->oMoveAngleYaw += 0xFF;

    load_object_collision_model();
}

void luigiman_moving_plat_init() {
    o->oHiddenObjectSwitchObj = NULL;
}

extern const Collision luigiman_spinning_holes1_collision[];
void luigiman_moving_plat_loop(void) {
    if (o->oHiddenObjectSwitchObj == NULL) {
        o->oHiddenObjectSwitchObj = cur_obj_nearest_object_with_behavior(bhvLuigimanPurpleSwitch);
    }

    if (o->oBehParams2ndByte != 0) {
        if (o->oTimer == 0) {
            o->oPosX -= 300.0f;
        }
        o->oPosX += sins(o->oTimer) * 35.0f;
    } else {
        o->oPosX -= sins(o->oTimer) * 33.0f;
    }

    if ((o->oHiddenObjectSwitchObj != NULL) && (o->oHiddenObjectSwitchObj->oAction == PURPLE_SWITCH_ACT_TICKING)) {
        if (o->oPosY <= 2300.0f) {
            o->oPosY += 30.0f;
        }
    }

    if ((o->oHiddenObjectSwitchObj != NULL) && (o->oHiddenObjectSwitchObj->oAction == PURPLE_SWITCH_ACT_IDLE)) {
        if (o->oPosY >= 1300.0f) {
            o->oPosY -= 30.0f;
        }
    }

    o->oTimer += 0x100;

    load_object_collision_model();
}

void luigiman_purple_switch_init()
{

}

void luigiman_purple_switch_loop()
{
    switch (o->oAction) {
        case PURPLE_SWITCH_ACT_IDLE:
            cur_obj_set_model(MODEL_PURPLE_SWITCH);
            cur_obj_scale(1.5f);
            if (
                gMarioObject->platform == o
                && !(gMarioStates[0].action & MARIO_NO_PURPLE_SWITCH)
                && lateral_dist_between_objects(o, gMarioObject) < 127.5f
            ) {
                o->oAction = PURPLE_SWITCH_ACT_PRESSED;
            }
            break;

        case PURPLE_SWITCH_ACT_PRESSED:
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                o->oAction = PURPLE_SWITCH_ACT_TICKING;
                cur_obj_shake_screen(SHAKE_POS_SMALL);
            }
            break;

        case PURPLE_SWITCH_ACT_TICKING:
            if (o->oTimer < 360) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
            }
            if (o->oTimer > 200) {
                o->oAction = PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF;
            }
            break;

        case PURPLE_SWITCH_ACT_UNPRESSED:
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_ACT_IDLE;
            }
            break;

        case PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF:
            if (!cur_obj_is_mario_on_platform()) {
                o->oAction = PURPLE_SWITCH_ACT_UNPRESSED;
            }
            break;
    }
}

void bhv_luigiman_bullet_bill_init(void) {
    o->oBulletBillInitialMoveYaw = o->oMoveAngleYaw;
}

void luigiman_bullet_bill_act_0(void) {
    cur_obj_become_tangible();
    o->oForwardVel = 0.0f;
    o->oMoveAngleYaw = o->oBulletBillInitialMoveYaw;
    o->oFaceAnglePitch = 0;
    o->oFaceAngleRoll = 0;
    o->oMoveFlags = OBJ_MOVE_NONE;
    cur_obj_set_pos_to_home();
    o->oAction = 2;
}

void luigiman_bullet_bill_act_1(void) {
    f32 triggerDistance;

    if (gCurrLevelNum != LEVEL_SA) {
        triggerDistance = 1500.f; // Vanilla
    } else if (BPARAM2 == 0xFF) {
        triggerDistance = 5000.f;
    } else if (BPARAM2 == 0xFE) {
        triggerDistance = 1500.f;
    } else {
        triggerDistance = 2500.f;
    }
    s16 sp1E = abs_angle_diff(o->oAngleToMario, o->oMoveAngleYaw);
    if (sp1E < 0x2000 && 400.0f < o->oDistanceToMario && o->oDistanceToMario < triggerDistance) {
        o->oAction = 2;
    }
}

void luigiman_bullet_bill_act_2(void) {
    if (o->oTimer < 40) {
        o->oForwardVel = 6.0f;
    } else if (o->oTimer < 50) {
        if (o->oTimer % 2) {
            o->oForwardVel = 6.0f;
        } else {
            o->oForwardVel = -6.0f;
        }
    } else {
        if (o->oTimer > 70) {
            cur_obj_update_floor_and_walls();
        }

        spawn_object(o, MODEL_SMOKE, bhvWhitePuffSmoke);
        o->oForwardVel = 60.0f;

        if (o->oTimer == 50) {
            cur_obj_play_sound_2(SOUND_OBJ_POUNDING_CANNON);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
        }

        if (o->oTimer > 150 || o->oMoveFlags & OBJ_MOVE_HIT_WALL) {
            o->oAction = 3;
            spawn_mist_particles();
        }
    }
}

void luigiman_bullet_bill_act_3(void) {
    o->oAction = 0;
}

void luigiman_bullet_bill_act_4(void) {
    if (o->oTimer == 0) {
        o->oForwardVel = -30.0f;
        cur_obj_become_intangible();
    }

    o->oFaceAnglePitch += 0x1000;
    o->oFaceAngleRoll += 0x1000;
    o->oPosY += 20.0f;

    if (o->oTimer > 90) {
        o->oAction = 0;
    }
}

ObjActionFunc sluigimanBulletBillActions[] = {
    luigiman_bullet_bill_act_0,
    luigiman_bullet_bill_act_1,
    luigiman_bullet_bill_act_2,
    luigiman_bullet_bill_act_3,
    luigiman_bullet_bill_act_4,
};

void bhv_luigiman_bullet_bill_loop(void) {
    cur_obj_call_action_function(sluigimanBulletBillActions);
    if (cur_obj_check_interacted()) {
        o->oAction = 4;
    }
}
