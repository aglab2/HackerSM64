// Star

// 0x0302A6D8
static const Lights1 star_seg3_lights = gdSPDefLights1(
    0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

// 0x0302A6F0
ALIGNED8 static const Texture star_seg3_texture_0302A6F0[] = {
#include "actors/star/star_surface.rgba16.inc.c"
};

// 0x0302AEF0
ALIGNED8 static const Texture star_seg3_texture_0302AEF0[] = {
#include "actors/star/star_eye.rgba16.inc.c"
};

// 0x0302B6F0
static const Vtx star_seg3_vertex_body[] = {
    {{{     0,      8,    -89}, 0, {     0,      0}, {0x00, 0x07, 0x82, 0xff}}},
    {{{   190,   -201,      0}, 0, {     0,      0}, {0x55, 0xa3, 0x00, 0xff}}},
    {{{     0,   -129,      0}, 0, {     0,      0}, {0x00, 0x82, 0x00, 0xff}}},
    {{{   146,    -42,      0}, 0, {     0,      0}, {0x7c, 0xe7, 0x00, 0xff}}},
    {{{     0,      8,     90}, 0, {     0,      0}, {0x00, 0x07, 0x7e, 0xff}}},
    {{{   257,     84,      0}, 0, {     0,      0}, {0x68, 0x47, 0x00, 0xff}}},
    {{{  -145,    -42,      0}, 0, {     0,      0}, {0x84, 0xe7, 0x00, 0xff}}},
    {{{  -189,   -201,      0}, 0, {     0,      0}, {0xaa, 0xa3, 0x00, 0xff}}},
    {{{  -256,     84,      0}, 0, {     0,      0}, {0x97, 0x47, 0x00, 0xff}}},
    {{{     0,    246,      0}, 0, {     0,      0}, {0x00, 0x7e, 0x00, 0xff}}},
    {{{    96,     99,      0}, 0, {     0,      0}, {0x3d, 0x6f, 0x00, 0xff}}},
    {{{   -95,     99,      0}, 0, {     0,      0}, {0xc3, 0x6f, 0x00, 0xff}}},
};

// 0x0302B7B0 - 0x0302B870
const Gfx star_seg3_sub_dl_body[] = {
    gsSPLight(&star_seg3_lights.l, 1),
    gsSPLight(&star_seg3_lights.a, 2),
    gsSPVertex(star_seg3_vertex_body, 12, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 2,  1,  4, 0x0,  1,  3,  4, 0x0),
    gsSP2Triangles( 5,  3,  0, 0x0,  4,  3,  5, 0x0),
    gsSP2Triangles( 6,  7,  4, 0x0,  7,  2,  4, 0x0),
    gsSP2Triangles( 8,  6,  4, 0x0,  9,  4, 10, 0x0),
    gsSP2Triangles( 9, 11,  4, 0x0,  4,  5, 10, 0x0),
    gsSP2Triangles(11,  8,  4, 0x0,  0,  2,  7, 0x0),
    gsSP2Triangles( 0,  7,  6, 0x0,  0,  6,  8, 0x0),
    gsSP2Triangles( 0,  8, 11, 0x0,  0, 11,  9, 0x0),
    gsSP2Triangles(10,  5,  0, 0x0, 10,  0,  9, 0x0),
    gsSPEndDisplayList(),
};

// 0x0302B870 - 0x0302B908
const Gfx star_seg3_dl_body[] = {
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_TEXTURE_GEN),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetCombineMode(G_CC_DECALFADE, G_CC_DECALFADE),
    gsDPLoadTextureBlock(star_seg3_texture_0302A6F0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_WRAP | G_TX_NOMIRROR, 5, 5, G_TX_NOLOD, G_TX_NOLOD),
    gsSPTexture(0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON),
    gsSPDisplayList(star_seg3_sub_dl_body),
    gsDPPipeSync(),
    gsSPTexture(0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPClearGeometryMode(G_TEXTURE_GEN),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

// 0x0302B920
static const Vtx star_seg3_vertex_eyes[] = {
    {{{    67,     86,     63}, 0, {   990,      0}, {0x18, 0x15, 0x7a, 0xff}}},
    {{{     0,    -27,     96}, 0, {     0,    990}, {0x18, 0x15, 0x7a, 0xff}}},
    {{{    67,    -29,     83}, 0, {   990,    990}, {0x18, 0x15, 0x7a, 0xff}}},
    {{{     0,     89,     76}, 0, {     0,      0}, {0x18, 0x15, 0x7a, 0xff}}},
    {{{     0,     89,     76}, 0, {   990,      0}, {0xe8, 0x15, 0x7a, 0xff}}},
    {{{   -66,    -29,     83}, 0, {     0,    990}, {0xe8, 0x15, 0x7a, 0xff}}},
    {{{     0,    -27,     96}, 0, {   990,    990}, {0xe8, 0x15, 0x7a, 0xff}}},
    {{{     0,     89,     76}, 0, {   990,      0}, {0xe7, 0x15, 0x7a, 0xff}}},
    {{{   -66,     86,     63}, 0, {     0,      0}, {0xe7, 0x15, 0x7a, 0xff}}},
    {{{   -66,    -29,     83}, 0, {     0,    990}, {0xe7, 0x15, 0x7a, 0xff}}},
};

// 0x0302B9C0 - 0x0302BA18
const Gfx star_seg3_sub_dl_eyes[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, star_seg3_texture_0302AEF0),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPLight(&star_seg3_lights.l, 1),
    gsSPLight(&star_seg3_lights.a, 2),
    gsSPVertex(star_seg3_vertex_eyes, 10, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  3,  1, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  7,  8,  9, 0x0),
    gsSPEndDisplayList(),
};

// 0x0302BA18 - 0x0302BA88
const Gfx star_seg3_dl_eyes[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGBA, G_CC_MODULATERGBA),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(star_seg3_sub_dl_eyes),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

static const Vtx omm_star_glow_vertices[] = {
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 128.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 118.256577, 48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 85.959549, 94.841743, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 48.983479, 118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 0.000000, 128.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -48.983479, 118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -90.509666, 90.509666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -118.256577, 48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -128.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -118.256577, -48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -90.509666, -90.509666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { -48.983479, -118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 0.000000, -128.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 48.983479, -118.256577, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 90.509666, -90.509666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 118.256577, -48.983479, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xDC } } },
    { { { 512.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 473.026306, 195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 362.038666, 362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 195.933914, 473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 512.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -195.933914, 473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -362.038666, 362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -473.026306, 195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -512.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -473.026306, -195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -362.038666, -362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { -195.933914, -473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, -512.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 195.933914, -473.026306, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 362.038666, -362.038666, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 473.026306, -195.933914, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
};

static const Gfx omm_star_glow_triangles[] = {
    gsSPVertex(omm_star_glow_vertices, 33, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 3, 0),
    gsSP1Triangle(0, 3, 4, 0),
    gsSP1Triangle(0, 4, 5, 0),
    gsSP1Triangle(0, 5, 6, 0),
    gsSP1Triangle(0, 6, 7, 0),
    gsSP1Triangle(0, 7, 8, 0),
    gsSP1Triangle(0, 8, 9, 0),
    gsSP1Triangle(0, 9, 10, 0),
    gsSP1Triangle(0, 10, 11, 0),
    gsSP1Triangle(0, 11, 12, 0),
    gsSP1Triangle(0, 12, 13, 0),
    gsSP1Triangle(0, 13, 14, 0),
    gsSP1Triangle(0, 14, 15, 0),
    gsSP1Triangle(0, 15, 16, 0),
    gsSP1Triangle(0, 16, 1, 0),
    gsSP2Triangles(1, 17, 2, 0, 2, 17, 18, 0),
    gsSP2Triangles(2, 18, 3, 0, 3, 18, 19, 0),
    gsSP2Triangles(3, 19, 4, 0, 4, 19, 20, 0),
    gsSP2Triangles(4, 20, 5, 0, 5, 20, 21, 0),
    gsSP2Triangles(5, 21, 6, 0, 6, 21, 22, 0),
    gsSP2Triangles(6, 22, 7, 0, 7, 22, 23, 0),
    gsSP2Triangles(7, 23, 8, 0, 8, 23, 24, 0),
    gsSP2Triangles(8, 24, 9, 0, 9, 24, 25, 0),
    gsSP2Triangles(9, 25, 10, 0, 10, 25, 26, 0),
    gsSP2Triangles(10, 26, 11, 0, 11, 26, 27, 0),
    gsSP2Triangles(11, 27, 12, 0, 12, 27, 28, 0),
    gsSP2Triangles(12, 28, 13, 0, 13, 28, 29, 0),
    gsSP2Triangles(13, 29, 14, 0, 14, 29, 30, 0),
    gsSP2Triangles(14, 30, 15, 0, 15, 30, 31, 0),
    gsSP2Triangles(15, 31, 16, 0, 16, 31, 32, 0),
    gsSP2Triangles(16, 32, 1, 0, 1, 32, 17, 0),
    gsSPEndDisplayList(),
};

const Gfx omm_star_glow_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xc3, 0x0b, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_glow_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

static const Vtx omm_star_rays_vertices[] = {
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1198.554565, 58.881210, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1198.554565, -58.881210, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1196.748535, 88.277481, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1196.748535, -88.277481, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1194.221680, 117.620567, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1194.221680, -117.620567, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1190.975464, 146.892807, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1190.975464, -146.892807, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1187.011841, 176.076569, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1187.011841, -176.076569, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 0.000000, 0.000000, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0xFF } } },
    { { { 1182.333130, 205.154266, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
    { { { 1182.333130, -205.154266, 0.000000 }, 0, { 0, 0 }, { 0xFF, 0xFF, 0xFF, 0x00 } } },
};

const Gfx omm_star_ray_0_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 0, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_1_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 3, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_2_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 6, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_3_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 9, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_4_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 12, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

static const Gfx omm_star_ray_5_triangles[] = {
    gsSPVertex(omm_star_rays_vertices + 15, 3, 0),
    gsSP1Triangle(0, 1, 2, 0),
    gsSP1Triangle(0, 2, 1, 0),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_0_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_0_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_1_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_1_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_2_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_2_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_3_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_3_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_4_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_4_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};

Gfx omm_star_ray_5_gfx[] = {
    gsDPSetEnvColor(0xFF, 0xba, 0x01, 0xFF),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0, SHADE, 0, ENVIRONMENT, 0),
    gsSPDisplayList(omm_star_ray_5_triangles),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
    gsDPSetEnvColor(0xFF, 0xFF, 0xFF, 0xFF),
    gsSPEndDisplayList(),
};
