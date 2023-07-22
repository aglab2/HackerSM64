#include <string.h>

#include "game/print.h"

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
    int internalState;
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
#if 1
    .state = { "1", 0, { "000", "000" } },
#else
    .state = { "6", 0, { "140", "044" } },
#endif
    .teams = { 
        { "Team 1", { "T1 Player 1 Name", "T1 Player 2 Name", "T1 Player 3 Name", "T1 Player 4 Name", "T1 Player 5 Name", } },
        { "Team 2", { "T2 Player 1 Name", "T2 Player 2 Name", "T2 Player 3 Name", "T2 Player 4 Name", "T2 Player 5 Name", } },
    },
    .rounds = {
        { { { "Round 1 answer 1", "25" }, { "Round 1 answer 2", "22" }, { "Round 1 answer 3", "16" }, { "Round 1 answer 4", "10" }, 
            { "Round 1 answer 5", "01" }, { "Round 1 answer 6", "05" }, { "Round 1 answer 7", "70" }, { "Round 1 answer 8", "80" }, } },
        { { { "Round 2 answer 1", "10" }, { "Round 2 answer 2", "20" }, { "Round 2 answer 3", "30" }, { "Round 2 answer 4", "40" }, 
            { "Round 2 answer 5", "50" }, { "Round 2 answer 6", "60" }, { "Round 2 answer 7", "70" }, { "Round 2 answer 8", "80" }, } },
        { { { "Round 3 answer 1", "10" }, { "Round 3 answer 2", "20" }, { "Round 3 answer 3", "30" }, { "Round 3 answer 4", "40" }, 
            { "Round 3 answer 5", "50" }, { "Round 3 answer 6", "60" }, { "Round 3 answer 7", "70" }, { "Round 3 answer 8", "80" }, } },
        { { { "Round 4 answer 1", "10" }, { "Round 4 answer 2", "20" }, { "Round 4 answer 3", "30" }, { "Round 4 answer 4", "40" }, 
            { "Round 4 answer 5", "50" }, { "Round 4 answer 6", "60" }, { "Round 4 answer 7", "70" }, { "Round 4 answer 8", "80" }, } },
        { { { "Round 5 answer 1", "10" }, { "Round 5 answer 2", "20" }, { "Round 5 answer 3", "30" }, { "Round 5 answer 4", "40" }, 
            { "Round 5 answer 5", "50" }, { "Round 5 answer 6", "60" }, { "Round 5 answer 7", "70" }, { "Round 5 answer 8", "80" }, } },
    },
    .final = {
        { { "Final answer 1-1", "10" }, { "Final answer 2-1", "20" }, { "Final answer 3-1", "30" }, { "Final answer 4-1", "40" }, { "Final answer 5-1", "50" } },
        { { "Final answer 1-2", "10" }, { "Final answer 2-2", "20" }, { "Final answer 3-2", "30" }, { "Final answer 4-2", "40" }, { "Final answer 5-2", "50" } },
    },
};

static char sSelectedX = 0;
static char sSelectedY = 0;

static char sCurrentResponder = 0;
static char sPickedResponder = 0;
static char sFailCount = 0;
static char sAnswerSide = 0;

static int sPendingScore = 0;
static int sCountdown = 0;

enum FinalePositions
{
    FP_LEFT = -1,
    FP_NEUTRAL = 0,
    FP_RIGHT = 1,
};

static char sNormalFinalePosition = FP_NEUTRAL;

static const char sScoreMultipliers[5] = { 1, 1, 2, 2, 3 };

extern s16 s8DirModeYawOffset;

enum Rounds
{
    R_INIT,
    ROUND1, ROUND2, ROUND3, ROUND4, ROUND5,
    FINAL1, FINAL2,
};

static int currentRound()
{
    return sConfiguration.state.curRound[0] - '1';
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
    NORMAL_FINALE,

    PRE_FINAL,
    FINAL_PICK,
    FINAL_ANSWER,
    FINAL_SHOW_ANSWERS,

    CLEAR,
};

#define sInternalState (sConfiguration.state.internalState)

static char sShowMonitor = 0;
char sBlockCamera = 0;

static const f32 sLeftBuzzerPos [3] = { 947, 529, -2788 };
static const f32 sRightBuzzerPos[3] = { 947, 529, -3153 };

static char sPlayedBuzzer = 0;

