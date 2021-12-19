#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "moving_texture_macros.h"
#include "level_misc_macros.h"
#include "macro_preset_names.h"
#include "special_preset_names.h"
#include "textures.h"

#include "make_const_nonconst.h"
#include "levels/wmotr/texture.inc.c"
#include "levels/wmotr/areas/1/model.inc.c"
#include "levels/wmotr/areas/1/collision.inc.c"
#include "levels/wmotr/areas/1/macro.inc.c"

// 0x0700FC00 - 0x0700FC18
static const Lights1 lll_seg7_lights_0700FC00 = gdSPDefLights1(
    0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

#include "levels/lll/moving_octagonal_mesh_platform/model.inc.c"
#include "levels/lll/moving_octagonal_mesh_platform/collision.inc.c"

#include "levels/wmotr/leveldata.inc.c"
