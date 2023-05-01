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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_mio0SegmentRomStart, _generic_mio0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
#if 0
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, wf_geo_0007E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, wf_geo_000820), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, wf_geo_000860), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, wf_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, wf_geo_000890), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, wf_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, wf_geo_0008E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, wf_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, wf_geo_000940), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, wf_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, wf_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, wf_geo_0009D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, wf_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
#endif

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(241, LEVEL_CASTLE, 1, 122, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 121, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_COTMC, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 2621, 1710, -12, 0, 0, 0, 0x0, bhv1Up),
		OBJECT_WITH_ACTS(140, 1892, 2640, -10, 0, 0, 0, 0x0, bhvBlueCoinSwitch, ACT_5),
		OBJECT_WITH_ACTS(0, -1035, 4617, 2372, 0, 90, 0, 0x0, bhvCoinFormation, ACT_5),
		OBJECT_WITH_ACTS(0, -1476, 3647, -2206, 0, -90, 0, 0x0, bhvCoinFormation, ACT_5),
		OBJECT_WITH_ACTS(0, -2174, 3960, -50, 0, 0, 0, 0x0, bhvCoinFormation, ACT_5),
		OBJECT_WITH_ACTS(137, 2021, 2970, -230, 0, 0, 0, 0x30000, bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(137, 2021, 2970, -30, 0, 0, 0, 0x30000, bhvExclamationBox, ACT_3 | ACT_4 | ACT_6),
		OBJECT_WITH_ACTS(137, 2021, 2970, 170, 0, 0, 0, 0x30000, bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(137, -71, 3900, -26, 0, 0, 0, 0x50000, bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(137, -2179, 5250, -27, 0, 0, 0, 0x60000, bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(137, -80, 5790, 2378, 0, 0, 0, 0x50000, bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(137, -63, -1080, -27, 0, 0, 0, 0x60000, bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(207, -61, -1467, -25, 0, -180, 0, 0x0, bhvFloorSwitchGrills, ACT_1 | ACT_2),
		OBJECT_WITH_ACTS(118, 2028, 2670, -789, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_5),
		OBJECT_WITH_ACTS(118, 2028, 2670, -1100, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_5),
		OBJECT_WITH_ACTS(118, 2028, 2820, -1400, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_5),
		OBJECT_WITH_ACTS(118, 2028, 2970, -1700, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_5),
		OBJECT_WITH_ACTS(118, 1474, 3090, -2195, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_5),
		OBJECT_WITH_ACTS(118, 1005, 3330, -2195, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_5),
		OBJECT_WITH_ACTS(0, -80, 1740, 2377, 0, 0, 0, 0x4000000, bhvHiddenRedCoinStar, ACT_5),
		OBJECT_WITH_ACTS(0, -81, 420, -2112, 0, 0, 0, 0x3000000, bhvHiddenStar, ACT_4),
		OBJECT_WITH_ACTS(122, -642, -279, 980, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_4),
		OBJECT_WITH_ACTS(122, -1262, 663, -767, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_4),
		OBJECT_WITH_ACTS(122, 881, 1353, 832, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_4),
		OBJECT_WITH_ACTS(122, 467, 1971, -826, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_4),
		OBJECT_WITH_ACTS(122, -905, 2394, 781, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_4),
		OBJECT_WITH_ACTS(124, 2208, 2640, -8, 0, -90, 0, 0x120000, bhvMessagePanel, ACT_1 | ACT_2),
		OBJECT_WITH_ACTS(0, -66, 0, 1827, 0, 0, 0, 0x0, bhvOpenableGrill, ACT_1 | ACT_2),
		OBJECT(187, 2020, 2642, -548, 90, 0, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, -75, -1365, -688, 0, 0, 0, 0x8a0000, bhvPoleGrabbing),
		OBJECT(0, -72, -915, -1205, 0, 0, 0, 0x5d0000, bhvPoleGrabbing),
		OBJECT(0, 2621, 345, -25, 0, 0, 0, 0x790000, bhvPoleGrabbing),
		OBJECT_WITH_ACTS(0, -2562, 4035, 133, 0, 0, 0, 0x5f0000, bhvPoleGrabbing, ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(0, 136, 4615, 2770, 0, 0, 0, 0x550000, bhvPoleGrabbing, ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(215, -97, 3660, -2188, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, -2167, 5010, -11, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, -82, 5520, 2383, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, 2056, 1020, -18, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, -68, 3594, -21, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, -78, 2580, 1168, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, -572, 1710, 465, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT_WITH_ACTS(215, -2156, 2490, 334, 0, 0, 0, 0x0, bhvRedCoin, ACT_5),
		OBJECT(0, -78, 120, -2129, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT_WITH_ACTS(122, -78, 2990, 2382, 0, 0, 0, 0x0, bhvStar, ACT_1),
		OBJECT_WITH_ACTS(122, -60, 275, 2499, 0, 0, 0, 0x1000000, bhvStar, ACT_1 | ACT_2),
		OBJECT_WITH_ACTS(122, -74, 4890, 2387, 0, 0, 0, 0x2000000, bhvStar, ACT_3 | ACT_4 | ACT_6),
		OBJECT_WITH_ACTS(122, -2070, 261, -23, 0, 0, 0, 0x5000000, bhvStar, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_6),
		OBJECT(22, -74, -1377, 2300, 0, 0, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 4),
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
