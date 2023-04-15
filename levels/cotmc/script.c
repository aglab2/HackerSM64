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
#include "levels/cotmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_cotmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_15), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE, palm_tree_geo), 
	LOAD_MODEL_FROM_DL(MODEL_FIREPLACE, fireplace_Cube_mesh, LAYER_OPAQUE),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cotmc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_COURTYARD, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_COURTYARD, 0x01, 0x22, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FIREPLACE, -157, 1281, -3131, 0, 0, 0, 0x00000000, bhvFireplace),
		OBJECT(MODEL_MR_BLIZZARD, 2369, 2799, 6557, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT(MODEL_MR_BLIZZARD, 3573, 1848, 4465, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT(MODEL_MR_BLIZZARD, 3917, 1702, 686, 0, 0, 0, 0x00000000, bhvMrBlizzard),
		OBJECT(MODEL_NONE, 214, 2207, -211, 0, 158, 0, (16 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 407, 1690, 2732, 0, 68, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3467, 1757, 255, 0, 68, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -948, 1281, -842, 0, 78, 0, (4 << 16), bhvCoinFormation),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 4609, 1281, 1943, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 6408, 1281, 2941, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 2319, 1281, -747, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -1057, 1281, -508, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -447, 1281, -2394, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_NONE, 2869, 1848, 5465, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -449, 1848, 2382, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		MARIO_POS(0x01, 0, 2425, 1848, 1330),
		OBJECT(MODEL_NONE, 2411, 1848 + 200, 1332, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_PENGUIN, -633, 1848, 2050, 0, 0, 0, 0x00000000, bhvTuxiesMother),
		OBJECT(MODEL_PENGUIN, -7864, 1340, -4806, 0, 0, 0, 0x00000000, bhvSmallPenguin),
		OBJECT(MODEL_PIRANHA_PLANT, 6685, 1922, 7561, 0, 0, 0, 0x00000000, bhvPiranhaPlant),
		OBJECT(MODEL_SPINDRIFT, -6478, 1001, -4719, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -8141, 1001, -3470, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_SPINDRIFT, -7870, 1340, -5297, 0, 0, 0, 0x00000000, bhvSpindrift),
		OBJECT(MODEL_RED_COIN, 1575, 3264, 5913, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3679, 2817, 4922, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2037, 1933, 1336, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6975, 1920, 7655, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 5193, 2677, 2800, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3537, 1604, -243, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 406, 1254, 2853, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 503, 2217, -592, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 2679, 2189, 1645, 0, 0, 0, (1 << 24), bhvBowserCourseRedCoinStar),
		//OBJECT(MODEL_SSL_PALM_TREE, 3040, 1544, 7222, 0, 0, 0, 0x00000000, bhvTree),
		//OBJECT(MODEL_SSL_PALM_TREE, 3459, 1544, 6830, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 3390, 1544, 6317, 0, 0, 0, 0x00000000, bhvTree),
		// OBJECT(MODEL_SSL_PALM_TREE, 4026, 1848, 5326, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 4415, 1848, 4648, 0, 0, 0, 0x00000000, bhvTree),
		//OBJECT(MODEL_SSL_PALM_TREE, 4324, 1848, 3898, 0, 0, 0, 0x00000000, bhvTree),
		//OBJECT(MODEL_SSL_PALM_TREE, 1765, 1848, 1104, 0, 0, 0, 0x00000000, bhvTree),
		// OBJECT(MODEL_SSL_PALM_TREE, 1423, 1848, 1559, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 1485, 1848, 1317, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -1104, 1848, 2649, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -1868, 1848, 1650, 0, 0, 0, 0x00000000, bhvTree),
		// OBJECT(MODEL_SSL_PALM_TREE, -1729, 1848, 1210, 0, 0, 0, 0x00000000, bhvTree),
		//OBJECT(MODEL_SSL_PALM_TREE, -1824, 1848, 2636, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, -2241, 1848, 2233, 0, 0, 0, 0x00000000, bhvTree),
		// OBJECT(MODEL_SSL_PALM_TREE, 2893, 1848, 1495, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2621, 1848, 1608, 0, 0, 0, 0x00000000, bhvTree),
		//OBJECT(MODEL_SSL_PALM_TREE, 3013, 1848, 3423, 0, 0, 0, 0x00000000, bhvTree),
		// OBJECT(MODEL_SSL_PALM_TREE, 2530, 1848, 4138, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 2077, 1848, 5313, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_SSL_PALM_TREE, 7130, 1835, 7952, 0, 0, 0, 0x00000000, bhvTree),
		//OBJECT(MODEL_SSL_PALM_TREE, 7050, 1835, 7319, 0, 0, 0, 0x00000000, bhvTree),
		TERRAIN(cotmc_area_1_collision),
		MACRO_OBJECTS(cotmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_TTC),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 2425, 1848, 1330),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
