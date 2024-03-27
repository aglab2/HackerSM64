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
	LOAD_YAY0(0x05, _group3_yay0SegmentRomStart, _group3_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_4), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	LOAD_MODEL_FROM_DL(0xf0, powerbar_Plane_mesh, LAYER_ALPHA),

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		OBJECT(0xf0, -9004, -436, 2038, 0, 0, 0, 0x00000000, bhvCtl),
		OBJECT(MODEL_NONE, -9000, -593, -1264, 0, 0, 0, (1 << 16), bhvHole),
		OBJECT(MODEL_NONE, -1797, -1581, -1264, 0, 0, 0, (2 << 16), bhvHole),
		OBJECT(MODEL_NONE, -9597, -267, -12902, 0, 0, 0, (3 << 16), bhvHole),
		OBJECT(MODEL_NONE, 5551, -1544, 386, 0, 0, 0, (4 << 16), bhvHole),
		OBJECT(MODEL_NONE, 1088, -1392, -15030, 0, 0, 0, (5 << 16), bhvHole),
		OBJECT(MODEL_NONE, -13642, -1019, 12489, 0, 0, 0, (6 << 16), bhvHole),
		OBJECT(MODEL_NONE, 7196, -607, -12663, 0, 0, 0, (7 << 16), bhvHole),
		OBJECT(MODEL_NONE, 2102, -1325, 12086, 0, 0, 0, (8 << 16), bhvHole),
		OBJECT(MODEL_NONE, 10504, -1495, 7736, 0, 0, 0, (9 << 16), bhvHole),
		OBJECT(MODEL_NONE, 15, -1424, 2319, 0, 0, 0, (2 << 16), bhvInit),
		OBJECT(MODEL_NONE, -9602, -95, -9453, 0, 0, 0, (3 << 16), bhvInit),
		OBJECT(MODEL_NONE, 10508, -1397, 386, 0, 0, 0, (4 << 16), bhvInit),
		OBJECT(MODEL_NONE, -3022, -900, -11171, 0, 0, 0, (5 << 16), bhvInit),
		OBJECT(MODEL_NONE, -8857, -860, 12488, 0, 0, 0, (6 << 16), bhvInit),
		OBJECT(MODEL_NONE, 7194, -903, -6991, 0, 0, 0, (7 << 16), bhvInit),
		OBJECT(MODEL_NONE, 2081, -1160, 14618, 0, 0, 0, (8 << 16), bhvInit),
		OBJECT(MODEL_NONE, 10496, -1347, 15221, 0, 0, 0, (9 << 16), bhvInit),
		MARIO_POS(0x01, 0, -9002, -436, 2044),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -9002, -436, 2044),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
