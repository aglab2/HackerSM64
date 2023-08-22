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
#include "levels/sa/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sa_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_SSL, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_SSL, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_SA, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, -5190, -1346, 2483, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -3688, -1346, 2483, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(137, -4415, 890, -4200, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(0, 583, 2683, -5387, 0, -154, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, 1680, 3835, -5523, 0, -153, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(192, -1402, -333, 5986, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(0, -4764, -363, 216, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		// OBJECT(124, -3465, -360, -770, 0, -45, 0, 0x7d0000, bhvMessagePanel),
		OBJECT(0, -3270, -259, 900, 0, -90, 0, 0x220000, bhvSignOnWall),
		OBJECT(0, -6200, -363, 203, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -4425, 100, 6670, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, -1368, -28, 5680, 0, 0, 0, 0x0, bhvStar),
		OBJECT(0, 0, -1000, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 1105, 117, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, -1000, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, -1000, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, -1000, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, -1000, 0, 0, 0, 0, 0x0, bhvStarDoor),
		OBJECT(0, 0, -1000, 0, 0, 0, 0, 0x0, bhvStarDoor),
		TERRAIN(sa_area_1_collision),
		MACRO_OBJECTS(sa_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 47),
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
