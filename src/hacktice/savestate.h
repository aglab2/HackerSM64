#pragma once

#include "types.h"

void SaveState_onPause();
void SaveState_onNormal();

// TODO: This is very much a culprit, useless one too
#define MaxStateSize 0x30000

typedef struct
{
    s32 size;
    s16 level;
    s16 area;
    char memory[MaxStateSize];
} State;

extern State gHacktice_State[1];
