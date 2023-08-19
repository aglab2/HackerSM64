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
	LOAD_YAY0_TEXTURE(0x09, _mountain_yay0SegmentRomStart, _mountain_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _slide_skybox_mio0SegmentRomStart, _slide_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pss_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_RR, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_RR, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_PSS, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_PSS, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, 5282, 6121, -5022, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3682, 6121, -5022, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 4482, 6121, -4222, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 4482, 6121, -3422, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 4482, 6121, -2622, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 4482, 6121, -1822, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 4482, 6121, -1022, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3682, 6121, -4377, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3682, 6121, -3577, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3682, 6121, -1977, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3682, 6121, -1322, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 2882, 6121, -2777, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 2882, 6121, -1977, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 2882, 6121, -3577, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 3682, 6121, -2777, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 5282, 6121, -4377, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 5282, 6121, -3577, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 5282, 6121, -2777, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 5282, 6121, -1977, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 5282, 6121, -1322, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 6082, 6121, -3577, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 6082, 6121, -2777, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 6082, 6121, -1977, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, 9327, 1580, 1320, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -6163, -1777, 4579, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -6651, 6126, 12531, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -9387, 6444, 11710, 0, 0, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, 4482, 6069, -5022, 0, 0, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(0, 2638, -141, -10072, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1930, -176, -9048, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 4700, -4180, 7889, 0, 0, 0, 0x0, bhvHiddenRedCoinStar),
		OBJECT(124, -8283, 6304, 12144, 0, -70, 0, 0x3e0000, bhvMessagePanel),
		OBJECT(0, 3790, -4405, 7885, 0, 0, 0, 0x870000, bhvPoleGrabbing),
		OBJECT(215, -9243, 6304, 13211, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1095, 5090, 12515, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 9679, 2242, 11840, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 7861, 1855, 5679, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 8773, 613, -9765, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4919, -1296, -2182, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4800, -4545, 8680, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 6088, -3145, 7899, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -8966, 6648, 12562, 0, 90, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -4246, -829, -11473, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -8735, -1525, 13124, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(116, -1423, 5100, 12515, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -1730, 5040, 12515, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -2000, 4880, 12515, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4684, -1273, -2502, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4439, -1248, -2839, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -3906, -1253, -2768, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -3701, -1288, -2295, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5194, -1319, -1875, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5454, -1342, -1557, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5741, -1370, -1174, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5763, -1320, -1850, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5493, -1296, -2176, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5264, -1272, -2500, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5034, -1251, -2784, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4445, -1404, -718, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4178, -1279, -2416, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4470, -1303, -2089, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4711, -1328, -1749, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4973, -1352, -1424, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5280, -1377, -1070, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5572, -1402, -732, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -3996, -1317, -1967, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4246, -1336, -1635, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4534, -1359, -1316, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4802, -1383, -987, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -5064, -1411, -616, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -3704, -1335, -1656, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -3934, -1357, -1349, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -4209, -1380, -1041, 0, 0, 0, 0x0, bhvYellowCoin),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 37),
		TERRAIN_TYPE(TERRAIN_SLIDE),
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
