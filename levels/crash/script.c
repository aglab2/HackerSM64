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


/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/crash/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_crash_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _crash_segment_7SegmentRomStart, _crash_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_CRASH_SPINNER, crash_move_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, crash_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 1, 0x65, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x75, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -19608, 11877, -24734),
		OBJECT(MODEL_RED_FLAME, -1561, -3422, -7888, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1866, -3805, -9089, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1251, -3810, -9105, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1876, -4061, -10256, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_KOOPA_SHELL, -6838, -5932, -15935, 0, -95, 0, 0x00000000, bhvCrashKoopaShellMover),
		OBJECT(MODEL_RED_FLAME, -1254, -4266, -11431, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1556, -4380, -12046, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1737, -4626, -13604, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -1810, -4838, -14692, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -2030, -4627, -13525, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -3645, -5149, -15268, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -4352, -5308, -16088, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -5282, -5531, -15787, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -6816, -5929, -15928, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7815, -6567, -14268, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_RED_FLAME, -7515, -6560, -14210, 0, -95, 0, 0x00000000, bhvFlame),
		OBJECT(MODEL_BLUE_FLAME, 4178, 2467, -12788, 0, -95, 0, (1 << 16), bhvCrashFlameSpawner),
		OBJECT(MODEL_BLUE_FLAME, 4184, 1483, -9745, 0, -95, 0, (1 << 16), bhvCrashFlameSpawner),
		OBJECT(MODEL_BLUE_FLAME, -2573, 5334, -15389, 0, 0, 0, 0x00000000, bhvCrashFlameSpawner),
		OBJECT(MODEL_BLUE_FLAME, -311, 4417, -15412, 0, 0, 0, 0x00000000, bhvCrashFlameSpawner),
		OBJECT(MODEL_BLUE_FLAME, 4077, 1177, -7224, 0, -95, 0, (2 << 16), bhvCrashFlameSpawner),
		OBJECT(MODEL_BLUE_FLAME, 1674, 4381, -15413, 0, 0, 0, 0x00000000, bhvCrashFlameSpawner),
		OBJECT(MODEL_BLUE_FLAME, 3371, 3253, -14433, 0, -53, 0, 0x00000000, bhvCrashFlameSpawner),
		OBJECT(MODEL_KOOPA_SHELL, -19355, 11877, -24474, 0, 0, 0, 0x00000000, bhvKoopaShellUnderwater),
		OBJECT(MODEL_NONE, -19477, 11877, -24263, 0, 0, 0, 0x00000000, bhvCrashCtl),
		OBJECT(MODEL_CRASH_SPINNER, -10646, 7044, -15832, 0, 135, 0, 0x00000000, bhvCrashSpinner),
		OBJECT(MODEL_CRASH_SPINNER, -14913, 9622, -19986, 0, 135, 0, (1 << 16), bhvCrashSpinner),
		OBJECT(MODEL_STAR, -15654, -9563, -7939, 0, -95, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_NONE, -19591, 12390, -24727, 0, 49, 0, (0xa << 16), bhvAirborneWarp),
		TERRAIN(crash_area_1_collision),
		MACRO_OBJECTS(crash_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_SEA),
		TERRAIN_TYPE(TERRAIN_WATER),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -19608, 11877, -24734),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
