// Some libultra functions that use VC alternatives
s32 osEepromProbeVC(OSMesgQueue *mq);
s32 osEepromLongReadVC(OSMesgQueue *mq, u8 address, u8 *buffer, int length);
s32 osEepromLongWriteVC(OSMesgQueue *mq, u8 address, u8 *buffer, int length);
