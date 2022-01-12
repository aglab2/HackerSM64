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
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_15), 
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
	LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_ROCK_BLOCK, lll_geo_000DD0), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_SQUARE_PLATFORMS, lll_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, lll_geo_000BC8), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_TILTING_SQUARE_PLATFORM, lll_geo_000BF8), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_JRB, 2, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xc, LEVEL_JRB, 3, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x32, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_AMP, 12224, -1422, -1069, 0, -1, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, 10568, -1422, -1823, 0, -1, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, 12071, -1422, -2953, 0, -1, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_AMP, 13502, -1422, 900, 0, -1, 0, 0x00000000, bhvCirclingAmp),
		OBJECT(MODEL_LLL_SINKING_ROCK_BLOCK, -6936, -1663, 6311, 0, -30, 0, 0x00000000, bhvLllSinkingRockBlock),
		OBJECT(MODEL_BLUE_COIN, -2736, -1551, 11392, 0, -30, 0, (6 << 16), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2823, -1474, 10209, 0, -30, 0, (6 << 16), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2382, -1474, 12791, 0, -30, 0, (6 << 16), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1315, -1474, 13553, 0, -30, 0, (6 << 16), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 47, -1474, 12661, 0, -30, 0, (6 << 16), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 943, -1474, 12119, 0, -30, 0, (6 << 16), bhvHiddenBlueCoin),
		OBJECT(MODEL_BULLY, 12143, -870, 1937, 0, -22, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BLACK_BOBOMB, -7149, 210, 3077, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9305, 200, 1966, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -6939, -767, 7718, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -2115, -1551, 9183, 0, -30, 0, (6 << 16), bhvBlueCoinSwitch),
		OBJECT(MODEL_BULLY, 8861, -1414, 11530, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 8823, -1487, 11047, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 6391, -1551, 7598, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 2534, -1551, 9888, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 437, -1551, 12668, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -2886, -1551, 10016, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -5761, -556, 4728, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -3167, -1551, 618, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -1410, -1551, -1725, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 5275, -1551, -1557, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -8183, -1551, 5960, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_NONE, 10234, -1244, 11902, 0, -22, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_CHUCKYA, 13850, -870, 2878, 0, 90, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -382, -586, -9409, 0, 0, 0, (0 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -1067, -2426, 7883, 0, -22, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -6953, 210, 3683, 0, -22, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 5998, -500, -5561, 0, -22, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -2694, -1551, 9500, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3162, -1551, 3299, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6440, -556, 4574, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6259, -1471, 9540, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13260, -870, 3329, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -12752, 290, 4927, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1943, -2667, 3245, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4893, -841, -9620, 0, 0, 0, (COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 9273, -1256, 2793, 0, 0, 0, (COIN_FORMATION_FLAG_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10536, -1551, 5351, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_LLL_SINKING_RECTANGULAR_PLATFORM, 7698, -1663, 6492, 0, -45, 0, 0x00000000, bhvLllSinkingRectangularPlatform),
		OBJECT(MODEL_NONE, 6202, -1471, 9514, 0, 0, 0, (COIN_FORMATION_FLAG_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4634, -1469, 7533, 0, 0, 0, (COIN_FORMATION_FLAG_RING << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -13391, -1609, 3570, 0, 0, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 533, -586, -10584, 0, 0, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5894, -500, -6598, 0, 0, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 14576, -1551, 5882, 0, 155, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5178, -329, -3944, 0, -33, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_EXCLAMATION_BOX, 2462, -1186, 12167, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -4183, -1207, 10080, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -12523, -1034, 1881, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1664, -1029, 2170, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 15157, -1211, 4453, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -5314, -3, 3294, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 11655, -962, 12435, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -2818, -1119, 2190, 0, 0, 0, (1 << 16), bhvExclamationBox),
		OBJECT(MODEL_FLYGUY, -2484, -157, -7067, 0, -1, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, -4162, -449, -6403, 0, -1, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, -3035, -924, -5718, 0, -1, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_GOOMBA, -13380, -1599, 3463, 0, 0, 0, (1 << 16), bhvGoomba),
		OBJECT(MODEL_GOOMBA, 3225, -1655, -11207, 0, -22, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_NONE, -3654, -1551, 4123, 0, -22, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1514, -586, -11828, 0, -22, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 1520, -1551, 10833, 0, -22, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 10360, -1551, 5375, 0, -22, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 12912, -870, 2984, 0, -22, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -4459, -1551, 5086, 0, -22, 0, 0x00000000, bhvKoopa),
		MARIO_POS(0x01, 0, 14342, -1230, 3551),
		OBJECT(MODEL_NONE, 11039, -596, 12239, 0, -113, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_PIRANHA_PLANT, -7767, -556, 4831, 0, -22, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -3191, -1551, 3281, 0, -22, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_EXCLAMATION_BOX, 7083, -1188, 12029, 0, -22, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_PIRANHA_PLANT, 6791, -1551, 10191, 0, 0, 0, (1 << 16), bhvFirePiranhaPlant),
		OBJECT(MODEL_YELLOW_COIN, 6791, -1408, 10191, 0, 0, 0, (1 << 16), bhvYellowCoin),
		OBJECT(MODEL_PIRANHA_PLANT, 5795, -1551, 8906, 0, 0, 0, (1 << 16), bhvFirePiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -3938, -1551, 8833, 0, 0, 0, (1 << 16), bhvFirePiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4728, -1551, 7604, 0, 0, 0, (1 << 16), bhvFirePiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, -4622, -1551, 6182, 0, 0, 0, (1 << 16), bhvFirePiranhaPlant),
		OBJECT(MODEL_YELLOW_COIN, 5795, -1408, 8906, 0, 0, 0, (1 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -3938, -1408, 8833, 0, 0, 0, (1 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -4728, -1408, 7604, 0, 0, 0, (1 << 16), bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, -4622, -1408, 6182, 0, 0, 0, (1 << 16), bhvYellowCoin),
		OBJECT(MODEL_BREAKABLE_BOX, -5515, -1536, 8573, 0, 0, 0, (2 << 16), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -5515, -1536, 8374, 0, 0, 0, (2 << 16), bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -5515, -1337, 8374, 0, 0, 0, (2 << 16), bhvBreakableBox),
		OBJECT(MODEL_RED_COIN, 11568, -1299, -2072, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 15488, -1299, 917, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11822, -1299, -424, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12421, -1299, -2185, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12766, -1299, -3492, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12805, -1299, -126, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 14560, -1299, 408, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 14149, -1299, 1493, 0, -1, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_LLL_SINKING_SQUARE_PLATFORMS, 3364, -1663, -1615, 0, 0, 0, 0x00000000, bhvLllSinkingSquarePlatforms),
		OBJECT(MODEL_LLL_SINKING_SQUARE_PLATFORMS, 14969, -1663, 1126, 0, 0, 0, 0x00000000, bhvLllSinkingSquarePlatforms),
		OBJECT(MODEL_LLL_SINKING_SQUARE_PLATFORMS, 12721, -1663, -614, 0, 42, 0, (0x40 << 16), bhvLllSinkingSquarePlatforms),
		OBJECT(MODEL_LLL_SINKING_SQUARE_PLATFORMS, 11924, -1663, -3041, 0, 0, 0, (0x80 << 16), bhvLllSinkingSquarePlatforms),
		OBJECT(MODEL_STAR, -2963, -1082, -4678, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_STAR, -11469, 259, 5730, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_NONE, 9298, -783, 2799, 0, 0, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_LLL_TILTING_SQUARE_PLATFORM, 1944, -2345, -11217, 0, 174, 0, 0x00000000, bhvLllTiltingInvertedPyramid),
		OBJECT(MODEL_LLL_TILTING_SQUARE_PLATFORM, 4238, -1540, -10229, 0, -136, 0, 0x00000000, bhvLllTiltingInvertedPyramid),
		OBJECT(MODEL_LLL_TILTING_SQUARE_PLATFORM, 5443, -923, -8999, 0, -144, 0, 0x00000000, bhvLllTiltingInvertedPyramid),
		OBJECT(MODEL_NONE, -13943, 365, 2555, 0, 0, 0, 0x00000000, bhvWallCtl),
		OBJECT(MODEL_NONE, -1088, -2426, 6090, 0, -69, 0, (0xc << 16), bhvWarp),
		OBJECT(MODEL_THI_WARP_PIPE, -6611, -767, 8139, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_WHOMP, -2004, -586, -9459, 0, -1, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, -44, -586, -11904, 0, -178, 0, 0x00000000, bhvSmallWhomp),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, jrb_area_2),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0xb, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x32, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_THI_WARP_PIPE, 1286, 1834, -1337, 0, 0, 0, (0xa << 16), bhvWarpPipe),
		OBJECT(MODEL_TRANSPARENT_STAR, 3012, 1600, -1304, 0, 0, 0, (0xa << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRANSPARENT_STAR, 468, 1600, -4298, 0, 0, 0, (0xa << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRANSPARENT_STAR, -3702, 1600, 2903, 0, 0, 0, (0xa << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRANSPARENT_STAR, 885, 1600, 1662, 0, 0, 0, (0xa << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_TRANSPARENT_STAR, -2587, 1600, 1476, 0, 0, 0, (0xa << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 1086, 2011, -1319, 0, 0, 0, (4 << 24), bhvHiddenStar),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, jrb_area_3),
		WARP_NODE(0x0A, LEVEL_JRB, 0x01, 0xc, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x32, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CANNON_BASE, 3529, -205, -7322, 0, 0, 0, 0x00000000, bhvCannon),
		OBJECT(MODEL_STAR, 3636, -125, -4989, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_NONE, 3562, -205, -8282, 0, 0, 0, (0xa << 16), bhvWarp),
		TERRAIN(jrb_area_3_collision),
		MACRO_OBJECTS(jrb_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x26),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 14342, -1230, 3551),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
