extern const Trajectory crash_area_1_spline_curve1[];
extern const Trajectory crash_area_1_spline_move1[];
extern const Trajectory crash_area_1_spline_move2[];
extern const Trajectory crash_area_1_spline_move3[];

static const Trajectory* sCrashTrajectories[] =
{
    crash_area_1_spline_move1,
    crash_area_1_spline_move2,
    crash_area_1_spline_move3,
};

static void crash_zipline_reset()
{
    struct Waypoint* path = segmented_to_virtual(crash_area_1_spline_curve1);
    o->oPosX = path->pos[0];
    o->oPosY = path->pos[1];
    o->oPosZ = path->pos[2];
    o->oPathedPrevWaypointFlags = 0;
    o->oPathedStartWaypoint = o->oPathedPrevWaypoint = path;
}

struct WaypointCtx
{
    s32 prevFlags;
    struct Waypoint* start;
    struct Waypoint* prev;
    f32 x;
    f32 y;
    f32 z;
};

static void crash_shellline_reset()
{
    struct WaypointCtx* ctxs = (struct WaypointCtx*) aglabScratch;
    for(int i = 0; i < 3; i++)
    {
        struct Waypoint* path = segmented_to_virtual(sCrashTrajectories[i]);
        struct WaypointCtx* ctx = &ctxs[i];
        ctx->x = path->pos[0];
        ctx->y = path->pos[1];
        ctx->z = path->pos[2];
        ctx->prevFlags = 0;
        ctx->start = ctx->prev = path;
    }

    o->oCrashLinePosition = 0;
}

void crash_ctl_init()
{
#if 1
    crash_zipline_reset();
#else
    crash_shellline_reset();
    o->oAction = 4;
#endif
}

s32 approach_angle_asymptotic_bool(s32 current, s32 target, f32 multiplier) {
    if (multiplier > 1.0f) multiplier = 1.0f;

    s32 dist = (s16)(target - current);
    return (current + dist * multiplier);
}

static s32 is_disallow_swim_state()
{
    if (gCamera->mode == 8 /*swimming*/)
    {
        return !gMarioStates->heldObj || gMarioStates->heldObj->behavior != segmented_to_virtual(bhvKoopaShellUnderwater);
    }
    else
    {
        return 0;
    }
}

