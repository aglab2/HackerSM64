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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_15), 

	/* Fast64 begin persistent block [level commands] */
	/*
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, wf_geo_0007E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, wf_geo_000820), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, wf_geo_000860), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, wf_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, wf_geo_000890), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, wf_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, wf_geo_0008E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, wf_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, wf_geo_000940), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, wf_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, wf_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, wf_geo_0009D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, wf_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
	*/
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		MARIO_POS(0x01, 0, 6019, 3162, 12181),
		OBJECT(MODEL_SL_SNOW_TREE, 3492, 2354, 11725, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 1617, 2354, 11592, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 2040, 2354, 10315, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4422, 2354, 9160, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4157, 2354, 8571, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 2751, 2354, 8777, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 1540, 2354, 8834, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4677, 2354, 5359, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4666, 2354, 3268, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 3422, 2354, 4537, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 2123, 3644, 1386, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 673, 3644, -41, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 1159, 3644, -1391, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4849, 3437, -12068, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 3377, 420, -8148, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4108, 420, -8959, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 3993, 420, -7361, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SL_SNOW_TREE, 4698, 420, -8339, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, -4188, 2354, 9016, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_CCM_SNOW_TREE, -3472, 2354, 7978, 0, 0, 0, 0x00000000, bhvTree),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 6019, 3162, 12181),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
