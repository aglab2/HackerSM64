#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "surface_terrains.h"
#include "types.h"
#include "make_const_nonconst.h"

#include "bookend/model.inc.c"
#include "bookend/anims/data.inc.c"
#include "bookend/anims/table.inc.c"
UNUSED static const u64 binid_0 = 0;

#include "book/model.inc.c"
UNUSED static const u64 binid_1 = 1;

#include "chair/model.inc.c"
#include "chair/anims/data.inc.c"
#include "chair/anims/table.inc.c"
UNUSED static const u64 binid_2 = 2;

#include "small_key/model.inc.c"
UNUSED static const u64 binid_3 = 3;

#include "mad_piano/model.inc.c"
#include "mad_piano/anims/data.inc.c"
#include "mad_piano/anims/table.inc.c"
UNUSED static const u64 binid_4 = 4;

#include "boo/model.inc.c"
UNUSED static const u64 binid_5 = 5;

#include "haunted_cage/model.inc.c"
UNUSED static const u64 binid_6 = 6;

#include "penguin/model.inc.c"
#include "penguin/anims/data.inc.c"
#include "penguin/anims/table.inc.c"
#include "penguin/collision.inc.c"

// 0x05013128
ALIGNED8 static const Texture tornado_seg5_texture_05013128[] = {
#include "actors/tornado/tornado.ia16.inc.c"
};

#include "pokey/model.inc.c"
#include "tornado/model.inc.c"
