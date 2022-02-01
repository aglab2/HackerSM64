#include "action.h"
#include "game/level_update.h"

u32 sLastAction = 0;
void Action_onNormal()
{
    sLastAction = gMarioStates->action;
}

u32 Action_last()
{
    return sLastAction;
}

bool Action_changed()
{
    return sLastAction != gMarioStates->action;
}
