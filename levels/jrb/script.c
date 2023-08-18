#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _clouds_skybox_yay0SegmentRomStart, _clouds_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 100, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 116, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_JRB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_JRB, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_JRB, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, 6187, 364, -1902, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(140, 1486, 3211, 1581, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(88, -4973, 1979, -4704, 0, 0, 0, 0x0, bhvClamShell),
		OBJECT(88, 2055, -1612, -1207, 0, 0, 0, 0x0, bhvClamShell),
		OBJECT(88, 837, -4190, 2606, 0, 0, 0, 0x0, bhvClamShell),
		OBJECT(88, 2028, -325, 481, 0, 0, 0, 0x0, bhvClamShell),
		OBJECT(0, -3088, 2263, -4088, 0, 135, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1099, -4167, 2595, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -5410, 3945, 4499, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2133, -1353, -3125, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 3694, 3268, 2568, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 203, 1875, -107, 90, 0, 0, 0x130000, bhvCoinFormation),
		OBJECT(0, -3511, 3320, 3579, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 3497, -4189, -5204, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4890, -323, 133, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(137, 3865, 3646, 6291, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 4955, 3594, 2065, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(0, 583, 2683, -5387, 0, -154, 0, 0xe0000, bhvFadingWarp),
		OBJECT(0, 1680, 3835, -5523, 0, -153, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(0, 1655, 2500, 5124, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, -4478, 2448, -2441, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, 5398, -1094, -3637, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, 383, -3802, -3769, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, -4256, 2396, 813, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, -501, 2500, -4231, 0, 0, 0, 0x0, bhvFish),
		OBJECT(207, -1737, 3211, 1241, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(207, -6198, 4954, 3940, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT_WITH_ACTS(207, 884, 1958, 4513, 0, 60, 0, 0x0, bhvFloorSwitchHiddenObjects, ACT_3),
		OBJECT(0, 5396, 3232, 2740, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, 1831, 3232, 1015, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1892, 3232, 562, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1923, 3232, 96, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1756, 3232, -1096, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1873, 3232, -486, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, -4501, 4792, 2173, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -4501, 4792, 3123, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -4501, 4675, 4037, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -1513, 3125, 866, 0, 28, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -393, 4179, 282, 0, 28, 0, 0x0, bhvHiddenObject),
		OBJECT_WITH_ACTS(129, -712, 2956, 2810, 0, 0, 0, 0x0, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -512, 2956, 2810, 0, 0, 0, 0x0, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -712, 2956, 3710, 0, 0, 0, 0x0, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -512, 2956, 3710, 0, 0, 0, 0x0, bhvHiddenObject, ACT_3),
		OBJECT(129, -748, 3748, 457, 0, 28, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -1144, 3422, 665, 0, 28, 0, 0x0, bhvHiddenObject),
		OBJECT(0, 4207, 3685, 1999, 0, 0, 0, 0x4000000, bhvHiddenRedCoinStar),
		OBJECT(0, 3263, 0, -3632, 0, 0, 0, 0x0, bhvManyBlueFishSpawner),
		OBJECT(0, -2123, -3490, 817, 0, 0, 0, 0x0, bhvManyBlueFishSpawner),
		OBJECT(0, 374, 2031, 622, 0, 0, 0, 0x0, bhvManyBlueFishSpawner),
		OBJECT(124, 1469, 3211, -1710, 0, 0, 0, 0x120000, bhvMessagePanel),
		OBJECT(215, 4630, -1111, -1136, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -155, 1489, -897, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4004, 3268, 4495, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4801, -626, -5794, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3363, 2406, -5930, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5954, 3232, 2141, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6001, 1979, 6245, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1929, 3246, 497, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(105, -239, 3216, 106, 0, 0, 0, 0x0, bhvSkeeter),
		OBJECT(105, -4788, 3216, 1248, 0, 0, 0, 0x0, bhvSkeeter),
		OBJECT(105, 4210, 3216, 5030, 0, 0, 0, 0x0, bhvSkeeter),
		OBJECT(105, 5535, 3216, 4561, 0, 0, 0, 0x0, bhvSkeeter),
		OBJECT(105, -5275, 3216, 1919, 0, 0, 0, 0x0, bhvSkeeter),
		OBJECT(0, 1675, 3784, -1285, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -283, -3854, 5005, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, -52, 4635, 94, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -4501, 5313, -694, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(122, -2957, -3437, -1150, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, -1010, 3959, 3323, 0, 0, 0, 0x2000000, bhvStar),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 5),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
