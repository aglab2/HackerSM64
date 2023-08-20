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
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _c4_skybox_mio0SegmentRomStart, _c4_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
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
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 99, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 115, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_CCM, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_CCM, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_CCM, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_CCM, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CCM, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(140, 2122, 1808, -2561, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(223, -1941, -690, 949, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, 4270, 1167, -3976, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -2629, -363, -350, 0, 45, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -5324, 649, -703, 0, 12, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4965, -649, 1814, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 6465, 825, -2412, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2798, -1506, -2097, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -5365, -94, -710, 0, 10, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 538, 40, 1850, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 3105, 3879, -136, 0, 5, 0, 0x0, bhvCoinFormation),
		OBJECT(207, 5568, 2746, 1118, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(207, 1607, 395, -4215, 0, -90, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(192, -4015, -1082, 1332, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -3948, -165, -2054, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(0, 1605, 1808, -2836, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, 1640, 1808, -2340, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1739, 1192, -1260, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 2000, 604, 172, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 2300, 287, 2140, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, 5250, 2746, 1118, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 5050, 2946, 1118, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 4850, 3146, 1118, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 4650, 3346, 1118, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1080, 395, -4300, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 880, 595, -4300, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 680, 795, -4300, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 680, 995, -4100, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 680, 1195, -3900, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 680, 1395, -3700, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -927, -377, 1104, 0, 0, 0, 0x4000000, bhvHiddenRedCoinStar),
		OBJECT_WITH_ACTS(0, 3048, -1858, 1057, 0, 0, 0, 0x0, bhvHiddenStar, ACT_1),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 4053, -2853, -249, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_1),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 1926, -2853, -290, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_1),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 1617, -2853, 1016, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_1),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 3920, -2853, 2201, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_1),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 1839, -2853, 2233, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_1),
		OBJECT_WITH_ACTS(124, 2696, -2091, 954, 0, -90, 0, 0x5a0000, bhvMessagePanel, ACT_1),
		OBJECT(124, -1554, 422, -3005, 0, -59, 0, 0x5b0000, bhvMessagePanel),
		OBJECT(116, -4927, -165, 245, 0, 0, 0, 0x0, bhvMoneybagHidden),
		OBJECT(86, 614, -12, 1159, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(86, -1921, -690, 1755, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(86, -4007, -1840, 7872, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(86, 7051, 555, -1644, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(86, -5845, -165, -1850, 0, 0, 0, 0x0, bhvMrBlizzard),
		OBJECT(116, 1607, 1800, -4215, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT_WITH_ACTS(120, 2959, -2083, 1615, 0, 0, 0, 0x0, bhvRecoveryHeart, ACT_1),
		OBJECT(215, 7446, 555, -2330, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4627, 1256, -3129, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5030, -323, 1390, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3030, -334, 85, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 634, -12, 2725, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 594, 1808, -2875, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4266, -624, 1441, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2846, -2091, 153, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(87, -175, 115, -4099, 0, 0, 0, 0x0, bhvSmallPenguin),
		OBJECT(87, -4212, -165, -1639, 0, 0, 0, 0x10000, bhvSmallPenguin),
		OBJECT(87, -3046, -165, -1782, 0, -180, 0, 0x10000, bhvSmallPenguin),
		OBJECT(87, -4195, -165, -542, 0, 90, 0, 0x10000, bhvSmallPenguin),
		OBJECT(0, -4574, -1082, 2343, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(84, -4882, -1161, 3265, 0, 0, 0, 0x0, bhvSpindrift),
		OBJECT(122, 4512, 5386, -1188, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, -4661, -1580, 8039, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, -2582, -2484, -4443, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(25, 6566, 555, -2001, 0, 0, 0, 0x0, bhvTree),
		OBJECT(25, -5420, -1082, 2463, 0, 0, 0, 0x0, bhvTree),
		OBJECT(25, -6133, -165, -756, 0, 0, 0, 0x0, bhvTree),
		OBJECT(87, -3343, -256, -2779, 0, 0, 0, 0x3000000, bhvTuxiesMother),
		OBJECT(22, 630, 1808, -2390, 0, 90, 0, 0xc0000, bhvWarpPipe),
		OBJECT(22, -1303, -690, 1688, 0, -180, 0, 0xb0000, bhvWarpPipe),
		OBJECT_WITH_ACTS(22, 252, -12, 2443, 0, -180, 0, 0xd0000, bhvWarpPipe, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(22, 3048, -2149, 1057, 0, 0, 0, 0xe0000, bhvWarpPipe, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(0, 4053, -2853, -249, 0, 0, 0, 0x0, bhvYellowCoin, ACT_1),
		OBJECT_WITH_ACTS(0, 1926, -2853, -290, 0, 0, 0, 0x0, bhvYellowCoin, ACT_1),
		OBJECT_WITH_ACTS(0, 1617, -2853, 1016, 0, 0, 0, 0x0, bhvYellowCoin, ACT_1),
		OBJECT_WITH_ACTS(0, 3920, -2853, 2201, 0, 0, 0, 0x0, bhvYellowCoin, ACT_1),
		OBJECT_WITH_ACTS(0, 1839, -2853, 2233, 0, 0, 0, 0x0, bhvYellowCoin, ACT_1),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 8),
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
