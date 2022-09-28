

struct ObjectHitbox sRovertBoxHitbox = {
    /* interactType:      */ INTERACT_NONE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 420,
    /* height:            */ 300,
    /* hurtboxRadius:     */ 420,
    /* hurtboxHeight:     */ 300,
};

Vec3f sPushable_Time_Position[2];

void init_rovert_pushable(void) {
    if (gPushableInit == 0) {
        gPushableInit = TRUE;
        vec3f_copy(&sPushable_Time_Position[0],&o->oHomeX);
        vec3f_copy(&sPushable_Time_Position[1],&o->oHomeX);
    } else {
        vec3f_copy(&o->oPosVec,&sPushable_Time_Position[o->oBehParams2ndByte]);
    }
}

void rovert_pushable(void) {
    obj_set_hitbox(o, &sRovertBoxHitbox);
    o->oForwardVel = 0.0f;

    if (obj_check_if_collided_with_object(o, gMarioObject) && gMarioStates[0].flags & MARIO_PUSHING) {
        s16 angleToMario = obj_angle_to_object(o, gMarioObject);
        if (abs_angle_diff(angleToMario, gMarioObject->oMoveAngleYaw) > 0x4000) {
            o->oMoveAngleYaw = (s16)((gMarioObject->oMoveAngleYaw + 0x2000) & 0xc000);
            if (check_if_moving_over_floor(8.0f, 200.0f)) {
                o->oForwardVel = 6.0f;
                cur_obj_play_sound_1(SOUND_ENV_METAL_BOX_PUSH);
                if (o->oBehParams2ndByte == 0) {//present
                    vec3f_copy(&sPushable_Time_Position[0],&o->oPosVec);
                    vec3f_copy(&sPushable_Time_Position[1],&o->oPosVec);
                }else{//future
                    vec3f_copy(&sPushable_Time_Position[1],&o->oPosVec);
                }
            }
        }
    }

    cur_obj_move_using_fvel_and_gravity();
}

struct ObjectHitbox sRovertExclamationBoxHitbox = {
    /* interactType:      */ INTERACT_BREAKABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 40,
    /* height:            */ 30,
    /* hurtboxRadius:     */ 40,
    /* hurtboxHeight:     */ 30,
};

void rovert_exclamation(void) {
    switch(o->oAction) {
        case 0://init
            o->oAction = 1;

            if (gUsedHyper & (1 << o->oBehParams2ndByte)) {
                obj_mark_for_deletion(o);
            }
        break;
        case 1:
            obj_set_hitbox(o, &sRovertExclamationBoxHitbox);
            if (cur_obj_was_attacked_or_ground_pounded()) {

                gUsedHyper |= (1 << o->oBehParams2ndByte);
                create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
                spawn_mist_particles_variable(0, 0, 100.0f);
                spawn_object(o,MODEL_NONE,bhvTenCoinsSpawn);
                obj_mark_for_deletion(o);

            }
        break;
    }
}

f32 bigball_size = 1.0f;
void rovert_bigball(void) {
    switch(o->oAction) {
        case 0://init
            bigball_size = 1.0f;
            o->oAction = 1;
        break;
        case 1:
            if (o->oDistanceToMario < bigball_size*50.0f) {
                o->oAction = 2;
                set_mario_action(gMarioState, ACT_EATEN_BY_BUBBA, 0);
            }
            cur_obj_scale(bigball_size);
            bigball_size += 1.0f;
        break;
        case 2:
            cur_obj_scale(bigball_size);
            bigball_size += 1.0f;
        break;
    }

}