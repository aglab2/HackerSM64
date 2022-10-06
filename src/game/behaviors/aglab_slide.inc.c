/*
extern u8 pss_scratch[0x1000];

extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_0[36];
extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_1[26];
extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_2[10];
extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_3[4];
extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_4[4];
extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_5[40];
extern Vtx pss_dl_apiece1_mesh_layer_1_vtx_6[8];

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

struct VertexElement
{
    Vtx* vtx;
    int sz;
    int scratchPos;
};

#define ELEMENT(d) { d, ARRAY_SIZE(d), 0 }

static struct VertexElement sSlideElements[][7] = 
{
    { 
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_0),
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_1),
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_2),
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_3),
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_4),
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_5),
        ELEMENT(pss_dl_apiece1_mesh_layer_1_vtx_6),
    },
};
*/

void slide_checkpoint_init()
{
/*
    u8* scratch = (u8*) segmented_to_virtual(pss_scratch);
    int scratchPos = 0;
*/
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvSlideCheckpointCtl, &d);
    struct Object** fires = &o->oSlideCheckpointFire0;
    for (int i = 0; i < 5; i++)
    {
        fires[i] = spawn_object(o, MODEL_RED_FLAME, bhvFlame);
    }

/*
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j <= 6; j++)
        {
            struct VertexElement* element = &sSlideElements[i][j];
            element->scratchPos = scratchPos;
            Vtx* vtx = segmented_to_virtual(element->vtx);
            for (int k = 0; k < element->sz; k++)
            {
                scratch[scratchPos + 0] = vtx[k].v.cn[0];
                scratch[scratchPos + 1] = vtx[k].v.cn[1];
                scratch[scratchPos + 2] = vtx[k].v.cn[2];
                scratchPos += 3;
            }
        }
    }

    o->oSlideCheckpointCount = pss_scratch;
*/
}

void slide_checkpoint_loop()
{
    gMarioStates->health = 0x880;
/*
    int pieceNum = o->oBehParams2ndByte - 1;
    u8* scratch = segmented_to_virtual(pss_scratch);

    // restore the colors
    for (int j = 0; j <= 6; j++)
    {
        struct VertexElement* element = &sSlideElements[pieceNum][j];
        int scratchPos = element->scratchPos;
        Vtx* vtx = segmented_to_virtual(element->vtx);
        for (int k = 0; k < element->sz; k++)
        {
            vtx[k].v.cn[0] = scratch[scratchPos + 0];
            vtx[k].v.cn[1] = scratch[scratchPos + 1];
            vtx[k].v.cn[2] = scratch[scratchPos + 2];
            scratchPos += 3;
        }
    }

*/
    struct Object** fires = &o->oSlideCheckpointFire0;
    for (int i = 0; i < 5; i++)
    {
        fires[i]->oPosX = o->oPosX + 500.f * sins(o->oTimer * 0x135 + i * 0x10000 / 5);
        fires[i]->oPosY = o->oPosY + 500.f * coss(o->oTimer * 0x135 + i * 0x10000 / 5);
        
/*
        // add some colors to the thing
        for (int j = 0; j <= 6; j++)
        {
            struct VertexElement* element = &sSlideElements[pieceNum][j];
                        
            if (i != 0)
                continue;

            Vtx* vtx = segmented_to_virtual(element->vtx);
            for (int k = 0; k < element->sz; k++)
            {
                f32 dx = vtx[k].v.ob[0] - fires[i]->oPosX;
                f32 dy = vtx[k].v.ob[1] - fires[i]->oPosY;
                f32 dz = vtx[k].v.ob[2] - fires[i]->oPosZ;
                int d = sqrtf(sqrtf(dx*dx + dy*dy + dz*dz)) / 5.f;
                int val = 30 - CLAMP(d, 0, 30);
                vtx[k].v.cn[0] += 0;
                vtx[k].v.cn[1] += 0;
                vtx[k].v.cn[2] += 0;
            }
        }
*/
    }

    if (0 == o->oSubAction)
    {
        if (o->oPosX - 500.f < gMarioStates->pos[0] && gMarioStates->pos[0] < o->oPosX + 500.f
         && o->oPosY - 500.f < gMarioStates->pos[1] && gMarioStates->pos[1] < o->oPosY + 500.f
         && o->oPosZ - 500.f < gMarioStates->pos[2] && gMarioStates->pos[2] < o->oPosZ)
        {
            o->oSubAction = 1;
            for (int i = 0; i < 5; i++)
            {
                obj_set_model(fires[i], MODEL_BLUE_FLAME);
                cur_obj_play_sound_2(SOUND_GENERAL2_RIGHT_ANSWER);
                o->parentObj->oPosX = o->oPosX;
                o->parentObj->oPosY = o->oPosY + 100.f;
                o->parentObj->oPosZ = o->oPosZ;
                o->parentObj->oFaceAngleYaw = 0x8000;
            }
        }
    }
}

extern void slide_checkpoint_ctl_init()
{
    o->oFaceAngleYaw = 0x4000;
    // -
}

extern void slide_checkpoint_ctl_loop()
{
    if (0 == o->oAction)
    {
        struct Surface* floor = gMarioStates->floor;
        int type = floor ? floor->type : 0;
        if (gMarioStates->floorHeight == gMarioStates->pos[1] && type == SURFACE_DEEP_QUICKSAND && gMarioStates->action != ACT_LEDGE_GRAB)
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0, 0, 0);
            o->oAction = 1;
        }
    }
    else 
    {
        if (o->oTimer == 12)
        {
            set_gravity(0);
            gMarioStates->pos[0] = o->oPosX;
            gMarioStates->pos[1] = o->oPosY;
            gMarioStates->pos[2] = o->oPosZ;
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
            gMarioStates->faceAngle[1] = o->oFaceAngleYaw;
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
            reset_camera(gCamera);
        }
        if (o->oTimer == 13)
        {
            reset_camera(gCamera);
        }
        if (o->oTimer == 14)
        {
            reset_camera(gCamera);
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0,0,0);
            o->oAction = 0;
        }
    }
}
