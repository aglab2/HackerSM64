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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR, haunted_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(WARP_NODE_MAIN_ENTRY, LEVEL_CASTLE_GROUNDS, 0x01, 0x25, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEFAULT, LEVEL_CASTLE_GROUNDS, 0x01, 0x35, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 0x01, 0x45, WARP_NO_CHECKPOINT),
		WARP_NODE(0x20, LEVEL_BOB, 0x01, 0x20, WARP_NO_CHECKPOINT),
		WARP_NODE(0x21, LEVEL_BOB, 0x01, 0x21, WARP_NO_CHECKPOINT),
		WARP_NODE(0x22, LEVEL_BOB, 0x01, 0x22, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CASTLE_GROUNDS, 0x01, 0x55, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLUE_COIN, -1324, 372, 2713, 0, 90, 0, (30 << 16) | (1), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1324, 372, 3325, 0, 90, 0, (30 << 16) | (1), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, -1324, 372, 4148, 0, 90, 0, (30 << 16) | (1), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1564, 372, 2713, 0, 90, 0, (30 << 16) | (1), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1564, 372, 3325, 0, 90, 0, (30 << 16) | (1), bhvHiddenBlueCoin),
		OBJECT(MODEL_BLUE_COIN, 1564, 372, 4148, 0, 90, 0, (30 << 16) | (1), bhvHiddenBlueCoin),
		OBJECT(MODEL_NONE, 2, -163, 3210, 0, -180, 0, (COIN_FORMATION_FLAG_ARROW << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -4839, 1773, 5477, 0, -90, 0, (0 << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2480, 1773, 374, 0, -90, 0, (0 << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1341, 992, 3821, 0, -180, 0, (0 << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1577, 992, 3821, 0, -180, 0, (0 << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 104, 2043, 4178, 0, -180, 0, (COIN_FORMATION_FLAG_RING << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, -74, -78, 5304, 0, 0, 0, (0xA << 16), bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, 76, -78, 5304, 0, -180, 0, (0xB << 16), bhvDoorWarp),
		OBJECT(MODEL_PURPLE_SWITCH, 107, 4038, -3003, 0, 0, 0, (0 << 16) | (4), bhvFloatingPlatSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, 3473, 3317, 1205, 0, 90, 0, (0 << 16) | (0), bhvFloatingPlatSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, 912, 231, 6689, 0, 0, 0, (0 << 16) | (2), bhvFloatingPlatSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, 2, -163, 3908, 0, 0, 0, (0 << 16) | (1), bhvFloatingPlatSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, 106, -2824, -7871, 0, -180, 0, (0 << 16) | (5), bhvFloatingPlatSwitch),
		OBJECT(MODEL_FLOATING_PLAT, -704, 1233, 3419, 0, 90, 0, (74 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -704, 71, 4627, 0, 90, 0, (25 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 851, 71, 4627, 0, 90, 0, (25 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 531, 1528, 3419, 0, 90, 0, (45 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -704, 71, 4314, 0, 90, 0, (55 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 851, 71, 4314, 0, 90, 0, (55 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -384, 1528, 3419, 0, 90, 0, (45 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 851, 1233, 3419, 0, 90, 0, (74 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 888, 4097, -4144, 0, 90, 0, (67 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 3486, 1805, 2134, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 4326, 1805, 2134, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 4326, 1805, 1300, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 4326, 1805, 608, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 5193, 1805, 608, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 5193, 1805, 1395, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 5193, 1805, 2196, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 3486, 1805, 1598, 0, 90, 0, (182 << 16) | (0), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 1256, 310, 7023, 0, 90, 0, (34 << 16) | (2), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 2340, 310, 7023, 0, 90, 0, (86 << 16) | (2), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 888, 4097, -3681, 0, 90, 0, (43 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 108, 4097, -3681, 0, 90, 0, (43 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -880, 4097, -3681, 0, 90, 0, (43 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 888, 4097, -5636, 0, 90, 0, (43 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 108, 4097, -5636, 0, 90, 0, (43 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -880, 4097, -5636, 0, 90, 0, (43 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -880, 4097, -4665, 0, 90, 0, (95 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 105, 4097, -4665, 0, 90, 0, (95 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 888, 4097, -4665, 0, 90, 0, (95 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 108, 4097, -4144, 0, 90, 0, (67 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -880, 4097, -4144, 0, 90, 0, (67 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 888, 4097, -5159, 0, 90, 0, (67 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 108, 4097, -5159, 0, 90, 0, (67 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -880, 4097, -5159, 0, 90, 0, (67 << 16) | (4), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 111, -2423, -8524, 0, 90, 0, (45 << 16) | (5), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 111, -3257, -11029, 0, 90, 0, (32 << 16) | (5), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 111, -3126, -11029, 0, 90, 0, (92 << 16) | (5), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 1564, -28, 3326, 0, 90, 0, (30 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 1564, -28, 4145, 0, 90, 0, (30 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, 1564, -28, 2713, 0, 90, 0, (30 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -1324, -28, 2713, 0, 90, 0, (30 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -1324, -28, 3326, 0, 90, 0, (30 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_FLOATING_PLAT, -1324, -28, 4145, 0, 90, 0, (30 << 16) | (1), bhvFloatingPlat),
		OBJECT(MODEL_NONE, 359, 2641, 1005, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 71, 3398, 1013, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 114, -377, -7689, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1491, -377, -7689, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -180, 1726, 7298, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 302, 720, 6710, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6062, 1922, 331, 0, 0, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 68, -163, 3014, 0, 0, 0, (0 << 16) | (0), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 402, -1567, 246, 0, 0, 0, (0 << 16) | (0), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 1686, -2460, -6457, 0, 0, 0, (0 << 16) | (0), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -1442, -3287, -8581, 0, 0, 0, (0 << 16) | (0), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -7817, 1768, 4276, 0, 0, 0, (0 << 16) | (0), bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 2005, 231, 7177, 0, 0, 0, (0 << 16) | (0), bhvGoombaTripletSpawner),
		OBJECT(MODEL_HANGING_PLAT, -570, -1006, -2154, 0, 0, 0, (1 << 16) | (0 << 8) | (14), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, -466, -648, -4355, 0, 0, 0, (1 << 16) | (0 << 8) | (14), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, 6062, 2200, 332, 0, 0, 0, (0 << 16) | (0 << 8) | (11), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, 92, -845, -6096, 0, 0, 0, (40 << 24) | (0 << 16) | (0 << 8) | (9), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, -1493, -450, -7696, 0, 0, 0, (41 << 24) | (0 << 16) | (0 << 8) | (17), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, 107, -450, -7696, 0, 0, 0, (41 << 24) | (0 << 16) | (0 << 8) | (17), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, 751, -444, -8122, 0, 0, 0, (65 << 24) | (0 << 16) | (0 << 8) | (20), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, 1890, -2950, -8762, 0, 0, 0, (40 << 24) | (0 << 16) | (0 << 8) | (9), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, -1409, -2970, -10101, 0, 0, 0, (40 << 24) | (0 << 16) | (0 << 8) | (20), bhvHangingPlat),
		OBJECT(MODEL_HANGING_PLAT, 751, -444, -6521, 0, 0, 0, (41 << 24) | (0 << 16) | (0 << 8) | (17), bhvHangingPlat),
		OBJECT(MODEL_RED_COIN, 109, -1671, -8524, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1883, -2279, -8775, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 1570, -1264, -6746, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1508, -1706, -6966, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1508, -1551, -8229, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 109, -3199, -11028, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 109, -1838, -11028, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1405, -2272, -8805, 0, 0, 0, (0 << 16) | (0), bhvRedCoin),
		OBJECT(MODEL_SCUTTLEBUG, 1721, 992, 3380, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -1424, 992, 3219, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -3234, 1768, 343, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, 2700, 1768, 483, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -6700, 1768, 3710, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -7258, 1768, 4825, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -7926, 1768, 4098, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_SCUTTLEBUG, -6992, 3266, 4147, 0, 0, 0, (0 << 16) | (0), bhvScuttlebug),
		OBJECT(MODEL_NONE, 109, -1728, -6541, 0, 0, 0, (0 << 16) | (0), bhvHiddenRedCoinStar),
		OBJECT(MODEL_STAR, 5617, 3818, 2119, 0, 0, 0, (1 << 24) | (0 << 8), bhvStar),
		OBJECT(MODEL_STAR, -7301, 4511, 1848, 0, 0, 0, (2 << 24) | (0 << 8), bhvStar),
		OBJECT(MODEL_STAR, 2380, 1639, 4725, 0, 0, 0, (3 << 24) | (0 << 8), bhvStar),
		OBJECT(MODEL_STAR, 120, 846, -10102, 0, 0, 0, (4 << 24) | (0 << 8), bhvStar),
		OBJECT(MODEL_BOO, 118, 5252, -4658, 0, 0, 0, (5 << 24) | (0 << 8), bhvBalconyBigBoo),
		OBJECT(MODEL_STICKY_PLAT, -1334, 1376, 2143, 0, 0, 0, (1 << 16) | (2), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, 1623, 1376, 2143, 0, 0, 0, (1 << 16) | (2), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, -6633, 3219, 5284, 0, 90, 0, (2 << 16) | (2), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, 364, 374, 6696, 0, 130, 0, (0 << 16) | (14), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, -182, 1433, 7332, 0, 0, 0, (0 << 16) | (12), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, 1788, 943, 7015, 0, 0, 0, (2 << 16) | (12), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, 2874, 1521, 7015, 0, 90, 0, (2 << 16) | (12), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, -6773, 3731, 3042, 0, 90, 0, (2 << 16) | (2), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, -8065, 4169, 3946, 0, -180, 0, (1 << 16) | (2), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, 1558, -1856, -6775, 0, 90, 0, (2 << 16) | (12), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, -1507, -1948, -6519, 0, 0, 0, (1 << 16) | (12), bhvStickyPlat),
		OBJECT(MODEL_STICKY_PLAT, -1507, -1539, -7419, 0, -180, 0, (1 << 16) | (12), bhvStickyPlat),
		OBJECT(MODEL_BLUE_COIN_SWITCH, 1595, -78, 1876, 0, 90, 0, (30 << 16) | (1), bhvBlueCoinSwitch),
		OBJECT(MODEL_BLUE_COIN_SWITCH, -1329, -78, 1876, 0, 90, 0, (30 << 16) | (1), bhvBlueCoinSwitch),
		OBJECT(MODEL_NONE, 870, -1509, -714, 0, 0, 0, (1 << 16) | (0 << 8), bhvCoinFormation),
		OBJECT(MODEL_NONE, -570, -1509, -714, 0, 0, 0, (1 << 16) | (0 << 8), bhvCoinFormation),
		OBJECT(MODEL_NONE, -704, 425, 4624, 0, 90, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 851, 425, 4624, 0, 90, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1512, -1739, -5627, 0, 90, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1601, -1739, -5627, 0, 90, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1512, -2523, -7346, 0, 90, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1601, -2523, -7346, 0, 90, 0, ((COIN_FORMATION_FLAG_VERTICAL | COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1589, -2460, -6436, 0, 90, 0, (COIN_FORMATION_FLAG_RING << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 97, -1278, -2530, 0, 0, 0, (COIN_FORMATION_FLAG_RING << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, -1523, -2460, -6436, 0, 90, 0, (COIN_FORMATION_FLAG_RING << 16) | (0), bhvCoinFormation),
		
		OBJECT(MODEL_NONE, 124, -1250, -511, 0, 180, 0, (0x20 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, 316, 2235, 6678, 0, 0, 0, (0x21 << 16), bhvDeathWarp),
		OBJECT(MODEL_NONE, -4221, 2062, 317, 0, 0, 0, (0x22 << 16), bhvDeathWarp),

		OBJECT(MODEL_NONE, 6087, 3300, 821, 0, 0, 0, ((COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 6087, 3300, 1821, 0, 0, 0, ((COIN_FORMATION_FLAG_FLYING) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 76, 2547, 1181, 0, 0, 0, ((COIN_FORMATION_FLAG_ARROW) << 16) | (0), bhvCoinFormation),
		OBJECT(MODEL_NONE, 3517, 3788, 1169, 0, 0, 0, 0, bhvCheckpoint),

		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0, 0x23),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(7, bob_area_7),
		WARP_NODE(WARP_NODE_MAIN_ENTRY, LEVEL_BOB, 0x01, WARP_NODE_MAIN_ENTRY, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEFAULT, LEVEL_CASTLE_GROUNDS, 0x01, 0x1B, WARP_NO_CHECKPOINT),
		WARP_NODE(WARP_NODE_DEATH, LEVEL_CASTLE_GROUNDS, 0x01, 0x1C, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_BOB, 0x02, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0C, LEVEL_BOB, 0x02, 0x0B, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, -180, -809, -5141, 0, 0, 0, (0xB << 16), bhvDoorWarp),
		OBJECT(MODEL_BBH_HAUNTED_DOOR, -30, -809, -5141, 0, -180, 0, (0xC << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 0, -328, 13, 0, 0, 0, (0xA << 16), bhvAirborneWarp),
		TERRAIN(bob_area_7_collision),
		MACRO_OBJECTS(bob_area_7_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
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
