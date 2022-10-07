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
#include "levels/Dan/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_Dan_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _Dan_segment_7SegmentRomStart, _Dan_segment_7SegmentRomEnd),
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd),
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd),
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd),
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd),
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_4),
	JUMP_LINK(script_func_global_15),
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, dan_bp_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, dan_slip_lines_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, dan_sky_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, dan_bird_geo),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, Dan_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_DAN, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 6659, 535, -10, 0, 270, 0, 0x00f10000, bhvDeathWarp),
		OBJECT(MODEL_NONE, 6659, 535, -10, 0, 270, 0, 0x000a0000, bhvAirborneWarp),
		OBJECT(MODEL_LEVEL_GEOMETRY_03, 4565, 209, -1400, 0, 180, 0, 0x00000000, Dan_BhvBP),
		OBJECT(MODEL_STAR, -21400, 1200, -1300, 0, 7401, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, 6933, 268, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(Dan_area_1_collision),
		MACRO_OBJECTS(Dan_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 6933, 268, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
