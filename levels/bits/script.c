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
#include "levels/bits/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bits_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bits_skybox_yay0SegmentRomStart, _bits_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bits_segment_7SegmentRomStart, _bits_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _cloud_floor_skybox_mio0SegmentRomStart, _cloud_floor_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bits_area_1),
		WARP_NODE(241, LEVEL_BITS, 1, 241, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITS, 1, 240, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_BITS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(182, LEVEL_BITS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(181, LEVEL_BITS, 1, 0, WARP_NO_CHECKPOINT),
		WARP_NODE(170, LEVEL_LLL, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(105, LEVEL_ENDING, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(187, 1259, 180, 35, 0, 0, 0, 0x0, bhvButterfly),
		OBJECT(34, -772, 0, 821, 0, -135, 0, 0x40000000, bhvDoor),
		OBJECT(0, 419, 650, 1248, 0, -90, 0, 0x0, bhvHidden1upInPoleSpawner),
		OBJECT(0, 418, 600, 1246, 0, 0, 0, 0x0, bhvHidden1upTrigger),
		OBJECT(0, 418, 600, 1246, 0, 0, 0, 0x0, bhvHidden1upTrigger),
		OBJECT(124, 188, 540, 779, 0, -154, 0, 0x3f0000, bhvMessagePanel),
		OBJECT(124, 752, 0, 564, 0, 137, 0, 0x400000, bhvMessagePanel),
		OBJECT(0, -5, 270, -420, 0, 0, 0, 0xf10000, bhvPaintingDeathWarp),
		OBJECT(0, -955, 300, 376, 0, 21, 0, 0xb60000, bhvPaintingDeathWarp),
		OBJECT(0, -5, 270, -420, 0, 0, 0, 0xb0000, bhvPaintingStarCollectWarp),
		OBJECT(0, -955, 300, 376, 0, 21, 0, 0xb50000, bhvPaintingStarCollectWarp),
		OBJECT(120, 527, 697, -476, 0, -180, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, -537, 697, -476, 0, -180, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, 499, 1148, 547, 0, -180, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, -537, 1148, 563, 0, -180, 0, 0x0, bhvRecoveryHeart),
		OBJECT(0, 1, 0, -1294, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(23, 1200, 0, 637, 0, -180, 0, 0x0, bhvTree),
		OBJECT(23, -1200, 0, 637, 0, -180, 0, 0x0, bhvTree),
		OBJECT(23, 1200, 0, -800, 0, -180, 0, 0x0, bhvTree),
		OBJECT(23, -1200, 0, -800, 0, -180, 0, 0x0, bhvTree),
		OBJECT(0, -385, 633, 1253, 0, 0, 0, 0x1690000, bhvWarp),
		OBJECT(0, -593, 0, 976, 0, 0, 0, 0x6aa0000, bhvWarp),
		TERRAIN(bits_area_1_collision),
		MACRO_OBJECTS(bits_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 11),
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
