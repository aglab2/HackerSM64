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
#include "levels/castle_inside/texture.inc.c"
#include "levels/castle_inside/painting.inc.c"
#include "levels/castle_inside/areas/1/1/model.inc.c"
#include "levels/castle_inside/areas/1/2/model.inc.c"
#include "levels/castle_inside/areas/1/3/model.inc.c"
#include "levels/castle_inside/areas/1/4/model.inc.c"
#include "levels/castle_inside/areas/1/5/model.inc.c"
#include "levels/castle_inside/areas/1/6/model.inc.c"
#include "levels/castle_inside/areas/1/7/model.inc.c"
#include "levels/castle_inside/areas/1/8/model.inc.c"
#include "levels/castle_inside/areas/1/9/model.inc.c"
#include "levels/castle_inside/areas/1/10/model.inc.c"
#include "levels/castle_inside/areas/1/11/model.inc.c"
#include "levels/castle_inside/areas/1/12/model.inc.c"
#include "levels/castle_inside/areas/1/13/model.inc.c"
#include "levels/castle_inside/areas/1/14/model.inc.c"
#include "levels/castle_inside/areas/1/15/model.inc.c"
#include "levels/castle_inside/areas/1/16/model.inc.c"
#include "levels/castle_inside/areas/1/17/model.inc.c"
#include "levels/castle_inside/areas/1/18/model.inc.c"
#include "levels/castle_inside/areas/1/19/model.inc.c"
#include "levels/castle_inside/areas/1/20/model.inc.c"
#include "levels/castle_inside/areas/1/21/model.inc.c"
#include "levels/castle_inside/areas/1/22/model.inc.c"
#include "levels/castle_inside/areas/1/23/model.inc.c"
#include "levels/castle_inside/areas/1/24/model.inc.c"
#include "levels/castle_inside/areas/1/25/model.inc.c"
#include "levels/castle_inside/areas/1/26/model.inc.c"
#include "levels/castle_inside/trap_door/model.inc.c"
#include "levels/castle_inside/areas/2/1/model.inc.c"
#include "levels/castle_inside/areas/2/2/model.inc.c"
#include "levels/castle_inside/areas/2/3/model.inc.c"
#include "levels/castle_inside/areas/2/4/model.inc.c"
#include "levels/castle_inside/areas/2/5/model.inc.c"
#include "levels/castle_inside/areas/2/6/model.inc.c"
#include "levels/castle_inside/areas/2/7/model.inc.c"
#include "levels/castle_inside/areas/2/8/model.inc.c"
#include "levels/castle_inside/areas/2/9/model.inc.c"
#include "levels/castle_inside/areas/2/pendulum/model.inc.c"
#include "levels/castle_inside/areas/2/10/model.inc.c"
#include "levels/castle_inside/areas/2/11/model.inc.c"
#include "levels/castle_inside/areas/2/12/model.inc.c"
#include "levels/castle_inside/areas/2/13/model.inc.c"
#include "levels/castle_inside/areas/2/14/model.inc.c"
#include "levels/castle_inside/areas/2/15/model.inc.c"
#include "levels/castle_inside/clock_minute_hand/model.inc.c"
#include "levels/castle_inside/clock_hour_hand/model.inc.c"
#include "levels/castle_inside/areas/3/1/model.inc.c"
#include "levels/castle_inside/areas/3/2/model.inc.c"
#include "levels/castle_inside/areas/3/3/model.inc.c"
#include "levels/castle_inside/areas/3/4/model.inc.c"
#include "levels/castle_inside/areas/3/5/model.inc.c"
#include "levels/castle_inside/areas/3/6/model.inc.c"
#include "levels/castle_inside/areas/3/7/model.inc.c"
#include "levels/castle_inside/areas/3/8/model.inc.c"
#include "levels/castle_inside/areas/3/9/model.inc.c"
#include "levels/castle_inside/areas/3/10/model.inc.c"
#include "levels/castle_inside/areas/3/11/model.inc.c"
#include "levels/castle_inside/water_level_pillar/model.inc.c"
#include "levels/castle_inside/areas/1/collision.inc.c"
#include "levels/castle_inside/areas/2/collision.inc.c"
#include "levels/castle_inside/areas/3/collision.inc.c"
#include "levels/castle_inside/areas/1/macro.inc.c"
#include "levels/castle_inside/areas/2/macro.inc.c"
#include "levels/castle_inside/areas/3/macro.inc.c"
#include "levels/castle_inside/areas/1/room.inc.c"
#include "levels/castle_inside/areas/2/room.inc.c"
#include "levels/castle_inside/areas/3/room.inc.c"
#include "levels/castle_inside/trap_door/collision.inc.c"
#include "levels/castle_inside/water_level_pillar/collision.inc.c"
#include "levels/castle_inside/areas/3/trajectory.inc.c"
#include "levels/castle_inside/areas/3/movtext.inc.c"
