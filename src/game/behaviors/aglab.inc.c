#include "seq_ids.h"
#include "audio/external.h"

extern int gTriggerHell;

extern Vtx fireball_fireball_001_mesh_layer_5_vtx_0[];
extern Vtx fireball_fireball_mesh_layer_1_vtx_0[];

static void Alter(Vtx* v, short offX, short offY, short offZ)
{
    v->n.ob[0] += offX;
    v->n.ob[1] += offY;
    v->n.ob[2] += offZ;
}

static char randoms[] = {
    9, -1, 6, -8, 3, -2, 7, 6, -6, -4, -7, 4, -6, 1, -6, 3, -6, 0, 
    -4, 1, 7, 5, 0, 7, 9, -7, -2, 1, -10, 0, 2, 6, 5, -5, -4, 5, 6, 
    -7, -8, 8, 3, 1, -4, 2, -2, -9, -10, -2, -5, 5, 3, 9, 7, 6, 5, 3, 
    -8, 2, 2, 4, -6, -6, 9, 4, -6, -9, 1, -3, 3, -5, -9, 6, 8, 7, -4, 
    -3, -9, 5, -4, -3, 3, 1, 0, -2, -10, -5, -10, -9, 7, -1, -8, -7, 
    3, 5, 8, 7, 8, 5, 6, 3,
};

static void shakeVertices()
{
#define COUNT 26
    static char bparam1 = 4;
    static char bparam2 = 37;
    static char bparam3 = 72;
    bparam1++; bparam1 %= 100;
    bparam2++; bparam2 %= 100;
    bparam3++; bparam3 %= 100;

    char wasAltered[COUNT] = {};

    Vtx* vertices = segmented_to_virtual(fireball_fireball_001_mesh_layer_5_vtx_0);
    for (int i = 0; i < COUNT; i++)
    {
        if (wasAltered[i])
            continue;
        wasAltered[i] = 1;

        Vtx* baseVertex = &vertices[i];
        short offX = 5 * randoms[bparam1];
        short offY = 5 * randoms[bparam2];
        short offZ = 5 * randoms[bparam3];

        for (int j = i + 1; j < COUNT; j++)
        {
            if (wasAltered[j])
                continue;

            Vtx* sameVertex = &vertices[j];
            if (sameVertex->n.ob[0] == baseVertex->n.ob[0] 
             && sameVertex->n.ob[1] == baseVertex->n.ob[1] 
             && sameVertex->n.ob[2] == baseVertex->n.ob[2])
             {
                Alter(sameVertex, offX, offY, offZ);
                wasAltered[j] = 1;
             }
        }
        Alter(baseVertex, offX, offY, offZ);
    }
}

void scroll_fireball5_vtx() {
	int i = 0;
	int count = 26;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(fireball_fireball_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.3f * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaX;
	}
	currentX += deltaX;
}

void scroll_fireball1_vtx() {
	int i = 0;
	int count = 22;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(fireball_fireball_mesh_layer_1_vtx_0);

	deltaX = (int)(0.3f * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaX;
	}
	currentX += deltaX;
}

extern const BehaviorScript bhvDeathFireballCore[];
void bhv_death_fireball_init()
{
    gCurrentObject->oFieldCtlStar0 = spawn_object(gCurrentObject, MODEL_CORE, bhvDeathFireballCore);
    gCurrentObject->oDrawingDistance = 50000.f;
}

