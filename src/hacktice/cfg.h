#pragma once

#include "bool.h"
#include "types.h"
#include "level_conv.h"

typedef struct
{
    char speed;
    char stickStyle;
    char showButtons;
    char lAction;
    char lRAction;
    char cButtonsAction;
    char dpadDownAction;
    char warp;
    char wallkickFrame;
    char distanceFromClosestRed;
    char distanceFromClosestSecret;
    char timerShow;
    char timerStyle;
    char timerStopOnCoinStar;
    char stateSaveStyle;
    char muteMusic;
    char musicNumber;
    char deathAction;

    char checkpointWallkick;
    char checkpointDoor;
    char checkpointPole;
    char checkpointLava;
    char checkpointGroundpound;
    char checkpointBurning;
    char checkpointCannon;
    char checkpointWarp;
    char checkpointRed;
    char checkpointCoin;
    char checkpointObject;
    char checkpointPlatform;
} Hacktice_Config;

extern Hacktice_Config sConfig;
extern u8 sOnDeathAction;

void Config_onPause();

typedef enum Config_StickStyle
{
    Config_StickStyle_OFF,
    Config_StickStyle_VALUE,
    Config_StickStyle_GRAPHICS,  
} Config_StickStyle;
static inline Config_StickStyle Config_showStick()
{ return (Config_StickStyle) sConfig.stickStyle; }

static inline bool Config_showButtons()
{ return sConfig.showButtons; }

typedef enum Config_ButtonAction
{
    Config_ButtonAction_OFF,
    Config_ButtonAction_ACT_SELECT,
    Config_ButtonAction_LEVEL_RESET,
    Config_ButtonAction_LEVEL_RESET_WARP,
    Config_ButtonAction_LEVITATE,
    Config_ButtonAction_LOAD_STATE,
} Config_ButtonAction;
Config_ButtonAction Config_action();

static inline LevelConv_PlainLevels Config_warpId()
{ return (LevelConv_PlainLevels) sConfig.warp; }

LevelConv_PlainLevels Config_warpIdAndReset();

static inline bool Config_showWallkickFrame()
{ return sConfig.wallkickFrame; }
static inline bool Config_showDistanceFromClosestRed()
{ return sConfig.distanceFromClosestRed; }
static inline bool Config_showDistanceFromClosestSecret()
{ return sConfig.distanceFromClosestSecret; }

typedef enum Config_TimerStyle
{
    Config_TimerStyle_GRAB,
    Config_TimerStyle_XCAM,
} Config_TimerStyle;

typedef enum Config_StateSaveStyle
{
    Config_StateSaveStyle_BUTTON,
    Config_StateSaveStyle_PAUSE,
} Config_StateSaveStyle;

typedef enum Config_DeathAction
{
    Config_DeathAction_OFF,
    Config_DeathAction_ACT_RESET,
    Config_DeathAction_LEVEL_RESET,
    Config_DeathAction_LOAD_STATE,
} Config_DeathAction;

static inline bool Config_showSpeed()
{ return sConfig.speed; }
static inline bool Config_timerShow()
{ return sConfig.timerShow; }
static inline Config_TimerStyle Config_timerStyle()
{ return (Config_TimerStyle) sConfig.timerStyle; }
static inline bool Config_timerStopOnCoinStar()
{ return sConfig.timerStopOnCoinStar; }
static inline Config_StateSaveStyle Config_saveStateStyle()
{ return (Config_StateSaveStyle) sConfig.stateSaveStyle; }
static inline bool Config_muteMusic()
{ return sConfig.muteMusic; }
static inline char Config_musicNumber()
{ return sConfig.musicNumber; }
static inline Config_DeathAction Config_deathAction()
{ return (Config_DeathAction) sConfig.deathAction; }
static inline void Config_setOnDeathAction(Config_ButtonAction act)
{ sOnDeathAction = (u8) act; }
static inline bool Config_checkpointWallkick()
{ return sConfig.checkpointWallkick; }
static inline bool Config_checkpointDoor()
{ return sConfig.checkpointDoor; }
static inline bool Config_checkpointPole()
{ return sConfig.checkpointPole; }
static inline bool Config_checkpointLava()
{ return sConfig.checkpointLava; }
static inline bool Config_checkpointGroundpound()
{ return sConfig.checkpointGroundpound; }
static inline bool Config_checkpointBurning()
{ return sConfig.checkpointBurning; }
static inline bool Config_checkpointCannon()
{ return sConfig.checkpointCannon; }
static inline bool Config_checkpointWarp()
{ return sConfig.checkpointWarp; }
static inline bool Config_checkpointRed()
{ return sConfig.checkpointRed; }
static inline bool Config_checkpointCoin()
{ return sConfig.checkpointCoin; }
static inline bool Config_checkpointObject()
{ return sConfig.checkpointObject; }
static inline bool Config_checkpointPlatform()
{ return sConfig.checkpointPlatform; }
