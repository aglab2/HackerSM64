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
#include "levels/ddd/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ddd_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ddd_segment_7SegmentRomStart, _ddd_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group12_geoSegmentRomStart, _group12_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ddd_segment_7SegmentRomStart, _ddd_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	LOAD_MIO0(0x6, _group12_mio0SegmentRomStart, _group12_mio0SegmentRomEnd), 
	LOAD_MIO0(0x5, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_13), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_BOWSER_SUB_DOOR, ddd_geo_000478), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_BOWSER_SUB, ddd_geo_0004A0), 
	LOAD_MODEL_FROM_GEO(MODEL_DDD_POLE, ddd_geo_000450), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ddd_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE_COURTYARD, 1, 115, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_CASTLE_COURTYARD, 1, 99, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_BOB, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_BOB, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_DDD, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_DDD, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, -3453, 4662, 8867, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(140, -9686, -666, -4263, 0, 0, 0, 0x0, bhvBlueCoinSwitch),
		OBJECT_WITH_ACTS(195, 6412, 1496, 5282, 0, -180, 0, 0x350000, bhvBobombBuddy, ACT_1),
		OBJECT_WITH_ACTS(195, -1456, 3281, 7753, 0, 90, 0, 0x360000, bhvBobombBuddy, ACT_2),
		OBJECT(223, -7189, 2147, 7516, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(223, 1114, 1496, 5084, 0, 0, 0, 0x0, bhvChuckya),
		OBJECT(0, -6905, -1400, -6527, 0, 0, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, -5071, -1400, -8378, 0, -45, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, -2690, -1400, -9499, 0, 90, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, 484, -1400, -9499, 0, 90, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, 2865, -1400, -8378, 0, 45, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, -609, -295, 345, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, 2752, 740, 2879, 0, 90, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -3760, -2863, -8722, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 3473, 752, 700, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT(0, -179, -4746, -9528, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 2099, -5625, 847, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, 4248, -833, 6723, 0, 0, 0, 0x20000, bhvCoinFormation),
		OBJECT(0, -7732, 0, 7492, 0, 0, 0, 0x110000, bhvCoinFormation),
		OBJECT(0, 4699, -1400, -6527, 0, 0, 0, 0x100000, bhvCoinFormation),
		OBJECT(0, -9495, 2147, 6910, 0, 0, 0, 0x0, bhvCoinFormation),
		OBJECT_WITH_ACTS(0, -9482, 2147, 8021, 0, -60, 0, 0x40000, bhvCoinFormation, ACT_5),
		OBJECT(0, 3861, -2280, -4052, 0, 0, 0, 0x140000, bhvCoinFormation),
		OBJECT(84, -3883, 1780, 2267, 0, 0, 0, 0x0, bhvEnemyLakitu),
		OBJECT(84, 6423, 2135, 3406, 0, 0, 0, 0x0, bhvEnemyLakitu),
		OBJECT_WITH_ACTS(84, -241, 3610, 8079, 0, 0, 0, 0x0, bhvEnemyLakitu, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT(84, -5928, 209, 840, 0, 0, 0, 0x0, bhvEnemyLakitu),
		OBJECT(0, 6364, -666, -3427, 0, 0, 0, 0xb0000, bhvFadingWarp),
		OBJECT(0, -620, 3340, -5713, 0, 0, 0, 0xc0000, bhvFadingWarp),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT_WITH_ACTS(180, -181, 3281, 8006, 0, 0, 0, 0x0, bhvFireSpitter, ACT_1),
		OBJECT(0, 1651, -4479, -110, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, -8568, -1615, -8811, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, 3791, -4740, -789, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, 1711, -4167, -9632, 0, 0, 0, 0x0, bhvFish),
		OBJECT(0, -6890, -1563, -10039, 0, 0, 0, 0x0, bhvFish),
		OBJECT(220, -2172, -521, -5101, 0, 0, 0, 0x10000, bhvFlyGuy),
		OBJECT(192, -10723, 2147, 5772, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(192, -10165, 2147, 5586, 0, 0, 0, 0x0, bhvGoomba),
		OBJECT(0, -5261, -295, 4363, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -7719, -626, -2046, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1275, -666, -2470, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT_WITH_ACTS(0, -37, 3281, 8011, 0, 0, 0, 0x0, bhvGoombaTripletSpawner, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT(0, 5401, -781, 6413, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -8023, -295, 5741, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, -7044, -295, 8929, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(118, -8736, -666, -3850, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -7455, -666, -3553, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -6002, -666, -3386, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(118, -4538, -666, -3298, 0, 0, 0, 0x0, bhvHiddenBlueCoin),
		OBJECT(0, -1434, -459, -5405, 0, 0, 0, 0x2000000, bhvHiddenRedCoinStar),
		OBJECT(0, -1118, 0, -13415, 0, 0, 0, 0x0, bhvInitializeChangingWaterLevel),
		OBJECT(0, 2099, -4010, 847, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, 5032, -3906, -8819, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, -5095, -1667, -6131, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, -1500, -4218, -9196, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, 5418, -2552, -6400, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(0, 4483, -4375, 1194, 0, 0, 0, 0x0, bhvFishGroup),
		OBJECT(124, -10863, 513, -11292, 0, 150, 0, 0x3c0000, bhvMessagePanel),
		OBJECT(124, 991, 1496, 3539, 0, 45, 0, 0x3d0000, bhvMessagePanel),
		OBJECT(215, -621, -66, -6889, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -4648, 3298, 7253, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4098, 2630, 4424, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -8724, 894, 2361, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -10610, 2147, 4999, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -10476, -246, 8687, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -36, 3281, 9356, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 7341, 1496, -298, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 6547, -666, -4185, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 3200, 1042, 4700, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, -2992, 2634, 2487, 0, 0, 0, 0x3000000, bhvStar),
		OBJECT(122, -10710, 2476, 8070, 0, 0, 0, 0x4000000, bhvStar),
		OBJECT(122, -597, 4133, -6153, 0, 0, 0, 0x5000000, bhvStar),
		OBJECT(23, -8365, -295, 9087, 0, 0, 0, 0x0, bhvTree),
		OBJECT(23, -1159, -295, 3815, 0, 0, 0, 0x0, bhvTree),
		OBJECT_WITH_ACTS(23, -1300, 3281, 8589, 0, 0, 0, 0x0, bhvTree, ACT_2 | ACT_3 | ACT_4 | ACT_5 | ACT_6),
		OBJECT(120, 7429, 208, 6941, 0, -180, -3, 0x0, bhvWaterLevelDiamond),
		OBJECT_WITH_ACTS(87, 8, 3281, 8036, 0, 0, 0, 0x0, bhvWigglerHead, ACT_1),
		OBJECT(116, 50, -106, -6180, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -1300, -106, -6180, 0, 0, 0, 0x0, bhvYellowCoin),
		OBJECT(116, -6924, 288, 5685, 0, 0, 0, 0x0, bhvYellowCoin),
		TERRAIN(ddd_area_1_collision),
		MACRO_OBJECTS(ddd_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 35),
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