void bhv_death_fireball_loop()
{
    // move to Y with vel 20
    // move to X/Z with vel 10

    // to: 28, -385, 5090 

    gCurrentObject->oFieldCtlStar0->oPosX = gCurrentObject->oPosX + 200.f;
    gCurrentObject->oFieldCtlStar0->oPosY = gCurrentObject->oPosY + 200.f;
    gCurrentObject->oFieldCtlStar0->oPosZ = gCurrentObject->oPosZ - 400.f;

    if (!gTriggerHell)
        return;
    
    scroll_fireball1_vtx();
    scroll_fireball5_vtx();
    shakeVertices();

    // 320 is total time
    if (!gCurrentObject->oAction)
    {
        gCurrentObject->oAction = 1;
        gCurrentObject->oTimer = 0;
    }

    gCurrentObject->oPosX = 28   + (220 - gCurrentObject->oTimer) * 10;
    gCurrentObject->oPosY = -385 + (220 - gCurrentObject->oTimer) * 10;
    gCurrentObject->oPosZ = 5090 + (220 - gCurrentObject->oTimer) * -20;

    if (gCurrentObject->oTimer < 100)
    {
        cur_obj_scale(0);
    }
    else if (gCurrentObject->oTimer < 140)
    {
        if ((gCurrentObject->oTimer % 10) == 0)
            create_sound_spawner(SOUND_AIR_BOWSER_SPIT_FIRE);
        cur_obj_scale((gCurrentObject->oTimer - 100) * (1.f / 40));
    }
    else if (gCurrentObject->oTimer < 200)
    {
        obj_scale_xyz(gCurrentObject->oFieldCtlStar0, 0, 0, 0);
        cur_obj_shake_screen(2);
        if ((gCurrentObject->oTimer % 10) == 0)
            create_sound_spawner(SOUND_AIR_BOWSER_SPIT_FIRE);
        cur_obj_scale(1.f + sins(gCurrentObject->oTimer * 2370) * 0.04f);
    }
    else if (gCurrentObject->oTimer < 250)
    {
        cur_obj_play_sound_1(SOUND_AIR_BLOW_FIRE);
        int left = (gCurrentObject->oTimer - 200) * (gCurrentObject->oTimer - 200);
        int leftMax = 2500;
        int diffW = 3000 - 2370;
        float diffA = 0.3f - 0.04f;
        cur_obj_scale(1.f + sins(gCurrentObject->oTimer * (2370 + diffW * left / leftMax)) * (0.04f + diffA * left / leftMax));
    }
    else
    {
        if (gCurrentObject->oTimer == 250)
            create_sound_spawner(SOUND_GENERAL_BOWSER_BOMB_EXPLOSION);
    
        cur_obj_scale(1.f + (gCurrentObject->oTimer - 250) * 0.15f);
    }

    // trap mario inside the cube
    if (gMarioStates->pos[2] > 5400.f)
        gMarioStates->pos[2] = 5400.f;
            
    if (gMarioStates->pos[0] < -1000.f)
        gMarioStates->pos[0] = -1000.f;
    if (gMarioStates->pos[0] > 500.f)
        gMarioStates->pos[0] = 500.f;

    if (gCurrentObject->oTimer == 250)
    {
        level_trigger_warp(gMarioStates, 1 /*WARP_OP_LOOK_UP*/);
    }
}

static void killPrimColor(Gfx* gfx, int off, int spd)
{
    u8* b = segmented_to_virtual(gfx);
    u8* p = &b[8 * off + 7];
    u8 v = *p;
    if (v < spd)
    {
        v = 0;
    }
    else
    {
        v -= spd;
    }

    *p = v;
}

extern Gfx mat_sa_dl__9_f3d[]; // +18
extern Gfx mat_sa_dl__10_f3d[]; // +18
extern Gfx mat_sa_dl__11_f3d[]; // +18
static void killCake()
{
    killPrimColor(mat_sa_dl__9_f3d, 18, 10);
    killPrimColor(mat_sa_dl__10_f3d, 18, 10);
    killPrimColor(mat_sa_dl__11_f3d, 18, 10);
}

extern Gfx mat_sa_dl__7_f3d_layer5_area1[]; // +23
extern Gfx mat_sa_dl__4_f3d_layer5_area1[]; // +16
extern Gfx mat_sa_dl__5_f3d_layer5_area1[]; // +16
extern Gfx mat_sa_dl__6_f3d_layer5_area1[]; // +16
extern Gfx mat_sa_dl__12_f3d_layer5_area1[]; // +23
extern Gfx mat_sa_dl__13_f3d_layer5_area1[]; // +24

