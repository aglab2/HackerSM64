#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "types.h"

#include "make_const_nonconst.h"

#define HD_INTRO_TEXTURES

// 0x0700B420 - 0x0700B460
static const Vtx intro_seg7_vertex_copyright[] = {
#ifdef HD_INTRO_TEXTURES
    {{{    80,     60,     -1}, 0, {     0,      0}, {0x00, 0xff, 0xf7, 0xff}}}, // 0
    {{{   240,     60,     -1}, 0, {256<<5,      0}, {0x00, 0xff, 0xf7, 0xff}}}, // 1

    {{{    80,     48,     -1}, 0, {     0,  16<<5}, {0x00, 0xff, 0xff, 0xff}}}, // 2
    {{{   240,     48,     -1}, 0, {256<<5,  16<<5}, {0x00, 0xff, 0xff, 0xff}}}, // 3

    {{{    80,     36,     -1}, 0, {     0,  32<<5}, {0x00, 0x7f, 0xff, 0xff}}}, // 4
    {{{   240,     36,     -1}, 0, {256<<5,  32<<5}, {0x00, 0x7f, 0xff, 0xff}}}, // 5
#else
    {{{    96,     58,     -1}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}}, // 0
    {{{   224,     58,     -1}, 0, {128<<5,      0}, {0xff, 0xff, 0xff, 0xff}}}, // 1
    {{{    96,     42,     -1}, 0, {     0,  16<<5}, {0xff, 0xff, 0xff, 0xff}}}, // 2
    {{{   224,     42,     -1}, 0, {128<<5,  16<<5}, {0xff, 0xff, 0xff, 0xff}}}, // 3
#endif
};

// 0x0700B460 - 0x0700B4A0
static const Vtx intro_seg7_vertex_trademark[] = {
#ifdef HD_INTRO_TEXTURES
    {{{   268,    192,     -1}, 0, {     0,      0}, {0x00, 0xff, 0xf7, 0xff}}}, // 0
    {{{   284,    192,     -1}, 0, { 64<<5,      0}, {0x00, 0xff, 0xf7, 0xff}}}, // 1

    {{{   268,    184,     -1}, 0, {     0,  32<<5}, {0x00, 0xff, 0xff, 0xff}}}, // 2
    {{{   284,    184,     -1}, 0, { 64<<5,  32<<5}, {0x00, 0xff, 0xff, 0xff}}}, // 3

    {{{   268,    176,     -1}, 0, {     0,  64<<5}, {0x00, 0x7f, 0xff, 0xff}}}, // 4
    {{{   284,    176,     -1}, 0, { 64<<5,  64<<5}, {0x00, 0x7f, 0xff, 0xff}}}, // 5
#else
    {{{   268,    196,     -1}, 0, {     0,      0}, {0xff, 0xff, 0xff, 0xff}}}, // 0
    {{{   284,    196,     -1}, 0, {   544,      0}, {0xff, 0xff, 0xff, 0xff}}}, // 1
    {{{   268,    180,     -1}, 0, {     0,    512}, {0xff, 0xff, 0xff, 0xff}}}, // 2
    {{{   284,    180,     -1}, 0, {   544,    512}, {0xff, 0xff, 0xff, 0xff}}}, // 3
#endif
};

#ifdef HD_INTRO_TEXTURES
// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const Texture intro_seg7_texture_copyright[] = {
#include "levels/intro/made_with_hackersm64.custom.i4.inc.c"
};
// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const Texture intro_seg7_texture_trademark[] = {
#include "levels/intro/tm.custom.i4.inc.c"
};
#else

#if defined(VERSION_EU) || defined(VERSION_SH)
// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const Texture intro_seg7_texture_copyright[] = {
#include "levels/intro/2_eu_copyright.rgba16.inc.c"
};
#else
// 0x0700B4A0 - 0x0700B4A2
ALIGNED8 static const Texture intro_seg7_texture_copyright[] = {
#include "levels/intro/2_copyright.rgba16.inc.c"
};
#endif

#if defined(VERSION_EU)
// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const Texture intro_seg7_texture_trademark[] = {
#include "levels/intro/3_eu_tm.rgba16.inc.c"
};
#elif defined(VERSION_SH)
ALIGNED8 static const Texture intro_seg7_texture_trademark[] = {
#include "levels/intro/3_sh_tm.rgba16.inc.c"
};
#else
// 0x0700C4A0 - 0x0700D4A0
ALIGNED8 static const Texture intro_seg7_texture_trademark[] = {
#include "levels/intro/3_tm.rgba16.inc.c"
};
#endif

