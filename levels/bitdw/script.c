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
#include "levels/bitdw/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitdw_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bidw_skybox_yay0SegmentRomStart, _bidw_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bitdw_segment_7SegmentRomStart, _bitdw_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitdw_area_1),
		WARP_NODE(241, LEVEL_BITDW, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITDW, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BITS, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 1284, 2160, 41, 0, 94, 0, 0x0, bhv1Up),
		OBJECT(212, -1444, 990, -4466, 0, 94, 0, 0x0, bhv1Up),
		OBJECT(212, -744, -4590, 2581, 0, 94, 0, 0x0, bhv1Up),
		OBJECT(0, 2114, -1380, 3109, 0, -180, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2114, 0, 3109, 0, -180, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2584, -2580, -2469, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2673, -1230, -2558, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2798, 60, -2733, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 2894, 930, -2815, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -3841, 690, -905, 0, 94, 0, 0x110000, bhvCoinFormation),
		OBJECT(124, -225, 3789, 269, 0, 138, 0, 0xf0000, bhvMessagePanel),
		OBJECT(116, 311, 3630, 814, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 390, 3420, 1040, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 530, 3150, 1338, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 641, 2880, 1695, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 769, 2610, 2037, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1101, 1830, 2366, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1432, 1290, 2619, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1831, 810, 2699, 0, -180, 0, 0x0, bhvOneCoin),
		OBJECT(116, 630, 3630, -572, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 826, 3390, -759, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1069, 3150, -1025, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1358, 2850, -1287, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1640, 2580, -1559, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 1996, 2190, -1925, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, 2374, 1770, -2267, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(116, -850, 3630, -157, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(116, -1134, 3390, -257, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(116, -1516, 3090, -345, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(116, -1919, 2790, -453, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(116, -2354, 2430, -573, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(116, -2789, 2100, -685, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(116, -3321, 1590, -896, 0, 94, 0, 0x0, bhvOneCoin),
		OBJECT(0, 47, 3930, 462, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 45, 3900, 413, 0, 0, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, -818, 3760, 863, 90, -20, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(217, -729, 3444, 742, 0, 0, 0, 0xb0000, bhvPushableMetalBox),
		OBJECT(0, -14, 3784, 101, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -4982, -1740, -1197, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, 1257, -3788, 1925, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 1507, -1410, -142, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(22, -729, 3750, 742, 0, 0, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(bitdw_area_1_collision),
		MACRO_OBJECTS(bitdw_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 33),
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
