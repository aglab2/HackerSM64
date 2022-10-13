#pragma once

#include "bool.h"

void Checkpoint_onNormal();

extern bool sShow;
static inline void Checkpoint_registerEvent()
{ sShow = true; }
