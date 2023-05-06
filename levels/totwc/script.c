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
#include "levels/totwc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_totwc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _totwc_segment_7SegmentRomStart, _totwc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _clouds_skybox_mio0SegmentRomStart, _clouds_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, totwc_geo_000160), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, totwc_area_1),
		WARP_NODE(241, LEVEL_TOTWC, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_TOTWC, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_CASTLE_COURTYARD, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(21, LEVEL_TOTWC, 1, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_TOTWC, 1, 21, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 510, 2190, -4433, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(212, -306, -2820, 1519, 0, 40, 0, 0x0, bhv1Up),
		OBJECT(212, 135, -2094, -4421, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(212, -1589, 96, -2100, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(212, -1589, 96, -2000, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(212, -1589, 96, -1900, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(212, 3664, -1284, -203, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(212, 1941, -954, 814, 0, -180, 0, 0x0, bhv1Up),
		OBJECT(85, 838, 2775, 1003, 0, 0, 0, 0x0, bhvCapSwitch),
		OBJECT(223, 716, 3825, -730, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -1002, 4675, -736, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, -1568, 2350, -1364, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 1311, 2350, 1599, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, 297, 2954, -4414, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(137, -886, 5730, 1004, 0, 0, 0, 0x80000, bhvExclamationBox),
		OBJECT(137, -26, 2730, -744, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(137, 442, -840, -3714, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(137, -570, -3270, 1547, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(0, -569, -4280, 669, 0, 0, 0, 0x1140000, bhvFadingWarp),
		OBJECT(0, -919, 2680, 154, 0, 0, 0, 0x1150000, bhvFadingWarp),
		OBJECT(220, 337, 1110, -3310, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(220, 356, -780, -2955, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(124, -1270, 2350, 1426, 0, 39, 0, 0x490000, bhvMessagePanel),
		OBJECT(0, 21, 2790, 299, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 15, 2790, 300, 0, 0, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, 1133, 3835, -906, 90, 30, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, 0, 2670, 0, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -581, -2520, 1084, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 1364, 720, -3721, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(22, -1498, 2350, 1606, 0, 0, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(totwc_area_1_collision),
		MACRO_OBJECTS(totwc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 17),
		SHOW_DIALOG(0x00, DIALOG_000),
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
