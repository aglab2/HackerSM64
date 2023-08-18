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
#include "levels/ssl/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ssl_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ssl_skybox_yay0SegmentRomStart, _ssl_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ssl_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ssl_geo_0005D8), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_TOP, ssl_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_GRINDEL, ssl_geo_000734), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_SPINDEL, ssl_geo_000764), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_MOVING_PYRAMID_WALL, ssl_geo_000794), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_ELEVATOR, ssl_geo_0007AC), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_TOX_BOX, ssl_geo_000630), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ssl_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_SA, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 114, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 1, 98, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_SSL, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_SSL, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_SSL, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_SSL, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_SSL, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(0, -2185, -3390, 4450, 0, 0, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(140, 653, -7000, 393, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(188, 4468, 324, -900, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(129, 1500, -7010, 380, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 1500, -7010, 180, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 1500, -7010, 580, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 1500, -6810, 380, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 1300, -7010, 380, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 1500, -6810, 180, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(223, 4301, 2101, -3653, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(194, 3600, -3897, 817, 0, 0, 0, 0x0, bhvCirclingAmp),
		OBJECT(0, -4290, 2340, 3750, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4177, 324, 1418, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4227, 324, 2921, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4227, 388, 692, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 970, -4375, 400, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -2200, -4006, 3600, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -2185, -3390, 4450, 0, 0, 0, 0x60000, bhvDeathWarp),
		OBJECT_WITH_ACTS(137, -770, 670, -4377, 0, 0, 0, 0x0, bhvExclamationBox, ACT_5),
		OBJECT(0, -2180, -3708, 5244, 0, 0, 0, 0x0, bhvFadingWarp),
		OBJECT_WITH_ACTS(207, -4758, 324, -3539, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects, ACT_6),
		OBJECT(207, -2400, -4990, 400, 0, 90, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(220, -3164, 886, -4836, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, -3782, 2533, 3781, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(0, -3211, 324, 1411, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1433, 324, 3122, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -4773, -4377, 400, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -2194, -4345, -1952, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -2198, -4345, 2785, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, 1325, -6965, -346, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 1325, -6965, 1100, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 100, -6965, 1100, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 100, -6965, -326, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT_WITH_ACTS(129, -5178, 205, -6833, 0, 0, 0, 0x0, bhvHiddenObject, ACT_6),
		OBJECT_WITH_ACTS(129, -5378, 205, -6833, 0, 0, 0, 0x0, bhvHiddenObject, ACT_6),
		OBJECT_WITH_ACTS(129, -5178, 205, -6633, 0, 0, 0, 0x0, bhvHiddenObject, ACT_6),
		OBJECT_WITH_ACTS(129, -5378, 205, -6633, 0, 0, 0, 0x0, bhvHiddenObject, ACT_6),
		OBJECT(129, -3620, -5060, 400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -3820, -4860, 400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -4020, -4660, 400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -3420, -5060, 400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, 5432, 1286, 5323, 0, 0, 0, 0x3000000, bhvHiddenRedCoinStar),
		OBJECT_WITH_ACTS(124, -4161, 324, -2587, 0, -180, 0, 0x1e0000, bhvMessagePanel, ACT_1),
		OBJECT(116, -1219, -7807, 830, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, -661, -7418, 150, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(0, -2294, 324, 2006, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 4363, 324, -135, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -825, 289, -3185, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 1943, 324, 3928, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -271, 324, 3647, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 4253, 324, 818, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, 249, 289, -2572, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(215, 777, 121, -4241, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4489, 1430, 4603, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4695, -4355, 2926, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5471, 324, -1196, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3602, 324, 3556, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2200, -3758, -5227, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 970, -4375, 1901, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4554, 283, -4188, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -4177, 324, -3735, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -2920, 4183, 4335, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, -2128, -1760, 400, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 4830, 3545, -4501, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT_WITH_ACTS(122, -5640, 876, -7561, 0, 0, 0, 0x5000000, bhvStar, ACT_1 | ACT_2 | ACT_3 | ACT_4 | ACT_6),
		OBJECT(122, 103, 3098, -191, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(0, 0, 0, 0, 0, -90, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(27, 5, 289, -4403, 0, 0, 0, 0x0, bhvTree),
		OBJECT(27, 1574, 281, -3333, 0, 0, 0, 0x0, bhvTree),
		OBJECT(27, 1049, 324, 4347, 0, 0, 0, 0x0, bhvTree),
		OBJECT(27, -4776, 324, -3138, 0, 0, 0, 0x0, bhvTree),
		OBJECT(22, -4227, 324, 4053, 0, -180, 0, 0xb0000, bhvWarpPipe),
		OBJECT(22, -5877, -4400, 400, 0, 90, 0, 0xc0000, bhvWarpPipe),
		OBJECT(22, -2110, -8205, 470, 0, 90, 0, 0xe0000, bhvWarpPipe),
		OBJECT(22, -2025, -4990, 400, 0, -90, 0, 0xd0000, bhvWarpPipe),
		OBJECT(107, 1712, 289, -5053, 0, 0, 0, 0x0, bhvWoodenPost),
		TERRAIN(ssl_area_1_collision),
		MACRO_OBJECTS(ssl_area_1_macro_objs),
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
