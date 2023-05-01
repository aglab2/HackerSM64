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
#include "levels/castle_inside/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP, castle_geo_000F18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND, castle_geo_001530), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND, castle_geo_001548), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM, castle_geo_001518), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(241, LEVEL_CASTLE, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(132, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(131, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(122, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(121, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(112, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(111, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_CASTLE, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(100, LEVEL_CASTLE_COURTYARD, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(130, LEVEL_JRB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(120, LEVEL_WF, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(110, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(31, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(212, 960, 160, 1073, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, -201, 64, -997, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(124, 43, 64, -1121, 0, -60, 0, (54 << 16), bhvMessagePanel),
		OBJECT(124, -902, 50, -1366, 0, 43, 0, (60 << 16), bhvMessagePanel),
		OBJECT(124, -1111, 96, -1169, 0, 43, 0, (61 << 16), bhvMessagePanel),
		OBJECT(124, -1452, 0, 884, 0, -90, 0, (68 << 16), bhvMessagePanel),
		OBJECT(124, 1230, 86, -687, 0, 145, 0, (74 << 16), bhvMessagePanel),
		OBJECT(0, -178, 300, 62, 0, 0, 0, (241 << 16), bhvPaintingDeathWarp),
		OBJECT(0, 626, 810, 1034, 0, -5, 0, (112 << 16), bhvPaintingDeathWarp),
		OBJECT(0, -942, 900, 857, 0, -90, 0, (122 << 16), bhvPaintingDeathWarp),
		OBJECT(0, -754, 420, 441, 0, 0, 0, (132 << 16), bhvPaintingDeathWarp),
		OBJECT(0, -177, 300, 45, 0, 0, 0, (240 << 16), bhvPaintingStarCollectWarp),
		OBJECT(0, 637, 840, 1029, 0, -5, 0, (111 << 16), bhvPaintingStarCollectWarp),
		OBJECT(0, -927, 900, 858, 0, -90, 0, (121 << 16), bhvPaintingStarCollectWarp),
		OBJECT(0, -766, 420, 435, 0, 0, 0, (131 << 16), bhvPaintingStarCollectWarp),
		OBJECT(187, 1307, 510, 141, 90, 36, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, -200, 64, -991, 0, 0, 0, (31 << 16), bhvSpinAirborneWarp),
		OBJECT(0, -299, -38, 854, 0, -180, 0, (11 << 16), bhvSpinAirborneWarp),
		OBJECT(213, -347, 0, 1800, 0, 0, 0, (8 << 24), bhvStarDoor),
		OBJECT(213, -189, 0, 1800, 0, -180, 0, (8 << 24), bhvStarDoor),
		OBJECT(221, -1361, 1273, 880, 0, 90, 0, (82 << 24), bhvToadMessage),
		OBJECT(221, -332, -10, -220, 0, 167, 0, (133 << 24), bhvToadMessage),
		OBJECT(24, 928, 16, -1182, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, 1419, 1006, 1523, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, -1434, 45, -755, 0, 0, 0, 0x0, bhvTree),
		OBJECT(25, 994, 456, 840, 0, -180, 0, 0x0, bhvTree),
		OBJECT(25, 1179, 212, -437, 0, -180, 0, 0x0, bhvTree),
		OBJECT(0, -259, 60, 2419, 0, 0, 0, (10 << 24) | (100 << 16), bhvWarp),
		OBJECT(22, 1205, 362, 393, 0, 0, 0, (110 << 16), bhvWarpPipe),
		OBJECT(22, -1283, 471, 880, 0, 0, 0, (120 << 16), bhvWarpPipe),
		OBJECT(22, -1105, 92, -49, 0, 0, 0, (130 << 16), bhvWarpPipe),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 10),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, castle_inside_area_2),
		WARP_NODE(241, LEVEL_CASTLE, 2, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 2, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(180, LEVEL_BITFS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(160, LEVEL_HMC, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(182, LEVEL_CASTLE, 2, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(181, LEVEL_CASTLE, 2, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(162, LEVEL_CASTLE, 2, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(161, LEVEL_CASTLE, 2, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(104, LEVEL_BITS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(103, LEVEL_CASTLE_COURTYARD, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 2, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 1063, -503, 1338, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 1666, -503, 1338, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 1370, -503, 1638, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 1370, -503, 1031, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(34, -1854, -232, 432, 0, 0, 0, (64 << 24), bhvDoor),
		OBJECT(207, -1764, 1342, 1586, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(129, -1490, 1142, 1587, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -1290, 1142, 1587, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -1090, 1142, 1587, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -200, 1142, 1587, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 0, 1142, 1587, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(124, -2011, 54, -640, 0, 103, 0, (62 << 16), bhvMessagePanel),
		OBJECT(0, 404, 300, -298, 0, 0, 0, (241 << 16), bhvPaintingDeathWarp),
		OBJECT(0, 1347, 390, 503, 0, 0, 0, (161 << 16), bhvPaintingDeathWarp),
		OBJECT(0, -1758, 750, 1187, 0, 0, 0, (182 << 16), bhvPaintingDeathWarp),
		OBJECT(0, 404, 300, -297, 0, 0, 0, (240 << 16), bhvPaintingStarCollectWarp),
		OBJECT(0, 1347, 390, 501, 0, 0, 0, (162 << 16), bhvPaintingStarCollectWarp),
		OBJECT(0, -1758, 750, 1186, 0, 0, 0, (181 << 16), bhvPaintingStarCollectWarp),
		OBJECT(187, -1416, 71, -1032, 90, 0, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(120, 802, 66, -291, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, -1852, -172, 569, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(0, 424, 0, -1051, 0, 0, 0, (10 << 16), bhvSpinAirborneWarp),
		OBJECT(208, 1286, 346, 986, 0, 0, 0, (30 << 24), bhvStarDoor),
		OBJECT(208, 1444, 346, 986, 0, -180, 0, (30 << 24), bhvStarDoor),
		OBJECT(209, -1839, 432, 1448, 0, 0, 0, (50 << 24), bhvStarDoor),
		OBJECT(209, -1681, 432, 1448, 0, -180, 0, (50 << 24), bhvStarDoor),
		OBJECT(221, 1385, 1418, 1343, 0, -90, 0, (83 << 24), bhvToadMessage),
		OBJECT(24, 1458, 90, -1529, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, 1635, 34, -1007, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, -1908, 34, -1514, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, -2172, 45, -968, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, -136, 0, -1410, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, -340, 0, -277, 0, 0, 0, 0x0, bhvTree),
		OBJECT(24, -1157, 43, -1534, 0, 0, 0, 0x0, bhvTree),
		OBJECT(0, 435, 0, -2197, 0, 0, 0, (10 << 24) | (103 << 16), bhvWarp),
		OBJECT(0, -1848, -232, 157, 0, 0, 0, (6 << 24) | (104 << 16), bhvWarp),
		OBJECT(0, 1375, 346, 1268, 0, 0, 0, (6 << 24) | (160 << 16), bhvWarp),
		OBJECT(0, -1756, 432, 1599, 0, 0, 0, (4 << 24) | (180 << 16), bhvWarp),
		TERRAIN(castle_inside_area_2_collision),
		MACRO_OBJECTS(castle_inside_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 10),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, -206, 64, -995),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
