#include "game/color.h"

extern u16 gDnvicCounter;
extern u16 gDnvicChamber;
extern u8  gDnvicMapAlpha;
extern s8  gDnvicMapAlphaVelocity;
extern hsv gDnvicColor;
extern hsv gDnvicCurrentColor;

extern const BehaviorScript bhvOWDecor[];

void ow_ctl_init()
{
    gDoInertia = 1;
    gDoPlatformDisplacement = 1;
    gDnvicCounter     = 0;
    gDnvicChamber     = 1;
    gDnvicMapAlpha    = 0;
    gDnvicMapAlphaVelocity = 0;
    gDnvicColor.h = 0.052028f * 0x10000;
    gDnvicColor.v = 0.814847f * 255;
    gDnvicColor.s = 0.826638f;
    gDnvicCurrentColor.h = gDnvicColor.h;
    gDnvicCurrentColor.v = gDnvicColor.v;
    gDnvicCurrentColor.s = gDnvicColor.s;
}

void ow_ctl_loop()
{
    if (gIsGravityFlipped)
    {
        gMarioStates->health = 0x880;
        if (0 == o->oTimer)
            seq_player_play_sequence(SEQ_PLAYER_LEVEL, 0, 0);

        if (30 == o->oTimer)
            seq_player_play_sequence(SEQ_PLAYER_LEVEL, SEQ_DUCKTALES, 0);

        if (o->oTimer > 120)
        {
            print_text_centered(160, 180, "GAME OVER");
            print_text_centered(160, 60, "PRESS L TO RESTART");
            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                gIsGravityFlipped = 0;
                o->activeFlags = 0;
            }
        }

        if (gMarioStates->pos[1] < -6000.f)
        {
            gMarioStates->pos[1] = -6000.f;
        }
    }
}

static void cur_obj_write_all_objects_with_behavior_and_bparam3(const BehaviorScript *behavior, int param, struct Object*** objsOut) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
            && GET_BPARAM3(obj->oBehParams) == param
        ) {
            **objsOut = obj;
            *objsOut = *objsOut + 1;
        }

        obj = (struct Object *) obj->header.next;
    }

    **objsOut = NULL;
}

static void cur_obj_write_all_objects_with_behavior(const BehaviorScript *behavior, struct Object*** objsOut) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
        ) {
            **objsOut = obj;
            *objsOut = *objsOut + 1;
        }

        obj = (struct Object *) obj->header.next;
    }

    **objsOut = NULL;
}

extern const Collision ow_part_brodute_collision[];
extern const Collision ow_part_arthur_collision[];
extern const Collision ow_part_gael_collision[];
extern const Collision ow_part_side_collision[];
extern const Collision ow_part_scut_collision[];
extern const Collision ow_part_bowser_collision[];

u8 sOWIsFirstLaunchFlags = 0;
u8 sOWIsShownFlags = 0;

extern Vec3f gAglabOWFocus;

