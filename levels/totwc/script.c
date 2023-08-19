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
	LOAD_MIO0(0xa, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, totwc_geo_000160), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, totwc_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_GROUNDS, 1, 102, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_GROUNDS, 1, 118, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_BOB, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BOB, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_TOTWC, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(0, -683, 507, 4580, 0, 0, 0, 0x0, bhvBowserCourseRedCoinStar),
		OBJECT(85, 1499, 1833, 3490, 0, 0, 0, 0x0, bhvCapSwitch),
		OBJECT(0, 3520, 313, 4462, 0, 90, 0, 0x0, bhvCheckerboardElevatorGroup),
		OBJECT(223, 1476, -1890, -54, 0, 107, 0, 0x0, bhvChuckya),
		OBJECT(223, -564, 1504, -2132, 0, -151, 0, 0x0, bhvChuckya),
		OBJECT(137, -627, 2198, 4038, 0, 0, 0, 0x0, bhvExclamationBox),
		OBJECT(0, -323, 2808, 436, 0, -154, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -563, -1400, 148, 0, -153, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 435, 90, 4547, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1412, -609, 2860, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(215, 2276, -3003, -3947, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2573, -1888, -4103, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1199, 1452, -2695, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1217, -1400, -602, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3759, -609, 3518, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 100, 3130, -340, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3920, 1931, 4140, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3057, 1521, 3223, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 1520, -3003, -4379, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -4640, 5053, 534, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(23, -1120, -1400, 610, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, -304, -609, 3016, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, 2162, -3003, -3306, 0, 0, 0, 0x0, bhvTree),
		OBJECT(116, -1787, 1820, 3654, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4260, 1150, 2303, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5132, 865, 1664, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5732, 706, 499, 0, 0, 0, 0x0, bhvYellowCoin),
		TERRAIN(totwc_area_1_collision),
		MACRO_OBJECTS(totwc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 48),
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
