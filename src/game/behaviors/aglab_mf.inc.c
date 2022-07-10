
struct MFButterflyConfig
{
    f32 speed;
    f32 top;
};

extern u8 gDontTurnCameraOnReset;

static struct MFButterflyConfig sBFCfg[] =
{
    { 1.0f, -2178.f },
    { 0.6f, 1411.f   },
    { 0.7f, 2471.f },
    { 0.7f, 900.f },
    { 1.0f, 8750.f },
};

void bhv_mf_butterfly_init()
{
    s32 bp1 = (o->oBehParams >> 24) & 0xFF;
    o->oMfButterflyVine = spawn_object(o, bp1 == 1 ? MODEL_MF_VINE : MODEL_MF_VINE2, bhvStaticObjectEx);
    o->oMfButterflyVine->oPosX = o->oPosX;
    o->oMfButterflyVine->oPosY = o->oPosY;
    o->oMfButterflyVine->oPosZ = o->oPosZ;

    if (2 == bp1)
    {
        o->oMfButterflyVine->oFaceAngleYaw += 0x4000;
        o->oMfButterflyVine->oMoveAngleYaw += 0x4000;
    }

    if (0 == bp1)
    {
        o->oMfButterflyVine->oFaceAngleYaw = 0xC000;
        o->oMfButterflyVine->oMoveAngleYaw = 0xC000;
    }
}

void bhv_mf_butterfly_loop()
{
    // print_text_fmt_int(20, 20, "X %d", (int) gMarioStates->pos[0]);
    // print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    // print_text_fmt_int(20, 60, "Z %d", (int) gMarioStates->pos[2]);

    s32 bp1 = (o->oBehParams >> 24) & 0xFF;
    s32 bp3 = (o->oBehParams >> 8)  & 0xFF;
    // f32 length = 4543.f - 2178.f;
    f32* objpos = &o->oPosX;

    if (0 == o->oAction)
    {   
        if (o->oDistanceToMario < 100.f)
        {
            o->oAction = 1;
            gMarioStates->pos[1] += 10.f;
            gMarioStates->vel[1] = 10.f;
            gMarioStates->vel[bp1] = sBFCfg[o->oBehParams2ndByte].speed * 38.f;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw + 0x4000;
            cur_obj_play_sound_2(SOUND_GENERAL_SWISH_AIR_UNUSED);
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
        }   
    }
    else
    {
        if (gMarioStates->action != ACT_FREEFALL)
        {
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
            o->oAction = 0;
            return;
        }

        if (1 == bp1)
            gMarioStates->vel[bp1] = sBFCfg[o->oBehParams2ndByte].speed * (250.f - ((250 - 38) / 30) * o->oTimer);
        else
            gMarioStates->forwardVel = sBFCfg[o->oBehParams2ndByte].speed * (250.f - ((250 - 150) / 30) * o->oTimer);

        if (o->oTimer < 10)
        {
            objpos[bp1] = gMarioStates->pos[bp1];
            o->oPosY = gMarioStates->pos[1];
        }
        else
        {
            o->oPosX = o->oHomeX;
            o->oPosY = o->oHomeY;
            o->oPosZ = o->oHomeZ;
        }

        if (o->oTimer < 27)
        {
            for (int i = 0; i < 3; i++)
            {
                if (i == bp1)
                    continue;
    
                if (i != 1)
                {
                    gMarioStates->pos[i] = objpos[i];
                    gMarioStates->vel[i] = 0;
                }
                else
                {
                    // gMarioStates->pos[1] = objpos[i];
                    gMarioStates->vel[1] = 10.f;  
                }
            }
        }

        if (30 == o->oTimer)
        {
            o->oAction = 0;
        }
    }

    o->oMfButterflyVine->oPosX = o->oPosX;
    o->oMfButterflyVine->oPosY = o->oPosY;
    o->oMfButterflyVine->oPosZ = o->oPosZ;
    f32 s[3];
    s[0] = s[1] = s[2] = 1.0f;
    s[bp1 == 1 ? 1 : 2] = ((bp3 * 2 - 1) * (-1.0f)) * (sBFCfg[o->oBehParams2ndByte].top - objpos[bp1]) / (4543.f - 2178.f);
    obj_scale_xyz(o->oMfButterflyVine, s[0], s[1], s[2]);
}

void bhv_mf_lava_init()
{
    // -
}