static void controls_print(int x, int y, const char* name)
{
    print_text_fmt_int(x, y, name, 0);
}

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
        o->oAnimations = (struct Animation**) bobomb_seg8_anims_0802396C;
    }
    else
    {
        o->oAnimations = (struct Animation**) goomba_seg8_anims_0801DA4C;
        obj_scale(o, 1.5f);
    }

    cur_obj_init_animation(0);
}

void bhv_player_loop()
{
    if (1 == o->oAction)
    {
        if (o->oPosY > o->oPlayerYMin)
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
        if (o->oPosY < o->oPlayerYMin + 5.f)
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

#define TEXT_TEAMSCORE_GRAPHICS(i,j, name) extern Gfx name[];
#include "aglab_x_team_score_graphics.h"
#undef TEXT_TEAMSCORE_GRAPHICS

#define PANEL_BG_GRAPHICS(name) extern Gfx name[];
#include "aglab_x_panel_bg.h"
#undef PANEL_BG_GRAPHICS

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

static Gfx* sTeamScoreTextVisuals[] = 
{
#define TEXT_TEAMSCORE_GRAPHICS(i,j, name) [i*4 + j] = name,
#include "aglab_x_team_score_graphics.h"
#undef TEXT_TEAMSCORE_GRAPHICS 
};

static Gfx* sPanelBgVisual[] = 
{
#define PANEL_BG_GRAPHICS(name) name,
#include "aglab_x_panel_bg.h"
#undef PANEL_BG_GRAPHICS 
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
    for (int i = 0; i < 5; i++)
    {
        void** gfx = segmented_to_virtual(sPendingScoreVisuals[i]);
        gfx[13] = luts[(int) (' ')];
    }

    if (score < 10)
    {
        void** gfx = segmented_to_virtual(sPendingScoreVisuals[3]);
        gfx[13] = luts[(int) ('0' + score)];
    }
    else if (score < 100)
    {
        char nums[] = { (score / 10) % 10, score % 10 };
        for (int i = 0; i < 2; i++)
        {
            void** gfx = segmented_to_virtual(sPendingScoreVisuals[i]);
            gfx[13] = luts[(int) ('0' + nums[i])];
        }
    }
    else if (score < 1000)
    {
        char nums[] = { (score / 100) % 10,  (score / 10) % 10, score % 10 };
        for (int i = 2; i < 5; i++)
        {
            void** gfx = segmented_to_virtual(sPendingScoreVisuals[i]);
            gfx[13] = luts[(int) ('0' + nums[i - 2])];
        }
    }
}

static void set_team_score(int team, const char* text)
{
    void** luts = segmented_to_virtual(sLUT);

    for (int i = 0; i < 3; i++)
    {
        void** gfx = segmented_to_virtual(sTeamScoreTextVisuals[4*team + i]);
        gfx[13] = luts[(int) (text[i])];
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

extern u8 panel0__6_rgba16[];
extern u8 castle_grounds_dl__5_rgba16[];

static int set_panel_text_from_start(int panelNumber, char* txt, int limit)
{
    int i;
    void** luts = segmented_to_virtual(sLUT);
    for (i = 0; i < MAX_PANEL_TEXT_LEN; i++)
    {
        void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + 2 + i]);
        gfx[13] = luts[' '];
    }

    for (i = 0; i < limit; i++)
    {
        if (txt[i] == '\0')
            break;

        void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + 2 + i]);
        gfx[13] = luts[(int) txt[i]];
    }

    if (txt[i] != '\0')
    {
        void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + 2 + i]);
        gfx[13] = panel0__6_rgba16;
        return 1;
    }
    else
    {
        return 0;
    }
}

static void set_panel_pending_draw(int panelNumber, int forScore)
{
    void** luts = segmented_to_virtual(sLUT);
    void** gfx = segmented_to_virtual(sPanelVisuals[32 * panelNumber + (forScore ? 0 : 2)]);
    gfx[13] = ((gGlobalTimer / 5) & 1) ? panel0__6_rgba16 : luts[' '];
}

