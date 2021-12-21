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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x41, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x42, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, 570, 661, 5463, 0, 0, 0, (2 << 16), bhvBobomb),
		OBJECT(MODEL_BREAKABLE_BOX, 5730, -337, -1042, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, 5730, -337, -1168, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_CHUCKYA, 2841, 718, 5241, 0, 0, 0, (2 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 2551, -4, 1775, 0, 0, 0, (2 << 16), bhvChuckya),
		OBJECT(MODEL_NONE, 2972, 1103, 4474, 0, -90, 0, (0 << 16), bhvCoinFormation),
		OBJECT(MODEL_BOWLING_BALL, 1191, 444, 4313, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 2325, 572, 4484, 0, 0, 0, (0 << 16), bhvFireSpitter),
		OBJECT(MODEL_NONE, 2860, -4, 1626, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 4206, -480, -1383, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2356, 1643, 7, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -972, 571, -3794, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6138, 525, -3921, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5917, 700, -2471, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7227, 613, -5584, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2392, -207, -485, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1087, -409, -2564, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -5904, 1520, -2844, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_SKEETER, 2745, -4, 1625, 0, 0, 0, (2 << 16), bhvSkeeter),
		OBJECT(MODEL_HEAVE_HO, -4982, 525, -3905, 0, 0, 0, (0 << 16), bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 3197, -4, 1788, 0, 0, 0, (0 << 16), bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -2945, -480, -574, 0, 0, 0, (0 << 16), bhvHeaveHo),
		MARIO_POS(0x01, -180, -1092, 6095, 7707),
		OBJECT(MODEL_NONE, -1084, 6294, 7685, 0, -180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_PURPLE_SWITCH, 6058, -1270, -1323, 0, 0, 0, (5 << 24), bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_NONE, 652, 768, 5626, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 629, 841, 4089, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 2506, 172, 4522, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 2764, 825, 5256, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 3631, 973, 4496, 0, 0, 0, (2 << 16), bhvHiddenStarTrigger),
		OBJECT(MODEL_SKEETER, -779, 571, -3842, 0, 0, 0, (2 << 16), bhvSkeeter),
		OBJECT(MODEL_SKEETER, 4248, -480, -1330, 0, 0, 0, (2 << 16), bhvSkeeter),
		OBJECT(MODEL_STAR, -2367, 2033, -17, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -2053, 830, -3781, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, -7252, 2164, -6029, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR, 6386, 300, -1118, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_STAR, 2245, 245, 3093, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_STAR, -1086, 2970, 1235, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_CAP_SWITCH, -5881, 1832, -2173, 0, 0, 0, (0 << 16), bhvCapSwitch),
		OBJECT(MODEL_NONE, -2919, -480, -956, 0, -90, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1092, 6095, 7630, 0, 0, 0, 0x00000000, bhvAirborneWarp),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, -4667, -1206, -940, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, -5917, 1344, -2471, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_NONE, -987, 571, -4012, 0, 0, 0, 0x00000000, bhvInitializeChangingWaterLevel),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x25),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, -1092, 6095, 7707),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
