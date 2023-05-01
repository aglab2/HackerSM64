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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
    LOAD_YAY0_TEXTURE(/*seg*/ 0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd),
    LOAD_YAY0(        /*seg*/ 0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd),
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ccm_skybox_mio0SegmentRomStart, _ccm_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(241, LEVEL_CASTLE, 1, 112, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 111, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_PSS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(0, -772, 360, -599, 0, 40, 0, (10 << 16), bhvSpinAirborneWarp),
		OBJECT_WITH_ACTS(140, 1116, 2366, 612, 0, 0, 0, 0x00000000, bhvBlueCoinSwitch, ACT_4),
		OBJECT_WITH_ACTS(0, 182, 955, 170, 0, -40, 0, 0x00000000, bhvCoinFormation, ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(0, 1865, 2182, -658, 0, -29, 0, (17 << 16), bhvCoinFormation, ACT_3 | ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(137, -1184, 3382, 1508, 0, -29, 0, (2 << 16), bhvExclamationBox, ACT_5),
		OBJECT_WITH_ACTS(137, 338, 3450, 374, 0, -39, 0, (6 << 16), bhvExclamationBox, ACT_4),
		OBJECT_WITH_ACTS(137, 1410, 2040, -1023, 0, -43, 0, (6 << 16), bhvExclamationBox, ACT_4),
		OBJECT_WITH_ACTS(137, 2515, 360, 739, 0, 0, 0, (6 << 16), bhvExclamationBox, ACT_4),
		OBJECT_WITH_ACTS(137, -855, 4140, 1043, 0, -39, 0, (6 << 16), bhvExclamationBox, ACT_4),
		OBJECT_WITH_ACTS(207, 1157, 2848, -945, 0, 57, 0, 0x00000000, bhvFloorSwitchHiddenObjects, ACT_3),
		OBJECT_WITH_ACTS(118, 1841, 1740, -804, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin, ACT_4),
		OBJECT_WITH_ACTS(118, 1586, 1590, -1271, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin, ACT_4),
		OBJECT_WITH_ACTS(118, 1156, 1410, -1426, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin, ACT_4),
		OBJECT_WITH_ACTS(118, 772, 1200, -1180, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin, ACT_4),
		OBJECT_WITH_ACTS(118, 589, 1050, -730, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin, ACT_4),
		OBJECT_WITH_ACTS(118, 984, 1020, -208, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin, ACT_4),
		OBJECT_WITH_ACTS(129, 843, 2762, -1125, 0, 55, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, 679, 2762, -1239, 0, 55, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, 524, 2762, -1348, 0, 55, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, 361, 2762, -1462, 0, 55, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, 197, 2762, -1577, 0, 55, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -192, 2762, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -391, 2762, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -591, 2762, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -790, 2962, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -990, 3162, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -1190, 3362, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(129, -1390, 3362, -1460, 0, 0, 0, 0x00000000, bhvHiddenObject, ACT_3),
		OBJECT_WITH_ACTS(0, -1994, 1500, 2331, 0, 0, 0, (4 << 24), bhvHiddenRedCoinStar, ACT_4),
		OBJECT_WITH_ACTS(0, 2549, 435, 788, 0, 0, 0, (2 << 24), bhvHiddenStar, ACT_2),
		OBJECT_WITH_ACTS(0, 1333, -162, 1641, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger, ACT_2),
		OBJECT_WITH_ACTS(0, 1460, 618, 405, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger, ACT_2),
		OBJECT_WITH_ACTS(0, 1323, 198, 1607, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger, ACT_2),
		OBJECT_WITH_ACTS(0, 1805, -42, 1919, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger, ACT_2),
		OBJECT_WITH_ACTS(0, 834, -132, 1898, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger, ACT_2),
		OBJECT_WITH_ACTS(124, 257, 41, 254, 0, -128, 0, (8 << 16), bhvMessagePanel, ACT_1 | ACT_2 | ACT_3),
		OBJECT_WITH_ACTS(124, 1388, 1815, -999, 0, 136, 0, (16 << 16), bhvMessagePanel, ACT_1 | ACT_2 | ACT_3),
		OBJECT(124, -154, 14, 771, 0, 160, 0, (77 << 16), bhvMessagePanel),
		OBJECT(85, 1822, -65, -1318, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT(85, -1847, -76, 1146, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT_WITH_ACTS(116, 1333, -162, 1641, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_2),
		OBJECT_WITH_ACTS(116, 1460, 618, 405, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_2),
		OBJECT_WITH_ACTS(116, 1323, 198, 1607, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_2),
		OBJECT_WITH_ACTS(116, 1805, -42, 1919, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_2),
		OBJECT_WITH_ACTS(116, 834, -132, 1898, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_2),
		OBJECT_WITH_ACTS(116, -756, 3600, 1782, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_4 | ACT_5),
		OBJECT_WITH_ACTS(116, -1163, 3750, 1502, 0, 0, 0, 0x00000000, bhvOneCoin, ACT_4 | ACT_5),
		OBJECT(187, 876, 2858, -581, 90, -78, 0, 0x00000000, bhvPenguinRaceShortcutCheck),
		OBJECT_WITH_ACTS(215, 1724, 1080, 148, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, 766, 1410, -1952, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, 2348, 2880, -521, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, -612, 1050, 1485, 0, 0, 0, (16 << 16), bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, -364, 180, -2591, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, -2089, 90, 2542, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, 2368, 90, 2502, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(215, 1748, 1650, -460, 0, 0, 0, 0x00000000, bhvRedCoin, ACT_4),
		OBJECT_WITH_ACTS(87, 1259, 596, -273, 0, 0, 0, 0x00000000, bhvSmallPenguin, ACT_1),
		OBJECT_WITH_ACTS(87, -432, 80, 1771, 0, 0, 0, (1 << 16), bhvSmallPenguin, ACT_1),
		OBJECT_WITH_ACTS(87, 1822, -157, 1601, 0, 0, 0, (1 << 16), bhvSmallPenguin, ACT_1),
		OBJECT(84, -1427, 16, 2637, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(84, -1476, -27, -1947, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT_WITH_ACTS(122, -866, 4260, 1042, 0, 0, 0, 0x00000000, bhvStar, ACT_1 | ACT_2 | ACT_3),
		OBJECT(122, -1745, 3900, -1482, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(122, 350, 2877, 365, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(25, -175, 45, 2543, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(25, -2102, -22, -2033, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(25, 2266, -20, -2140, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(25, -2562, 58, 1016, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT_WITH_ACTS(87, -488, 168, -2135, 0, 0, 0, (1 << 24), bhvTuxiesMother, ACT_1),
		OBJECT(22, -823, -2, 1156, 0, 0, 0, (11 << 16), bhvWarpPipe),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 3),
		TERRAIN_TYPE(TERRAIN_SNOW),
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