extern Gfx mat_sa_dl_Color_M08_f3d[];
extern Gfx mat_sa_dl_FrontColor_f3d[];
static void killCourse()
{
    killPrimColor(mat_sa_dl__7_f3d_layer5_area1, 23, 5);
    killPrimColor(mat_sa_dl__4_f3d_layer5_area1, 16, 5);
    killPrimColor(mat_sa_dl__5_f3d_layer5_area1, 16, 5);
    killPrimColor(mat_sa_dl__6_f3d_layer5_area1, 16, 5);
    killPrimColor(mat_sa_dl__12_f3d_layer5_area1, 23, 5);
    killPrimColor(mat_sa_dl__13_f3d_layer5_area1, 24, 5);
    
    killPrimColor(mat_sa_dl_Color_M08_f3d, 3, 2);
    killPrimColor(mat_sa_dl_FrontColor_f3d, 3, 5);
}

extern f32 absf(f32 x);
static void limitMarioMovementForCtl(f32 x, f32 z, f32 max)
{
    if (x + max < gMarioStates->pos[0])
        gMarioStates->pos[0] = x + max;
    if (x - max > gMarioStates->pos[0])
        gMarioStates->pos[0] = x - max;
        
    if (z + max < gMarioStates->pos[2])
        gMarioStates->pos[2] = z + max;
    if (z - max > gMarioStates->pos[2])
        gMarioStates->pos[2] = z - max;
}

static void find_all_spawner_stars(const BehaviorScript *behavior) {
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    struct Object** objInObj = &gCurrentObject->oFieldCtlStar0;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->oPosY > 100.f) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                *objInObj = obj;
                objInObj++;
            }
        }
        obj = (struct Object *) obj->header.next;
    }
}

static void raise_all_switches(const BehaviorScript *behavior)
{
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    int cnt = 0;
    int cnt2 = 0;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->oPosY < 0.f) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                obj->oPosY += 10.f;
            }
        }
        obj = (struct Object *) obj->header.next;
    }
}

static void raise_all_troll_stars_for(const BehaviorScript *behavior, int dcenter)
{
    uintptr_t *behaviorAddr = segmented_to_virtual(behavior);
    struct Object *closestObj = NULL;
    struct Object *obj;
    struct ObjectNode *listHead;
    int cnt = 0;
    int cnt2 = 0;

    listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    obj = (struct Object *) listHead->next;

    while (obj != (struct Object *) listHead) {
        if (obj->behavior == behaviorAddr && obj->oPosY < 100.f) {
            if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                cnt2++;
                int need = 1;           
                if (dcenter == 0)
                {
                    need = absf(obj->oPosX) > 400.f || (obj->oPosZ == 0 && obj->oPosX == 0); 
                }
                else if (dcenter == 1)
                {
                    need = absf(obj->oPosX) < 50.f;
                }
                else if (dcenter == 2)
                {
                    need = absf(obj->oPosX) < 400.f; 
                }                

                if (need)
                {
                    obj->oFaceAngleRoll = 0x8000;
                    obj->oPosY += 10.f;
                    cnt++;
                }
            }
        }
        obj = (struct Object *) obj->header.next;
    }
    
    //print_text_fmt_int(20, 20, "%d", cnt);
    //print_text_fmt_int(20, 40, "%d", cnt2);
}

static int sFightRetries = 0;
static int sSavedRetries = 0;
extern const BehaviorScript bhvStar[];
void bhv_fight_init()
{
    sFightRetries++;
    gCurrentObject->oHealth = 10;
    find_all_spawner_stars(bhvStar);
}

extern const BehaviorScript bhvStarMoving[];
void spawn_attack_stars()
{
    cur_obj_play_sound_2(SOUND_OBJ_SNUFIT_SHOOT);
    struct Object** spawners = &gCurrentObject->oFieldCtlStar0;
    for (int i = 0; i < 4; i++)
    {
        struct Object* spawner = spawners[i];
        struct Object* n = spawn_object(spawner, MODEL_STAR, bhvStarMoving);
        u16 angle = random_u16();
        f32 spd = 5.f;
        f32 accel = 0.07;
        n->oVelX = sins(angle) * spd;
        n->oVelY = 0;
        n->oVelZ = coss(angle) * spd;
        n->oVelAccelX = sins(angle) * accel;
        n->oVelAccelZ = coss(angle) * accel;
        if (gCurrentObject->oHealth <= 1)
        {
            n->oFaceAngleRoll = random_u16();
        }

        if (n->oPosX < 0)
        {
            n->oVelX = absf(n->oVelX);
            n->oVelAccelX = absf(n->oVelAccelX);
        }
        if (n->oPosX > 0)
        {
            n->oVelX = -absf(n->oVelX);
            n->oVelAccelX = -absf(n->oVelAccelX);
        }
    }
}

