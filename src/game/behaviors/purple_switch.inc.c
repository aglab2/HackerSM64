
void bhv_purple_switch_init_rovert(void) {
    struct Object *gate;

        if (gCurrLevelNum==LEVEL_ROVERT) {//rovert purpleswitch init
        if (gCurrAreaIndex == 1) {
            //present
            if (gRovertPurpleSwitchState == 1) {
                o->header.gfx.scale[1] = 0.2f;
                o->header.gfx.scale[0] = 1.5f;
                o->header.gfx.scale[2] = 1.5f;
                o->oAction = 0xFF;
            }
        } else {
            //future
            gate = cur_obj_nearest_object_with_behavior(bhvRovertGate);
            if (gRovertPurpleSwitchState > 0) {
                o->header.gfx.scale[1] = 0.2f;
                o->header.gfx.scale[0] = 1.5f;
                o->header.gfx.scale[2] = 1.5f;
                o->oAction = 0xFF;
            }
            if (gRovertPurpleSwitchState == 1) {
                if (gate) {
                    obj_mark_for_deletion(gate);
                }
            }
        }
    }
}

/**
 * Behavior for bhvFloorSwitchHardcodedModel, bhvFloorSwitchGrills, and
 * bhvFloorSwitchAnimatesObject.
 *
 * This controls the purple switches that Mario can step on to affect parts of
 * the environment.
 */

void bhv_purple_switch_loop(void) {
    switch (o->oAction) {
        /**
         * Set the switch's model and scale. If Mario is standing near the
         * switch's middle section, transition to the pressed state.
         */
        case PURPLE_SWITCH_ACT_IDLE:
            cur_obj_set_model(MODEL_PURPLE_SWITCH);
            cur_obj_scale(1.5f);
            if (
                gMarioObject->platform == o
                && !(gMarioStates[0].action & MARIO_NO_PURPLE_SWITCH)
                && lateral_dist_between_objects(o, gMarioObject) < 127.5f
            ) {
                //no level check because this variable does not affect anything outside rovert level
                if (gCurrAreaIndex == 1) {
                    //present
                    gRovertPurpleSwitchState = 1;
                } else {
                    //future
                    if (gRovertPurpleSwitchState == 0) {
                        gRovertPurpleSwitchState = 2;
                    }
                }
                o->oAction = PURPLE_SWITCH_ACT_PRESSED;
            }
            break;

        /**
         * Collapse the switch downward, play a sound, and shake the screen.
         * Immediately transition to the ticking state.
         */
        case PURPLE_SWITCH_ACT_PRESSED:
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 1.5f, 0.2f);
            if (o->oTimer == 3) {
                cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
                switch(gCurrLevelNum) {
                    case LEVEL_SA:
                    case LEVEL_ROVERT:
                        o->oAction = 0xFF;
                        break;
                    default:
                        o->oAction = PURPLE_SWITCH_ACT_TICKING;
                        break;
                }
                
                cur_obj_shake_screen(SHAKE_POS_SMALL);
#if ENABLE_RUMBLE
                queue_rumble_data(5, 80);
#endif
            }
            break;

        /**
         * Play a continuous ticking sound that gets faster when time is almost
         * up. When time is up, move to a waiting-while-pressed state.
         */
        case PURPLE_SWITCH_ACT_TICKING:
            if (o->oBehParams2ndByte != 0) {
                if (o->oBehParams2ndByte == 1 && gMarioObject->platform != o) {
                    o->oAction++;
                } else {
                    if (o->oTimer < 360) {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
                    } else {
                        play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
                    }
                    if (o->oTimer > 400) {
                        o->oAction = PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF;
                    }
                }
            }
            break;

        /**
         * Make the switch look unpressed again, and transition back to the
         * idle state.
         */
        case PURPLE_SWITCH_ACT_UNPRESSED:
            cur_obj_scale_over_time(SCALE_AXIS_Y, 3, 0.2f, 1.5f);
            if (o->oTimer == 3) {
                o->oAction = PURPLE_SWITCH_ACT_IDLE;
            }
            break;

        /**
         * Mario is standing on the switch, but time has expired. Wait for
         * him to get off the switch, and when he does so, transition to the
         * unpressed state.
         */
        case PURPLE_SWITCH_ACT_WAIT_FOR_MARIO_TO_GET_OFF:
            if (!cur_obj_is_mario_on_platform()) {
                o->oAction = PURPLE_SWITCH_ACT_UNPRESSED;
            }
            break;
    }
}
