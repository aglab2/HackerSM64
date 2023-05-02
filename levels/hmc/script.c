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
#include "levels/hmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
    LOAD_YAY0(        /*seg*/ 0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd),
    LOAD_RAW(         /*seg*/ 0x0C, _group2_geoSegmentRomStart,  _group2_geoSegmentRomEnd),
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _hmc_segment_7SegmentRomStart, _hmc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
    JUMP_LINK(script_func_global_3),
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_HAZY_MAZE_DOOR, hazy_maze_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(55, lll_geo_000DD0), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hmc_area_1),
		WARP_NODE(241, LEVEL_CASTLE, 2, 162, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 2, 161, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_WMOTR, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, -3777, 930, 670, 0, 0, 0, 0x0, bhv1Up),
		OBJECT_WITH_ACTS(212, -68, 666, 3601, 0, 0, 0, 0x0, bhv1Up, ACT_1 | ACT_2 | ACT_3 | ACT_4),
		OBJECT(212, 973, -3360, -346, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(87, -166, -3468, -322, 0, 0, 0, 0x0, bhvBigBully),
		OBJECT_WITH_ACTS(140, -2329, 1136, 1757, 0, 27, 0, 0x0, bhvBlueCoinSwitch, ACT_6),
		OBJECT_WITH_ACTS(0, -1834, 300, -67, 0, -99, 0, 0x0, bhvCoinFormation, ACT_6),
		OBJECT_WITH_ACTS(0, -1909, 300, -636, 0, -91, 0, 0x0, bhvCoinFormation, ACT_6),
		OBJECT_WITH_ACTS(137, 3538, 2040, 3534, 0, 0, 0, 0x0, bhvExclamationBox, ACT_5),
		OBJECT(137, 2481, 720, -3115, 0, -54, 0, 0xa0000, bhvExclamationBox),
		OBJECT_WITH_ACTS(137, 3538, 2040, 3534, 0, 0, 0, 0x50000, bhvExclamationBox, ACT_6),
		OBJECT_WITH_ACTS(137, -81, 960, 3607, 0, 0, 0, 0x60000, bhvExclamationBox, ACT_6),
		OBJECT_WITH_ACTS(137, 2478, 1500, -3093, 0, 35, 0, 0x60000, bhvExclamationBox, ACT_6),
		OBJECT_WITH_ACTS(145, -24, -2981, -719, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(145, -24, -2981, 31, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(145, 2916, 919, 2116, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(145, 3193, 919, 1586, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(145, 2882, 649, 181, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(145, 2300, 649, 167, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(145, 3296, 619, -2806, 0, 0, 0, 0x0, bhvFlame, ACT_1 | ACT_2 | ACT_3 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(118, -1929, 690, 2389, 0, 105, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, -1368, 690, 2100, 0, 105, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, -691, 690, 1729, 0, 105, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 621, 420, 1886, 0, -175, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 1307, 420, 2492, 0, -175, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 1718, 420, 2105, 0, -175, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 2388, 510, 1509, 0, -160, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 2468, 510, 934, 0, -160, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(0, 2417, 900, 1222, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar, ACT_6),
		OBJECT_WITH_ACTS(0, -87, 1020, 3585, 0, 0, 0, 0x4000000, bhvHiddenStar, ACT_5),
		OBJECT_WITH_ACTS(122, 1939, 1873, 3122, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_5),
		OBJECT_WITH_ACTS(122, -2216, 1982, 3203, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_5),
		OBJECT_WITH_ACTS(122, 571, 1072, 3658, 180, 90, 0, 0x0, bhvHiddenStarTrigger, ACT_5),
		OBJECT_WITH_ACTS(122, -818, 1143, 3659, 180, 90, 0, 0x0, bhvHiddenStarTrigger, ACT_5),
		OBJECT_WITH_ACTS(122, -167, 1419, 3408, 180, 90, 0, 0x0, bhvHiddenStarTrigger, ACT_5),
		OBJECT(129, -3031, 1144, -2467, 0, 0, 0, 0x0, bhvJumpingBox),
		OBJECT(129, -3300, 1144, -2498, 0, 0, 0, 0x0, bhvJumpingBox),
		OBJECT(55, 2639, 0, -530, 0, 18, 0, 0x0, bhvLllSinkingRockBlock),
		OBJECT(55, 1868, 4, -1188, 0, 93, 0, 0x0, bhvLllSinkingRockBlock),
		OBJECT(55, 2803, 31, -1326, 0, -75, 0, 0x0, bhvLllSinkingRockBlock),
		OBJECT(55, 2771, -13, -2236, 0, 104, 0, 0x0, bhvLllSinkingRockBlock),
		OBJECT_WITH_ACTS(124, 3527, 1668, 3693, 0, -180, 0, 0x320000, bhvMessagePanel, ACT_1 | ACT_2 | ACT_3 | ACT_4),
		OBJECT(187, -2654, 108, 1637, 90, -60, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(120, -1027, -3390, -340, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT_WITH_ACTS(215, -580, -300, -698, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 516, -300, -700, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -633, -330, 242, 0, -180, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 557, -330, 242, 0, -180, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -3376, 270, 1762, 0, 87, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 1823, 180, -1189, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 3586, 433, 2304, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -2043, 1470, -3425, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT(86, -58, 124, 1506, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT(86, -2575, 152, 748, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT(0, -154, 357, -2518, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -2321, 960, 1733, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, -3299, 2640, 519, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(22, 1671, 2076, -3341, 0, 0, 0, 0xb0000, bhvWarpPipe),
		// OBJECT(0, 60, 5, 44, 0, 0, 20, 0, RM_Scroll_Texture),
		TERRAIN(hmc_area_1_collision),
		MACRO_OBJECTS(hmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 8),
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
