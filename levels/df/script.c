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
#include "levels/df/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_df_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _df_segment_7SegmentRomStart, _df_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_DF_ARROW, df_arrow_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, df_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x39, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_DF, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -862, -267, -617),
		OBJECT(MODEL_EXCLAMATION_BOX, -1289, -199, -216, 0, 0, 0, 0x00000000, bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 1305, 1319, -3361, 0, 0, 0, (1 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -7793, 1152, -3234, 0, 0, 0, (2 << 16), bhvExclamationBox),
		OBJECT(MODEL_WOODEN_SIGNPOST, -846, -530, -1164, 0, 0, 0, (8 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, -4129, -530, -5666, 0, -141, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -7657, -530, -1628, 0, -141, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -3888, -530, -1285, 0, -141, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -957, 1304, -6147, 0, -141, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -6795, -530, -7473, 0, -141, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -867, -261, -619, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_RED_COIN, -6111, 2383, -5542, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2358, 3112, -6727, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2859, 2214, -2438, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8068, 308, -724, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5577, -875, -1732, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5904, 1189, -3814, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1194, -255, -7342, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -9250, 179, -9087, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -859, 11, -632, 0, 0, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_CAP_SWITCH, -6138, 705, -6793, 0, 0, 0, 0x00000000, bhvCapSwitch),
		OBJECT(MODEL_CAP_SWITCH, -5637, -530, -5039, 0, 0, 0, (1 << 24) | (1 << 16), bhvCapSwitch),
		OBJECT(MODEL_CAP_SWITCH, -1255, 1492, -5461, 0, 0, 0, (2 << 24) | (2 << 16), bhvCapSwitch),
		OBJECT(MODEL_NONE, -3084, -530, -1012, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7116, 705, -4681, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -7745, -530, -5298, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3053, -530, -4305, 0, -141, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1243, 1493, -5459, 0, -180, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -662, -530, -2462, 0, 154, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -859, -345, -632, 0, 0, 0, 0x00000000, bhvDfLevelReset),
		OBJECT(MODEL_NONE, -6097, 2284, -5569, 0, -24, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_DF_ARROW, -452, -530, -553, 0, 0, 0, 0x00000000, bhvDfArrow),
		OBJECT(MODEL_NONE, -4068, -1713, -2288, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		TERRAIN(df_area_1_collision),
		MACRO_OBJECTS(df_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_DF),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -862, -267, -617),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
