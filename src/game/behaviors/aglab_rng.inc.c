extern const BehaviorScript bhvAglabRngCollision[];

extern const Collision rng_mushroom_collision[];
extern const Collision rng_pyramid_collision[];
extern const Collision rng_shape1_collision[];
extern const Collision rng_shape2_collision[];
extern const Collision rng_shape3_collision[];
extern const Collision rng_shape4_collision[];
extern const Collision rng_cactus_collision[];
extern const Collision rng_cactus2_collision[];
extern const Collision rng_lamp_collision[];

extern const BehaviorScript bhvNoteblock_MOP[];
extern const BehaviorScript bhvSpring_MOP[];
extern const BehaviorScript bhvShrink_Platform_MOP[];
extern const BehaviorScript bhvCheckpoint_Flag_MOP[];
extern const BehaviorScript bhvMoving_Rotating_Block_MOP[];
extern const BehaviorScript bhvSandBlock_MOP[];

struct Object* spawn_for_mop(const BehaviorScript* bs, int model)
{
    if (0 == (random_u16() & 0x7))
    {
        return spawn_object(o, MODEL_AGLAB_RNG_SPRING, bhvSpring_MOP);
    }
    else
    {
        return spawn_object(o, model, bs);
    }
}

static void rng_reroll()
{
    cur_obj_unload_object_with_behavior(bhvAglabRngCollision);
    cur_obj_unload_object_with_behavior(bhvExclamationBox);
    cur_obj_unload_object_with_behavior(bhvNoteblock_MOP);
    cur_obj_unload_object_with_behavior(bhvSpring_MOP);
    cur_obj_unload_object_with_behavior(bhvShrink_Platform_MOP);
    cur_obj_unload_object_with_behavior(bhvCheckpoint_Flag_MOP);
    cur_obj_unload_object_with_behavior(bhvMoving_Rotating_Block_MOP);
    cur_obj_unload_object_with_behavior(bhvStaticObject);
    cur_obj_unload_object_with_behavior(bhvSandBlock_MOP);

    switch(gCurrentArea->index)
    {
        case 1:
        {
            for (int i = 0; i < 20; i++)
            {
                struct Object* mush = spawn_object(o, MODEL_EXCLAMATION_BOX, bhvExclamationBox);
                mush->oPosX = random_float_ft(-748.f, 1702.f);
                mush->oPosY = 2687.f + random_float() * 800.f;
                mush->oPosZ = random_float_ft(-2842.f,  4200.f);
                mush->oBehParams = (1 << 24); // enable cap always
                mush->oBehParams2ndByte = random_u16() % 3; // all caps
            }
        }
        break;
        // mushrooms
        case 2:
        {
            f32 d;
            struct Object* sign = cur_obj_find_nearest_object_with_behavior(bhvMessagePanel, &d);
            sign->oPosX = random_float_ft(3831.f, 4658.f);
            sign->oPosZ = random_float_ft(-1339.f, -949.f);
            sign->oFaceAngleYaw = random_u16();

            for (int i = 0; i < 20; i++)
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
            for (int i = 0; i < 12; i++)
            {
                struct Object* pyr = spawn_object(o, MODEL_AGLAB_RNG_PYRAMID, bhvAglabRngCollision);
                pyr->oPosX = random_float_ft(-927.f, 1389.f);
                pyr->oPosY = 3150.f - random_float() * 1200.f;
                pyr->oPosZ = random_float_ft(-1900.f, 5070.f);
                pyr->oBehParams2ndByte = 1;
                pyr->oFaceAngleYaw = random_u16() & 0xe000;
            }
        }
        break;
        // cacti
        case 4:
        {
            for (int i = 0; i < 30; i++)
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
        // lamps
        case 5:
        {
            for (int i = 0; i < 20; i++)
            {
                struct Object* pyr = spawn_object(o, MODEL_AGLAB_RNG_LAMP, bhvAglabRngCollision);
                pyr->oPosX = random_float_ft(-1112.f, 1338.f);
                pyr->oPosZ = random_float_ft(-2700.f, 4000.f);
                pyr->oPosY = 2400.f;
                pyr->oBehParams2ndByte = 8;
                pyr->oKleptoStartPosX = random_f32_around_zero(60.f);
                pyr->oKleptoStartPosY = 0x280 + (random_u16() & 0x1ff);
                pyr->oTimer = random_u16();
                pyr->oFaceAngleYaw = random_u16();
            } 
        }
        break;
        // shapes
        case 6:
        {
            for (int i = 0; i < 12; i++)
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
        // MOP
        case 7:
        {
            for (int i = 0; i < 32; i++)
            {
                // (-300, 3400)
                struct Object* pyr = spawn_for_mop(bhvCheckpoint_Flag_MOP, MODEL_AGLAB_RNG_CHECKPOINT);
                pyr->oPosX = random_float_ft(-5800.f, -100.f);
                pyr->oPosY = 1950.f - random_float() * 500.f;
                pyr->oPosZ = random_float_ft(-2000.f, 3600.f);
                pyr->oFaceAngleYaw = random_u16();
            }
            for (int i = 0; i < 20; i++)
            {
                // (-300, 4500)
                struct Object* pyr = spawn_for_mop(bhvMoving_Rotating_Block_MOP, MODEL_AGLAB_RNG_MOVING_ROTATING);
                pyr->oPosX = random_float_ft(-5800.f, -100.f);
                pyr->oPosY = 1950.f - random_float() * 500.f;
                pyr->oPosZ = random_float_ft(4300.f, 10000.f);
                pyr->oBehParams2ndByte = i & 1;
                pyr->oFaceAngleYaw = random_u16();
            }
            for (int i = 0; i < 40; i++)
            {
                // (800, 3500)
                struct Object* pyr;
                int v = i % 9;
                if (v > 1)
                {
                    pyr = spawn_for_mop(bhvNoteblock_MOP, MODEL_AGLAB_RNG_NOTEBLOCK);
                }
                else
                {
                    // dont allow overriding sandblocks with springs
                    pyr = spawn_object(o, MODEL_AGLAB_RNG_SANDBLOCK, bhvSandBlock_MOP);
                }
                pyr->oPosX = random_float_ft(600.f, 6100.f);
                pyr->oPosY = 1950.f - random_float() * 500.f;
                pyr->oPosZ = random_float_ft(-2000.f, 3600.f);
                pyr->oFaceAngleYaw = random_u16();
            }
            for (int i = 0; i < 38; i++)
            {
                // (750, 4500)
                struct Object* pyr = spawn_for_mop(bhvShrink_Platform_MOP, MODEL_AGLAB_RNG_SHRINK_PLATFORM);
                pyr->oPosX = random_float_ft(600.f, 6100.f);
                pyr->oPosY = 1950.f - random_float() * 500.f;
                pyr->oPosZ = random_float_ft(4300.f, 10000.f);
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
        default: return 0.f;
    }
}

static u8 sWasDetectedReset = 0;
u8 gWarpTrigger = 0;
extern u8 gDeathFloorBarrier;
void bhv_aglab_rng_init()
{
    if (2 != gCurrentArea->index)
    {
        rng_reroll();
    }
    else
    {
        o->oSubAction = 1;
    }

    gWarpTrigger = 0;
    gDeathFloorBarrier = 0;
    sWasDetectedReset = 0;
}

void bhv_aglab_rng_surface_check_loop()
{
    struct Surface* surf = NULL;
    find_floor(gMarioStates->pos[0], 4000.f, gMarioStates->pos[2], &surf);
    if (surf && surf->type == SURFACE_SHALLOW_QUICKSAND)
    {
        sWasDetectedReset = 1;
    }
}

void bhv_aglab_rng_loop()
{
    if (gWarpTrigger)
    {
        if (0 == o->oSubAction)
            rng_reroll();

        gWarpTrigger = 0;
    }

    if (4 == gCurrentArea->index)
    {
        gMarioStates->flags |= MARIO_METAL_CAP;
    }
    if (5 == gCurrentArea->index)
    {
        gMarioStates->flags &= ~MARIO_METAL_CAP;
    }
    
    if (0 == o->oAction)
    {
        int attempt = (o->oDistanceToMario > 500.f) || (gCurrentArea->index != 7 && gMarioStates->pos[2] < rng_z_attempt_threshold());
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
                o->oSubAction = 0;
                rng_reroll();
            }
        }

        if (gDeathFloorBarrier)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
            o->oAction = 1;
            gDeathFloorBarrier = 0;
        }

        if (gMarioStates->floorHeight == gMarioStates->pos[1] && (gMarioStates->action != ACT_LAVA_BOOST_LAND) && (gMarioStates->action != ACT_LAVA_BOOST))
        {
            struct Surface* floor = gMarioStates->floor;
            if (floor && (floor->type == SURFACE_SHALLOW_QUICKSAND))
            {
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
                o->oAction = 1;
                return;
            }
        }
        if (sWasDetectedReset)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
            o->oAction = 1;
            return;
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
            sWasDetectedReset = 0;
            gDeathFloorBarrier = 0;
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
            obj_scale_xyz(o, 1.2f, 1.2f, 1.2f);
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
            obj_scale_xyz(o, 1.15f, 1.15f, 1.15f);
        }
        break;
        case 7:
        {
            obj_set_collision_data(o, rng_cactus2_collision);
            obj_scale_xyz(o, 1.25f, 1.25f, 1.25f);
        }
        break;
        case 8:
        {
            obj_set_collision_data(o, rng_lamp_collision);
            obj_scale_xyz(o, 1.1f, 1.1f, 1.1f);
        }
        break;
    }
}

void bhv_aglab_rng_collision_loop()
{
    if (o->oKleptoStartPosX)
    {
        o->oVelX = o->oKleptoStartPosX * sins(o->oTimer * o->oKleptoStartPosY);
        o->oPosX += o->oVelX;
    }
}