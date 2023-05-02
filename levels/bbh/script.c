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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _spooky_yay0SegmentRomStart, _spooky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 152, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 1, 151, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_SA, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 443, 2910, 1365, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 1831, 3240, -782, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -1848, 39, 1223, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -2316, 1860, 703, 0, -180, 0, 0x0, bhv1Up),
		OBJECT_WITH_ACTS(140, 1099, 1650, -1296, 0, 0, 0, 0x0, bhvBlueCoinSwitch, ACT_6),
		OBJECT(84, 2282, 150, -39, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, 1196, 1680, 784, 0, 0, 0, 0x0, bhvBoo),
		OBJECT_WITH_ACTS(130, 1079, 2145, 858, 0, 0, 0, 0x0, bhvBreakableBoxSmall, ACT_6),
		OBJECT(0, 1653, 750, 838, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT_WITH_ACTS(0, 1963, 2340, 848, 0, 0, 0, 0x110000, bhvCoinFormation, ACT_6),
		OBJECT_WITH_ACTS(0, -2196, 1560, -391, 0, 0, 0, 0x110000, bhvCoinFormation, ACT_6),
		OBJECT(137, -133, 3210, -234, 0, 0, 0, 0xa0000, bhvExclamationBox),
		OBJECT(137, 582, 2130, 179, 0, 0, 0, 0xc0000, bhvExclamationBox),
		OBJECT(137, 570, 1650, -388, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(137, 1117, 1890, 174, 0, 0, 0, 0x90000, bhvExclamationBox),
		OBJECT(137, 1664, 1890, -604, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT_WITH_ACTS(137, -1040, 2550, -1297, 0, 0, 0, 0x60000, bhvExclamationBox, ACT_6),
		OBJECT_WITH_ACTS(118, 1826, 1890, -1318, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 1826, 2130, -1873, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 950, 1950, -1873, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 446, 2010, -1873, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(118, 446, 2400, -1873, 0, 0, 0, 0x0, bhvHiddenBlueCoin, ACT_6),
		OBJECT_WITH_ACTS(0, 1148, 330, 2044, 0, 0, 0, 0x5000000, bhvHiddenRedCoinStar, ACT_6),
		OBJECT_WITH_ACTS(0, -218, 270, 75, 0, 0, 0, 0x0, bhvHiddenStar, ACT_1),
		OBJECT_WITH_ACTS(0, -1012, 2205, -175, 0, 0, 0, 0x2000000, bhvHiddenStar, ACT_3),
		OBJECT_WITH_ACTS(122, -847, 90, 1737, 180, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_1),
		OBJECT_WITH_ACTS(122, -1750, 1530, -909, -90, 0, 0, 0x0, bhvHiddenStarTrigger, ACT_3),
		OBJECT(87, -1753, 1410, -929, 0, 0, 0, 0x0, bhvMadPiano),
		OBJECT(124, -1803, 120, -1785, 0, -156, 0, 0x310000, bhvMessagePanel),
		OBJECT(0, -2622, 0, 70, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(187, 1028, 2711, 249, 90, 0, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT_WITH_ACTS(215, 767, 3570, 1363, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 722, 1386, 843, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 623, 990, 129, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -1627, 1440, 978, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -2038, 13, -1132, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -1152, 30, 2085, 0, -180, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, 1131, 2910, 1364, 0, 0, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT_WITH_ACTS(215, -2200, 2160, -957, 0, -180, 0, 0x0, bhvRedCoin, ACT_6),
		OBJECT(101, 1375, 0, -1161, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, -1641, 0, -339, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 1443, 30, 1981, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(0, -2002, 120, -2102, 0, 79, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -2106, 74, 968, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(24, -2570, 0, 2128, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, 64, 27, 2325, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, 2021, 0, -2363, 0, 0, 0, 0x0, bhvTree),
		OBJECT(22, -1071, 1110, -1082, 90, -90, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 7),
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
