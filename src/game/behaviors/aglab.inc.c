#include "levels/castle_inside/header.inc.h"

struct VertexGroupDesc
{
    const Vtx* vtx;
    const u32 size;
};

#define ARR_SIZE(x) { x, sizeof(x) / sizeof(*(x)) }

const struct VertexGroupDesc sVertices[] = {
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_5_vtx_0),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_5_vtx_1),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_0),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_1),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_2),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_3),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_4),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_5),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_6),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_7),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_8),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_9),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_10),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_11),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_12),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_13),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_14),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_15),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_16),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_17),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_18),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_19),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_20),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_21),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_22),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_23),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_24),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_25),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_26),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_27),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_28),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_29),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_30),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_31),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_32),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_33),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_34),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_35),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_36),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_37),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_38),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_39),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_40),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_41),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_42),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_43),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_44),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_45),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_4_vtx_0),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_4_vtx_1),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_4_vtx_2),
  ARR_SIZE(castle_inside_dl_tower_001_mesh_layer_5_vtx_0),
  ARR_SIZE(castle_inside_dl_tower_002_mesh_layer_5_vtx_0),
};

void bhv_books_ctl_init()
{
    o->oF4 = 1600;
}

void bhv_books_ctl_loop()
{
    print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);

    for (int i = 0; i < sizeof(sVertices) / sizeof(*sVertices); i++)
    {
        const struct VertexGroupDesc* desc = &sVertices[i];
        Vtx* vtx = segmented_to_virtual(desc->vtx);
        for (int j = 0; j < desc->size; j++)
        {
            s16 y = vtx[j].v.ob[1];
            vtx[j].v.cn[3] = 255 - CLAMP(y, 0, o->oF4) * 255 / o->oF4;
        }
    }
}
