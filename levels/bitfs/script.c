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
#include "levels/bitfs/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitfs_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bitfs_skybox_mio0SegmentRomStart, _bitfs_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bitfs_geo_0004B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, bitfs_geo_0004C8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, bitfs_geo_0004E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, bitfs_geo_0004F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, bitfs_geo_000510), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, bitfs_geo_000528), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, bitfs_geo_000540), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, bitfs_geo_000558), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, bitfs_geo_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, bitfs_geo_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, bitfs_geo_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, bitfs_geo_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, bitfs_geo_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, bitfs_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, bitfs_geo_000600), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, bitfs_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13, bitfs_geo_000630), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14, bitfs_geo_000648), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_15, bitfs_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_PLATFORM_ON_TRACK, bitfs_geo_000758), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TILTING_SQUARE_PLATFORM, bitfs_geo_0006C0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SINKING_PLATFORMS, bitfs_geo_000770), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_BLUE_POLE, bitfs_geo_0006A8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SINKING_CAGE_PLATFORM, bitfs_geo_000690), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_ELEVATOR, bitfs_geo_000678), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_STRETCHING_PLATFORMS, bitfs_geo_000708), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SEESAW_PLATFORM, bitfs_geo_000788), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_MOVING_SQUARE_PLATFORM, bitfs_geo_000728), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SLIDING_PLATFORM, bitfs_geo_000740), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TUMBLING_PLATFORM_PART, bitfs_geo_0006D8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TUMBLING_PLATFORM, bitfs_geo_0006F0), 
	LOAD_MODEL_FROM_GEO(22, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitfs_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BITFS, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOWSER_2, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 112, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITFS, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BITFS, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BITFS, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BITFS, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, -113, 7903, 49, 0, -151, 0, 0x0, bhv1Up),
		OBJECT(212, -3165, -600, 88, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(122, -122, -3281, -2970, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -6041, -2402, -142, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(0, 9724, -2820, 32, 0, 90, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(0, 196, 4265, -300, 0, 0, 0, 0x0, bhvBowserCourseRedCoinStar),
		OBJECT(84, -70, -2500, 3285, 0, -180, 0, 0x0, bhvBulletBill),
		OBJECT(84, -645, -2500, 3285, 0, -180, 0, 0x0, bhvBulletBill),
		OBJECT(84, 500, -2500, 3285, 0, -180, 0, 0x0, bhvBulletBill),
		OBJECT(84, 3090, 880, -470, 0, -90, 0, 0x0, bhvBulletBill),
		OBJECT(84, 3090, 880, 100, 0, -90, 0, 0x0, bhvBulletBill),
		OBJECT(84, 3090, 880, 675, 0, -90, 0, 0x0, bhvBulletBill),
		OBJECT(0, -475, 3893, 95, 0, 90, 0, 0x10000, bhvDeathWarp),
		OBJECT(137, 715, -6302, -2605, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(0, -1690, 1185, 2590, 0, 135, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -2583, 1185, 1715, 0, 135, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -2135, 1185, 2146, 0, 135, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 470, 2864, 95, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(207, -2655, -2650, -1089, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, -4962, -2708, 43, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(89, 1462, 729, 2227, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(129, -1980, -2031, -1905, 0, 45, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2235, -2448, -1633, 0, 45, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -1746, -1667, -2171, 0, 45, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2330, -2847, -55, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2130, -2847, -55, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(217, 1955, -6930, 1300, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, 675, -6930, 41, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, 675, -6598, 50, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5622, -2672, 79, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1960, -6598, 1304, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1366, -208, -2262, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 9713, -3337, -549, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 480, 3021, 68, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 608, 3906, 98, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2130, -2608, -55, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 9724, -3337, 32, 0, -90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 12567, -3130, 32, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(88, 1366, -209, -2262, 0, -45, 0, 0x0, bhvThwomp),
		OBJECT(88, -2799, 1093, 1008, 0, 90, 0, 0x0, bhvThwomp),
		OBJECT(22, 2554, -3340, -614, 0, 0, 0, 0xc0000, bhvWarpPipe),
		OBJECT(22, 2537, -6570, -688, 0, -180, 0, 0xb0000, bhvWarpPipe),
		OBJECT(22, 196, 3890, 95, 0, 0, 0, 0x0, bhvWarpPipe),
		TERRAIN(bitfs_area_1_collision),
		MACRO_OBJECTS(bitfs_area_1_macro_objs),
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
