#include "levels/castle_inside/header.inc.h"

struct VertexGroupDesc
{
    const Vtx* vtx;
    const u32 size;
};

#define ARR_SIZE(x) { x, sizeof(x) / sizeof(*(x)) }

const struct VertexGroupDesc sVertices[] = {
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_5_vtx_0),
  // ARR_SIZE(castle_inside_dl_tower_mesh_layer_5_vtx_1),
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
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_1_vtx_46),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_4_vtx_0),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_4_vtx_1),
  ARR_SIZE(castle_inside_dl_tower_mesh_layer_4_vtx_2),
  ARR_SIZE(castle_inside_dl_water_mesh_layer_5_vtx_0),
  ARR_SIZE(castle_inside_dl_waterbox2_mesh_layer_5_vtx_0),
  ARR_SIZE(castle_inside_dl_tower_002_mesh_layer_4_vtx_0),
};

f32 gFromY = 0;

void set_room_colors()
{
    for (int i = 0; i < sizeof(sVertices) / sizeof(*sVertices); i++)
    {
        const struct VertexGroupDesc* desc = &sVertices[i];
        Vtx* vtx = segmented_to_virtual(desc->vtx);
        for (int j = 0; j < desc->size; j++)
        {
            s16 y = vtx[j].v.ob[1];
            const f32 limit = 1600.f;
            vtx[j].v.cn[3] = 255 - CLAMP(y - gFromY, 0, 1600.f) * 255 / 1600.f;
        }
    }
}

void bhv_books_ctl_init()
{
    gFromY = 5000.f; // -200.f;
    set_room_colors();
}

void bhv_books_ctl_loop()
{
#if 0
    gCamera->cutscene = CUTSCENE_F4;
    if (gFromY < 6400.f)
    {
        gFromY += 20.f;
    }
#endif

    print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);

    if (0 == o->oAction)
    {
        if (15 == o->oF8)
        {
            spawn_default_star(o->oHomeX, o->oHomeY, o->oHomeZ);
            o->activeFlags = 0;
            return;
        }

        f32 d;
        struct Object* of = cur_obj_find_nearest_object_with_behavior(bhvMovingFlame, &d);
        if (of)
        {
            if (!(o->oF8 & 1) && 1882.f < of->oPosX && of->oPosX < 2317.f && of->oPosZ > 850.f)
            {
                o->oPosX = of->oPosX;
                o->oPosY = of->oPosY;
                o->oPosZ = of->oPosZ;
                o->oAction = 1;
                o->oF4 = 1;
                o->oF8 |= 1;
            }
            
            if (!(o->oF8 & 2) && 414.f < of->oPosZ && of->oPosZ < 847.f && 1460.f < of->oPosX && of->oPosX < 1660.f)
            {
                o->oPosX = of->oPosX;
                o->oPosY = of->oPosY;
                o->oPosZ = of->oPosZ;
                o->oAction = 1;
                o->oF4 = 2;
                o->oF8 |= 2;
            }
            
            if (!(o->oF8 & 4) && -847.f < of->oPosZ && of->oPosZ < -414.f && 1460.f < of->oPosX && of->oPosX < 1660.f)
            {
                o->oPosX = of->oPosX;
                o->oPosY = of->oPosY;
                o->oPosZ = of->oPosZ;
                o->oAction = 1;
                o->oF4 = 3;
                o->oF8 |= 4;
            }
            
            if (!(o->oF8 & 8) && 1882.f < of->oPosX && of->oPosX < 2317.f && of->oPosZ < -850.f)
            {
                o->oPosX = of->oPosX;
                o->oPosY = of->oPosY;
                o->oPosZ = of->oPosZ;
                o->oAction = 1;
                o->oF4 = 4;
                o->oF8 |= 8;
            }
        }
    }
    else if (1 == o->oAction)
    {
        Vtx* vtxs = segmented_to_virtual(castle_inside_dl_tower_003_mesh_layer_1_vtx_0);
        f32 burnDist = o->oTimer * 20.f;
        print_text_fmt_int(100, 100, "%d", o->oTimer);
        for (int i = 0; i < sizeof(castle_inside_dl_tower_003_mesh_layer_1_vtx_0) / sizeof(*castle_inside_dl_tower_003_mesh_layer_1_vtx_0); i++)
        {
            Vtx* vtx = &vtxs[i];
            int allowed = 0;
            switch (o->oF4)
            {
                case 1:
                    allowed = 1882.f < vtx->v.ob[0] && vtx->v.ob[0] < 2317.f && vtx->v.ob[2] > 850.f;
                break;
                case 2:
                    allowed = 414.f < vtx->v.ob[2] && vtx->v.ob[2] < 847.f && 1460.f < vtx->v.ob[0] && vtx->v.ob[0] < 1660.f;
                break;
                case 3:
                    allowed = -847.f < vtx->v.ob[2] && vtx->v.ob[2] < -414.f && 1460.f < vtx->v.ob[0] && vtx->v.ob[0] < 1660.f;
                break;
                case 4:
                    allowed = 1882.f < vtx->v.ob[0] && vtx->v.ob[0] < 2317.f && vtx->v.ob[2] < -850.f;
                break;
            }

            if (!allowed)
                continue;
            
            f32 dx = vtx->v.ob[0] - o->oPosX;
            f32 dy = vtx->v.ob[1] - o->oPosY;
            f32 dz = vtx->v.ob[2] - o->oPosZ;

            f32 d = sqrtf(dx*dx + dy*dy + dz*dz);
            if (d < burnDist)
            {
                if (vtx->v.cn[0] > 10)
                {
                    vtx->v.cn[0] -= 10;
                    vtx->v.cn[1] -= 10;
                    vtx->v.cn[2] -= 10;
                    if (0 == (random_u16() % 16))
                    {
                        struct Object* flame = spawn_object(o, MODEL_RED_FLAME, bhvFlameBurningDown);
                        flame->oPosX = vtx->v.ob[0];
                        flame->oPosY = vtx->v.ob[1];
                        flame->oPosZ = vtx->v.ob[2];
                    }
                }
                else
                {
                    vtx->v.cn[0] = vtx->v.cn[1] = vtx->v.cn[2] = 0;
                }
            }
        }

        if (80 == o->oTimer)
        {
            o->oAction = 0;
        }
    }
}

