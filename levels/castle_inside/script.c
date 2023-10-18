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
#include "levels/castle_inside/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_inside_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x06, _group12_yay0SegmentRomStart, _group12_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _castle_inside_segment_7SegmentRomStart, _castle_inside_segment_7SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_BOWSER_TRAP, castle_geo_000F18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WATER_LEVEL_PILLAR, castle_geo_001940), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_MINUTE_HAND, castle_geo_001530), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_HOUR_HAND, castle_geo_001548), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CLOCK_PENDULUM, castle_geo_001518), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_METAL_DOOR, metal_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_CASTLE_DOOR_UNUSED, castle_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_WOODEN_DOOR_UNUSED, wooden_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_0_STARS, castle_door_0_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_1_STAR, castle_door_1_star_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_DOOR_3_STARS, castle_door_3_stars_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_KEY_DOOR, key_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_30_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_8_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_50_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_STAR_DOOR_70_STARS, castle_geo_000F00), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_PLATFORM, hmc_geo_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM1, hmc_geo_0005B8_1), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM2, hmc_geo_0005B8_2), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM3, hmc_geo_0005B8_3), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM4, hmc_geo_0005B8_4), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM5, hmc_geo_0005B8_5), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_SQUARE_FLOATING_PLATFORM, wdw_geo_000580), 
	LOAD_MODEL_FROM_GEO(MODEL_WARROW, warrow_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_ARROW_LIFT, wdw_geo_000598), 
	LOAD_MODEL_FROM_GEO(MODEL_WDW_WATER_LEVEL_DIAMOND, wdw_geo_0005C0), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WDROPLET, wdroplet_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_PENGUIN_DEATH, death_penguin_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_inside_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 0x01, 0xf1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0b, LEVEL_CASTLE, 0x01, 0x0c, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0c, LEVEL_CASTLE, 0x01, 0x0b, WARP_NO_CHECKPOINT),
		WARP_NODE(20, LEVEL_CASTLE, 0x01, 21, WARP_NO_CHECKPOINT),
		WARP_NODE(21, LEVEL_CASTLE, 0x01, 20, WARP_NO_CHECKPOINT),
		WARP_NODE(50, LEVEL_CASTLE_COURTYARD, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_PENGUIN_DEATH, 311, 211, 3190, 0, 90, 0, 0x00000000, bhvPenguinDeath),
		OBJECT(MODEL_BOBOMB_BUDDY, 316, -51, 3190, 0, 90, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_NONE, 22, 4800, 2892, 0, 0, 0, 0x00000000, bhvBoxSpawner),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 2911, 7, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_PURPLE_SWITCH, -377, 4800, 2100, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3111, -193, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3111, 207, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3111, 7, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3311, 407, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3311, -393, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3311, 7, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3511, 7, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3125, 3711, 7, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_PURPLE_SWITCH, 377, 4800, 2100, 0, 0, 0, 0x00000000, bhvFloorSwitchAnimatesObject),
		OBJECT(MODEL_NONE, 665, 0, 1783, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -671, 0, 1765, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2150, -63, -13, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2, 1600, -1912, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -1736, 2236, -624, 0, 90, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1742, 2636, -17, 0, 90, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1750, 3036, 594, 0, 90, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3134, 5993, -10, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -3125, 3112, 6, 0, 0, 0, (21 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -3125, 2485, 7, 0, 0, 0, (20 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -29, -431, -3, 0, 0, 0, (0xb << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 796, 219, -93, 0, 0, 0, (0xc << 16), bhvFadingWarp),
		OBJECT(MODEL_BOWLING_BALL, 2799, 78, 0, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_GOOMBA, 2134, 6400, -400, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 2134, 6400, 400, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 2534, 6400, 0, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 1734, 6400, 0, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 1854, 6400, -280, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 2414, 6400, -280, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 1854, 6400, 280, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_GOOMBA, 2414, 6400, 280, 0, 0, 0, (12 << 24), bhvHiddenBlueCoin),
		OBJECT(MODEL_HMC_METAL_PLATFORM, 0, 0, 0, 0, 0, 0, 0x00000000, bhvControllablePlatform),
		MARIO_POS(0x01, 0, 4, 0, -4),
		OBJECT(MODEL_PENGUIN, -2149, -63, -9, 0, 0, 0, (4 << 24), bhvSmallPenguin),
		OBJECT(MODEL_THI_WARP_PIPE, -881, 8000, -5, 0, 0, 0, (50 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 2970, 7329, 28, 0, 0, 0, (14 << 24), bhvScanvenger),
		OBJECT(MODEL_NONE, -307, -136, 3196, 0, 0, 0, (EXCLAMATION_BOX_BP_STAR_4 << 16), bhvExclamationBox),
		OBJECT(MODEL_STAR, -8, 184, -3579, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_STAR, -29, -232, -3, 0, 0, 0, (7 << 24), bhvStar),
		OBJECT(MODEL_STAR, -3015, -338, 333, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_BOO, 2997, 182, 0, 0, 0, 0, (10 << 24), bhvBalconyBigBoo),
		OBJECT(MODEL_NONE, 1915, 312, 0, 0, 0, 0, (2 << 24), bhvBooksCtl),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 2134, 6400, 0, 0, 0, 0, (12 << 24), bhvBlueCoinSwitch),
		OBJECT(MODEL_STAR, -3125, 2484, 7, 0, 0, 0, (9 << 24), bhvStar),
		OBJECT(MODEL_NONE, 1, 2171, -3699, 0, 0, 0, (6 << 24), bhvPokeyCtl),
		OBJECT(MODEL_STAR, -9, 5339, 7620, 0, 0, 0, (11 << 24), bhvStar),
		OBJECT(MODEL_STAR, 913, 1978, 944, 0, 0, 0, (13 << 24), bhvStar),
		OBJECT(MODEL_NONE, -15, 0, -782, 0, 0, 0, (0xf1 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -843, 457, 841, 0, 0, 0, 0x00000000, bhvLightSwitch),
		OBJECT(MODEL_PENGUIN, -1969, 780, -30, 0, -90, 0, (8 << 24), bhvTuxiesMother),
		OBJECT(MODEL_TWEESTER, 11, 1515, -2760, 0, 0, 0, 0x00000000, bhvTweester),
		OBJECT(MODEL_WARROW, -2815, 1800, -11, 0, 0, 0, 0x00000000, bhvWArrow),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 2469, 113, -520, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 2469, 714, 0, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_WDW_WATER_LEVEL_DIAMOND, 2469, 1169, 524, 0, 0, 0, 0x00000000, bhvWaterLevelDiamond),
		OBJECT(MODEL_NONE, -808, 739, 889, 0, 0, 0, 0x00000000, bhvInitializeChangingWaterLevel),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, -3008, 79, 336, 0, 0, 0, 0x00000000, bhvWdwSquareFloatingPlatform),
		OBJECT(MODEL_WDW_SQUARE_FLOATING_PLATFORM, -3008, 79, -352, 0, 0, 0, 0x00000000, bhvWdwSquareFloatingPlatform),
		TERRAIN(castle_inside_area_1_collision),
		MACRO_OBJECTS(castle_inside_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 4, 0, -4),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
