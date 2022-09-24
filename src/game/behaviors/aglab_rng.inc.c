extern const BehaviorScript bhvAglabRngCollision[];

extern const Collision rng_mushroom_collision[];

static void rng_reroll()
{
    cur_obj_unload_object_with_behavior(bhvAglabRngCollision);
    cur_obj_unload_object_with_behavior(bhvExclamationBox);

    switch(gCurrentArea->index)
    {
        // mushrooms
        case 2:
        {
            // (3031, 2550, -1692) - (5475, 2550, -8671)
            for (int i = 0; i < 15; i++)
            {
                struct Object* mush = spawn_object(o, MODEL_AGLAB_RNG_MUSHROOM, bhvAglabRngCollision);
                mush->oPosX = random_float_ft(3031.f, 5475.f);
                mush->oPosY = 3050.f - random_float() * 1300.f;
                mush->oPosZ = random_float_ft(-8671.f, -1692.f);
                mush->oBehParams2ndByte = 0;
            }
        }
        break;
    }
}

static f32 rng_z_attempt_threshold()
{
    switch(gCurrentArea->index)
    {
        case 2: return -1500.f;
    }
}

void bhv_aglab_rng_init()
{
    rng_reroll();
}

u8 gWarpTrigger = 0;
void bhv_aglab_rng_loop()
{
    if (gWarpTrigger)
    {
        rng_reroll();
    }

    gWarpTrigger = 0;
    if (0 == o->oAction)
    {
        int attempt = (o->oDistanceToMario > 300.f) || (gMarioStates->pos[2] < rng_z_attempt_threshold());
        if (attempt)
        {
            if (L_TRIG & gPlayer1Controller->buttonPressed)
            {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
                o->oAction = 1;
            }
        }
        else
        {
            if (L_TRIG & gPlayer1Controller->buttonPressed)
            {
                rng_reroll();
            } 
        }
    }
    else if (1 == o->oAction)
    {
        if (o->oTimer == 12)
        {
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY + 100.f;
            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
            gMarioStates->faceAngle[1] = 0x8000;
            rng_reroll();
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
        }
        if (o->oTimer == 13)
        {
            reset_camera(gCamera);
        }
        if (o->oTimer == 14)
        {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0,0,0);
            o->oAction = 0;
        }
    }
}

void bhv_aglab_rng_collision_init()
{
    switch(o->oBehParams2ndByte)
    {
        case 0:
        {
            obj_set_collision_data(o, rng_mushroom_collision);
            break;
        }
    }
}
