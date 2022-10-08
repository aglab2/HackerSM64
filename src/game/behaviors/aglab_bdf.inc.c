struct Pos
{
    f32 x, y, z;
};

static struct Pos gBowserPadNearPositions[] = 
{
    { 1668.f, 389.f, -1379.f }, 
    { -2025.f, 389.f, 0.f }, 
    { 1668.f, 389.f, 1113.f }, 
};

static struct Pos gBowserPadFarPositions[] = 
{
    { 6215.f, 372.f, -9607.f }, 
    { -11023.f, 389.f, -463.f }, 
    { 6600.f, 442.f, 7612.f }, 
};

extern Gfx mat_bdf_dl_bg_4_0_002[];
extern Gfx mat_bdf_dl_bg_4_0_001[];
extern Gfx mat_bdf_dl_bg_0_0[];

static Gfx* sBowserWarpCtlGfxs[] = {
    mat_bdf_dl_bg_4_0_001, 
    mat_bdf_dl_bg_0_0,
    mat_bdf_dl_bg_4_0_002, 
};

static int sBowserWarpCtlGfxOffsets[] = {
    18 * 8 + 7, 
    4 * 8 + 7, 
    18 * 8 + 7,
};

extern void bowser_course_warp_ctl_init()
{
    u8* a;
    a = (u8*) segmented_to_virtual(mat_bdf_dl_bg_4_0_002) + 18 * 8 + 7;
    *a = 0;
    a = (u8*) segmented_to_virtual(mat_bdf_dl_bg_4_0_001) + 18 * 8 + 7;
    *a = 0;
    a = (u8*) segmented_to_virtual(mat_bdf_dl_bg_0_0) + 4 * 8 + 7;
    *a = 0;
}

void bowser_course_warp_ctl_loop()
{
    if (-1700.f < gMarioStates->pos[0] && gMarioStates->pos[0] < 1400.f && -1500.f < gMarioStates->pos[2] && gMarioStates->pos[2] < 1500.f)
    {
        bowser_course_warp_ctl_init();
    }

    if (0 == o->oAction)
    {
        struct Surface* floor = gMarioStates->floor;
        int type = floor ? floor->type : 0;
        if (SURFACE_INSTANT_WARP_1B <= type && type <= SURFACE_INSTANT_WARP_1E && gMarioStates->pos[1] == gMarioStates->floorHeight)
        {
            print_text_centered(160, 20, "PRESS L TO GO");
            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                o->oAction = 1;
                if (type != SURFACE_INSTANT_WARP_1E)
                {
                    o->oBowserWarpCtlTarget = type - SURFACE_INSTANT_WARP_1B;
                    o->oBowserWarpCtlDirection = 0;
                }
                else
                {
                    o->oBowserWarpCtlDirection = 1;
                }
            }
        } 
    }
    else
    {
        if (o->oTimer == 1)
        {
            drop_and_set_mario_action(gMarioStates, ACT_SHOT_FROM_CANNON, 0);
        }

        if (o->oTimer > 40)
        {
            Gfx* gfx = sBowserWarpCtlGfxs[o->oBowserWarpCtlTarget];
            u8* a = (u8*) segmented_to_virtual(gfx) + sBowserWarpCtlGfxOffsets[o->oBowserWarpCtlTarget];
            if (!o->oBowserWarpCtlDirection)
            {
                *a = 15 + 8 * (o->oTimer - 40);
            }
            else
            {
                *a = 8 * (70 - o->oTimer);
            }
        }

        if (o->oTimer == 70)
            o->oAction = 0;

        struct Pos* froms = o->oBowserWarpCtlDirection ? gBowserPadFarPositions  : gBowserPadNearPositions;
        struct Pos* tos   = o->oBowserWarpCtlDirection ? gBowserPadNearPositions : gBowserPadFarPositions;

        struct Pos* from = &froms[o->oBowserWarpCtlTarget];
        struct Pos* to   = &tos  [o->oBowserWarpCtlTarget];

        f32 dx = to->x - from->x;
        f32 dy = to->y - from->y;
        f32 dz = to->z - from->z;
        
        s16 yaw = atan2s(dz, dx);
        f32 d = sqrtf(dx*dx + dz*dz);

        gMarioStates->pos[0] = from->x + dx / 70 * o->oTimer;
        gMarioStates->pos[1] = from->y + dy / 70 * o->oTimer + 2000.f * sins(o->oTimer * 0x8000 / 70);
        gMarioStates->pos[2] = from->z + dz / 70 * o->oTimer;
        gMarioStates->faceAngle[1] = yaw;
        gMarioStates->faceAngle[0] = atan2s(d, dy);
    }
}

extern const Collision bdf_p1_collision[];
extern const Collision bdf_p2_collision[];
extern const Collision bdf_p3_collision[];

