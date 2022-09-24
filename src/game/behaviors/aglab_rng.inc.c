extern const BehaviorScript bhvAglabRngCollision[];

extern const Collision rng_mushroom_collision[];
extern const Collision rng_pyramid_collision[];

static void rng_reroll()
{
    cur_obj_unload_object_with_behavior(bhvAglabRngCollision);
    cur_obj_unload_object_with_behavior(bhvExclamationBox);

    switch(gCurrentArea->index)
    {
        // mushrooms
        case 2:
        {
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
        // pyramid
        case 3:
        {
            for (int i = 0; i < 10; i++)
            {
                struct Object* pyr = spawn_object(o, MODEL_AGLAB_RNG_PYRAMID, bhvAglabRngCollision);
                pyr->oPosX = random_float_ft(-927.f, 1389.f);
                pyr->oPosY = 3250.f - random_float() * 1300.f;
                pyr->oPosZ = random_float_ft(-1900.f, 5070.f);
                pyr->oBehParams2ndByte = 1;
                pyr->oFaceAngleYaw = random_u16() & 0xe000;
            }
        }
        break;
    }
}

static f32 rng_z_attempt_threshold()
{
    switch(gCurrentArea->index)
    {
        case 1: return  2806.f;
        case 2: return -1500.f;
        case 3: return  5270.f;
        case 4: return  2049.f;
        case 5: return  2193.f;
        case 6: return  4477.f;
        case 7: return  2177.f;
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
        int attempt = (o->oDistanceToMario > 500.f) || (gMarioStates->pos[2] < rng_z_attempt_threshold());
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
        case 1:
        {
            obj_set_collision_data(o, rng_pyramid_collision);
            obj_scale_xyz(o, 1.1f, 1.1f, 1.1f);
            break;
        }
    }
}
