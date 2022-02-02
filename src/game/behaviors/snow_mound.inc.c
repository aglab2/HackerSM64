// snow_mound.inc.c

void bhv_sliding_snow_mound_loop(void) {
    switch (o->oAction) {
        case 0:
            o->oVelX = -50.0f * sins(o->oFaceAngleYaw + 0x4000);
            o->oVelZ = -50.0f * coss(o->oFaceAngleYaw + 0x4000);
            o->oPosX += o->oVelX;
            o->oPosZ += o->oVelZ;
            if (o->oTimer > 100) {
                o->oAction = 1;
            }
            cur_obj_play_sound_1(SOUND_ENV_SINK_QUICKSAND);
            break;

        case 1:
            o->oVelX = -5.0f * sins(o->oFaceAngleYaw + 0x4000);
            o->oVelZ = -5.0f * coss(o->oFaceAngleYaw + 0x4000);
            o->oPosX += o->oVelX;
            o->oPosZ += o->oVelZ;
            o->oVelY = -10.0f;
            o->oPosY += o->oVelY;
            // o->oPosZ = o->oHomeZ - 2.0f;
            if (o->oTimer > 50) {
                o->activeFlags = ACTIVE_FLAG_DEACTIVATED;
            }
            break;
    }
}

void bhv_snow_mound_spawn_loop(void) {
    struct Object *moundObj = NULL;

    if (!is_point_within_radius_of_mario(o->oPosX, o->oPosY, o->oPosZ, 10000)
        || o->oPosY + 1000.0f < gMarioObject->header.gfx.pos[1]) {
        return;
    }

    if (0 == (o->oTimer % 20)) {
        moundObj = spawn_object(o, MODEL_SL_SNOW_TRIANGLE, bhvSlidingSnowMound);
    }

    if (moundObj)
    {
        moundObj->oFaceAngleYaw = o->oFaceAngleYaw;
        moundObj->header.gfx.scale[0] = 2.0f;
        moundObj->header.gfx.scale[1] = 2.0f;
    }
}
