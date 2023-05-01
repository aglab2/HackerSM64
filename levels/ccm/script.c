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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 142, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 1, 141, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_TOTWC, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 424, 3240, -1999, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -621, 3150, -1879, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -1299, 3150, -2264, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -2060, 3150, -2255, 0, 0, 0, 0x0, bhv1Up),
		OBJECT_WITH_ACTS(140, 2577, 570, 2035, 0, -9, 0, 0x0, bhvBlueCoinSwitch, ACT_6),
		OBJECT_WITH_ACTS(0, 2469, 2636, -803, 0, 0, 0, 0x0, bhvCoinFormation, ACT_6),
		OBJECT(0, 1281, 2445, 3013, 0, -80, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -2052, 19, 712, 0, 27, 0, 0x0, bhvCoinFormation),
		OBJECT_WITH_ACTS(0, -752, 420, 745, 0, 0, 0, 0x110000, bhvCoinFormation, ACT_6),
		OBJECT_WITH_ACTS(137, -1645, 930, -1642, 0, 12, 0, 0x10000, bhvExclamationBox, ACT_1 | ACT_2),
		OBJECT_WITH_ACTS(137, -1467, 1680, 2741, 0, 32, 0, 0x10000, bhvExclamationBox, ACT_4),
		OBJECT_WITH_ACTS(137, 2426, 480, -1066, 0, 0, 0, 0x60000, bhvExclamationBox, ACT_6),
		OBJECT(137, -1247, 360, 2592, 0, -26, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, -1699, 298, -1892, 0, -7, 0, 0x50000, bhvExclamationBox),
		OBJECT_WITH_ACTS(0, -2964, 780, -1118, 0, 87, 0, 0x0, bhvFlamethrower, ACT_1),
		OBJECT_WITH_ACTS(0, -3142, 900, -477, 0, 89, 0, 0x0, bhvFlamethrower, ACT_1),
		OBJECT_WITH_ACTS(0, -3150, 1200, 1167, 0, 87, 0, 0x0, bhvFlamethrower, ACT_1),
		OBJECT_WITH_ACTS(0, -3344, 1260, 1857, 0, 86, 0, 0x0, bhvFlamethrower, ACT_1),
		OBJECT_WITH_ACTS(0, -1798, 1440, 2735, 0, -119, 0, 0x0, bhvFlamethrower, ACT_1),
		OBJECT_WITH_ACTS(118, 2130, 450, 1687, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 1517, 360, 1025, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 1017, 210, 233, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 353, 60, -673, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, -175, 60, -1310, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, -714, 90, -1801, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, -1295, 180, -2211, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(0, 953, 540, 1852, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar, ACT_6),
		OBJECT(124, 2134, 240, 36, 0, -64, 0, 0x2e0000, bhvMessagePanel),
		OBJECT(187, -2799, 1050, 1252, 90, -60, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT_WITH_ACTS(215, -385, 180, 311, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -2650, 1020, 3207, 0, 175, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -2691, 810, -1632, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -2861, 870, 431, 0, 87, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -1339, 1170, 2254, 0, 152, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 2443, 3060, 270, 0, -90, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 1069, 2880, 1405, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 67, 660, 3248, 0, -178, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT(0, 1192, 330, 468, 0, -97, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT_WITH_ACTS(122, -2101, 2100, 2119, 0, 0, 0, 0x0, bhvStar, ACT_1),
		OBJECT(122, 2436, -390, -1066, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 128, 3060, -1455, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT_WITH_ACTS(122, -1133, 2790, 3186, 0, 0, 0, 0x3000000, bhvStar, ACT_4),
		OBJECT(122, -1703, 4020, 480, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(88, 2423, -300, -1063, 0, -129, 0, 0x0, bhvThwomp),
		OBJECT_WITH_ACTS(88, -794, 2596, 3168, 0, -180, 0, 0x0, bhvThwomp, ACT_4),
		OBJECT_WITH_ACTS(88, -448, 2596, 3166, 0, -180, 0, 0x0, bhvThwomp, ACT_4),
		OBJECT(88, 84, 1546, 3163, 0, -180, 0, 0x0, bhvThwomp),
		OBJECT(88, 504, 2896, 3169, 0, -180, 0, 0x0, bhvThwomp),
		OBJECT(27, -573, 23, -275, 0, 0, 0, 0x0, bhvTree),
		OBJECT(27, -1056, 21, 541, 0, 0, 0, 0x0, bhvTree),
		OBJECT(27, -491, 27, 908, 0, 0, 0, 0x0, bhvTree),
		OBJECT(27, 100, 22, 729, 0, 0, 0, 0x0, bhvTree),
		OBJECT(22, -731, 1990, -2690, 0, 0, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 6),
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
