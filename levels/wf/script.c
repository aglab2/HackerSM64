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
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
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
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(241, LEVEL_WF, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(70, LEVEL_COTMC, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(60, LEVEL_WF, 1, 60, WARP_NO_CHECKPOINT),
		WARP_NODE(50, LEVEL_WF, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(40, LEVEL_WF, 2, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(30, LEVEL_WF, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_CASTLE_GROUNDS, 1, 90, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 90, WARP_NO_CHECKPOINT),
		OBJECT(140, 4443, -359, -3529, 0, 0, 0, 0x110000, bhvBlueCoinSwitch),
		OBJECT(195, 4622, -666, 10175, 0, -180, 0, 0x410000, bhvBobombBuddy),
		OBJECT(0, 5525, -744, 4312, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3215, -608, 1806, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 5525, -479, -1170, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 7170, 121, -2931, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 6649, -780, 7454, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 7586, 1462, -1293, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 10322, -802, 5908, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 12501, -802, 5287, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -986, 955, -6460, 0, 155, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 2317, 79, -3286, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 1718, 381, -4803, 0, 40, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 664, -238, -2354, 0, 110, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1460, -238, -3263, 0, 25, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4442, -892, 8527, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -486, 0, 193, 0, 90, 0, 0x320000, bhvDeathWarp),
		OBJECT(0, 7923, -544, 2155, 0, 90, 0, 0x3c0000, bhvDeathWarp),
		OBJECT(137, 1760, -90, 4930, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 7389, 67, -554, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(0, 7489, 122, 2153, 0, 0, 0, 0x280000, bhvFadingWarp),
		OBJECT(42, -177, -377, -2133, 0, 0, 0, 0x0, bhvFlipswitch_Panel_MOP),
		OBJECT(42, 644, 713, -5675, 0, 0, 0, 0x0, bhvFlipswitch_Panel_MOP),
		OBJECT(42, 1013, 274, -4190, 0, 0, 0, 0x0, bhvFlipswitch_Panel_MOP),
		OBJECT(42, -1036, 278, -4390, 0, 0, 0, 0x0, bhvFlipswitch_Panel_MOP),
		OBJECT(42, -639, 1684, -5988, 0, 0, 0, 0x0, bhvFlipswitch_Panel_MOP),
		OBJECT(0, -275, 744, -3057, 0, 0, 0, 0x3000000, bhvFlipswitch_Panel_StarSpawn_MOP),
		OBJECT(207, 5456, -1264, 2029, 0, 0, 0, 0x0, bhvFloorSwitchGrills),
		OBJECT(118, 4443, -359, -2786, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 4443, -359, -1978, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 4443, -359, -1192, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6663, -359, -1192, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6663, -359, -1978, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(0, 5446, -1052, 2383, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, 5516, -1079, -1805, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, 5476, -1079, 6245, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(124, 1001, -64, 194, 0, -90, 0, 0x340000, bhvMessagePanel),
		OBJECT(124, 8051, -544, 2149, 0, -90, 0, 0x400000, bhvMessagePanel),
		OBJECT(85, 8718, -1031, 6578, 0, 0, 0, 0x10000, bhvMontyMole),
		OBJECT(85, 8921, -1013, 5329, 0, 0, 0, 0x10000, bhvMontyMole),
		OBJECT(85, 10923, -1265, 7399, 0, 0, 0, 0x10000, bhvMontyMole),
		OBJECT(85, 11532, -1044, 5881, 0, 0, 0, 0x10000, bhvMontyMole),
		OBJECT(84, 8718, -698, 6578, 0, 0, 0, 0x0, bhvMontyMoleHole),
		OBJECT(84, 8921, -698, 5329, 0, 0, 0, 0x0, bhvMontyMoleHole),
		OBJECT(84, 10923, -961, 7399, 0, 0, 0, 0x0, bhvMontyMoleHole),
		OBJECT(84, 10868, -802, 6235, 0, 0, 0, 0x0, bhvMontyMoleHole),
		OBJECT(84, 12507, -930, 5302, 0, 0, 0, 0x0, bhvMontyMoleHole),
		OBJECT(0, 3113, 54, -788, 0, 90, 0, 0x0, bhvOpenableGrill),
		OBJECT(101, 2340, 54, -774, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 9544, -763, 6011, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 11801, -763, 5742, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 1605, 246, -3937, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(0, -486, 0, 193, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 3400, 310, -816, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(122, 1569, 2274, 6613, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 7213, 1702, -720, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, 11069, 1052, 5140, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(100, 6988, 2291, -513, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 6970, 393, -296, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 7012, 416, 2653, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 6958, 299, 6416, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 4064, 383, 4319, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(100, 4075, 383, -2134, 0, 0, 0, 0x0, bhvSwoop),
		OBJECT(0, -950, 65, 200, 0, 0, 0, 0x14140000, bhvWarp),
		OBJECT(0, 8540, -845, 2141, 0, 0, 0, 0x1e0000, bhvWarp),
		OBJECT(22, 6431, -232, 9975, 0, -90, 0, 0x460000, bhvWarpPipe),
		OBJECT(0, 5565, -565, -3648, 0, 0, 0, 0x0, bhvWaterfallSoundLoop),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 43),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, wf_area_2),
		WARP_NODE(241, LEVEL_WF, 1, 60, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_WF, 1, 40, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 2, 0, WARP_NO_CHECKPOINT),
		OBJECT(0, -1452, 0, 24, 0, 0, 0, 0x140000, bhvFadingWarp),
		OBJECT(0, 3186, -214, -651, 0, 0, 0, 0x4000000, bhvHiddenRedCoinStar),
		OBJECT(120, 3175, -595, -31, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, 4795, -915, 1595, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(215, 3104, -640, -1924, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2555, -640, 1915, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3843, -960, 637, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4381, -640, -1935, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5130, -640, -1935, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6402, -640, -89, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5855, -640, 648, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3311, -640, 1920, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 0, 918, 0, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 43),
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
