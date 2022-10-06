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
	LOAD_MODEL_FROM_GEO(MODEL_TRIARC_ROCK, triarc_rock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TRIARC_COMB, triarc_comb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TRIARC_GRASS1, triarc_plat0_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TRIARC_GRASS2, triarc_plat1_geo), 
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
		WARP_NODE(0x12, LEVEL_ROVERT, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x13, LEVEL_LUIGIMAN, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x23, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x33, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0xf0, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 4667, 169, 3871, 0, 0, 0, (0x31 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 5227, 169, -2913, 0, 0, 0, (0x32 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 5215, -64, 1643, 0, 0, 0, 0x00000000, bhvOWCtl2),
		OBJECT(MODEL_NONE, -4259, 169, 1921, 0, 0, 0, (0x33 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -5443, 521, -3787, 0, 0, 0, (0x30 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -5413, -64, -3307, 0, 0, 0, (0x10 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 4788, -64, 4321, 0, 0, 0, (0x11 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 5263, -64, -2499, 0, 0, 0, (0x12 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -4317, -64, 2324, 0, 0, 0, (0x13 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -5413, -64, -3307, 0, 0, 0, 0x00000000, bhvSparkler),
		OBJECT(MODEL_RED_COIN, 2943, 1202, 7575, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3607, 2424, 106, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3243, 1936, 4122, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1785, -339, -6024, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2727, 1199, -3017, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2706, 1799, 3240, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2959, 1761, 82, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1469, 226, 3219, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 41, 452, 92, 0, 0, 0, (1 << 24), bhvBowserCourseRedCoinStar),
		OBJECT(MODEL_NONE, 41, 454, 86, 0, 0, 0, (0xf1 << 16), bhvDeathWarp),
		MARIO_POS(0x01, 0, 5673, 455, 6728),
		OBJECT(MODEL_NONE, -5676, 383, -6365, 0, -28, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_THI_WARP_PIPE, -5473, 86, -6942, 0, -28, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -5445, 523, -3783, 0, 0, 0, (0x20 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 4665, 171, 3874, 0, 0, 0, (0x21 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, 5225, 171, -2910, 0, 0, 0, (0x22 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_NONE, -4261, 171, 1924, 0, 0, 0, (0x23 << 16), bhvAirborneStarCollectWarp),
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
