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
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bits_geo_000430), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, bits_geo_000448), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, bits_geo_000460), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, bits_geo_000478), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, bits_geo_000490), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, bits_geo_0004A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, bits_geo_0004C0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, bits_geo_0004D8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, bits_geo_0004F0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, bits_geo_000508), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, bits_geo_000520), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, bits_geo_000538), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, bits_geo_000550), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, bits_geo_000568), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, bits_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, bits_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13, bits_geo_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14, bits_geo_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SLIDING_PLATFORM, bits_geo_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TWIN_SLIDING_PLATFORMS, bits_geo_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_OCTAGONAL_PLATFORM, bits_geo_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_BLUE_PLATFORM, bits_geo_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_FERRIS_WHEEL_AXLE, bits_geo_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_ARROW_PLATFORM, bits_geo_000658), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SEESAW_PLATFORM, bits_geo_000670), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_TILTING_W_PLATFORM, bits_geo_000688), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE, bits_geo_0006A0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME1, bits_geo_0006B8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME2, bits_geo_0006D0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME3, bits_geo_0006E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_STAIRCASE_FRAME4, bits_geo_000700), 
	LOAD_MODEL_FROM_GEO(22, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BITS, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE, 1, 117, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITS, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BITS, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BITS, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BITS, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BITS, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BITS, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, 3914, -2066, 9929, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 1038, 698, 2101, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(122, -8900, 3293, -12100, 0, 90, 0, 0x2000000, bhvStar),
		OBJECT(122, 8737, 3803, -2335, 0, 90, 0, 0x1000000, bhvStar),
		OBJECT(122, 6697, -525, 7515, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(0, 9139, -4230, 8852, 0, 0, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT(188, 8096, -4638, 6905, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(188, 9601, -4638, 7093, 0, 0, 0, 0x0, bhvBobomb),
		OBJECT(195, 8144, -872, 3906, 0, 0, 0, 0x0, bhvBobombBuddyOpensCannon),
		OBJECT(0, -1107, 7558, 2387, 0, -180, 0, 0x0, bhvBowserCourseRedCoinStar),
		OBJECT(129, 0, -2100, 3822, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, -200, -2100, 3822, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, -400, -2100, 3822, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, -200, -1900, 3822, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(130, -1154, -2100, 1908, 0, 0, 0, 0x0, bhvBreakableBoxSmall),
		OBJECT(201, 4810, -4970, 3540, 0, 90, 0, 0x640000, bhvCannonClosed),
		OBJECT(223, 6007, -2097, 2457, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, -7200, 7389, 610, 0, -90, 0, 0x10000, bhvDeathWarp),
		OBJECT(180, -1107, 7233, 1225, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(207, 5944, -2100, -4070, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 548, -2100, 1385, 0, 90, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -2884, -2100, 1837, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -1929, -2100, -1229, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 8818, -4638, 5611, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(89, -9751, -395, -5109, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 1693, -2181, -10596, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(129, 3650, -2100, -4000, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3650, -2100, -5200, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3650, -2100, -6400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3650, -2100, -7600, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3650, -2100, -8800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3650, -2100, -10000, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(124, -487, 7233, 620, 0, 90, 0, 0x510000, bhvMessagePanel),
		OBJECT(0, 5300, -63, 220, 0, -90, 0, 0xe80000, bhvPoleGrabbing),
		OBJECT(0, 2930, -2287, -8860, 0, 0, 0, 0xff0000, bhvPoleGrabbing),
		OBJECT(0, 2880, 117, -6780, 0, 0, 0, 0xff0000, bhvPoleGrabbing),
		OBJECT(0, 2930, -677, -8860, 0, 0, 0, 0xc80000, bhvPoleGrabbing),
		OBJECT(215, 9139, -4988, 8852, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1168, -2033, -558, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3343, -4955, 2490, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -8800, -1625, -3070, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 974, -1604, -11447, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 75, 3446, -2600, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -13593, 1136, -11315, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 901, 7233, 625, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -1530, 7297, 620, 0, -90, 0, 0x4e0000, bhvSignOnWall),
		OBJECT(0, -2080, -2044, 620, 0, -90, 0, 0x4d0000, bhvSignOnWall),
		OBJECT(103, -12769, 1136, -11315, 0, 90, 0, 0x0, bhvSmallWhomp),
		OBJECT(0, 9139, -4638, 8852, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(22, -8050, -969, -2617, 0, -180, 0, 0xc0000, bhvWarpPipe),
		OBJECT(22, -1210, 1199, 13689, 0, -180, 0, 0xb0000, bhvWarpPipe),
		OBJECT(22, -7900, 7233, 610, 0, 0, 0, 0x0, bhvWarpPipe),
		OBJECT(22, 115, 2851, 1175, 0, -180, 0, 0xe0000, bhvWarpPipe),
		OBJECT(22, -1107, 7233, -721, 0, 0, 0, 0xd0000, bhvWarpPipe),
		OBJECT(116, -9228, 975, -8446, 0, 0, 0, 0x0, bhvYellowCoin),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 46),
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
