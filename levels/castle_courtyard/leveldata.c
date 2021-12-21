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
#include "levels/castle_courtyard/texture.inc.c"
#include "levels/castle_courtyard/areas/1/1/model.inc.c"
#include "levels/castle_courtyard/areas/1/spire/model.inc.c"
#include "levels/castle_courtyard/areas/1/2/model.inc.c"
#include "levels/castle_courtyard/areas/1/3/model.inc.c"
#include "levels/castle_courtyard/areas/1/collision.inc.c"
#include "levels/castle_courtyard/areas/1/macro.inc.c"
#include "levels/castle_courtyard/areas/1/movtext.inc.c"

// 0x07003000 - 0x07004000
ALIGNED8 static const Texture ttm_seg7_texture_07003000[] = {
#include "levels/ttm/6.rgba16.inc.c"
};

// 0x07004000 - 0x07005000
ALIGNED8 static const Texture ttm_seg7_texture_07004000[] = {
#include "levels/ttm/7.rgba16.inc.c"
};

#include "levels/ttm/areas/1/painting.inc.c"

#include "levels/castle_courtyard/leveldata.inc.c"
