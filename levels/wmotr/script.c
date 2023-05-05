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
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wmotr_area_1),
		WARP_NODE(241, LEVEL_WMOTR, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_WMOTR, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_CASTLE, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, -102, -2659, 20, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -983, -2837, -1510, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -11, -4009, 1377, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 600, -4009, 1377, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -376, 2610, 478, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -376, 2538, 399, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(194, 236, 2700, -704, 0, 0, 0, 0x0, bhvCirclingAmp),
		OBJECT(0, -1660, 2010, 83, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 552, 5010, 557, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(137, 264, 4890, 2756, 0, 0, 0, 0x70000, bhvExclamationBox),
		OBJECT(137, 264, 4890, -2612, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(180, 239, 4660, -29, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 239, 4660, 1120, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, -693, 2660, -711, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(220, 2608, 3060, -378, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, 2519, 3060, 718, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, -586, -3060, -808, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, 831, -3810, 423, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(0, 1252, -3780, -89, 0, 0, 0, 0x1000000, bhvHiddenRedCoinStar),
		OBJECT(194, 245, 4740, -988, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(194, 245, 4740, 2051, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(124, 2350, 2500, -4, 0, -90, 0, 0x330000, bhvMessagePanel),
		OBJECT(124, -2038, 2350, 389, 0, -180, 0, 0x490000, bhvMessagePanel),
		OBJECT(0, -2082, 2580, -553, 0, -90, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, -2089, 2580, -562, 0, -90, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, 148, 2475, 520, 90, -90, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(215, -994, -3870, 23, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1020, -4560, 1109, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1255, -3060, -717, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 277, -3210, -1360, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 1233, -4170, 1354, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 848, -4170, -318, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 843, -3750, -723, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 319, -3600, 1378, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -1678, 2350, -527, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 1304, 3930, 683, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, 1795, -1740, -557, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(22, -1920, 2350, 742, 0, 0, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, 0),
		SET_BACKGROUND_MUSIC(0x00, 24),
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
