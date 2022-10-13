#include "level_table.h"

typedef enum LevelConv_PlainLevels
{
    LevelConv_PlainLevels_OFF,
    LevelConv_PlainLevels_C1,
    LevelConv_PlainLevels_C2,
    LevelConv_PlainLevels_C3,
    LevelConv_PlainLevels_C4,
    LevelConv_PlainLevels_C5,
    LevelConv_PlainLevels_C6,
    LevelConv_PlainLevels_C7,
    LevelConv_PlainLevels_C8,
    LevelConv_PlainLevels_C9,
    LevelConv_PlainLevels_C10,

    LevelConv_PlainLevels_SPHERE,
    LevelConv_PlainLevels_DAN,
    LevelConv_PlainLevels_RNG,
    LevelConv_PlainLevels_CRASH,
    LevelConv_PlainLevels_SA,
    LevelConv_PlainLevels_WMOTR,
    LevelConv_PlainLevels_BITFS,
    LevelConv_PlainLevels_BDF,
    LevelConv_PlainLevels_Slide,
    LevelConv_PlainLevels_MC,
    LevelConv_PlainLevels_WC,
    LevelConv_PlainLevels_VCM,
    LevelConv_PlainLevels_VC,
    LevelConv_PlainLevels_DF,
} LevelConv_PlainLevels;

typedef enum LevelConv_SM64Levels
{
    LevelConv_SM64Levels_OFF = LEVEL_NONE,
    LevelConv_SM64Levels_C1 = LEVEL_AB,
    LevelConv_SM64Levels_C2 = LEVEL_MTC,
    LevelConv_SM64Levels_C3 = LEVEL_MF,
    LevelConv_SM64Levels_C4 = LEVEL_HF,
    LevelConv_SM64Levels_C5 = LEVEL_BOB,
    LevelConv_SM64Levels_C6 = LEVEL_SPIDERS,
    LevelConv_SM64Levels_C7 = LEVEL_LUIGIMAN,
    LevelConv_SM64Levels_C8 = LEVEL_ROVERT,
    LevelConv_SM64Levels_C9 = LEVEL_DDD,
    LevelConv_SM64Levels_C10 = LEVEL_SL,

    LevelConv_SM64Levels_SPHERE = LEVEL_SPHERE,
    LevelConv_SM64Levels_DAN = LEVEL_DAN,
    LevelConv_SM64Levels_RNG = LEVEL_RNG,
    LevelConv_SM64Levels_CRASH = LEVEL_CRASH,
    LevelConv_SM64Levels_SA = LEVEL_SA,
    LevelConv_SM64Levels_WMOTR = LEVEL_WMOTR,
    LevelConv_SM64Levels_BITFS = LEVEL_BITFS,
    LevelConv_SM64Levels_BDF = LEVEL_BDF,
    LevelConv_SM64Levels_Slide = LEVEL_PSS,
    LevelConv_SM64Levels_MC = LEVEL_COTMC,
    LevelConv_SM64Levels_WC = LEVEL_TOTWC,
    LevelConv_SM64Levels_VCM = LEVEL_VCM,
    LevelConv_SM64Levels_VC = LEVEL_VCUTM,
    LevelConv_SM64Levels_DF = LEVEL_DF,
} LevelConv_SM64Levels;

LevelConv_SM64Levels LevelConv_toSM64Level(LevelConv_PlainLevels);
