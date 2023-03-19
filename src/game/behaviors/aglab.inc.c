#include "config/config_debug.h"

#define DEBUG_TRIGGER_IMMEDIATELY

void bhv_aglab_lakitu_init()
{
    o->oAglabLakituDialog = 30;
    spawn_object_relative_with_scale(CLOUD_BP_LAKITU_CLOUD, 0, 0, 0, 2.0f, o, MODEL_MIST, bhvCloud);
}

extern s16 gDialogID;

enum LakituActions
{
    LA_INIT,
    LA_ADVANCE,
    LA_WELCOME,
    LA_SHOW_SURROUNDINGS,
    LA_SWITCH_SURROUNDINGS,
    LA_SWITCH_CASTLE,
    LA_SWITCH_POOL,
};

static void show_cs_time_advance(int cs, int deadline)
{
    if (o->oTimer > deadline)
    {
        gCamera->cutscene = cs;
    }

    if (gDialogID == DIALOG_NONE)
    {
        gCamera->cutscene = cs;
        o->oAglabLakituDialog++;
        o->oAglabLakituNextAction = o->oAction + 1;
        o->oAction = LA_ADVANCE;
    }
}

extern const Texture aglab_zargrass[];
extern const Texture aglab_zarsand[];
extern const Texture aglab_zarside[];
extern const Texture aglab_betaside[];
extern const Texture aglab_betagrass[];
extern const Texture aglab_betasand2[];
extern const Texture aglab_normalgrass[];
extern const Texture aglab_normalside[];
extern const Texture aglab_normalsand[];
extern u8 castle_grounds_dl_Shape_144_rgba16[];
extern u8 castle_grounds_dl_Shape_145_rgba16[];
extern u8 castle_grounds_dl_Shape_160_rgba16[];

extern Gfx mat_castle_grounds_dl_Shape_144_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_145_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_152_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_160_f3d[];

struct SelectedStates
{
    u8 surroundings;
    u8 castle;
    u8 pool;
};

static struct SelectedStates gStates = { 0 };

static const void* sSurroundingsTextures[][3] = {
    { aglab_zargrass, aglab_zarsand, aglab_zarside },
    { castle_grounds_dl_Shape_144_rgba16, castle_grounds_dl_Shape_145_rgba16, castle_grounds_dl_Shape_160_rgba16 },
    { aglab_betagrass, aglab_betasand2, aglab_betaside },
    { aglab_normalgrass, aglab_normalsand, aglab_normalside },
};

static void switch_surroundings()
{
    const void** text;

    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_144_f3d) + 2*6 + 1;
    *text = sSurroundingsTextures[gStates.surroundings][0];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_152_f3d) + 2*6 + 1;
    *text = sSurroundingsTextures[gStates.surroundings][0];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_145_f3d) + 2*6 + 1;
    *text = sSurroundingsTextures[gStates.surroundings][1];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_160_f3d) + 2*6 + 1;
    *text = sSurroundingsTextures[gStates.surroundings][2];
}

extern Gfx castle_grounds_dl_walls_mesh_layer_6[];
extern Gfx castle_grounds_dl_walls_mesh_layer_4[];
extern Gfx mat_castle_grounds_dl_Shape_139_f3d[];

extern u8 castle_grounds_dl_Shape_139_rgba16[];
extern const Texture aglab_betawall[];
extern const Texture aglab_zarwall[];
extern const Texture aglab_normalwall[];

static const void* sCastleTextures[] = {
    castle_grounds_dl_Shape_139_rgba16, aglab_betawall, aglab_zarwall, aglab_normalwall 
};

static void switch_castle()
{
    u8* env;
    const void** text;
    
    env = (u8*) segmented_to_virtual(castle_grounds_dl_walls_mesh_layer_6) + 15;
    *env = 0xff;
    env = (u8*) segmented_to_virtual(castle_grounds_dl_walls_mesh_layer_4) + 15;
    *env = 0xff;

    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_139_f3d) + 2*6 + 1;
    *text = sCastleTextures[gStates.castle];
}

extern Gfx mat_castle_grounds_dl_Shape_131_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_136_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_259_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_258_f3d[];
extern u8 castle_grounds_dl_Shape_259_rgba16[];
extern u8 castle_grounds_dl_Shape_258_rgba16[];
extern const Texture aglab_zarlava[];
extern const Texture aglab_zarlava2[];
extern const Texture aglab_zarrock[];
extern const Texture aglab_jamwater[];
extern const Texture aglab_jamwater2[];
extern const Texture aglab_jamrock2[];
extern const Texture aglab_zarwalls[];
extern const Texture aglab_zarground2[];
extern const Texture aglab_jamground[];
extern const Texture aglab_jamground2[];

