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
#include "levels/totwc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_totwc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, totwc_geo_000160), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RED_COIN_RADAR, redcoinradar_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, totwc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x61, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x62, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_AMP, 2233, 1976, 328, 0, 0, 0, (2 << 16), bhvHomingAmp),
		OBJECT(MODEL_RED_COIN_RADAR, 4441, -994, 12133, 0, 0, 0, (2 << 16), bhvRedCoinRadar),
		OBJECT(MODEL_BLACK_BOBOMB, 4729, 4809, -3319, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 5563, 1892, 3424, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 6884, 4688, -2467, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BOWLING_BALL, -4709, -18, 8796, 0, -39, 0, 0x00000000, bhvFireSpitter),
		OBJECT_WITH_ACTS(MODEL_EXCLAMATION_BOX, 1591, 5878, -9869, 0, 0, 0, 0x00000000, bhvExclamationBox, 0),
		OBJECT(MODEL_CAP_SWITCH, 1546, 5494, -9103, 0, 0, 0, 0x00000000, bhvCapSwitch),
		OBJECT(MODEL_CHUCKYA, -1873, -137, 8282, 0, 0, 0, (2 << 16), bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 2441, 4903, 566, 0, 0, 0, (2 << 16), bhvChuckya),
		OBJECT(MODEL_NONE, -1321, 50, 6775, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8, 481, 7284, 0, -39, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1535, 5080, -4334, 0, 0, 0, (2 << 16), bhvCoinFormationSpawn),
		OBJECT(MODEL_NONE, 5189, 1892, 4373, 0, 0, 0, (2 << 16), bhvCoinFormationSpawn),
		OBJECT(MODEL_NONE, -748, -137, 9112, 0, 0, 0, (2 << 16), bhvCoinFormationSpawn),
		OBJECT(MODEL_FLYGUY, 5896, 3326, 1429, 0, -39, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4974, 3983, 2594, 0, -39, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_NONE, 392, -994, 10842, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 4490, 1892, 5057, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 3429, 4211, 2041, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1573, 5080, -4368, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_WOODEN_SIGNPOST, 1227, -994, 11752, 0, 85, 0, (42 << 16), bhvMessagePanel),
		OBJECT(MODEL_PIRANHA_PLANT, 4841, 1892, 2822, 0, -39, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 2900, 1892, 6277, 0, -39, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 5114, 4688, -2504, 0, -39, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 3249, 4211, 2690, 0, -39, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_HEAVE_HO, 1465, -137, 10113, 0, -39, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, 2204, 1892, -3339, 0, -39, 0, 0x00000000, bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -2848, -137, 8882, 0, -39, 0, 0x00000000, bhvHeaveHo),
		MARIO_POS(0x01, -2, 6147, 1892, -218),
		OBJECT(MODEL_NONE, 4447, -994, 12143, 0, -94, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_NONE, 2332, -137, 10061, 0, -2, 0, 0x00000000, bhvRainbowCtl),
		OBJECT(MODEL_RED_COIN, -6816, -17, 8745, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2265, 2013, 290, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1486, 2013, -3108, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1588, 4809, -1414, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7588, 5162, -2518, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1538, 5201, -6531, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2308, 3310, 813, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5823, 1977, -4146, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -747, 343, 9121, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_SSL_PALM_TREE, -879, 5080, -3849, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -2428, 5080, -4024, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -1886, 5080, -4570, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -905, 5080, -4762, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3048, 4688, -2983, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2565, 4688, -2417, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2392, 4688, -1302, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3424, 4688, 258, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4560, 4688, -126, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 5546, 4688, -1183, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4857, 4688, 647, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4828, 4688, 1494, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 6691, 4688, -3351, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 8512, 4688, -2721, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 7377, 4688, -1662, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 6533, 1892, -1112, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 6386, 1892, 2377, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 6207, 1892, 4113, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4467, 1892, 3816, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 5243, 1892, 5636, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3587, 1892, 5449, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2475, 1892, 6059, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3674, 1892, 6635, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -6885, -137, 8318, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -6268, -137, 9318, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -2446, -137, 8211, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -2096, -137, 7757, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -1135, -137, 7721, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -2764, -137, 9740, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -317, -137, 8476, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1785, -137, 9871, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1762, -137, 10347, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1210, -137, 10215, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -337, -137, 10747, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 93, -994, 10840, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 911, -994, 11493, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1560, -994, 11570, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 766, -994, 12055, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -515, -137, 9597, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -328, -137, 9106, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -847, -137, 8776, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -1099, -137, 9381, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2678, 4211, 2919, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2443, 4211, 2239, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3872, 4211, 2817, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3565, 4211, 3313, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3342, 4211, 3993, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1715, 1892, -3888, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1244, 1892, -2297, 0, 0, 0, 0x00000000, bhvTree),
		TERRAIN(totwc_area_1_collision),
		MACRO_OBJECTS(totwc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_MAV),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -2, 6147, 1892, -218),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
