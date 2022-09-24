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
#include "levels/luigiman/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_luigiman_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _luigiman_segment_7SegmentRomStart, _luigiman_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGIMAN_RINGS, luigiman_rings_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGIMAN_SPINNING_HOLES1, luigiman_spinning_holes1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LUIGIMAN_MOVING_PLATFORM, luigiman_moving_platform_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, luigiman_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_YELLOW_COIN, 8011, 1748, 12101, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 5926, 634, 13232, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4056, 2907, 12107, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 6954, 3339, 13127, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 5971, 3403, 9028, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4527, 267, 11596, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4918, 487, 11496, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_YELLOW_COIN, 4769, 1578, 8839, 0, 0, 0, 0x00000000, bhvOneCoin),
		OBJECT(MODEL_NONE, 980, 800, 3974, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1013, 562, 2521, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2462, 1735, -924, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1018, 5811, -2594, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 670, 3890, -10820, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 670, 1323, -6396, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6632, 1327, 12109, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 6953, 3256, 13128, 0, 0, 0, 0x00020000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8012, 2767, 11570, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4302, 3296, 8308, 0, -90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_GOOMBA, 8041, 2945, 13167, 0, 0, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 7763, 2614, 9016, 0, -154, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 5536, 0, 10753, 0, 56, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 6758, 301, 10030, 0, 110, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 7284, 301, 11477, 0, -31, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_GOOMBA, 5725, 1070, 11971, 0, 110, 0, 0x00000000, bhvGoomba),
		OBJECT(MODEL_LUIGIMAN_MOVING_PLATFORM, 7461, 1328, 10376, 0, 0, 0, 0x00000000, bhvLuigimanMovingPlat1),
		OBJECT(MODEL_LUIGIMAN_RINGS, 7652, 1480, 489, 0, 0, 0, 0x00000000, bhvLuigimanRing),
		OBJECT(MODEL_PURPLE_SWITCH, 5391, 2205, 9688, 0, 180, 0, 0x00000000, bhvLuigimanPurpleSwitch),
		OBJECT(MODEL_RED_COIN, 5449, 1941, -929, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8551, 2174, -2677, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10222, 1941, 583, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10686, 1862, 2277, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7610, 1863, 2018, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4639, 2025, 3077, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5653, 1941, 3023, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7642, 1863, -1228, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 7711, 2796, 408, 0, 0, 0, (1 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, 8011, 1748, 12101, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 5926, 634, 13232, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 4056, 2907, 12107, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 6954, 3339, 13127, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, 5971, 3403, 9028, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_LUIGIMAN_SPINNING_HOLES1, 661, 2630, -12273, 0, 0, 0, 0x00000000, bhvLuigimanSpinningHoles1),
		OBJECT(MODEL_STAR, 2687, 8557, -346, 0, 0, 0, (0 << 16), bhvStar),
		OBJECT(MODEL_NONE, 6585, 1282, 11104, 0, 0, 0, (2 << 24), bhvHiddenStar),
		OBJECT(MODEL_STAR, 665, 1614, -9311, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_NONE, -656, 4975, 1098, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 1208, 1012, -55, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 0, 102, 10662, 0, -180, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, -180, 0, 102, 10662),
		TERRAIN(luigiman_area_1_collision),
		MACRO_OBJECTS(luigiman_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, -180, 0, 102, 10662),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
