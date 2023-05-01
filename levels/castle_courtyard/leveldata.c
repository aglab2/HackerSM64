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
#if 0
#include "levels/castle_courtyard/areas/1/1/model.inc.c"
#include "levels/castle_courtyard/areas/1/spire/model.inc.c"
#include "levels/castle_courtyard/areas/1/2/model.inc.c"
#include "levels/castle_courtyard/areas/1/3/model.inc.c"
#include "levels/castle_courtyard/areas/1/collision.inc.c"
#include "levels/castle_courtyard/areas/1/macro.inc.c"
#endif
#include "levels/castle_courtyard/areas/1/movtext.inc.c"
#include "levels/castle_courtyard/grill_door/model.inc.c"
#include "levels/castle_courtyard/grill_door/collision.inc.c" // This is odd, but the model data for this is in the middle of area 1. I have to conclude it is an area local object, despite the fact it has collision. Let's hope this is the only oddity...

#include "levels/castle_courtyard/leveldata.inc.c"
