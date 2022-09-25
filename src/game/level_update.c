#include "texscroll.h"
#include <ultra64.h>

#include "sm64.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "audio/external.h"
#include "level_update.h"
#include "game_init.h"
#include "level_update.h"
#include "main.h"
#include "engine/math_util.h"
#include "engine/graph_node.h"
#include "area.h"
#include "save_file.h"
#include "sound_init.h"
#include "mario.h"
#include "camera.h"
#include "object_list_processor.h"
#include "ingame_menu.h"
#include "obj_behaviors.h"
#include "save_file.h"
#if MULTILANG
#include "memory.h"
#include "eu_translation.h"
#include "segment_symbols.h"
#endif
#include "level_table.h"
#include "course_table.h"
#include "rumble_init.h"
#include "puppycam2.h"
#include "puppyprint.h"
#include "puppylights.h"
#include "level_commands.h"
#include "dnvic_print.h" //debug

#include "print.h"

#include "config.h"

#include "color.h"

const char *creditsFM[] = { "1MADE FOR", "FANGAME MARATHON 2022" };
const char *creditsArthur[] = { "2MODELLING", "ARTHURTILLY", "GAEL" };
const char *creditsMushie[] = { "1MODELLING", "MUSHIE" };
const char *creditsBroDute[] = { "1MODELLING", "BRODUTE" };
const char *creditsDesigners[] = { "3DESIGNERS", "LINCRASH", "DNVIC", "ASHLEY" };
const char *creditsCoding[] = { "2GENERAL CODING", "AGLAB", "THECOZIES" };
const char *creditsReonu[] = { "1DEVELOPER", "REONU" };
const char *creditsZenon[] = { "1DEVELOPER", "ZENONX" };
const char *creditsAxo[] = { "1DEVELOPER", "AXOLLYON" };
const char *creditsPie[] = { "1DEVELOPER", "SM64PIE" };
const char *creditsScut[] = { "1DEVELOPER", "SCUTTLEBUG RAISER" };
const char *creditsTesting[] = { "3TESTING", "LINCRASH", "MUSHIE", "GMD" };
const char *creditsOrganizer[] = { "1ORGANIZED BY", "AGLAB" };
const char *creditsPJ74[] = { "2PJ74 TEAM", "ARTHURTILLY", "GALAXTIC" };
const char *creditsMusic[] = { "3MUSIC", "AGLAB", "SCUTTLEBUG RAISER", "GAEL" };

struct CreditsEntry sCreditsSequence[] = {
    { LEVEL_CASTLE_GROUNDS, 1, 1, -128, { 0, 8000, 0 }, NULL },
    { LEVEL_AB,             1, 1, 117,   { -3028, 93, -8781 }  , creditsFM },
    { LEVEL_DF,             1, 18, 22,   { -3268, 2133, -2823 } , creditsOrganizer },
    { LEVEL_MF,             1, -15, 123, { -1115, 0, -1581 }, creditsArthur },
    { LEVEL_MTC,            1, 34, 25,   { 1071, 2046, 223 }, creditsBroDute },
    { LEVEL_SA,             1, 33, 105,  { 13376, 100, 15 }  , creditsReonu },
    { LEVEL_VCUTM,          1, 17, -32,  { 367, 573, 267 }   , creditsPie },
    { LEVEL_BOB,            1, 2, -33,   { 130, -1379, -8261 }   , creditsScut },
    { LEVEL_COTMC,          1, 65, 98,   { 70, 2118, 1109 }, creditsZenon },
    { LEVEL_TOTWC,          1, 17, -34,  { 0, 1000, 0 }   , creditsAxo },
    { LEVEL_VCM,            1, 50, 46,   { -4, 261, 109 }    , creditsMushie },
    { LEVEL_CASTLE_GROUNDS, 1, 51, 54,   { -53, 4536, -109 }   , creditsCoding },
    { LEVEL_HF,             1, 33, 124,  { -3657, 1358, -90 }    , creditsTesting },
    { LEVEL_PSS,            1, 1, 60,    { 11234, 2319, 1765 }   , creditsMusic },
    { LEVEL_CRASH,          1, 50, 47,   { -1433, -2165, -7954 }, creditsDesigners },
    { LEVEL_THI,          1, 50, 47,   { -1433, -2165, -7954 }, creditsDesigners },
    { LEVEL_NONE,  0, 1, 0, { 0, 0, 0 }, NULL },
};

struct MarioState gMarioStates[1];
struct HudDisplay gHudDisplay;
s16 sCurrPlayMode;
s16 sTransitionTimer;
void (*sTransitionUpdate)(s16 *);
struct WarpDest sWarpDest;
s16 sSpecialWarpDest;
s16 sDelayedWarpOp;
s16 sDelayedWarpTimer;
s16 sSourceWarpNodeId;
s32 sDelayedWarpArg;
s8 sTimerRunning;
s8 gNeverEnteredCastle;

struct MarioState *gMarioState = &gMarioStates[0];
s8 sWarpCheckpointActive = FALSE;

u16 level_control_timer(s32 timerOp) {
    switch (timerOp) {
        case TIMER_CONTROL_SHOW:
            gHudDisplay.flags |= HUD_DISPLAY_FLAG_TIMER;
            sTimerRunning = FALSE;
            gHudDisplay.timer = 0;
            break;

        case TIMER_CONTROL_START:
            sTimerRunning = TRUE;
            break;

        case TIMER_CONTROL_STOP:
            sTimerRunning = FALSE;
            break;

        case TIMER_CONTROL_HIDE:
            gHudDisplay.flags &= ~HUD_DISPLAY_FLAG_TIMER;
            sTimerRunning = FALSE;
            gHudDisplay.timer = 0;
            break;
    }

    return gHudDisplay.timer;
}

u32 pressed_pause(void) {
    u32 dialogActive = get_dialog_id() >= 0;
    u32 intangible = (gMarioState->action & ACT_FLAG_INTANGIBLE) != 0;

    if (!intangible && !dialogActive && !gWarpTransition.isActive && sDelayedWarpOp == WARP_OP_NONE
        && (gPlayer1Controller->buttonPressed & START_BUTTON)) {
        return TRUE;
    }

    return FALSE;
}

void set_play_mode(s16 playMode) {
    sCurrPlayMode = playMode;
}

void warp_special(s32 arg) {
    sCurrPlayMode = PLAY_MODE_CHANGE_LEVEL;
    sSpecialWarpDest = arg;
}

void fade_into_special_warp(u32 arg, u32 color) {
    if (color != 0) {
        color = 0xFF;
    }

    fadeout_music(190);
    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 0x10, color, color, color);
    level_set_transition(30, NULL);

    warp_special(arg);
}

void load_level_init_text(u32 arg) {
    s32 gotAchievement;
    u32 dialogID = gCurrentArea->dialog[arg];

    switch (dialogID) {
        case DIALOG_129:
            gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_VANISH_CAP;
            break;

        case DIALOG_130:
            gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_METAL_CAP;
            break;

        case DIALOG_131:
            gotAchievement = save_file_get_flags() & SAVE_FLAG_HAVE_WING_CAP;
            break;

        case (u8)DIALOG_NONE: // 255, cast value to u8 to match (-1)
            gotAchievement = TRUE;
            break;

        default:
            gotAchievement =
                save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
            break;
    }

    if (!gotAchievement) {
        level_set_transition(-1, NULL);
        create_dialog_box(dialogID);
    }
}

