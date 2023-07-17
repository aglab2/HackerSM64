struct Player
{
    char name[32];
};

struct Score
{
    char score[4];
};

struct State
{
    char curRound[4];
    char _reserved[4];
    struct Score scores[2];
};

struct Team
{
    char teamName[16];
    struct Player players[5];
};

struct Answer
{
    char name[28];
    char cost[4];
};

struct Round
{
    struct Answer answers[8];
};

struct FinalRound
{
    struct Answer answersInit[5];
    struct Answer answersAfter[5];
};

__attribute__((aligned(32))) struct FeudConfig
{
    char header[32];
    struct State state;
    struct Team teams[2];
    struct Round rounds[5];
    struct FinalRound final;
} sConfiguration = 
{
    .header = "THE FAMILY FEUD CONTROL START YE",
    .state = { "0", "", { "000", "000" } },
    .teams = { 
        { "TEAM 1", { "T1 PLAYER 1 NAME", "T1 PLAYER 2 NAME", "T1 PLAYER 3 NAME", "T1 PLAYER 4 NAME", "T1 PLAYER 5 NAME", } },
        { "TEAM 2", { "T2 PLAYER 1 NAME", "T2 PLAYER 2 NAME", "T2 PLAYER 3 NAME", "T2 PLAYER 4 NAME", "T2 PLAYER 5 NAME", } },
    },
    .rounds = {
        { { { "ROUND 1 ANSWER 1", "25" }, { "ROUND 1 ANSWER 2", "22" }, { "ROUND 1 ANSWER 3", "16" }, { "ROUND 1 ANSWER 4", "10" }, 
            { "ROUND 1 ANSWER 5", "01" }, { "ROUND 1 ANSWER 6", "05" }, { "ROUND 1 ANSWER 7", "70" }, { "ROUND 1 ANSWER 8", "80" }, } },
        { { { "ROUND 2 ANSWER 1", "10" }, { "ROUND 2 ANSWER 2", "20" }, { "ROUND 2 ANSWER 3", "30" }, { "ROUND 2 ANSWER 4", "40" }, 
            { "ROUND 2 ANSWER 5", "50" }, { "ROUND 2 ANSWER 6", "60" }, { "ROUND 2 ANSWER 7", "70" }, { "ROUND 2 ANSWER 8", "80" }, } },
        { { { "ROUND 3 ANSWER 1", "10" }, { "ROUND 3 ANSWER 2", "20" }, { "ROUND 3 ANSWER 3", "30" }, { "ROUND 3 ANSWER 4", "40" }, 
            { "ROUND 3 ANSWER 5", "50" }, { "ROUND 3 ANSWER 6", "60" }, { "ROUND 3 ANSWER 7", "70" }, { "ROUND 3 ANSWER 8", "80" }, } },
        { { { "ROUND 4 ANSWER 1", "10" }, { "ROUND 4 ANSWER 2", "20" }, { "ROUND 4 ANSWER 3", "30" }, { "ROUND 4 ANSWER 4", "40" }, 
            { "ROUND 4 ANSWER 5", "50" }, { "ROUND 4 ANSWER 6", "60" }, { "ROUND 4 ANSWER 7", "70" }, { "ROUND 4 ANSWER 8", "80" }, } },
        { { { "ROUND 5 ANSWER 1", "10" }, { "ROUND 5 ANSWER 2", "20" }, { "ROUND 5 ANSWER 3", "30" }, { "ROUND 5 ANSWER 4", "40" }, 
            { "ROUND 5 ANSWER 5", "50" }, { "ROUND 5 ANSWER 6", "60" }, { "ROUND 5 ANSWER 7", "70" }, { "ROUND 5 ANSWER 8", "80" }, } },
    },
    .final = {
        { { "FINAL ANSWER 1-1", "10" }, { "FINAL ANSWER 2-1", "20" }, { "FINAL ANSWER 3-1", "30" }, { "FINAL ANSWER 4-1", "40" }, { "FINAL ANSWER 5-1", "50" } },
        { { "FINAL ANSWER 1-2", "10" }, { "FINAL ANSWER 2-2", "20" }, { "FINAL ANSWER 3-2", "30" }, { "FINAL ANSWER 4-2", "40" }, { "FINAL ANSWER 5-2", "50" } },
    },
};

