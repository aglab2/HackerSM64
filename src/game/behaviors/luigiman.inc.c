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