extern s16 atan2s(f32 y, f32 x);
void spawn_homing()
{    struct Object** spawners = &gCurrentObject->oFieldCtlStar0;
    for (int i = 0; i < 4; i++)
    {
        struct Object* spawner = spawners[i];
        struct Object* n = spawn_object(spawner, MODEL_TRANSPARENT_STAR, bhvStarMoving);
        u16 angle = atan2s(spawner->oPosZ - gMarioStates->pos[2], spawner->oPosX - gMarioStates->pos[0]);
        f32 spd = -10.f;
        f32 accel = -0.07;
        n->oVelX = sins(angle) * spd;
        n->oVelY = 0;
        n->oVelZ = coss(angle) * spd;
        n->oVelAccelX = sins(angle) * accel;
        n->oVelAccelZ = coss(angle) * accel;
        n->oFaceAnglePitch = 0x4000;
    }
}

extern f32 gGlobalSoundSource[];
void bhv_fight_loop()
{
    if (0 == gCurrentObject->oAction)
    {
        load_object_collision_model();
        if (gCurrentObject->oDistanceToMario < 250.f)
        {
            gCurrentObject->oAction = 1;
        }
    }
    else if (1 == gCurrentObject->oAction)
    {
        if (gCurrentObject->oTimer == 0)
            play_sound(SOUND_MENU_BOWSER_LAUGH, gGlobalSoundSource);
    
        // no more collision for any oAction past 0
        killCake();
        limitMarioMovementForCtl(gCurrentObject->oPosX, gCurrentObject->oPosZ, 180.f);
    
        if (gCurrentObject->oTimer == 30)
        {
            gCurrentObject->oAction = 2;
        }
    }
    else if (2 == gCurrentObject->oAction)
    {
        killCourse();
        raise_all_switches(bhvFightFloorSwitch);    
        if (gCurrentObject->oTimer < 20)
            limitMarioMovementForCtl(gCurrentObject->oPosX, gCurrentObject->oPosZ, 180.f);
        if (gCurrentObject->oTimer == 55)
        {
            gCurrentObject->oAction = 3;
        }
    }
    else if (3 == gCurrentObject->oAction)
    {
        if (gCurrentObject->oTimer == 0)
            play_music(0, SEQUENCE_ARGS(4, SEQ_LEVEL_HOT), 0);
    
        if (gCurrentObject->oHealth >= 0)
            print_text_fmt_int(145, 220, "%d", gCurrentObject->oHealth);

        // on first hit we dont shoot
        if (gCurrentObject->oHealth < 10)
        {
            // star spawning the attacks from the stars
            struct Object** spawners = &gCurrentObject->oFieldCtlStar0;
            for (int i = 0; i < 4; i++)
            {
                struct Object* spawner = spawners[i];
                f32 scale = 1.f + (gCurrentObject->oTimer % 40) * 0.047f;
                obj_scale_xyz(spawner, scale, scale, scale);
            }
            // nerfing with more attempts
            if (0 == sFightRetries)
            {
                if (gCurrentObject->oHealth > 3)
                {
                    if (!(gCurrentObject->oTimer % 30))
                        spawn_attack_stars();
                }
                else
                {
                    if (!(gCurrentObject->oTimer % 40))
                        spawn_attack_stars();
                }

                if (!(gCurrentObject->oTimer % 150))
                    spawn_homing();
            }
            else if (sFightRetries > 2)
            {
                if (gCurrentObject->oHealth > 3 && sFightRetries == 3)
                {
                    if (!(gCurrentObject->oTimer % 60))
                        spawn_attack_stars();
                }
                else
                {
                    if (!(gCurrentObject->oTimer % 75))
                        spawn_attack_stars();
                }
            }
            else
            {
                // 1, 2 or 3 attempts
                if (gCurrentObject->oHealth > 3 && sFightRetries == 1)
                {
                    if (!(gCurrentObject->oTimer % 40))
                        spawn_attack_stars();
                }
                else
                {
                    if (!(gCurrentObject->oTimer % 60))
                        spawn_attack_stars();
                }
            }
        }
        else
        {
            if (sFightRetries)
                print_text_fmt_int(20, 20, "ATTEMPT %d", sFightRetries);
            else 
                print_text_fmt_int(20, 20, "GAMER MODE", sFightRetries);

            if (gPlayer1Controller->buttonPressed & L_TRIG)
            {
                if (sFightRetries)
                {
                    sSavedRetries = sFightRetries;
                    sFightRetries = 0;
                }
                else
                {
                    sFightRetries = sSavedRetries;
                }
            }
        }

        if (gCurrentObject->oHealth == 7)
        {
            raise_all_troll_stars_for(bhvStar, 0);
        }
        else if (gCurrentObject->oHealth == 5)
        {
            raise_all_troll_stars_for(bhvStar, 1);
        }
        else if (gCurrentObject->oHealth == 3)
        {
            raise_all_troll_stars_for(bhvStar, 2);
        }
        else if (gCurrentObject->oHealth <= 0)
        {
            if (0 != sFightRetries || gCurrentObject->oHealth < 0)
                level_trigger_warp(gMarioStates, 1 /*WARP_OP_LOOK_UP*/);
        }
    }
}

