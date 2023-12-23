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
	LOAD_MIO0(0xa, _c4_skybox_mio0SegmentRomStart, _c4_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(241, LEVEL_BBH, 1, 60, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_CASTLE_GROUNDS, 1, 170, WARP_NO_CHECKPOINT),
		WARP_NODE(90, LEVEL_BBH, 1, 90, WARP_NO_CHECKPOINT),
		WARP_NODE(80, LEVEL_BBH, 1, 80, WARP_NO_CHECKPOINT),
		WARP_NODE(30, LEVEL_BBH, 4, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(40, LEVEL_BBH, 3, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(70, LEVEL_BBH, 1, 70, WARP_NO_CHECKPOINT),
		WARP_NODE(50, LEVEL_BBH, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(60, LEVEL_BBH, 1, 60, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_GROUNDS, 1, 170, WARP_NO_CHECKPOINT),
		OBJECT(140, -4181, -720, -2305, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(0, 3632, -720, 7458, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 3808, -720, 5739, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 3007, -720, 3715, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 4119, -720, 1903, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 6318, -720, 2612, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 5532, -720, -740, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 4279, -800, -1690, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 115, -800, -2076, 0, 0, 0, 0x3c0000, bhvDeathWarp),
		OBJECT(0, 4627, -800, -1282, 0, 90, 0, 0x460000, bhvDeathWarp),
		OBJECT(0, 110, 940, 3095, 0, -180, 0, 0x500000, bhvDeathWarp),
		OBJECT(0, -2905, -560, 1632, 0, 90, 0, 0x5a0000, bhvDeathWarp),
		OBJECT(38, 112, -800, -2360, 0, 0, 0, 0x140000, bhvDoorWarp),
		OBJECT(41, -3150, -560, 1631, 0, 90, 0, 0x1e0000, bhvDoorWarp),
		OBJECT(41, 106, -560, 3344, 0, 0, 0, 0x280000, bhvDoorWarp),
		OBJECT(41, 4389, -800, -1272, 0, -90, 0, 0x320000, bhvDoorWarp),
		OBJECT(84, -339, -420, -358, 0, 0, 0, 0x5000000, bhvGhostHuntBigBoo),
		OBJECT(84, -5700, -409, -3870, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, -7043, -409, 4415, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, -252, 132, 5952, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, 3205, 363, -6284, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, -1940, -688, -1655, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(118, -4483, -771, -3459, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -4864, -771, -3062, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -5270, -771, -2670, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -5403, -771, -1804, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -5083, -771, -1488, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -4740, -771, -1144, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -2992, -771, -2813, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3334, -771, -3148, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3651, -771, -3485, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(124, -521, -800, -2243, 0, 0, 0, 0x130000, bhvMessagePanel),
		// OBJECT(215, 2952, -400, 1852, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 4740, -400, 1194, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 5415, -400, 2376, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 5674, -400, 4155, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 4966, -400, 6106, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 2950, -400, 5815, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 4158, -400, 3265, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 2198, -400, 3045, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(101, -1219, -800, 1187, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 1263, -800, -1488, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, -229, 1120, -7768, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, -3375, 1600, -7151, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, 1159, -248, 6089, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(101, -3997, -800, -379, 0, 0, 0, 0x0, bhvScuttlebug),
		OBJECT(206, -1890, 1630, -6609, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -4211, -350, -4589, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(206, -6322, -476, -2708, 0, 0, 0, 0x0, bhvSnufit),
		OBJECT(0, 115, -800, -2077, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		// OBJECT(122, -6455, 1996, -4306, 0, 0, 0, 0x4000000, bhvStar),
		
		OBJECT(122, 104, 2356, 4265, 0, 0, 0, 0x0000000, bhvStar),
		OBJECT(122, -7036, -590 + 30, 4135, 0, 0, 0, 0x1000000, bhvStar),

		// OBJECT(122, -7039, -590 + 30, 4113, 0, 0, 0, 0x0000000, bhv1Up),

		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 12),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bbh_area_2),
		WARP_NODE(241, LEVEL_BBH, 1, 70, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BBH, 1, 50, WARP_NO_CHECKPOINT),
		OBJECT(0, -733, 252, 49, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -733, 1185, -798, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(41, -246, 0, -998, 0, 0, 0, 0xa0000, bhvDoorWarp),
		OBJECT(86, -260, 0, 675, 0, -180, 0, 0x0, bhvHauntedChair),
		OBJECT(86, 1728, 1185, -460, 0, 0, 0, 0x0, bhvHauntedChair),
		// OBJECT(122, 1772, 1981, -799, 0, 0, 0, 0x0, bhvStar),
		
		OBJECT(122, -718, -727, 1189, 0, 0, 0, 0x2000000, bhvStar),

		TERRAIN(bbh_area_2_collision),
		MACRO_OBJECTS(bbh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 41),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, bbh_area_3),
		WARP_NODE(241, LEVEL_BBH, 1, 80, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BBH, 1, 40, WARP_NO_CHECKPOINT),
		OBJECT(84, -671, 1530, -1015, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, 640, 1530, -869, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, 214, 1530, 882, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(0, -586, 230, -1572, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 586, 1185, -1577, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 1266, 1185, 494, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -472, 1185, 1502, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 373, 1185, -33, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(41, -1398, 0, -36, 0, 90, 0, 0xa0000, bhvDoorWarp),
		OBJECT(86, 857, 0, -1040, 0, 90, 0, 0x0, bhvHauntedChair),
		OBJECT(86, -1279, 0, -1305, 0, 0, 0, 0x0, bhvHauntedChair),
		OBJECT(86, -1273, 0, 1214, 0, -180, 0, 0x0, bhvHauntedChair),
		OBJECT(86, 381, 0, 600, 0, 0, 0, 0x0, bhvHauntedChair),
		OBJECT(87, 1177, 0, -1045, 0, -90, 0, 0x0, bhvMadPiano),
		
		OBJECT(122, -1286, 2189, -73, 0, 0, 0, 0x3000000, bhvStar),

		TERRAIN(bbh_area_3_collision),
		MACRO_OBJECTS(bbh_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 41),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, bbh_area_4),
		WARP_NODE(241, LEVEL_BBH, 1, 90, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BBH, 1, 30, WARP_NO_CHECKPOINT),
		OBJECT(84, 617, -67, 430, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(84, -733, -67, -643, 0, 0, 0, 0x0, bhvBoo),
		OBJECT(41, 912, 0, -1727, 0, -180, 0, 0xa0000, bhvDoorWarp),
		// OBJECT(137, -1195, 468, 1487, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(207, 4, -800, 133, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(129, 1168, -11, -801, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, -11, -601, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 189, -401, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 189, -201, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 389, -1, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 389, 199, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 589, 399, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 789, 599, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 1168, 989, 799, 0, 0, 0, 0x0, bhvHiddenObject),
		
		OBJECT(122, -1259, 689, -881, 0, 0, 0, 0x4000000, bhvStar),

		// OBJECT(122, 1199, 1677, 1482, 0, 0, 0, 0x3000000, bhvStar),
		TERRAIN(bbh_area_4_collision),
		MACRO_OBJECTS(bbh_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 41),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
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