void init_door_warp(struct SpawnInfo *spawnInfo, u32 warpDestFlags) {
    if (warpDestFlags & WARP_FLAG_DOOR_FLIP_MARIO) {
        spawnInfo->startAngle[1] += 0x8000;
    }

    spawnInfo->startPos[0] += 300.0f * sins(spawnInfo->startAngle[1]);
    spawnInfo->startPos[2] += 300.0f * coss(spawnInfo->startAngle[1]);
}

void set_mario_initial_cap_powerup(struct MarioState *m) {
    return;
}

void set_mario_initial_action(struct MarioState *m, u32 spawnType, u32 actionArg) {
    switch (spawnType) {
        case MARIO_SPAWN_DOOR_WARP:
            set_mario_action(m, ACT_WARP_DOOR_SPAWN, actionArg);
            break;
        case MARIO_SPAWN_IDLE:
            set_mario_action(m, ACT_IDLE, 0);
            break;
        case MARIO_SPAWN_PIPE:
            set_mario_action(m, ACT_EMERGE_FROM_PIPE, 0);
            break;
        case MARIO_SPAWN_TELEPORT:
            set_mario_action(m, ACT_TELEPORT_FADE_IN, 0);
            break;
        case MARIO_SPAWN_INSTANT_ACTIVE:
            set_mario_action(m, ACT_IDLE, 0);
            break;
        case MARIO_SPAWN_AIRBORNE:
            set_mario_action(m, ACT_SPAWN_NO_SPIN_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_HARD_AIR_KNOCKBACK:
            set_mario_action(m, ACT_HARD_BACKWARD_AIR_KB, 0);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE:
            set_mario_action(m, ACT_SPAWN_SPIN_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_DEATH:
            set_mario_action(m, ACT_FALLING_DEATH_EXIT, 0);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE:
            set_mario_action(m, ACT_SPAWN_SPIN_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_FLYING:
            set_mario_action(m, ACT_FLYING, 2);
            break;
        case MARIO_SPAWN_SWIMMING:
            set_mario_action(m, ACT_WATER_IDLE, 1);
            break;
        case MARIO_SPAWN_PAINTING_STAR_COLLECT:
            set_mario_action(m, ACT_EXIT_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_PAINTING_DEATH:
            set_mario_action(m, ACT_DEATH_EXIT, 0);
            break;
        case MARIO_SPAWN_AIRBORNE_STAR_COLLECT:
            set_mario_action(m, ACT_FALLING_EXIT_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_AIRBORNE_DEATH:
            set_mario_action(m, ACT_UNUSED_DEATH_EXIT, 0);
            break;
        case MARIO_SPAWN_LAUNCH_STAR_COLLECT:
            set_mario_action(m, ACT_SPECIAL_EXIT_AIRBORNE, 0);
            break;
        case MARIO_SPAWN_LAUNCH_DEATH:
            set_mario_action(m, ACT_SPECIAL_DEATH_EXIT, 0);
            break;
    }

#ifdef PREVENT_DEATH_LOOP
    if (m->isDead) {
        m->health = 0x880;
        m->isDead = FALSE;
    }
#endif

    set_mario_initial_cap_powerup(m);
}

void init_mario_after_warp(void) {
    struct ObjectWarpNode *spawnNode = area_get_warp_node(sWarpDest.nodeId);
    u32 marioSpawnType = get_mario_spawn_type(spawnNode->object);

    if (gMarioState->action != ACT_UNINITIALIZED) {
        gPlayerSpawnInfos[0].startPos[0] = (s16) spawnNode->object->oPosX;
        gPlayerSpawnInfos[0].startPos[1] = (s16) spawnNode->object->oPosY;
        gPlayerSpawnInfos[0].startPos[2] = (s16) spawnNode->object->oPosZ;

        gPlayerSpawnInfos[0].startAngle[0] = 0;
        gPlayerSpawnInfos[0].startAngle[1] = spawnNode->object->oMoveAngleYaw;
        gPlayerSpawnInfos[0].startAngle[2] = 0;

        if (gIsGravityFlipped) gPlayerSpawnInfos[0].startPos[1] = 9000.f - gPlayerSpawnInfos[0].startPos[1]; // If gravity is flipped when warping

        if (marioSpawnType == MARIO_SPAWN_DOOR_WARP) {
            init_door_warp(&gPlayerSpawnInfos[0], sWarpDest.arg);
        }

        if (sWarpDest.type == WARP_TYPE_CHANGE_LEVEL || sWarpDest.type == WARP_TYPE_CHANGE_AREA) {
            gPlayerSpawnInfos[0].areaIndex = sWarpDest.areaIdx;
            load_mario_area();
        }

        init_mario();
        set_mario_initial_action(gMarioState, marioSpawnType, sWarpDest.arg);

        gMarioState->interactObj = spawnNode->object;
        gMarioState->usedObj = spawnNode->object;
    }

    reset_camera(gCurrentArea->camera);
    sWarpDest.type = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;

    switch (marioSpawnType) {
        case MARIO_SPAWN_PIPE:
            play_transition(WARP_TRANSITION_FADE_FROM_STAR, 0x10, 0x00, 0x00, 0x00);
            break;
        case MARIO_SPAWN_DOOR_WARP:
            play_transition(WARP_TRANSITION_FADE_FROM_CIRCLE, 0x10, 0x00, 0x00, 0x00);
            break;
        case MARIO_SPAWN_TELEPORT:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x14, 0xFF, 0xFF, 0xFF);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x1A, 0xFF, 0xFF, 0xFF);
            break;
        case MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE:
            play_transition(WARP_TRANSITION_FADE_FROM_CIRCLE, 0x10, 0x00, 0x00, 0x00);
            break;
        case MARIO_SPAWN_FADE_FROM_BLACK:
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x10, 0x00, 0x00, 0x00);
            break;
        default:
            play_transition(WARP_TRANSITION_FADE_FROM_STAR, 0x10, 0x00, 0x00, 0x00);
            break;
    }

    if (gCurrDemoInput == NULL) {
        set_background_music(gCurrentArea->musicParam, gCurrentArea->musicParam2, 0);

        if (gMarioState->flags & MARIO_METAL_CAP) {
            play_cap_music(SEQUENCE_ARGS(4, SEQ_EVENT_METAL_CAP));
        }

        if (gMarioState->flags & (MARIO_VANISH_CAP | MARIO_WING_CAP)) {
            play_cap_music(SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP));
        }

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
        if (gCurrLevelNum == LEVEL_BOB
            && get_current_background_music() != SEQUENCE_ARGS(4, SEQ_LEVEL_SLIDE) && sTimerRunning) {
            play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_LEVEL_SLIDE), 0);
        }

        if (sWarpDest.levelNum == LEVEL_CASTLE && sWarpDest.areaIdx == 1
            && (sWarpDest.nodeId == 31 || sWarpDest.nodeId == 32)
        ) {
            play_sound(SOUND_MENU_MARIO_CASTLE_WARP, gGlobalSoundSource);
        }

        if (sWarpDest.levelNum == LEVEL_CASTLE_GROUNDS && sWarpDest.areaIdx == 1
            && (sWarpDest.nodeId == 7 || sWarpDest.nodeId == 10 || sWarpDest.nodeId == 20
                || sWarpDest.nodeId == 30)) {
            play_sound(SOUND_MENU_MARIO_CASTLE_WARP, gGlobalSoundSource);
        }
#endif
    }
}

