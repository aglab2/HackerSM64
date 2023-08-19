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
#include "levels/bitdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, geo_bitdw_0003C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, geo_bitdw_0003D8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, geo_bitdw_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, geo_bitdw_000408), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, geo_bitdw_000420), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, geo_bitdw_000438), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, geo_bitdw_000450), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, geo_bitdw_000468), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, geo_bitdw_000480), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, geo_bitdw_000498), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, geo_bitdw_0004B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, geo_bitdw_0004C8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, geo_bitdw_0004E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, geo_bitdw_0004F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, geo_bitdw_000510), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SQUARE_PLATFORM, geo_bitdw_000558), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SEESAW_PLATFORM, geo_bitdw_000540), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_SLIDING_PLATFORM, geo_bitdw_000528), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_FERRIS_WHEEL_AXLE, geo_bitdw_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_BLUE_PLATFORM, geo_bitdw_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME4, geo_bitdw_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME3, geo_bitdw_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME2, geo_bitdw_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE_FRAME1, geo_bitdw_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_STAIRCASE, geo_bitdw_000600), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitdw_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BITDW, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOWSER_1, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 101, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITDW, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BITDW, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BITDW, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, 6549, -3620, -1346, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -893, 5043, 1150, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(122, 5818, -1927, -6355, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, 1170, -3800, 4700, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(0, 6497, -5836, -6636, 0, -180, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(0, -170, 5274, 25, 0, 0, 0, 0x0, bhvBowserCourseRedCoinStar),
		OBJECT(129, 5990, -4185, 4910, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 5790, -3985, 4810, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 5790, -4185, 4810, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 5790, -3985, 5010, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 5790, -4185, 5010, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 5790, -4185, 3365, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 5990, -4185, 3365, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, -5755, -433, -1790, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, -5955, -433, -1790, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, -5755, -233, -1790, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(84, 1155, -4150, 5364, 0, 0, 0, 0x0, bhvBulletBill),
		OBJECT(84, 1800, -4150, 5364, 0, 0, 0, 0x0, bhvBulletBill),
		OBJECT(84, 2450, -4150, 5364, 0, 0, 0, 0x0, bhvBulletBill),
		OBJECT(84, -6500, -310, -2274, 0, 0, 0, 0x0, bhvBulletBill),
		OBJECT(84, -6500, 30, -2585, 0, 0, 0, 0x0, bhvBulletBill),
		OBJECT(84, -6500, 330, -2883, 0, 0, 0, 0x0, bhvBulletBill),
		OBJECT(0, -313, -4001, 5619, 0, 90, 0, 0x0, bhvCheckerboardElevatorGroup),
		OBJECT(0, -900, -3236, 5619, 0, 90, 0, 0x0, bhvCheckerboardElevatorGroup),
		OBJECT(194, -5202, -913, 5803, 0, 0, 0, 0x0, bhvCirclingAmp),
		OBJECT(194, -6514, 1228, -4448, 0, 0, 0, 0x0, bhvCirclingAmp),
		OBJECT(0, 6541, -4546, 2475, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 1576, -4249, 6774, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -6473, -743, 2641, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -6224, 1176, -5587, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -903, 4575, -2665, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -884, 4962, -993, 0, 0, 0, 0x10000, bhvDeathWarp),
		OBJECT(137, -1717, -2012, 5970, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 6957, -3861, 4292, 0, 0, 0, 0x40000, bhvExclamationBox),
		OBJECT(0, -380, 3813, -6362, 0, -90, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, 5818, -2328, -6855, 0, 0, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, -6215, -350, -105, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -6215, -350, 385, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -6215, -350, 870, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(207, -5796, -433, -1010, 0, -90, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 6518, -4185, 4323, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(89, -5066, 1176, -6402, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(129, -6535, -633, 505, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -6335, -633, 505, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(124, 6322, -4787, -1463, 0, 135, 0, 0x340000, bhvMessagePanel),
		OBJECT(217, 5818, -2688, -6855, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, 6507, -4481, -4440, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6549, -4185, -1033, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2833, -3485, 5468, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5790, -4185, 3365, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -6340, 60, 4300, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -6335, -413, 505, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3960, 2926, -6341, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -901, 5026, 761, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 6497, -5836, -6636, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(88, -6340, -965, 4300, 0, 0, 0, 0x0, bhvThwomp),
		OBJECT(88, -6680, -965, 4300, 0, 0, 0, 0x0, bhvThwomp),
		OBJECT(0, -895, 4754, -160, 0, 0, 0, 0x0, bhvWarp),
		TERRAIN(bitdw_area_1_collision),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 17),
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
