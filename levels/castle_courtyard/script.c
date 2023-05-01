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
#include "levels/castle_courtyard/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_courtyard_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_courtyard_segment_7SegmentRomStart, _castle_courtyard_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bbh_skybox_mio0SegmentRomStart, _bbh_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_WOODEN_DOOR, wooden_door_geo), 
    LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, hmc_geo_000530), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_courtyard_area_1),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(152, LEVEL_CASTLE_COURTYARD, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(151, LEVEL_CASTLE_COURTYARD, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(150, LEVEL_BBH, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(142, LEVEL_CASTLE_COURTYARD, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(141, LEVEL_CASTLE_COURTYARD, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(140, LEVEL_CCM, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_CASTLE_COURTYARD, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(102, LEVEL_CASTLE, 2, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(101, LEVEL_CASTLE, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 1780, 1890, -253, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(195, -1795, 165, 2286, 0, -180, 0, 0x0, bhvBobombBuddyOpensCannon),
		OBJECT(201, -2201, 330, 723, 0, -90, 0, 0x0, bhvCannonClosed),
		OBJECT(137, -300, 300, -455, 0, 33, 0, 0x0, bhvExclamationBox),
		OBJECT(137, -476, 300, -340, 0, 33, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, -661, 300, -221, 0, 33, 0, 0x20000, bhvExclamationBox),
		OBJECT(207, 2113, -459, 906, 0, -90, 0, 0x0, bhvFloorSwitchGrills),
		OBJECT(0, -1831, 165, 2071, 0, 0, 0, 0x1 << 16, bhvOpenableGrill),
		OBJECT(0, 1573, 360, -1035, 0, 44, 0, 0x8e0000, bhvPaintingDeathWarp),
		OBJECT(0, -2415, 660, -1947, 0, -180, 0, 0x980000, bhvPaintingDeathWarp),
		OBJECT(0, -1259, 420, 66, 0, -18, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, 1580, 360, -1021, 0, 46, 0, 0x8d0000, bhvPaintingStarCollectWarp),
		OBJECT(0, -2404, 690, -1916, 0, -180, 0, 0x970000, bhvPaintingStarCollectWarp),
		OBJECT(0, -1259, 420, 66, 0, -18, 0, 0xf00000, bhvPaintingStarCollectWarp),
		OBJECT(187, 1416, -74, 309, 90, -15, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, 89, 119, -1577, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(0, 1625, 1640, 918, 0, -107, 0, 0xc0000, bhvSpinAirborneWarp),
		OBJECT(221, 1496, 2640, 2293, 0, -90, 0, 0x4c000000, bhvToadMessage),
		OBJECT(23, -904, 108, -1619, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, -1196, 113, 1589, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, 617, 2996, 1268, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, 1758, 3256, 1119, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, -1777, 26, -609, 0, 0, 0, 0x0, bhvTree),
		OBJECT(0, 105, 141, -2574, 0, 0, 0, 0x6650000, bhvWarp),
		OBJECT(0, 2088, 1640, 1549, 0, 30, 0, 0x6660000, bhvWarp),
		OBJECT(22, 1796, 84, -1444, 0, 0, 0, 0x8c0000, bhvWarpPipe),
		OBJECT(22, -1871, 339, -1658, 0, 0, 0, 0x960000, bhvWarpPipe),
		TERRAIN(castle_courtyard_area_1_collision),
		MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 10),
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
