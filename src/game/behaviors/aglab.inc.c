#include "config/config_debug.h"

// #define DEBUG_TRIGGER_IMMEDIATELY

void bhv_aglab_lakitu_init()
{
    // spawn_object(o, MODEL_CASTLE_GROUNDS_VCUTM_GRILL, bhvStaticObject);

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
    LA_SWITCH_BRIDGE,
    LA_SWITCH_WINDOWS,
    LA_SWITCH_FRAME,
    LA_SWITCH_ROOF,
    LA_SWITCH_TOWERS,
    LA_SWITCH_MAIN,
};

static void show_cs_time_advance(int cs, int deadline, int dialog)
{
    if (o->oTimer > deadline)
    {
        gCamera->cutscene = cs;
    }

    if (gDialogID == DIALOG_NONE)
    {
        gCamera->cutscene = cs;
        o->oAglabLakituDialog = dialog;
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
    u8 bridge;
    u8 towers;
    u8 window;
    u8 frame;
    u8 roof;
    u8 main;
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

extern const Texture aglab_betawwall2[];
extern const Texture aglab_hdwall[];
extern Gfx castle_grounds_dl_briodge_mesh_layer_4[];

extern u8 castle_grounds_dl_Shape_133_rgba16[];
extern u8 castle_grounds_dl_Shape_135_rgba16[];

extern Gfx mat_castle_grounds_dl_Shape_133_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_135_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_137_f3d[];

static const void* sBridgeTextures[][2] = {
    { aglab_jamground2, aglab_hdwall },
    { castle_grounds_dl_Shape_133_rgba16, castle_grounds_dl_Shape_135_rgba16 },
    { aglab_zarrock, aglab_zarwall },
    { aglab_betaground1, aglab_betawwall2 },
};

static void switch_bridge()
{
    const void** text;
    u8* env;
    env = (u8*) segmented_to_virtual(castle_grounds_dl_briodge_mesh_layer_4) + 15;
    *env = 0xff;
    
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_133_f3d) + 2*7 + 1;
    *text = sBridgeTextures[gStates.bridge][0];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_135_f3d) + 2*6 + 1;
    *text = sBridgeTextures[gStates.bridge][1];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_137_f3d) + 2*7 + 1;
    *text = sBridgeTextures[gStates.bridge][1];
}

extern Gfx castle_grounds_dl_windows_mesh_layer_4[];
extern u8 castle_grounds_dl_Shape_231_rgba16[];
extern Gfx mat_castle_grounds_dl_Shape_231_f3d[];
extern Gfx mat_castle_grounds_dl_f3dlite_material_001[];
extern const Texture aglab_luigiwindow[];
extern const Texture aglab_mariowindow[];
extern const Texture aglab_zarwindow[];
extern const Texture aglab_betawindow[];

static const void* sWindowTextures[][2] = {
    { aglab_luigiwindow, aglab_mariowindow },
    { castle_grounds_dl_Shape_231_rgba16, castle_grounds_dl_Shape_231_rgba16 },
    { aglab_zarwindow, aglab_zarwindow },
    { aglab_betawindow, aglab_betawindow },
};

static void switch_window()
{
    const void** text;
    u8* env;

    env = (u8*) segmented_to_virtual(castle_grounds_dl_windows_mesh_layer_4) + 15;
    *env = 0xff;
    
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_231_f3d) + 2*7 + 1;
    *text = sWindowTextures[gStates.window][0];

    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_f3dlite_material_001) + 2*7 + 1;
    *text = sWindowTextures[gStates.window][1];
}

extern Gfx castle_grounds_dl_frame_mesh_layer_4[];
extern Gfx mat_castle_grounds_dl_Shape_232_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_233_f3d[];
extern const Texture aglab_bowserb[];
extern const Texture aglab_bowsert[];
extern u8 castle_grounds_dl_Shape_233_rgba16[];
extern u8 castle_grounds_dl_Shape_232_rgba16[];
extern const Texture aglab_betat[];
extern const Texture aglab_betab[];
extern const Texture aglab_jamst[];
extern const Texture aglab_jamsb[];
extern Gfx castle_grounds_dl_frame_mesh_layer_4[];

