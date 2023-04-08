#include "death_floor.h"

#include "audio/external.h"
#include "game/area.h"
#include "course_table.h"
#include "game/level_update.h"
#include "sm64.h"

#include "cfg.h"
#include "death.h"

extern u8 gDeathFloorBarrier;

void DeathFloor_checkDeathBarrierHook(struct MarioState *m)
{
    Config_DeathAction action = Config_deathAction();
    if (action != Config_DeathAction_OFF)
    {
        Death_TouchedDeathFloor = true;
    }
    else if (level_trigger_warp(m, WARP_OP_WARP_FLOOR) == 20 && !(m->flags & MARIO_FALL_SOUND_PLAYED)) 
    {
        if (gCurrCourseNum != COURSE_RNG && gCurrCourseNum != COURSE_ROVERT)
        {
            if (level_trigger_warp(m, WARP_OP_WARP_FLOOR) == 20 && !(m->flags & MARIO_FALL_SOUND_PLAYED)) {
                mario_stop_riding_and_holding(m);
                play_sound(SOUND_MARIO_WAAAOOOW, m->marioObj->header.gfx.cameraToObject);
            }
        }
        else
        {
            gDeathFloorBarrier = 1;
            // play_sound(SOUND_MARIO_WAAAOOOW, m->marioObj->header.gfx.cameraToObject);
        }
    }
}
