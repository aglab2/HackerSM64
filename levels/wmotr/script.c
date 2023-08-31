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
#include "levels/wmotr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wmotr_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_VCUTM, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_WMOTR, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_ENDING, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_WMOTR, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_WMOTR, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_WMOTR, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(0, -6895, -1501, 0, 0, 90, 0, 0xf10000, bhvDeathWarp),
		OBJECT(137, 3843, 336, 200, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(0, -1065, -1238, 0, 0, 0, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, 4300, -29, 0, 0, -90, 0, 0xc0000, bhvFadingWarp),
		OBJECT(120, -3300, -1440, -200, 0, 90, 0, 0x0, bhvRecoveryHeart),
		OBJECT(0, -6895, -1709, 0, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -1800, -336, 0, 0, 0, 0, 0, bhvStar),
		OBJECT(221, -3187, -771, -226, 0, -30, 0, 0x58000000, bhvToadMessage),
		OBJECT(221, -2964, -771, -318, 0, -30, 0, 0x56000000, bhvToadMessage),
		OBJECT(221, -2098, -771, 380, 0, -140, 0, 0x59000000, bhvToadMessage),
		OBJECT(221, -2900, -771, 288, 0, -180, 0, 0x57000000, bhvToadMessage),
		OBJECT(221, -6616, -1709, -321, 0, -45, 0, 0x55000000, bhvToadMessage),
		OBJECT(22, -3300, -1500, 200, 0, 0, 0, 0x0, bhvWarpPipe),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 42),
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
