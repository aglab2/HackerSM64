#pragma once
#include "bool.h"
#include "types.h"

#include "game/level_update.h"

extern u32 sLastAction;
static inline void Action_onNormal()
{ sLastAction = gMarioStates->action; }
static inline u32  Action_last()
{ return sLastAction; }
static inline bool Action_changed()
{ return sLastAction != gMarioStates->action; }
