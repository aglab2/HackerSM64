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
        o->oPosX += sins(o->oTimer / 1.2f) * 35.0f / 1.2f;
    } else {
        o->oPosX -= sins(o->oTimer / 1.2f) * 33.0f / 1.2f;
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
            if (o->oTimer > 400) {
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

extern const BehaviorScript bhvLuigimanAirlockDoor[];
extern void bhv_luigiman_airlock_init()
{
    struct Object** doors = &o->oLuigimanDoors;
    doors[0] = spawn_object(o, MODEL_LUIGIMAN_AIRLOCK_DOOR, bhvLuigimanAirlockDoor);
    doors[1] = spawn_object(o, MODEL_LUIGIMAN_AIRLOCK_DOOR, bhvLuigimanAirlockDoor);

    doors[0]->oPosX -= 45.f;
    doors[0]->oPosY -= 90.f;
    doors[0]->oPosZ -= 545.f;

    doors[1]->oPosX -= 45.f;
    doors[1]->oPosY -= 90.f;
    doors[1]->oPosZ += 615.f;
}

#define AIRLOCK_DOOR_CHANGE_SPEED 25.f

enum
{
    AIRLOCK_INIT,
    AIRLOCK_CHANGE_DOORS,
    AIRLOCK_PERFORM_LOCK,
    AIRLOCK_PERFORM_UNLOCK,
    AIRLOCK_WAIT_FOR_LEAVE,
};

extern Gfx mat_mario_red[];
extern Gfx mat_mario_logo[];
extern Lights1 mario_blue_lights;
extern Lights1 mario_red_lights;

extern u8 gLowGravityEnabled;
static void airlock_switch_airlock(u8 value)
{
    u8 newGravity = (!!o->oBehParams2ndByte) ^ value;
    if (gLowGravityEnabled == newGravity)
        return;

    gLowGravityEnabled = newGravity;
    {
        void** ptr = segmented_to_virtual(mat_mario_red);
        ptr[9] = gLowGravityEnabled ? &mario_blue_lights.l[0] : &mario_red_lights.l[0];
        ptr[11] = gLowGravityEnabled ? &mario_blue_lights.a : &mario_red_lights.a;
    }
    {
        void** ptr = segmented_to_virtual(mat_mario_logo);
        ptr[39] = gLowGravityEnabled ? &mario_blue_lights.l[0] : &mario_red_lights.l[0];
        ptr[41] = gLowGravityEnabled ? &mario_blue_lights.a : &mario_red_lights.a;
    }
    
    for (int i = 0; i < 10; i++)
    {
        struct Object* particle = spawn_object(o, MODEL_MIST, bhvWhitePuffExplosion);
        if (!particle)
            continue;

        particle->oPosX = gMarioStates->pos[0];
        particle->oPosY = gMarioStates->pos[1];
        particle->oPosZ = gMarioStates->pos[2];
        particle->oBehParams2ndByte = 2;
        particle->oMoveAngleYaw = random_u16();
        particle->oGravity = 0;
        particle->oDragStrength = 0;
        particle->oForwardVel = random_float() * 5.f + 30.f;
        particle->oVelY = random_float() * 5.f + 20.f;
        obj_scale(particle, random_float() * 1.f + 3.f);
    }
}

static void airlock_door_play_switch_sound(struct Object* door)
{
    if (0 != o->oTimer)
    {
        return;
    }

    s32 magic = door->oAction ? SOUND_GENERAL_CLOSE_IRON_DOOR : SOUND_GENERAL_OPEN_IRON_DOOR;
    play_sound(magic, door->header.gfx.cameraToObject);
}

extern void bhv_luigiman_airlock_loop()
{
    // print_text_fmt_int(20, 20, "%d", gLowGravityEnabled);

    struct Object** doors = &o->oLuigimanDoors;
    if (AIRLOCK_INIT == o->oAction)
    {
        // scanning for lads nearby
        // for Y & X coordinates for both doors are equal
        f32 yMid = o->oPosY - 90.f;
        s8 nearLockCylinder = absf(yMid - gMarioStates->pos[1]) < 800.f && absf(doors[0]->oPosX - gMarioStates->pos[0]) < 800.f;

        // there is a leaveaway between nearDoor* and inside to allow nearDoor to be triggered first
        s8 nearDoor[2];
        nearDoor[0] = nearLockCylinder && (doors[0]->oPosZ - 1000.f < gMarioStates->pos[2] && gMarioStates->pos[2] < doors[0]->oPosZ);
        nearDoor[1] = nearLockCylinder && (doors[1]->oPosZ          < gMarioStates->pos[2] && gMarioStates->pos[2] < doors[1]->oPosZ + 1000.f);

        // XOR tells us if state mismatch happens hence it wants to either be opened or closed
        s8 wantsToChange[2];
        for (int i = 0; i < 2; i++)
            wantsToChange[i] = nearDoor[i] ^ doors[i]->oAction;

        // first find if any door wants to close, if it does, alter its state
        // it should not happen that both wants to close at the same time as such condition is invalid.
        // we can handle it somewhat gracefully though by just doing 1 by 1
        for (int i = 0; i < 2; i++)
        {
            s8 wantsToClose = wantsToChange[i] & !nearDoor[i];
            if (wantsToClose)
            {
                o->oLuigimanDoorToAlter = i;
                o->oAction = AIRLOCK_CHANGE_DOORS;
                return;
            }
        }

        // no one feels like closing the doors, but maybe they want to open them?
        // just check it and let them do the job
        // notice that nearDoor[0] & nearDoor[1] cannot be 'true' at the same time so let's bug on it
        if (nearDoor[0] && nearDoor[1])
        {
            print_text_fmt_int(20, 20, "OOPS %d", 0);
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            if (wantsToChange[i])
            {
                o->oLuigimanDoorToAlter = i;
                o->oAction = AIRLOCK_CHANGE_DOORS;
                return;
            }
        }

        // no one wants to do anything, start checks for the airlock switching

        // if mario is inside the airlock, start the transition
        // adjust lo and hi limits for inside, when door is opened we need to make sure mario is in
        // otherwise just use raw values.
        f32 lo = doors[0]->oPosZ;
        if (doors[0]->oAction)
            lo += 100.f;

        f32 hi = doors[1]->oPosZ;
        if (doors[1]->oAction)
            hi -= 100.f;
    
        s8 inside = nearLockCylinder && (lo < gMarioStates->pos[2] && gMarioStates->pos[2] < hi);
        if (inside)
        {
            // hopefully here one of the doors is opened :)
            int cnt = doors[0]->oAction + doors[1]->oAction;
            if (0 == cnt)
            {
                // this might happen when someone jumped while the door was closing.
                // the oLuigimanDoorLastClosed is considered to be closed as in AIRLOCK_PERFORM_LOCK
                // this means the other door needs to be opened, do it
                o->oLuigimanDoorToEventuallyOpen = !o->oLuigimanDoorLastClosed;
                struct Object* doorToClose = doors[o->oLuigimanDoorLastClosed];
                airlock_switch_airlock(doorToClose->oPosZ > gMarioStates->pos[2]);
                o->oAction = AIRLOCK_PERFORM_UNLOCK;
                return;
            }
            else if (1 == cnt)
            {
                // to eventually open the door that is closed -> oAction==0 for it
                o->oLuigimanDoorToEventuallyOpen = (0 == doors[1]->oAction);
                o->oAction = AIRLOCK_PERFORM_LOCK;
                return;
            }
            else
            {
                // both doors are opened, this is a bug. bail
                print_text_fmt_int(20, 20, "OOPS %d", 1);
                return;
            }
        }
    }
    else if (AIRLOCK_CHANGE_DOORS == o->oAction)
    {
        // switch state of door for 'oLuigimanDoorToAlter'   
        struct Object* door = doors[o->oLuigimanDoorToAlter];
        airlock_door_play_switch_sound(door);

        if (30 == o->oTimer)
        {
            door->oAction = !door->oAction;
            if (0 == door->oAction)
            {
                // the door was just closed, keep it for the future
                o->oLuigimanDoorLastClosed = o->oLuigimanDoorToAlter;
            }
            o->oAction = AIRLOCK_INIT;
            return;
        }

        door->oPosY += door->oAction ? AIRLOCK_DOOR_CHANGE_SPEED : -AIRLOCK_DOOR_CHANGE_SPEED;
    }
    else if (AIRLOCK_PERFORM_LOCK == o->oAction)
    {
        // do the door locking as mario is inside
        struct Object* doorToClose = doors[!o->oLuigimanDoorToEventuallyOpen];
        airlock_door_play_switch_sound(doorToClose);
        if (o->oTimer < 30)
        {
            // lower the door, both will be closed
            doorToClose->oPosY += AIRLOCK_DOOR_CHANGE_SPEED;
        }
        else
        {
            // perform the next step
            // it is also the time when we should decide if mario actually crossed the airlock
            airlock_switch_airlock(doorToClose->oPosZ > gMarioStates->pos[2]);
            doorToClose->oAction = 0;
            o->oAction = AIRLOCK_PERFORM_UNLOCK;
            return;
        }
    }
    else if (AIRLOCK_PERFORM_UNLOCK == o->oAction)
    {
        // do the door opening and switch gravity
        struct Object* doorToOpen = doors[o->oLuigimanDoorToEventuallyOpen];
        airlock_door_play_switch_sound(doorToOpen);
        if (o->oTimer < 30)
        {
            // raised the other door
            doorToOpen->oPosY -= AIRLOCK_DOOR_CHANGE_SPEED;
        }
        else
        {
            // swap the current states and wait for mario to leave
            doorToOpen ->oAction = 1;
            o->oAction = AIRLOCK_WAIT_FOR_LEAVE;
        }
    }
    else if (AIRLOCK_WAIT_FOR_LEAVE == o->oAction)
    {
        // wait while mario gets out of the lock
        // door will be closed automatically as xor condition will decide
        s8 stillInside = (doors[0]->oPosZ + 50.f < gMarioStates->pos[2] && gMarioStates->pos[2] < doors[1]->oPosZ - 50.f);
        if (!stillInside)
        {
            o->oAction = AIRLOCK_INIT;
        }
    }
}

void bhv_luigiman_respawn_loop()
{
    if (0 == o->oAction)
    {
        struct Surface* floor = gMarioStates->floor;
        int type = floor ? floor->type : 0;
        if (gMarioStates->floorHeight == gMarioStates->pos[1] && type == SURFACE_QUICKSAND && gMarioStates->action != ACT_LEDGE_GRAB && gMarioStates->health > 0x100)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0, 0, 0);
            gAllowPausing = 0;
            o->oAction = 1;
        }
    }
    else 
    {
        if (o->oTimer == 12)
        {
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY;
            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw;
            gMarioStates->squishTimer = 0;
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
            reset_camera(gCamera);
        }
        if (o->oTimer == 13)
        {
            reset_camera(gCamera);
        }
        if (o->oTimer == 14)
        {
            reset_camera(gCamera);
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0,0,0);
            gAllowPausing = 1;
            o->oAction = 0;
        }
    }
}