static void change_panel_visuals()
{
    for (int i = 0; i <= 9; i++)
    {
        void** gfx = segmented_to_virtual(sPanelBgVisual[i]);
        gfx[13] = (void*) castle_grounds_dl__5_rgba16;
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
    sInternalState = 0;
    sPendingScore = 0;
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
    controls_print(20, 20, "R CAMERA");
    if (gPlayer1Controller->buttonPressed & R_TRIG)
    {
        sShowMonitor = !sShowMonitor;
    }

    if (!sShowMonitor)
        return;

    controls_print(20, 40, "DPAD MOVE");
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

    controls_print(230, 20, "B FAIL");
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
            if (sFailCount == 4)
                sFailCount = 1;

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

    controls_print(230, 40, "C SFX");
    if (gPlayer1Controller->buttonPressed & L_CBUTTONS)
    {
        play_sound(SOUND_PEACH_BAKE_A_CAKE, gGlobalSoundSource);
    }
    if (gPlayer1Controller->buttonPressed & R_CBUTTONS)
    {
        play_sound(SOUND_PEACH_FOR_MARIO, gGlobalSoundSource);
    }
}

static f32 lerp(f32 l, f32 r, f32 p)
{
    return l * (1 - p) + r * p;
}

static void perform_buzzer_action()
{
    if (!sPlayedBuzzer)
    {
        play_sound(SOUND_MENU_THANK_YOU_PLAYING_MY_GAME, gGlobalSoundSource);
        sPlayedBuzzer = 1;
    }

    o->oSubAction++;
    sCurrentResponder = currentRound() + o->oSubAction / 2;
}

extern void seq_player_play_sequence(u8 player, u8 seqId, u16 arg2);
extern BehaviorScript bhvPanel[];
void bhv_ctl_loop()
{
    {  
        void** luts = segmented_to_virtual(sLUT);
        for (int k = 0; k < 2; k++)
        {
            char* txt = sConfiguration.teams[k].teamName;
            int len = strlen(txt);
            if (len > MAX_TEAM_TEXT_LEN)
            {
                len = MAX_TEAM_TEXT_LEN;
            }

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
    }
    for (int i = 0; i < 2; i++)
        set_team_score(i, sConfiguration.state.scores[i].score);

    if (o->oTimer > 1 && sInternalState == IS_INIT)
    {
        sSelectedX = 0;
        sSelectedY = 0;

        sCurrentResponder = 0;
        sFailCount = 0;
        sAnswerSide = 0;
        sShowMonitor = 0;
        sBlockCamera = 0;
        sPlayedBuzzer = 0;
        sNormalFinalePosition = 0;

        {
            uintptr_t *behaviorAddr = segmented_to_virtual(bhvPanel);
            struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
            struct Object *obj = (struct Object *) listHead->next;

            while (obj != (struct Object *) listHead) {
                if (obj->behavior == behaviorAddr
                    && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
                    && obj != o
                ) {
                    obj->activeFlags = 0;
                }

                obj = (struct Object *) obj->header.next;
            }
        }
        {
            uintptr_t *behaviorAddr = segmented_to_virtual(bhvPlayer);
            struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
            struct Object *obj = (struct Object *) listHead->next;

            while (obj != (struct Object *) listHead) {
                if (obj->behavior == behaviorAddr
                    && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
                    && obj != o
                ) {
                    obj->oPosX = obj->oHomeX;
                    obj->oPosY = obj->oHomeY;
                    obj->oPosZ = obj->oHomeZ;
                }

                obj = (struct Object *) obj->header.next;
            }
        }
        {
            uintptr_t *behaviorAddr = segmented_to_virtual(bhvStaticBillboard);
            struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
            struct Object *obj = (struct Object *) listHead->next;

            while (obj != (struct Object *) listHead) {
                if (obj->behavior == behaviorAddr
                    && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED
                    && obj != o
                ) {
                    obj_hide(obj);
                }

                obj = (struct Object *) obj->header.next;
            }
        }

        if (currentRound() < 5)
        {
            struct Round* round = &sConfiguration.rounds[currentRound()];

            for (int i = 0; i < 4; i++)
            for (int j = 0; j < 2; j++)
            {
                int num = i + 4*j;
                if ('\0' == round->answers[num].name[0])
                    break;

                set_panel_text(num, "");
                set_panel_score(num, "  ");
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
        else
        {
            for (int i = 0; i < 5; i++)
            for (int j = 0; j < 2; j++)
            {
                int num = i + 5*j;
                set_panel_text(num, "");
                set_panel_score(num, "  ");
                struct Object* th = spawn_object(o, 0xf0 + num, bhvPanel);
                th->oPosX = 107;
                th->oPosY = 1510 - 150 * i;
                th->oPosZ = -2935 + 520 * (j ? -1 : 1);
                th->oFaceAngleYaw = 0x8000;
                th->oFaceAngleRoll = 0x8000;
                th->oFaceAnglePitch = 0x8000;
                th->oAction = 3;
                SET_BPARAM2(th->oBehParams, i);
                SET_BPARAM1(th->oBehParams, j);
                obj_scale_xyz(th, 1.f, 1.f, 1.03f);
            }
            change_panel_visuals();
            sInternalState = PRE_FINAL;
        }
    }

    if (sInternalState == PRE_REACTION)
    {
        spawn_sparkles();
        if (o->oDistanceToMario < 200.f)
        {
            controls_print(20, 20, "START");
            if (gPlayer1Controller->buttonPressed & START_BUTTON)
            {
                sInternalState = REACTION;
                sBlockCamera = 1;
                o->oTimer = 0;
                seq_player_play_sequence(0, 0, 0);
                sCurrentResponder = currentRound();
                o->oSubAction = -1; // first responce will add 1 making this zero as intended
                sAnswerSide = -1;
                // play_sound(SOUND_PEACH_POWER_OF_THE_STARS, gGlobalSoundSource); // intro
            }
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
        if (sPlayedBuzzer)
            handle_monitor();

        struct Object* p1 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 0, currentRound());
        struct Object* p2 = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, currentRound());
        struct Object* ps[] = { p1, p2 };
        struct Object* marked = NULL;

        if (o->oTimer <= 50)
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
            controls_print(20, 40, "DPAD BUZZ");
            if ((gPlayer1Controller->buttonPressed & R_JPAD) && (0 != sAnswerSide))
            {
                perform_buzzer_action();
                p1->oAction = 1;
                // enable jumping only if less than 2 responces
                if (o->oSubAction < 2)
                {
                    p2->oAction = 2;
                }
                else
                {
                    p2->oAction = 1;
                    cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 0, (currentRound() + (o->oSubAction - 1) / 2) % 5)->oAction = 1;
                    marked = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, (currentRound() + o->oSubAction / 2) % 5);
                    marked->oAction = 2;
                }
                sAnswerSide = 0;
            }
            if ((gPlayer1Controller->buttonPressed & L_JPAD) && (1 != sAnswerSide))
            {
                perform_buzzer_action();
                p2->oAction = 1;
                if (o->oSubAction < 2)
                {
                    p1->oAction = 2;
                }
                else
                {
                    p1->oAction = 1;
                    cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, (currentRound() + (o->oSubAction - 1) / 2) % 5)->oAction = 1;
                    marked = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 0, (currentRound() + o->oSubAction / 2) % 5);
                    marked->oAction = 2;
                }
                sAnswerSide = 1;
            }

            int stage = o->oSubAction % 10;
            if (o->oSubAction > 0 && stage != 0 && stage != 1)
            {
                sNormalFinalePosition = sAnswerSide ? FP_LEFT : FP_RIGHT;
            }
            else
            {
                sNormalFinalePosition = FP_NEUTRAL;
            }

            if (0 != sPendingScore)
            {
                controls_print(20, 60, "L EXIT");
                if (gPlayer1Controller->buttonPressed & L_TRIG)
                {
                    cur_obj_find_with_behavior_with_bparam12(bhvPlayer, 1, (currentRound() + o->oSubAction / 2) % 5)->oAction = 1;
                    o->oTimer = 0;
                    sInternalState = AFTER_REACTION;
                    sBlockCamera = 0;
                    
                    p1->oMoveAngleYaw += 0x8000;
                    p2->oMoveAngleYaw += 0x8000;
                    p1->oAction = 0;
                    p2->oAction = 0;

                    sCurrentResponder = (1 + currentRound() + o->oSubAction / 2) % 5;
                    sNormalFinalePosition = FP_NEUTRAL;
                }
            }
        }

        if (marked)
            marked->oPlayerYMin = marked->oHomeY;

        p1->oPlayerYMin = sLeftBuzzerPos[1];
        p2->oPlayerYMin = sLeftBuzzerPos[1];

        if (sNormalFinalePosition == 0)
        {
            for (int k = 0; k < 2; k++)
            {
                struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, k);
                obj_unhide(bb);
                obj_scale(bb, 0.5f);
                bb->parentObj = ps[k];
                set_player_text(k, sConfiguration.teams[k].players[currentRound()].name);
            }
        }
        else if (marked)
        {
            struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0);
            obj_unhide(bb);
            obj_scale(bb, 1.f);
            bb->parentObj = marked;
            set_player_text(0, sConfiguration.teams[GET_BPARAM1(marked->oBehParams)].players[GET_BPARAM2(marked->oBehParams)].name);
            obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1));
        }
    }

    if (sInternalState == AFTER_REACTION)
    {
        if (o->oTimer <= 50)
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

    if (!sShowMonitor)
    {
        if (sInternalState == LEFT || sInternalState == RIGHT)
        {
            controls_print(20, 40, "L EXIT");
            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                o->oTimer = 0;
                sInternalState = STEAL;
                sBlockCamera = 0;
                sCurrentResponder = 0;
            }
        }
    }

    if (sShowMonitor)
    {
        gCamera->cutscene = CUTSCENE_MAIN_SCENE;
    }
    else
    {
        switch (sNormalFinalePosition)
        {
            case FP_LEFT:
                gCamera->cutscene = CUTSCENE_LEFT;
                break;
            case FP_RIGHT:
                gCamera->cutscene = CUTSCENE_RIGHT;
                break;
            case FP_NEUTRAL:
                gCamera->cutscene = 0;
                break;
        }
    }

    // print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    // print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    // print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);
}

