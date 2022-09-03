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
#include "levels/spiders/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_spiders_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x7, _spiders_segment_7SegmentRomStart, _spiders_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bidw_skybox_mio0SegmentRomStart, _bidw_skybox_mio0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_BEE, spiders_bee_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_BEE_ANGY, spiders_bee_angy_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_BEE_BLUE, spiders_bee_blue_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_BOARDOS, spiders_bee_boardos_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_NEST, spiders_waterfally_nest_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_PA, spiders_waterfally_pa_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_PB, spiders_waterfally_pb_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_SWITCH, waterfally_switch_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_SWITCHBLOCK, waterfally_switchblock_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_SPIDERS_GATE, spiders_cage_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, spiders_area_1),
		OBJECT(MODEL_NONE, -9127, 654, 6215, 0, -18, 0, 0x00000000, bhvCoinFormation),
		MARIO_POS(0x01, 0, 4949, 7, -8493),
		OBJECT(MODEL_SPIDERS_BEE_BLUE, -9890, 1190, 4697, 0, -29, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_SPIDERS_BOARDOS, -1475, 2339, -2548, 0, -59, 0, 0x00000000, bhvSpidersBoardos),
		OBJECT(MODEL_SPIDERS_BOARDOS, 4389, 2342, -2536, 0, 31, 0, 0x00000000, bhvSpidersBoardos),
		OBJECT(MODEL_SPIDERS_BOARDOS, -4, 2339, 4, 0, 31, 0, 0x00000000, bhvSpidersBoardos),
		OBJECT(MODEL_BREAKABLE_BOX, -1041, 4, -1772, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -768, 6, -1348, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, -475, 17, -859, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -881, 5829, 8832, 0, -59, 0, (2 << 16), bhvExclamationBox),
		OBJECT(MODEL_BREAKABLE_BOX, 3532, 12, 1002, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 3867, 24, 1549, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 4212, 44, 2149, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_BREAKABLE_BOX, 4606, 61, 2805, 0, -59, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_SPIDERS_GATE, 8256, 0, 3757, 0, -51, 0, 0x00000000, bhvSpidersCage),
		OBJECT(MODEL_SPIDERS_BEE_BLUE, 8247, 0, 3505, 0, -51, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_SPIDERS_BEE, 9211, 3921, 2372, 0, -51, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_SPIDERS_SWITCHBLOCK, 9569, 1347, 1610, 0, -32, 0, 0x00000000, bhvSpidersGateSwitch),
		OBJECT(MODEL_PURPLE_SWITCH, -2331, 0, -3310, 0, -29, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_SPIDERS_BEE_BLUE, -3705, 0, -3298, 0, -29, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_PURPLE_SWITCH, -6476, -69, -8133, 0, -63, 0, 0x00000000, bhvPurpleSwitchHiddenBoxes),
		OBJECT(MODEL_SPIDERS_BEE_BLUE, -6793, -69, -8680, 0, -61, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_SPIDERS_BEE_BLUE, -5088, 1262, -5052, 0, -114, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_SPIDERS_BEE_BLUE, 3488, 0, -50, 0, -114, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_SPIDERS_BEE_ANGY, 10466, 368, 2922, 0, -114, 0, 0x00000000, bhvBobombBuddy),
		OBJECT(MODEL_RED_COIN, -7222, -2, -2625, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2843, 357, 2422, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3812, 357, 4081, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 7102, -164, -4254, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -1899, -472, -5146, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5191, 441, -12578, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5112, 357, 2959, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -8082, 12, -7568, 0, 31, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -9647, 62, 3183, 0, 31, 0, (4 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_NONE, -4097, 1744, -5338, 0, 31, 0, (3 << 24), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -6254, 1561, -6009, 0, 31, 0, (3 << 24), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -5856, 2334, -5464, 0, 31, 0, (3 << 24), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -6484, 2363, -6721, 0, 31, 0, (3 << 24), bhvHiddenStarTrigger),
		OBJECT(MODEL_NONE, -5637, 2386, -7294, 0, 31, 0, (3 << 24), bhvHiddenStarTrigger),
		OBJECT(MODEL_SPIDERS_NEST, -4097, 1744, -5338, 0, 31, 0, (15 << 16), bhvHiddenStar),
		OBJECT(MODEL_SPIDERS_NEST, -6254, 1561, -6009, 0, 31, 0, (15 << 16), bhvHiddenStar),
		OBJECT(MODEL_SPIDERS_NEST, -5856, 2334, -5464, 0, 31, 0, (15 << 16), bhvHiddenStar),
		OBJECT(MODEL_SPIDERS_NEST, -6484, 2363, -6721, 0, 31, 0, (15 << 16), bhvHiddenStar),
		OBJECT(MODEL_SPIDERS_NEST, -5637, 2386, -7294, 0, 31, 0, (15 << 16), bhvHiddenStar),
		OBJECT(MODEL_STAR, 4355, 2917, -4081, 0, 31, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, -1261, 3662, 9473, 0, -59, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 8661, 284, 3738, 0, 31, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR, -5364, 3403, -6078, 0, 31, 0, (3 << 24), bhvHiddenStar),
		OBJECT(MODEL_SPIDERS_PA, -913, 1667, 8871, 0, -51, 0, 0x00000000, bhvSpidersPA),
		OBJECT(MODEL_SPIDERS_PB, -913, 1967, 8871, 0, -51, 0, 0x00000000, bhvSpidersPB),
		OBJECT(MODEL_SPIDERS_PA, -913, 2867, 8871, 0, -51, 0, 0x00000000, bhvSpidersPA),
		OBJECT(MODEL_SPIDERS_PB, -913, 3167, 8871, 0, -51, 0, 0x00000000, bhvSpidersPB),
		TERRAIN(spiders_area_1_collision),
		MACRO_OBJECTS(spiders_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_HONEY),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 4949, 7, -8493),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
