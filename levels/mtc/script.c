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
#include "levels/mtc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_mtc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _mtc_segment_7SegmentRomStart, _mtc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bitfs_skybox_mio0SegmentRomStart, _bitfs_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_BALL, mtc_ball_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_PLATSPIN, mtc_platspin_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_PROPELLER, mtc_spinner_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_LINE_ACTIVE, mtc_line_active_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_LINE_INACTIVE, mtc_line_inactive_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_LINE_WHOLE, mtc_line_whole_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_LINE_SWITCH, mtc_line_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_LINE_SWITCH_OFF, mtc_line_switch_off_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_LINE_SWITCH_OFF, mtc_line_switch_off_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_MTC_ICE_ROTAT, mtc_blue_rotat_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, mtc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_MTC, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_MTC, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 1, 0x32, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 1, 0x42, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0D, LEVEL_MTC, 0x01, 0x0E, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0E, LEVEL_MTC, 0x01, 0x0D, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_MTC, 0x01, 0x20, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 3237, -332, 2052),
		OBJECT(MODEL_BLUE_COIN, 67, 544, -3913, 0, 144, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 642, 304, -3900, 0, 144, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 572, 75, -3298, 0, 144, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1114, -98, -3396, 0, 144, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1244, -349, -2932, 0, 144, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1823, -132, -2446, 0, 144, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -258, 651, -4621, 0, 136, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_NONE, -841, 695, -4381, 0, 136, 0, (0x11 << 16), bhvCoinFormation),
		OBJECT(MODEL_MTC_ICE_ROTAT, -3037, 438, -3938, 0, 0, 0, 0x00000000, bhvMtcBlueRotat),
		OBJECT(MODEL_PURPLE_SWITCH, -4357, 1515, -5009, 0, 0, 0, 0x00000000, bhvFloorSwitchGrills),
		OBJECT(MODEL_MTC_ICE_ROTAT, -3729, 617, -3933, 0, 0, 0, 0x00000000, bhvMtcBlueRotat),
		OBJECT(MODEL_MTC_ICE_ROTAT, -4576, 844, -3938, 0, 0, 0, 0x00000000, bhvMtcBlueRotat),
		OBJECT(MODEL_MTC_ICE_ROTAT, -5355, 1019, -3927, 0, 0, 0, 0x00000000, bhvMtcBlueRotat),
		OBJECT(MODEL_MTC_ICE_ROTAT, -6142, 1248, -3938, 0, 0, 0, 0x00000000, bhvMtcBlueRotat),
		OBJECT(MODEL_MTC_ICE_ROTAT, -3834, 2699, -5277, 0, 0, 0, (1 << 16), bhvMtcBlueRotat),
		OBJECT(MODEL_MTC_ICE_ROTAT, -4586, 2562, -5291, 0, 0, 0, (2 << 16), bhvMtcBlueRotat),
		OBJECT(MODEL_MTC_ICE_ROTAT, -5349, 2727, -5260, 0, 0, 0, (3 << 16), bhvMtcBlueRotat),
		OBJECT(MODEL_NONE, 7440, 758, 5290, 0, 144, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_BULLY, 6356, 300, -372, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -5555, 1258, -6081, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 9779, 1672, -9725, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 8779, 1672, -10373, 0, 64, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 206, 707, -5332, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -2874, 2820, -6580, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 15170, 1272, 6312, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_NONE, -2250, 2044, 2911, 0, -180, 0, 0x00000000, bhvCannon),
		OBJECT(MODEL_NONE, 2299, 474, -7651, 0, -180, 0, 0x00000000, bhvCannon),
		OBJECT(MODEL_NONE, 10435, 1191, 2682, 0, 144, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6266, 537, -784, 0, 144, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2544, -171, -2970, 0, 144, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6156, 828, -6065, 0, 90, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 12596, 1799, -5974, 0, 90, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10258, 1140, -2100, 0, -150, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 7077, 1137, -8054, 0, 64, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6157, -389, 7440, 0, -71, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3052, -322, 1864, 0, -71, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3903, -186, -48, 0, 174, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2694, -213, -1913, 0, -118, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 350, 966, -7504, 0, -71, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4659, 2750, -7855, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7103, 1721, -5325, 0, 1, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4664, 89, 7453, 0, -23, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 16768, -699, -2133, 0, -113, 0, (0xb << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 11781, -699, 8293, 0, -113, 0, (0xc << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 15677, 731, 350, 0, -47, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 11785, -697, 8290, 0, -113, 0, (0xc << 16), bhvSparkler),
		OBJECT(MODEL_NONE, 16768, -699, -2136, 0, -113, 0, (0xc << 16), bhvSparkler),
		OBJECT(MODEL_NONE, 16470, -30, 1036, 0, -47, 0, (4 << 24), bhvMtcBrickCtl),
		OBJECT(MODEL_NONE, 745, 1201, -7271, 0, 90, 0, (0x20 << 16), bhvFadingWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, -7233, 912, -8400, 0, 0, 0, 0x00000000, bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 7946, 1587, 6031, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT_WITH_ACTS(MODEL_EXCLAMATION_BOX, 6257, 834, -769, 0, 144, 0, (0 << 16), bhvExclamationBox, ACT_6),
		OBJECT(MODEL_EXCLAMATION_BOX, -6164, -120, -5219, 0, 144, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -3978, 1464, -5951, 0, -133, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 9207, 1984, -10620, 0, -177, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 10355, -202, 7990, 0, 161, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 4292, 1754, -4913, 0, 130, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 6939, 1606, 3323, 0, 166, 0, (6 << 16), bhvExclamationBox),
		OBJECT_WITH_ACTS(MODEL_EXCLAMATION_BOX, -1989, 2517, 3309, 0, 118, 0, (0 << 16), bhvExclamationBox, ACT_6),
		OBJECT_WITH_ACTS(MODEL_EXCLAMATION_BOX, 2556, 948, -7914, 0, 118, 0, (0 << 16), bhvExclamationBox, ACT_6),
		OBJECT(MODEL_NONE, 1058, 2471, 217, 0, 144, 0, (5 << 24), bhvHiddenStar),
		OBJECT(MODEL_WOODEN_SIGNPOST, 6120, 300, -1112, 0, -36, 0, (52 << 24) | (52 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, -3645, -650, 8283, 0, -180, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, -3920, -656, 8580, 0, 0, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, -3375, -654, 8580, 0, 0, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_NONE, 9233, 1956, -9419, 0, 0, 0, (4 << 16), bhvFlamethrower),
		OBJECT(MODEL_BULLY, 7970, 321, 5679, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_THI_WARP_PIPE, 2551, -474, 5738, 0, 0, 0, (0xd << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, -852, -429, 5018, 0, 0, 0, (0xe << 16), bhvWarpPipe),
		OBJECT(MODEL_WOODEN_SIGNPOST, -677, -429, 5612, 0, -139, 0, (16 << 24) | (16 << 16), bhvMessagePanel),
		OBJECT(MODEL_RED_COIN, 88, -139, 4859, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2586, -706, 4095, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5389, -247, 4046, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5351, 212, 6352, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5616, -706, 7996, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3654, -706, 8878, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1323, 50, 7902, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3682, -58, 9452, 0, -139, 0, (16 << 24) | (16 << 16), bhvRedCoin),
		OBJECT(MODEL_NONE, -174, -79, 5956, 0, -139, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvMtcRedGround),
		OBJECT(MODEL_NONE, 9643, 3669, -6478, 0, 144, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -3315, 3972, -9533, 0, 144, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -2679, 4349, 7093, 0, 144, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 13856, 3507, 4730, 0, 144, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 6257, 537, -769, 0, 144, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 9643, 4091, -6478, 0, 144, 0, (18 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3315, 4394, -9533, 0, 144, 0, (18 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2679, 4771, 7093, 0, 144, 0, (18 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 13856, 3929, 4730, 0, 144, 0, (18 << 16), bhvCoinFormation),
		OBJECT(MODEL_MTC_PLATSPIN, 3049, 977, -7650, 0, 90, 0, (0x20 << 16), bhvMtcGreenPlatspin),
		OBJECT(MODEL_MTC_LINE_SWITCH, 4631, 988, -5161, 0, 90, 0, 0x00000000, bhvMtcGreenLineSwitch),
		OBJECT(MODEL_MTC_LINE_SWITCH, 9231, 2441, -10138, 0, 90, 0, 0x00000000, bhvMtcGreenLineSwitch),
		OBJECT(MODEL_MTC_LINE_SWITCH, 11937, 2250, -8922, 0, 90, 0, 0x00000000, bhvMtcGreenLineSwitch),
		OBJECT(MODEL_MTC_LINE_SWITCH, 10545, 1582, -958, 0, 90, 0, 0x00000000, bhvMtcGreenLineSwitch),
		OBJECT(MODEL_STAR, -6220, 3629, -5369, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, 11005, 1467, -6196, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR, 13061, 1945, 6494, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_NONE, 3070, 9, 1905, 0, 0, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, -7125, 1848, -8243, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5466, -509, -449, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 12234, 976, 1732, 0, 0, 0, (1 << 24) | (4 << 16), bhvMtcYellowSpawner),
		OBJECT(MODEL_NONE, 14598, 1000, 2125, 0, 0, 0, (1 << 24) | (2 << 16), bhvMtcYellowSpawner),
		OBJECT(MODEL_NONE, 7429, 127, 5293, 0, 0, 0, 0x00000000, bhvMtcYellowSpawner),
		OBJECT(MODEL_NONE, 7464, 349, 2870, 0, 0, 0, (1 << 16), bhvMtcYellowSpawner),
		OBJECT(MODEL_PURPLE_SWITCH, 10115, 1299, 3023, 0, -36, 0, 0x00000000, bhvMtcYellowPurpleSwitch),
		OBJECT(MODEL_NONE, 7468, 1062, 2865, 0, 144, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_BULLY, 10565, -35, 6587, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 12883, 1672, -6469, 0, 144, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_NONE, 11000, 938, 1783, 0, 0, 0, (1 << 24) | (5 << 16), bhvMtcYellowSpawner),
		OBJECT(MODEL_NONE, 13429, 1071, 2029, 0, 0, 0, (1 << 24) | (3 << 16), bhvMtcYellowSpawner),
		OBJECT(MODEL_NONE, 15616, 622, 2879, 0, 0, 0, (1 << 24) | (1 << 16), bhvMtcYellowSpawner),
		OBJECT(MODEL_NONE, 15221, 1218, 7004, 0, 0, 0, (4 << 16), bhvMtcYellowSpawner),
		TERRAIN(mtc_area_1_collision),
		MACRO_OBJECTS(mtc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_C2),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 3237, -332, 2052),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};