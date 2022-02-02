#include "savestate.h"
#include "binary.h"

#include "cfg.h"
#include "text_manager.h"

#include "game/area.h"
#include "game/camera.h"
#include "game/print.h"
#include "game/level_update.h"
#include "libc/string.h"

void set_play_mode(s16 playMode);

// TODO: This is very much a culprit, useless one too
#define MaxStateSize 0x30000

typedef struct State
{
    s8 level;
    s8 area;
    char memory[MaxStateSize];
} State;

static bool mustSaveState = 0;

static void resetCamera()
{
    if (CAMERA_MODE_BEHIND_MARIO  == gCamera->mode
     || CAMERA_MODE_WATER_SURFACE == gCamera->mode
     || CAMERA_MODE_INSIDE_CANNON == gCamera->mode
     || CAMERA_MODE_CLOSE         == gCamera->mode)
    {
        set_camera_mode(gMarioStates->area->camera, gMarioStates->area->camera->defMode, 1);
    }

    if (CUTSCENE_ENTER_BOWSER_ARENA != gMarioStates->area->camera->cutscene)
    {
        gMarioStates->area->camera->cutscene = 0;
    }
}

void SaveState_onNormal()
{
    if (mustSaveState)
    {
        mustSaveState = false;
        gState->area  = gCurrAreaIndex;
        gState->level = gCurrCourseNum;
        memcpy(gState->memory, _hackticeStateDataStart, _hackticeStateDataEnd - _hackticeStateDataStart);
    }
    else
    {
        if (Config_action() == Config_ButtonAction_LOAD_STATE)
        {
            if (gState->area == gCurrAreaIndex && gState->level == gCurrCourseNum)
            {
                memcpy(_hackticeStateDataStart, gState->memory, _hackticeStateDataEnd - _hackticeStateDataStart);
                resetCamera();
            }
        }
    }
}

void SaveState_onPause()
{
    if ((Config_saveStateStyle() == Config_StateSaveStyle_PAUSE  && !mustSaveState)
     || (Config_saveStateStyle() == Config_StateSaveStyle_BUTTON && Config_action() == Config_ButtonAction_LOAD_STATE))
    {
        mustSaveState = true;
        TextManager_addLine("STATE SET", 30);
    }
}
