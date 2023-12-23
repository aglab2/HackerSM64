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
#include "levels/ttc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _machine_yay0SegmentRomStart, _machine_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _c4_skybox_mio0SegmentRomStart, _c4_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_CUBE, ttc_geo_000240), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_PRISM, ttc_geo_000258), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PENDULUM, ttc_geo_000270), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_LARGE_TREADMILL, ttc_geo_000288), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_SMALL_TREADMILL, ttc_geo_0002A8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PUSH_BLOCK, ttc_geo_0002C8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_HEXAGON, ttc_geo_0002E0), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_TRIANGLE, ttc_geo_0002F8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PIT_BLOCK, ttc_geo_000310), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PIT_BLOCK_UNUSED, ttc_geo_000328), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ELEVATOR_PLATFORM, ttc_geo_000340), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_CLOCK_HAND, ttc_geo_000358), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_SPINNER, ttc_geo_000370), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_SMALL_GEAR, ttc_geo_000388), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_LARGE_GEAR, ttc_geo_0003A0), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(22, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttc_area_1),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 3, 40, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(130, LEVEL_TTC, 1, 130, WARP_NO_CHECKPOINT),
		WARP_NODE(120, LEVEL_TTC, 1, 120, WARP_NO_CHECKPOINT),
		WARP_NODE(110, LEVEL_TTC, 1, 110, WARP_NO_CHECKPOINT),
		WARP_NODE(100, LEVEL_RR, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(90, LEVEL_TTC, 2, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(80, LEVEL_TTC, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(70, LEVEL_TTC, 1, 60, WARP_NO_CHECKPOINT),
		WARP_NODE(60, LEVEL_TTC, 1, 70, WARP_NO_CHECKPOINT),
		WARP_NODE(50, LEVEL_TTC, 1, 40, WARP_NO_CHECKPOINT),
		WARP_NODE(40, LEVEL_TTC, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(30, LEVEL_TTC, 1, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_TTC, 1, 30, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_CASTLE_COURTYARD, 3, 30, WARP_NO_CHECKPOINT),
		WARP_NODE(0xe0, LEVEL_TTC, 3, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xe1, LEVEL_TTC, 4, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -5286, 4656, 11432, 0, -180, 0, (0xe0 << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -10448, 4360, 6329, 0, 90, 0, (0xe1 << 16), bhvWarpPipe),
		OBJECT(140, -7514, 4666, 9178, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT(0, -5008, 1488, 639, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4986, 1680, 3615, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4958, 4080, 5719, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -1643, 4328, 5054, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3187, 4519, 4716, 0, 96, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3455, 4936, 6133, 0, 90, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -8212, 4200, 5510, 0, 123, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -4950, 1200, -2797, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -5277, 4656, 10778, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 13421, 4720, -4666, 0, 0, 0, 0x780000, bhvDeathWarp),
		OBJECT(0, 10640, 4720, 838, 0, 0, 0, 0x820000, bhvDeathWarp),
		OBJECT(38, 13428, 4720, -4884, 0, 0, 0, 0x64000000, bhvDoor),
		OBJECT(38, -4964, 1200, -4226, 0, 0, 0, 0xa0000, bhvDoorWarp),
		// OBJECT(0, 10625, 5361, -71, 0, -180, 0, 0x14500000, bhvFadingWarp),
		// OBJECT(0, 10632, 4720, -65, 0, -180, 0, 0x14500000, bhvFadingWarp),
		// OBJECT(0, 10640, 5302, 838, 0, 0, 0, 0x145a0000, bhvFadingWarp),
		OBJECT(118, -6555, 4543, 9203, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -6529, 4496, 8544, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -6864, 4471, 7885, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -7553, 4465, 7510, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -8346, 4532, 7683, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -8876, 4584, 8198, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(124, -4986, 1680, 4851, 0, -180, 0, 0x2a0000, bhvMessagePanel),
		// OBJECT(215, 10437, 4720, 4524, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 9614, 4720, 3331, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 8421, 4720, -662, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 7601, 4720, -5470, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 12024, 4720, -5489, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 12017, 4720, -1865, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 14021, 4720, 5329, 0, 0, 0, 0x0, bhvRedCoin),
		// OBJECT(215, 12846, 4720, 1731, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(100, -8468, 4360, 6716, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -4317, 4200, 7909, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -887, 3282, 6817, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, 2331, 4472, 3553, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -3877, 1520, 1681, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -5689, 1520, 1690, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -5850, 1264, -557, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -5720, 1200, -1957, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -6299, 1200, -4590, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -3745, 1200, -4431, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -3686, 1264, -339, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -2585, 4200, 4367, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -509, 4328, 5954, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, 1479, 4328, 5634, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, 3754, 4936, 6116, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, 6422, 4720, -5399, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -5547, 4416, 8816, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -8441, 4666, 8670, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -7918, 4200, 4435, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(0, 13421, 4720, -4666, 0, 0, 0, 0x6e0000, bhvSpinAirborneWarp),
		OBJECT(0, 13426, 4720, -5136, 0, 0, 0, 0x640000, bhvWarp),
		
		OBJECT(122, -4968, 2631, 5038, 0, 0, 0, 0x0000000, bhvStar),
		OBJECT(122, 10624, 5904, -67, 0, 0, 0, 0x1000000, bhvStar),

		TERRAIN(ttc_area_1_collision),
		MACRO_OBJECTS(ttc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x3d),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ttc_area_2),
		WARP_NODE(241, LEVEL_TTC, 1, 130, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_TTC, 1, 90, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 80, WARP_NO_CHECKPOINT),
		OBJECT(0, 572, 2641, 755, 0, -180, 0, 0x14140000, bhvFadingWarp),
		OBJECT(0, -376, 2840, 847, 0, -180, 0, 0xa0000, bhvFadingWarp),
		OBJECT(0, 573, 2000, 747, 0, -180, 0, 0x14140000, bhvFadingWarp),
		// OBJECT(122, 191, 2390, -1011, 0, 0, 0, 0x5000000, bhvStar),
		
		TERRAIN(ttc_area_2_collision),
		MACRO_OBJECTS(ttc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x3d),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, ttc_area_3),
		WARP_NODE(0x0A, LEVEL_TTC, 0x01, 0xe0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_COURTYARD, 3, 40, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_TTC, 3, 0x28, WARP_NO_CHECKPOINT),
		WARP_NODE(0x28, LEVEL_TTC, 3, 0x32, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -10287, 4656, -8573, 0, 0, 0, (0xa << 16), bhvWarpPipe),
		OBJECT(0, -10409, 5466, -5968, 0, -180, 0, 0x280000, bhvFadingWarp),
		OBJECT(0, -8828, 4958, 6885, 0, -180, 0, 0x320000, bhvFadingWarp),
		// OBJECT(104, -9087, 4816, -7443, 0, 0, 0, 0x1030000, bhvKoopa),
		// OBJECT(0, -6991, 4816, 6874, 0, 0, 0, 0x0, bhvKoopaRaceEndpoint),
		OBJECT(100, -10828, 4776, -5906, 0, 0, 0, 0x0, bhvSmallBomp),
		OBJECT(100, -8648, 4958, 7302, 0, 0, 0, 0x0, bhvSmallBomp),
		
		OBJECT(122, 8816, 4612, 1004, 0, 0, 0, 0x2000000, bhvStar),

		TERRAIN(ttc_area_3_collision),
		MACRO_OBJECTS(ttc_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x3d),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, ttc_area_4),
		WARP_NODE(0x0A, LEVEL_TTC, 1, 0xe1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 1, 50, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_COURTYARD, 3, 40, WARP_NO_CHECKPOINT),
		WARP_NODE(0x1e, LEVEL_TTC, 4, 0x14, WARP_NO_CHECKPOINT),
		WARP_NODE(0x14, LEVEL_TTC, 4, 0x1e, WARP_NO_CHECKPOINT),
		WARP_NODE(0x3c, LEVEL_TTC, 4, 0x46, WARP_NO_CHECKPOINT),
		WARP_NODE(0x46, LEVEL_TTC, 4, 0x3c, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 4533, 4360, -3675, 0, -90, 0, (0xa << 16), bhvWarpPipe),
		OBJECT(0, 420, 4440, -3700, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -783, 5250, -3689, 0, 0, 0, 0x140000, bhvFadingWarp),
		OBJECT(0, -783, 2800, -9527, 0, 0, 0, 0x1e0000, bhvFadingWarp),
		OBJECT(0, -1045, 3947, 14888, 0, -180, 0, 0x3c0000, bhvFadingWarp),
		OBJECT(0, -783, 5730, -3689, 0, -180, 0, 0x460000, bhvFadingWarp),
		OBJECT(124, -3715, 2800, -7102, 0, 90, 0, 0x280000, bhvMessagePanel),
		OBJECT(100, -357, 3947, 14755, 0, 0, 0, 0x0, bhvSmallBomp),
		// OBJECT(122, -1472, 9134, -6731, 0, 0, 0, 0x4000000, bhvStar),
		// OBJECT(122, -1057, 4249, 14353, 0, 0, 0, 0x3000000, bhvStar),
		
		OBJECT(122, -11090 + 10000, 6679, 9261, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -13671 + 10000, 9360, -8183, 0, 0, 0, 0x4000000, bhvStar),

		TERRAIN(ttc_area_4_collision),
		MACRO_OBJECTS(ttc_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x3d),
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
