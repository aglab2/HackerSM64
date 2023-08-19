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
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x6, _group16_mio0SegmentRomStart, _group16_mio0SegmentRomEnd), 
	LOAD_MIO0(0xb, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group2_mio0SegmentRomStart, _group2_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(30, LEVEL_BBH, 1, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_BBH, 1, 30, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_COTMC, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 113, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 97, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BBH, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, -4778, -1461, 576, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, 1400, -450, -3950, 0, -180, 0, 0x50000, bhvAirborneStarCollectWarp),
		OBJECT_WITH_ACTS(87, 3208, 723, 5583, 0, 0, 0, 0x0, bhvBigBully, ACT_1),
		OBJECT(140, -1958, 723, -1932, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(129, 2380, 1283, 805, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2580, 1483, 1005, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2180, 1283, 805, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 2580, 1283, 805, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 2380, 1283, 1005, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2980, 1283, 805, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 2580, 1283, 1005, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2380, 1483, 805, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2780, 1283, 805, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2780, 1483, 805, 0, 0, 0, 0x10000, bhvBreakableBox),
		OBJECT(129, 2780, 1283, 1005, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2580, 1483, 805, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2580, 1283, 1205, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2180, 1283, 1005, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(129, 2680, 1783, 805, 0, 0, 90, 0x0, bhvBreakableBox),
		OBJECT(129, 2780, 1283, 1205, 0, 0, 0, 0x0, bhvBreakableBox),
		OBJECT(0, -2807, -2124, 1661, 0, 0, 0, 0x0, bhvCheckerboardElevatorGroup),
		OBJECT(0, -5397, -730, -4058, 0, -90, 0, 0x0, bhvCheckerboardElevatorGroup),
		OBJECT(223, -5065, -1026, -984, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, 2550, -519, -3690, 0, -180, 0, 0x40000, bhvCoinFormation),
		OBJECT(0, -301, 37, 850, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 829, -170, -113, 20, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4530, -2013, 1438, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -3708, 1983, 978, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -3737, -916, 483, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -367, 1515, 3045, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -392, -907, -2785, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1047, 723, 5070, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -538, -2583, 3615, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4290, 2193, 1741, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3186, -13, 1046, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 1400, -450, -3950, 0, 0, 0, 0x60000, bhvDeathWarp),
		OBJECT(137, -2755, 2160, 3218, 0, 0, 0, 0x30000, bhvExclamationBox),
		OBJECT(137, 4050, -419, -2400, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 1349, 1042, 5970, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(0, 1680, 3835, -5523, 0, -153, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1899, 768, 6920, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(180, 4570, -2713, -1247, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(220, 2757, -208, -3252, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, -405, 313, 1424, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(0, -2149, -2433, 174, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, -2593, 723, -1932, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3720, 723, -1932, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3720, 792, -1311, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3720, 1122, -700, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3138, 688, -1932, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -3720, 1318, -125, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(0, -282, -2010, 1410, 0, 0, 0, 0x3000000, bhvHiddenRedCoinStar),
		OBJECT(217, 2550, -872, -4060, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, -5588, 723, 6005, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4600, -2713, -9, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4559, -2013, 2575, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3186, -88, 1046, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1465, -2187, 5200, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -358, -872, 1214, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1923, 1633, 885, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1882, 723, -4089, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(86, -1842, -2433, 2318, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT(86, -2468, 723, -2767, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT(86, -3954, -1026, 1780, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT(86, -393, -2433, 2420, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT(86, -4597, -1026, -2643, 0, 0, 0, 0x0, bhvSmallBully),
		OBJECT_WITH_ACTS(86, 3930, 723, 5548, 0, 0, 0, 0x0, bhvSmallBully, ACT_1),
		OBJECT_WITH_ACTS(86, 2688, 723, 5594, 0, 0, 0, 0x0, bhvSmallBully, ACT_1),
		OBJECT(0, 3640, -2154, -580, 0, -45, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -353, 2052, 269, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, -479, 782, -2370, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(122, -4050, -1459, -2000, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT_WITH_ACTS(122, 3223, -2470, 4058, 0, 0, 0, 0x4000000, bhvStar, ACT_5 | ACT_6),
		OBJECT(0, 0, -500, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 2550, -872, -4441, 0, 0, 0, 0x0, bhvWarp),
		OBJECT_WITH_ACTS(22, 2077, -2730, -304, 0, 90, 0, 0x140000, bhvWarpPipe, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT_WITH_ACTS(22, 3130, 700, 5600, 0, -180, 0, 0x1e0000, bhvWarpPipe, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 19),
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
