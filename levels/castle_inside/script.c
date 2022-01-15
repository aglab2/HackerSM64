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
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
	JUMP_LINK(script_func_global_1), 
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
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_SA, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xc, LEVEL_CASTLE, 0x3, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -6831, 165, 3228, 0, 0, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_MR_I, -8271, 1059, 4623, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -6085, 165, 2037, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -6077, 165, -71, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -4455, 165, 512, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -3044, 165, -113, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 1171, -323, -1310, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_NONE, -6887, 225, 3589, 0, 62, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -7910, 1217, 4966, 0, 62, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 7256, -856, -1041, 0, 0, 0, (0xb << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 7217, -856, 651, 0, 0, 0, (-1 << 24) | (0xc << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 7258, -468, -701, 0, 0, 0, (0x22 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 7256, -468, -703, 0, 0, 0, (0x21 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, 7458, -594, -196, 0, 0, 0, (2 << 16), bhvExclamationBox),
		OBJECT(MODEL_TOAD, 820, -323, -2044, 0, 0, 0, (76 << 24), bhvToadMessage),
		OBJECT(MODEL_EXCLAMATION_BOX, -40, -12, -2367, 0, 0, 0, (2 << 16), bhvExclamationBox),
		OBJECT(MODEL_MR_I, 5208, -856, -154, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 5767, -856, -588, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 5794, -856, 261, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 4399, -856, 248, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 4408, -856, -623, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, 3156, -633, -226, 0, 0, 0, 0x00000000, bhvMrI),
		OBJECT(MODEL_MR_I, -6784, 165, 593, 0, 0, 0, 0x00000000, bhvMrI),
		MARIO_POS(0x01, 78, -6839, 165, 3163),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_OW1),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, castle_inside_area_2),
		WARP_NODE(0x91, LEVEL_CASTLE, 3, 0x90, WARP_NO_CHECKPOINT),
		WARP_NODE(0x92, LEVEL_CASTLE, 3, 0x91, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(9, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(10, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(11, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(12, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(13, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(14, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(15, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(16, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(17, LEVEL_BBH, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x41, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x42, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x51, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x52, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x70, LEVEL_PSS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x71, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x72, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x60, LEVEL_TOTWC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x61, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x62, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xa0, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xa1, LEVEL_CASTLE_COURTYARD, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0xf0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x80, LEVEL_BITFS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x81, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x82, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT_WITH_ACTS(MODEL_CASTLE_GROUNDS_METAL_DOOR, 2956, -5002, 9230, 0, 0, 0, (0xa << 16), bhv1Up, 0),
		OBJECT_WITH_ACTS(MODEL_CASTLE_GROUNDS_METAL_DOOR, 2956, -4600, 8858, 0, 0, 0, (0xa << 16), bhv1Up, 0),
		OBJECT(MODEL_NONE, 436, -3427, -614, 0, -90, 0, (0x32 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 3335, -2629, -6393, 0, 90, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 296, -3382, -583, 0, -90, 0, (0x31 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 7880, -3833, 4843, 0, 90, 0, (0x42 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 7888, -3831, 4870, 0, 90, 0, (0x41 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 3223, -4750, 9045, 0, -90, 0, (0x52 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 3229, -4767, 9035, 0, -90, 0, (0x51 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 4604, -5240, 12693, 0, -180, 0, (3 << 24) | (0xa0 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3340, -2975, -7320, 0, 0, 0, (0x92 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3474, -2975, -7321, 0, -180, 0, (0x91 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 4505, -5240, 7166, 0, -180, 0, (14 << 24), bhvDoor),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 4467, -5240, 12691, 0, 0, 0, (3 << 24) | (0xa1 << 16), bhvDoorWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 1904, -3069, 3976, 0, 0, 0, (0x70 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 2341, -2892, 3977, 0, 0, 0, (0x72 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 2367, -2860, 3965, 0, 0, 0, (0x71 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_TOAD, 8077, -3840, 12290, 0, -180, 0, (82 << 24), bhvToadMessage),
		OBJECT(MODEL_THI_WARP_PIPE, 8807, -5240, 11077, 0, -180, 0, (0x80 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 9422, -6190, 4798, 0, 0, 0, (0x60 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 9101, -5887, 4764, 0, 88, 0, (0x62 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 8497, -4914, 11077, 0, 88, 0, (0x82 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 9126, -5895, 4757, 0, 88, 0, (0x61 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 8522, -4922, 11069, 0, 88, 0, (0x81 << 16), bhvAirborneStarCollectWarp),
		TERRAIN(castle_inside_area_2_collision),
		MACRO_OBJECTS(castle_inside_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_OW1),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, castle_inside_area_3),
		WARP_NODE(0x0A, LEVEL_CASTLE, 0x01, 0xc, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(2, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x12, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(3, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(4, LEVEL_WF, 1, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(5, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x80, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x81, LEVEL_CASTLE_GROUNDS, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(6, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(7, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(8, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x90, LEVEL_CASTLE, 2, 0x91, WARP_NO_CHECKPOINT),
		WARP_NODE(0x91, LEVEL_CASTLE, 2, 0x92, WARP_NO_CHECKPOINT),
		WARP_NODE(0xa0, LEVEL_CASTLE, 4, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 3, 0xf0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 3, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1602, 2474, -783, 0, 89, 0, (0x12 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -3910, 2509, -2682, 0, 89, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 1606, 2457, -809, 0, 89, 0, (0x11 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -3907, 2492, -2708, 0, 89, 0, (0xf0 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 1882, 3424, -2967, 0, 159, 0, (0x22 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 1869, 3424, -2963, 0, 159, 0, (0x21 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -3658, 2032, -3148, 0, 0, 0, (0xa << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3118, 2971, -885, 0, -90, 0, (-4 << 24) | (0x80 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3121, 2971, -733, 0, 90, 0, (-4 << 24) | (0x81 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -4137, 2032, 1691, 0, 0, 0, (2 << 24) | (0x91 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -3997, 2032, 1693, 0, -180, 0, (2 << 24) | (0x90 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 1078, 3052, -817, 0, 89, 0, (130 << 16), bhvPoleGrabbing),
		OBJECT(MODEL_NONE, 1776, 3596, 1545, 0, 26, 0, (0x32 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 1781, 3596, 1544, 0, 26, 0, (0x31 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 1078, 4223, -817, 0, 89, 0, (0xa0 << 16), bhvWarp),
		OBJECT(MODEL_NONE, -3746, 866, 4532, 0, 89, 0, (130 << 16), bhvWarp),
		TERRAIN(castle_inside_area_3_collision),
		MACRO_OBJECTS(castle_inside_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_OW1),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, castle_inside_area_4),
		WARP_NODE(0x0A, LEVEL_CASTLE, 3, 0xa0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 3, 0xf0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 3, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1640, -1073, -550, 0, 89, 0, (200 << 16), bhvDddMovingPole),
		OBJECT(MODEL_NONE, 1640, 19, -550, 0, 0, 0, (10 << 24) | (0xa << 16), bhvWarp),
		OBJECT(MODEL_TOAD, -950, 0, 61, 0, 87, 0, (83 << 24), bhvToadMessage),
		TERRAIN(castle_inside_area_4_collision),
		MACRO_OBJECTS(castle_inside_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_OW1),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 78, -6839, 165, 3163),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
