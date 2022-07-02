#include "types.h"
#include "include/segment_symbols.h"
#include "memory.h"
#include "engine/math_util.h"
#include "src/engine/behavior_script.h"
#include "tile_scroll.h"
#include "texscroll.h"

#ifdef TARGET_N64
#define SCROLL_CONDITION(condition) condition
#else
#define SCROLL_CONDITION(condition) 1
#endif


#include "src/game/texscroll/castle_grounds_texscroll.inc.c"
#include "src/game/texscroll/ab_texscroll.inc.c"
#include "src/game/texscroll/mf_texscroll.inc.c"
#include "src/game/texscroll/bob_texscroll.inc.c"
#include "src/game/texscroll/group0_texscroll.inc.c"
#include "src/game/texscroll/df_texscroll.inc.c"
#include "src/game/texscroll/mtc_texscroll.inc.c"
#include "src/game/texscroll/hf_texscroll.inc.c"
#include "src/game/texscroll/pss_texscroll.inc.c"
#include "src/game/texscroll/vcm_texscroll.inc.c"
#include "src/game/texscroll/bdf_texscroll.inc.c"
#include "src/game/texscroll/bowser_2_texscroll.inc.c"
#include "src/game/texscroll/crash_texscroll.inc.c"
#include "src/game/texscroll/vcutm_texscroll.inc.c"
void scroll_textures() {
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_castle_grounds_segment_7SegmentRomStart)) {
		scroll_textures_castle_grounds();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_ab_segment_7SegmentRomStart)) {
		scroll_textures_ab();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_mf_segment_7SegmentRomStart)) {
		scroll_textures_mf();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bob_segment_7SegmentRomStart)) {
		scroll_textures_bob();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x4] == (uintptr_t)_group0_mio0SegmentRomStart)) {
		scroll_textures_group0();
	}
	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_df_segment_7SegmentRomStart)) {
		scroll_textures_df();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_mtc_segment_7SegmentRomStart)) {
		scroll_textures_mtc();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_hf_segment_7SegmentRomStart)) {
		scroll_textures_hf();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_pss_segment_7SegmentRomStart)) {
		scroll_textures_pss();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_vcm_segment_7SegmentRomStart)) {
		scroll_textures_vcm();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bdf_segment_7SegmentRomStart)) {
		scroll_textures_bdf();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_bowser_2_segment_7SegmentRomStart)) {
		scroll_textures_bowser_2();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_crash_segment_7SegmentRomStart)) {
		scroll_textures_crash();
	}

	if(SCROLL_CONDITION(sSegmentROMTable[0x7] == (uintptr_t)_vcutm_segment_7SegmentRomStart)) {
		scroll_textures_vcutm();
	}

}