static struct Pos gBowserPiecesPositions[] = 
{
    { 1467.f, 847.f, 752.f }, 
    { 1467.f, 1567.f, -93.f }, 
    { 1467.f, 2319.f, -846.f }, 
};

void bowser_pieces_init()
{
    o->parentObj = spawn_object(o, MODEL_BUBBLE, bhvStaticObjectBillboardEx);
    obj_scale(o->parentObj, 9.f);
    o->parentObj->oPosY -= 140.f;

    if (1 == o->oBehParams2ndByte)
        obj_set_collision_data(o, bdf_p1_collision);
    if (2 == o->oBehParams2ndByte)
        obj_set_collision_data(o, bdf_p2_collision);
    if (3 == o->oBehParams2ndByte)
        obj_set_collision_data(o, bdf_p3_collision);
    
    obj_scale(o, 0.2f);
    f32 d;
    o->oBowserPieceCtlKlepto = cur_obj_find_nearest_object_with_behavior(bhvKlepto, &d);
}

void bowser_pieces_loop()
{
    if (0 == o->oAction)
    {
        o->oMoveAngleYaw += 0x134;
        o->oMoveAnglePitch += 0x104;

        if (2 == o->oBehParams2ndByte)
        {
            if (o->oBowserPieceCtlKlepto->oAction == KLEPTO_ACT_STRUCK_BY_MARIO)
            {
                cur_obj_play_sound_2(SOUND_GENERAL_BUBBLES);
                o->oAction = 1;
            }

            Vec3s rotation;
            Mat4 displaceMatrix;
            rotation[0] = o->oBowserPieceCtlKlepto->oAngleVelPitch;
            rotation[1] = o->oBowserPieceCtlKlepto->oAngleVelYaw;
            rotation[2] = o->oBowserPieceCtlKlepto->oAngleVelRoll;
            Vec3f relativeOffset;
            Vec3f currentObjectOffset = { 0.f, 0.f, 0.f };
            Vec3f fromOffset = { -200.f, 0.f, 0.f };
            
            mtxf_rotate_zxy_and_translate(displaceMatrix, currentObjectOffset, rotation);
            linear_mtxf_transpose_mul_vec3f(displaceMatrix, relativeOffset, fromOffset);

            o->oPosX = o->oBowserPieceCtlKlepto->oPosX + relativeOffset[0];
            o->oPosY = o->oBowserPieceCtlKlepto->oPosY + relativeOffset[1];
            o->oPosZ = o->oBowserPieceCtlKlepto->oPosZ + relativeOffset[2];

            o->parentObj->oPosX = o->oPosX;
            o->parentObj->oPosY = o->oPosY - 140.f;
            o->parentObj->oPosZ = o->oPosZ;
        }
        else
        {
            if (o->oDistanceToMario < 120.f)
            {
                cur_obj_play_sound_2(SOUND_GENERAL_BUBBLES);
                o->oAction = 1;
            }
        }
    }
    else
    {
        if (o->oTimer <= 10)
        {
            f32 timeLeft = 10 - o->oTimer;
            obj_scale(o, timeLeft * timeLeft / 1000.f);
            obj_scale(o->parentObj, timeLeft * timeLeft * 9.f / 100.f);
        }
        else
        {
            load_object_collision_model();
        }

        if (o->oTimer == 10)
        {
            for (int i = 0; i < 10; i++)
                spawn_object(o, MODEL_WHITE_PARTICLE_SMALL, bhvSmallParticleBubbles);
    
            o->parentObj->activeFlags = 0;
            o->oMoveAngleYaw = 0;
            o->oMoveAnglePitch = 0;
            o->oPosX = gBowserPiecesPositions[o->oBehParams2ndByte - 1].x;
            o->oPosY = gBowserPiecesPositions[o->oBehParams2ndByte - 1].y;
            o->oPosZ = gBowserPiecesPositions[o->oBehParams2ndByte - 1].z;
            obj_scale(o, 1.f);
        }
    }
}

void bowser_metal_box_push_init()
{
    o->oPosY -= 20.f;
}

void bowser_metal_box_push_loop()
{
    if (0 == o->oAction)
    {
        if (-200.f  < gMarioStates->pos[2] && gMarioStates->pos[2] < 200.f
         && -1600.f < gMarioStates->pos[0] && gMarioStates->pos[0] < -1100.f
         && 1000.f  < gMarioStates->pos[1] && gMarioStates->pos[1] < 2000.f)
         {
            o->oAction = 1;
         }
    }
    else if (1 == o->oAction)
    {
        o->oPosX -= 25.f;
        if (30 == o->oTimer)
        {
            o->oAction = 2;
        }
    }
    else
    {
        o->oPosX += 10.f;
        if (75 == o->oTimer)
        {
            o->oPosX = o->oHomeX;
            o->oAction = 0;
        }
    }
}
