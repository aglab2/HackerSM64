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
#include "levels/pss/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _machine_yay0SegmentRomStart, _machine_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_CUBE, ttc_geo_000240), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_PRISM, ttc_geo_000258), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pss_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x71, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x72, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_PSS, 0x01, 0x0C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_PSS, 0x01, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, -4510, 3358, 2675, 0, 0, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, -316, 6218, 4571, 0, -106, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4510, 4524, 2675, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4492, 2872, 3457, 0, 65, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4552, 2881, 1908, 0, 166, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1501, 6517, 3961, 0, -106, -12, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 10929, 9693, 10216, -13, -25, 4, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_TTC_ROTATING_CUBE, -3028, 5177, -4039, 0, 0, 0, 0x00000000, bhvTTCRotatingSolid),
		OBJECT(MODEL_TTC_ROTATING_PRISM, -3933, 5743, -4020, 0, 0, 0, (1 << 16), bhvTTCRotatingSolid),
		OBJECT(MODEL_TTC_ROTATING_CUBE, -4863, 5977, -4022, 0, 0, 0, 0x00000000, bhvTTCRotatingSolid),
		MARIO_POS(0x01, 0, -4171, 2881, 2339),
		OBJECT(MODEL_NONE, 4765, 14201, 797, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_BITS_WARP_PIPE, 3976, 14206, 2258, 0, 0, 0, (0xb << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -4883, 2608, 2747, 0, 0, 0, (0xc << 16), bhvWarpPipe),
		OBJECT(MODEL_STAR, -7527, 6449, -4038, 0, -18, 0, 0x00000000, bhvStar),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SLIDE),
		TERRAIN_TYPE(TERRAIN_SLIDE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -4171, 2881, 2339),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
