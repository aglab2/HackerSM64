// swing_platform.inc.c

void bhv_swing_platform_init(void) {
    o->oSwingPlatformAngle =  0x1800;
}

void bhv_swing_platform_update(void) {
    s32 startRoll = o->oFaceAngleRoll;

    if (o->oFaceAngleRoll < 0) {
        o->oSwingPlatformSpeed += 20.f * (1 + o->oBehParams2ndByte);
    } else {
        o->oSwingPlatformSpeed -= 20.f * (1 + o->oBehParams2ndByte);
    }

    o->oSwingPlatformAngle += o->oSwingPlatformSpeed;
    o->oFaceAngleRoll = o->oSwingPlatformAngle;
    o->oAngleVelRoll = o->oFaceAngleRoll - startRoll;
}
