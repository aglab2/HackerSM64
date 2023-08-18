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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, lll_geo_0009E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, lll_geo_0009F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, lll_geo_000A10), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, lll_geo_000A28), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, lll_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, lll_geo_000A60), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, lll_geo_000A90), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, lll_geo_000AA8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, lll_geo_000AC0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, lll_geo_000AD8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, lll_geo_000AF0), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_DRAWBRIDGE_PART, lll_geo_000B20), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_ROTATING_BLOCK_FIRE_BARS, lll_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_ROTATING_HEXAGONAL_RING, lll_geo_000BB0), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, lll_geo_000BC8), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_SQUARE_PLATFORMS, lll_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_TILTING_SQUARE_PLATFORM, lll_geo_000BF8), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_1, lll_geo_bowser_puzzle_piece_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_2, lll_geo_bowser_puzzle_piece_2), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_3, lll_geo_bowser_puzzle_piece_3), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_4, lll_geo_bowser_puzzle_piece_4), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_5, lll_geo_bowser_puzzle_piece_5), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_6, lll_geo_bowser_puzzle_piece_6), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_7, lll_geo_bowser_puzzle_piece_7), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_8, lll_geo_bowser_puzzle_piece_8), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_9, lll_geo_bowser_puzzle_piece_9), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_10, lll_geo_bowser_puzzle_piece_10), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_11, lll_geo_bowser_puzzle_piece_11), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_12, lll_geo_bowser_puzzle_piece_12), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_13, lll_geo_bowser_puzzle_piece_13), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_14, lll_geo_bowser_puzzle_piece_14), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, lll_geo_000B08), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_ROCK_BLOCK, lll_geo_000DD0), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_ROLLING_LOG, lll_geo_000DE8), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_ROTATING_HEXAGONAL_PLATFORM, lll_geo_000A78), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_WOOD_BRIDGE, lll_geo_000B50), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_LARGE_WOOD_BRIDGE, lll_geo_000B68), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_FALLING_PLATFORM, lll_geo_000B80), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_LARGE_FALLING_PLATFORM, lll_geo_000B98), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_VOLCANO_FALLING_TRAP, lll_geo_000EA8), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 117, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 1, 101, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_LLL, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_LLL, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_LLL, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(140, 6203, 1525, 3442, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(195, -1959, 1210, 7236, 0, -154, 0, 0x0, bhvBobombBuddyOpensCannon),
		OBJECT(129, 1087, -931, -4991, 0, 10, 0, 0x0, bhvBreakableBox),
		OBJECT(130, 1433, -931, -5063, 0, 10, 0, 0x0, bhvBreakableBoxSmall),
		OBJECT(201, -2300, 870, -1618, 0, 0, 0, 0x0, bhvCannonClosed),
		OBJECT(0, 2173, -693, 2413, 0, 161, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -6533, -2275, -6229, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4547, 804, -2075, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT_WITH_ACTS(100, -2613, -581, 7066, 0, 0, 0, 0x10000, bhvFirePiranhaPlant, ACT_1),
		OBJECT_WITH_ACTS(100, -3629, -581, 921, 0, 0, 0, 0x10000, bhvFirePiranhaPlant, ACT_1),
		OBJECT_WITH_ACTS(100, 3107, -581, -5263, 0, 0, 0, 0x10000, bhvFirePiranhaPlant, ACT_1),
		OBJECT_WITH_ACTS(100, 6279, -581, -2815, 0, 0, 0, 0x10000, bhvFirePiranhaPlant, ACT_1),
		OBJECT_WITH_ACTS(100, 1026, -581, 6080, 0, 0, 0, 0x10000, bhvFirePiranhaPlant, ACT_1),
		OBJECT(207, -5859, -581, 6539, 0, 90, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 3564, -357, 5657, 0, 0, 0, 0x10000, bhvGoombaTripletSpawner),
		OBJECT(0, 3559, -581, -1039, 0, 0, 0, 0x10000, bhvGoombaTripletSpawner),
		OBJECT(0, 225, -931, -4068, 0, 0, 0, 0x10000, bhvGoombaTripletSpawner),
		OBJECT(0, -3072, 790, -4073, 0, 0, 0, 0x10000, bhvGoombaTripletSpawner),
		OBJECT(0, 7298, 1525, 70, 0, 0, 0, 0x10000, bhvGoombaTripletSpawner),
		OBJECT(118, 7410, 1525, 3523, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 8340, 1525, 3098, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 9291, 1525, 2317, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 9879, 1525, 1282, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 10024, 1525, 267, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, -2301, 417, 5356, 0, 15, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2350, 417, 5170, 0, 15, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -5278, -260, 3991, 0, 0, 0, 0x4000000, bhvHiddenRedCoinStar),
		OBJECT(100, -1220, 790, -5708, 0, 0, 0, 0x0, bhvPiranhaPlant),
		OBJECT(100, -4221, -581, -610, 0, 0, 0, 0x0, bhvPiranhaPlant),
		OBJECT(215, -1550, 230, 6450, 0, -81, 0, 0x0, bhvRedCoin),
		OBJECT(215, -152, 1429, -3768, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4838, 850, -105, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3130, 776, 6133, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4645, -671, 1077, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1073, -865, -4995, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 7029, 1525, -2715, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2649, -535, 5466, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(103, -2278, -581, 4073, 0, 90, 0, 0x0, bhvSmallWhomp),
		OBJECT(0, 5074, -301, -3998, 0, -27, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -3647, 1761, 6485, 1, 0, 2, 0x2000000, bhvStar),
		OBJECT(122, -1051, -3177, -8700, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(122, -4819, 2320, -196, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 8907, 1475, 907, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(22, -4175, -581, 150, 0, 0, 0, 0xc0000, bhvWarpPipe),
		OBJECT(22, -2600, -2275, -1133, 0, -180, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 38),
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
