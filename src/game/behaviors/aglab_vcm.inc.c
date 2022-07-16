static void set_gravity(s32 grav)
{
    if (grav == gIsGravityFlipped)
        return;

    gIsGravityFlipped = grav;
            
    if (gIsGravityFlipped)
        play_sound(SOUND_MENU_CAMERA_ZOOM_IN, gMarioObject->header.gfx.pos);
    else
        play_sound(SOUND_MENU_CAMERA_ZOOM_OUT, gMarioObject->header.gfx.pos);

    gMarioState->pos[1] = 8825.f - gMarioState->pos[1]; // Transform position. The extra 165 is due to Mario's visual model.
    if ((gMarioState->action == ACT_CRAZY_BOX_BOUNCE) || (gMarioState->action == ACT_SHOT_FROM_CANNON))
        gMarioState->pos[1] += 165.f;
    else if ((gMarioState->action == ACT_DIVE) || (gMarioState->action == ACT_FLYING))
        gMarioState->pos[1] += 65.f;

    gMarioState->vel[1] = -gMarioState->vel[1]; // Flip velocity
    gMarioState->peakHeight = 9000.f - gMarioState->peakHeight; // For fall damage
    gMarioObject->hitboxDownOffset = (gIsGravityFlipped ? 160.f : 0.f); // Adjust hitbox when upside down
}

void vcm_ctl_loop()
{
    gMarioStates->health = 0x880;

    s32 on_floor = gMarioStates->floorHeight == gMarioStates->pos[1];
    if (!gIsGravityFlipped
      && on_floor
      && (gMarioStates->pos[0] < 4000.f || gMarioStates->pos[2] > -3000.f)
      && gMarioStates->pos[1] > -1500.f)
    {
        o->oVcmLastGoodY = gMarioStates->pos[1];
    }

    if (gMarioState->wallkickedOf == SURFACE_HARD_NOT_SLIPPERY)
    {
        set_gravity(!gIsGravityFlipped);
    }
    gMarioState->wallkickedOf = 0;

    if (0 == o->oAction)
    {
        if (!gIsGravityFlipped && gMarioStates->pos[1] < -1329.f)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
            o->oAction = 1;
            return;
        }
        if (gIsGravityFlipped && gMarioStates->pos[1] < 4784.f)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
            o->oAction = 1;
            return;
        }

        u32 val4 = get_dialog_id() >= 0;
        u32 intangible = (gMarioState->action & ACT_FLAG_INTANGIBLE) != 0;
        if (!intangible
        && !val4
        && !gWarpTransition.isActive
        && sDelayedWarpOp == WARP_OP_NONE
        && on_floor
        && (gPlayer1Controller->buttonPressed & L_TRIG))  { // Flip gravity
            set_gravity(!gIsGravityFlipped);
        }
    }
    else
    {
        if (o->oTimer == 12)
        {
            set_gravity(0);
            if (gMarioStates->pos[0] < -3500.f)
            {
                // yellow
                gMarioStates->pos[0] = -3184.f;
                gMarioStates->pos[1] = 229.f;
                gMarioStates->pos[2] = 21.f;
                gMarioStates->faceAngle[1] = -0x4000;
            }
            else if (gMarioStates->pos[0] > 0.f && gMarioStates->pos[2] < -3000.f && o->oVcmLastGoodY > 2188.f)
            {
                // no A press
                gMarioStates->pos[0] = 5085.f;
                gMarioStates->pos[1] = 2636.f;
                gMarioStates->pos[2] = -2219.f;
                gMarioStates->faceAngle[1] = 0x8000;
            }
            else if (gMarioStates->pos[0] > 4000.f && gMarioStates->pos[2] > 3500.f && o->oVcmLastGoodY < 20.f)
            {
                // shoot wall jump bruh
                gMarioStates->pos[0] = 6000.f;
                gMarioStates->pos[1] = 438.f;
                gMarioStates->pos[2] = 3772.f;
                gMarioStates->faceAngle[1] = 0;
            }
            else if (gMarioStates->pos[0] > 3000.f && o->oVcmLastGoodY > 2188.f)
            {
                // the top
                gMarioStates->pos[0] = 6899.f;
                gMarioStates->pos[1] = 2591.f;
                gMarioStates->pos[2] = -98.f;
                gMarioStates->faceAngle[1] = -0x4000;
            }
            else
            {
                gMarioStates->pos[0] = 0;
                gMarioStates->pos[1] = 700.f;
                gMarioStates->pos[2] = 0;
                gMarioStates->faceAngle[1] = 0;
            }
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
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
            o->oAction = 0;
        }
    }
}

void vcm_arrow_loop()
{
    f32 d;
    obj_scale(o, 0.3f);
    struct Object* red = cur_obj_find_nearest_object_with_behavior_y_biased(bhvRedCoin);
    if (!red)
    {
        cur_obj_hide();
        return;
    }

    // TODO:
    if (0)
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
    
    o->oPosX = gMarioStates->pos[0];
    o->oPosY = gIsGravityFlipped ? (9000.f - gMarioStates->pos[1] - 150.f) : (gMarioStates->pos[1] + 150.f);
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
