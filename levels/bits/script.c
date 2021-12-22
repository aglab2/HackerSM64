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
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_HIDDEN_PLATFORM, wdw_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_SLIDING_PLATFORM, bits_geo_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES, rr_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME1, rr_geo_000970), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME2, rr_geo_000988), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME3, rr_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_RR_TRICKY_TRIANGLES_FRAME4, rr_geo_0009B8), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_COURTYARD, 0x01, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_COURTYARD, 0x01, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_BOWSER_3, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1292, -1531, 9623, 30, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1450, -1367, 9268, 30, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1285, -1208, 8905, 30, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1003, -1059, 8596, 0, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1002, -1018, 6928, 0, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1180, -1108, 6568, -19, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1320, -1226, 6205, -19, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_WDW_HIDDEN_PLATFORM, 1537, -1342, 5843, -19, 0, 0, (1 << 16), bhvHiddenObject),
		OBJECT(MODEL_NONE, 1293, -2995, 14236, 0, -180, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 760, -927, 7796, 0, -180, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -95, 5632, -13182, 0, 0, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_HEAVE_HO, -803, 2774, -6566, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 570, 2088, -6454, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -724, 1482, -6329, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -866, 827, -6483, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -483, 213, -6464, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -71, -452, -3673, 0, 0, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_NONE, 1273, -2995, 15373, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		MARIO_POS(0x01, 0, 23, 4145, -14248),
		OBJECT(MODEL_BITS_WARP_PIPE, -119, 5632, -12639, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_PURPLE_SWITCH, 1279, -1601, 10170, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_RED_COIN, 3557, 170, 298, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -21, -68, -2616, 0, 0, 0, 0x00000000, bhvBowserCourseRedCoinStar),
		OBJECT(MODEL_RED_COIN, 1019, 613, -1195, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3190, 840, -1588, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -335, 816, 834, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1744, 840, 846, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2558, -167, 2180, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -869, 170, -98, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 175, 230, -460, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BITS_SLIDING_PLATFORM, -120, 5241, -13300, 0, -90, 0, 0x00000000, bhvSlidingPlatform2),
		OBJECT(MODEL_RR_TRICKY_TRIANGLES, 10, 2886, -10887, 0, -90, 0, (2 << 16), bhvAnimatesOnFloorSwitchPress),
		OBJECT(MODEL_PURPLE_SWITCH, -32, 2774, -9423, 0, -180, 0, 0x00000000, bhvFloorSwitchAnimatesObject),
		OBJECT(MODEL_WHOMP, -41, -452, -4822, 0, 0, 0, 0x00000000, bhvSmallWhomp),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_B3),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 23, 4145, -14248),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
