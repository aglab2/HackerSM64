#include "audio/external.h"
#include "game/print.h"
#include "engine/surface_load.h"
#include "seq_ids.h"

extern void seq_player_play_sequence(u8 player, u8 seqId, u16 arg2);

extern u8 gDoInertia;
extern u8 gDoPlatformDisplacement;
extern s32 gTatums;
extern u8 gAllowPausing;

u32 aglabScratch[100];

static void cur_obj_find_all_objects_with_behavior_and_bparam(const BehaviorScript *behavior, struct Object** objs, int param) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
            && obj->oBehParams2ndByte == param
        ) {
            *objs = obj;
            objs++;
        }

        obj = (struct Object *) obj->header.next;
    }
}

static struct Object* cur_obj_find_object_with_behavior_and_bparam(const BehaviorScript *behavior, int param) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
            && obj->oBehParams2ndByte == param
        ) {
            return obj;
        }

        obj = (struct Object *) obj->header.next;
    }

    return NULL;
}

static struct Object *cur_obj_find_nearest_object_with_behavior_y_biased(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;
    struct Object *closestObj = NULL;
    f32 minDist = 0x200000000;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
        ) {
            f32 dx = o->oPosX - obj->oPosX;
            f32 dy = o->oPosY - obj->oPosY;
            f32 dz = o->oPosZ - obj->oPosZ;
            f32 objDist = dx*dx + 10*dy*dy + dz*dz;
            if (objDist < minDist) {
                closestObj = obj;
                minDist = objDist;
            }
        }

        obj = (struct Object *) obj->header.next;
    }

    return closestObj;
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
}

static f32 random_float_ft(f32 from, f32 to)
{
    f32 d = to - from;
    return from + random_float() * d;
}

#include "aglab_ab.inc.c"
#include "aglab_mf.inc.c"
#include "aglab_df.inc.c"
#include "aglab_mtc.inc.c"
#include "aglab_hf.inc.c"
#include "aglab_vcm.inc.c"
#include "aglab_bdf.inc.c"
#include "aglab_slide.inc.c"
#include "aglab_fight.inc.c"
#include "aglab_ow.inc.c"
#include "aglab_crash.inc.c"
#include "aglab_pie.inc.c"
#include "aglab_spiders.inc.c"
#include "aglab_rng.inc.c"
#include "aglab_sphere.inc.c"
#include "luigiman.inc.c"

static void sparkler_make_unvisited_course_sparkle(int course, f32 x, f32 y, f32 z)
{
   if (0 == save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(course)))
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX = x + random_f32_around_zero(500.f);
        spark->oPosY = y + random_f32_around_zero(500.f);
        spark->oPosZ = z + random_f32_around_zero(500.f);
    }
}

void sparkler_loop()
{
    s32 isOWCS = gCurrLevelNum == LEVEL_CASTLE_GROUNDS && (o->header.gfx.node.flags & GRAPH_RENDER_INVISIBLE);
    if (gCamera->cutscene != CUTSCENE_AGLAB_MTC_CS && !isOWCS)
    {
        spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        if (gCurrLevelNum == LEVEL_CASTLE_GROUNDS)
        {
            {
                s32 div = o->oTimer % 8;
                if (0 == div) 
                    sparkler_make_unvisited_course_sparkle(COURSE_TOTWC, -3201.f, -916.f, 3804.f);
                if (1 == div)
                    sparkler_make_unvisited_course_sparkle(COURSE_CRASH, -4885.f, -915.f, 2784.f);
                if (2 == div)
                    sparkler_make_unvisited_course_sparkle(COURSE_COTMC, -3254.f, -915.f, 1510.f);
                if (3 == div)
                    sparkler_make_unvisited_course_sparkle(COURSE_PSS  ,  3802.f, 645.f, 199.f);
                if (4 == div)
                    sparkler_make_unvisited_course_sparkle(COURSE_VCM  ,  2572.f, 1218.f, -2741.f);
                if (5 == div)
                    sparkler_make_unvisited_course_sparkle(COURSE_DF   ,  2504.f, -830.f, -2651.f);
                if (6 == div)
                    sparkler_make_unvisited_course_sparkle(COURSE_WMOTR, -1344.f, -1243.f, 4343.f);
                if (7 == div)
                {
                    if (0x3 != save_file_get_star_flags((gCurrSaveFileNum - 1), COURSE_NUM_TO_INDEX(COURSE_VCUTM)))
                    {
                        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
                        spark->oPosX = -2211.f + random_f32_around_zero(500.f);
                        spark->oPosY = -731.f  + random_f32_around_zero(500.f);
                        spark->oPosZ = -1213.f + random_f32_around_zero(500.f);
                    }
                }
            }
        }
    }
}

void sparkler_slow_loop()
{
    if (0 == (o->oTimer % 16))
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX += random_f32_around_zero(500.f);
        spark->oPosY += random_f32_around_zero(500.f);
        spark->oPosZ += random_f32_around_zero(500.f);
    }
}
