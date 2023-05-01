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
	LOAD_YAY0(0x05, _group5_yay0SegmentRomStart, _group5_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _pss_segment_7SegmentRomStart, _pss_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ssl_skybox_mio0SegmentRomStart, _ssl_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_6), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, pss_area_1),
		WARP_NODE(241, LEVEL_PSS, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_PSS, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(21, LEVEL_PSS, 1, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_PSS, 1, 21, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 977, 4140, 258, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 749, 686, 5433, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 556, -90, -3994, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, -339, -1500, 2778, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, -339, 360, -2757, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 101, -4500, 515, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -1308, 4570, 657, 0, 0, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, -1384, -4025, 671, 0, 0, 0, 0x1140000, bhvFadingWarp),
		OBJECT(0, 184, 2725, 1409, 0, 0, 0, 0x1150000, bhvFadingWarp),
		OBJECT(220, -272, 1350, -4079, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(220, 27, 0, 4173, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(220, 89, -4050, -2121, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(220, -751, -3930, 2212, 0, 0, 0, 0x0, bhvFlyGuy),
		OBJECT(0, -2773, 2820, 593, 0, 0, 0, 0x2000000, bhvHiddenRedCoinStar),
		OBJECT(0, -347, -4024, -498, 0, 0, 0, 0x1000000, bhvHiddenStar),
		OBJECT(122, 16, -600, 3722, 180, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, 552, 930, -4378, 180, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -324, -4410, 2779, 180, 0, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -324, -4410, -2700, 0, 0, 180, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -318, -3750, 512, -180, 90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(124, 1565, -2950, -163, 0, 0, 0, 0x470000, bhvMessagePanel),
		OBJECT(124, -1268, -4050, 550, 0, -180, 0, 0x480000, bhvMessagePanel),
		OBJECT(0, 794, 2760, 1288, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 830, 2760, 1274, 0, 0, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, -1132, 4210, 1377, 90, -90, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, -983, 2350, 1200, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -1079, 2350, -819, 0, 0, 0, 0x0, bhvPokey),
		OBJECT(0, -2784, 692, 595, 0, 0, 0, 0xa80000, bhvPoleGrabbing),
		OBJECT(217, -2790, 1590, 1068, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, -2225, -2010, 670, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1613, -1050, -284, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3518, -265, 374, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4052, -690, -1075, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4149, 390, -1286, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -1540, 900, -583, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4117, 990, 197, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3517, 1020, -610, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 1058, 2350, 1366, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 12, 5610, 0, 0, 0, 0, 0x0, bhvStar),
		TERRAIN(pss_area_1_collision),
		MACRO_OBJECTS(pss_area_1_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, 0),
		SET_BACKGROUND_MUSIC(0x00, 12),
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