static char sSelectedX = 0;
static char sSelectedY = 0;

static char sCurrentResponder = 0;
static char sPendingScore = 0;
static char sFailCount = 0;

extern s16 s8DirModeYawOffset;

enum Rounds
{
    R_INIT,
    ROUND1, ROUND2, ROUND3, ROUND4, ROUND5,
    FINAL1, FINAL2,
};

static int currentRound()
{
    return sConfiguration.state.curRound[0] - '0';
}

enum InternalState
{
    IS_INIT,
    PRE_REACTION,
    REACTION,
    AFTER_REACTION,
    LEFT,
    RIGHT,
    STEAL,
};

static char sInternalState = IS_INIT;
static char sShowMonitor = 0;
char sBlockCamera = 0;

static f32 sLeftBuzzerPos [3] = { 947, 529, -2788 };
static f32 sRightBuzzerPos[3] = { 947, 529, -3153 };

static char sPlayedBuzzer = 0;

static void obj_unhide(struct Object* obj) {
    obj->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE;
}

static void obj_hide(struct Object* obj) {
    obj->header.gfx.node.flags |= GRAPH_RENDER_INVISIBLE;
}

struct Object *cur_obj_find_with_behavior_with_bparam12(const BehaviorScript *behavior, int bparam1, int bparam2) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct Object *obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr
            && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
            && obj != o
            && GET_BPARAM1(obj->oBehParams) == bparam1
            && GET_BPARAM2(obj->oBehParams) == bparam2
        ) {
            return obj;
        }

        obj = (struct Object *) obj->header.next;
    }

    return NULL;
}

void bhv_player_init()
{
    if (0 == BPARAM1)
    {
        o->oAnimations = bobomb_seg8_anims_0802396C;
    }
    else
    {
        o->oAnimations = goomba_seg8_anims_0801DA4C;
        obj_scale(o, 1.5f);
    }

    cur_obj_init_animation(0);
}

void bhv_player_loop()
{
    if (1 == o->oAction)
    {
        if (o->oPosY > sLeftBuzzerPos[1])
        {
            o->oVelY -= 2.f;
            o->oPosY += o->oVelY;
        }
        else
        {
            o->oVelY = 0;
        }
    }
    if (2 == o->oAction)
    {
        if (o->oPosY < sLeftBuzzerPos[1] + 5.f)
        {
            o->oVelY = 20.f;
        }

        o->oVelY -= 2.f;
        o->oPosY += o->oVelY;
    }
}

#define PANEL_GRAPHICS(i, j, name) extern Gfx name[]; 
#include "aglab_x_panel_graphics.h"
#undef PANEL_GRAPHICS

#define TEAM_GRAPHICS(i, j, name) extern Gfx name[]; 
#include "aglab_x_teams_graphics.h"
#undef TEAM_GRAPHICS

#define SCORE_GRAPHICS(name) extern Gfx name[]; 
#include "aglab_x_score_graphics.h"
#undef SCORE_GRAPHICS

#define TEXT_GRAPHICS(i,j, name) extern Gfx name[];
#include "aglab_x_text_graphics.h"
#undef TEXT_GRAPHICS

static Gfx* sPanelVisuals[] =
{
#define PANEL_GRAPHICS(i, j, name) [i*32 + j] = name, 
#include "aglab_x_panel_graphics.h"
#undef PANEL_GRAPHICS
};

static Gfx* sTeamsVisuals[] = 
{
#define TEAM_GRAPHICS(i, j, name) [i*16 + j] = name, 
#include "aglab_x_teams_graphics.h"
#undef TEAM_GRAPHICS 
};

static Gfx* sPendingScoreVisuals[] = 
{
#define SCORE_GRAPHICS(name) name, 
#include "aglab_x_score_graphics.h"
#undef SCORE_GRAPHICS 
};

static Gfx* sPlayerTextVisuals[] = 
{
#define TEXT_GRAPHICS(i,j, name) [i*32 + j] = name,
#include "aglab_x_text_graphics.h"
#undef TEXT_GRAPHICS 
};

extern const Texture *const sLUT[128];