void ow_part_init()
{
    switch(o->oBehParams2ndByte)
    {
        case 1:
        obj_set_collision_data(o, ow_part_brodute_collision);
        break;
        case 2:
        obj_set_collision_data(o, ow_part_arthur_collision);
        break;
        case 3:
        obj_set_collision_data(o, ow_part_gael_collision);
        break;
        case 4:
        obj_set_collision_data(o, ow_part_side_collision);
        break;
        case 5:
        obj_set_collision_data(o, ow_part_scut_collision);
        break;
        case 6:
        obj_set_collision_data(o, ow_part_bowser_collision);
        break;
    }

    s32 active = 0;
    switch (o->oBehParams2ndByte)
    {
        case 1:
        {
            u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_AB));
            active = 0 != starFlags;
        }
        break;
        case 2:
        {
            u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_MTC));
            active = 0 != starFlags;
        }
        break;
        case 3:
        {
            u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_MF));
            active = 0 != starFlags;
        }
        break;
        case 4:
        {
            u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_HF));
            active = 0 != starFlags;
        }
        break;
        case 5:
        {
            u8 agtStars   = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_TOTWC));
            u8 reonuStars = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_SA));
            u8 axoStars   = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_COTMC));
            u8 crashStars = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_CRASH));
            active = agtStars || reonuStars || axoStars || crashStars;
        }
        break;
        case 6:
        {
            u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_BOB));
            active = 0 != starFlags;
        }
        break;
    }

    u8 flag = 1 << o->oBehParams2ndByte;
    if (sOWIsFirstLaunchFlags & flag)
    {
        if (active)
        {
            if (!(sOWIsShownFlags & flag))
            {
                gCamera->cutscene = CUTSCENE_AGLAB_OW_CS;
                o->oOWPartShowCutscene = 1;
            }
            sOWIsShownFlags |= flag;
        }
    }
    else
    {
        sOWIsFirstLaunchFlags |= flag;
        if (active)
            sOWIsShownFlags |= flag;
    }

    o->oHomeX = gMarioStates->pos[0];
    o->oHomeY = gMarioStates->pos[1];
    o->oHomeZ = gMarioStates->pos[2];

    if (1 == o->oOWPartShowCutscene)
    {
        gAglabOWFocus[0] = o->oPosX;
        gAglabOWFocus[1] = o->oPosY;
        gAglabOWFocus[2] = o->oPosZ;

        struct Object** objsOut = (struct Object**) aglabScratch;
        cur_obj_hide();
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvDoorWarp    , o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvWarp        , o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvWarpPipe    , o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvBooCage     , o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvSparkler    , o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvOWLuigi     , o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvOWDnvicClose, o->oBehParams2ndByte, &objsOut);
        cur_obj_write_all_objects_with_behavior_and_bparam3(bhvMessagePanel, o->oBehParams2ndByte, &objsOut);
        if (5 == o->oBehParams2ndByte)
            cur_obj_write_all_objects_with_behavior(bhvStickyPlat, &objsOut);

        *objsOut = NULL;

        for (struct Object** objsIt = (struct Object**) aglabScratch; *objsIt; objsIt++)
        {
            (*objsIt)->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
        }
    }
    
    if (!active)
    {
        cur_obj_unload_object_with_behavior_and_bparam3(bhvDoorWarp    , o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvWarp        , o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvWarpPipe    , o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvBooCage     , o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvSparkler    , o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvOWLuigi     , o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvOWDnvicClose, o->oBehParams2ndByte);
        cur_obj_unload_object_with_behavior_and_bparam3(bhvMessagePanel, o->oBehParams2ndByte);
        if (5 == o->oBehParams2ndByte)
            cur_obj_unload_object_with_behavior(bhvStickyPlat);

        o->activeFlags = 0;
    }
}

static void fixMario()
{
    gMarioStates->pos[0] = o->oHomeX;
    gMarioStates->pos[1] = o->oHomeY;
    gMarioStates->pos[2] = o->oHomeZ;
}

void ow_part_loop()
{
    if (0 == o->oAction)
    {
        if (1 == o->oOWPartShowCutscene)
        {
            fixMario();
            if (0 == o->oTimer)
            {
                cur_obj_play_sound_2(SOUND_GENERAL_GRAND_STAR);
            }
            if (o->oTimer < 63)
            {
                gCamera->cutscene = CUTSCENE_AGLAB_OW_CS;
                struct Object *sparkle = try_to_spawn_object(0, 1.0f, o, MODEL_SPARKLES_ANIMATION, bhvSparkle);
                if (sparkle != NULL) {
                    obj_translate_xyz_random(sparkle, 1500.0f);
                    obj_scale_random(sparkle, 10.0f, 5.0f);
                }
            }
            
            if (o->oTimer == 60)
            {
                cur_obj_play_sound_2(SOUND_GENERAL2_STAR_APPEARS);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 40, 0, 0, 0);
            }
            else if (o->oTimer == 101)
            {
                cur_obj_unhide();
                for (struct Object** objsIt = (struct Object**) aglabScratch; *objsIt; objsIt++)
                {
                    (*objsIt)->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
                }
            }
            else if (o->oTimer == 102)
            {
                play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 30, 0, 0, 0);
            }
            else if (200 == o->oTimer)
            {
                gCamera->cutscene = 0;
                reset_camera(gCamera);
                o->oAction = 1;
            }            
        }
        else
        {
            o->oAction = 1;
        }
    }
    else
    {
        if (o->collisionData)
            load_object_collision_model();
    }
}

void ow_luigi_init()
{

}

