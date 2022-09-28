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
	LOAD_MIO0(0x7, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
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
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x10, LEVEL_SPIDERS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x11, LEVEL_RNG, 2, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 4666, 132, 5364, 0, 0, 0, (0x30 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 4960, 169, 2030, 0, 0, 0, (0x31 << 16), bhvDeathWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 4878, -64, 4862, 0, 0, 0, (0x10 << 16), bhvWarpPipe),
		OBJECT(MODEL_THI_WARP_PIPE, 4902, -64, 2138, 0, 0, 0, (0x11 << 16), bhvWarpPipe),
		OBJECT(MODEL_RED_COIN, 2943, 1202, 7575, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3607, 2424, 106, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3243, 1936, 4122, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3214, 1486, -1660, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2727, 1199, -3017, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2706, 1799, 3240, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2959, 1761, 82, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1469, 226, 3219, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 41, 452, 92, 0, 0, 0, (1 << 24), bhvHiddenRedCoinStar),
		MARIO_POS(0x01, 0, 5673, 455, 6728),
		OBJECT(MODEL_NONE, 5695, 486, 6745, 0, 0, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 4664, 134, 5367, 0, 0, 0, (0x20 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 4958, 171, 2033, 0, 0, 0, (0x21 << 16), bhvAirborneStarCollectWarp),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_PSYNC),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 5673, 455, 6728),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
