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
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, castle_courtyard_geo_000200), 
	LOAD_MODEL_FROM_GEO(MODEL_BITS_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_courtyard_area_1),
		WARP_NODE(0x0A, LEVEL_CASTLE, 2, 0xa0, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(0, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(1, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		PAINTING_WARP_NODE(2, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE, 2, 0xa1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BITS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_COURTYARD, 0x01, 0xf0, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_COURTYARD, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x32, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 5523, -2520, 11127, 0, 90, 0, (0x32 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 5522, -2520, 11122, 0, 90, 0, (0x31 << 16), bhvAirborneStarCollectWarp),
		OBJECT(MODEL_BLACK_BOBOMB, -2408, -2813, -7625, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -7426, -2813, -9104, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -7105, -2813, 1311, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -11584, -2797, 7309, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 10843, -2813, 739, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 8998, -2813, 2778, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 7271, -2813, 3793, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 7663, -2813, 5182, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 5683, -2813, 6178, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 5539, -2813, 8095, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 5520, -2813, 11227, 0, 90, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BOO, -7574, -2696, -8390, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -2068, 549, -7000, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -3651, -2696, -5726, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5547, -2696, -2614, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -5534, -2696, 267, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -8854, -2696, 2303, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -7920, -2696, 4088, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -10313, -2680, 7975, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -10813, -2680, 6364, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -12194, -2680, 7814, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -2162, 720, -7508, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1221, -2696, -7223, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 6030, -2696, -7857, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 11659, -2696, 412, 0, 90, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -16169, -2797, 8670, 0, 90, 0, (0xb << 16), bhvDoorWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -16169, -2797, 8527, 0, -90, 0, (0xa << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, -15599, -2797, 8579, 0, 90, 0, (0xf1 << 16), bhvDeathWarp),
		MARIO_POS(0x01, 0, -15946, -2797, 8594),
		OBJECT(MODEL_BITS_WARP_PIPE, 5529, -2904, 11777, 0, 90, 0, (0xc << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_METAL_DOOR, -8589, -2679, -7544, 0, -90, 0, (0xa << 16), bhvDoorWarp),
		OBJECT(MODEL_RED_COIN, -4496, -2679, -8294, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2299, -2679, -5636, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3757, -2679, -10366, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -7853, -2679, -4764, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -6682, -2679, 37, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3669, -2735, -8902, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1197, -2679, -7371, 0, -90, 0, (0xa << 16), bhvRedCoin),
		OBJECT(MODEL_NONE, 4644, -2488, -7381, 0, -90, 0, (4 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -5456, -2813, -4383, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -8138, -2813, -5102, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -6747, -2813, -4414, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -6954, -2813, -7111, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -6424, -2813, -8787, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -5322, -2813, -7281, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -3030, -2813, -6630, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -2841, -2813, -9095, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -4513, -2813, -5166, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 11329, -2813, -157, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 12643, -2813, 1291, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 10897, -2813, 1104, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 9216, -2813, 2896, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 7432, -2813, 3380, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 7438, -2813, 4990, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 5606, -2813, 6355, 0, 90, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_NONE, -6061, -2283, -9433, 0, 90, 0, (0x22 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -6062, -2284, -9438, 0, 90, 0, (0x21 << 16), bhvAirborneStarCollectWarp),
		TERRAIN(castle_courtyard_area_1_collision),
		MACRO_OBJECTS(castle_courtyard_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x28),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -15946, -2797, 8594),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
