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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 82, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 81, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(140, 2742, -749, 4629, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(188, -4498, -749, 1767, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, 5990, -749, 2381, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, -1856, -749, 5373, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, 1932, -749, 5298, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, -344, -749, 3083, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT_WITH_ACTS(195, 4834, -749, 87, 0, -180, 0, 0x100000, bhvBobombBuddy, ACT_1),
		OBJECT_WITH_ACTS(223, -3063, 1455, -3303, 0, 0, 0, 0x0, bhvChuckya, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT(0, 2205, 1190, 2493, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -5314, -746, -3166, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -3220, -749, 2500, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(137, -5966, -380, -6879, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(137, 4077, 417, 2069, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT_WITH_ACTS(137, 2320, 1500, 1574, 0, 0, 0, 0x0, bhvExclamationBox, ACT_6),
		OBJECT(0, 583, 2683, -5387, 0, -154, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, 1680, 3835, -5523, 0, -153, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(207, 3011, 1350, -2711, 0, 0, 0, 0x0, bhvFloorSwitchGrills),
		OBJECT(207, 3018, 1140, 1287, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 551, -749, -4852, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 5832, -749, 4892, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -2678, -749, -647, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, 1228, -749, 3877, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 2017, -749, 4390, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 987, -749, 1863, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 775, -749, 2863, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1572, -749, 609, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1462, -749, -802, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, 3011, 940, 694, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3011, 940, 494, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3011, 940, 94, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3011, 940, 294, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3011, 940, -106, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -4382, -384, 536, 0, 0, 0, 0x3000000, bhvHiddenRedCoinStar),
		OBJECT_WITH_ACTS(0, 2984, 1633, -1661, 0, 0, 0, 0x5000000, bhvHiddenStar, ACT_6),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 2334, 1184, 1597, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_6),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, -4431, 1921, -2467, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_6),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, -3081, 1501, -3377, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_6),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, -3220, 2783, 2560, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_6),
		OBJECT_WITH_ACTS(MODEL_SILVER_COIN, 2599, 1380, -2682, 0, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_6),
		OBJECT_WITH_ACTS(86, -3094, 1455, -3325, 0, 90, 0, 0x0, bhvKingBobomb, ACT_1),
		OBJECT_WITH_ACTS(0, 2602, 1350, -2677, 0, 0, 0, 0x0, bhvOneCoin, ACT_6),
		OBJECT_WITH_ACTS(0, -3072, 1500, -3374, 0, 0, 0, 0x0, bhvOneCoin, ACT_6),
		OBJECT_WITH_ACTS(0, -3220, 2783, 2560, 0, 0, 0, 0x0, bhvOneCoin, ACT_6),
		OBJECT_WITH_ACTS(0, -4431, 1920, -2457, 0, 0, 0, 0x0, bhvOneCoin, ACT_6),
		OBJECT_WITH_ACTS(0, 2322, 1170, 1588, 0, 0, 0, 0x0, bhvOneCoin, ACT_6),
		OBJECT(0, 1475, -749, 2800, 0, -90, 0, 0x0, bhvOpenableGrill),
		OBJECT(100, 5097, -749, -1999, 0, 90, 0, 0x0, bhvPiranhaPlant),
		OBJECT(100, 4623, -749, -3691, 0, 0, 0, 0x0, bhvPiranhaPlant),
		OBJECT(100, 2085, -749, -4211, 0, -180, 0, 0x0, bhvPiranhaPlant),
		OBJECT(215, 3832, 1140, 1347, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 8471, -151, -8105, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2217, -730, -4317, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1428, 312, -2278, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -681, -1041, 645, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3240, -749, 4200, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4884, -749, -3208, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3081, -749 + 30, -4491, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 5285, -749, -515, 0, -90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT_WITH_ACTS(122, -3220, 2783, 2560, 0, 0, 0, 0x1000000, bhvStar, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_5),
		OBJECT(122, 1711, -489, 2808, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, 9456, 726, 6946, 0, 0, 0, 0x4000000, bhvStar),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 3),
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