static void set_panel_score(int panelNumber, char* txt)
{
    void** luts = segmented_to_virtual(sLUT);
    for (int i = 0; i < 2; i++)
    {
        void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + i]);
        gfx[13] = luts[(int) txt[i]];
    }
}

static void set_total_score(int score)
{
    void** luts = segmented_to_virtual(sLUT);

    char nums[] = { (score / 10) % 10, score % 10 };
    for (int i = 0; i < 2; i++)
    {
        void** gfx = segmented_to_virtual(sPendingScoreVisuals[i]);
        gfx[13] = luts[(int) ('0' + nums[i])];
    }
}

#define MAX_PANEL_TEXT_LEN 24

static void set_panel_text(int panelNumber, char* txt)
{
    void** luts = segmented_to_virtual(sLUT);
    int len = strlen(txt);
    if (len > MAX_PANEL_TEXT_LEN)
    {
        len = MAX_PANEL_TEXT_LEN;
    }

    txt[len] = '\0';
    for (int i = 0; i < MAX_PANEL_TEXT_LEN; i++)
    {
        void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + 2 + i]);
        gfx[13] = luts[' '];
    }

    int off = MAX_PANEL_TEXT_LEN - len - (MAX_PANEL_TEXT_LEN - len) / 2;
    for (int i = 0; i < len; i++)
    {
        void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + 2 + off + i]);
        gfx[13] = luts[(int) txt[i]];
    }
}

#define MAX_PLAYER_TEXT_LEN 24
static void set_player_text(int side, char* txt)
{
    void** luts = segmented_to_virtual(sLUT);
    int len = strlen(txt);
    if (len > MAX_PLAYER_TEXT_LEN)
    {
        len = MAX_PLAYER_TEXT_LEN;
    }

    txt[len] = '\0';
    for (int i = 0; i < MAX_PLAYER_TEXT_LEN; i++)
    {
        void** gfx = segmented_to_virtual(sPlayerTextVisuals[32 * side + i]);
        gfx[13] = luts[' '];
    }

    int off = (MAX_PLAYER_TEXT_LEN - len) / 2;
    for (int i = 0; i < len; i++)
    {
        void** gfx = segmented_to_virtual(sPlayerTextVisuals[32 * side + off + i]);
        gfx[13] = luts[(int) txt[i]];
    }
}

extern const BehaviorScript bhvStaticBillboard[];

#define MAX_TEAM_TEXT_LEN 11
void bhv_ctl_init()
{
    // play_sound(SOUND_PEACH_FOR_MARIO, gGlobalSoundSource); // success finale
    // play_sound(SOUND_PEACH_BAKE_A_CAKE, gGlobalSoundSource); // success round

    void** luts = segmented_to_virtual(sLUT);
    for (int k = 0; k < 2; k++)
    {
        char* txt = sConfiguration.teams[k].teamName;
        int len = strlen(txt);
        if (len > MAX_TEAM_TEXT_LEN)
        {
            len = MAX_TEAM_TEXT_LEN;
        }

        txt[len] = '\0';
        for (int i = 0; i < MAX_TEAM_TEXT_LEN; i++)
        {
            void** gfx = segmented_to_virtual(sTeamsVisuals[16 * k + i]);
            gfx[13] = luts[' '];
        }

        int off = (MAX_TEAM_TEXT_LEN - len) / 2;
        for (int i = 0; i < len; i++)
        {
            void** gfx = segmented_to_virtual(sTeamsVisuals[16 * k + off + i]);
            gfx[13] = luts[(int) txt[i]];
        }
    }

    set_total_score(0);
    
    for (int k = 0; k < 2; k++)
    {
        struct Object* bb = spawn_object(o, 0xfa + k, bhvStaticBillboard);
        SET_BPARAM1(bb->oBehParams, 0);
        SET_BPARAM2(bb->oBehParams, k);
        obj_hide(bb);
        obj_scale(bb, 0.5f);
    }
}

static void spawn_sparkles()
{
    if (0 == (o->oTimer % 4))
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX += random_f32_around_zero(100.f);
        spark->oPosY += random_f32_around_zero(100.f);
        spark->oPosZ += random_f32_around_zero(100.f);
    }
}

