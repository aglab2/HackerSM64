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


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/sphere/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sphere_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _sphere_segment_7SegmentRomStart, _sphere_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_SPHERE_SPHERE, sphere_sphere_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sphere_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_CASTLE, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_CASTLE, 0x01, 0x35, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 506, 5166),
		OBJECT(MODEL_NONE, 0, 506, 5160, 0, 180, 0, 0x000A0000, bhvAirborneWarp),
		OBJECT(MODEL_SPHERE_SPHERE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvAglabSphere),
		OBJECT(MODEL_STAR, 0, 0, 2257, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(sphere_area_1_collision),
		MACRO_OBJECTS(sphere_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STT),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 506, 5166),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
