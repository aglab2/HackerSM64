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
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(241, LEVEL_SA, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_SA, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_CASTLE_COURTYARD, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(30, LEVEL_SA, 1, 31, WARP_NO_CHECKPOINT),
		WARP_NODE(31, LEVEL_SA, 1, 30, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_SA, 1, 21, WARP_NO_CHECKPOINT),
		WARP_NODE(21, LEVEL_SA, 1, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, -911, 855, 3607, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -911, -1089, 4472, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 826, -1089, 5172, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 2386, -1711, 64, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(212, 2386, -1223, 64, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(212, 2386, -1711, -410, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(212, 2386, -1223, -410, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(212, 3409, 792, -242, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(212, 4985, -412, -248, 0, 90, 0, 0x0, bhv1Up),
		OBJECT(0, 581, 4257, -99, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(0, 831, -521, 3308, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 652, 1527, -850, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(0, -1227, 1527, -524, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(137, -703, 2820, -1819, 0, 0, 0, 0x90000, bhvExclamationBox),
		OBJECT(0, 823, -496, 4655, 0, 0, 0, 0x1140000, bhvFadingWarp),
		OBJECT(0, 819, 2924, 961, 0, 0, 0, 0x1150000, bhvFadingWarp),
		OBJECT(0, 3740, 1575, -1649, 0, 0, 0, 0x11e0000, bhvFadingWarp),
		OBJECT(0, 804, 2954, 985, 0, 0, 0, 0x11f0000, bhvFadingWarp),
		OBJECT(180, -385, 1540, -829, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1769, 1540, -765, 0, 0, 0, 0x0, bhvFireSpitter),
		OBJECT(220, 246, 0, 3018, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(220, -324, 0, 3888, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(192, -850, 3130, -1289, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, 674, 3575, -840, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -22, 4235, -1615, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(86, 4143, 1000, -1039, 0, 0, 0, 0x2000000, bhvKingBobomb),
		OBJECT(124, -1875, 2500, 1843, 0, 41, 0, 0x490000, bhvMessagePanel),
		OBJECT(0, 148, 2670, 1467, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 117, 2700, 1419, 0, 0, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, -779, 4655, 509, 90, 15, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, 155, 2610, 1103, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -800, 5190, 136, 0, 0, 0, 0x0, bhvStar),
		OBJECT(122, -914, 403, 3340, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(22, -2040, 2500, 1687, 0, 0, 0, 0xb0000, bhvWarpPipe),
		TERRAIN(sa_area_1_collision),
		MACRO_OBJECTS(sa_area_1_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, 0),
		SET_BACKGROUND_MUSIC(0x00, 23),
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