extern const BehaviorScript bhvFailCross[];
void handle_monitor()
{
    if (gPlayer1Controller->buttonPressed & R_TRIG)
    {
        sShowMonitor = !sShowMonitor;
    }

    if (!sShowMonitor)
        return;

    if (gPlayer1Controller->buttonPressed & L_JPAD)
    {
        if (sSelectedX == 1)
            sSelectedX = 0;
    }
    if (gPlayer1Controller->buttonPressed & R_JPAD)
    {
        if (sSelectedX == 0)
            sSelectedX = 1;
    }
    
    if (gPlayer1Controller->buttonPressed & U_JPAD)
    {
        if (sSelectedY > 0)
            sSelectedY--;
    }
    if (gPlayer1Controller->buttonPressed & D_JPAD)
    {
        if (sSelectedY < 4)
            sSelectedY++;
    }

    if (gPlayer1Controller->buttonPressed & B_BUTTON)
    {
        if (sInternalState == REACTION)
        {
            struct Object* cross = spawn_object(o, 0xfc, bhvFailCross);
            cross->oPosX = 200.f;
            cross->oPosY = 1183.f;
            cross->oPosZ = -2945.f;
            cross->oFaceAngleYaw = 0;
            cross->oFaceAngleRoll = 0;
            cross->oFaceAnglePitch = 0;
            cross->oBehParams2ndByte = 0;
        }
        else
        {
            sFailCount++;
            sFailCount %= 3;
            f32 off = (sFailCount - 1) * 300.f;
            for (int i = 0; i < sFailCount; i++)
            {
                struct Object* cross = spawn_object(o, 0xfc, bhvFailCross);
                cross->oPosX = 200.f;
                cross->oPosY = 1183.f;
                cross->oPosZ = -2945.f + 600.f * i - off;
                cross->oFaceAngleYaw = 0;
                cross->oFaceAngleRoll = 0;
                cross->oFaceAnglePitch = 0;
                cross->oBehParams2ndByte = 0;
            }
        }
    }

    if (gPlayer1Controller->buttonPressed & L_CBUTTONS)
    {
        play_sound(SOUND_PEACH_BAKE_A_CAKE, gGlobalSoundSource);
    }
}

static f32 lerp(f32 l, f32 r, f32 p)
{
    return l * (1 - p) + r * p;
}

