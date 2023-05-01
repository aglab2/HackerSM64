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
#include "levels/vcutm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_vcutm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x07, _vcutm_segment_7SegmentRomStart, _vcutm_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _vcutm_segment_7SegmentRomStart, _vcutm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_VCUTM_SEESAW_PLATFORM, vcutm_geo_0001F0), 
	LOAD_MODEL_FROM_GEO(MODEL_VCUTM_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, vcutm_area_1),
		WARP_NODE(241, LEVEL_VCUTM, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_VCUTM, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 4533, -58, 2811, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -3466, 787, -14, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(85, 0, 2550, 0, 0, 0, 0, 0x20000, bhvCapSwitch),
		OBJECT(223, 3380, 25, 521, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, -223, 1350, 65, 0, -90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 3544, -600, 520, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 4524, -100, -2507, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(137, 14, 2670, -1049, 0, 0, 0, 0x20000, bhvExclamationBox),
		OBJECT(137, 3828, -1440, 642, 0, 0, 0, 0x20000, bhvExclamationBox),
		OBJECT(207, -2661, 1350, 53, 0, 90, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(129, -2663, 1625, 429, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2663, 1985, 628, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -4163, -570, -786, 0, 0, 0, 0x2000000, bhvHiddenRedCoinStar),
		OBJECT(0, 19, 2910, 2339, 0, 0, 0, 0x0, bhvHiddenStar),
		OBJECT(122, -983, 2370, 944, 180, 45, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -975, 2370, -978, 0, 46, -180, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, 945, 2370, 948, 180, -45, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, 957, 2370, -979, 0, -45, 180, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, 9, 3480, -1057, 0, 0, 180, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, -981, 3025, -966, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, 960, 3025, 949, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, 960, 3025, -966, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, -981, 3025, 949, 0, 0, 0, 0x0, bhvMrI),
		OBJECT(0, 27, 2640, 1379, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 22, 2640, 1413, 0, 0, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, -1031, 2241, -967, -90, 90, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(217, -3664, -330, 1701, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(215, -3627, -720, -1544, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4263, -1129, 144, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2774, 690, -1549, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3165, 1230, -753, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5018, 1147, -10, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4106, -1132, 1367, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4065, 396, 1347, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4156, 1230, 536, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 35, 2550, 1337, 0, -180, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 2496, -420, 495, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(100, 4463, 60, 60, 0, 0, 0, 0x0, bhvSwoop),
		TERRAIN(vcutm_area_1_collision),
		MACRO_OBJECTS(vcutm_area_1_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, 0),
		SET_BACKGROUND_MUSIC(0x00, 19),
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
