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


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bdf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bdf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _bdf_segment_7SegmentRomStart, _bdf_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BDF_P1, bdf_p1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BDF_P2, bdf_p2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BDF_P3, bdf_p3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BDF_PUSHER, bdf_pusher_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bdf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x60, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x70, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf3, LEVEL_BDF, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x40, LEVEL_BOWSER_2, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 2184, 383, -103),
		OBJECT(MODEL_NONE, 1275, 648, -93, 0, -90, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 4999, 1071, -7249, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3966, 752, -9185, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2766, 764, -7256, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7860, 2530, -8915, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7034, 1397, -8691, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 460, 3071, -68, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_CHAIN_CHOMP, 15, 296, -2338, 0, 0, 0, (17 << 16), bhvChainChomp),
		OBJECT(MODEL_NONE, 1209, 383, -10, 0, 0, 0, 0x00000000, bhvBowserCourseWarpCtl),
		OBJECT(MODEL_WOODEN_SIGNPOST, -663, 383, -74, 0, 90, 0, (90 << 24) | (90 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 6398, 326, -8098, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 4924, 1071, -7302, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_BULLET_BILL, 7829, 2618, -8080, 0, -180, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_BULLET_BILL, 5942, 2623, -9912, 0, -90, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_RED_COIN, 1903, 3424, -9894, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BULLET_BILL, 4735, 2577, -8706, 0, 90, 0, 0x00000000, bhvBulletBill),
		OBJECT(MODEL_HEAVE_HO, 6411, 347, -6999, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 278, 2719, 517, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_BDF_P1, 3802, 2468, -7233, 0, 0, 0, (1 << 16), bhvBowserPieces),
		OBJECT(MODEL_BDF_P3, 5827, -1920, 9498, 0, 0, 0, (3 << 16), bhvBowserPieces),
		OBJECT(MODEL_BDF_P2, -8429, 1755, -15, 0, 0, 0, (2 << 16), bhvBowserPieces),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -11015, 296, 559, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -11763, 296, -840, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -10561, 296, -2017, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KLEPTO, -9297, 1898, -15, 0, 0, 0, 0x00000000, bhvKlepto),
		OBJECT(MODEL_NONE, 2191, 763, -109, 0, -89, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_BDF_PUSHER, -967, 1603, -40, 0, 0, 0, 0x00000000, bhvBowserMetalBoxPush),
		OBJECT(MODEL_RED_COIN, 4953, 367, -7243, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -11351, 1602, 1201, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3946, -2024, 7686, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4735, 183, 6188, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BOWLING_BALL, 3723, 2535, -9943, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_RED_COIN, -9331, 282, -2085, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 388, 2153, 604, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1312, 1079, -587, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -302, 2922, -490, 0, 0, 0, 0x00000000, bhvBowserCourseRedCoinStar),
		OBJECT(MODEL_NONE, -59, 4970, -74, 0, 0, 0, (0x20 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -53, 4978, -109, 0, 0, 0, (0x30 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -320, 4622, -83, 0, 0, 0, (0x40 << 16), bhvFadingWarp),
		OBJECT(MODEL_YELLOW_COIN, 5679, 454, 6349, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 6581, 454, 9608, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_YELLOW_COIN, 4780, 454, 10499, 0, 0, 0, 0x00000000, bhvYellowCoin),
		OBJECT(MODEL_NONE, -318, 4622, -80, 0, 0, 0, 0x00000000, bhvSparkler),
		TERRAIN(bdf_area_1_collision),
		MACRO_OBJECTS(bdf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_BOWSER),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 2184, 383, -103),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