extern BehaviorScript bhvPanel[];
void bhv_ctl_loop()
{
    if (sInternalState == IS_INIT)
    {
        struct Round* round = &sConfiguration.rounds[currentRound()];

        for (int i = 0; i < 4; i++)
        for (int j = 0; j < 2; j++)
        {
            int num = i + 4*j;
            if ('\0' == round->answers[num].name[0])
                break;

            struct Object* th = spawn_object(o, 0xf1 + num, bhvPanel);
            th->oPosX = 107;
            th->oPosY = 1510 - 200 * i;
            th->oPosZ = -2935 + 520 * (j ? -1 : 1);
            th->oFaceAngleYaw = 0x8000;
            th->oFaceAngleRoll = 0;
            th->oFaceAnglePitch = 0x8000;
            SET_BPARAM2(th->oBehParams, i);
            SET_BPARAM1(th->oBehParams, j);
            obj_scale_xyz(th, 1.f, 1.f, 1.03f);
        }
        sInternalState = PRE_REACTION;
    }

    if (sInternalState == PRE_REACTION)
    {
        if (0 == (o->oTimer % 470))    
            play_sound(SOUND_PEACH_THANKS_TO_YOU, gGlobalSoundSource); // intro

        spawn_sparkles();
        if (o->oDistanceToMario < 200.f && (gPlayer1Controller->buttonPressed & START_BUTTON))
        {
            sInternalState = REACTION;
            sBlockCamera = 1;
            o->oTimer = 0;
            play_sound(SOUND_PEACH_POWER_OF_THE_STARS, gGlobalSoundSource); // intro
        }
    }

    if (sInternalState == REACTION)
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
        gMarioStates->faceAngle[1] = 0x4000;
        s8DirModeYawOffset = 0x4000;
        obj_scale_xyz(gMarioObject, 2.0f, 5.5f, 2.f);
        handle_monitor();
        
        struct Object* p1 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 0, currentRound());
        struct Object* p2 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, currentRound());
        struct Object* ps[] = { p1, p2 };

        if (o->oTimer < 50)
        {
            p1->oPosX = lerp(p1->oHomeX, sLeftBuzzerPos[0],  o->oTimer / 50.f);
            p1->oPosY = lerp(p1->oHomeY, sLeftBuzzerPos[1],  o->oTimer / 50.f);
            p1->oPosZ = lerp(p1->oHomeZ, sLeftBuzzerPos[2],  o->oTimer / 50.f);
            p2->oPosX = lerp(p2->oHomeX, sRightBuzzerPos[0], o->oTimer / 50.f);
            p2->oPosY = lerp(p2->oHomeY, sRightBuzzerPos[1], o->oTimer / 50.f);
            p2->oPosZ = lerp(p2->oHomeZ, sRightBuzzerPos[2], o->oTimer / 50.f);
        }
        else if (!sShowMonitor)
        {
            if (gPlayer1Controller->buttonPressed & R_JPAD)
            {
                if (!sPlayedBuzzer)
                {
                    play_sound(SOUND_MENU_THANK_YOU_PLAYING_MY_GAME, gGlobalSoundSource);
                    sPlayedBuzzer = 1;
                }

                p1->oAction = 1;
                p2->oAction = 2;
            }
            if (gPlayer1Controller->buttonPressed & L_JPAD)
            {
                if (!sPlayedBuzzer)
                {
                    play_sound(SOUND_MENU_THANK_YOU_PLAYING_MY_GAME, gGlobalSoundSource);
                    sPlayedBuzzer = 1;
                }

                p1->oAction = 2;
                p2->oAction = 1;
            }

            if (0 != sPendingScore && gPlayer1Controller->buttonPressed & L_TRIG)
            {
                o->oTimer = 0;
                sInternalState = AFTER_REACTION;
                sBlockCamera = 0;
                
                p1->oMoveAngleYaw += 0x8000;
                p2->oMoveAngleYaw += 0x8000;
                p1->oAction = 0;
                p2->oAction = 0;

                sCurrentResponder = (1 + currentRound()) % 5;
            }
        }

        for (int k = 0; k < 2; k++)
        {
            struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, k);
            obj_unhide(bb);
            bb->parentObj = ps[k];
            set_player_text(k, sConfiguration.teams[k].players[currentRound()].name);
        }
    }

    if (sInternalState == AFTER_REACTION)
    {
        if (o->oTimer < 50)
        {
            struct Object* p1 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 0, currentRound());
            p1->oPosX = lerp(sLeftBuzzerPos[0],  p1->oHomeX, o->oTimer / 50.f);
            p1->oPosY = lerp(sLeftBuzzerPos[1],  p1->oHomeY, o->oTimer / 50.f);
            p1->oPosZ = lerp(sLeftBuzzerPos[2],  p1->oHomeZ, o->oTimer / 50.f);
            struct Object* p2 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, currentRound());
            p2->oPosX = lerp(sRightBuzzerPos[0], p2->oHomeX, o->oTimer / 50.f);
            p2->oPosY = lerp(sRightBuzzerPos[1], p2->oHomeY, o->oTimer / 50.f);
            p2->oPosZ = lerp(sRightBuzzerPos[2], p2->oHomeZ, o->oTimer / 50.f);
        }

        if (50 == o->oTimer)
        {
            struct Object* p1 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 0, currentRound());
            p1->oMoveAngleYaw += 0x8000;
            struct Object* p2 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, currentRound());
            p2->oMoveAngleYaw += 0x8000;
        }
    }

    if (sInternalState == LEFT || sInternalState == RIGHT)
    {
        if (gPlayer1Controller->buttonPressed & L_TRIG)
        {
            o->oTimer = 0;
            sInternalState = STEAL;
            sBlockCamera = 0;
            sCurrentResponder = 0;
        }
    }

    if (sShowMonitor)
    {
        gCamera->cutscene = CUTSCENE_MAIN_SCENE;
    }
    else
    {
        gCamera->cutscene = 0;
    }

    print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);
}

void bhv_ctl_choice_init()
{
}