static struct ObjectHitbox sLuigiHitbox = {
    /* interactType:      */ 0,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 65,
    /* height:            */ 113,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void ow_luigi_loop()
{
    obj_set_hitbox(o, &sLuigiHitbox);
    o->oInteractStatus = INT_STATUS_NONE;
    o->oOpacity = 255;

    if (((gMarioState->action == 0x1327) || (gMarioState->action == 0x192D)) && (gLastCompletedCourseNum == COURSE_SA)) {
        o->oPosX = gMarioState->pos[0];
        o->oPosY = gMarioState->pos[1] + 60;
        o->oPosZ = gMarioState->pos[2] + 100;

        o->oFaceAngleYaw = DEGREES(-90);

        if (gMarioState->actionState == ACT_STATE_EXIT_LAND_SAVE_DIALOG_WITH_CAP) {
            cur_obj_init_animation(3);
            o->oFaceAngleYaw = DEGREES(180);
            o->oFaceAnglePitch = DEGREES(-90);
        } else {
            cur_obj_init_animation(0);
        }  
    } else {
        cur_obj_init_animation(0);
        o->oFaceAngleYaw = DEGREES(90);
        o->oFaceAnglePitch = DEGREES(0);
        o->oPosX = o->oHomeX;
        o->oPosY = o->oHomeY;
        o->oPosZ = o->oHomeZ;        
    }
    
}

void ow_dnvic_close_init()
{
    // -
}

void ow_dnvic_close_loop()
{
    int cnt = save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1);
    if (cnt >= 40)
    {
        o->activeFlags = 0;
    }

    load_object_collision_model();
}

extern Gfx mat_castle_inside_dl_mat2[]; // +12
extern Gfx mat_castle_inside_dl_YellowCobble_f3d_layer1[]; // +14 / 254, 201, 57
extern Gfx mat_castle_inside_dl_BlueFlowers_f3d_layer4[]; // +14 / 127, 254, 235
extern Gfx mat_castle_inside_dl_TreeBark_f3d_layer1[]; // +14 / 217, 118, 65
extern Gfx mat_castle_inside_dl_DarkBeigeCobble_f3d_layer1[]; // +14 / 254, 190, 157
extern Gfx mat_castle_inside_dl_BeigeCobble_f3d_layer1[]; // +14 / 254, 197, 124
extern Gfx mat_castle_inside_dl_TowerRoof_f3d_layer1[]; // +14 / 192, 63, 75
extern Gfx mat_castle_inside_dl_YellowWood_f3d_layer1[]; // +14 / 254, 243, 98
extern Gfx mat_castle_inside_dl_OrangeWood_f3d_layer1[]; // +14 / 254, 151, 94
extern Gfx mat_castle_inside_dl_RedWood_f3d_layer1[]; // +14 / 254, 92, 69
extern Gfx mat_castle_inside_dl_Grass_f3d_layer1[]; // +14 / 37, 188, 46
extern Gfx mat_castle_inside_dl_Dirt_f3d_layer1[]; // +14 / 254, 195, 108
extern Gfx mat_castle_inside_dl_Path_f3d_layer1[]; // +14 / 210, 217, 111
extern Gfx mat_castle_inside_dl_PathOutside_f3d_layer1[]; // +14 / 195, 185, 77
extern Gfx mat_castle_inside_dl_Leaves_f3d_layer1[]; // +14 / 60, 161, 34
extern Gfx mat_castle_inside_dl_mat_layer1[]; // +14 / 0,0,0

extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_15[27];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_15_backup[27];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_16[16];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_16_backup[16];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_17[21];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_17_backup[21];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_18[14];
extern Vtx castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_18_backup[14];

struct OW2Texture
{
    void* ptr;
    rgb color;
};

enum
{
    OW2_MAT_NOISE = 0,
    OW2_MAT_COBBLE_YELLOW,
    OW2_MAT_FLOWERS,
    OW2_MAT_TREE_BARK,
    OW2_MAT_BEIGE_DARK,
    OW2_MAT_COBBLE_BEIGE,
    OW2_MAT_ROOF,
    OW2_MAT_WOOD_YELLOW,
    OW2_MAT_WOOD_ORANGE,
    OW2_MAT_WOOD_RED,
    OW2_MAT_GRASS,
    OW2_MAT_DIRT,
    OW2_MAT_PATH,
    OW2_MAT_PATH_OUTSIDE,
    OW2_MAT_LEAVES,
    OW2_MAT_BACK,
};

