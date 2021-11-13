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
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_14), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf2, LEVEL_ENDING, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 0x01, 0xb, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 1, 0xc, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_NONE, 0, -3, 1, 0, 0, 0, 0x00000000, bhvFightCtl),
		OBJECT(MODEL_PURPLE_SWITCH, 0, -160, 2400, 0, 0, 0, 0x00000000, bhvFightFloorSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, 0, -160, -2400, 0, 0, 0, 0x00000000, bhvFightFloorSwitch),
		OBJECT(MODEL_STAR, 1193, 138, 1202, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_STAR, -1216, 138, 1202, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_STAR, -1216, 138, -1196, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_STAR, 1182, 138, -1196, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 1198, -160, -2401, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, -1208, -160, -2401, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 0, -160, -1203, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 0, -160, 0, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 1185, -160, 2, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 1185, -160, 2399, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, -1228, -160, 2399, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, -1228, -160, 8, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 0, -160, 1221, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, -190, -160, 0, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 190, -160, 0, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 190, -160, -190, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 190, -160, 190, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 0, -190, 190, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, -190, -160, 190, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, -190, -160, -190, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_TRANSPARENT_STAR, 0, -160, -190, 0, 0, 0, (10 << 24), bhvStar),
		OBJECT(MODEL_NONE, -10, 311, 3739, 0, 0, 0, (0xa << 16), bhvSpinAirborneWarp),
		TERRAIN(sa_area_1_collision),
		MACRO_OBJECTS(sa_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
