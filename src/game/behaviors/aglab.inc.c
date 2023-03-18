void bhv_aglab_lakitu_init()
{
    spawn_object_relative_with_scale(CLOUD_BP_LAKITU_CLOUD, 0, 0, 0, 2.0f, o, MODEL_MIST, bhvCloud);
}

extern s16 gDialogID;

void bhv_aglab_lakitu_loop()
{
    if (o->oDistanceToMario < 500.f && set_mario_npc_dialog(MARIO_DIALOG_LOOK_UP) == MARIO_DIALOG_STATUS_SPEAK)
    {
        gDialogID = 30;
    }

    o->oHomeX = gLakituState.curFocus[0];
    o->oHomeZ = gLakituState.curFocus[2];

    o->oFaceAngleYaw = cur_obj_angle_to_home();
    o->oFaceAnglePitch = atan2s(cur_obj_lateral_dist_to_home(), o->oPosY - gLakituState.curFocus[1]);
}
