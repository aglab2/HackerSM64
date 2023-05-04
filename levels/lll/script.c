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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(241, LEVEL_BITS, 1, 182, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITS, 1, 181, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BITDW, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 7524, 16590, 1789, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 7003, 10350, 1396, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 7696, 9540, 2180, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 7225, 8160, 2798, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(140, 6600, 11873, -1706, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(130, 2798, 5237, -3898, 0, 0, 0, 0x0, bhvBreakableBoxSmall),
		OBJECT(130, -3159, 15818, -1901, 0, 0, 0, 0x0, bhvBreakableBoxSmall),
		OBJECT(223, -2875, 13684, -258, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -6173, 13404, 202, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, -5587, 5242, 1200, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 2680, 1943, 1274, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1, 2578, 38, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -5802, 12278, -1966, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 6028, 15677, 1756, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3486, 16350, -5839, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 3512, 16260, 2658, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -4591, 14850, 6317, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(137, 7093, 3360, 1788, 0, 0, 0, 0x20000, bhvExclamationBox),
		OBJECT(137, -6989, 17280, 2503, 0, 0, 0, 0x30000, bhvExclamationBox),
		OBJECT(137, 2804, 3000, 3128, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 5555, 4470, 4311, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 6159, 4470, 4311, 0, 0, 0, 0x40000, bhvExclamationBox),
		OBJECT(137, 4961, 4470, 4311, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(137, 0, 13500, 332, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 1011, 14910, -1851, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(137, 4, 16620, -2764, 0, 0, 0, 0x70000, bhvExclamationBox),
		OBJECT(137, -3245, 4886, 2428, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(137, 6536, 8254, 1266, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(137, 723, 13484, -2645, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(137, 3426, 14091, 1519, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(137, -2649, 15897, -1671, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(0, -5057, 4530, 3824, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -5057, 4740, 3824, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -6100, 4530, 3824, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(0, -6100, 4740, 3824, 0, 0, 0, 0x0, bhvFlamethrower),
		OBJECT(207, 2812, 5237, 1276, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(220, -3748, 6330, 2130, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, -3331, 17580, -1237, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(89, 5194, 3023, 2243, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 4990, 3023, 3229, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, 6349, 3023, 4096, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -5687, 14609, 2021, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(89, -4384, 15818, 2115, 0, 0, 0, 0x0, bhvHeaveHo),
		OBJECT(118, 6596, 11940, -1000, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6596, 11940, -200, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6596, 11940, 600, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6596, 12360, 1391, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6596, 11520, 2200, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, 6596, 11520, 2700, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(129, -5, 4836, 1400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -5, 4836, 1600, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -5, 4836, 2400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -30, 1416, -679, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -30, 1416, -879, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -30, 1462, -1502, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -4940, 17400, 402, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar),
		OBJECT(0, -7, 10890, -2354, 0, 0, 0, 0x2000000, bhvHiddenStar),
		OBJECT(212, -3206, 9720, -1274, -180, -90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(212, -1498, 9330, -1675, 0, 0, -180, 0x0, bhvHiddenStarTrigger),
		OBJECT(212, 6, 10230, -1134, 0, 0, -180, 0x0, bhvHiddenStarTrigger),
		OBJECT(212, 1499, 9930, -1643, 0, 0, -180, 0x0, bhvHiddenStarTrigger),
		OBJECT(212, 3199, 9930, -2140, 180, 90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(129, 6603, 5840, 4517, 0, 0, 0, 0x0, bhvJumpingBox),
		OBJECT(129, -6967, 17025, -1845, 0, 0, 0, 0x0, bhvJumpingBox),
		OBJECT(124, -1587, 6440, -2023, 0, 0, 0, 0x2a0000, bhvMessagePanel),
		OBJECT(124, -3, 17305, -1983, 0, -180, 0, 0x2b0000, bhvMessagePanel),
		OBJECT(124, 7, 2863, -3065, 0, -180, 0, 0x4b0000, bhvMessagePanel),
		OBJECT(116, -5613, 7260, 1813, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, -5893, 6780, 2077, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, -6125, 6780, 2316, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(187, 2, 15760, -782, 90, 0, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(187, 2528, 1954, 2729, 90, -90, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, 2, 6480, -1706, 0, 0, 0, 0x9f0000, bhvPoleGrabbing),
		OBJECT(0, 2, 8070, -1706, 0, 0, 0, 0xc30000, bhvPoleGrabbing),
		OBJECT(0, 2, 10020, -1706, 0, 0, 0, 0xb10000, bhvPoleGrabbing),
		OBJECT(0, 3, 11790, -1706, 0, 0, 0, 0x8a0000, bhvPoleGrabbing),
		OBJECT(217, -30, 1356, -1755, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, -2678, 2040, 2745, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6607, 6600, 3041, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5120, 7950, 1482, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 13, 5280, 2045, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4146, 12180, 1016, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 2609, 15990, -1615, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4379, 14430, 1458, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3858, 16080, 2118, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(206, 5469, 16727, 2008, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, 4733, 16847, 1483, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -5440, 16097, -1030, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -5899, 16097, 1504, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(0, -1593, 6540, -1263, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -5598, 4650, 4342, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, 7030, 2850, 4042, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, -5787, 9120, 485, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, 4593, 14550, 1511, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(22, -30, 1661, -1752, 0, 24, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 34),
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
