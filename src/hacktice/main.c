#include "main.h"
#include "types.h"

#include "game/level_update.h"

#include "cfg.h"
#include "distance.h"
#include "death.h"
#include "input_viewer.h"
#include "level_reset.h"
#include "levitate.h"
#include "savestate.h"
#include "speed.h"
#include "text_manager.h"
#include "timer.h"
#include "wallkick_frame.h"
#include "checkpoint.h"
#include "action.h"
#include "interaction.h"
#include "music.h"

#define PLAY_MODE_NORMAL 0
#define PLAY_MODE_PAUSED 2

void Hacktice_onFrame()
{
    if (PLAY_MODE_NORMAL == sCurrPlayMode)
    {
        Death_onNormal();
        Distance_onNormal();
        InputViewer_onNormal();
        LevelReset_onNormal();
        Levitate_onNormal();
        SaveState_onNormal();
        Speed_onNormal();
        WallkickFrame_onNormal();
        Interaction_onNormal();
        Music_onFrame();

        Checkpoint_onNormal();
        
        Action_onNormal();
    }

    Timer_onFrame();
    TextManager_onFrame();
}

void Hacktice_onPause()
{
    SaveState_onPause();
    Config_onPause();
}

#ifdef BINARY
uintptr_t _start[] = {
    (uintptr_t) Hacktice_onFrame,
    (uintptr_t) Hacktice_onPause,
    (uintptr_t) Music_setVolumeHook,
};
#else
bool Hacktice_gEnabled = false;
#endif
