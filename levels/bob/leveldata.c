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
#include "levels/bob/texture.inc.c"
#include "levels/bob/areas/1/1/model.inc.c"
#include "levels/bob/areas/1/2/model.inc.c"
#include "levels/bob/areas/1/3/model.inc.c"
#include "levels/bob/areas/1/4/model.inc.c"
#include "levels/bob/areas/1/5/model.inc.c"
#include "levels/bob/areas/1/6/model.inc.c"
#include "levels/bob/chain_chomp_gate/model.inc.c"
#include "levels/bob/seesaw_platform/model.inc.c"
#include "levels/bob/areas/1/collision.inc.c"
#include "levels/bob/areas/1/macro.inc.c"
#include "levels/bob/chain_chomp_gate/collision.inc.c"
#include "levels/bob/seesaw_platform/collision.inc.c"
#include "levels/bob/areas/1/trajectory.inc.c"

#include "levels/bob/leveldata.inc.c"

#include "levels/wf/tumbling_bridge_near/model.inc.c"
#include "levels/wf/tumbling_bridge_far/model.inc.c"
#include "levels/wf/tumbling_bridge_near/collision.inc.c"
#include "levels/wf/areas/1/14/model.inc.c"
#include "levels/wf/areas/1/17/model.inc.c"
#include "levels/wf/rotating_platform/collision.inc.c"

// 0x07002000 - 0x07002800
ALIGNED8 static const Texture wf_seg7_texture_07002000[] = {
#include "levels/wf/4.rgba16.inc.c"
};

#include "levels/wf/large_bomp/model.inc.c"
#include "levels/wf/large_bomp/collision.inc.c"
#include "levels/wf/rotating_wooden_platform/1.inc.c"
#include "levels/wf/rotating_wooden_platform/2.inc.c"
#include "levels/wf/rotating_wooden_platform/collision.inc.c"

#include "levels/wdw/arrow_lift/model.inc.c"
#include "levels/wdw/arrow_lift/collision.inc.c"

#include "levels/wf/kickable_board/1.inc.c"
#include "levels/wf/kickable_board/2.inc.c"
#include "levels/wf/kickable_board/collision.inc.c"

#include "levels/wf/sliding_platform/model.inc.c"
#include "levels/wf/sliding_platform/collision.inc.c"