static struct OW2Texture sOW2Textures[] = 
{
    { mat_castle_inside_dl_mat2, { 0,0,0,60 } },
    { mat_castle_inside_dl_YellowCobble_f3d_layer1, { 254, 201, 57, 0 } },
    { mat_castle_inside_dl_BlueFlowers_f3d_layer4, { 127, 254, 235, 0 } },
    { mat_castle_inside_dl_TreeBark_f3d_layer1, { 217, 118, 65, 0 } },
    { mat_castle_inside_dl_DarkBeigeCobble_f3d_layer1, { 254, 190, 157, 0 } },
    { mat_castle_inside_dl_BeigeCobble_f3d_layer1, { 254, 197, 124, 0 } },
    { mat_castle_inside_dl_TowerRoof_f3d_layer1, { 192, 63, 75, 0 } },
    { mat_castle_inside_dl_YellowWood_f3d_layer1, { 254, 243, 98, 0 } },
    { mat_castle_inside_dl_OrangeWood_f3d_layer1, { 254, 151, 94, 0 } },
    { mat_castle_inside_dl_RedWood_f3d_layer1, { 254, 151, 94, 0 } },
    { mat_castle_inside_dl_Grass_f3d_layer1, { 37, 188, 46, 0 } },
    { mat_castle_inside_dl_Dirt_f3d_layer1, { 254, 195, 108, 0 } },
    { mat_castle_inside_dl_Path_f3d_layer1, { 210, 217, 111, 0 } },
    { mat_castle_inside_dl_PathOutside_f3d_layer1, { 195, 185, 77, 0 } },
    { mat_castle_inside_dl_Leaves_f3d_layer1, { 60, 161, 34, 0 } },
    { mat_castle_inside_dl_mat_layer1, { 23, 23, 102, 0 } },
};

static rgb sOW2OriginalColors[] = 
{
    { 254, 201, 57, 0 },
    { 127, 254, 235, 0 },
    { 217, 118, 65, 0 },
    { 254, 190, 157, 0 },
    { 254, 197, 124, 0 },
    { 192, 63, 75, 0 },
    { 254, 243, 98, 0 },
    { 254, 151, 94, 0 },
    { 254, 151, 94, 0 },
    { 37, 188, 46, 0 },
    { 254, 195, 108, 0 },
    { 210, 217, 111, 0 },
    { 195, 185, 77, 0 },
    { 60, 161, 34, 0 },
    { 23, 23, 102, 0 },
};

struct OW2Vertices
{
    Vtx* ptr;
    Vtx* ptrb;
    s32 sz;
    u8 enabled;
    rgb color;
};

#define OW2_VERTICES_ENTRY(name) name, name##_##backup, sizeof(name) / sizeof(*name), 1

enum
{
    OW2_VTX_HONEY,
    OW2_VTX_SPACE,
    OW2_VTX_GRASS,
    OW2_VTX_RNG,
};

static struct OW2Vertices sOW2Vertices[] = 
{
    { OW2_VERTICES_ENTRY(castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_15), { 0, 0, 0, 0 } },
    { OW2_VERTICES_ENTRY(castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_16), { 0, 0, 0, 0 } },
    { OW2_VERTICES_ENTRY(castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_17), { 0, 0, 0, 0 } },
    { OW2_VERTICES_ENTRY(castle_inside_dl_Triarc_Bridge_mesh_layer_1_vtx_18), { 0, 0, 0, 0 } },
};

static void ow2_reset_colors(void)
{
    for (unsigned int i = 1; i < sizeof(sOW2Textures) / sizeof(*sOW2Textures); i++)
    {
        struct OW2Texture* mat = &sOW2Textures[i];
        mat->color.r = 255;
        mat->color.g = 255;
        mat->color.b = 255;
        mat->color.a = 255;
    }
    for (unsigned int i = 0; i < sizeof(sOW2Vertices) / sizeof(*sOW2Vertices); i++)
    {
        struct OW2Vertices* vts = &sOW2Vertices[i];
        vts->color.r = 255;
        vts->color.g = 255;
        vts->color.b = 255;
        vts->color.a = 255;
    }
}