extern Vtx mf_dl_mlavaline_mesh_layer_6_vtx_0[424];
void bhv_mf_lava_loop()
{
    // -2992 596-630~613 | 1104-1146~1125
    // -2664 660-702~681 | 1172-1216~1194
    // -2488 714-758~736 | 1226-1266~1246

    /*
    Y = 4.126*X - 5506
    Y = 4.197*X - 7702
      -2992 | -2664 | -2488
       613  |  681  |  736
       1125 |  1194 |  1246
     */

    if (gMarioStates->floorHeight != gMarioStates->pos[1])
        return;

    struct Surface* floor = gMarioStates->floor;
    if (!floor || floor->type != SURFACE_HARD_NOT_SLIPPERY)
        return;

    Vtx* v = segmented_to_virtual(mf_dl_mlavaline_mesh_layer_6_vtx_0);

    f32 k = (4.126f + 4.197f) / 2.f;
    f32 bl = -5506.f + 20.f;
    f32 bh = -7702.f + 80.f;
    f32 d = 10.f;

    f32 ll = k * (v->n.tc[1] - d) + bl;
    f32 lh = k * (v->n.tc[1] + d) + bl;
    f32 hl = k * (v->n.tc[1] - d) + bh;
    f32 hh = k * (v->n.tc[1] + d) + bh;
    
    int hit = 0;
    if (ll < gMarioStates->pos[1] && gMarioStates->pos[1] < lh)
        hit = 1;
        
    if (hl < gMarioStates->pos[1] && gMarioStates->pos[1] < hh)
        hit = 1;

    if (hit)
    {
        gMarioStates->hurtCounter += 8;
        drop_and_set_mario_action(gMarioStates, ACT_LAVA_BOOST, 0);
    }
}

struct ObjectHitbox sMfWoodenPostAnchorHitbox = {
    /* interactType:      */ INTERACT_GRABBABLE,
    /* downOffset:        */ 20,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 1,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 100,
    /* hurtboxRadius:     */ 100,
    /* hurtboxHeight:     */ 100,
};

void bhv_mf_wooden_post_anchor_init()
{
    o->oMfWoodenPostAnchorMain = cur_obj_find_nearest_object_with_behavior(bhvMfWoodenPostMain, &o->oMfWoodenPostAnchorDistance);
    obj_set_hitbox(o, &sMfWoodenPostAnchorHitbox);
}

// 464, 0, -2773
f32 gAglabThrowSpeed = 0;
void bhv_mf_wooden_post_anchor_loop()
{
    if (o->oDistanceToMario < 300.f && o->oHeldState == HELD_FREE)
    {
        spawn_object_relative(ORANGE_NUMBER_B, 0, 160,  0, o, MODEL_NUMBER, bhvOrangeNumber);
    }

    switch (o->oHeldState) {
        case HELD_FREE:
        {
            struct Object* sparkle = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
            sparkle->oPosY += 10.f;
            o->oMfWoodenPostAnchorFixAngle = 0;
            if (gCamera->cutscene == CUTSCENE_AGLAB_WOODEN_POST_CS)
            {
                gDontTurnCameraOnReset = 1;
                gCamera->cutscene = 0;
                reset_camera(gCamera);
            }
        }
            break;

        case HELD_HELD:
            obj_copy_pos(o, gMarioObject);
            cur_obj_unrender_set_action_and_anim(-1, 0);

            f32 d;
            s16 yaw;
            vec3f_get_lateral_dist_and_yaw(&o->oMfWoodenPostAnchorMain->oPosVec, &o->oPosVec, &d, &yaw);
            if (0 == o->oMfWoodenPostAnchorFixAngle)
            {
                o->oMfWoodenPostAnchorFixAngle = 1;
                gMarioStates->faceAngle[1] = yaw + 0x8000;
                o->oMfWoodenPostAnchorLastMarioYaw = gMarioStates->faceAngle[1];
            }
            if (gMarioStates->action == ACT_HOLDING_BOWSER)
            {
                gMarioStates->pos[0] = o->oMfWoodenPostAnchorMain->oPosX - o->oMfWoodenPostAnchorDistance * sins(gMarioStates->faceAngle[1]);
                gMarioStates->pos[2] = o->oMfWoodenPostAnchorMain->oPosZ - o->oMfWoodenPostAnchorDistance* coss(gMarioStates->faceAngle[1]);
                s16 spd = o->oMfWoodenPostAnchorLastMarioYaw - gMarioStates->faceAngle[1];
                o->oMfWoodenPostAnchorLastMarioYaw = gMarioStates->faceAngle[1];
                f32 espd = (ABS(spd) / 20.f) - 70.f;
                gAglabThrowSpeed = 2.5f * (espd > 3.f ? espd : 3.f);
                gMarioStates->pos[1] += espd;
                gMarioStates->pos[1] = CLAMP(gMarioStates->pos[1], o->oHomeY + 136.f, o->oMfWoodenPostAnchorMain->oPosY + 200.f);
            }
            
            gCamera->cutscene = CUTSCENE_AGLAB_WOODEN_POST_CS;

            break;

        case HELD_THROWN:
            o->oPosX = gMarioStates->pos[0];
            o->oPosZ = gMarioStates->pos[2];
            o->oPosY = o->oHomeY;
            o->oHeldState = HELD_FREE;
            gCamera->cutscene = 0;
            gDontTurnCameraOnReset = 1;
            reset_camera(gCamera);
            // cur_obj_get_thrown_or_placed(0.0f, 20.0f, 1);
            break;

        case HELD_DROPPED:
            o->oPosX = gMarioStates->pos[0];
            o->oPosZ = gMarioStates->pos[2];
            o->oPosY = o->oHomeY;
            gCamera->cutscene = 0;
            gDontTurnCameraOnReset = 1;
            reset_camera(gCamera);
            cur_obj_get_dropped();
            break;
    }

    o->oInteractStatus = INT_STATUS_NONE;
}