void crash_ctl_loop()
{
    s32 floorType = gMarioStates->floor ? gMarioStates->floor->type : 0;
    if (!o->oCrashCheckpointActive)
    {
        if ((gMarioStates->pos[1] < 0.f)
         && (floorType == SURFACE_VERY_SLIPPERY)
         && (gMarioStates->floorHeight == gMarioStates->pos[1]))
        {
            o->oCrashCheckpointActive = 1;
        }
    }

    if (o->oAction != 3 && (is_disallow_swim_state() 
     || gMarioStates->action == ACT_BURNING_FALL
     || gMarioStates->action == ACT_BURNING_GROUND
     || gMarioStates->action == ACT_BURNING_JUMP
     || (floorType == SURFACE_SHALLOW_QUICKSAND && gMarioStates->floorHeight == gMarioStates->pos[1])))
    {
        play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 10, 0,0,0);
        if (1 == o->oAction)
        {
            struct Object** bullets = (struct Object**) aglabScratch;
            for (int i = 0; i < 5; i++)
            {
                bullets[i]->activeFlags = 0;
            }
        }

        o->oAction = 3;
        return;
    }

    {
        f32 d;
        struct Object* shell = cur_obj_find_nearest_object_with_behavior(bhvKoopaShellUnderwater, &d);
        if (!shell)
        {
            shell = spawn_object(o, MODEL_KOOPA_SHELL, bhvKoopaShellUnderwater);
        }
        shell->oPosX = -19355.f;
        shell->oPosY =  11877.f;
        shell->oPosZ = -24474.f;
    }

    if (0 == o->oAction)
    {
        f32 dx =  -5919.f - gMarioStates->pos[0];
        f32 dy =   5797.f - gMarioStates->pos[1];
        f32 dz = -13664.f - gMarioStates->pos[2];
        f32 d = sqrtf(dx*dx + dy*dy + dz*dz);
        if (d < 1000.f)
        {
            o->oAction = 1;
            struct Object** bullets = (struct Object**) aglabScratch;
            for (int i = 0; i < 5; i++)
            {
                bullets[i] = spawn_object(o, MODEL_BOWLING_BALL, bhvStaticObjectBillboardEx);
                bullets[i]->oPosX = 0;
                bullets[i]->oPosY = 0;
                bullets[i]->oPosZ = 0;
                obj_scale(bullets[i], 0.1f);
            }
        }

        struct Object* sparkle = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        sparkle->oPosX = -5919.f;
        sparkle->oPosY = 5797.f;
        sparkle->oPosZ = -13664.f;
    }
    else if (1 == o->oAction)
    {
        if (1 == o->oTimer)
        {
            set_camera_mode(gCamera, gCamera->defMode, 1);
            reset_camera(gCamera);
        }

        if (o->oPathedPrevWaypointFlags == 0) {
            o->oPathedPrevWaypoint = o->oPathedStartWaypoint;
            o->oPathedPrevWaypointFlags = WAYPOINT_FLAGS_INITIALIZED;
        }

        struct Waypoint *startWaypoint = o->oPathedStartWaypoint;
        struct Waypoint *lastWaypoint = o->oPathedPrevWaypoint;
        struct Waypoint *targetWaypoint;
        struct Waypoint *nextWaypoint = NULL;
        Vec3s prevToNext, objToNext, prevToNew, nextToNew;

        if ((lastWaypoint + 1)->flags != WAYPOINT_FLAGS_END) {
            targetWaypoint = lastWaypoint + 1;
            if ((lastWaypoint + 2)->flags != WAYPOINT_FLAGS_END)
            {
                nextWaypoint = lastWaypoint + 2;
            }
        } else {
            targetWaypoint = startWaypoint;
        }

        o->oPathedPrevWaypointFlags = lastWaypoint->flags | WAYPOINT_FLAGS_INITIALIZED;

        if (nextWaypoint)
            vec3_diff(nextToNew, nextWaypoint->pos, targetWaypoint->pos);
    
        vec3_diff(prevToNext, targetWaypoint->pos, lastWaypoint->pos);
        vec3_diff(objToNext, targetWaypoint->pos, &o->oPosVec);

        f32 spd = (50 + o->oTimer) * 0.2f;
        f32 curLen = sqrtf(objToNext[0] * objToNext[0] + objToNext[1] * objToNext[1] + objToNext[2] * objToNext[2]);
        f32 len = curLen / spd;
        if (len > 0.001f)
        {
            objToNext[0] /= len;
            objToNext[1] /= len;
            objToNext[2] /= len;
        }
        
        // If dot(prevToNext, objToNext) <= 0 (i.e. reached other side of target waypoint)
        if (vec3_dot(prevToNext, objToNext) <= 0.0f) {
            o->oPathedPrevWaypoint = targetWaypoint;
            if ((targetWaypoint + 1)->flags == WAYPOINT_FLAGS_END) {
                struct Object** bullets = (struct Object**) aglabScratch;
                for (int i = 0; i < 5; i++)
                {
                    bullets[i]->activeFlags = 0;
                }
                o->oAction = 2;
                gMarioStates->forwardVel = 30.f;
                return;
            }
        }
        else
        {
            gMarioStates->faceAngle[1] = atan2s(objToNext[2], objToNext[0]);
        }

        o->oPosX += objToNext[0];
        o->oPosY += objToNext[1];
        o->oPosZ += objToNext[2];

        vec3_diff(prevToNew, targetWaypoint->pos, &o->oPosVec);
        f32 newlen = sqrtf(prevToNew[0] * prevToNew[0] + prevToNew[1] * prevToNew[1] + prevToNew[2] * prevToNew[2]);
        f32 abslen = sqrtf(prevToNext[0] * prevToNext[0] + prevToNext[1] * prevToNext[1] + prevToNext[2] * prevToNext[2]);

        f32 pathratio = newlen / abslen;

        f32 antiLen = sqrtf(objToNext[0]*objToNext[0] + objToNext[2]*objToNext[2]);
        Vec3f anti = { -objToNext[2] / antiLen, 0, objToNext[0] / antiLen };

        if (nextWaypoint)
        {
            f32 antiNextLen = sqrtf(nextToNew[0]*nextToNew[0] + nextToNew[2]*nextToNew[2]);
            Vec3f antiNext = { -nextToNew[2] / antiNextLen, 0, nextToNew[0] / antiNextLen };

            anti[0] = anti[0] * pathratio + antiNext[0] * (1 - pathratio);
            anti[2] = anti[2] * pathratio + antiNext[2] * (1 - pathratio);

            f32 antiLen = sqrtf(anti[0]*anti[0] + anti[2]*anti[2]);
            anti[0] /= antiLen;
            anti[2] /= antiLen;
        }

        s16 controlStickAngle = 0;
        if (gPlayer1Controller->stickMag > 30.f)
        {
            f32 x = gPlayer1Controller->stickX / gPlayer1Controller->stickMag;
            f32 y = gPlayer1Controller->stickY / gPlayer1Controller->stickMag;
            controlStickAngle = atan2s(y, x);
            
            o->oCrashLineAngle = approach_angle_asymptotic_bool(o->oCrashLineAngle, controlStickAngle, 0.1f);
        }

        gMarioObject->header.gfx.angle[2] = o->oCrashLineAngle;
        if (gMarioStates->action != ACT_DIVE && gMarioStates->action != ACT_BURNING_FALL)
        {
            set_mario_action(gMarioStates, ACT_DIVE, 0);
        }

        f32 d = 500.f * (o->oTimer > 30 ? 30 : o->oTimer) / 30.f;
        gMarioStates->pos[0] = o->oPosX + sins(o->oCrashLineAngle) * anti[0] * d;
        gMarioStates->pos[1] = o->oPosY + coss(o->oCrashLineAngle)           * d - d / 10.f;
        gMarioStates->pos[2] = o->oPosZ + sins(o->oCrashLineAngle) * anti[2] * d;

        struct Object** bullets = (struct Object**) aglabScratch;
        for (int i = 0; i < 5; i++)
        {
            bullets[i]->oPosX = o->oPosX + sins(o->oCrashLineAngle) * anti[0] * d * (i + 1) / 6.f;
            bullets[i]->oPosY = o->oPosY + coss(o->oCrashLineAngle)           * d * (i + 1) / 6.f;
            bullets[i]->oPosZ = o->oPosZ + sins(o->oCrashLineAngle) * anti[2] * d * (i + 1) / 6.f;
        }
    }
    else if (2 == o->oAction)
    {
        if (0 == o->oTimer && !o->oCrashCheckpointActive)
        {
            crash_shellline_reset();
            gMarioStates->forwardVel = 50.f;
            gMarioStates->vel[1] = 0;
            gMarioStates->faceAngle[1] = 0;
            // -
        }
        
        f32 dx = -1550.f - gMarioStates->pos[0];
        f32 dy = -2805.f - gMarioStates->pos[1];
        f32 dz = -6052.f - gMarioStates->pos[2];
        f32 d = sqrtf(dx*dx + dy*dy + dz*dz);
        if (d < 1000.f)
        {
            o->oAction = 4;
            gMarioStates->interactObj = gMarioStates->heldObj;
            gMarioStates->usedObj = gMarioStates->heldObj;
            gMarioStates->riddenObj = gMarioStates->heldObj;
            gMarioStates->heldObj = NULL;
        }
        
        struct Object* sparkle = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        sparkle->oPosX = -1550.f;
        sparkle->oPosY = -2805.f;
        sparkle->oPosZ = -6052.f;
    }
    else if (3 == o->oAction)
    {
        if (o->oTimer == 12)
        {
            if (!o->oCrashCheckpointActive)
            {
                crash_zipline_reset();
                gMarioStates->pos[0] = -19608.f;
                gMarioStates->pos[1] = 12213.f;
                gMarioStates->pos[2] = -24734.f;
                gMarioStates->faceAngle[1] = 0x2000;
            }
            else
            {
                crash_shellline_reset();
                gMarioStates->pos[0] = -1608.f;
                gMarioStates->pos[1] = -1533.f;
                gMarioStates->pos[2] = -3137.f;
                gMarioStates->faceAngle[1] = 0x8000;
            }
            gMarioStates->vel[0] = 0;
            gMarioStates->vel[1] = 0;
            gMarioStates->vel[2] = 0;
            gMarioStates->forwardVel = 0;
            drop_and_set_mario_action(gMarioStates, ACT_FREEFALL, 0);
            set_camera_mode(gCamera, gCamera->defMode, 1);
            reset_camera(gCamera);
        }
        if (o->oTimer == 13)
        {
            reset_camera(gCamera);
        }
        if (o->oTimer == 14)
        {
            reset_camera(gCamera);
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 10, 0,0,0);
            o->oAction = 2 * o->oCrashCheckpointActive;
        }
    }
    else if (4 == o->oAction)
    {
        struct WaypointCtx* ctxs = (struct WaypointCtx*) aglabScratch;
        struct WaypointCtx* ctx = &ctxs[1];
        if (ctx->prevFlags == 0) {
            ctx->prev = ctx->start;
            ctx->prevFlags = WAYPOINT_FLAGS_INITIALIZED;
        }

        struct Waypoint *startWaypoint = ctx->start;
        struct Waypoint *lastWaypoint = ctx->prev;
        struct Waypoint *targetWaypoint;
        Vec3s prevToNext, objToNext, prevToNew;

        if ((lastWaypoint + 1)->flags != WAYPOINT_FLAGS_END) {
            targetWaypoint = lastWaypoint + 1;
        } else {
            targetWaypoint = startWaypoint;
        }

        ctx->prevFlags = lastWaypoint->flags | WAYPOINT_FLAGS_INITIALIZED;

        vec3_diff(prevToNext, targetWaypoint->pos, lastWaypoint->pos);
        vec3_diff(objToNext, targetWaypoint->pos, &ctx->x);

        f32 spd = (100 + o->oTimer) * ((0 == o->oCrashLinePosition) ? 0.12f : 0.09f);
        f32 len = sqrtf(objToNext[0] * objToNext[0] + objToNext[1] * objToNext[1] + objToNext[2] * objToNext[2]) / spd;
        if (len > 0.001f)
        {
            objToNext[0] /= len;
            objToNext[1] /= len;
            objToNext[2] /= len;
        }
        
        // If dot(prevToNext, objToNext) <= 0 (i.e. reached other side of target waypoint)
        s32 switchPoints = 0;
        if (vec3_dot(prevToNext, objToNext) <= 0.0f) {
            switchPoints = 1;
            ctx->x = targetWaypoint->pos[0];
            ctx->y = targetWaypoint->pos[1];
            ctx->z = targetWaypoint->pos[2];

            ctx->prev = targetWaypoint;
            if ((targetWaypoint + 1)->flags == WAYPOINT_FLAGS_END) {
                o->oAction = 5;
                gMarioStates->forwardVel = 30.f;
            }
        }
        else
        {
            ctx->x += objToNext[0];
            ctx->y += objToNext[1];
            ctx->z += objToNext[2];
            s32 targetAngle = atan2s(objToNext[2], objToNext[0]);
            gMarioStates->faceAngle[1] = targetAngle;
        }

        vec3_diff(prevToNew, targetWaypoint->pos, &ctx->x);
        f32 newlen = sqrtf(prevToNew[0] * prevToNew[0] + prevToNew[1] * prevToNew[1] + prevToNew[2] * prevToNew[2]);
        f32 abslen = sqrtf(prevToNext[0] * prevToNext[0] + prevToNext[1] * prevToNext[1] + prevToNext[2] * prevToNext[2]);

        f32 pathratio = newlen / abslen;

        // all paths are following the 1st path
        for (int i = 0; i < 3; i++)
        {
            if (1 == i)
                continue;

            struct WaypointCtx* ctx = &ctxs[i];
            if (ctx->prevFlags == 0) {
                ctx->prev = ctx->start;
                ctx->prevFlags = WAYPOINT_FLAGS_INITIALIZED;
            }

            struct Waypoint *startWaypoint = ctx->start;
            struct Waypoint *lastWaypoint = ctx->prev;
            struct Waypoint *targetWaypoint;
            Vec3s prevToNext;

            if ((lastWaypoint + 1)->flags != WAYPOINT_FLAGS_END) {
                targetWaypoint = lastWaypoint + 1;
            } else {
                targetWaypoint = startWaypoint;
            }

            ctx->prevFlags = lastWaypoint->flags | WAYPOINT_FLAGS_INITIALIZED;

            vec3_diff(prevToNext, targetWaypoint->pos, lastWaypoint->pos);
            if (switchPoints) {
                ctx->x = targetWaypoint->pos[0];
                ctx->y = targetWaypoint->pos[1];
                ctx->z = targetWaypoint->pos[2];

                ctx->prev = targetWaypoint;
                if ((targetWaypoint + 1)->flags == WAYPOINT_FLAGS_END) {
                    o->oAction = 5;
                    gMarioStates->forwardVel = 30.f;
                }
            }
            else
            {
                ctx->x = targetWaypoint->pos[0] - prevToNext[0] * pathratio;
                ctx->y = targetWaypoint->pos[1] - prevToNext[1] * pathratio;
                ctx->z = targetWaypoint->pos[2] - prevToNext[2] * pathratio;
            }
        }
    
        if (gMarioStates->action != ACT_RIDING_SHELL_GROUND 
         && gMarioStates->action != ACT_BURNING_FALL
         && gMarioStates->action != ACT_BURNING_JUMP
         && gMarioStates->action != ACT_BURNING_GROUND)
            set_mario_action(gMarioStates, ACT_RIDING_SHELL_GROUND, 0);

        if (0 == (o->oCrashLinePosition % 100))
        {
            if ((gPlayer1Controller->stickX < -40.f) && (gPlayer1Controller->buttonPressed & A_BUTTON) && (-100 != o->oCrashLinePosition))
            {
                o->oCrashLineDirection = -10;
                o->oCrashLinePosition -= 10;
            }
            if ((gPlayer1Controller->stickX >  40.f) && (gPlayer1Controller->buttonPressed & A_BUTTON) && (100 != o->oCrashLinePosition))
            {
                o->oCrashLineDirection = 10;
                o->oCrashLinePosition += 10;
            }
        }
        else
        {
            o->oCrashLinePosition += o->oCrashLineDirection;
        }
        
        // all coordinates are calculated, we might want to interpolate stuff
        s32 posabs = o->oCrashLinePosition > 0 ? o->oCrashLinePosition : -o->oCrashLinePosition;
        f32 posnorm = o->oCrashLinePosition / 100.f;
        if (o->oCrashLinePosition < 0)
        {
            gMarioStates->pos[0] = ctxs[1].x * (1.f + posnorm) + (ctxs[0].x) * (-posnorm);
            gMarioStates->pos[1] = ctxs[1].y * (1.f + posnorm) + (ctxs[0].y) * (-posnorm) + posabs*(100-posabs)*0.05f;
            gMarioStates->pos[2] = ctxs[1].z * (1.f + posnorm) + (ctxs[0].z) * (-posnorm);
        }
        else
        {
            gMarioStates->pos[0] = ctxs[1].x * (1.f - posnorm) + (ctxs[2].x) * (posnorm);
            gMarioStates->pos[1] = ctxs[1].y * (1.f - posnorm) + (ctxs[2].y) * (posnorm) + posabs*(100-posabs)*0.05f;
            gMarioStates->pos[2] = ctxs[1].z * (1.f - posnorm) + (ctxs[2].z) * (posnorm);
        }
    }
    else if (5 == o->oAction)
    {
        // -
    }
}