static void ow2_write_colors(void)
{
    for (unsigned int i = 0; i < sizeof(sOW2Textures) / sizeof(*sOW2Textures); i++)
    {
        struct OW2Texture* mat = &sOW2Textures[i];
        rgb* ptr = (rgb*) segmented_to_virtual(mat->ptr);
        if (i != 0)
        {
            ptr[14*2 + 1].r = mat->color.r;
            ptr[14*2 + 1].g = mat->color.g;
            ptr[14*2 + 1].b = mat->color.b;
        }
        else
        {
            ptr[12*2 + 1].a = mat->color.a;
        }
    }
    for (unsigned int i = 0; i < sizeof(sOW2Vertices) / sizeof(*sOW2Vertices); i++)
    {
        struct OW2Vertices* vts = &sOW2Vertices[i];
        Vtx* ptr  = (Vtx*) segmented_to_virtual(vts->ptr);
        Vtx* ptrb = (Vtx*) segmented_to_virtual(vts->ptrb);
        for (int j = 0; j < vts->sz; j++)
        {
            Vtx* vtx  = &ptr[j];
            Vtx* vtxb = &ptrb[j];
            if (vts->enabled)
            {
                if (vtx->v.cn[3] > 0x80)
                {
                    vtx->v.cn[3] = 0xff;
                }
                else
                {
                    vtx->v.cn[0] = (vtxb->v.cn[0] / 255.f) * vts->color.r;
                    vtx->v.cn[1] = (vtxb->v.cn[1] / 255.f) * vts->color.g;
                    vtx->v.cn[2] = (vtxb->v.cn[2] / 255.f) * vts->color.b;
                    vtx->v.cn[3] = 0;
                }
            }
            else
            {
                if (vtx->v.cn[3] > 0x80)
                {
                    vtx->v.cn[0] = 200;
                    vtx->v.cn[1] = 200;
                    vtx->v.cn[2] = 200;
                    vtx->v.cn[3] = 0xff;
                }
                else
                {
                    vtx->v.cn[3] = 0;
                }
            }
        }
    }
}

extern u8 gLowGravityEnabled;
extern Gfx mat_mario_red[];
extern Gfx mat_mario_logo[];
extern Lights1 mario_red_lights;
extern void rovert_init(void);
void ow_ctl2_init()
{
    struct Surface* floor = gMarioStates->floor;
    int type = floor ? floor->type : 0;
    if (type == SURFACE_VANISH_CAP_WALLS)
    {
        seq_player_play_sequence(SEQ_PLAYER_LEVEL, SEQ_ALONE, 0);
    }
    if (type == SURFACE_TTM_VINES)
    {
        seq_player_play_sequence(SEQ_PLAYER_LEVEL, SEQ_PROMISE_R, 0);
    }
    if (type == SURFACE_SWITCH)
    {
        seq_player_play_sequence(SEQ_PLAYER_LEVEL, SEQ_GRIEF, 0);
    }

    rovert_init();
    gLowGravityEnabled = 0;
    {
        void** ptr = segmented_to_virtual(mat_mario_red);
        ptr[9] = &mario_red_lights.l[0];
        ptr[11] = &mario_red_lights.a;
    }
    {
        void** ptr = segmented_to_virtual(mat_mario_logo);
        ptr[39] = &mario_red_lights.l[0];
        ptr[41] = &mario_red_lights.a;
    }

    s32* colors = &o->oOW2CtlRNGColor1;
    for (int i = 0; i < 3; i++)
    {
        colors[i] = random_u16();
        colors[i] |= ((s32) random_u16()) << 16;
    }

    sOW2Vertices[OW2_VTX_HONEY].enabled = 1;
    {
        u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_SPIDERS));
        sOW2Vertices[OW2_VTX_SPACE].enabled = 0 != starFlags;
        if (!sOW2Vertices[OW2_VTX_SPACE].enabled)
        {
            struct Object* pipe = cur_obj_find_object_with_behavior_and_bparam(bhvWarpPipe, 0x13);
            pipe->activeFlags = 0;
        }
    }
    {
        u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_LUIGIMAN));
        sOW2Vertices[OW2_VTX_GRASS].enabled = 0 != starFlags;
        if (!sOW2Vertices[OW2_VTX_GRASS].enabled)
        {
            struct Object* pipe = cur_obj_find_object_with_behavior_and_bparam(bhvWarpPipe, 0x12);
            pipe->activeFlags = 0;
        }
    }
    {
        u8 starFlags = save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_ROVERT));
        sOW2Vertices[OW2_VTX_RNG].enabled = 0 != starFlags;
        if (!sOW2Vertices[OW2_VTX_RNG].enabled)
        {
            struct Object* pipe = cur_obj_find_object_with_behavior_and_bparam(bhvWarpPipe, 0x11);
            pipe->activeFlags = 0;
        }
    }
    if (save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_RNG)))
    {
        o->oOW2CtlEndingStart = spawn_object(o, MODEL_BOWSER_KEY, bhvBowserKey);
        o->oOW2CtlEndingStart->oPosX = 5656.f;
        o->oOW2CtlEndingStart->oPosY = 357.f;
        o->oOW2CtlEndingStart->oPosZ = 6727.f;
    }
    ow2_reset_colors();
    ow2_write_colors();
}