static const void* sFrameTextures[][2] = {
    { aglab_betab, aglab_betat },
    { aglab_jamst, aglab_jamsb },
    { castle_grounds_dl_Shape_233_rgba16, castle_grounds_dl_Shape_232_rgba16 },
    { aglab_bowsert, aglab_bowserb },
};

static void switch_frame()
{
    const void** text;
    u8* env;

    env = (u8*) segmented_to_virtual(castle_grounds_dl_frame_mesh_layer_4) + 15;
    *env = 0xff;
    
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_233_f3d) + 2*6 + 1;
    *text = sFrameTextures[gStates.frame][0];

    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_232_f3d) + 2*6 + 1;
    *text = sFrameTextures[gStates.frame][1];
}

extern Gfx castle_grounds_dl_roof_mesh_layer_4[];
extern Gfx mat_castle_grounds_dl_Shape_134_f3d[];
extern u8 castle_grounds_dl_Shape_134_rgba16[];
extern const Texture aglab_hdroof[];
extern const Texture aglab_zarroof[];
extern const Texture aglab_betaroof[];
static const void* sRoofTextures[] = {
    castle_grounds_dl_Shape_134_rgba16, aglab_hdroof, aglab_zarroof, aglab_betaroof
};

static void switch_roof()
{
    const void** text;
    u8* env;

    env = (u8*) segmented_to_virtual(castle_grounds_dl_roof_mesh_layer_4) + 15;
    *env = 0xff;

    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_134_f3d) + 2*7 + 1;
    *text = sRoofTextures[gStates.roof];
}

static u8 sTowerModels[] = { MODEL_CASTLE_GROUNDS_CANNON_GRILL, MODEL_CASTLE_GROUNDS_VCUTM_GRILL, MODEL_CASTLE_GROUNDS_CANNON_GRILL, MODEL_CASTLE_GROUNDS_FLAG };

extern Gfx mat_vtowers_Shape_135_f3d[];
extern Gfx mat_vtowers_Shape_139_f3d[];
extern Gfx mat_vtowers_Shape_134_f3d[];

static void switch_towers()
{
    static u8 LastSpawnedTower = 0;
    if (LastSpawnedTower != gStates.towers)
    {
        f32 d;
        struct Object* tower = cur_obj_find_nearest_object_with_behavior(bhvStaticObject, &d);
        if (tower)
        {
            tower->activeFlags = 0;
        }
        
        tower = spawn_object(o, sTowerModels[gStates.towers], bhvStaticObject);
        tower->oPosX = 0;
        tower->oPosY = 0;
        tower->oPosZ = 0;
        tower->oFaceAngleYaw = 0;
        tower->oFaceAnglePitch = 0;
        tower->oFaceAngleRoll = 0;
        LastSpawnedTower = gStates.towers;

        void** text;
        text = (const void**) segmented_to_virtual(mat_vtowers_Shape_135_f3d) + 2*6 + 1;
        *text = gStates.towers ? aglab_betawwall2 : castle_grounds_dl_Shape_135_rgba16;
        text = (const void**) segmented_to_virtual(mat_vtowers_Shape_139_f3d) + 2*6 + 1;
        *text = gStates.towers ? aglab_betawall : castle_grounds_dl_Shape_139_rgba16;
        text = (const void**) segmented_to_virtual(mat_vtowers_Shape_134_f3d) + 2*7 + 1;
        *text = gStates.towers ? aglab_betaroof : castle_grounds_dl_Shape_134_rgba16;
    }
}

extern Gfx castle_grounds_dl_tmain_mesh_layer_1[];
extern Gfx castle_grounds_dl_tmain_mesh_layer_4[];
extern Gfx mat_castle_grounds_dl_Shape_192_f3d[];
extern Gfx mat_castle_grounds_dl_Shape_193_f3d[];
extern u8 castle_grounds_dl_Shape_192_rgba16[];
extern u8 castle_grounds_dl_Shape_193_rgba16[];

