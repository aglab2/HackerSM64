#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

#include "make_const_nonconst.h"
#include "levels/bitfs/header.h"

static const LevelScript script_func_local_1[] = {
    OBJECT(/*model*/ MODEL_BITFS_PLATFORM_ON_TRACK,       /*pos*/ -5733, -3071,    0, /*angle*/ 0, 0, 0,   /*behParam*/ 0x07330000, /*beh*/ bhvPlatformOnTrack),
    OBJECT(/*model*/ MODEL_BITFS_TILTING_SQUARE_PLATFORM, /*pos*/ -1945, -3225, -715, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvBitfsTiltingInvertedPyramid),
    OBJECT(/*model*/ MODEL_BITFS_TILTING_SQUARE_PLATFORM, /*pos*/ -2866, -3225, -715, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvBitfsTiltingInvertedPyramid),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_PLATFORMS,       /*pos*/ -1381,  3487,   96, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvBitfsSinkingPlatforms),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_PLATFORMS,       /*pos*/  1126, -3065,  307, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvBitfsSinkingPlatforms),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_PLATFORMS,       /*pos*/ -3225,  3487,   96, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvBitfsSinkingPlatforms),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_CAGE_PLATFORM,   /*pos*/  6605, -3071,  266, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvBitfsSinkingCagePlatform),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_CAGE_PLATFORM,   /*pos*/  1843,  3584,   96, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00010000, /*beh*/ bhvBitfsSinkingCagePlatform),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_CAGE_PLATFORM,   /*pos*/   614,  3584,   96, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00010000, /*beh*/ bhvBitfsSinkingCagePlatform),
    OBJECT(/*model*/ MODEL_BITFS_SINKING_CAGE_PLATFORM,   /*pos*/  3072,  3584,   96, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00010000, /*beh*/ bhvBitfsSinkingCagePlatform),
    OBJECT(/*model*/ MODEL_BITFS_ELEVATOR,                /*pos*/  2867, -1279,  307, /*angle*/ 0, 0, 0,   /*behParam*/ 0x029F0000, /*beh*/ bhvActivatedBackAndForthPlatform),
    OBJECT(/*model*/ MODEL_BITFS_STRETCHING_PLATFORMS,    /*pos*/ -5836,   410,  300, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00000000, /*beh*/ bhvSquishablePlatform),
    OBJECT(/*model*/ MODEL_BITFS_SEESAW_PLATFORM,         /*pos*/  4454, -2226,  266, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00040000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_BITFS_SEESAW_PLATFORM,         /*pos*/  5786, -2380,  266, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00040000, /*beh*/ bhvSeesawPlatform),
    OBJECT(/*model*/ MODEL_BITFS_MOVING_SQUARE_PLATFORM,  /*pos*/ -3890,   102,  617, /*angle*/ 0, 90, 0,  /*behParam*/ 0x020C0000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_BITFS_MOVING_SQUARE_PLATFORM,  /*pos*/ -3276,   102,    2, /*angle*/ 0, 270, 0, /*behParam*/ 0x020C0000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_BITFS_SLIDING_PLATFORM,        /*pos*/  2103,   198,  312, /*angle*/ 0, 0, 0,   /*behParam*/ 0x031F0000, /*beh*/ bhvSlidingPlatform2),
    OBJECT(/*model*/ MODEL_BITFS_TUMBLING_PLATFORM,       /*pos*/  4979,  4250,   96, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00030000, /*beh*/ bhvWfTumblingBridge),
    OBJECT(/*model*/ MODEL_NONE,                          /*pos*/  3890, -2043,  266, /*angle*/ 0, 0, 0,   /*behParam*/ 0x00520000, /*beh*/ bhvPoleGrabbing),
    RETURN(),
};

static const LevelScript script_func_local_2[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -3226, 3584, -822, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/ -1382, 3584, -822, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  1229,  307, -412, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvFlamethrower),
    RETURN(),
};

static const LevelScript script_func_local_3[] = {
    OBJECT(/*model*/ MODEL_NONE, /*pos*/  1200, 5700,  160, /*angle*/ 0, 0, 0, /*behParam*/ 0x00000000, /*beh*/ bhvBowserCourseRedCoinStar),
    RETURN(),
};

const LevelScript level_bitfs_entry[] = {
    INIT_LEVEL(),
#include "levels/bitfs/areas/script_vanilla.inc.c"
    ALLOC_LEVEL_POOL(),
    MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
#include "levels/bitfs/areas/script_vanilla_load.inc.c"

    AREA(/*index*/ 1, bitfs_geo_0007A0),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/ -7577, -1764,  0, /*angle*/ 0, 90, 0, /*behParam*/ 0x000A0000, /*beh*/ bhvAirborneWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/  6735,  3681, 99, /*angle*/ 0, 0, 0,  /*behParam*/ 0x140B0000, /*beh*/ bhvWarp),
        OBJECT(/*model*/ MODEL_NONE, /*pos*/  5886,  5000, 99, /*angle*/ 0, 90, 0, /*behParam*/ 0x000C0000, /*beh*/ bhvDeathWarp),
        WARP_NODE(/*id*/ 0x0A, /*destLevel*/ LEVEL_BITFS, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0B, /*destLevel*/ LEVEL_BOWSER_2, /*destArea*/ 0x01, /*destNode*/ 0x0A, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0x0C, /*destLevel*/ LEVEL_BITFS, /*destArea*/ 0x01, /*destNode*/ 0x0C, /*flags*/ WARP_NO_CHECKPOINT),
        WARP_NODE(/*id*/ 0xF1, /*destLevel*/ LEVEL_CASTLE, /*destArea*/ 0x03, /*destNode*/ 0x68, /*flags*/ WARP_NO_CHECKPOINT),
        JUMP_LINK(script_func_local_1),
        JUMP_LINK(script_func_local_2),
        JUMP_LINK(script_func_local_3),
        TERRAIN(/*terrainData*/ bitfs_seg7_collision_level),
        MACRO_OBJECTS(/*objList*/ bitfs_seg7_macro_objs),
        SET_BACKGROUND_MUSIC(/*settingsPreset*/ 0x0000, /*seq*/ SEQ_LEVEL_KOOPA_ROAD),
        TERRAIN_TYPE(/*terrainType*/ TERRAIN_STONE),
    END_AREA(),

    FREE_LEVEL_POOL(),
    MARIO_POS(/*area*/ 1, /*yaw*/ 90, /*pos*/ -7577, -2764, 0),
    CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
    CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
    CLEAR_LEVEL(),
    SLEEP_BEFORE_EXIT(/*frames*/ 1),
    EXIT(),
};
