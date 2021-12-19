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
#include "actors/group12.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/bowser_1/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bowser_1_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bowser_1_segment_7SegmentRomStart, _bowser_1_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _machine_yay0SegmentRomStart, _machine_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PUSH_BLOCK, ttc_geo_0002C8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_HEXAGON, ttc_geo_0002E0), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_TRIANGLE, ttc_geo_0002F8), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bowser_1_area_1),
		OBJECT(MODEL_BLACK_BOBOMB, 1336, 1658, -262, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 4086, 385, 1655, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 5390, 2973, -1128, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -4249, 1475, -848, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHAIN_CHOMP, 816, 1658, 1693, 0, 0, 0, 0x00000000, bhvChainChomp),
		OBJECT(MODEL_NONE, 860, 1334, -7989, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4794, 1691, -1705, -162, 0, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_BOWLING_BALL, 838, 1506, -3403, 0, 0, 0, (2 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 3212, 1643, 1742, 0, 0, 0, (2 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 5428, 2973, 3548, 0, 0, 0, (2 << 16), bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -945, 1519, 3462, 0, 0, 0, (2 << 16), bhvFireSpitter),
		OBJECT(MODEL_NONE, 922, 1499, -8737, 0, 0, 0, 0x00000000, bhvKingBobomb),
		MARIO_POS(0x01, 0, 855, 1334, -8001),
		OBJECT(MODEL_TTC_PUSH_BLOCK, 5136, 300, 1074, 0, 0, 0, 0x00000000, bhvTTCMovingBar),
		OBJECT(MODEL_TTC_PUSH_BLOCK, 5619, 300, 270, 0, 0, 0, 0x00000000, bhvTTCMovingBar),
		OBJECT(MODEL_TTC_PUSH_BLOCK, 5382, 300, -596, 0, 0, 0, 0x00000000, bhvTTCMovingBar),
		OBJECT(MODEL_TTC_ROTATING_TRIANGLE, 5401, 295, -3514, -90, 0, 0, (TTC_COG_BP_SHAPE_TRIANGLE << 16), bhvTTCCog),
		OBJECT(MODEL_TTC_ROTATING_HEXAGON, 5391, 358, -2352, 0, 0, 0, (TTC_COG_BP_SHAPE_HEXAGON << 16), bhvTTCCog),
		OBJECT(MODEL_STAR, -2934, 2512, -2428, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_THWOMP, 5379, 2973, -339, 0, 0, 0, 0x00000000, bhvThwomp),
		TERRAIN(bowser_1_area_1_collision),
		MACRO_OBJECTS(bowser_1_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 855, 1334, -8001),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
