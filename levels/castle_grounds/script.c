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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_grounds_geo_0006F4), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_VCUTM_GRILL, castle_grounds_geo_00070C), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_FLAG, castle_grounds_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_CANNON_GRILL, castle_grounds_geo_000724), 
	LOAD_MODEL_FROM_GEO(0xf0, panel0_geo), 
	LOAD_MODEL_FROM_GEO(0xf1, panel1_geo), 
	LOAD_MODEL_FROM_GEO(0xf2, panel2_geo), 
	LOAD_MODEL_FROM_GEO(0xf3, panel3_geo), 
	LOAD_MODEL_FROM_GEO(0xf4, panel4_geo), 
	LOAD_MODEL_FROM_GEO(0xf5, panel5_geo), 
	LOAD_MODEL_FROM_GEO(0xf6, panel6_geo), 
	LOAD_MODEL_FROM_GEO(0xf7, panel7_geo), 
	LOAD_MODEL_FROM_GEO(0xf8, panel8_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, 2385, 405, -688, 0, 157, 0, (0 << 24) | (0 << 16), bhvPlayer),
		OBJECT(MODEL_BLACK_BOBOMB, 947, 529, -2788, 0, 179, 0, (0 << 24) | (0 << 16), bhvPlayer),
		OBJECT(MODEL_BLACK_BOBOMB, 2245, 405, -771, 0, 152, 0, (0 << 24) | (1 << 16), bhvPlayer),
		OBJECT(MODEL_BLACK_BOBOMB, 2108, 405, -853, 0, 154, 0, (0 << 24) | (2 << 16), bhvPlayer),
		OBJECT(MODEL_BLACK_BOBOMB, 1972, 405, -935, 0, 151, 0, (0 << 24) | (3 << 16), bhvPlayer),
		OBJECT(MODEL_BLACK_BOBOMB, 1841, 405, -1017, 0, 153, 0, (0 << 24) | (4 << 16), bhvPlayer),
		OBJECT(MODEL_GOOMBA, 1844, 405, -4645, 0, 24, 0, (1 << 24) | (0 << 16), bhvPlayer),
		OBJECT(MODEL_GOOMBA, 946, 529, -3153, 0, 1, 0, (1 << 24) | (0 << 16), bhvPlayer),
		OBJECT(MODEL_GOOMBA, 1988, 405, -4713, 0, 27, 0, (1 << 24) | (1 << 16), bhvPlayer),
		OBJECT(MODEL_GOOMBA, 2139, 405, -4784, 0, 24, 0, (1 << 24) | (2 << 16), bhvPlayer),
		OBJECT(MODEL_GOOMBA, 2282, 405, -4852, 0, 24, 0, (1 << 24) | (3 << 16), bhvPlayer),
		OBJECT(MODEL_GOOMBA, 2429, 405, -4918, 0, 30, 0, (1 << 24) | (4 << 16), bhvPlayer),
		MARIO_POS(0x01, 0, 2989, 5, -2875),
		OBJECT(MODEL_NONE, 700, 40, -2965, 0, -91, 0, (1 << 24) | (0 << 16), bhvCtl),
		OBJECT(MODEL_NONE, 2182, 40, -3937, 0, 24, 0, (1 << 24) | (0 << 16), bhvCtlChoice),
		OBJECT(MODEL_NONE, 2182, 40, -1604, 0, 24, 0, (0 << 24) | (0 << 16), bhvCtlChoice),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 2989, 5, -2875),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
