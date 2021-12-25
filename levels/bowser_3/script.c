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
#include "levels/bowser_3/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_3_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bowser_3_segment_7SegmentRomStart, _bowser_3_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_1, bowser_3_geo_000290), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_2, bowser_3_geo_0002A8), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_3, bowser_3_geo_0002C0), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_4, bowser_3_geo_0002D8), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_5, bowser_3_geo_0002F0), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_6, bowser_3_geo_000308), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_7, bowser_3_geo_000320), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_8, bowser_3_geo_000338), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_9, bowser_3_geo_000350), 
	LOAD_MODEL_FROM_GEO(MODEL_BOWSER_3_FALLING_PLATFORM_10, bowser_3_geo_000368), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bowser_3_geo_000380), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_3_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_BITS, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_KING_BOBOMB, 0, 843, -15, 0, 0, 0, 0x00000000, bhvKingBobomb),
		OBJECT(MODEL_NONE, -7, 843, -16, 0, 0, 0, 0x00000000, bhvKingBobombCtl),
		MARIO_POS(0x01, 0, 8, 843, -2634),
		OBJECT(MODEL_NONE, 15, 843, -2636, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		TERRAIN(bowser_3_area_1_collision),
		MACRO_OBJECTS(bowser_3_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_F2),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 8, 843, -2634),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
