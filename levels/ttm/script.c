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
#include "levels/ttm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttm_segment_7SegmentRomStart, _ttm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _mountain_yay0SegmentRomStart, _mountain_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ttm_segment_7SegmentRomStart, _ttm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group5_mio0SegmentRomStart, _group5_mio0SegmentRomEnd), 
	LOAD_MIO0(0x6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd), 
	LOAD_RAW(0xd, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttm_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE, 1, 112, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 96, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_TTM, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_TTM, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_TTM, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_TTM, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_TTM, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(140, 1654, 293, -857, 0, 50, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(129, -5454, 281, -1214, 0, 60, 0, 0x0, bhvBreakableBox),
		OBJECT(129, -5280, 281, -1114, 0, 60, 0, 0x10000, bhvBreakableBox),
		OBJECT(0, -3335, 2831, 7522, 0, 0, 0, 0x0, bhvCheckerboardElevatorGroup),
		OBJECT(223, -6005, 281, -2191, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -407, 8, -10425, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, 7042, 1178, 5958, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -5615, 134, -5914, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4642, 330, 2558, 0, 54, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1795, 8, -10257, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 7285, 2005, -7039, 0, 117, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4009, 333, -1171, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 6411, 1803, 5655, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(180, 8261, 2234, -7723, 0, 45, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 3603, 1069, -7563, 0, 63, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -3609, 281, -1854, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 8278, -712, -1927, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -1592, 2049, 6895, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1022, 293, -1923, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(0, 8629, 2172, -8342, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 4570, 1052, -7134, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 7197, 1634, -6955, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(207, 854, 293, -1425, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, -6103, 8, -9585, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -4950, 281, -1900, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, 1689, -350, -216, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 2677, -350, 833, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 3021, 0, 1149, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 4192, 6, 2258, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, 1310, 293, -2250, 0, -14, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1264, 762, -2530, 0, 15, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1109, 1233, -2741, 0, 65, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 846, 1745, -2826, 0, 20, 0, 0x0, bhvHiddenObject),
		OBJECT(0, 5993, 1197, 3282, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar),
		OBJECT(194, 6109, -712, -4322, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(194, 7189, -712, -3242, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT_WITH_ACTS(0, 6893, 1751, 4838, 0, 0, 0, 0x0, bhvMrI, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT(0, -3813, 5009, 3487, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, 381, 293, -723, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, 8046, 687, -1060, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, -5019, 281, -2801, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 468, 8, -10268, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 6418, 1751, 4045, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(215, -872, -733, -11425, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -6900, 8, -10643, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5689, 883, 3852, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 537, 293, -2460, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2395, -712, -5411, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4965, 916, 3050, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1418, 1622, 3432, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -6551, 281, -2090, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(101, -1523, -733, -11731, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, -170, -733, -11565, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(0, -6252, 8, -11119, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 9506, 2932, -10611, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, -4701, 5344, 4710, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT_WITH_ACTS(122, 946, 2376, -2404, 0, -90, 0, 0x2000000, bhvStar, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT(122, 6825, -1936, 5955, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 9196, 2448, -300, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(27, -6737, 8, -10168, 0, 45, 0, 0x0, bhvTree),
		OBJECT(22, -4061, 281, -2332, 0, -68, 0, 0xc0000, bhvWarpPipe),
		OBJECT(22, 276, 293, -1920, 0, 55, 0, 0xb0000, bhvWarpPipe),
		OBJECT(22, 266, -733, -11213, 0, -158, 0, 0xe0000, bhvWarpPipe),
		OBJECT(22, 4406, -712, -5058, 0, 45, 0, 0xd0000, bhvWarpPipe),
		OBJECT(116, -1095, 664, 3649, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -1406, 216, 2650, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4224, 4195, 6688, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5520, 4182, 6424, 0, 0, 0, 0x0, bhvYellowCoin),
		TERRAIN(ttm_area_1_collision),
		MACRO_OBJECTS(ttm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 39),
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
