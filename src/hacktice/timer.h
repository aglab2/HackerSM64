#pragma once

#include "bool.h"

extern bool sGrabTimerSet;
static inline void Timer_reset()
{ sGrabTimerSet = false; }

void Timer_onFrame();
