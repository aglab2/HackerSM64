#ifndef MAIN_H
#define MAIN_H

#include "config.h"

enum ThreadID {
    THREAD_0,
    THREAD_1_IDLE,
    THREAD_2_CRASH_SCREEN,
    THREAD_3_MAIN,
    THREAD_4_SOUND,
    THREAD_5_GAME_LOOP,
    THREAD_6_RUMBLE,
    THREAD_7_HVQM,
    THREAD_8_TIMEKEEPER,
    THREAD_9_DA_COUNTER,
};

struct RumbleData {
    u8  comm;
    u8  level;
    s16 time;
    s16 decay;
};

struct RumbleSettings {
    s16 event;
    s16 level;
    s16 timer;
    s16 count;
    s16 start;
    s16 slip;
    s16 vibrate;
    s16 decay;
};

extern struct Config gConfig __attribute__((section(".data")));

// extern OSThread gUnkThread;
extern OSThread gIdleThread;
extern OSThread gMainThread;
extern OSThread gGameLoopThread;
extern OSThread gSoundThread;
extern OSThread hvqmThread;
#if ENABLE_RUMBLE
extern OSThread gRumblePakThread;

extern OSPfs gRumblePakPfs;
#endif

extern OSMesgQueue gPIMesgQueue;
extern OSMesgQueue gIntrMesgQueue;
extern OSMesgQueue gSPTaskMesgQueue;
#if ENABLE_RUMBLE
extern OSMesgQueue gRumblePakSchedulerMesgQueue;
extern OSMesgQueue gRumbleThreadVIMesgQueue;
#endif
extern OSMesg gDmaMesgBuf[1];
extern OSMesg gPIMesgBuf[32];
extern OSMesg gSIEventMesgBuf[1];
extern OSMesg gIntrMesgBuf[16];
extern OSMesg gUnknownMesgBuf[16];
extern OSIoMesg gDmaIoMesg;
extern OSMesg gMainReceivedMesg __attribute__((section(".data")));
extern OSMesgQueue gDmaMesgQueue;
extern OSMesgQueue gSIEventMesgQueue __attribute__((section(".data")));
#if ENABLE_RUMBLE
extern OSMesg gRumblePakSchedulerMesgBuf[1];
extern OSMesg gRumbleThreadVIMesgBuf[1];

extern struct RumbleData gRumbleDataQueue[3];
extern struct RumbleSettings gCurrRumbleSettings;
#endif

extern struct VblankHandler *gVblankHandler1 __attribute__((section(".data")));
extern struct VblankHandler *gVblankHandler2 __attribute__((section(".data")));
extern struct SPTask *gActiveSPTask __attribute__((section(".data")));
extern u32 gNumVblanks __attribute__((section(".data")));
extern s8 gResetTimer __attribute__((section(".data")));
extern s8 gNmiResetBarsTimer __attribute__((section(".data")));
extern s8 gDebugLevelSelect __attribute__((section(".data")));
#ifdef VANILLA_DEBUG
extern s8 gShowDebugText;
#endif

void set_vblank_handler(s32 index, struct VblankHandler *handler, OSMesgQueue *queue, OSMesg *msg);
void dispatch_audio_sptask(struct SPTask *spTask);
void exec_display_list(struct SPTask *spTask);
void setgp();

#endif // MAIN_H