struct ObjectHitbox sCrashBowserFlameHitbox = {
    /* interactType:      */ INTERACT_FLAME,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 1,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 20,
    /* height:            */ 40,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

void crash_flame_init()
{
    obj_set_hitbox(o, &sCrashBowserFlameHitbox);
    obj_scale(o, 14.f);
}

void crash_flame_loop()
{
    // -
}

void crash_flame_element_init()
{
    obj_set_hitbox(o, &sCrashBowserFlameHitbox);
    obj_scale(o, 14.f);
}

void crash_flame_element_loop()
{
    if (1 == o->oBehParams2ndByte)
    {
        o->oCrashFlameRotation += 0x169;
        o->oPosX = o->oHomeX + 500.f * sins(o->oCrashFlameRotation) * sins(o->oFaceAngleYaw);
        o->oPosY = o->oHomeY + 500.f * coss(o->oCrashFlameRotation);
        o->oPosZ = o->oHomeZ + 500.f * sins(o->oCrashFlameRotation) * coss(o->oFaceAngleYaw);
    }
}

void crash_flame_spawner_init()
{
    s16 angleSpawn = 2 == o->oBehParams2ndByte ? 0x1000 : random_u16(); 
    int cnt = 2 == o->oBehParams2ndByte ? 10 : 8;
    for (int i = 0; i < cnt; i++)
    {
        angleSpawn += 0x1500;
        struct Object* flame = spawn_object(o, MODEL_BLUE_FLAME, bhvCrashFlameElement);
        flame->oHomeX = o->oPosX;
        flame->oHomeY = o->oPosY;
        flame->oHomeZ = o->oPosZ;
        flame->oPosX = flame->oHomeX + 500.f * sins(angleSpawn) * sins(o->oFaceAngleYaw);
        flame->oPosY = flame->oHomeY + 500.f * coss(angleSpawn);
        flame->oPosZ = flame->oHomeZ + 500.f * sins(angleSpawn) * coss(o->oFaceAngleYaw);
        flame->oBehParams2ndByte = o->oBehParams2ndByte;
        flame->oCrashFlameRotation = angleSpawn;
        flame->oFaceAngleYaw = o->oFaceAngleYaw;
    }
}

void crash_flame_spawner_loop()
{
    // -
}

void crash_spinner_init()
{
    
}

void crash_spinner_loop()
{
    if (0 == o->oBehParams2ndByte)
    {
        o->oPosY = o->oHomeY + 200.f * sins(o->oTimer * 0x354);
    }
    else if (1 == o->oBehParams2ndByte)
    {
        o->oPosX = o->oHomeX + 300.f * sins(o->oTimer * 0x354);
        o->oPosZ = o->oHomeZ + 300.f * coss(o->oTimer * 0x354);
    }
}

void bhv_crash_shell_mover_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvCrashCtl, &d);
}

void bhv_crash_shell_mover_loop()
{
    if (o->parentObj->oAction >= 4)
    {
        o->oPosX = gMarioObject->oPosX;
        o->oPosY = gMarioObject->oPosY;
        o->oPosZ = gMarioObject->oPosZ;
        o->oFaceAngleYaw = gMarioObject->oFaceAngleYaw;
        cur_obj_enable_rendering();
    }
    else
    {
        cur_obj_disable_rendering();
    }
}