extern Gfx mat_castle_grounds_dl_Shape_131_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_136_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_155_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_156_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_157_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_158_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_159_f3d[];
extern u8 castle_grounds_dl_Shape_155_rgba16[];

extern const Texture aglab_betaground1[];
extern const Texture aglab_betaground2[];
extern const Texture aglab_betawall3[];

static const void* sWaterTextures[][5] = {
    { castle_grounds_dl_Shape_258_rgba16, castle_grounds_dl_Shape_259_rgba16, aglab_betawall3, aglab_betaground1, aglab_betaground2 },
    { aglab_jamwater2, aglab_jamwater, aglab_jamrock2, aglab_jamground, aglab_jamground2 },
    { castle_grounds_dl_Shape_258_rgba16, castle_grounds_dl_Shape_259_rgba16, castle_grounds_dl_Shape_155_rgba16, mat_castle_grounds_dl_Shape_131_f3d, mat_castle_grounds_dl_Shape_136_f3d },
    { aglab_zarlava2, aglab_zarlava, aglab_zarwalls, aglab_zarground2, aglab_zarrock },
};

static void switch_water()
{
    u8 wantEnv = gStates.pool ? 200 : 0;

    u8* env;
    const void** text;
    env = (u8*) segmented_to_virtual(mat_castle_grounds_dl_Shape_259_f3d) + 4*8 + 7;
    *env = wantEnv;
    env = (u8*) segmented_to_virtual(mat_castle_grounds_dl_Shape_258_f3d) + 4*8 + 7;
    *env = wantEnv;
    
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_259_f3d) + 2*8 + 1;
    *text = sWaterTextures[gStates.pool][0];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_258_f3d) + 2*8 + 1;
    *text = sWaterTextures[gStates.pool][1];
    
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_155_f3d) + 2*6 + 1;
    *text = sWaterTextures[gStates.pool][2];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_156_f3d) + 2*6 + 1;
    *text = sWaterTextures[gStates.pool][2];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_157_f3d) + 2*6 + 1;
    *text = sWaterTextures[gStates.pool][2];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_158_f3d) + 2*6 + 1;
    *text = sWaterTextures[gStates.pool][2];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_131_f3d) + 2*6 + 1;
    *text = sWaterTextures[gStates.pool][3];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_136_f3d) + 2*7 + 1;
    *text = sWaterTextures[gStates.pool][4];
}

static void advance_state(int num, u8* val)
{
    if (0 == o->oTimer % num)
    {
        (*val)++;
        (*val) %= 4;
    }
}

void bhv_aglab_lakitu_loop()
{
    print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);

    print_text_fmt_int(20, 200, "A %d", o->oAction);
    print_text_fmt_int(20, 180, "T %d", o->oTimer);

    if (LA_INIT == o->oAction)
    {
#ifndef DEBUG_TRIGGER_IMMEDIATELY
        if (o->oDistanceToMario < 500.f)
#endif
        {
            if (set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_START)
            {
                create_dialog_box(o->oAglabLakituDialog);
                o->oAction = LA_WELCOME;
            }
        }
    }
    else if (LA_ADVANCE == o->oAction)
    {
        set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP);
        create_dialog_box(o->oAglabLakituDialog);
        o->oAction = o->oAglabLakituNextAction;
    }
    else if (LA_WELCOME == o->oAction)
    {
        show_cs_time_advance(CUTSCENE_AGLAB_CASTLE_VIEW, 30);
    }
    else if (LA_SHOW_SURROUNDINGS == o->oAction)
    {
        show_cs_time_advance(CUTSCENE_AGLAB_OUTSIDES, 160);
    }
    else if (LA_SWITCH_SURROUNDINGS == o->oAction)
    {
        advance_state(30, &gStates.surroundings);
        switch_surroundings();
        show_cs_time_advance(CUTSCENE_AGLAB_OUTSIDES, 0);
    }
    else if (LA_SWITCH_CASTLE == o->oAction)
    {
        advance_state(30, &gStates.castle);
        switch_castle();
        show_cs_time_advance(CUTSCENE_AGLAB_CASTLE_WALLS, 0);
    }
    else if (LA_SWITCH_POOL == o->oAction)
    {
        advance_state(30, &gStates.pool);
        switch_water();
        show_cs_time_advance(CUTSCENE_AGLAB_WATER, 0);
    }

    o->oHomeX = gLakituState.curFocus[0];
    o->oHomeZ = gLakituState.curFocus[2];

    o->oFaceAngleYaw = cur_obj_angle_to_home();
    o->oFaceAnglePitch = atan2s(cur_obj_lateral_dist_to_home(), o->oPosY - gLakituState.curFocus[1]);
}
