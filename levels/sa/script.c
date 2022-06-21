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
#include "levels/sa/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_sa_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _sa_segment_7SegmentRomStart, _sa_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _inside_yay0SegmentRomStart, _inside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_BLINKING_PLATFORM, blinking_platform_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_METEOR_A, meteor_a_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_METEOR_B, meteor_b_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, sa_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x30, LEVEL_SA, 0x01, 0x31, WARP_NO_CHECKPOINT),
		WARP_NODE(0x31, LEVEL_SA, 0x01, 0x31, WARP_NO_CHECKPOINT),
		INSTANT_WARP(0x00, 0x02, 0, 0, 0),
		OBJECT(MODEL_BLINKING_PLATFORM, 13068, 400, 0, 0, 0, 0, (0x1E << 8), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 12768, 700, 0, 0, 0, 0, (0x1E << 8), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 12468, 1000, 0, 0, 0, 0, (0x1E << 8), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 10186, 1000, 0, 0, 0, 0, (0x01 << 24) | (0x1E << 8), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 10486, 1000, 0, 0, 0, 0, (0x00 << 24) | (0x1E << 8), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 8431, 2800, 0, 0, 0, 0, (0x01 << 24) | (20 << 8) | (60), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 9181, 3100, 0, 0, 0, 0, (0x01 << 24) | (20 << 8) | (60), bhvBlinkingPlatform),
		OBJECT(MODEL_BLINKING_PLATFORM, 9886, 1000, 0, 0, 0, 0, (0x02 << 24) | (0x1E << 8), bhvBlinkingPlatform),
		MARIO_POS(0x01, 0, 15144, 200, 0),
		OBJECT(MODEL_METEOR_A, 15277, 368, 2873, 0, 0, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_B, 13332, 824, 3572, 0, 0, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_A, 11630, 1679, 2873, 0, 0, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_B, 9896, 1279, 4099, 0, 0, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_B, 8224, 1750, 2041, 0, 0, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_A, 8067, 368, -3955, 0, -180, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_B, 10012, 824, -4653, 0, -180, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_A, 11713, 1679, -3955, 0, -180, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_B, 13447, 1279, -5180, 0, -180, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_METEOR_B, 15120, 1750, -3122, 0, -180, 0, 0x00000000, bhvMeteor),
		OBJECT(MODEL_SPRING, 14959, 100, -324, 0, 0, 0, (0x00 << 16), bhvSpring),
		OBJECT(MODEL_SPRING, 15138, 100, -324, 0, 0, 0, (0x01 << 16), bhvSpring),
		OBJECT(MODEL_SPRING, 15309, 100, -324, 0, 0, 0, (0x02 << 16), bhvSpring),
		OBJECT(MODEL_NONE, 10188, 138, 11, 0, 0, 0, (0x30 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 10822, 2276, 485, 0, 0, 0, (0x31 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 15144, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(sa_area_1_collision),
		ROOMS(sa_area_1_collision_rooms),
		MACRO_OBJECTS(sa_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_C1),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, sa_area_2),
		OBJECT(MODEL_BULLET_BILL, 15214, 5203, -1057, 0, -90, 0, 0x00000000, bhvBulletBill),
		TERRAIN(sa_area_2_collision),
		MACRO_OBJECTS(sa_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 15144, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