// used for warps inside one level
void warp_area(void) {
    if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
        if (sWarpDest.type == WARP_TYPE_CHANGE_AREA) {
            level_control_timer(TIMER_CONTROL_HIDE);
            unload_mario_area();
            load_area(sWarpDest.areaIdx);
        }

        init_mario_after_warp();
    }
}

// used for warps between levels
void warp_level(void) {
    gCurrLevelNum = sWarpDest.levelNum;

    level_control_timer(TIMER_CONTROL_HIDE);

    load_area(sWarpDest.areaIdx);
    init_mario_after_warp();
}

void warp_credits(void) {
    s32 marioAction = ACT_UNINITIALIZED;

    switch (sWarpDest.nodeId) {
        case WARP_NODE_CREDITS_START:
            marioAction = ACT_END_PEACH_CUTSCENE;
            break;

        case WARP_NODE_CREDITS_NEXT:
            sEndCutsceneVp.vp.vscale[0] = 640;
            sEndCutsceneVp.vp.vscale[1] = 360;
            sEndCutsceneVp.vp.vtrans[0] = 640;
            sEndCutsceneVp.vp.vtrans[1] = 480;
            marioAction = ACT_CREDITS_CUTSCENE;
            break;

        case WARP_NODE_CREDITS_END:
            marioAction = ACT_END_WAVING_CUTSCENE;
            break;
    }

    gCurrLevelNum = sWarpDest.levelNum;

    load_area(sWarpDest.areaIdx);

    vec3s_set(gPlayerSpawnInfos[0].startPos, gCurrCreditsEntry->marioPos[0],
              gCurrCreditsEntry->marioPos[1], gCurrCreditsEntry->marioPos[2]);

    vec3s_set(gPlayerSpawnInfos[0].startAngle, 0, 0x100 * gCurrCreditsEntry->marioAngle, 0);

    gPlayerSpawnInfos[0].areaIndex = sWarpDest.areaIdx;

    load_mario_area();
    init_mario();

    set_mario_action(gMarioState, marioAction, 0);

    reset_camera(gCurrentArea->camera);

    sWarpDest.type = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;

    play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x14, 0x00, 0x00, 0x00);

    if (gCurrCreditsEntry == NULL || gCurrCreditsEntry == sCreditsSequence) {
        set_background_music(gCurrentArea->musicParam, gCurrentArea->musicParam2, 0);
    }
}

#include "tile_scroll.h"

u16 gDnvicCounter = 0;
u16 gDnvicChamber = 1;
u8 gDnvicPlayEffect = 0;
extern u8 gDnvicWasMapShown;
hsv gDnvicColor =
{    
    .h = 0.052028f * 0x10000,
    .v = 250,
    .s = 0.826638f,
};

static void stretch_vcols(Vtx* vtx, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        vtx[i].v.tc[1] *= 1.2f;
    }
}