static const void* sMainTextures[][2] = 
{ 
    { castle_grounds_dl_Shape_192_rgba16, castle_grounds_dl_Shape_193_rgba16 },
    { aglab_betaroof, aglab_betawall3 },
    { castle_grounds_dl_Shape_192_rgba16, castle_grounds_dl_Shape_193_rgba16 },
    { aglab_zarroof, aglab_zarwall },
};

static void switch_main()
{
    u8 venv = gStates.main == 0 ? 0 : 0xff;
    u8* env;
    env = (u8*) segmented_to_virtual(castle_grounds_dl_tmain_mesh_layer_1) + 15;
    *env = venv;
    env = (u8*) segmented_to_virtual(castle_grounds_dl_tmain_mesh_layer_4) + 15;
    *env = venv;

    const void** text;
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_192_f3d) + 2*7 + 1;
    *text = sMainTextures[gStates.main][0];
    text = (const void**) segmented_to_virtual(mat_castle_grounds_dl_Shape_193_f3d) + 2*6 + 1;
    *text = sMainTextures[gStates.main][1];
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
        show_cs_time_advance(CUTSCENE_AGLAB_CASTLE_VIEW, 30, 31);
    }
    else if (LA_SHOW_SURROUNDINGS == o->oAction)
    {
        show_cs_time_advance(CUTSCENE_AGLAB_OUTSIDES, 160, 32);
    }
    else if (LA_SWITCH_SURROUNDINGS == o->oAction)
    {
        advance_state(30, &gStates.surroundings);
        switch_surroundings();
        show_cs_time_advance(CUTSCENE_AGLAB_OUTSIDES, 0, 33);
    }
    else if (LA_SWITCH_CASTLE == o->oAction)
    {
        advance_state(30, &gStates.castle);
        switch_castle();
        show_cs_time_advance(CUTSCENE_AGLAB_CASTLE_WALLS, 0, 34);
    }
    else if (LA_SWITCH_POOL == o->oAction)
    {
        advance_state(30, &gStates.pool);
        switch_water();
        show_cs_time_advance(CUTSCENE_AGLAB_WATER, 0, 35);
    }
    else if (LA_SWITCH_BRIDGE == o->oAction)
    {
        advance_state(30, &gStates.bridge);
        switch_bridge();
        show_cs_time_advance(CUTSCENE_AGLAB_BRIDGE, 0, 36);
    }
    else if (LA_SWITCH_WINDOWS == o->oAction)
    {
        advance_state(30, &gStates.window);
        switch_window();
        show_cs_time_advance(CUTSCENE_AGLAB_WINDOW, 0, 37);
    }
    else if (LA_SWITCH_FRAME == o->oAction)
    {
        advance_state(30, &gStates.frame);
        switch_frame();
        show_cs_time_advance(CUTSCENE_AGLAB_FRAME, 0, 38);
    }
    else if (LA_SWITCH_ROOF == o->oAction)
    {
        advance_state(30, &gStates.roof);
        switch_roof();
        show_cs_time_advance(CUTSCENE_AGLAB_ROOF, 0, 39);
    }
    else if (LA_SWITCH_TOWERS == o->oAction)
    {
        advance_state(30, &gStates.towers);
        switch_towers();
        show_cs_time_advance(CUTSCENE_AGLAB_TOWERS, 0, 40);
    }
    else if (LA_SWITCH_MAIN == o->oAction)
    {
        advance_state(30, &gStates.main);
        switch_main();
        show_cs_time_advance(CUTSCENE_AGLAB_MAIN, 0, 41);
    }

    o->oHomeX = gLakituState.curFocus[0];
    o->oHomeZ = gLakituState.curFocus[2];

    o->oFaceAngleYaw = cur_obj_angle_to_home();
    o->oFaceAnglePitch = atan2s(cur_obj_lateral_dist_to_home(), o->oPosY - gLakituState.curFocus[1]);
}

void bhv_aglab_towers_loop()
{

}
