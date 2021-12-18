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
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_OCTAGONAL_PLATFORM, rr_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_ROTATING_BRIDGE_PLATFORM, rr_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_SL_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree2_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 3, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 3, 0x22, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -12686, 6235, 4175, 0, 0, 0, (0 << 16), bhvBobBowlingBallSpawner),
		OBJECT(MODEL_NONE, -7119, 7615, -943, 0, 0, 0, (1 << 16), bhvBobBowlingBallSpawner),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 862, 2946, 2236, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_BLACK_BOBOMB, -7586, 4690, 1211, 0, -21, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -1732, 4690, -20, 0, -21, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 9758, 3481, 3606, 0, -21, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 9904, 3235, 643, 0, -21, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 9998, 3831, 6458, 0, -21, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 1497, 1883, 4164, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 7602, 3589, 1065, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 6805, 2915, -1620, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1454, 4592, 191, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -3208, 2752, -4765, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -5518, 2752, -10137, 0, -21, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_BLACK_BOBOMB, -9996, 5817, 5215, 0, -21, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHAIN_CHOMP, 1550, 3312, 66, 0, -21, 0, (COIN_FORMATION_FLAG_ARROW << 16), bhvChainChomp),
		OBJECT(MODEL_CHUCKYA, 1828, 1006, 48, 0, 0, 0, (5 << 16), bhvChuckya),
		OBJECT(MODEL_NONE, -1115, 747, 10187, 0, 0, 0, (COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2064, 747, 10661, 0, 0, 0, (COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2631, 499, 255, 0, 0, 0, (COIN_FORMATION_FLAG_FLYING | COIN_FORMATION_FLAG_VERTICAL << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3279, 57, 436, 0, -108, 0, (COIN_FORMATION_FLAG_ARROW << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -12304, 6586, -870, 0, 14, 0, (COIN_FORMATION_FLAG_ARROW << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7726, 1883, 5983, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 7360, 4044, 3439, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 2079, 1883, 4546, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		MARIO_POS(0x01, 0, 10358, 2530, 7813),
		OBJECT(MODEL_NONE, 10362, 2530, 7828, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, 1788, 1527, 30, 0, 0, 0, (1 << 16), bhvExclamationBox),
		OBJECT(MODEL_PURPLE_SWITCH, -5552, 536, -9493, 0, -30, 0, (0 << 16), bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_RR_ROTATING_BRIDGE_PLATFORM, 206, 2510, -2535, 0, -21, 0, 0x00000000, bhvRrRotatingBridgePlatform),
		OBJECT(MODEL_RR_OCTAGONAL_PLATFORM, -1639, 2752, -4018, 90, -15, 0, (1 << 16), bhvOctagonalPlatformRotating),
		OBJECT(MODEL_RR_OCTAGONAL_PLATFORM, -4673, 2752, -5670, 90, -46, 0, (1 << 16), bhvOctagonalPlatformRotating),
		OBJECT(MODEL_RR_OCTAGONAL_PLATFORM, -3145, 2752, -11172, 90, -86, 0, (1 << 16), bhvOctagonalPlatformRotating),
		OBJECT(MODEL_RR_OCTAGONAL_PLATFORM, -508, 2752, -9657, 90, -148, 0, (1 << 16), bhvOctagonalPlatformRotating),
		OBJECT(MODEL_STAR, -5282, 1520, 10393, 0, 0, 0, (0 << 16), bhvStar),
		OBJECT(MODEL_STAR, -12398, 9825, 3848, 0, 0, 0, (1 << 16), bhvStar),
		OBJECT(MODEL_STAR, 2233, 3501, -8347, 0, 0, 0, (2 << 16), bhvStar),
		OBJECT(MODEL_STAR, 9360, 3291, -11264, 0, 0, 0, (3 << 16), bhvStar),
		OBJECT(MODEL_STAR, 8759, 464, 2481, 0, 0, 0, (4 << 16), bhvStar),
		OBJECT(MODEL_STAR, 4959, 6681, 6096, 0, 0, 0, (5 << 16), bhvStar),
		OBJECT(MODEL_SL_SNOW_TREE, 8230, 1883, 7397, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 6730, 1883, 7291, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 7068, 1883, 6269, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 8974, 1883, 5345, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 8761, 1883, 4874, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 7637, 1883, 5039, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 6668, 1883, 5084, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 9177, 1883, 2304, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 9169, 1883, 632, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 8174, 1883, 1647, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 7135, 2915, -874, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 5974, 2915, -2015, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 6363, 2915, -3095, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 9315, 2749, -11637, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 8138, 336, -8501, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 8722, 336, -9150, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 8631, 336, -7872, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 9195, 336, -8654, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 4915, 4542, 6025, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 5795, 4542, 7480, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 7625, 4542, 8045, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 2086, 1883, 5230, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, 2658, 1883, 4400, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_WHOMP, -12068, 6144, 5063, 0, 92, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, -9430, 7508, -1616, 0, -90, 0, 0x00000000, bhvSmallWhomp),
		OBJECT(MODEL_WHOMP, -7611, 4690, 3620, 0, 178, 0, 0x00000000, bhvSmallWhomp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 10358, 2530, 7813),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
