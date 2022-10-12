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
#include "levels/hf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_hf_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _hf_segment_7SegmentRomStart, _hf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_BOO, hf_boo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_GOO, hf_goo_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_CRYSTAL, hf_crystal_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_CRYSTAL_PLAT, hf_crystal_block_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_ICE, hf_ice_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_ICE_POLE, hf_ice_pole_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_ICE_POLE2, hf_ice_pole2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_ICE_POLE2, hf_ice_pole2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_ICE_BRIDGE, hf_bridge_mover_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_BRIDGE1, hf_bridge1_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_BRIDGE2, hf_bridge2_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_JOEL, hf_joel_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_HF_SCARY_BOO, hf_scary_boo_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, hf_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE_GROUNDS, 0x01, 0x34, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE_GROUNDS, 0x01, 0x44, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_HF, 0x01, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_HF, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_HF, 0x01, 0x22, WARP_NO_CHECKPOINT),
		WARP_NODE(0x23, LEVEL_HF, 0x01, 0x23, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, -1698, 264, 6603),
		OBJECT(MODEL_BLUE_COIN, -5307, 4756, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5307, 4258, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5307, 3735, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5307, 3206, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5307, 2623, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -5307, 2131, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4666, 1851, -2001, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4039, 1487, -1572, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4046, 1487, -2057, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4046, 1487, -2595, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -4863, 5066, -1994, 0, 0, 0, 0x00000000, bhvHiddenBlueCoin),
		OBJECT(MODEL_HF_BOO, -466, 462, 6366, 0, 0, 0, (1 << 16), bhvHfBoo),
		OBJECT(MODEL_HF_BOO, 537, 670, 6366, 0, -90, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, 537, 753, 7252, 0, -43, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, 537, 1545, 7252, 0, 136, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, -89, 1483, 6562, 0, 89, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, -79, 1691, 5805, 0, 89, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_GOO, 3176, 2136, 5651, 0, 0, 0, 0x00000000, bhvHfGoo),
		OBJECT(MODEL_HF_GOO, 3608, 2136, 6717, 0, 0, 0, 0x00000000, bhvHfGoo),
		OBJECT(MODEL_HF_GOO, 5041, 2136, 7094, 0, 0, 0, (1 << 16), bhvHfGoo),
		OBJECT(MODEL_HF_GOO, 6711, 2136, 6790, 0, 0, 0, (2 << 16), bhvHfGoo),
		OBJECT(MODEL_HF_GOO, 7607, 2136, 6867, 0, 0, 0, 0x00000000, bhvHfGoo),
		OBJECT(MODEL_HF_GOO, 8921, 2136, 7241, 0, 0, 0, (2 << 16), bhvHfGoo),
		OBJECT(MODEL_HF_BOO, 8557, 2270, 9421, 0, 144, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, 7743, 2397, 8885, 0, -146, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, 7072, 2614, 9150, 0, -178, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_EXCLAMATION_BOX, -6329, 2041, -4866, 0, 0, 0, (2 << 16), bhvExclamationBox),
		OBJECT(MODEL_HF_BOO, 113, 2104, -3206, 0, 125, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_NONE, -1846, 2472, -10718, 0, -43, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_BOO, -1001, 2672, -11700, 0, -43, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_HF_BOO, -1592, 281, 5517, 0, 91, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_BOO, -1018, 281, 5517, 0, -93, 0, 0x00000000, bhvHfBoo),
		OBJECT(MODEL_HF_GOO, 9448, 2136, 8577, 0, 0, 0, (2 << 16), bhvHfGoo),
		OBJECT(MODEL_NONE, 46, 0, 6551, 0, 0, 0, 0x00000000, bhvHfBooCtl),
		OBJECT(MODEL_WOODEN_SIGNPOST, -1319, 0, 5631, 0, 0, 0, (39 << 24) | (39 << 16), bhvMessagePanel),
		OBJECT(MODEL_HF_BRIDGE1, 0, 0, 0, 0, 0, 0, 0x00000000, bhvHfBridge1),
		OBJECT(MODEL_HF_BRIDGE2, -2134, 9084, -463, 0, 0, 0, 0x00000000, bhvHfBridge2),
		OBJECT(MODEL_NONE, 1668, 3844, 1128, 0, 0, 0, (1 << 16), bhvCheckpoint),
		OBJECT(MODEL_CHUCKYA, -6741, 1664, -1989, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, -5320, 1664, 2550, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_NONE, -4711, 6029, 1921, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 2544, 1392, -2509, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1700, 2472, -11248, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 33, 0, 6546, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -6383, 1664, -2957, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3657, 1358, -85, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 849, 1246, -1811, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3960, 1664, 2580, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 12274, 3394, 4237, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_WOODEN_SIGNPOST, 3353, 1392, -2534, 0, -90, 0, (19 << 24) | (19 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, -1453, -443, 223, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1219, 1652, 1005, 0, 0, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 3485, 3502, 970, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4581, 3263, 967, 0, 90, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -12145, 2148, 2654, 0, -180, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_EXCLAMATION_BOX, -12218, 2525, 1126, 0, -180, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, -6900, 1761, -4221, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3890, 2050, 2934, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3219, 1446, -1634, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3219, 1446, -3513, 0, 0, 0, (17 << 16), bhvCoinFormation),
		OBJECT(MODEL_HF_CRYSTAL, 3219, 2020, -3296, 0, 0, 0, 0x00000000, bhvHfCrystal),
		OBJECT(MODEL_NONE, -1665, 1662, -1735, 0, 0, 0, 0x00000000, bhvHfDeathCtl),
		OBJECT(MODEL_NONE, 3976, 1846, -2593, 0, 0, 0, 0x00000000, bhvHfCrystalImageCtl),
		OBJECT(MODEL_EXCLAMATION_BOX, 4843, 1836, 1651, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1515, 1268, 3223, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1240, 1130, 4845, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -855, 910, 7928, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 1665, 4091, 69, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -6444, 3622, -2025, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -4863, 4660, -1994, 0, 0, 0, 0x00000000, bhvBlueCoinSwitch),
		OBJECT(MODEL_EXCLAMATION_BOX, 3175, 4002, 2955, 0, 0, 0, (6 << 16), bhvExclamationBox),
		OBJECT(MODEL_BOO, 267, 761, 2221, 0, 0, 0, (6 << 16), bhvBoo),
		OBJECT(MODEL_NONE, -2949, 2472, -4272, 0, -43, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 833, 1246, -1682, 0, -43, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 3332, 1693, 1285, 0, -43, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 4561, 2766, 2788, 0, -43, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_BOO, 3324, 3566, 921, 0, -43, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1651, 3957, 118, 0, -43, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_HEAVE_HO, -3956, 5543, 756, 0, 0, 0, (2 << 16), bhvHeaveHo),
		OBJECT(MODEL_HEAVE_HO, -3242, 1300, 2899, 0, 0, 0, (2 << 16), bhvHeaveHo),
		OBJECT(MODEL_HF_ICE, -6898, 6067, 22, 0, 14, 0, 0x00000000, bhvHfIce),
		OBJECT(MODEL_NONE, -2400, 5701, 1080, 0, 0, 0, 0x00000000, bhvHfIceBridgeCtl),
		OBJECT(MODEL_WOODEN_SIGNPOST, -4840, 9212, -419, 0, -90, 0, (97 << 24) | (97 << 16), bhvMessagePanel),
		OBJECT(MODEL_HF_ICE_POLE, -7747, 6012, -1891, 0, 14, 0, 0x00000000, bhvHfIcePole),
		OBJECT(MODEL_HF_ICE_POLE2, -5472, 7997, 34, 0, 0, 0, 0x00000000, bhvHfIcePole2),
		OBJECT(MODEL_NONE, -1792, 2472, -3642, 0, 1, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_HF_JOEL, -2638, -14, -7735, 0, 0, 0, (2 << 16), bhvHfJoel),
		OBJECT(MODEL_HF_JOEL, -4762, 301, -9486, 0, 0, 0, 0x00000000, bhvHfJoel),
		OBJECT(MODEL_HF_JOEL, -5746, 424, -11104, 0, 0, 0, (3 << 16), bhvHfJoel),
		OBJECT(MODEL_HF_JOEL, -4620, 688, -12738, 0, 0, 0, (4 << 16), bhvHfJoel),
		OBJECT(MODEL_HF_JOEL, -1424, -122, -6284, 0, 0, 0, (1 << 16), bhvHfJoel),
		OBJECT(MODEL_NONE, -1703, 445, 6848, 0, 172, 0, (0xa << 16), bhvAirborneWarp),
		OBJECT(MODEL_NONE, 1060, 2452, 5785, 0, 114, 0, (0x20 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 2427, 1770, -2560, 0, 90, 0, (0x21 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -2684, 92, -7180, 0, 0, 0, (0x22 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -5035, 2038, 2603, 0, -87, 0, (0x23 << 16), bhvDeathWarp),
		OBJECT(MODEL_BOO, 830, 1246, -1827, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6879, 3019, -3093, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6889, 2666, -4821, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -1732, 1813, -1833, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -2222, 1770, -1834, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1171, 1652, 1288, 0, 0, 0, (6 << 16), bhvBoo),
		OBJECT(MODEL_BOO, 1597, 3953, 494, 0, 0, 0, (6 << 16), bhvBoo),
		OBJECT(MODEL_BOO, -5847, 3560, -3965, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, -6620, 3972, -2159, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_BOO, 1412, 9480, -133, 0, 0, 0, 0x00000000, bhvBoo),
		OBJECT(MODEL_EXCLAMATION_BOX, -2689, 86, -6894, 0, 0, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_HF_SCARY_BOO, -2101, -443, -994, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1794, -443, -1135, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1721, -443, -1165, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1824, -443, -353, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1391, -443, -619, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1203, -443, -54, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1032, -443, -905, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_HF_SCARY_BOO, -1157, -443, -1815, 0, 0, 0, 0x00000000, bhvHfScaryBoo),
		OBJECT(MODEL_STAR, -4039, 1220, -13839, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_STAR, -93, 3749, -10855, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, 12257, 3693, 4241, 0, 0, 0, (3 << 24), bhvStar),
		OBJECT(MODEL_STAR, 6166, 3384, 9162, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR, 1519, 9787, -484, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, -6327, 4663, -2, 0, 0, 0, (4 << 24), bhvStar),
		OBJECT(MODEL_THWOMP, -2493, 2472, -5819, 0, -90, 0, 0x00000000, bhvThwomp),
		OBJECT(MODEL_THWOMP, -2493, 2472, -6482, 0, -90, 0, (1 << 16), bhvThwomp),
		OBJECT(MODEL_THWOMP, -2493, 2472, -7124, 0, -90, 0, (2 << 16), bhvThwomp),
		OBJECT(MODEL_THWOMP, -2493, 2472, -7737, 0, -90, 0, (3 << 16), bhvThwomp),
		OBJECT(MODEL_THWOMP, -2493, 2472, -8359, 0, -90, 0, (4 << 16), bhvThwomp),
		OBJECT(MODEL_THWOMP, -2493, 2472, -8982, 0, -90, 0, (5 << 16), bhvThwomp),
		OBJECT(MODEL_THWOMP, -2493, 2472, -9717, 0, -90, 0, (6 << 16), bhvThwomp),
		OBJECT(MODEL_NONE, 13066, 3394, 366, 0, 0, 0, 0x00000000, bhvHfWind),
		OBJECT(MODEL_NONE, 13055, 3394, 1380, 0, 0, 0, 0x00000000, bhvHfWind),
		OBJECT(MODEL_NONE, 13056, 3394, 2432, 0, 0, 0, 0x00000000, bhvHfWind),
		OBJECT(MODEL_NONE, 13051, 3394, 3845, 0, 0, 0, 0x00000000, bhvHfWind),
		OBJECT(MODEL_HF_CRYSTAL, 3219, 2020, -1793, 0, 0, 0, 0x00000000, bhvHfCrystal),
		TERRAIN(hf_area_1_collision),
		MACRO_OBJECTS(hf_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_C4),
		TERRAIN_TYPE(TERRAIN_SPOOKY),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -1698, 264, 6603),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
