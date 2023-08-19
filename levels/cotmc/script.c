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
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _ow_skybox_mio0SegmentRomStart, _ow_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_17), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE, warp_pipe_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cotmc_area_1),
		WARP_NODE(6, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(0, LEVEL_BOB, 1, 10, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_BBH, 1, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(240, LEVEL_BBH, 1, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(14, LEVEL_COTMC, 1, 13, WARP_NO_CHECKPOINT),
		WARP_NODE(13, LEVEL_COTMC, 1, 14, WARP_NO_CHECKPOINT),
		WARP_NODE(12, LEVEL_COTMC, 1, 11, WARP_NO_CHECKPOINT),
		WARP_NODE(11, LEVEL_COTMC, 1, 12, WARP_NO_CHECKPOINT),
		WARP_NODE(10, LEVEL_COTMC, 1, 10, WARP_NO_CHECKPOINT),
		OBJECT(212, 5839, -3802, -714, 0, 0, 0, 0x0, bhv1Up),
		OBJECT(195, 2105, -1156, 826, 0, 0, 0, 0x3f0000, bhvBobombBuddy),
		OBJECT(0, -5281, -245, -5060, 0, 0, 0, 0x0, bhvBowserCourseRedCoinStar),
		OBJECT(85, -7337, 1784, 5731, 0, 0, 0, 0x10000, bhvCapSwitch),
		OBJECT(137, -8615, -941, 13487, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, -5661, 2089, 5731, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 7594, -260, -4060, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 413, -729, 1313, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 8437, -4010, 11043, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(137, 8340, -938, 5986, 0, 0, 0, 0x10000, bhvExclamationBox),
		OBJECT(0, -6612, 1024, -3351, 0, 107, 0, 0xd0000, bhvFadingWarp),
		OBJECT(0, 1980, 768, 6618, 0, -151, 0, 0xe0000, bhvFadingWarp),
		OBJECT(0, 7282, -4545, 7621, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 7420, -4545, 12592, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 3219, -4545, 8826, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 4151, -4545, 9680, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(0, 3205, -4546, 11841, 0, 0, 0, 0x40000, bhvFlamethrower),
		OBJECT(207, 647, -1610, -6444, 0, 0, 0, 0x0, bhvFloorSwitchHiddenObjects),
		OBJECT(0, 4188, -602, -2551, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 1592, -602, -3106, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(0, 6961, -4286, 10018, 0, 0, 0, 0x0, bhvGoombaTripletSpawner),
		OBJECT(129, -2549, -602, -4030, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(129, -2749, -410, -4030, 0, 0, 0, 0x0, bhvHiddenObject),
		OBJECT(194, -5273, -1253, 5869, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(194, -8997, 625, 5143, 0, 0, 0, 0x0, bhvHomingAmp),
		OBJECT(124, 6408, -602, -4846, 0, 0, 0, 0x660000, bhvMessagePanel),
		OBJECT(116, 3430, -602, -7279, 0, 0, 0, 0x0, bhvMoneybagHidden),
		OBJECT(120, 5464, -4234, 12927, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(120, 3853, -531, -3928, 0, 0, 0, 0x0, bhvRecoveryHeart),
		OBJECT(215, -241, -1278, -875, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 972, -2608, -3496, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -2749, 261, -4030, 4, 0, 1, 0x0, bhvRedCoin),
		OBJECT(215, 392, -1253, 9826, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -8100, 2729, 7575, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, -5680, 552, -2998, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 5693, -3750, -3060, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(215, 4497, -602, -8663, 0, 0, 0, 0x0, bhvRedCoin),
		OBJECT(0, 1257, -1156, 187, 0, 0, 0, 0xa0000, bhvSpinAirborneWarp),
		OBJECT(122, 2548, -3646, 10916, 0, 0, 0, 0x1000000, bhvStar),
		OBJECT(122, 5134, 3021, -8184, 0, 0, 0, 0x2000000, bhvStar),
		OBJECT(22, 11874, -602, -2254, 0, -81, 0, 0xb0000, bhvWarpPipe),
		OBJECT(22, 10137, -3815, -1903, 0, -90, 0, 0xc0000, bhvWarpPipe),
		TERRAIN(cotmc_area_1_collision),
		MACRO_OBJECTS(cotmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, 40),
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
