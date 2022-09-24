extern const BehaviorScript bhvAglabRngCollision[];

extern const Collision rng_mushroom_collision[];
extern const Collision rng_pyramid_collision[];
extern const Collision rng_shape1_collision[];
extern const Collision rng_shape2_collision[];
extern const Collision rng_shape3_collision[];
extern const Collision rng_shape4_collision[];
extern const Collision rng_cactus_collision[];
extern const Collision rng_cactus2_collision[];

static void rng_reroll()
{
    cur_obj_unload_object_with_behavior(bhvAglabRngCollision);
    cur_obj_unload_object_with_behavior(bhvExclamationBox);

    switch(gCurrentArea->index)
    {
        // mushrooms
        case 2:
        {
            f32 d;
            struct Object* sign = cur_obj_find_nearest_object_with_behavior(bhvMessagePanel, &d);
            sign->oPosX = random_float_ft(3831.f, 4658.f);
            sign->oPosZ = random_float_ft(-1339.f, -949.f);
            sign->oFaceAngleYaw = random_u16();

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
        // cacti
        case 4:
        {
            for (int i = 0; i < 25; i++)
            {
                // (Y=4148, Z=-4143) - (Y=2164, Z=2450)
                int model = random_u16() & 1;
                struct Object* pyr = spawn_object(o, MODEL_AGLAB_RNG_CACTUS + model, bhvAglabRngCollision);
                pyr->oPosX = random_float_ft(86.f, 2536.f);
                pyr->oPosZ = random_float_ft(-5200.f, 1800.f);
                f32 yr = 4148.f - (4143.f + pyr->oPosZ) / 3.f;
                pyr->oPosY = yr + random_float() * 1000.f;
                pyr->oBehParams2ndByte = 6 + model;
                pyr->oFaceAngleYaw = random_u16();
            }
        }
        break;
        // shapes
        case 6:
        {
            for (int i = 0; i < 10; i++)
            {
                int model = random_u16() & 3;
                struct Object* pyr = spawn_object(o, MODEL_AGLAB_RNG_SHAPE1 + model, bhvAglabRngCollision);
                pyr->oPosX = random_float_ft(933.f, 3383.f);
                pyr->oPosY = 3050.f - random_float() * 1300.f;
                pyr->oPosZ = random_float_ft(-2500.f, 4000.f);
                pyr->oBehParams2ndByte = 2 + model;
                pyr->oFaceAngleYaw = random_u16() & 0xc000;
                pyr->oFaceAngleRoll = random_u16() & 0xc000;
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

u8 gWarpTrigger = 0;
void bhv_aglab_rng_init()
{
    if (2 != gCurrentArea->index)
    {
        rng_reroll();
    }

    gWarpTrigger = 0;
}

void bhv_aglab_rng_loop()
{
    if (gWarpTrigger)
    {
        rng_reroll();
        gWarpTrigger = 0;
    }

    if (4 == gCurrentArea->index)
    {
        gMarioStates->flags |= MARIO_METAL_CAP;
    }
    
    if (0 == o->oAction)
    {
        int attempt = (o->oDistanceToMario > 500.f) || (gMarioStates->pos[2] < rng_z_attempt_threshold());
        if (attempt)
        {
            if (L_TRIG & gPlayer1Controller->buttonPressed)
            {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
                o->oAction = 1;
                return;
            }
        }
        else
        {
            if (L_TRIG & gPlayer1Controller->buttonPressed)
            {
                rng_reroll();
            }
        }

        if (gMarioStates->floorHeight == gMarioStates->pos[1] && (gMarioStates->action != ACT_LAVA_BOOST_LAND) && (gMarioStates->action != ACT_LAVA_BOOST))
        {
            struct Surface* floor = gMarioStates->floor;
            if (floor && (floor->type == SURFACE_SHALLOW_QUICKSAND))
            {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
                o->oAction = 1;
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
        }
        break;
        case 1:
        {
            obj_set_collision_data(o, rng_pyramid_collision);
            obj_scale_xyz(o, 1.1f, 1.1f, 1.1f);
        }
        break;
        case 2:
        {
            obj_set_collision_data(o, rng_shape1_collision);
            obj_scale_xyz(o, 0.7f, 0.7f, 0.7f);
        }
        break;
        case 3:
        {
            obj_set_collision_data(o, rng_shape2_collision);
            obj_scale_xyz(o, 0.7f, 0.7f, 0.7f);
        }
        break;
        case 4:
        {
            obj_set_collision_data(o, rng_shape3_collision);
            obj_scale_xyz(o, 0.7f, 0.7f, 0.7f);
        }
        break;
        case 5:
        {
            obj_set_collision_data(o, rng_shape4_collision);
            obj_scale_xyz(o, 0.7f, 0.7f, 0.7f);
        }
        break;
        case 6:
        {
            obj_set_collision_data(o, rng_cactus_collision);
        }
        break;
        case 7:
        {
            obj_set_collision_data(o, rng_cactus2_collision);
        }
        break;
    }
}