void bhv_ctl_choice_loop()
{
    if (sInternalState == AFTER_REACTION || sInternalState == STEAL)
    {
        spawn_sparkles();
        if (o->oDistanceToMario < 200.f && (gPlayer1Controller->buttonPressed & START_BUTTON))
        {
            sInternalState = RIGHT - BPARAM1;
            sBlockCamera = 1;
            obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1));
            struct Object* p = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, BPARAM1, sCurrentResponder);
            struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0);
            bb->parentObj = p;
            obj_unhide(bb);
            obj_scale(bb, 0.8f);
            set_player_text(0, sConfiguration.teams[BPARAM1].players[sCurrentResponder].name);
        }
    }

    if (0 == BPARAM1 && sInternalState == RIGHT)
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
        gMarioStates->faceAngle[1] = 0;
        s8DirModeYawOffset = 0x4000;
        handle_monitor();
    }
    
    if (1 == BPARAM1 && sInternalState == LEFT)
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
        gMarioStates->faceAngle[1] = 0x8000;
        s8DirModeYawOffset = 0x4000;
        handle_monitor();
    }

    if ((!BPARAM1 && sInternalState == RIGHT) || (BPARAM1 && sInternalState == LEFT))
    {
        int update = 0;
        if (gPlayer1Controller->buttonPressed & L_JPAD)
        {
            if (BPARAM1)
                sCurrentResponder--;
            else
                sCurrentResponder++;

            update = 1;
        }
        if (gPlayer1Controller->buttonPressed & R_JPAD)
        {
            if (BPARAM1)
                sCurrentResponder++;
            else
                sCurrentResponder--;

            update = 1;
        }

        if (update)
        {
            sCurrentResponder += 5;
            sCurrentResponder %= 5;
            struct Object* p = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, BPARAM1, sCurrentResponder);
            struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0);
            bb->parentObj = p;
            set_player_text(0, sConfiguration.teams[BPARAM1].players[sCurrentResponder].name);
        }
    }
}

void bhv_panel_init()
{
    // left  - 947, 529, -2788
    // right - 947, 529, -3153
}

int str_to_int(const char* txt)
{
    int score = 0;
    while ('\0' != *txt)
    {
        score = score * 10 + (*txt - '0');
        txt++;
    }

    return score;
}

void bhv_panel_loop()
{
    if (0 == o->oAction)
    {
        if (sSelectedX == BPARAM1 && (sSelectedY - 1) == BPARAM2)
        {
            o->oFaceAngleRoll = 0x1000 * sins(0x767 * o->oTimer);
            if (gPlayer1Controller->buttonPressed & A_BUTTON)
            {
                play_sound(SOUND_PEACH_DEAR_MARIO, gGlobalSoundSource);
                o->oAction = 1;
                {
                    struct Round* round = &sConfiguration.rounds[currentRound()];
                    int num = BPARAM2 + 4 * BPARAM1;
                    sPendingScore += str_to_int(round->answers[num].cost);

                    set_panel_text (1 + num, round->answers[num].name);
                    set_panel_score(1 + num, round->answers[num].cost);
                }
            }
        }
        else
        {
            o->oFaceAngleRoll = 0;
        }
    }
    else if (1 == o->oAction)
    {
        if (o->oTimer == 25)
        {
            o->oAction = 2;
            set_total_score(sPendingScore);
        }

        o->oFaceAngleRoll = 0x8000 / 25 * o->oTimer;
    }
    else
    {
        // -
    }
}

void bhv_static_billboard_loop()
{
    if (o->parentObj)
    {
        o->oPosX = o->parentObj->oPosX;
        o->oPosY = o->parentObj->oPosY + 100.f + 100.f * (*o->header.gfx.scale);
        o->oPosZ = o->parentObj->oPosZ;
    }
}

void bhv_fail_cross_init()
{
    obj_scale(o, 0.f);
    if (0 == o->oBehParams2ndByte)
        play_sound(SOUND_PEACH_MARIO, gGlobalSoundSource);
}

void bhv_fail_cross_loop()
{
    if (o->oTimer < 10)
    {
        obj_scale(o, o->oTimer / 10.f);
    }

    if (o->oTimer > 30)
    {
        obj_scale(o, (40 - o->oTimer) / 10.f); 
    }

    if (40 == o->oTimer)
    {
        o->activeFlags = 0;
    }
}
