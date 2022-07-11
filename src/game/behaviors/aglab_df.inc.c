
extern struct CreditsEntry *gCurrCreditsEntry;
void mf_df_level_reset_init()
{
    if (gCurrCreditsEntry)
    {
        o->activeFlags = 0;
    }
}

static f32 sDfPositions[][3] = {
    { -862, -114, -617 },
    { -7504, 1153, -3301 },
    { 990, 1153, -3389 },
};

void mf_df_level_reset_loop()
{
    f32 d;
    o->activeFlags |= ACTIVE_FLAG_INITIATED_TIME_STOP;
    struct Object* red = cur_obj_find_nearest_object_with_behavior(bhvRedCoin, &d);
    if (!red)
    {
        return;
    }

    if (0 == o->oAction)
    {
        if (0 == o->oTimer)
        {
            reset_camera(gCamera);
            set_camera_mode(gCamera, gCamera->defMode, 1);
        }

        struct Surface* floor = gMarioStates->floor;
        int type = floor ? floor->type : 0;
        int isOnCheckpoint = type == SURFACE_HARD || type == SURFACE_HARD_NOT_SLIPPERY || type == SURFACE_NOISE_DEFAULT || type == SURFACE_0018;
        if (isOnCheckpoint)
        {
            if (floor->type == SURFACE_HARD)
                o->oDfLastCheckpoint = 0;
            if (floor->type == SURFACE_HARD_NOT_SLIPPERY)
                o->oDfLastCheckpoint = 1;
            if (floor->type == SURFACE_NOISE_DEFAULT)
                o->oDfLastCheckpoint = 2;

            o->oTimer = 0;
        }
        else
        {
            // -
        }

        int timeLeft = 10 * 30 - o->oTimer;
        if (!isOnCheckpoint && (timeLeft < 0 || (gPlayer1Controller->buttonPressed & L_TRIG) || (gMarioStates->pos[1] < -1500.f)))
        {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0, 0, 0);
            o->oAction = 1;
        }
        else
        {
            int f = 3 * (timeLeft % 30);
            int s = (timeLeft / 30) % 60;
            
            print_text_fmt_int(120, 20, "%02d", s);
            print_text_fmt_int(150, 20, "%02d", f);
        }
    }
    else
    {
        if (11 == o->oTimer)
        {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0, 0, 0);
            gMarioStates->pos[0] = sDfPositions[o->oDfLastCheckpoint][0];
            gMarioStates->pos[1] = sDfPositions[o->oDfLastCheckpoint][1];
            gMarioStates->pos[2] = sDfPositions[o->oDfLastCheckpoint][2];
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
            o->oAction = 0;
        }
    }
}

void df_arrow_loop()
{
    f32 d;
    struct Object* star = cur_obj_find_nearest_object_with_behavior(bhvHiddenRedCoinStar, &d);
    if (star)
    {
        star->oPosX = gMarioStates->pos[0];
        star->oPosY = gMarioStates->pos[1];
        star->oPosZ = gMarioStates->pos[2];
    }

    star = cur_obj_find_nearest_object_with_behavior(bhvStar, &d);
    if (star)
    {
        star->oPosX = gMarioStates->pos[0];
        star->oPosY = gMarioStates->pos[1];
        star->oPosZ = gMarioStates->pos[2];
    }

    obj_scale(o, 0.3f);
    struct Object* red = cur_obj_find_nearest_object_with_behavior_y_biased(bhvRedCoin);
    if (!red)
    {
        cur_obj_hide();
        return;
    }

    struct Surface* floor = gMarioStates->floor;
    int type = floor ? floor->type : 0;
    int isOnCheckpoint = type == SURFACE_HARD || type == SURFACE_HARD_NOT_SLIPPERY || type == SURFACE_NOISE_DEFAULT;

    if (isOnCheckpoint && (gPlayer1Controller->buttonPressed & 32))
    {
        if (obj_is_hidden(o))
        {
            cur_obj_unhide();
        }
        else
        {
            cur_obj_hide();
        }
    }
    
    o->oPosX = gMarioStates->pos[0];
    o->oPosY = gMarioStates->pos[1] + 150.f;
    o->oPosZ = gMarioStates->pos[2];

    f32 dx = o->oPosX - red->oPosX;
    f32 dy = o->oPosY - red->oPosY;
    f32 dz = o->oPosZ - red->oPosZ;
    f32 l = sqrtf(dx*dx + dz*dz);

    s16 yaw = atan2s(dz, dx) + 0x8000;
    s16 pitch = atan2s(l, dy);
    o->oFaceAngleYaw = yaw;
    o->oPosX += sins(yaw) * 80.f;
    o->oPosZ += coss(yaw) * 80.f;
    o->oFaceAnglePitch = pitch;
}