void bhv_moving_star_init()
{
    gCurrentObject->oBehParams = 0x10101010;
}

void bhv_moving_star()
{
    gCurrentObject->oVelX += gCurrentObject->oVelAccelX;
    gCurrentObject->oVelZ += gCurrentObject->oVelAccelZ;
    gCurrentObject->oPosX += gCurrentObject->oVelX;
    gCurrentObject->oPosY += gCurrentObject->oVelY;
    gCurrentObject->oPosZ += gCurrentObject->oVelZ;

    if (gCurrentObject->oTimer > 200)
    {
        gCurrentObject->oVelY += 0.3f;
    }

    if (gCurrentObject->oTimer > 300)
        gCurrentObject->activeFlags = 0;
}

extern const BehaviorScript bhvFightCtl[];
extern const BehaviorScript bhvFightFloorSwitch[];
void bhv_fight_switch_loop()
{
    if (0 == gCurrentObject->oAction)
    {
        // initial state, all are unpressed but we need to check if mao is pressed on us
        if (gMarioObject->platform == gCurrentObject)
        {
            // reset the other switch
            // I could cache these but I cba
            struct Object* os = cur_obj_nearest_object_with_behavior(bhvFightFloorSwitch);
            os->oAction = 0;

            struct Object* ctl = cur_obj_nearest_object_with_behavior(bhvFightCtl);
            ctl->oHealth--;
            if (0 == sFightRetries)
            {
                s16 ra = random_u16();
                for (int i = 0; i < 8; i++)
                {
                    int angle = ra + i * 0x2000; 
                    struct Object* n = spawn_object(gCurrentObject, MODEL_TRANSPARENT_STAR, bhvStarMoving);
                    f32 spd = 20.f - 2.f * ctl->oHealth;
                    f32 accel = 0.07;
                    n->oPosX += -sins(angle) * 1000.f;
                    n->oPosY = 138.f;
                    n->oPosZ += -coss(angle) * 1000.f;
                    n->oVelX = sins(angle) * spd;
                    n->oVelY = 0.f;
                    n->oVelZ = coss(angle) * spd;
                    n->oVelAccelX = sins(angle) * accel;
                    n->oVelAccelZ = coss(angle) * accel;
                    n->oFaceAngleRoll = 0x8000;
                }
            }

            cur_obj_play_sound_2(SOUND_GENERAL2_PURPLE_SWITCH);
            cur_obj_shake_screen(SHAKE_POS_SMALL);
            gCurrentObject->oAction = 1;
        }
        obj_scale_xyz(gCurrentObject, 1.2f, 1.2f, 1.2f);
    }
    else
    {
        // it is pressed, we do nothing basically
        obj_scale_xyz(gCurrentObject, 1.2f, 0.1f, 1.2f);
    }
}
