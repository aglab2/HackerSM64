#include "vc_bin.h"

s32 osEepromProbeVC(OSMesgQueue *mq)
{
    s32 ret;
    u16 type;
    ret = 0;
    OSContStatus sdata;
    ret = __osEepStatusVC(mq, &sdata);
    type = sdata.type & (CONT_EEPROM | CONT_EEP16K);
    if (ret != 0)
    {
        ret = 0;
    }
    else
    {
        switch (type)
        {
        case CONT_EEPROM:
            ret = EEPROM_TYPE_4K;
            break;
        case CONT_EEPROM | CONT_EEP16K:
            ret = EEPROM_TYPE_16K;
            break;
        default:
            ret = 0;
            break;
        }
    }

    return ret;
}

s32 osEepromLongReadVC(OSMesgQueue *mq, u8 address, u8 *buffer, int length)
{
    s32 ret;
    ret = 0;
    while (length > 0)
    {
        osEepromReadVC(mq, address, buffer);
        length -= EEPROM_BLOCK_SIZE;
        address++;
        buffer += EEPROM_BLOCK_SIZE;
    }
    return ret;
}

s32 osEepromLongWriteVC(OSMesgQueue *mq, u8 address, u8 *buffer, int length)
{
    s32 ret;
    ret = 0;
    while (length > 0)
    {
        osEepromWriteVC(mq, address, buffer);
        length -= EEPROM_BLOCK_SIZE;
        address++;
        buffer += EEPROM_BLOCK_SIZE;
    }
    return ret;
}