void bhv_ctl_choice_init()
{
}

static void advance_selected_player(int amt, int forbidPicked)
{
    sCurrentResponder += amt;
    sCurrentResponder += 5;
    sCurrentResponder %= 5;

    if (forbidPicked && sCurrentResponder == sPickedResponder)
    {
        sCurrentResponder += amt;
        sCurrentResponder += 5;
        sCurrentResponder %= 5;
    }
}

static void control_selected_player(int forbidPicked)
{
    controls_print(20, 60, "DPAD PLAYER");
    if (gPlayer1Controller->buttonPressed & L_JPAD)
    {
        if (BPARAM1)
        {
            advance_selected_player(-1, forbidPicked);
        }
        else
        {
            advance_selected_player(1, forbidPicked);
        }
    }
    if (gPlayer1Controller->buttonPressed & R_JPAD)
    {
        if (BPARAM1)
        {
            advance_selected_player(1, forbidPicked);
        }
        else
        {
            advance_selected_player(-1, forbidPicked);
        }

        sCurrentResponder += 5;
        sCurrentResponder %= 5;
    }

    struct Object* p = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, BPARAM1, sCurrentResponder);
    struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0);
    bb->parentObj = p;
    set_player_text(0, sConfiguration.teams[BPARAM1].players[(int) sCurrentResponder].name);
}

