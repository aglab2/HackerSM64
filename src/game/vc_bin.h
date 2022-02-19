// These functions are actually fully binary and this is a lie

#include <ultra64.h>

s32 osEepromReadVC(OSMesgQueue *mq, u8 address, u8 *buffer);
s32 osEepromWriteVC(OSMesgQueue *mq, u8 address, u8 *buffer);
s32 __osEepStatusVC(OSMesgQueue *mq, OSContStatus *data);
