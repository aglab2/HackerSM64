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
#include "levels/cotmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_cotmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cotmc_area_1),
		WARP_NODE(241, LEVEL_COTMC, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_COTMC, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, -2602, -870, -459, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -818, 2384, -1629, 0, -149, 0, 0x0, bhv1Up),
		// OBJECT(187, 1267, 2550, -197, 0, 0, 0, 0x0, bhvButterfly),
		OBJECT(85, -444, 2285, -1045, 0, 0, 0, 0x10000, bhvCapSwitch),
		OBJECT(137, -828, 2700, 943, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 3621, 180, -734, 0, 0, 0, 0xb0000, bhvExclamationBox),
		OBJECT(137, 2321, -600, 1655, 0, 0, 0, 0x70000, bhvExclamationBox),
		OBJECT(137, 4379, -30, 689, 0, 0, 0, 0x60000, bhvExclamationBox),
		OBJECT(137, 3014, 720, 1100, 0, 0, 0, 0x50000, bhvExclamationBox),
		OBJECT(137, 3640, 1170, -788, 0, 0, 0, 0x40000, bhvExclamationBox),
		OBJECT(137, 4275, 1740, 731, 0, 0, 0, 0xf0000, bhvExclamationBox),
		OBJECT(207, 2081, 178, -1875, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 1462, 2314, -146, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(129, 2147, 240, -983, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 2147, 40, -1182, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 2664, 720, -576, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 2863, 919, -576, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3062, 1118, -576, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 3261, 1318, -576, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 2710, 1678, -62, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 2710, 1878, 137, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, 2710, 2078, 337, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -2380, 1230, -89, 0, 0, 0, 0x1000000, bhvHiddenStar),
		OBJECT(122, -2576, -210, -1309, -180, -90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -2678, 30, -72, -180, -90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -2548, 930, 1435, -180, -90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -2574, 1620, -1040, -180, -90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(122, -3195, 1590, 845, -180, -90, 0, 0x0, bhvHiddenStarTrigger),
		OBJECT(0, 98, 2700, 1409, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 75, 2700, 1353, 0, 0, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(217, -2554, 1438, -1046, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(217, -2576, -488, 917, 0, 0, 0, 0x0, bhvPushableMetalBox),
		OBJECT(0, 93, 2610, 1133, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, -444, 4020, 3000, 0, 0, 0, 0x0, bhvStar),
		OBJECT(23, 1442, 2295, -994, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, 1449, 2447, 1255, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, -1210, 2378, 299, 0, 0, 0, 0x0, bhvTree),
		TERRAIN(cotmc_area_1_collision),
		MACRO_OBJECTS(cotmc_area_1_macro_objs),
        SHOW_DIALOG(/*index*/ 0x00, 0),
		SET_BACKGROUND_MUSIC(0x00, 17),
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