void check_instant_warp(void) {
    s16 cameraAngle;
    struct Surface *floor;

#ifdef ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS
 #ifdef UNLOCK_ALL
    if (gCurrLevelNum == LEVEL_CASTLE) {
 #else // !UNLOCK_ALL
    if (gCurrLevelNum == LEVEL_CASTLE
        && save_file_get_total_star_count(gCurrSaveFileNum - 1, COURSE_MIN - 1, COURSE_MAX - 1) >= 70) {
 #endif // !UNLOCK_ALL
        return;
    }
#endif // ENABLE_VANILLA_LEVEL_SPECIFIC_CHECKS BOOKMARK

    if ((floor = gMarioState->floor) != NULL) {
        if (gCurrLevelNum != LEVEL_SA) {
            s32 index = floor->type - SURFACE_INSTANT_WARP_1B;
            if (index >= INSTANT_WARP_INDEX_START && index < INSTANT_WARP_INDEX_STOP
                && gCurrentArea->instantWarps != NULL) {
                struct InstantWarp *warp = &gCurrentArea->instantWarps[index];

            if (warp->id != 0) {
                if (gCurrCourseNum == COURSE_WMOTR)
                {
                    gDnvicPlayEffect = 1;
                    switch(floor->force) {
                        case 0x69:
                            gDnvicCounter++;
                            break;
                        case 0x420:
                            if (gDnvicCounter)
                                gDnvicCounter--;

                            break;
                        case 0x4:
                            gDnvicCounter = 0;
                            gDnvicChamber = 1;
                            break;
                    }
                    switch(gDnvicChamber) {
                        case 1:
                            if(gDnvicWasMapShown && (floor->force == 0x420) && gDnvicCounter < 2) {
                                gDnvicChamber = 2;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0x3000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            else if (!gDnvicWasMapShown && floor->force == 0x420)
                            {
                                gDnvicPlayEffect = 2;
                            }
                            if(gDnvicCounter == 10) {
                                gDnvicWasMapShown = 1;
                                gDnvicChamber = 10;
                                gDnvicColor.h = 0.052028f * 0x10000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            else if (gDnvicCounter >= 2)
                            {
                                gDnvicColor.h = 0.052028f * 0x10000;
                                gDnvicColor.v = 0.814847f * 255 - 15 * (gDnvicCounter - 2);
                                gDnvicColor.s = 0.826638f;
                            }
                            break;
                        case 2:
                            if(gDnvicCounter == 1) {
                                gDnvicChamber = 3;
                                gDnvicCounter = 0;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0x6000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                            }
                            break;
                        case 3:
                            if(gDnvicCounter == 1) {
                                gDnvicChamber = 4;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0x9000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            else if(gDnvicCounter == 0)
                            {
                                gDnvicChamber = 5;
                                gDnvicCounter = 0;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0xB000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                            }
                            break;
                        case 4:
                            if(gDnvicCounter == 1) {
                                gDnvicChamber = 1;
                                gDnvicColor.h = 0.052028f * 0x10000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            else if(gDnvicCounter == 0)
                            {
                                gDnvicChamber = 2;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0x3000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            break;
                        case 5:
                            if(gDnvicCounter == 5) {
                                gDnvicChamber = 12;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0xB000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                // gDnvicCounter = 0;
                            }
                            if (floor->force == 0x69)
                            {
                                gDnvicColor.h = 0.052028f * 0x10000 + 0xB000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f - 0.15f * gDnvicCounter;
                            }
                            if(gDnvicCounter == 0) {
                                gDnvicChamber = 2;
                                gDnvicColor.h = 0.052028f * 0x10000 + 0x3000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            break;
                        case 10:
                            {
                                // it is only possible to go downwards from here, reset stuff
                                gDnvicChamber = 1;
                                gDnvicColor.h = 0.052028f * 0x10000;
                                gDnvicColor.v = 250;
                                gDnvicColor.s = 0.826638f;
                                gDnvicCounter = 0;
                            }
                            break;
                    }
                    switch(gDnvicChamber) {// don't want to wait until the next instant warp in order to warp
                        case 10:
                            cameraAngle = gMarioState->area->camera->yaw;
                            gDnvicCounter = 0; // fix being stuck forever
                            change_area(3);
                            gMarioState->area = gCurrentArea;
                            warp_camera(0, 0, 0);
                            gMarioState->area->camera->yaw = cameraAngle;
                            return;
                        case 12:
                            cameraAngle = gMarioState->area->camera->yaw;
                            change_area(4);
                            gMarioState->area = gCurrentArea;
                            warp_camera(0, 0, 0);
                            gMarioState->area->camera->yaw = cameraAngle;
                            return;
                    }
                }

                gMarioState->pos[0] += warp->displacement[0];
                gMarioState->pos[1] += warp->displacement[1];
                gMarioState->pos[2] += warp->displacement[2];

                    gMarioState->marioObj->oPosX = gMarioState->pos[0];
                    gMarioState->marioObj->oPosY = gMarioState->pos[1];
                    gMarioState->marioObj->oPosZ = gMarioState->pos[2];

                    // Fix instant warp offset not working when warping across different areas
                    gMarioObject->header.gfx.pos[0] = gMarioState->pos[0];
                    gMarioObject->header.gfx.pos[1] = gMarioState->pos[1];
                    gMarioObject->header.gfx.pos[2] = gMarioState->pos[2];

                    cameraAngle = gMarioState->area->camera->yaw;

                    change_area(warp->area);
                    gMarioState->area = gCurrentArea;

                    warp_camera(warp->displacement[0], warp->displacement[1], warp->displacement[2]);

                    gMarioState->area->camera->yaw = cameraAngle;
                }            
            }
        } else {
            s32 index = floor->type - SURFACE_INSTANT_WARP_1B;
            if (index >= INSTANT_WARP_INDEX_START && index < INSTANT_WARP_INDEX_STOP
                && gCurrentArea->instantWarps != NULL && (floor->type >= SURFACE_INSTANT_WARP_1B) && (floor->type <= SURFACE_INSTANT_WARP_1E)) {
                struct InstantWarp *warp = &gCurrentArea->instantWarps[index];

                if ((((gMarioState->pos[1] - gMarioState->floorHeight < 2500)) || (floor->type != SURFACE_INSTANT_WARP_1C)) && (warp->id != 0) && (gMarioState->action < ACT_LEDGE_GRAB) && (gMarioState->action > ACT_LEDGE_CLIMB_FAST)) {
                    gMarioState->pos[0] += warp->displacement[0];
                    gMarioState->pos[1] += warp->displacement[1];
                    gMarioState->pos[2] += warp->displacement[2];

                    gMarioState->marioObj->oPosX = gMarioState->pos[0];
                    gMarioState->marioObj->oPosY = gMarioState->pos[1];
                    gMarioState->marioObj->oPosZ = gMarioState->pos[2];

                    // Fix instant warp offset not working when warping across different areas
                    gMarioObject->header.gfx.pos[0] = gMarioState->pos[0];
                    gMarioObject->header.gfx.pos[1] = gMarioState->pos[1];
                    gMarioObject->header.gfx.pos[2] = gMarioState->pos[2];

                    cameraAngle = gMarioState->area->camera->yaw;

                    change_area(warp->area);
                    gMarioState->area = gCurrentArea;

                    warp_camera(warp->displacement[0], warp->displacement[1], warp->displacement[2]);

                    gMarioState->area->camera->yaw = cameraAngle;
                }            
            }           
        }
    }
}

s16 music_unchanged_through_warp(s16 arg) {
    struct ObjectWarpNode *warpNode = area_get_warp_node(arg);
    s16 levelNum = warpNode->node.destLevel & 0x7F;

    s16 destArea = warpNode->node.destArea;
    s16 unchanged = TRUE;
    s16 currBgMusic;

#ifndef DISABLE_LEVEL_SPECIFIC_CHECKS
    if (levelNum == LEVEL_BOB && levelNum == gCurrLevelNum && destArea == gCurrAreaIndex) {
        currBgMusic = get_current_background_music();
        if (currBgMusic == SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP | SEQ_VARIATION)
            || currBgMusic == SEQUENCE_ARGS(4, SEQ_EVENT_POWERUP)) {
            unchanged = FALSE;
        }
    } else {
#endif
        u16 destParam1 = gAreas[destArea].musicParam;
        u16 destParam2 = gAreas[destArea].musicParam2;

        unchanged = levelNum == gCurrLevelNum && destParam1 == gCurrentArea->musicParam
               && destParam2 == gCurrentArea->musicParam2;

        if (get_current_background_music() != destParam2) {
            unchanged = FALSE;
        }
#ifndef DISABLE_LEVEL_SPECIFIC_CHECKS
    }
#endif
    return unchanged;
}

/**
 * Set the current warp type and destination level/area/node.
 */
void initiate_warp(s16 destLevel, s16 destArea, s16 destWarpNode, s32 warpFlags) {
    if (destWarpNode >= WARP_NODE_CREDITS_MIN) {
        sWarpDest.type = WARP_TYPE_CHANGE_LEVEL;
    } else if (destLevel != gCurrLevelNum) {
        sWarpDest.type = WARP_TYPE_CHANGE_LEVEL;
    } else if (destArea != gCurrentArea->index) {
        sWarpDest.type = WARP_TYPE_CHANGE_AREA;
    } else {
        sWarpDest.type = WARP_TYPE_SAME_AREA;
    }

    sWarpDest.levelNum = destLevel;
    sWarpDest.areaIdx = destArea;
    sWarpDest.nodeId = destWarpNode;
    sWarpDest.arg = warpFlags;
#if defined(PUPPYCAM) || defined(PUPPYLIGHTS)
    s32 i = 0;
#endif
#ifdef PUPPYCAM
    if (sWarpDest.type == WARP_TYPE_CHANGE_LEVEL)
    {
        for (i = 0; i < gPuppyVolumeCount; i++)
        {
            mem_pool_free(gPuppyMemoryPool, sPuppyVolumeStack[i]);
        }
        gPuppyVolumeCount = 0;
    }
#endif
#ifdef PUPPYLIGHTS
    if (sWarpDest.type == WARP_TYPE_CHANGE_LEVEL)
    {
        for (i = 0; i < gNumLights; i++)
        {
            mem_pool_free(gLightsPool, gPuppyLights[i]);
        }
        gNumLights = 0;
        levelAmbient = FALSE;
    }
#endif
}

// From Surface 0xD3 to 0xFC
#define PAINTING_WARP_INDEX_START 0x00 // Value greater than or equal to Surface 0xD3
#define PAINTING_WARP_INDEX_FA 0x2A    // THI Huge Painting index left
#define PAINTING_WARP_INDEX_END 0x2D   // Value less than Surface 0xFD

/**
 * Check if Mario is above and close to a painting warp floor, and return the
 * corresponding warp node.
 */
struct WarpNode *get_painting_warp_node(void) {
    struct WarpNode *warpNode = NULL;
    s32 paintingIndex = gMarioState->floor->type - SURFACE_PAINTING_WARP_D3;

    if (paintingIndex >= PAINTING_WARP_INDEX_START && paintingIndex < PAINTING_WARP_INDEX_END) {
        if (paintingIndex < PAINTING_WARP_INDEX_FA
            || gMarioState->pos[1] - gMarioState->floorHeight < 80.0f) {
            warpNode = &gCurrentArea->paintingWarpNodes[paintingIndex];
        }
    }

    return warpNode;
}

/**
 * Check is Mario has entered a painting, and if so, initiate a warp.
 */
void initiate_painting_warp(void) {
    if (gCurrentArea->paintingWarpNodes != NULL && gMarioState->floor != NULL) {
        struct WarpNode warpNode;
        struct WarpNode *pWarpNode = get_painting_warp_node();

        if (pWarpNode != NULL) {
            if (gMarioState->action & ACT_FLAG_INTANGIBLE) {
                play_painting_eject_sound();
            } else if (pWarpNode->id != 0) {
                warpNode = *pWarpNode;

                if (!(warpNode.destLevel & WARP_NO_CHECKPOINT)) {
                    sWarpCheckpointActive = check_warp_checkpoint(&warpNode);
                }

                initiate_warp(warpNode.destLevel & 0x7F, warpNode.destArea, warpNode.destNode, WARP_FLAGS_NONE);
                gIsGravityFlipped = FALSE;
                check_if_should_set_warp_checkpoint(&warpNode);

                play_transition_after_delay(WARP_TRANSITION_FADE_INTO_COLOR, 30, 255, 255, 255, 45);
                level_set_transition(74, basic_update);

                set_mario_action(gMarioState, ACT_DISAPPEARED, 0);

                gMarioState->marioObj->header.gfx.node.flags &= ~GRAPH_RENDER_ACTIVE;

                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                fadeout_music(398);
#if ENABLE_RUMBLE
                queue_rumble_data(80, 70);
                queue_rumble_decay(1);
#endif
            }
        }
    }
}

/**
 * If there is not already a delayed warp, schedule one. The source node is
 * based on the warp operation and sometimes Mario's used object.
 * Return the time left until the delayed warp is initiated.
 */
s16 level_trigger_warp(struct MarioState *m, s32 warpOp) {
    s32 fadeMusic = TRUE;

    if (sDelayedWarpOp == WARP_OP_NONE) {
#ifdef SAVE_NUM_LIVES
        save_file_set_num_lives(m->numLives);
#endif
        m->invincTimer = -1;
        sDelayedWarpArg = WARP_FLAGS_NONE;
        sDelayedWarpOp = warpOp;

        switch (warpOp) {
            case WARP_OP_DEMO_NEXT:
            case WARP_OP_DEMO_END:
                sDelayedWarpTimer = 20;
                sSourceWarpNodeId = WARP_NODE_DEFAULT;
                gSavedCourseNum = COURSE_NONE;
                fadeMusic = FALSE;
                play_transition(WARP_TRANSITION_FADE_INTO_STAR, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_CREDITS_END:
                sDelayedWarpTimer = 60;
                sSourceWarpNodeId = WARP_NODE_DEFAULT;
                fadeMusic = FALSE;
                gSavedCourseNum = COURSE_NONE;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_STAR_EXIT:
                sDelayedWarpTimer = 32;
                sSourceWarpNodeId = WARP_NODE_DEFAULT;
                gSavedCourseNum = COURSE_NONE;
                play_transition(WARP_TRANSITION_FADE_INTO_MARIO, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_DEATH:
#ifndef DISABLE_LIVES
                if (m->numLives == 0) {
                    sDelayedWarpOp = WARP_OP_GAME_OVER;
                }
#endif
                sDelayedWarpTimer = 48;
                sSourceWarpNodeId = WARP_NODE_DEATH;
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_BOWSER, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                play_sound(SOUND_MENU_BOWSER_LAUGH, gGlobalSoundSource);
#ifdef PREVENT_DEATH_LOOP
                m->isDead = TRUE;
#endif
                break;

            case WARP_OP_WARP_FLOOR:
                sSourceWarpNodeId = WARP_NODE_WARP_FLOOR;
                if (area_get_warp_node(sSourceWarpNodeId) == NULL) {
#ifndef DISABLE_LIVES
                    if (m->numLives == 0) {
                        sDelayedWarpOp = WARP_OP_GAME_OVER;
                    } else {
                        sSourceWarpNodeId = WARP_NODE_DEATH;
                    }
#else
                    sSourceWarpNodeId = WARP_NODE_DEATH;
#endif
                }

                if (gCurrCourseNum == COURSE_HF)
                {
                    if (gMarioStates->pos[2] > 5100.f)
                    {
                        sSourceWarpNodeId = 0x20;
                    }
                    else if (gMarioStates->pos[0] > 3100.f)
                    {
                        sSourceWarpNodeId = 0x21;
                    }
                    else if (gMarioStates->pos[2] < -5400.f)
                    {
                        sSourceWarpNodeId = 0x22;
                    }
                    else if (gMarioStates->pos[2] > 0.f && gMarioStates->pos[0] < -6000.f)
                    {
                        sSourceWarpNodeId = 0x23;
                    }
                }

                if (gCurrCourseNum == COURSE_BOB)
                {
                    if (gMarioStates->pos[2] > 6000.f)
                    {
                        // near the bottom drop
                        sSourceWarpNodeId = 0x21;
                    }
                    else if (gMarioStates->pos[1] < -1500.f)
                    {
                        // center
                        sSourceWarpNodeId = 0x20;
                    }
                    else
                    {
                        // near wallkicks
                        sSourceWarpNodeId = 0x22;
                    }
                }

                sDelayedWarpTimer = 20;
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_LOOK_UP: // enter totwc
                sDelayedWarpTimer = 30;
                sSourceWarpNodeId = WARP_NODE_LOOK_UP;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0xFF, 0xFF, 0xFF);
                play_sound(SOUND_MENU_STAR_SOUND, gGlobalSoundSource);
                break;

            case WARP_OP_SPIN_SHRINK: // bbh enter
                sDelayedWarpTimer = 30;
                sSourceWarpNodeId = GET_BPARAM2(m->usedObj->oBehParams);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0xFF, 0xFF, 0xFF);
                break;

            case WARP_OP_TELEPORT:
                sDelayedWarpTimer = 20;
                sSourceWarpNodeId = GET_BPARAM2(m->usedObj->oBehParams);
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0xFF, 0xFF, 0xFF);
                break;

            case WARP_OP_WARP_DOOR:
                sDelayedWarpTimer = 20;
                sDelayedWarpArg = m->actionArg;
                sSourceWarpNodeId = GET_BPARAM2(m->usedObj->oBehParams);
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_CIRCLE, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_WARP_OBJECT:
                sDelayedWarpTimer = 20;
                sSourceWarpNodeId = GET_BPARAM2(m->usedObj->oBehParams);
                fadeMusic = !music_unchanged_through_warp(sSourceWarpNodeId);
                play_transition(WARP_TRANSITION_FADE_INTO_STAR, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_CREDITS_START:
                sDelayedWarpTimer = 30;
                play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                break;

            case WARP_OP_CREDITS_NEXT:
                if (gCurrCreditsEntry == &sCreditsSequence[0]) {
                    sDelayedWarpTimer = 60;
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                } else {
                    sDelayedWarpTimer = 20;
                    play_transition(WARP_TRANSITION_FADE_INTO_COLOR, sDelayedWarpTimer, 0x00, 0x00, 0x00);
                }
                fadeMusic = FALSE;
                break;
        }

        if (fadeMusic && gCurrDemoInput == NULL) {
            fadeout_music((3 * sDelayedWarpTimer / 2) * 8 - 2);
        }
    }

    return sDelayedWarpTimer;
}

/**
 * If a delayed warp is ready, initiate it.
 */
extern u8 gWarpTrigger;
void initiate_delayed_warp(void) {
    struct ObjectWarpNode *warpNode;
    s32 destWarpNode;

    if (sDelayedWarpOp != WARP_OP_NONE && --sDelayedWarpTimer == 0) {
        reset_dialog_render_state();

        if (gDebugLevelSelect && (sDelayedWarpOp & WARP_OP_TRIGGERS_LEVEL_SELECT)) {
            warp_special(WARP_SPECIAL_LEVEL_SELECT);
        } else if (gCurrDemoInput != NULL) {
            if (sDelayedWarpOp == WARP_OP_DEMO_END) {
                warp_special(WARP_SPECIAL_INTRO_SPLASH_SCREEN);
            } else {
                warp_special(WARP_SPECIAL_MARIO_HEAD_REGULAR);
            }
        } else {
            switch (sDelayedWarpOp) {
                case WARP_OP_GAME_OVER:
                    save_file_reload();
                    warp_special(WARP_SPECIAL_MARIO_HEAD_DIZZY);
                    break;

                case WARP_OP_CREDITS_END:
                    warp_special(WARP_SPECIAL_ENDING);
                    sound_banks_enable(SEQ_PLAYER_SFX, SOUND_BANKS_ALL & ~SOUND_BANKS_DISABLED_AFTER_CREDITS);
                    break;

                case WARP_OP_DEMO_NEXT:
                    warp_special(WARP_SPECIAL_MARIO_HEAD_REGULAR);
                    break;

                case WARP_OP_CREDITS_START:
                    gCurrCreditsEntry = &sCreditsSequence[0];
                    initiate_warp(gCurrCreditsEntry->levelNum, gCurrCreditsEntry->areaIndex,
                                  WARP_NODE_CREDITS_START, WARP_FLAGS_NONE);
                    break;

                case WARP_OP_CREDITS_NEXT:
                    sound_banks_disable(SEQ_PLAYER_SFX, SOUND_BANKS_ALL);

                    gCurrCreditsEntry++;
                    gCurrActNum = gCurrCreditsEntry->actNum & 0x07;
                    if ((gCurrCreditsEntry + 1)->levelNum == LEVEL_NONE) {
                        destWarpNode = WARP_NODE_CREDITS_END;
                        initiate_warp(LEVEL_ENDING, 1, 0, WARP_FLAGS_NONE);
                    } else {
                        destWarpNode = WARP_NODE_CREDITS_NEXT;
                        initiate_warp(gCurrCreditsEntry->levelNum, gCurrCreditsEntry->areaIndex, destWarpNode, WARP_FLAGS_NONE);
                    }
                    break;

                default:
                    gWarpTrigger = 1;
                    warpNode = area_get_warp_node(sSourceWarpNodeId);

                    initiate_warp(warpNode->node.destLevel & 0x7F, warpNode->node.destArea,
                                  warpNode->node.destNode, sDelayedWarpArg);

                    check_if_should_set_warp_checkpoint(&warpNode->node);
                    if (sWarpDest.type != WARP_TYPE_CHANGE_LEVEL) {
                        level_set_transition(2, NULL);
                    }
                    break;
            }
        }
    }
}

void update_hud_values(void) {
    if (gCurrCreditsEntry == NULL) {
        s16 numHealthWedges = gMarioState->health > 0 ? gMarioState->health >> 8 : 0;

#ifdef BREATH_METER
        s16 numBreathWedges = gMarioState->breath > 0 ? gMarioState->breath >> 8 : 0;
#endif
        COND_BIT((gCurrCourseNum >= COURSE_MIN), gHudDisplay.flags, HUD_DISPLAY_FLAG_COIN_COUNT);

        if (gHudDisplay.coins < gMarioState->numCoins) {
            if (gGlobalTimer & 1) {
                u32 coinSound;
                if (gMarioState->action & (ACT_FLAG_SWIMMING | ACT_FLAG_METAL_WATER)) {
                    coinSound = SOUND_GENERAL_COIN_WATER;
                } else {
                    coinSound = SOUND_GENERAL_COIN;
                }

                gHudDisplay.coins++;
                play_sound(coinSound, gMarioState->marioObj->header.gfx.cameraToObject);
            }
        }

#ifdef SAVE_NUM_LIVES
        if (gMarioState->numLives > MAX_NUM_LIVES) {
            gMarioState->numLives = MAX_NUM_LIVES;
            save_file_set_num_lives(MAX_NUM_LIVES);
        }
#else
        if (gMarioState->numLives > 100) {
            gMarioState->numLives = 100;
        }
#endif

#if BUGFIX_MAX_LIVES
        if (gMarioState->numCoins > 999) {
            gMarioState->numCoins = 999;
        }

        if (gHudDisplay.coins > 999) {
            gHudDisplay.coins = 999;
        }
#else
        if (gMarioState->numCoins > 999) {
            gMarioState->numLives = (s8) 999; //! Wrong variable
        }
#endif

        gHudDisplay.stars = gMarioState->numStars;
        gHudDisplay.lives = gMarioState->numLives;
        gHudDisplay.keys = gMarioState->numKeys;

        if (numHealthWedges > gHudDisplay.wedges) {
            play_sound(SOUND_MENU_POWER_METER, gGlobalSoundSource);
        }
        gHudDisplay.wedges = numHealthWedges;

        COND_BIT((gMarioState->hurtCounter > 0), gHudDisplay.flags, HUD_DISPLAY_FLAG_EMPHASIZE_POWER);
#ifdef BREATH_METER
        gHudDisplay.breath = numBreathWedges;
        COND_BIT((gMarioState->breath > 0), gHudDisplay.flags, HUD_DISPLAY_FLAG_BREATH_METER);
#endif
    }
}

/**
 * Update objects, HUD, and camera. This update function excludes things like
 * endless staircase, warps, pausing, etc. This is used when entering a painting,
 * presumably to allow painting and camera updating while avoiding triggering the
 * warp twice.
 */
void basic_update(void) {
    area_update_objects();
    update_hud_values();
#ifdef PUPPYLIGHTS
    delete_lights();
#endif

    if (gCurrentArea != NULL) {
        update_camera(gCurrentArea->camera);
    }
}

s32 play_mode_normal(void) {
#ifndef DISABLE_DEMO
    if (gCurrDemoInput != NULL) {
        print_intro_text();
        if (gPlayer1Controller->buttonPressed & END_DEMO) {
            level_trigger_warp(gMarioState, gCurrLevelNum == LEVEL_PSS ? WARP_OP_DEMO_END : WARP_OP_DEMO_NEXT);
        } else if (!gWarpTransition.isActive && sDelayedWarpOp == WARP_OP_NONE
                   && (gPlayer1Controller->buttonPressed & START_BUTTON)) {
            level_trigger_warp(gMarioState, WARP_OP_DEMO_NEXT);
        }
    }
#endif

    warp_area();
    check_instant_warp();
    /*char buffer[50]; debug text
    sprintf(buffer, "up times: %d down times: %d gDnvicChamber: %d", gDnvicUpCounter, gDnvicDownCounter, gDnvicChamber); 
    /dnvic_print_white_text(100, 100, buffer, PRINT_TEXT_ALIGN_CENTRE, PRINT_ALL, 0xFF); */

    if (sTimerRunning && gHudDisplay.timer < 17999) {
        gHudDisplay.timer++;
    }

    area_update_objects();
    update_hud_values();
#ifdef PUPPYLIGHTS
    delete_lights();
#endif

    if (gCurrentArea != NULL) {
        update_camera(gCurrentArea->camera);
    }

    initiate_painting_warp();
    initiate_delayed_warp();

    // If either initiate_painting_warp or initiate_delayed_warp initiated a
    // warp, change play mode accordingly.
    if (sCurrPlayMode == PLAY_MODE_NORMAL) {
        if (sWarpDest.type == WARP_TYPE_CHANGE_LEVEL) {
            set_play_mode(PLAY_MODE_CHANGE_LEVEL);
        } else if (sTransitionTimer != 0) {
            set_play_mode(PLAY_MODE_CHANGE_AREA);
        } else if (pressed_pause()) {
            lower_background_noise(2);
#if ENABLE_RUMBLE
            cancel_rumble();
#endif
            gCameraMovementFlags |= CAM_MOVE_PAUSE_SCREEN;
            set_play_mode(PLAY_MODE_PAUSED);
        }
    }

    return FALSE;
}

s32 play_mode_paused(void) {
    if (gMenuOptSelectIndex == MENU_OPT_NONE) {
        set_menu_mode(MENU_MODE_RENDER_PAUSE_SCREEN);
    } else if (gMenuOptSelectIndex == MENU_OPT_DEFAULT) {
        raise_background_noise(2);
        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
        set_play_mode(PLAY_MODE_NORMAL);
#ifndef DISABLE_EXIT_COURSE
    } else { // MENU_OPT_EXIT_COURSE
        if (gDebugLevelSelect) {
            fade_into_special_warp(WARP_SPECIAL_LEVEL_SELECT, 1);
        } else {
            if (gCurrCourseNum == COURSE_DF
             || gCurrCourseNum == COURSE_SA
             || gCurrCourseNum == COURSE_VCUTM
             || gCurrCourseNum == COURSE_RNG)
            {
                if (gCurrCourseNum == COURSE_RNG)
                {
                    initiate_warp(LEVEL_CASTLE, EXIT_COURSE_AREA, 0x31, WARP_FLAGS_NONE);
                }
                else
                {
                    initiate_warp(EXIT_COURSE_LEVEL, EXIT_COURSE_AREA, EXIT_COURSE_NODE, WARP_FLAGS_NONE);
                }
                fade_into_special_warp(WARP_SPECIAL_NONE, 0);
            }
            else
            {
                struct ObjectWarpNode* warpNode = area_get_warp_node(0xf1);
                initiate_warp(warpNode->node.destLevel, warpNode->node.destArea, warpNode->node.destNode, 0);
            }
            fade_into_special_warp(0, 0);
            gSavedCourseNum = COURSE_NONE;
        }

        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
#endif
    }

    return FALSE;
}

/**
 * Debug mode that lets you frame advance by pressing D-pad down. Unfortunately
 * it uses the pause camera, making it basically unusable in most levels.
 */
s32 play_mode_frame_advance(void) {
    if (gPlayer1Controller->buttonPressed & D_JPAD) {
        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
        play_mode_normal();
    } else if (gPlayer1Controller->buttonPressed & START_BUTTON) {
        gCameraMovementFlags &= ~CAM_MOVE_PAUSE_SCREEN;
        raise_background_noise(1);
        set_play_mode(PLAY_MODE_NORMAL);
    } else {
        gCameraMovementFlags |= CAM_MOVE_PAUSE_SCREEN;
    }

    return FALSE;
}

/**
 * Set the transition, which is a period of time after the warp is initiated
 * but before it actually occurs. If updateFunction is not NULL, it will be
 * called each frame during the transition.
 */
void level_set_transition(s16 length, void (*updateFunction)()) {
    sTransitionTimer = length;
    sTransitionUpdate = updateFunction;
}

/**
 * Play the transition and then return to normal play mode.
 */
s32 play_mode_change_area(void) {
    // sm64ex-alo
    // Change function to have similar change_level defines
    if (sTransitionUpdate != NULL) {
        sTransitionUpdate(&sTransitionTimer);
    }

    if (--sTransitionTimer == -1) {
        update_camera(gCurrentArea->camera);
        sTransitionTimer = 0;
        sTransitionUpdate = NULL;
        set_play_mode(PLAY_MODE_NORMAL);
    }

    return FALSE;
}

/**
 * Play the transition and then return to normal play mode.
 */
s32 play_mode_change_level(void) {
    if (sTransitionUpdate != NULL) {
        sTransitionUpdate(&sTransitionTimer);
    }

    if (--sTransitionTimer == -1) {
        gHudDisplay.flags = HUD_DISPLAY_NONE;
        sTransitionTimer = 0;
        sTransitionUpdate = NULL;

        if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
            return sWarpDest.levelNum;
        } else {
            return sSpecialWarpDest;
        }
    }

    return FALSE;
}

/**
 * Unused play mode. Doesn't call transition update and doesn't reset transition at the end.
 */
UNUSED static s32 play_mode_unused(void) {
    if (--sTransitionTimer == -1) {
        gHudDisplay.flags = HUD_DISPLAY_NONE;

        if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
            return sWarpDest.levelNum;
        } else {
            return sSpecialWarpDest;
        }
    }

    return FALSE;
}

s32 update_level(void) {
    s32 changeLevel = FALSE;

    switch (sCurrPlayMode) {
        case PLAY_MODE_NORMAL:
            changeLevel = play_mode_normal(); scroll_textures();
            break;
        case PLAY_MODE_PAUSED:
            changeLevel = play_mode_paused();
            break;
        case PLAY_MODE_CHANGE_AREA:
            changeLevel = play_mode_change_area();
            break;
        case PLAY_MODE_CHANGE_LEVEL:
            changeLevel = play_mode_change_level();
            break;
        case PLAY_MODE_FRAME_ADVANCE:
            changeLevel = play_mode_frame_advance();
            break;
    }

    if (changeLevel) {
        reset_volume();
        enable_background_sound();
    }

    return changeLevel;
}

s32 init_level(void) {
    s32 fadeFromColor = FALSE;
#if PUPPYPRINT_DEBUG
    OSTime first = osGetTime();
#endif

    set_play_mode(PLAY_MODE_NORMAL);

    sDelayedWarpOp = WARP_OP_NONE;
    sTransitionTimer = 0;
    sSpecialWarpDest = WARP_SPECIAL_NONE;

    if (gCurrCreditsEntry == NULL) {
        gHudDisplay.flags = HUD_DISPLAY_DEFAULT;
    } else {
        gHudDisplay.flags = HUD_DISPLAY_NONE;
    }

    sTimerRunning = FALSE;

    if (sWarpDest.type != WARP_TYPE_NOT_WARPING) {
        if (sWarpDest.nodeId >= WARP_NODE_CREDITS_MIN) {
            warp_credits();
        } else {
            warp_level();
        }
    } else {
        if (gPlayerSpawnInfos[0].areaIndex >= 0) {
            load_mario_area();
            init_mario();
        }

        if (gCurrentArea != NULL) {
            reset_camera(gCurrentArea->camera);

#ifdef PEACH_SKIP
            if (gCurrDemoInput != NULL) {
                set_mario_action(gMarioState, ACT_IDLE, 0);
            } else if (!gDebugLevelSelect) {
                if (gMarioState->action != ACT_UNINITIALIZED) {
                    set_mario_action(gMarioState, ACT_IDLE, 0);
                }
            }
        }
#else
            if (gCurrDemoInput != NULL) {
                set_mario_action(gMarioState, ACT_IDLE, 0);
            } else if (!gDebugLevelSelect) {
                if (gMarioState->action != ACT_UNINITIALIZED) {
                    if (save_file_exists(gCurrSaveFileNum - 1)) {
                        set_mario_action(gMarioState, ACT_IDLE, 0);
                    } else {
                        set_mario_action(gMarioState, ACT_INTRO_CUTSCENE, 0);
                        fadeFromColor = TRUE;
                    }
                }
            }
        }
#endif
        if (fadeFromColor) {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 0x5A, 0xFF, 0xFF, 0xFF);
        } else {
            play_transition(WARP_TRANSITION_FADE_FROM_STAR, 0x10, 0xFF, 0xFF, 0xFF);
        }

        if (gCurrDemoInput == NULL) {
            set_background_music(gCurrentArea->musicParam, gCurrentArea->musicParam2, 0);
        }
    }
#if ENABLE_RUMBLE
    if (gCurrDemoInput == NULL) {
        cancel_rumble();
    }
#endif

    if (gMarioState->action == ACT_INTRO_CUTSCENE) {
        sound_banks_disable(SEQ_PLAYER_SFX, SOUND_BANKS_DISABLED_DURING_INTRO_CUTSCENE);
    }

#ifdef PUPPYLIGHTS
    puppylights_allocate();
#endif

#if PUPPYPRINT_DEBUG
#ifdef PUPPYPRINT_DEBUG_CYCLES
    append_puppyprint_log("Level loaded in %dc", (s32)(osGetTime() - first));
#else
    append_puppyprint_log("Level loaded in %dus", (s32)(OS_CYCLES_TO_USEC(osGetTime() - first)));
#endif
#endif
    return TRUE;
}

/**
 * Initialize the current level if initOrUpdate is 0, or update the level if it is 1.
 */
s32 lvl_init_or_update(s16 initOrUpdate, UNUSED s32 unused) {
    return (initOrUpdate ? update_level() : init_level());
}

#if MULTILANG
void load_language_text(void) {
    switch (gInGameLanguage - 1) {
        case LANGUAGE_ENGLISH:
            load_segment_decompress(SEGMENT_EU_TRANSLATION, _translation_en_yay0SegmentRomStart, _translation_en_yay0SegmentRomEnd);
            break;
        case LANGUAGE_FRENCH:
            load_segment_decompress(SEGMENT_EU_TRANSLATION, _translation_fr_yay0SegmentRomStart, _translation_fr_yay0SegmentRomEnd);
            break;
        case LANGUAGE_GERMAN:
            load_segment_decompress(SEGMENT_EU_TRANSLATION, _translation_de_yay0SegmentRomStart, _translation_de_yay0SegmentRomEnd);
            break;
    }
}
#endif

s32 lvl_init_from_save_file(UNUSED s16 initOrUpdate, s32 levelNum) {
#if MULTILANG
    gInGameLanguage = eu_get_language()+1;
    load_language_text();
#endif
    sWarpDest.type = WARP_TYPE_NOT_WARPING;
    sDelayedWarpOp = WARP_OP_NONE;
#ifdef CASTLE_MUSIC_FIX
    gNeverEnteredCastle = 0;
#else
    gNeverEnteredCastle = !save_file_exists(gCurrSaveFileNum - 1);
#endif
    gCurrLevelNum = levelNum;
    gCurrCourseNum = COURSE_NONE;
    gSavedCourseNum = COURSE_NONE;
    gCurrCreditsEntry = NULL;
    gSpecialTripleJump = FALSE;

    init_mario_from_save_file();
    disable_warp_checkpoint();
    save_file_move_cap_to_default_location();
    select_mario_cam_mode();
    set_yoshi_as_not_dead();

    return levelNum;
}

s32 lvl_set_current_level(UNUSED s16 initOrUpdate, s32 levelNum) {
    s32 warpCheckpointActive = sWarpCheckpointActive;

    sWarpCheckpointActive = FALSE;
    gCurrLevelNum = levelNum;
    gCurrCourseNum = gLevelToCourseNumTable[levelNum - 1];
	if (gCurrLevelNum == LEVEL_SA) return 0;
		
	if (gCurrLevelNum == LEVEL_VCUTM) return 0;
	if (gCurrLevelNum == LEVEL_COTMC) return 0;

    if (gCurrDemoInput != NULL || gCurrCreditsEntry != NULL || gCurrCourseNum == COURSE_NONE) {
        return FALSE;
    }

    if (gCurrLevelNum != LEVEL_BOWSER_1 && gCurrLevelNum != LEVEL_BOWSER_2 && gCurrLevelNum != LEVEL_BOWSER_3) {
        gMarioState->numCoins = 0;
        gHudDisplay.coins = 0;
        gCurrCourseStarFlags =
            save_file_get_star_flags(gCurrSaveFileNum - 1, COURSE_NUM_TO_INDEX(gCurrCourseNum));
    }

    if (gSavedCourseNum != gCurrCourseNum) {
        gSavedCourseNum = gCurrCourseNum;
        disable_warp_checkpoint();
    }

    if (gCurrCourseNum > COURSE_STAGES_MAX || warpCheckpointActive) {
        return FALSE;
    }

    return !gDebugLevelSelect;
}

/**
 * Play the "thank you so much for to playing my game" sound.
 */
s32 lvl_play_the_end_screen_sound(UNUSED s16 initOrUpdate, UNUSED s32 levelNum) {
    seq_player_fade_out(0, 1000);
    play_sound(SOUND_MENU_THANK_YOU_PLAYING_MY_GAME, gGlobalSoundSource);
    return TRUE;
}
