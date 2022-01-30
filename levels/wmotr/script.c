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
#include "levels/wmotr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _fire_yay0SegmentRomStart, _fire_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0xb, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, lll_geo_000B08), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wmotr_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf0, LEVEL_CASTLE, 3, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0xf1, LEVEL_CASTLE, 3, 0x32, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 3940, 21, -3476),
		OBJECT(MODEL_NONE, -4489, 21, 8317, 0, 180, 0, (0xa << 16), bhvInstantActiveWarp),
		OBJECT(MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, 4660, -352, -4338, 0, 0, 0, 0x00000000, bhvLllMovingOctagonalMeshPlatform),
		OBJECT(MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, 3415, -346, -7061, 0, 0, 0, (1 << 16), bhvLllMovingOctagonalMeshPlatform),
		OBJECT(MODEL_BLUE_COIN, -4854, 18822, 8302, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4053, 107, 8296, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4495, 107, 8679, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4495, 107, 7870, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4473, 107, 7251, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4476, 107, 6515, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4094, 107, 5829, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4477, 107, 5446, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4015, 107, 5008, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3481, 107, 5252, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4708, 107, 4875, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5067, 107, 4152, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5364, 107, 3502, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4605, 107, 3635, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4981, 107, 2997, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5565, 107, 2517, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3863, 107, 3453, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3238, 107, 3283, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -2873, 107, 3915, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3408, 107, 4291, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -2915, 107, 4857, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -2047, 107, 4954, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4084, 232, 4281, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -876, 107, 4954, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 456, 107, 4792, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 1304, 107, 4027, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 1383, 107, 5016, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2277, 107, 4517, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 35, -98, 6579, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 717, -98, 6150, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 1428, -98, 6245, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2671, 298, 5422, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3047, 298, 6285, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2305, 654, 6991, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2227, 842, 7991, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3262, 1890, 7204, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3674, 1890, 7238, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3811, 1890, 7581, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3511, 1890, 7886, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3142, 842, 7660, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3138, 1270, 7663, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3138, 1664, 7663, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2852, 312, 5886, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 916, 107, 3377, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 1368, 107, 2606, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 989, 107, 1663, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 1683, 107, 283, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2557, 107, -679, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 2345, 107, -2093, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 1689, 107, -2588, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 889, 107, -2212, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 920, 107, -2894, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 628, 107, -3624, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 217, 107, -2724, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -184, 107, -3339, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -918, 107, -3542, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3811, 107, -3263, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4014, 6, -8142, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4014, 528, -8142, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4014, 949, -8142, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3614, 1114, -8496, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4492, 1114, -8123, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4944, 1114, -8354, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3503, 1114, -8908, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3951, 1114, -9195, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4268, 1114, -8761, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4858, 1114, -8883, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4703, -212, -7011, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4471, -212, -6026, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 4896, -212, -5049, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3641, -212, -6321, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3222, -212, -5390, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, 3424, -212, -4544, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -1709, 107, -2980, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -1939, 107, -4210, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3141, 107, -2963, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3014, 107, -3933, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4110, 107, -4017, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -2642, 107, -5129, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3922, 107, -5464, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3301, 107, -6192, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -3763, 107, -6882, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4270, 107, -6022, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5009, 107, -5384, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4811, 107, -4723, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5346, 107, -4143, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5322, 107, -3387, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -5832, 107, -4812, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6604, 107, -5583, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -7080, 107, -4674, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6575, 107, -3791, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -7441, 107, -3233, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6750, 107, -2219, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -7833, 107, -2112, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -7598, 107, -1475, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6555, 107, -1117, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6696, 107, 97, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6794, 107, 1190, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -8840, 747, -4801, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -4892, 113, 8297, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -7832, 400, -4259, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -7434, 107, -5609, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -8211, 107, -6141, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -9126, 107, -6512, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_BLUE_COIN, -6996, 107, -7515, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -4497, 424, 8322, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvMusicSwitcher),

		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_100CC),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 3940, 21, -3476),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
