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
#include "levels/wdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _wdw_skybox_yay0SegmentRomStart, _wdw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wdw_segment_7SegmentRomStart, _wdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM, wdw_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT, wdw_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM, wdw_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_EXPRESS_ELEVATOR, wdw_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_RECTANGULAR_FLOATING_PLATFORM, wdw_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ROTATING_PLATFORM, wdw_geo_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wdw_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE, 1, 115, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 99, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_WDW, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_WDW, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_WDW, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, 4608, -690, 431, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 5024, 3380, 876, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(140, -958, 6583, -3606, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(129, 5611, -2554, 4029, 0, 27, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 6878, -2554, 597, 0, 39, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 6758, -2354, 466, 0, 39, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 5611, -2354, 4029, 0, 27, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 6716, -2554, 400, 0, 39, 0, 0x0, bhvBreakableBox),
		OBJECT(128, 4145, 2630, -430, 0, 35, 0, 0x0, bhvCannon),
		OBJECT(128, 4300, -2560, 220, 0, 45, 0, 0x0, bhvCannon),
		OBJECT(128, -215, 3505, 1015, 0, 0, 0, 0x0, bhvCannon),
		OBJECT(0, 853, -3438, 311, 0, -36, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 115, 833, 3472, -99, 0, 0, 0x130000, bhvCoinFormation),
		OBJECT(0, 158, -1004, 3200, -78, -74, 0, 0x130000, bhvCoinFormation),
		OBJECT(0, 4881, -2477, 1927, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 6417, -1927, 1843, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT_WITH_ACTS(0, 604, -729, -589, 0, 81, 0, 0x0, bhvCoinFormation, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT(137, 49, -3125, 2079, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, -1484, -2500, -1320, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, -5238, -1250, 2284, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT_WITH_ACTS(207, -185, -7850, 4746, 0, -180, 0, 0x0, bhvFloorSwitchHiddenObjects, ACT_2),
		OBJECT_WITH_ACTS(207, -4191, -1645, 2665, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects, ACT_6),
		OBJECT(118, -103, 6596, -4027, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1853, 6596, -4187, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 2900, 6596, -3949, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 3693, 6596, -3348, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 4420, 6596, -2525, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, 965, -5700, 6223, 0, 74, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 872, -5364, 6558, 0, 74, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 530, -5156, 6759, 0, 20, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -4000, -1143, 1117, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -4300, -1487, 1117, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, 1279, 6962, -4100, 0, 0, 0, 0x4000000, bhvHiddenRedCoinStar),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvInitializeChangingWaterLevel),
		OBJECT(0, 529, -6042, 999, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT_WITH_ACTS(124, 215, -3490, 1320, 0, 147, 0, 0x400000, bhvMessagePanel, ACT_1),
		OBJECT(215, -843, -6198, -19, 0, 78, 0, 0x0, bhvRedCoin),
		OBJECT(215, 40, 1220, 3300, 0, 78, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4400, -1101, 3600, 0, 90, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1086, 1498, -5339, 0, 78, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5295, -1630, 561, 0, 78, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1110, -533, 3336, 0, 78, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5332, 6596, -1020, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1610, 6442, 5564, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT_WITH_ACTS(0, 812, -4446, 3251, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp, ACT_1 | ACT_2 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(0, -4684, -1290, 1798, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp, ACT_3),
		OBJECT_WITH_ACTS(0, 219, -480, -683, 0, 81, 0, 0xa0000, bhvSpinAirborneWarp, ACT_4),
		OBJECT(122, 3317, 6962, 3934, 0, 0, 0, 0x0, bhvStar),
		OBJECT_WITH_ACTS(122, 6890, 3333, 3645, 0, 0, 0, 0x2000000, bhvStar, ACT_3),
		OBJECT_WITH_ACTS(122, 526, -4844, 6810, 0, 0, 0, 0x1000000, bhvStar, ACT_2),
		OBJECT(122, -4710, -2500, -5417, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -3042, 2396, 1047, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(0, 456, 0, -1404, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, -4747, -1560, -499, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(22, -4082, 2162, 1063, 0, 90, 0, 0xc0000, bhvWarpPipe),
		OBJECT_WITH_ACTS(22, -3710, -667, 1117, 13, -3, 105, 0xb0000, bhvWarpPipe, ACT_6),
		OBJECT_WITH_ACTS(MODEL_WDW_WATER_LEVEL_DIAMOND, 20, -3420, 1631, 0, 146, 0, 0x0, bhvWaterLevelDiamond, ACT_1 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, -60, -5625, 1296, 0, 0, 0, 0x0, bhvWaterLevelDiamond),
		OBJECT_WITH_ACTS(MODEL_WDW_WATER_LEVEL_DIAMOND, -658, -885, 962, 0, 32, 0, 0x0, bhvWaterLevelDiamond, ACT_1 | ACT_4 | ACT_5),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, -1402, 2315, 3311, 0, -170, 0, 0x0, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, -246, 6480, 1530, 0, 0, 0, 0x0, bhvWaterLevelDiamond),
		OBJECT_WITH_ACTS(MODEL_WDW_WATER_LEVEL_DIAMOND, 1086, -690, -520, 0, 0, 0, 0x0, bhvWaterLevelDiamond, ACT_4),
		OBJECT(87, -2003, -6354, 401, 0, 0, 0, 0x0, bhvWhirlpool),
		OBJECT(116, -2583, -1771, 766, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, 2185, -156, 1677, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, 644, 3542, 2315, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, 756, 3542, 2500, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, 525, 3542, 2135, 0, 0, 0, 0x0, bhvYellowCoin),
		TERRAIN(wdw_area_1_collision),
		MACRO_OBJECTS(wdw_area_1_macro_objs),
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