static void ow_ctl2_approach_colors(rgb* color, hsv* target)
{
    hsv hsv;
    rgb2hsv(color, &hsv);
    // we do not have a target to approach as we are grayscale
    if (color->r == color->g && color->g == color->b)
    {
        hsv.h = target->h;
    }

    // exact comparison because just a certain case I want to handle when target is passed
    if (0.f == target->s)
    {
        target->h = hsv.h;
    }

    hsv.h = approach_angle(hsv.h, target->h, 1000);
    approach_f32_asymptotic_bool(&hsv.s, target->s, 0.1f);
    hsv.v = approach_s16(hsv.v, target->v, 1, 1);
    hsv2rgb(&hsv, color);
}

static void ow_ctl2_approach_color0(rgb* color)
{
    hsv target;
    rgb2hsv(color, &target);

    for (unsigned i = 0; i < sizeof(sOW2Vertices) / sizeof(*sOW2Vertices); i++)
        ow_ctl2_approach_colors(&sOW2Vertices[i].color, &target);

    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_GRASS].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_COBBLE_YELLOW].color, &target);
    target.v /= 2;
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_LEAVES].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_BACK].color, &target);
}

static void ow_ctl2_approach_color1(rgb* color)
{
    hsv target;
    rgb2hsv(color, &target);

    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_FLOWERS].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_TREE_BARK].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_WOOD_YELLOW].color, &target);
}

static void ow_ctl2_approach_color2(rgb* color)
{
    hsv target;
    rgb2hsv(color, &target);

    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_BEIGE_DARK].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_COBBLE_BEIGE].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_ROOF].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_WOOD_ORANGE].color, &target);
}

static void ow_ctl2_approach_color3(rgb* color)
{
    hsv target;
    rgb2hsv(color, &target);

    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_DIRT].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_PATH].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_PATH_OUTSIDE].color, &target);
    ow_ctl2_approach_colors(&sOW2Textures[OW2_MAT_WOOD_RED].color, &target);
}

extern Gfx mat_triarc_rock_f3d_material_001_layer5[];
extern Gfx mat_triarc_comb__23_f3d[];
extern Gfx mat_triarc_plat0_Stoney[];
extern Gfx mat_triarc_plat0_Grass[];
extern Gfx mat_triarc_plat1_Stoney[];
extern Gfx mat_triarc_plat1_Leaves_001[];

static Gfx sOpaSurf[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
};
static Gfx sXluSurf[] = {
	gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
};

static void ow_ctl2_degrade_color(void* vptr, int off)
{
    u8* val = (u8*) segmented_to_virtual(vptr);
    u8* ptr = val + off*8 + 7;
    u32* rmCmd = (u32*) (val + 4*8);
    u32* xluCmd = (u32*) sXluSurf;
    rmCmd[0] = xluCmd[0];
    rmCmd[1] = xluCmd[1];
    if (*ptr > 3)
    {
        (*ptr) -= 3;
    }
    else
    {
        *ptr = 0;
    }
}

