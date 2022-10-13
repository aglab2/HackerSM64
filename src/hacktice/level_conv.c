#include "level_conv.h"

LevelConv_SM64Levels LevelConv_toSM64Level(LevelConv_PlainLevels pl)
{
    static LevelConv_SM64Levels levels[] = 
    {
    LevelConv_SM64Levels_OFF,
    LevelConv_SM64Levels_C1,
    LevelConv_SM64Levels_C2,
    LevelConv_SM64Levels_C3,
    LevelConv_SM64Levels_C4,
    LevelConv_SM64Levels_C5,
    LevelConv_SM64Levels_C6,
    LevelConv_SM64Levels_C7,
    LevelConv_SM64Levels_C8,
    LevelConv_SM64Levels_C9,
    LevelConv_SM64Levels_C10,

    LevelConv_SM64Levels_SPHERE,
    LevelConv_SM64Levels_DAN,
    LevelConv_SM64Levels_RNG,
    LevelConv_SM64Levels_CRASH,
    LevelConv_SM64Levels_SA,
    LevelConv_SM64Levels_WMOTR,
    LevelConv_SM64Levels_BITFS,
    LevelConv_SM64Levels_BDF,
    LevelConv_SM64Levels_Slide,
    LevelConv_SM64Levels_MC,
    LevelConv_SM64Levels_WC,
    LevelConv_SM64Levels_VCM,
    LevelConv_SM64Levels_VC,
    LevelConv_SM64Levels_DF,
    };

    return levels[(int) pl];
}
