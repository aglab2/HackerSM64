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
#include "levels/bbh/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bbh_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _bbh_skybox_yay0SegmentRomStart, _bbh_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP, geo_bbh_0005B0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM, geo_bbh_0005E0), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF, geo_bbh_000610), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR, geo_bbh_000628), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND, geo_bbh_000640), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB, geo_bbh_000658), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_ELEVATOR_PLATFORM, hmc_geo_0005D0), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_PLATFORM, hmc_geo_0005A0), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_METAL_ARROW_PLATFORM, hmc_geo_0005B8), 
	LOAD_MODEL_FROM_GEO(MODEL_HMC_WOODEN_DOOR, wooden_door_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bbh_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x51, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x52, WARP_NO_CHECKPOINT),
		WARP_NODE(0xb, LEVEL_BBH, 2, 0xa, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -15667, 2395, 3854, 0, 89, 0, (3 << 16), bhvThiBowlingBallSpawner),
		OBJECT(MODEL_NONE, -15203, 3345, 8644, 0, 89, 0, (4 << 16), bhvThiBowlingBallSpawner),
		OBJECT(MODEL_NONE, -10698, -243, 6870, 0, 89, 0, (2 << 16), bhvThiBowlingBallSpawner),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -2436, -685, 12696, 0, 92, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_BLUE_COIN, -2922, -1033, 11274, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2619, -1033, 10495, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2267, -1033, 10987, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2922, -437, 11274, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2619, -437, 10495, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2267, -437, 10987, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2922, -710, 11274, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2619, -710, 10495, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -2267, -710, 10987, 0, 92, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLACK_BOBOMB, 9170, -566, 3538, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 13550, 249, 4172, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, 15021, 520, 1325, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_NONE, -4928, -685, 11014, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -917, -685, 10516, 0, 89, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -8015, -354, 7468, 0, 89, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -15221, 2669, 5936, 0, 179, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12880, 835, 3505, 0, 89, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -15461, 2669, 7108, 0, 179, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6490, -685, 12523, 0, 133, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 2793, -685, 8061, 0, 133, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 5168, -685, 4132, 0, 133, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_EXCLAMATION_BOX, -2364, -264, 13302, 0, 133, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, -8616, -227, 6812, 0, 89, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 460, -685, 14130, 0, -109, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -9450, -402, 13986, 0, 90, 0, (0xb << 16), bhvDoorWarp),
		OBJECT(MODEL_DORRIE, 10097, -2650, -99, 0, 0, 0, 0x00000000, bhvDorrie),
		OBJECT(MODEL_ENEMY_LAKITU, 3479, -473, 6506, 0, 0, 0, (2 << 16), bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, -2460, -108, 7112, 0, 0, 0, (2 << 16), bhvEnemyLakitu),
		OBJECT(MODEL_ENEMY_LAKITU, 14638, 1121, -123, 0, 0, 0, (2 << 16), bhvEnemyLakitu),
		OBJECT(MODEL_EXCLAMATION_BOX, 3180, -101, 8720, 0, 133, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -10649, 15, 6891, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_BOWLING_BALL, 12099, 300, 5598, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_NONE, 6422, -1061, -482, 0, -11, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 8862, -283, 3348, 0, 53, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2081, -685, 9077, 0, 177, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -5681, -685, 11740, 0, 133, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -2138, -685, 12474, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -5033, -685, 10943, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 2939, -685, 7800, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -4315, -685, 10342, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_HEART, 15385, 732, 752, 0, 0, 0, 0x00000000, bhvRecoveryHeart),
		MARIO_POS(0x01, 90, -9028, -354, 7461),
		OBJECT(MODEL_NONE, 487, -685, 14126, 0, -108, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_HMC_METAL_PLATFORM, -8574, -464, 5687, 0, 0, 0, 0x00000000, bhvControllablePlatform),
		OBJECT(MODEL_RED_COIN, 9786, -2036, -2273, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 12140, -2036, -1341, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11025, -2036, -1540, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8117, -2036, -626, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8683, -2036, 759, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 11929, -2036, 99, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10918, -2036, 1510, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 8912, -2036, 1858, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_SCUTTLEBUG, 7312, -685, 2105, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 11144, -90, 5358, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 3461, -685, 5932, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -2148, -685, 8215, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -9681, -354, 7431, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -12813, 835, 3882, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -15206, 2669, 5188, 0, 0, 0, 0x00000000, bhvScuttlebug),
		OBJECT(MODEL_BOWLING_BALL, 14620, 476, -96, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_STAR, -5490, -228, 4884, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -15190, 3519, 9705, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, 13904, 804, -4113, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_NONE, 7430, -1479, -3067, 0, 0, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT_WITH_ACTS(MODEL_WIGGLER_HEAD, -3138, -685, 10450, 0, 0, 0, 0x05000000, bhvWigglerHead, ACT_6),
		TERRAIN(bbh_area_1_collision),
		MACRO_OBJECTS(bbh_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_C5),
		TERRAIN_TYPE(TERRAIN_SAND),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, bbh_area_2),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 2, 0x51, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 2, 0x52, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HMC_WOODEN_DOOR, -10042, -2436, 126, 0, 0, 0, (0xa << 16), bhvDoorWarp),
		OBJECT(MODEL_SNUFIT, -10004, -1565, -2429, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -11502, -1014, -3170, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -11374, -923, -4449, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -9502, -874, -4190, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -8722, -793, -5479, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -7442, 864, -4925, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -6263, 860, -5789, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -4114, 971, -6180, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -2328, 657, -6046, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -1773, 268, -8095, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -1843, -664, -10867, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -3771, -1021, -10843, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_SNUFIT, -5087, -1347, -10950, 0, 0, 0, 0x00000000, bhvSnufit),
		OBJECT(MODEL_STAR, -7524, -1533, -10833, 0, 0, 0, (4 << 24), bhvStar),
		TERRAIN(bbh_area_2_collision),
		MACRO_OBJECTS(bbh_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_C5),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 90, -9028, -354, 7461),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