__attribute__ ((noinline))
static void ow_ctl2_spawn_and_undegrade(void* vptr, int off, int num, int model, f32 x, f32 z)
{
    u8* val = (u8*) segmented_to_virtual(vptr);
    u8* ptr = val + off*8 + 7;
    if (!cur_obj_find_object_with_behavior_and_bparam(bhvOWDecor, num))
    {
        for (int i = 1; i < 10; i++)
        {
            struct Object* decor = spawn_object(o, model + (num == 3 ? (i % 2) : 0), bhvOWDecor);
            decor->oPosX = sins(0x8000 + i * 6553) * 1000.f * (1.f + random_f32_around_zero(0.1f)) + x;
            decor->oPosY = 400.f + random_f32_around_zero(500.f);
            decor->oPosZ = coss(0x8000 + i * 6553) * 1000.f * (1.f + random_f32_around_zero(0.1f)) + z;
            decor->oBehParams2ndByte = num;
            
            decor->oFaceAngleYaw = random_u16();
            decor->oFaceAngleRoll = random_u16();

            if (1 == num)
            {
                obj_scale_xyz(decor, 1.2f, 1.2f, 1.2f);
            }
            if (2 == num)
            {
                obj_scale_xyz(decor, .2f, .2f, .2f);
            }
            if (3 == num)
            {
                obj_scale_xyz(decor, .4f, .4f, .4f);
            }
        }
        *ptr = 4;
    }
    else
    {
        if (*ptr < 240)
        {
            *ptr += 15;
        }
        else
        {
            u32* rmCmd = (u32*) (val + 4*8);
            u32* opaCmd = (u32*) sOpaSurf;
            rmCmd[0] = opaCmd[0];
            rmCmd[1] = opaCmd[1];
            *ptr = 255;
        }
    }
}

__attribute__ ((noinline))
static void ow_ctl2_copy_alpha(void* from, int fromOff, void* to, int toOff)
{
    u8* vf = (u8*) segmented_to_virtual(from);
    u8* vt = (u8*) segmented_to_virtual(to);
    u8 v = vf[8*fromOff + 7];
    if (v == 255)
    {
        u32* rmCmd = (u32*) (vt + 4*8);
        u32* opaCmd = (u32*) sOpaSurf;
        rmCmd[0] = opaCmd[0];
        rmCmd[1] = opaCmd[1];
    }
    else
    {
        u32* rmCmd = (u32*) (vt + 4*8);
        u32* xluCmd = (u32*) sXluSurf;
        rmCmd[0] = xluCmd[0];
        rmCmd[1] = xluCmd[1];
    }
    vt[8*toOff + 7] = vf[8*fromOff + 7];
}

