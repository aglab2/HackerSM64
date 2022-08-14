#include "game/color.h"

extern u16 gDnvicCounter;
extern u16 gDnvicChamber;
extern u8  gDnvicMapAlpha;
extern s8  gDnvicMapAlphaVelocity;
extern hsv gDnvicColor;
extern hsv gDnvicCurrentColor;

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

static void cur_obj_unload_object_with_behavior_and_bparam3(const BehaviorScript *behavior, int param) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
            && GET_BPARAM3(obj->oBehParams) == param
        ) {
            obj->activeFlags = 0;
        }

        obj = (struct Object *) obj->header.next;
    }
}

static void cur_obj_unload_object_with_behavior(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
        ) {
            obj->activeFlags = 0;
        }

        obj = (struct Object *) obj->header.next;
    }

    return NULL;
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

    return NULL;
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

    return NULL;
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
