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
extern const GeoLayout wf_geo_0009B8[];
extern const GeoLayout wf_geo_000AB0[];
extern const GeoLayout wf_geo_000AC8[];
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
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 

	/* Fast64 begin persistent block [level commands] */
    LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM,             wf_geo_0009B8),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART,          wf_geo_000AB0),
    LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE,               wf_geo_000AC8),
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
	/*
		OBJECT(MODEL_BLACK_BOBOMB, -13011, -1836, -5583, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -11466, -1004, -5675, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -10361, 91, -2125, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -9999, 91, -3867, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -6884, 1872, -4701, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_BLACK_BOBOMB, -6190, 1872, -5984, 0, 0, 0, 0x00000000, bhvBobomb),
		OBJECT(MODEL_CHAIN_CHOMP, -9435, 186, -2788, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_EXCLAMATION_BOX, -1568, 2110, -6477, 0, 0, 0, (0x10 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -4059, 2521, -3612, 0, 0, 0, (0 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -1930, 604, -1609, 0, 0, 0, (0 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -925, 604, -4412, 0, -7, 0, (0 << 16), bhvExclamationBox),
		OBJECT(MODEL_PIRANHA_PLANT, -4028, 2194, -4732, 0, 0, 0, (0 << 16), bhvPiranhaPlant),
		OBJECT(MODEL_PIRANHA_PLANT, 374, 1730, -3896, 0, 0, 0, (0 << 16), bhvPiranhaPlant),
		OBJECT(MODEL_WHOMP, -1907, 604, -1263, 0, 0, 0, (0 << 16), bhvSmallWhomp),
		OBJECT(MODEL_NONE, -13596, -1836, -5765, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -11770, -1004, -4904, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -10240, 91, -3134, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -7289, 186, -8656, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, -8554, 186, -8161, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_NONE, -6471, 1872, -4766, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 1820, 1519, -4293, 0, 0, 0, (0 << 16), bhvGoombaTripletSpawner),
		OBJECT(MODEL_EXCLAMATION_BOX, 2878, 1922, -4619, 0, 0, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_KOOPA_WITHOUT_SHELL, 1149, 1623, -3720, 0, 0, 0, 0x00000000, bhvKoopa),
		OBJECT(MODEL_NONE, 3200, 1247, -7880, 0, 0, 0, 0x00000000, bhvFlamethrower),
		OBJECT(MODEL_WF_GIANT_POLE, -6463, 84, -8941, 0, 0, 0, 0x00000000, bhvGiantPole),
		OBJECT(MODEL_PURPLE_SWITCH, -10863, -1055, -4653, 0, 0, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_BREAKABLE_BOX, -11472, -538, -3937, 0, 0, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, -5794, 965, -8660, 0, 0, 0, (10 << 24), bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, -5389, 1501, -7513, 0, 0, 0, (10 << 24), bhvRotatingPlatform),
		OBJECT(MODEL_WF_ROTATING_PLATFORM, -5590, 2343, -2376, 0, 0, 0, (10 << 24), bhvRotatingPlatform),
		OBJECT(MODEL_STAR, -3826, 1117, 2123, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 9788, 3518, -6061, 0, 0, 0, (3 << 16), bhvStar),
		*/
		MARIO_POS(0x01, 0, -13371, -1894, -9343),
	/*
		OBJECT(MODEL_NONE, -13360, -1894, -9341, 0, 0, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -9758, 91, -2063, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -8753, 91, -2776, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -6602, 1872, -5418, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -7256, 1872, -4822, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -7161, 1872, -4155, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -5333, 891, 2106, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -3985, 891, 3763, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_COURTYARD_SPIKY_TREE, -2290, 891, 2327, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -13649, -1975, -7159, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -9768, 91, -3331, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -9100, 91, -2851, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -8501, 186, -7688, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -8957, 186, -8364, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7446, 186, -9237, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -14098, -1795, -5752, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -13005, -1836, -5041, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -13131, -1413, -3452, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12327, -1004, -5089, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -11674, -1004, -5232, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -11638, -1004, -4629, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -13305, 91, -541, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -12967, 91, 252, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -10267, 91, -2706, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -9106, 91, -3514, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_BOB_BUBBLY_TREE, -7131, 186, -8858, 0, 0, 0, 0x00000000, bhvTree),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, -8822, -49, -5299, 0, -24, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, -7097, 1945, -2474, 0, -14, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_WF_TUMBLING_BRIDGE, -889, 2110, -7276, 0, 50, 0, 0x00000000, bhvWfTumblingBridge),
		OBJECT(MODEL_NONE, -11678, -1836, -5636, 0, 0, 0, (0xb << 16), bhvWarp),
		OBJECT(MODEL_EXCLAMATION_BOX, -13419, 632, 41, 0, 0, 0, 0x00000000, bhvExclamationBox),
		OBJECT(MODEL_NONE, -11827, 623, 398, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -7863, 422, 618, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -8427, 476, 2568, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -4767, 1108, 4427, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -14261, -101, 2542, 0, 0, 0, 0x00000000, bhvHiddenStarTrigger),
		*/
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -13371, -1894, -9343),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