void bhv_mf_wooden_post_main_init()
{
    o->oMfWoodenPostMainRope = spawn_object(o, MODEL_MF_ROPE, bhvStaticObjectEx);
    o->oMfWoodenPostMainRope->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    obj_scale_xyz(o->oMfWoodenPostMainRope, 1.2f, 1.2f, 1.2f);
    struct Object** objs = &o->oMfWoodenPostMainPosts;
    cur_obj_find_all_objects_with_behavior_and_bparam(bhvWoodenPost, objs, 0);
    o->oMfWoodenPostMainTarget = 300;
    o->oPosY = 300.f;
}

extern const Texture texture_hud_char_0[];
extern const Texture texture_hud_char_1[];
extern const Texture texture_hud_char_2[];
extern const Texture texture_hud_char_3[];
extern const Texture texture_hud_char_4[];
extern const Texture texture_hud_char_5[];
extern const Texture texture_hud_char_6[];
extern const Texture texture_hud_char_7[];
extern const Texture texture_hud_char_8[];
extern const Texture texture_hud_char_9[];

static const Texture* sNumberTextures[] = {
    texture_hud_char_0,
    texture_hud_char_1,
    texture_hud_char_2,
    texture_hud_char_3,
    texture_hud_char_4,
    texture_hud_char_5,
    texture_hud_char_6,
    texture_hud_char_7,
    texture_hud_char_8,
    texture_hud_char_9,
};

extern Gfx mat_mf_dl_num1[]; // +5
extern Gfx mat_mf_dl_num2[];
extern Gfx mat_mf_dl_num3[];

static void mf_set_num_texture(int num)
{
    int d0 =  num        % 10;
    int d1 = (num / 10 ) % 10;
    int d2 = (num / 100) % 10;
    
    u32* t0 = ((u32*) segmented_to_virtual(mat_mf_dl_num3)) + 5 * 2 + 1;
    *t0 = (u32) sNumberTextures[d0];
    u32* t1 = ((u32*) segmented_to_virtual(mat_mf_dl_num2)) + 5 * 2 + 1;
    *t1 = (u32) sNumberTextures[d1];
    u32* t2 = ((u32*) segmented_to_virtual(mat_mf_dl_num1)) + 5 * 2 + 1;
    *t2 = (u32) sNumberTextures[d2];
}

void bhv_mf_wooden_post_main_loop()
{
    if (gCamera->cutscene == CUTSCENE_AGLAB_WOODEN_POST_CS)
    {
        o->oMfWoodenPostMainRope->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
        o->oMfWoodenPostMainRope->oPosY = o->oPosY + 200.f;
        o->oMfWoodenPostMainRope->oFaceAngleYaw += 0x169;
    }
    else
    {
        o->oMfWoodenPostMainRope->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
    }

    if (gMarioStates->pos[1] < -800.f)
    {
        cur_obj_hide();
        o->oIntangibleTimer = -1;
    }
    else
    {
        cur_obj_unhide();
        o->oIntangibleTimer = 0;
    }

    int i = 0;
    f32 targetY = 300.f;
    for (struct Object** posts = &o->oMfWoodenPostMainPosts; *posts; posts++)
    {
        i++;
        struct Object* post = *posts;
        targetY -= 1.6f * (post->oWoodenPostOffsetY);
    }

    if (o->oPosY < targetY)
    {
        o->oPosY += 10.f;
    }
    else
    {
        o->oPosY = targetY;
    }

    mf_set_num_texture(o->oPosY / 4.f);
}

void mf_kq_init()
{
    o->oPosY -= 1000.f;
    o->parentObj = cur_obj_nearest_object_with_behavior(bhvKoopaRaceEndpoint);
}

void mf_kq_loop()
{
    if (o->oAction == 2)
    {
        // -
    }
    else if (o->oAction == 1)
    {
        if (o->oTimer > 100)
            o->oAction = 2;

        o->oPosY += 10.f;
    }
    else if (o->parentObj->oKoopaRaceEndpointRaceStatus)
    {
        struct Object* koopa;
        cur_obj_find_all_objects_with_behavior_and_bparam(bhvKoopa, &koopa, 2);
        o->oAction = koopa->oPosY > -10.f ? 2 : 1;
    }
}
