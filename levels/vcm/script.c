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
#include "levels/vcm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_vcm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _vcm_segment_7SegmentRomStart, _vcm_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_VCM_ARROW, vcm_arrow_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, vcm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x37, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x47, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -4, 261, 82),
		OBJECT(MODEL_NONE, 7678, 2082, -45, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 7678, 725, -45, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 63, -328, 7906, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 0, 576, -1550, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4583, 454, 2031, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3128, 440, -62, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3128, 1594, -62, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5427, 2511, -49, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 5272, 1268, -7997, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2840, 85, -1222, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6818, 1313, 1659, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6767, 2271, 2319, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4, 609, 82, 0, 0, 0, (0xa << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_RED_COIN, -6518, 797, 36, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6, -1016, 7088, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -62, 270, -5261, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6028, 807, 6524, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4016, 1365, 1169, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2579, 4153, -153, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2857, 828, -2381, 0, -5, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4988, 3258, -7694, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -15, 624, 84, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 3523, 89, -2227, 0, -36, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2517, 5, -51, 0, 54, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3649, 5, 2242, 0, 40, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_EXCLAMATION_BOX, 5460, 1671, -2034, 0, 0, 0, (1 << 24) | (2 << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, -290, 261, 32, 0, 0, 0, 0x00000000, bhvVcmCtl),
		OBJECT(MODEL_WOODEN_SIGNPOST, 7, 261, -297, 0, 0, 0, (35 << 24) | (35 << 16), bhvMessagePanel),
		OBJECT(MODEL_VCM_ARROW, -143, 261, 125, 0, 0, 0, 0x00000000, bhvVcmArrow),
		OBJECT(MODEL_YELLOW_COIN_NO_SHADOW, 6503, 469, 4737, 0, 0, 0, 0x00000000, bhvYellowCoin),
		TERRAIN(vcm_area_1_collision),
		MACRO_OBJECTS(vcm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_V6),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -4, 261, 82),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
