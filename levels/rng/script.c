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
#include "levels/rng/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_rng_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _rng_segment_7SegmentRomStart, _rng_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_MUSHROOM, rng_mushroom_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_PYRAMID, rng_pyramid_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_SHAPE1, rng_shape1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_SHAPE2, rng_shape2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_SHAPE3, rng_shape3_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_SHAPE4, rng_shape4_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_CACTUS, rng_cactus_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_AGLAB_RNG_CACTUS2, rng_cactus2_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, rng_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_RNG, 7, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 461, 2856, 4670, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 449, 2853, 4671, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 483, 2550, -3233, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 451, 2867, 4699, 0, -180, 0, 0x00000000, bhvAglabRng),
		OBJECT(MODEL_STAR, 207, 2844, -3240, 0, 0, 0, (4 << 24), bhvStar),
		TERRAIN(rng_area_1_collision),
		MACRO_OBJECTS(rng_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, rng_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_RNG, 3, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 2, 0xf1, WARP_NO_CHECKPOINT),
		MARIO_POS(4, -180, 4222, 2550, -1125),
		OBJECT(MODEL_NONE, 4266, 2779, -1109, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 4256, 2833, -1154, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_WOODEN_SIGNPOST, 4252, 2550, -1381, 0, 0, 0, (60 << 24) | (60 << 16), bhvMessagePanel),
		OBJECT(MODEL_THI_WARP_PIPE, 4249, 2550, -9041, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 4287, 2752, -1140, 0, -180, 0, 0x00000000, bhvAglabRng),
		OBJECT(MODEL_STAR, 3932, 2835, -9049, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(rng_area_2_collision),
		MACRO_OBJECTS(rng_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(3, rng_area_3),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_RNG, 6, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 3, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 197, 2917, 5582, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 190, 2919, 5586, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 153, 2550, -2303, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 161, 2922, 5594, 0, -180, 0, 0x00000000, bhvAglabRng),
		OBJECT(MODEL_STAR, -162, 2809, -2311, 0, 0, 0, (1 << 24), bhvStar),
		TERRAIN(rng_area_3_collision),
		MACRO_OBJECTS(rng_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(4, rng_area_4),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_RNG, 5, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 4, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 1477, 2318, 2186, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 1474, 2309, 2178, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 1476, 4594, -5711, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 1451, 2320, 2164, 0, -180, 0, 0x00000000, bhvAglabRng),
		OBJECT(MODEL_STAR, 1187, 5016, -5698, 0, 0, 0, (2 << 24), bhvStar),
		TERRAIN(rng_area_4_collision),
		MACRO_OBJECTS(rng_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(5, rng_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_RNG, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 5, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 168, 2302, 4502, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 176, 2299, 4500, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 217, 1969, -3392, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 169, 2301, 4497, 0, -180, 0, 0x00000000, bhvAglabRng),
		OBJECT(MODEL_STAR, -142, 2191, -3410, 0, 0, 0, (3 << 24), bhvStar),
		TERRAIN(rng_area_5_collision),
		MACRO_OBJECTS(rng_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(6, rng_area_6),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xB, LEVEL_RNG, 4, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 6, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2203, 2273, 4814, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 2191, 2273, 4813, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, 2159, 1969, -3072, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 2189, 2266, 4844, 0, -180, 0, 0x00000000, bhvAglabRng),
		OBJECT(MODEL_STAR, 1915, 2323, -3088, 0, 0, 0, (5 << 24), bhvStar),
		TERRAIN(rng_area_6_collision),
		MACRO_OBJECTS(rng_area_6_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(7, rng_area_7),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_COURTYARD, 0x01, 0x30, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_RNG, 7, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 225, 2325, 4021, 0, -180, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 225, 2323, 4019, 0, -180, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_STAR, 181, 2334, -3864, 0, 0, 0, (6 << 24), bhvStar),
		OBJECT(MODEL_NONE, 225, 2311, 3971, 0, -180, 0, 0x00000000, bhvAglabRng),
		TERRAIN(rng_area_7_collision),
		MACRO_OBJECTS(rng_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(4, -180, 4222, 2550, -1125),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
