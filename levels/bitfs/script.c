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
	LOAD_MIO0(0x7, _bitfs_segment_7SegmentRomStart, _bitfs_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
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

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bitfs_area_1),
		WARP_NODE(241, LEVEL_CASTLE, 2, 182, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BITS, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 0, WARP_NO_CHECKPOINT),
		OBJECT(212, 1971, 4088, 3351, 0, -90, 0, 0x0, bhv1Up),
		OBJECT(212, -2874, 4080, 3515, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, -3522, 510, 648, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(212, 1205, 2045, -1677, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(0, -2433, -180, 5, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(0, -2502, 4020, -2506, 0, -135, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, 0, 60, 0, 0, 0, 0, 0x120000, bhvCoinFormation),
		OBJECT(137, -16, 150, 1620, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, -1410, 150, -18, 0, 0, 0, 0x30000, bhvExclamationBox),
		OBJECT(137, 1259, 300, 11, 0, 0, 0, 0x20000, bhvExclamationBox),
		OBJECT(180, 1753, 2652, 759, 0, -90, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 1758, 2652, 1253, 0, -90, 0, 0x0, bhvFireSpitter),
		OBJECT(180, 2502, 2652, 1000, 0, -90, 0, 0x0, bhvFireSpitter),
		OBJECT(0, 3366, 3401, 3958, 0, -180, 0, 0x0, bhvFlamethrower),
		OBJECT(0, 3733, 3396, 2064, 0, -90, 0, 0x0, bhvFlamethrower),
		OBJECT(207, -18, -224, -1543, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(192, -3492, 3076, 1867, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -3221, 3076, 1606, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(129, -15, -425, -1855, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -15, -425, -2055, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -15, -425, -2255, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -15, -425, -3200, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -15, -425, -3400, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -15, -425, -3600, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -15, -425, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -215, -425, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -415, -425, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -615, -425, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -815, -425, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -815, -225, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -815, -25, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -1500, 235, -3800, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(0, -500, 2790, 0, 0, 0, 0, 0x0, bhvHiddenRedCoinStar),
		OBJECT(116, 3147, 2190, -3392, 0, 0, 0, 0x0, bhvOneCoin),
		OBJECT(187, 982, 3547, 2065, 90, 0, 0, 0x0, bhvPenguinRaceShortcutCheck),
		OBJECT(0, 0, 0, 0, 0, 0, 0, 0xfc0000, bhvPoleGrabbing),
		OBJECT(215, -1495, 510, -3797, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2505, 1110, 521, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5, 1440, 3404, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3416, 1380, -2, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3429, 5250, -3405, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -3310, 4290, 3529, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 3147, 2340, -4009, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 985, 3720, 3344, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, -455, 0, 228, 0, -179, 0, 0xa0000, bhvSpinAirborneWarp),
		TERRAIN(bitfs_area_1_collision),
		MACRO_OBJECTS(bitfs_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 9),
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
