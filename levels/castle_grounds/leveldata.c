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

// 0x07078E14 - 0x07078E80
const Collision ow1_star_door_coll[] = {
    COL_INIT(),
    COL_VERTEX_INIT(0x8),
    COL_VERTEX(-80, 0, -20),
    COL_VERTEX(-80, 256, 20),
    COL_VERTEX(-80, 256, -20),
    COL_VERTEX(80, 256, 20),
    COL_VERTEX(80, 256, -20),
    COL_VERTEX(80, 0, -20),
    COL_VERTEX(-80, 0, 20),
    COL_VERTEX(80, 0, 20),
    COL_TRI_INIT(SURFACE_DEFAULT, 8),
    COL_TRI(2, 3, 4),
    COL_TRI(2, 1, 3),
    COL_TRI(5, 2, 4),
    COL_TRI(5, 0, 2),
    COL_TRI(6, 3, 1),
    COL_TRI(6, 7, 3),
    COL_TRI(5, 6, 0),
    COL_TRI(5, 7, 6),
    COL_TRI_STOP(),
    COL_END(),
};

#include "levels/castle_grounds/leveldata.inc.c"
