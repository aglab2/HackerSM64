#include <ultra64.h>
#include "sm64.h"
#include "geo_commands.h"

#include "game/level_geo.h"
#include "game/geo_misc.h"
#include "game/camera.h"
#include "game/moving_texture.h"
#include "game/screen_transition.h"
#include "game/paintings.h"

#include "make_const_nonconst.h"

#include "actors_vanilla/rr/header.h"

#include "actors_vanilla/rr/flying_carpet/geo.inc.c"
#include "actors_vanilla/rr/swinging_platform/geo.inc.c"
#include "actors_vanilla/rr/rotating_bridge_platform/geo.inc.c"
#include "actors_vanilla/rr/cruiser_wing/geo.inc.c"
#include "actors_vanilla/rr/octagonal_platform/geo.inc.c"
#include "actors_vanilla/rr/sliding_platform/geo.inc.c"
#include "actors_vanilla/rr/pyramid_platform/geo.inc.c" // unused
#include "actors_vanilla/rr/elevator_platform/geo.inc.c"
#include "actors_vanilla/rr/seesaw_platform/geo.inc.c"
#include "actors_vanilla/rr/donut_block/geo.inc.c"
#include "actors_vanilla/rr/l_platform/geo.inc.c" // also unused
#include "actors_vanilla/rr/tricky_triangles_1/geo.inc.c"
#include "actors_vanilla/rr/tricky_triangles_2/geo.inc.c"
#include "actors_vanilla/rr/tricky_triangles_3/geo.inc.c"
#include "actors_vanilla/rr/tricky_triangles_4/geo.inc.c"
#include "actors_vanilla/rr/tricky_triangles_5/geo.inc.c"
