#ifndef BOB_HEADER_H
#define BOB_HEADER_H

#include "types.h"

// geo
extern const GeoLayout bob_geo_000440[];
extern const GeoLayout bob_geo_000458[];
extern const GeoLayout bob_geo_000488[];

// leveldata
extern const Gfx bob_seg7_dl_07004390[];
extern const Gfx bob_seg7_dl_07009D80[];
extern const Gfx bob_seg7_dl_0700A470[];
extern const Gfx bob_seg7_dl_0700A920[];
extern const Gfx bob_seg7_dl_0700DD18[];
extern const Gfx bob_seg7_dl_0700E338[];
extern const Gfx bob_seg7_dl_0700E458[];
extern const Gfx bob_seg7_dl_0700E768[];
extern const Collision bob_seg7_collision_level[];
extern const MacroObject bob_seg7_macro_objs[];
extern const Collision bob_seg7_collision_chain_chomp_gate[];
extern const Collision bob_seg7_collision_bridge[];
extern const Collision bob_seg7_collision_gate[];
extern const Trajectory bob_seg7_metal_ball_path0[];
extern const Trajectory bob_seg7_metal_ball_path1[];
extern const Trajectory bob_seg7_trajectory_koopa[];

extern const GeoLayout wf_geo_000AB0[];
extern const GeoLayout wf_geo_000AC8[];
extern const GeoLayout wf_geo_000AE0[];
extern const GeoLayout wf_geo_0009B8[];
extern const Gfx wf_seg7_dl_0700BF50[];

extern const Gfx wf_seg7_dl_0700E9B8[];
extern const Gfx wf_seg7_dl_0700DE20[];
extern const Gfx wf_seg7_dl_0700E760[];
extern const GeoLayout wf_geo_000A58[];
extern const GeoLayout wf_geo_000A40[];

extern const GeoLayout wdw_geo_000598[];
extern const Gfx wdw_seg7_dl_07012E88[];

extern const Gfx wf_seg7_dl_0700F610[];
extern const Gfx wf_seg7_dl_0700F6C0[];
extern const Gfx wf_seg7_dl_0700EB40[];

extern const GeoLayout wf_geo_000BA8[];
extern const GeoLayout wf_geo_000BC8[];
extern const GeoLayout wf_geo_000A98[];

// script
extern const LevelScript level_bob_entry[];


#include "levels/bob/header.inc.h"

#include "levels/bob/tree_root/collision_header.h"

#include "levels/bob/tree_root/geo_header.h"

#include "levels/bob/tree_trunk/collision_header.h"

#include "levels/bob/tree_trunk/geo_header.h"

#include "levels/bob/tree_root_shadow/geo_header.h"

#endif