#endif

// 0x0700C6A0 - 0x0700C790
const Gfx intro_seg7_dl_copyright_trademark[] = {
    gsDPPipeSync(),
#ifdef HD_INTRO_TEXTURES
    gsDPSetCombineMode(G_CC_MODULATEFADE, G_CC_MODULATEFADE),
#else
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
#endif
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),

#ifdef HD_INTRO_TEXTURES
    gsDPLoadTextureBlock_4b(intro_seg7_texture_copyright, G_IM_FMT_I, 256, 32, (G_TX_NOMIRROR | G_TX_CLAMP), (G_TX_NOMIRROR | G_TX_CLAMP), 0, 8, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(intro_seg7_vertex_copyright, 6, 0),
    gsSP2Triangles( 0,  3,  1, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 2,  5,  3, 0x0,  2,  4,  5, 0x0),

    //gsDPLoadTextureBlock_4b(intro_seg7_texture_trademark, G_IM_FMT_I, 64, 64, (G_TX_NOMIRROR | G_TX_CLAMP), (G_TX_NOMIRROR | G_TX_CLAMP), 0, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    //gsSPVertex(intro_seg7_vertex_trademark, 6, 0),
    //gsSP2Triangles( 0,  3,  1, 0x0,  0,  2,  3, 0x0),
    //gsSP2Triangles( 2,  5,  3, 0x0,  2,  4,  5, 0x0),
#else
    gsDPLoadTextureBlock(intro_seg7_texture_copyright, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 7, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(intro_seg7_vertex_copyright, 4, 0),
    gsSP2Triangles( 0,  3,  1, 0x0,  0,  2,  3, 0x0),

    gsDPLoadTextureBlock(intro_seg7_texture_trademark, G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP, 4, 4, G_TX_NOLOD, G_TX_NOLOD),
    gsSPVertex(intro_seg7_vertex_trademark, 4, 0),
    gsSP2Triangles( 0,  3,  1, 0x0,  0,  2,  3, 0x0),
#endif

    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

// 0x0700C790
const f32 intro_seg7_table_scale_1[] = {
    0.016000f, 0.052000f, 0.002500f, 0.148300f,
    0.189200f, 0.035200f, 0.471600f, 0.525300f,
    0.116600f, 0.875800f, 0.947000f, 0.222100f,
    1.250500f, 1.341300f, 0.327000f, 1.485400f,
    1.594900f, 0.406500f, 1.230500f, 1.563700f,
    0.464300f, 0.913900f, 1.351300f, 0.520200f,
    1.022900f, 1.216100f, 0.574400f, 1.122300f,
    1.097200f, 0.627000f, 1.028300f, 0.955600f,
    0.678100f, 0.934800f, 1.049400f, 0.727700f,
    0.994200f, 1.005200f, 0.775900f, 1.070200f,
    0.961500f, 0.822900f, 0.995600f, 0.995000f,
    0.868700f, 0.991600f, 1.005700f, 0.913500f,
    1.016500f, 0.985200f, 0.957200f, 0.985200f,
    1.007100f, 1.000000f, 0.999900f, 0.999800f,
    1.010600f, 1.000000f, 1.000000f, 1.000000f,
};

// 0x0700C880
const f32 intro_seg7_table_scale_2[] = {
    1.000000f, 1.000000f, 1.000000f, 0.987300f,
    0.987300f, 0.987300f, 0.951400f, 0.951400f,
    0.951400f, 0.896000f, 0.896000f, 0.896000f,
    0.824600f, 0.824600f, 0.824600f, 0.740700f,
    0.740700f, 0.740700f, 0.648000f, 0.648000f,
    0.648000f, 0.549900f, 0.549900f, 0.549900f,
    0.450100f, 0.450100f, 0.450100f, 0.352000f,
    0.352000f, 0.352000f, 0.259300f, 0.259300f,
    0.259300f, 0.175400f, 0.175400f, 0.175400f,
    0.104000f, 0.104000f, 0.104000f, 0.048600f,
    0.048600f, 0.048600f, 0.012800f, 0.012800f,
    0.012800f, 0.000000f, 0.000000f, 0.000000f,
};

#include "levels/intro/intro_logo/model.inc.c"
#include "levels/intro/intro_cherry/model.inc.c"