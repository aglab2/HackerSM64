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
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_COURTYARD_SPIKY_TREE, spiky_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 

	/* Fast64 begin persistent block [level commands] */
    LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART,          wf_geo_000AB0),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE,               wf_geo_000AC8),
    LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE,                    wf_geo_000AE0),
    LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM,             wf_geo_0009B8),
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 3, 0x11, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 3, 0x12, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BLACK_BOBOMB, -12257, -1423, -3267, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -10480, -466, -3372, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9209, 794, 710, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -8793, 794, -1292, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -5211, 2841, -2251, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -4413, 2841, -3727, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHAIN_CHOMP, -8145, 902, -51, 0, 0, 0, 0x00000000, bhvChainChomp),
		OBJECT(MODEL_EXCLAMATION_BOX, 903, 3116, -4294, 0, 0, 0, (0x10 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1962, 3588, -1000, 0, 0, 0, (0 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 486, 1383, 1305, 0, 0, 0, (0 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 1642, 1383, -1920, 0, -7, 0, (0 << 16), bhvExclamationBox),
		OBJECT(MODEL_PIRANHA_PLANT, -1926, 3212, -2288, 0, 0, 0, (0 << 16), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 3136, 2678, -1326, 0, 0, 0, (0 << 16), bhvPiranhaPlant),
		OBJECT(MODEL_WHOMP, 512, 1383, 1702, 0, 0, 0, (0 << 16), bhvSmallWhomp),
		OBJECT(MODEL_NONE, -12931, -1423, -3475, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10830, -466, -2485, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -9071, 794, -450, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -5677, 902, -6800, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -7131, 902, -6230, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_NONE, -4736, 2841, -2326, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 4799, 2435, -1782, 0, 0, 0, (0 << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_EXCLAMATION_BOX, 6015, 2899, -2158, 0, 0, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 4027, 2556, -1123, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_NONE, 6385, 2123, -5908, 0, 0, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_WF_GIANT_POLE, -4727, 786, -7128, 0, 0, 0, 0x00000000, bhvGiantPole),
		OBJECT(MODEL_PURPLE_SWITCH, -9787, -525, -2197, 0, 0, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_BREAKABLE_BOX, -10487, 70, -1373, 0, 0, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, -3958, 1799, -6804, 0, 0, 0, (10 << 24), bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, -3492, 2415, -5485, 0, 0, 0, (10 << 24), bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, -3724, 3383, 422, 0, 0, 0, (10 << 24), bhvRotatingPlatform),
		OBJECT(MODEL_STAR, -1694, 1973, 5596, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 13962, 4734, -3816, 0, 0, 0, (3 << 16), bhvStar),
		MARIO_POS(0x01, 0, -12671, -1489, -7590),
		OBJECT(MODEL_NONE, -12659, -1489, -7588, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -8517, 794, 782, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -7361, 794, -39, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -4887, 2841, -3076, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -5639, 2841, -2390, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -5529, 2841, -1624, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -3428, 1714, 5576, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -1877, 1714, 7482, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, 72, 1714, 5830, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12991, -1583, -5079, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -8528, 794, -676, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7760, 794, -124, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7071, 902, -5687, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7595, 902, -6464, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -5858, 902, -7469, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -13508, -1375, -3461, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12250, -1423, -2643, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12395, -936, -815, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -11470, -466, -2698, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -10720, -466, -2863, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -10678, -466, -2169, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12596, 794, 2533, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12207, 794, 3444, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -9102, 794, 42, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7767, 794, -887, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -5495, 902, -7033, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, -7440, 633, -2939, 0, -24, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, -5456, 2926, 309, 0, -14, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, 1683, 3116, -5213, 0, 50, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_NONE, -10725, -1423, -3327, 0, 0, 0, (0xb << 16), bhvWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, -12727, 1416, 3202, 0, 0, 0, 0x00000000, bhvExclamationBox),
		OBJECT(MODEL_NONE, -10896, 1405, 3612, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -6337, 1174, 3865, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -6986, 1236, 6108, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -2777, 1963, 8246, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -13694, 573, 6077, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 0x2a),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -12671, -1489, -7590),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
