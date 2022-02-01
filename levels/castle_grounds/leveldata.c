#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"
#include "dialog_ids.h"

#include "make_const_nonconst.h"
#include "levels/castle_grounds/texture.inc.c"
#include "levels/castle_grounds/areas/1/1/model.inc.c"
#include "levels/castle_grounds/areas/1/2/model.inc.c"
#include "levels/castle_grounds/areas/1/3/model.inc.c"
#include "levels/castle_grounds/areas/1/4/model.inc.c"
#include "levels/castle_grounds/areas/1/5/model.inc.c"
#include "levels/castle_grounds/areas/1/6/model.inc.c"
#include "levels/castle_grounds/areas/1/7/model.inc.c"
#include "levels/castle_grounds/areas/1/8/model.inc.c"
#include "levels/castle_grounds/areas/1/9/model.inc.c"
#include "levels/castle_grounds/areas/1/10/model.inc.c"
#include "levels/castle_grounds/areas/1/11/model.inc.c"
#include "levels/castle_grounds/areas/1/11/anim.inc.c"
#include "levels/castle_grounds/areas/1/12/model.inc.c" // Letter
#ifndef VERSION_JP
#include "levels/castle_grounds/areas/1/13/model.inc.c" // Peach signature
#endif
#include "levels/castle_grounds/areas/1/collision.inc.c"
#include "levels/castle_grounds/areas/1/macro.inc.c"
#include "levels/castle_grounds/areas/1/7/collision.inc.c"
#include "levels/castle_grounds/areas/1/8/collision.inc.c"
#include "levels/castle_grounds/areas/1/movtext.inc.c"

#include "levels/castle_grounds/leveldata.inc.c"

// 0x07079068 - 0x07079090
const Trajectory *const inside_castle_seg7_trajectory_mips[] = {
    castle_grounds_area_1_spline_mips_curve, castle_grounds_area_1_spline_mips_curve_001,
    castle_grounds_area_1_spline_mips_curve_002, castle_grounds_area_1_spline_mips_curve_003,
    castle_grounds_area_1_spline_mips_curve_004, castle_grounds_area_1_spline_mips_curve_005,
    castle_grounds_area_1_spline_mips_curve_006, castle_grounds_area_1_spline_mips_curve_007,
    castle_grounds_area_1_spline_mips_curve_008, castle_grounds_area_1_spline_mips_curve_009,
};

#include "levels/castle_grounds/chiaki/model.inc.c"