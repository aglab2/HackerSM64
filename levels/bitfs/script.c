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
#include "levels/bitfs/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bitfs_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bitfs_skybox_yay0SegmentRomStart, _bitfs_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, bitfs_geo_0004B0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, bitfs_geo_0004C8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, bitfs_geo_0004E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, bitfs_geo_0004F8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, bitfs_geo_000510), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, bitfs_geo_000528), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, bitfs_geo_000540), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, bitfs_geo_000558), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B, bitfs_geo_000570), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, bitfs_geo_000588), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D, bitfs_geo_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, bitfs_geo_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, bitfs_geo_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_10, bitfs_geo_0005E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, bitfs_geo_000600), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, bitfs_geo_000618), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_13, bitfs_geo_000630), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_14, bitfs_geo_000648), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_15, bitfs_geo_000660), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_PLATFORM_ON_TRACK, bitfs_geo_000758), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TILTING_SQUARE_PLATFORM, bitfs_geo_0006C0), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SINKING_PLATFORMS, bitfs_geo_000770), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_BLUE_POLE, bitfs_geo_0006A8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SINKING_CAGE_PLATFORM, bitfs_geo_000690), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_ELEVATOR, bitfs_geo_000678), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_STRETCHING_PLATFORMS, bitfs_geo_000708), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SEESAW_PLATFORM, bitfs_geo_000788), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_MOVING_SQUARE_PLATFORM, bitfs_geo_000728), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_SLIDING_PLATFORM, bitfs_geo_000740), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TUMBLING_PLATFORM_PART, bitfs_geo_0006D8), 
	LOAD_MODEL_FROM_GEO(MODEL_BITFS_TUMBLING_PLATFORM, bitfs_geo_0006F0), 
	LOAD_MODEL_FROM_GEO(0xf2, bitfs_thing_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitfs_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x81, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x82, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BULLY_BOSS, -3, 3476, -6, 0, 0, 0, 0x00000000, bhvBigBully),
		OBJECT(0xf2, -1, 3476, -5, 0, 0, 0, 0x00000000, bhvBitfsThing),
		OBJECT(MODEL_NONE, 28, 3476, -1896, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		MARIO_POS(0x01, 0, 21, 3476, -1902),
		TERRAIN(bitfs_area_1_collision),
		MACRO_OBJECTS(bitfs_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EYE),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 21, 3476, -1902),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