void bhv_flame_burning_down(void)
{
    if (9 == o->oTimer)
    {
        o->activeFlags = 0;
    }
    
    obj_scale(o, 10.f - o->oTimer);
}

void bhv_pokey_ctl_init()
{
    o->oObjF4 = spawn_object(o, MODEL_NONE, bhvPokey);
    o->oObjF4->oPosX -= 500.f;
    o->oObjF4->oHomeX -= 500.f;
    o->oObjF8 = spawn_object(o, MODEL_NONE, bhvPokey);
    o->oObjF8->oPosX += 500.f;
    o->oObjF8->oHomeX += 500.f;
}

void bhv_pokey_ctl_loop()
{
    if (0 == o->oAction)
    {
        if (4 == o->oObjF4->oPokeyNumAliveBodyParts && 2 == o->oObjF8->oPokeyNumAliveBodyParts)
        {
            o->oAction = 1;
            cur_obj_spawn_star_at_y_offset(o->oPosX, o->oPosY, o->oPosZ, 200.0f);
        }
    }

    if (gMarioStates->action == ACT_TWIRLING)
    {
        if (1600.f < gMarioStates->pos[1] && gMarioStates->pos[1] < 3000.f && gMarioStates->pos[2] < -3700.f)
        {
            Vtx* vtxs = segmented_to_virtual(castle_inside_dl_tower_mesh_layer_5_vtx_1);
            f32 minDist = 10000.f;
            Vtx* minVtx = NULL;
            for (int i = 0; i < sizeof(castle_inside_dl_tower_mesh_layer_5_vtx_1) / sizeof(*castle_inside_dl_tower_mesh_layer_5_vtx_1); i++)
            {
                Vtx* vtx = &vtxs[i];
                f32 dx = vtx->v.ob[0] - gMarioStates->pos[0];
                f32 dy = vtx->v.ob[1] - gMarioStates->pos[1];
                f32 d = dx*dx + dy*dy;
                if (d < minDist)
                {
                    minDist = d;
                    minVtx = vtx;
                }
            }

            if (minVtx)
            {
                for (int i = 0; i < sizeof(castle_inside_dl_tower_mesh_layer_5_vtx_1) / sizeof(*castle_inside_dl_tower_mesh_layer_5_vtx_1); i++)
                {
                    Vtx* vtx = &vtxs[i];
                    if (vtx->v.ob[0] == minVtx->v.ob[0] && vtx->v.ob[1] == minVtx->v.ob[1] && vtx->v.ob[2] == minVtx->v.ob[2])
                    {
                        if (vtx->v.cn[3] >= 17)
                            vtx->v.cn[3] -= 17;
                    }
                }
            }
        }
    }
}

void bhv_box_spawner_init()
{
    f32 d;
    o->oObjF4 = cur_obj_find_nearest_object_with_behavior(bhvFloorSwitchAnimatesObject, &d);
}

void bhv_box_spawner_loop()
{
    if (1 == o->oObjF4->oAction)
    {
        if (cur_obj_find_nearby_held_actor(bhvBreakableBoxSmall, 100000.0f) != NULL)
        {
            print_text_fmt_int(20, 20, "%d", __LINE__);
            return;
        }

        f32 d;
        struct Object* otherBox = cur_obj_find_nearest_object_with_behavior(bhvBreakableBoxSmall, &d);
        if (otherBox)
        {
            if (4500.f < otherBox->oPosY && otherBox->oPosY < 7000.f && otherBox->oPosZ > 1300.f)
            {
                print_text_fmt_int(20, 20, "%d", __LINE__);
                return;
            }

            otherBox->activeFlags = 0;
        }
        
        print_text_fmt_int(20, 20, "%d", __LINE__);
        spawn_mist_particles_variable(0, 0, 46.0f);
        spawn_object(o, MODEL_BREAKABLE_BOX, bhvBreakableBoxSmall);
    }
}

// castle_inside_dl_tower_003_mesh_layer_1_vtx_0