void ow_ctl2_loop()
{
    struct Surface* floor = gMarioStates->floor;
    int type = floor ? floor->type : 0;
    if (type == SURFACE_WALL_MISC)
    {
        type = o->oOW2CtlLastGoodFloorType;
    }
    else
    {
        o->oOW2CtlLastGoodFloorType = type;
    }

    ow_ctl2_degrade_color(mat_triarc_rock_f3d_material_001_layer5, 13);
    ow_ctl2_degrade_color(mat_triarc_comb__23_f3d, 20);
    ow_ctl2_degrade_color(mat_triarc_comb__23_f3d, 20);
    ow_ctl2_degrade_color(mat_triarc_plat0_Stoney, 20);
    ow_ctl2_degrade_color(mat_triarc_plat0_Grass, 20);
    ow_ctl2_degrade_color(mat_triarc_plat1_Stoney, 20);
    ow_ctl2_degrade_color(mat_triarc_plat1_Leaves_001, 13);
    s32 ending = 0;
    if (sOW2Vertices[OW2_VTX_HONEY].enabled && SURFACE_NOISE_DEFAULT == type)
    {
        {
            rgb color = { 0xCC, 0x8E, 0x3D, 0x00 };
            ow_ctl2_approach_color0(&color);
        }
        {
            rgb color = { 148, 92, 198, 0x00 };
            ow_ctl2_approach_color1(&color);
        }
        {
            rgb color = { 92, 198, 187, 0x00 };
            ow_ctl2_approach_color2(&color);
        }
        {
            rgb color = { 229, 52, 82, 0x00 };
            ow_ctl2_approach_color3(&color);
        }

        ow_ctl2_spawn_and_undegrade(mat_triarc_comb__23_f3d, 20, 1, MODEL_TRIARC_COMB, -5459.f, -3347.f);
    }
    else if (sOW2Vertices[OW2_VTX_SPACE].enabled && SURFACE_VANISH_CAP_WALLS == type)
    {
        {
            rgb color = { 0xB6, 0x56, 0xD4, 0x00 };
            ow_ctl2_approach_color0(&color);
        }
        {
            rgb color = { 83, 94, 74, 0x00 };
            ow_ctl2_approach_color1(&color);
        }
        {
            rgb color = { 131, 172, 178, 0x00 };
            ow_ctl2_approach_color2(&color);
        }
        {
            rgb color = { 24, 236, 94, 0x00 };
            ow_ctl2_approach_color3(&color);
        }

        ow_ctl2_spawn_and_undegrade(mat_triarc_rock_f3d_material_001_layer5, 13, 2, MODEL_TRIARC_ROCK, -4315.f, 2345.f);
    }
    else if (sOW2Vertices[OW2_VTX_GRASS].enabled && SURFACE_TTM_VINES == type)
    {
        {
            rgb color = { 0x7D, 0xC2, 0x9D, 0x00 };
            ow_ctl2_approach_color0(&color);
        }
        {
            rgb color = { 100, 142, 97, 0x00 };
            ow_ctl2_approach_color1(&color);
        }
        {
            rgb color = { 203, 12, 89, 0x00 };
            ow_ctl2_approach_color2(&color);
        }
        {
            rgb color = { 210, 124, 58, 0x00 };
            ow_ctl2_approach_color3(&color);
        }

        ow_ctl2_spawn_and_undegrade(mat_triarc_plat0_Stoney, 20, 3, MODEL_TRIARC_GRASS1, 5266.f, -2540.f);
        ow_ctl2_copy_alpha(mat_triarc_plat0_Stoney, 20, mat_triarc_plat0_Grass, 20);
        ow_ctl2_copy_alpha(mat_triarc_plat0_Stoney, 20, mat_triarc_plat1_Stoney, 20);
        ow_ctl2_copy_alpha(mat_triarc_plat0_Stoney, 20, mat_triarc_plat1_Leaves_001, 13);
    }
    else if (sOW2Vertices[OW2_VTX_RNG].enabled && SURFACE_SWITCH == type)
    {
        {
            rgb color = { 0x35, 0x4C, 0xBD, 0x0 };
            ow_ctl2_approach_color0(&color);
        }
        ow_ctl2_approach_color1((rgb*)&o->oOW2CtlRNGColor1);
        ow_ctl2_approach_color2((rgb*)&o->oOW2CtlRNGColor2);
        ow_ctl2_approach_color3((rgb*)&o->oOW2CtlRNGColor3);
    }
    else if (o->oOW2CtlEndingStart && SURFACE_HARD == type)
    {
        ending = 1;
        for (unsigned i = 0; i < sizeof(sOW2OriginalColors) / sizeof(*sOW2OriginalColors); i++)
        {
            hsv target;
            rgb2hsv(&sOW2OriginalColors[i], &target);
            ow_ctl2_approach_colors(&sOW2Textures[i + 1].color, &target);
        }
            
        for (unsigned i = 0; i < sizeof(sOW2Vertices) / sizeof(*sOW2Vertices); i++)
        {
            hsv target;
            rgb2hsv(&sOW2OriginalColors[OW2_MAT_GRASS - 1], &target);
            ow_ctl2_approach_colors(&sOW2Vertices[i].color, &target); 
        }
    }
    else
    {
        // gray color
        hsv target = { 0, 255, 0.f };
        for (unsigned i = 0; i < sizeof(sOW2Textures) / sizeof(*sOW2Textures); i++)
        {
            ow_ctl2_approach_colors(&sOW2Textures[i].color, &target);
        }
        for (unsigned i = 0; i < sizeof(sOW2Vertices) / sizeof(*sOW2Vertices); i++)
        {
            ow_ctl2_approach_colors(&sOW2Vertices[i].color, &target);
        }
    }

    sOW2Textures[0].color.a = approach_s32(sOW2Textures[0].color.a, ending ? 0 : 90, 2, 2);
    ow2_write_colors();
}

void ow_decor_loop()
{
    u8* ptr = NULL;
    switch(o->oBehParams2ndByte)
    {
        case 1:
        {
            ptr = (u8*) segmented_to_virtual(mat_triarc_comb__23_f3d) + 20*8 + 7;
            o->oFaceAngleYaw += 0x39;
            o->oFaceAngleRoll += 023;
        }
        break;
        case 2:
        {
            ptr = (u8*) segmented_to_virtual(mat_triarc_rock_f3d_material_001_layer5) + 13*8 + 7;
            o->oFaceAngleYaw += 0x39;
            o->oFaceAngleRoll += 023;
        }
        break;
        case 3:
        {
            ptr = (u8*) segmented_to_virtual(mat_triarc_plat0_Stoney) + 20*8 + 7;
            o->oFaceAngleYaw += 0x39;
            o->oFaceAngleRoll += 023;
        }
        break;
    }

    if (0 == *ptr)
    {
        o->activeFlags = 0;
    }
}
