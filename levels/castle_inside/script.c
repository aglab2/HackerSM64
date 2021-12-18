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
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_16), 
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
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_SA, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xc, LEVEL_CASTLE, 0x3, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -6831, 165, 3228, 0, 0, 0, 0x00000000, bhvDeathWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 7256, -856, -1041, 0, 0, 0, 0x00000000, bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 7217, -856, 651, 0, 0, 0, 0x00000000, bhvDoorWarp),
		MARIO_POS(0x01, 0, 6783, -856, -184),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, castle_inside_area_2),
		TERRAIN(castle_inside_area_2_collision),
		MACRO_OBJECTS(castle_inside_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
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
		WARP_NODE(0x81, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(6, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(7, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(8, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT_WITH_ACTS(MODEL_CASTLE_GROUNDS_METAL_DOOR, 1822, 3876, 1958, 0, 0, 0, 0x00000000, bhv1Up, 0),
		OBJECT_WITH_ACTS(MODEL_CASTLE_GROUNDS_METAL_DOOR, 2247, 3392, 1782, 0, 0, 0, 0x00000000, bhv1Up, 0),
		OBJECT(MODEL_NONE, 1591, 2474, -798, 0, 0, 0, (0x12 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 1524, 2511, -822, 0, 0, 0, (0x11 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 1870, 3424, -2961, 0, 0, 0, (0x22 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 1881, 3424, -2969, 0, 0, 0, (0x21 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -3658, 2032, -3148, 0, 0, 0, 0x00000000, bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3118, 2971, -885, 0, -90, 0, (-7 << 24) | (0x80 << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, 3121, 2971, -733, 0, 90, 0, (-7 << 24) | (0x81 << 16), bhvDoorWarp),
		TERRAIN(castle_inside_area_3_collision),
		MACRO_OBJECTS(castle_inside_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 6783, -856, -184),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