void bhv_ctl_choice_loop()
{
    if (sInternalState == AFTER_REACTION || sInternalState == STEAL)
    {
        spawn_sparkles();
        if (o->oDistanceToMario < 200.f)
        {
            controls_print(20, 20, "START");
            if (gPlayer1Controller->buttonPressed & START_BUTTON)
            {
                sInternalState = RIGHT - BPARAM1;
                sBlockCamera = 1;
                obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1));
                struct Object* p = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, BPARAM1, sCurrentResponder);
                struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0);
                bb->parentObj = p;
                obj_unhide(bb);
                obj_scale(bb, 0.8f);
                set_player_text(0, sConfiguration.teams[BPARAM1].players[(int) sCurrentResponder].name);
            }
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

    if (!sShowMonitor)
    {
        if ((!BPARAM1 && sInternalState == RIGHT) || (BPARAM1 && sInternalState == LEFT))
        {
            control_selected_player(0);
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
            controls_print(140, 20, "A OPEN");
            if (gPlayer1Controller->buttonPressed & A_BUTTON)
            {
                play_sound(SOUND_PEACH_DEAR_MARIO, gGlobalSoundSource);
                o->oAction = 1;
                {
                    struct Round* round = &sConfiguration.rounds[currentRound()];
                    o->oPanelRound = (struct Object*) round;
                    int num = BPARAM2 + 4 * BPARAM1;
                    if (sInternalState < STEAL)
                        sPendingScore += str_to_int(round->answers[num].cost);

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
        struct Round* round = (struct Round*) o->oPanelRound;
        int num = BPARAM2 + 4 * BPARAM1;
        set_panel_text (1 + num, round->answers[num].name);
        if (o->oTimer == 25)
        {
            o->oAction = 2;
            set_total_score(sPendingScore);
        }

        o->oFaceAngleRoll = 0x8000 / 25 * o->oTimer;
    }
    else if (o->oAction == 2)
    {
        struct Round* round = (struct Round*) o->oPanelRound;
        int num = BPARAM2 + 4 * BPARAM1;
        set_panel_text (1 + num, round->answers[num].name);
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

void bhv_finale_ctl_init()
{
}

void bhv_finale_ctl_loop()
{
    if (sInternalState == STEAL)
    {
        spawn_sparkles();
        if (o->oDistanceToMario < 200.f)
        {
            controls_print(20, 40, "START");
            if (gPlayer1Controller->buttonPressed & START_BUTTON)
            {
                sInternalState = NORMAL_FINALE;
                sBlockCamera = 1;
                obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0));
                obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1));
            }
        }
    }

    if (sInternalState == NORMAL_FINALE)
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
        s8DirModeYawOffset = 0x4000;
        gMarioStates->faceAngle[1] = 0x4000;
        handle_monitor();

        if (!sShowMonitor)
        {
            controls_print(20, 40, "DPAD SELECT TEAM");
            if (gPlayer1Controller->buttonPressed & L_JPAD)
            {
                if (sNormalFinalePosition != FP_LEFT)
                {
                    sNormalFinalePosition--;
                }
            }
            if (gPlayer1Controller->buttonPressed & R_JPAD)
            {
                if (sNormalFinalePosition != FP_RIGHT)
                {
                    sNormalFinalePosition++;
                }
            }
        }
        else
        {
            sNormalFinalePosition = 0;
        }

        if (sPendingScore && sNormalFinalePosition)
        {
            controls_print(20, 60, "A GIVE POINTS");
            if (gPlayer1Controller->buttonPressed & A_BUTTON)
            {
                int team = 1 - (sNormalFinalePosition + 1) / 2;
                char* scoreText = sConfiguration.state.scores[team].score;
                int score = str_to_int(scoreText) + sPendingScore * sScoreMultipliers[currentRound()];
                sprintf(scoreText, "%03d", score);
                sPendingScore = 0;
            }
        }

        if (0 == sPendingScore && 0 == sNormalFinalePosition && !sShowMonitor)
        {
            controls_print(20, 60, "L NEXT ROUND");
            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                sConfiguration.state.curRound[0]++;
                sInternalState = 0;
            }
        }
    }

    if (sInternalState == PRE_FINAL)
    {
        spawn_sparkles();
        if (o->oDistanceToMario < 200.f)
        {
            controls_print(20, 40, "START");
            if (gPlayer1Controller->buttonPressed & START_BUTTON)
            {
                seq_player_play_sequence(0, 0, 0);
                sInternalState = FINAL_PICK;
                sBlockCamera = 1;
                obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0));
                obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1));
                sCurrentResponder = 0;
                struct Object* bb = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0);
                obj_scale(bb, 0.8f);
                obj_unhide(bb);
                struct Object* bb1 = cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1);
                obj_hide(bb1);
                o->oSubAction = 0;
                o->oAction = 0;
                o->oFinaleCountdownLength = 20 * 30;
            }
        }
    }

    if (sInternalState > PRE_FINAL)
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
        s8DirModeYawOffset = 0x4000;
        gMarioStates->faceAngle[1] = 0x4000;
    }

    if (sInternalState == FINAL_PICK)
    {
        if (str_to_int(sConfiguration.state.scores[0].score) > str_to_int(sConfiguration.state.scores[1].score))
        {
            SET_BPARAM1(o->oBehParams, 1);
            sNormalFinalePosition = 1;
        }
        else
        {
            SET_BPARAM1(o->oBehParams, 0);
            sNormalFinalePosition = -1;
        }

        control_selected_player(o->oAction); // greater than 5 also works
        controls_print(20, 40, "A SELECT");
        if (gPlayer1Controller->buttonPressed & A_BUTTON)
        {
            sInternalState = FINAL_ANSWER;
            o->oTimer = 0;
            o->oSubAction = 0;
            sNormalFinalePosition = 0;
            sCountdown = o->oFinaleCountdownLength;
            sPickedResponder = sCurrentResponder;
        }
    }

    if (sInternalState == FINAL_ANSWER)
    {
        struct Object* p = cur_obj_find_with_behavior_with_bparam12(bhvPlayer, BPARAM1, sCurrentResponder);
        if (o->oTimer <= 50)
        {
            p->oPosX = lerp(p->oHomeX, o->oPosX + (o->oAction ? 500.f : 0.f),  o->oTimer / 50.f);
            p->oPosY = lerp(p->oHomeY, o->oPosY,  o->oTimer / 50.f);
            p->oPosZ = lerp(p->oHomeZ, o->oPosZ - 500.f * (BPARAM1 - 0.5f),  o->oTimer / 50.f);
        }
        else
        {
            if (sCountdown > 29)
                print_text_fmt_int(160 - 16, 130, "%d", sCountdown / 30);

            if (0 == o->oSubAction)
            {
                controls_print(20, 20, "A START");
                if (gPlayer1Controller->buttonPressed & A_BUTTON)
                {
                    o->oSubAction = 1;
                }
            }
            else
            {
                if (sCountdown > 28)
                    sCountdown--;
                else
                    sCountdown = 0;
   
                if (0 == sCountdown)
                {
                    if (!sShowMonitor)
                    {
                        controls_print(20, 20, "A SHOW ANSWERS");
                        if (gPlayer1Controller->buttonPressed & A_BUTTON)
                        {
                            sShowMonitor = 1;
                            sInternalState = FINAL_SHOW_ANSWERS;
                            o->oSubAction = 0;
                            return;
                        }
                    }
                }
            }
        }
    }

    if (sInternalState == FINAL_SHOW_ANSWERS)
    {
        if (0 == o->oSubAction)
        {
            set_panel_pending_draw(o->oAction, 0);
            controls_print(20, 20, "A SHOW ANSWER");
            if (gPlayer1Controller->buttonPressed & A_BUTTON)
            {
                o->oSubAction = 1;
                o->oFinaleDrawingProgress = 0;
                play_sound(SOUND_PEACH_POWER_OF_THE_STARS, gGlobalSoundSource); 
            }
        }
        else if (1 == o->oSubAction)
        {
            o->oFinaleDrawingProgress++;
            int keepGoing = set_panel_text_from_start(o->oAction, sConfiguration.final.answersInit[o->oAction].name, o->oFinaleDrawingProgress);
            if (!keepGoing)
            {
                o->oSubAction = 2;
            }
        }
        else
        {
            set_panel_pending_draw(o->oAction, 1);
            controls_print(20, 20, "A SHOW SCORE");
            if (gPlayer1Controller->buttonPressed & A_BUTTON)
            {
                set_panel_score(o->oAction, sConfiguration.final.answersInit[o->oAction].cost);
                int cost = str_to_int(sConfiguration.final.answersInit[o->oAction].cost);
                if (0 == cost)
                {
                    play_sound(SOUND_PEACH_MARIO, gGlobalSoundSource); 
                }
                sPendingScore += cost;
                set_total_score(sPendingScore);

                o->oAction++;
                o->oSubAction = 0;
                if (5 == o->oAction)
                {
                    o->oFinaleCountdownLength = 30 * 25;
                    sInternalState = FINAL_PICK;
                    sShowMonitor = 0;
                    sCurrentResponder++;
                    sCurrentResponder %= 5;
                    return;
                }
                
                if (10 == o->oAction)
                {
                    sInternalState = CLEAR;
                    obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 0));
                    obj_hide(cur_obj_find_with_behavior_with_bparam12(bhvStaticBillboard, 0, 1));
                    seq_player_play_sequence(0, SEQ_FEUD, 0);
                    return;
                }
            }
        }
    }
    
    if (sInternalState == CLEAR)
    {
        sShowMonitor = 0;
        char line[128];
        sprintf(line, "WINNERS: %s", sConfiguration.teams[BPARAM1].teamName);
        print_text_centered(160, 170, line);
        sprintf(line, "TOTAL PRIZE MONEY %d", sPendingScore >= 150 ? 10000 : sPendingScore * 20);
        print_text_centered(160, 130, line);
    }
}
