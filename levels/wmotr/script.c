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
#include "actors/group0.h"

#include "make_const_nonconst.h"
#include "levels/wmotr/header.h"

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BITDW_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_RIFT, rift_geo), 

	AREA(1, wmotr_area_1),
		INSTANT_WARP(0x00, 0x02, 0, 0, 0),
		WARP_NODE(0x01, LEVEL_WMOTR, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CASTLE_WOODEN_DOOR, -1492, -253, -13, 0, 90, 0, 0x00000000, bhvDoor),
		OBJECT(MODEL_WOODEN_SIGNPOST, -1447, -253, 362, 0, 0, 0, 0x008A0000, bhvMessagePanel),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_ARENA),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(2, wmotr_area_2),
		INSTANT_WARP(0x00, 0x02, 0, -678, 0),
		INSTANT_WARP(0x01, 0x02, 0, 682, 0),
		TERRAIN(wmotr_area_2_collision),
		MACRO_OBJECTS(wmotr_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_ARENA),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(3, wmotr_area_3),
		INSTANT_WARP(0x00, 0x02, 0, 0, 0),
		OBJECT(MODEL_WOODEN_SIGNPOST, -1964, 3602, 257, 0, -90, 0, 0x008B0000, bhvMessagePanel),
		TERRAIN(wmotr_area_3_collision),
		MACRO_OBJECTS(wmotr_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_ARENA),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(4, wmotr_area_4),
		WARP_NODE(0x01, LEVEL_WMOTR, 0x05, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -4003, 3891, -7, 0, 90, 0, 0x00010000, bhvWarp),
		OBJECT(MODEL_NONE, -4003, 4529, -7, 0, 90, 0, 0x00010000, bhvWarp),
		OBJECT(MODEL_NONE, -4003, 4742, -7, 0, 90, 0, 0x00010000, bhvWarp),
		OBJECT(MODEL_RIFT, -4003, 4316, -7, 0, 90, 0, 0x00010000, bhvWarp),
		OBJECT(MODEL_NONE, -4003, 4103, -7, 0, 90, 0, 0x00010000, bhvWarp),
		TERRAIN(wmotr_area_4_collision),
		MACRO_OBJECTS(wmotr_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_ARENA),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	AREA(5, wmotr_area_5),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x00, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -2133, 30, -1001, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, -2133, 206, -13, 0, 0, 0, 0x00000000, bhvStar),
		TERRAIN(wmotr_area_5_collision),
		MACRO_OBJECTS(wmotr_area_5_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_TIME),
		TERRAIN_TYPE(TERRAIN_GRASS),
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
