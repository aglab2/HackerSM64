extern Gfx mat_bowser_2_dl_f3d_material_001_layer5[];
#if 0
static void fight_set_lines_color(u8 r, u8 g, u8 b)
{
    u8* color = (u8*)segmented_to_virtual(mat_bowser_2_dl_f3d_material_001_layer5) + 14 * 8 + 4;
    color[0] = r;
    color[1] = g;
    color[2] = b;
}
#endif

void fight_set_lines_alpha(u8 a)
{
    u8* color = (u8*)segmented_to_virtual(mat_bowser_2_dl_f3d_material_001_layer5) + 14 * 8 + 4;
    color[3] = a;
}

void fight_platform_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvBowser, &d);
    fight_set_lines_alpha(0);
}

static void fight_platform_rotate()
{
    o->oMoveAngleYaw += o->oAngleVelYaw;
    o->parentObj->oFaceAngleYaw = o->oMoveAngleYaw;
}

static void fight_platform_magnet_bowser()
{
    o->parentObj->oPosX = o->oPosX;
    o->parentObj->oPosZ = o->oPosZ;
}

static void fight_calm_bowser()
{
    if (o->parentObj->oAction != BOWSER_ACT_HIT_MINE
     && o->parentObj->oAction != BOWSER_ACT_DEAD
     && o->parentObj->oAction != BOWSER_ACT_DANCE)
    {
        o->parentObj->oAction = BOWSER_ACT_WAIT;
    }
}

// #define FIGHT_DEBUG
extern Vtx bowser_2_dl_cupol_mesh_layer_1_vtx_0[62] __attribute__((section(".data")));
static void fight_animate_bg()
{
    o->oFightCtlAnimTimer++;
    Vtx* vertices = segmented_to_virtual(bowser_2_dl_cupol_mesh_layer_1_vtx_0);
    f32 val = 140;
    s16 biasX = 198; 
    s16 biasZ = 0;

    for (int i = 0; i < 62; i++)
    {
        Vtx* vtx = &vertices[i];
        if (vtx->v.ob[0] == biasX && vtx->v.ob[2] == biasZ)
            continue;

        s16 dx = vtx->v.ob[0] - biasX;
        s16 dz = vtx->v.ob[2] - biasZ;
        s32 angle = atan2s(dx, dz);
        // there are 12 vertices, i want to have a periodic thing so I multiply angle to have 4 spots
        //  + vtx->v.ob[1] * 5.f
        f32 angleVal = (1.f + sins(o->oFightCtlAnimTimer * 562 + angle * 4)) / 2.f;
        vtx->v.cn[0] = angleVal * val;
        vtx->v.cn[1] = angleVal * val;
        vtx->v.cn[2] = angleVal * val;
    }
}

static void fight_decay_lines_alpha()
{
    u8* color = (u8*)segmented_to_virtual(mat_bowser_2_dl_f3d_material_001_layer5) + 14 * 8 + 4;
    u8 a = color[3];
    if (a < 4)
    {
        color[3] = 0;
    }
    else
    {
        color[3] = a - 4;
    }
}

#include "game/color.h"

static void fight_approach_lines_color(hsv* target)
{
    rgb* color = (rgb*) ((u8*)segmented_to_virtual(mat_bowser_2_dl_f3d_material_001_layer5) + 14 * 8 + 4);
    hsv hsv;
    rgb2hsv(color, &hsv);
    hsv.h = approach_angle(hsv.h, target->h, 1000);
    approach_f32_asymptotic_bool(&hsv.s, target->s, 0.1f);
    hsv.v = approach_s16(hsv.v, target->v, 1, 1);
    hsv2rgb(&hsv, color);
}

static void fight_magnet_bowser_to_opposite_side()
{
    approach_f32_asymptotic_bool(&o->oPosX, CLAMP(-gMarioStates->pos[0], -1150.f, 1150.f), 0.1f);
    approach_f32_asymptotic_bool(&o->oPosZ, CLAMP(-gMarioStates->pos[2], -1150.f, 1150.f), 0.1f);
}

extern Gfx mat_fight_bomb_f3d_material_002[]; // +19
extern Gfx mat_fight_plat_shadow_f3d_material_003[]; // +12

void fight_shadow_set_alpha(u8 v)
{
    u8* a;
    a = (u8*) segmented_to_virtual(mat_fight_bomb_f3d_material_002) + 19*8 + 7;
    *a = v;
    a = (u8*) segmented_to_virtual(mat_fight_plat_shadow_f3d_material_003) + 12*8 + 7;
    *a = v;
}

void fight_shadow_set_color(rgb* v)
{
    rgb* c = (rgb*) ((u8*) segmented_to_virtual(mat_fight_plat_shadow_f3d_material_003) + 12*8 + 4);
    c->r = v->r;
    c->g = v->g;
    c->b = v->b;
}

s32 fight_is_bomb(int i, int j)
{
    return !!(o->oFightCtlBombMap & (1 << (i*5 + j)));
}

void fight_set_bomb(int i, int j)
{
    o->oFightCtlBombMap |= 1 << (i*5 + j); 
}

s32 fight_is_empty(int i, int j)
{
    return !!(o->oFightCtlEmptiesMap & (1 << (i*5 + j)));
}

void fight_set_empty(int i, int j)
{
    o->oFightCtlEmptiesMap |= 1 << (i*5 + j); 
}

static void fight_draw_rope()
{
    if (!o->oFightCtlRoped)
    {
        o->oFightCtlRoped = spawn_object(o, MODEL_FIGHT_ROPED, bhvStaticObjectEx);
        o->oFightCtlRoped->oPosX = 0.0f;
        o->oFightCtlRoped->oPosY = 70.0f;
        o->oFightCtlRoped->oPosZ = 0.0f;
    }

    {
        // minus (0, 0)
        f32 dx = gMarioStates->pos[0];
        f32 dz = gMarioStates->pos[2];
        f32 d = sqrtf(dx*dx + dz*dz);
        o->oFightCtlRoped->oFaceAngleYaw = atan2s(dz, dx);
        obj_scale_xyz(o->oFightCtlRoped, 1.5f, 1.f, d / 300.f);
    }
}

static const f32 ArenaSize = 1150.f;
void fight_platform_ctl_loop()
{
    fight_animate_bg();
    if (0 == o->oAction && o->oTimer < 10)
        return;

    // intro
    if (gCamera->cutscene)
        return;

    // print_text_fmt_int(20, 20, "%d", o->oTimer);
    // print_text_fmt_int(20, 40, "%d", o->oAction);

    fight_calm_bowser();
    fight_platform_magnet_bowser();

    if (0 == o->oAction)
    {
        o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw = 0x4000;
        o->parentObj->oPosZ = 0;
        // 1450 is not arena size for platform - it is for mario arena size
        if (gMarioStates->pos[0] < 1450.f)
        {
            o->oAction = 1;
            o->oPosX = o->parentObj->oPosX;
            o->oPosZ = o->parentObj->oPosZ = 0;
        }
    }
    else if (1 == o->oAction)
    {
        o->oMoveAngleYaw = o->parentObj->oFaceAngleYaw = 0x4000;
        o->oPosY += 5.1f;
        if (30 == o->oTimer)
        {
#ifdef FIGHT_DEBUG
            fight_set_lines_alpha(200);
            seq_player_fade_out(0, 100);
            o->oAction = 3;
#else
            o->oAction = 2;
#endif
            o->oVelX = -30.f;
            o->oVelZ = -40.f;
            o->oAngleVelYaw = 0x172;
        }
    }
    else if (2 == o->oAction)
    {
        fight_magnet_bowser_to_opposite_side();
        fight_draw_rope();
        fight_decay_lines_alpha();
        if (o->parentObj->oAction == BOWSER_ACT_DEAD && o->parentObj->oTimer > 10)
        {
            // the fake death
            o->oAction = 3;
            seq_player_fade_out(0, 100);
        }
    }
    else if (3 == o->oAction)
    {
        // troll death, decelerate, when hit zero kill the lad
        o->oAngleVelYaw *= 0.97f;
        if (o->oFightCtlRoped)
        {
            o->oFightCtlRoped->activeFlags = 0;
            o->oFightCtlRoped = NULL;
        }

        if (0 == o->oAngleVelYaw)
        {
#ifdef FIGHT_DEBUG
            o->parentObj->oHealth = 1;
#else
            o->parentObj->oHealth = 3;
#endif
            o->oAction = 4;
            o->parentObj->oAction = BOWSER_ACT_DANCE;
            seq_player_play_sequence(0, SEQ_FIGHT2, 0);
        }
    }
    else if (4 == o->oAction)
    {
        // spin back up
        o->oAngleVelYaw += 150;

        if (o->oAngleVelYaw > 2000)
        {
            o->oAction = 5;
            f32 dx = gMarioStates->pos[0] - o->oPosX;
            f32 dz = gMarioStates->pos[2] - o->oPosZ;
            f32 d = sqrtf(dx*dx + dz*dz);
            o->oVelX = dx / d * 50.f;
            o->oVelZ = dz / d * 50.f;
        }
    }
    else if (5 == o->oAction)
    {
        // target mario
        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;
        s32 clampX = -ArenaSize > o->oPosX || o->oPosX > ArenaSize;
        s32 clampZ = -ArenaSize > o->oPosZ || o->oPosZ > ArenaSize;
        if (clampX || clampZ)
        {
            //struct Object* wave = spawn_object(o, MODEL_BOWSER_WAVE, bhvBowserShockWave);
            //wave->oPosY += 100.f;
            o->oAction = 10;
            spawn_object(o, MODEL_NONE, bhvTenCoinsSpawn);
        }
    }
    else if (6 == o->oAction)
    {
        // pick attack and maybe prepare it
        fight_magnet_bowser_to_opposite_side();
        
        u8* objAttacks = (u8*) &o->oFightCtlAttacksOrder;
        if (o->oFightCtlAttacksOrder == 0)
        {
            // this is the starting position - create an array of attacks and shuffle it
            char attacks[5] = { 0,1,2,3,4 };
            for (int i = 0; i < 5-1; i++)
            {
                int j = i + (random_u16() % (5-i));
                if (i != j)
                {
                    char v = attacks[i];
                    attacks[i] = attacks[j];
                    attacks[j] = v;
                }
            }

            objAttacks[0] = attacks[0];
            objAttacks[1] = attacks[1];
            objAttacks[2] = attacks[2];
            objAttacks[3] = attacks[3];
        }

        int active = 0;
        for (active = 0; active < 4; active++)
        {
            if (!(objAttacks[active] & 0x80))
            {
                break;
            }
        }

        if (active == 4)
        {
            // the last level is the one not chosen yet
            o->oFightCtlAttack = 0x80*4 + 0+1+2+3+4 - objAttacks[0] - objAttacks[1] - objAttacks[2] - objAttacks[3];
            // to reset next cycle
            o->oFightCtlAttacksOrder = 0;
        }
        else
        {
            // pick and mark attack used
            // MARK: oFightCtlAttack
            o->oFightCtlAttack = objAttacks[active];
            objAttacks[active] |= 0x80;
        }

        o->oAction = 7;
    }
    else if (7 == o->oAction)
    {
        // do mario attack
        fight_magnet_bowser_to_opposite_side();
        hsv color;
        color.h = o->oFightCtlAttack * (0x10000 / 5) + 0x10000 / 10;
        color.s = 1.f;
        color.v = 200;
        fight_approach_lines_color(&color);

        switch (o->oFightCtlAttack)
        {
        case 0:
        {
            // square attack
            if (0 == o->oTimer || 70 == o->oTimer || 140 == o->oTimer)
            {
                for (int i = 0; i < 40; i++)
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlameSquare);
                    hsv2rgb(&color, (rgb*) &flame->oFightFlameColor);
                    flame->oFightFlameAlphaSpeed = 0 == o->oTimer ? 3 : 7;

                    int pt = i / 10;
                    int num = i % 10;
                    int axisX = pt & 1;
                    f32 mult  = (pt & 2) ? 1.f : -1.f;
                    if (axisX)
                    {
                        flame->oPosX = mult * 1300.f;
                        flame->oPosZ = mult * (-1300.f + num * 260.f);
                    }
                    else
                    {
                        flame->oPosZ = mult * 1300.f;
                        flame->oPosX = mult * (-1300.f + num * 260.f);
                    }
                }
            }
        }
        break;
        case 2:
        {
            if (0 == o->oTimer)
            {
                for (int i = 0; i < 230; i++)
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlameCircle);
                    hsv2rgb(&color, (rgb*) &flame->oFightFlameColor);
                    flame->oFightFlameAlphaSpeed = 5;
                    flame->oPosX = 0.f    + random_f32_around_zero(9000.f);
                    flame->oPosZ = 2000.f + random_f32_around_zero(9000.f);
                }
            }
        }
        break; 
        case 1:
        {
            /*
                   /
             - - -
                   \
             */
            if ((o->oTimer < 180) && (0 == (o->oTimer % 4)))
            {
                f32 zPos = random_f32_around_zero(3200.f);

                // tail parts
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
                    flame->oForwardVel = 100.f;
                    flame->oMoveAngleYaw = -0x4000;
                    flame->oPosX = 1600.f;
                    flame->oPosY = 30.f;
                    flame->oPosZ = zPos;
                    rgb* c = (rgb*) &flame->oFightFlameColor;
                    c->r = 0xfd;
                    c->g = 0xff;
                    c->b = 0x9f;
                    c->a = 0;
                    flame->oFightFlameAlphaSpeed = o->oTimer < 30 ? 5 : 20;
                    if (o->oTimer > 30)
                    {
                        flame->oFightFlameFlags = 1;
                    }
                }
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
                    flame->oForwardVel = 100.f;
                    flame->oMoveAngleYaw = -0x4000;
                    flame->oPosX = 1550.f;
                    flame->oPosY = 30.f;
                    flame->oPosZ = zPos;
                    rgb* c = (rgb*) &flame->oFightFlameColor;
                    c->r = 0xff;
                    c->g = 0xff;
                    c->b = 0xff;
                    c->a = 0;
                    flame->oFightFlameAlphaSpeed = o->oTimer < 30 ? 5 : 20;
                    if (o->oTimer > 30)
                    {
                        flame->oFightFlameFlags = 1;
                    }
                }
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
                    flame->oForwardVel = 100.f;
                    flame->oMoveAngleYaw = -0x4000;
                    flame->oPosX = 1500.f;
                    flame->oPosY = 30.f;
                    flame->oPosZ = zPos;
                    rgb* c = (rgb*) &flame->oFightFlameColor;
                    c->r = 0x2c;
                    c->g = 0x77;
                    c->b = 0x2c;
                    c->a = 0;
                    flame->oFightFlameAlphaSpeed = o->oTimer < 30 ? 5 : 20;
                    if (o->oTimer > 30)
                    {
                        flame->oFightFlameFlags = 1;
                    }
                }
                // head parts
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
                    flame->oForwardVel = 100.f;
                    flame->oMoveAngleYaw = -0x4000;
                    flame->oPosX = 1450.f;
                    flame->oPosY = 30.f;
                    flame->oPosZ = zPos + 50.f;
                    rgb* c = (rgb*) &flame->oFightFlameColor;
                    c->r = 0x25;
                    c->g = 0x61;
                    c->b = 0x2b;
                    c->a = 0;
                    flame->oFightFlameAlphaSpeed = o->oTimer < 30 ? 5 : 20;
                    if (o->oTimer > 30)
                    {
                        flame->oFightFlameFlags = 1;
                    }
                }
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
                    flame->oForwardVel = 100.f;
                    flame->oMoveAngleYaw = -0x4000;
                    flame->oPosX = 1450.f;
                    flame->oPosY = 30.f;
                    flame->oPosZ = zPos - 50.f;
                    rgb* c = (rgb*) &flame->oFightFlameColor;
                    c->r = 0x25;
                    c->g = 0x61;
                    c->b = 0x2b;
                    c->a = 0;
                    flame->oFightFlameAlphaSpeed = o->oTimer < 30 ? 5 : 20;
                    if (o->oTimer > 30)
                    {
                        flame->oFightFlameFlags = 1;
                    }
                }
            }
        }
        break;
        case 3:
        {
            if (0 == (o->oTimer % 15) && o->oTimer < 180)
            {
                for (int i = 0; i < 8; i++)
                {
                    struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlameEmperor);
                    flame->oForwardVel = 50.f;
                    flame->oFaceAngleYaw = 0x2000 * i;
                    flame->oPosX = gMarioStates->pos[0];
                    flame->oPosY = 30.f;
                    flame->oPosZ = gMarioStates->pos[2];
                    rgb* c = (rgb*) &flame->oFightFlameColor;
                    hsv2rgb(&color, c);
                    flame->oFightFlameAlphaSpeed = o->oTimer < 30 ? 3 : 10;
                }
            }
        }
        break;
        case 4:
        {
            if (0 != o->oTimer && o->oTimer < 230)
            {
                struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlameG);
                flame->parentObj = o;
                flame->oPosX = 0.f;
                flame->oPosY = 0.f;
                flame->oPosZ = 0.f;
                rgb* c = (rgb*) &flame->oFightFlameColor;
                hsv2rgb(&color, c);
                flame->oFightFlameAlphaSpeed = o->oTimer < 60 ? 5 : 15;
                flame->oMoveAngleYaw = random_u16();
            }
        }
        break;
        default:
            break;
        }
    
        if (250 == o->oTimer)
        {
            o->oAction = 8;
        }
    }
    else if (8 == o->oAction)
    {
        fight_draw_rope();
        if (o->parentObj->oHealth == 0)
        {
            cur_obj_become_intangible();
            o->oAction = 9;
            o->oFightCtlRoped->activeFlags = 0;
            o->oFightCtlRoped = NULL;
            save_file_set_flags(SAVE_FLAG_MOAT_DRAINED);
            save_file_do_save(gCurrSaveFileNum - 1);
            return;
        }
        // o->oFaceAngleRoll = 0x600 * (3 - o->parentObj->oHealth);

        fight_magnet_bowser_to_opposite_side();
        // do the panels/bombs attack
        // this is 5x5 attack encompassing the whole area of the fight
        if (0 == o->oTimer)
        {
            o->oFightCtlBombMap = 0;
            o->oFightCtlEmptiesMap = 0;
            // pick 4 random spots where bombs will be in 4 quarters
            s32 negativeX = gMarioStates->pos[0] > 0;
            s32 negativeZ = gMarioStates->pos[2] > 0;
            s32 lastHit = o->parentObj->oHealth == 1;
            if ((!lastHit && (!negativeX || !negativeZ)) || (lastHit && !negativeX && !negativeZ))
            {
                u8 pos = random_u16() % 8;
                fight_set_bomb(0 + pos % 3, 0 + pos / 3); // -/-
            }

            if ((!lastHit && (!negativeX || negativeZ)) || (lastHit && !negativeX && negativeZ))
            {
                u8 pos = random_u16() % 8;
                s32 x = 0 + pos % 3; s32 z = 4 - pos / 3;
                if (!fight_is_bomb(x, z))
                    fight_set_bomb(x, z); // -/+
                else 
                    fight_set_bomb(0, 4);
            }

            if ((!lastHit && (negativeX || !negativeZ)) || (lastHit && negativeX && !negativeZ))
            {
                u8 pos = random_u16() % 8;
                s32 x = 4 - pos / 3; s32 z = 0 + pos % 3;
                if (!fight_is_bomb(x, z))
                    fight_set_bomb(x, z); // +/-
                else 
                    fight_set_bomb(4, 0);
            }

            if ((!lastHit && (negativeX || negativeZ)) || (lastHit && negativeX && negativeZ))
            {
                u8 pos = random_u16() % 8;
                s32 x = 4 - pos / 3; s32 z = 4 - pos % 3;
                if (!fight_is_bomb(x, z))
                    fight_set_bomb(x, z); // +/+
                else 
                    fight_set_bomb(4, 4);
            }

            if (o->parentObj->oHealth <= 2)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (o->parentObj->oHealth == 1 && (i % 2))
                        continue;

                    int num = i / 2; // from 0 to 3
                    s32 x = 2 * (num / 2) + random_u16() % 3;
                    s32 z = 2 * (num % 2) + random_u16() % 3;
                    if (!fight_is_bomb(x, z))
                        fight_set_empty(x, z);
                }
            }

            fight_shadow_set_alpha(0);
            for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                if (fight_is_bomb(4-i, 4-j) || fight_is_empty(i, j))
                    continue;

                s32 is_bomb = fight_is_bomb(i, j);
                struct Object* plat = spawn_object(o, is_bomb ? MODEL_FIGHT_BOMB_SHADOW : MODEL_FIGHT_PLAT_SHADOW, bhvFightShadow);
                // plat->oFaceAngleRoll = 0;
                plat->oFaceAngleYaw = 0;
                plat->oBehParams2ndByte = is_bomb;
                plat->parentObj = o;
                plat->oPosX = i * 600.f - 1200.f;
                plat->oPosY = 10.f;
                plat->oPosZ = j * 600.f - 1200.f;
            }
        }
        else if (o->oTimer < 150)
        {
            rgb color;
            color.r = 150 + 50 * sins(0x345 * o->oTimer);
            color.g = 50;
            color.b = 50;
            fight_shadow_set_color(&color);
            fight_shadow_set_alpha(o->oTimer * 1.5f);
        }
        else if (o->oTimer == 170)
        {
            for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                if (fight_is_bomb(4-i, 4-j) || fight_is_empty(i, j))
                    continue;

                s32 is_bomb = fight_is_bomb(i, j);
                struct Object* stuff;
                if (is_bomb)
                {
                    stuff = spawn_object(o, MODEL_BOWSER_BOMB, bhvBowserBomb);
                    stuff->oBehParams2ndByte = 2;
                    stuff->oPosY = 430.f;
                }
                else
                {
                    stuff = spawn_object(o, MODEL_FIGHT_SPIKES, bhvFightSpikes);
                    stuff->oPosY = -400.f;
                }
                stuff->oFaceAngleYaw = 0;
                stuff->parentObj = o;
                stuff->oPosX = i * 600.f - 1200.f;
                stuff->oPosZ = j * 600.f - 1200.f;
            }
        }
        else if (o->oTimer == 300)
        {
            o->oFightCtlRoped->activeFlags = 0;
            o->oFightCtlRoped = NULL;
            o->oAction = 6;
            struct Object* coins = spawn_object(o, MODEL_NONE, bhvThreeCoinsSpawn);
            coins->oPosX = o->oPosX;
            coins->oPosY = o->oPosY + 20.f;
            coins->oPosZ = o->oPosZ;
        }
    }
    else if (9 == o->oAction)
    {
        return;
        if (0 == o->oTimer)
        {
            o->oVelY = 100.f;
            f32 d = sqrtf(o->oPosX*o->oPosX + o->oPosZ*o->oPosZ);
            o->oVelX = 30.f * (o->oPosX / d);
            o->oVelZ = 30.f * (o->oPosZ / d);
        }

        if (o->oPosY < -5000.f)
        {
            o->activeFlags = 0;
        }

        o->oVelY -= 1.f;
        o->oPosX += o->oVelX;
        o->oPosY += o->oVelY;
        o->oPosZ += o->oVelZ;
    }
    else if (10 == o->oAction)
    {
        fight_magnet_bowser_to_opposite_side();
        if (o->oTimer == 30)
        {
            o->oAction = 6;
        }
    }

    fight_platform_rotate();
}

void fight_shadow_loop()
{
    if (o->oBehParams2ndByte)
    {
        o->oFaceAngleYaw += 0x269;
        o->oPosY = o->oHomeY + 10.f * sins(0x656 * o->oTimer);
    }
    else
    {
        o->oPosX = o->oHomeX + 10.f * sins(0x456 * o->oTimer);
        o->oPosZ = o->oHomeZ + 10.f * coss(0x156 * o->oTimer);
    }

    if (171 == o->oTimer)
    {
        o->activeFlags = 0;
    }
}

struct ObjectHitbox sFightBowserFlameHitbox = {
    /* interactType: */ INTERACT_FLAME,
    /* downOffset: */ 0,
    /* damageOrCoinValue: */ 1,
    /* health: */ 0,
    /* numLootCoins: */ 0,
    /* radius: */ 5,
    /* height: */ 20,
    /* hurtboxRadius: */ 0,
    /* hurtboxHeight: */ 0,
};

void fight_flame_init()
{
    o->oVelY = -28.0f;
    o->oPosY += 10.f;
    o->oFlameScale = 3.f;
}

void fight_flame_loop()
{
    rgb* c = (rgb*) &o->oFightFlameColor;
    if (c->a > 254 - o->oFightFlameAlphaSpeed)
    {
        c->a = 255;
        obj_set_hitbox(o, &sFightBowserFlameHitbox);
    }
    else
    {
        c->a += o->oFightFlameAlphaSpeed;
    }
    if (o->oFightFlameFlags)
    {
        obj_set_hitbox(o, &sFightBowserFlameHitbox);
    }
    obj_scale(o, o->oFlameScale);
    o->oBounciness = -1.f;
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    o->oInteractStatus = 0;

    f32 dist = o->oPosX * o->oPosX + o->oPosZ * o->oPosZ;
    if (dist > 2000.f * 2000.f)
        o->activeFlags = 0; 
}

void fight_flame_square_init()
{
    fight_flame_init();
    // calculate the positions
    o->oFaceAngleYaw = atan2s(o->oPosZ, o->oPosX);
    o->oHomeX = sqrtf(o->oPosX * o->oPosX + o->oPosZ * o->oPosZ);

    // just a convenience in case I messed up atan2s params lol
    o->oPosX = o->oHomeX * sins(o->oFaceAngleYaw);
    o->oPosZ = o->oHomeX * coss(o->oFaceAngleYaw);
}

void fight_flame_square_loop()
{
    if (o->oTimer > 10)
    {
        s32 t = o->oTimer - 10;
        o->oPosX = (1.f - 0.0000015f * t * t * t) * o->oHomeX * sins(o->oFaceAngleYaw + t * 0x145);
        o->oPosY = 10.f;
        o->oPosZ = (1.f - 0.0000015f * t * t * t) * o->oHomeX * coss(o->oFaceAngleYaw + t * 0x145);
    }

    rgb* c = (rgb*) &o->oFightFlameColor;
    if (c->a > 255 - o->oFightFlameAlphaSpeed)
    {
        c->a = 255;
        obj_set_hitbox(o, &sFightBowserFlameHitbox);
    }
    else
    {
        c->a += o->oFightFlameAlphaSpeed;
    }
    obj_scale(o, o->oFlameScale);
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    o->oInteractStatus = 0;

    f32 dist = o->oPosX * o->oPosX + o->oPosZ * o->oPosZ;
    if (dist > 2000.f * 2000.f)
        o->activeFlags = 0;
}

void fight_flame_circle_init()
{
    fight_flame_init();

    f32 centerX = 0.f;
    f32 centerZ = 3000.f;

    // calculate the positions
    f32 dx = centerX - o->oPosX;
    f32 dz = centerZ - o->oPosZ;
    o->oFaceAngleYaw = atan2s(dz, dx);
    o->oHomeY = sqrtf(dx * dx + dz * dz);
    o->oPosX = o->oHomeY * sins(o->oFaceAngleYaw) + centerX;
    o->oPosZ = o->oHomeY * coss(o->oFaceAngleYaw) + centerZ;
}

void fight_flame_circle_loop()
{
    f32 centerX = 3000.f * sins(o->oTimer * o->oTimer * 0.55f);
    f32 centerZ = 3000.f * coss(o->oTimer * o->oTimer * 0.55f);
    o->oPosX = o->oHomeY * sins(o->oFaceAngleYaw) + centerX;
    o->oPosZ = o->oHomeY * coss(o->oFaceAngleYaw) + centerZ;

    rgb* c = (rgb*) &o->oFightFlameColor;
    if (o->oTimer < 230)
    {
        if (c->a > 255 - o->oFightFlameAlphaSpeed)
        {
            c->a = 255;
            obj_set_hitbox(o, &sFightBowserFlameHitbox);
        }
        else
        {
            c->a += o->oFightFlameAlphaSpeed;
        }
    }
    else
    {
        cur_obj_become_intangible();
        if (c->a < 10)
        {
            o->activeFlags = 0;
        }
        else
        {
            c->a -= 7;
        }
    }

    obj_scale(o, o->oFlameScale);
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    o->oInteractStatus = 0;
    o->oPosY = 10.f;
}

void fight_flame_locus_init()
{
    fight_flame_init();
    o->oFlameScale = 5.f;
}

void fight_flame_locus_loop()
{
    fight_flame_loop();
    o->oPosY = 500.f - 25.f * o->oTimer;
    if (o->oPosY < 30.f)
    {
        f32 dx = gMarioStates->pos[0] - o->oPosX;
        f32 dz = gMarioStates->pos[2] - o->oPosZ;
        s16 angle = atan2s(dz, dx);
        for (int i = 0; i < 4; i++)
        {
            struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
            flame->oForwardVel = i == 0 ? 60.f : 50.f;
            flame->oMoveAngleYaw = angle + 0x4000 * i;
            flame->oPosX = o->oPosX;
            flame->oPosY = o->oPosY;
            flame->oPosZ = o->oPosZ;
            flame->oFightFlameColor = o->oFightFlameColor;
        }
        o->activeFlags = 0;
    }
}

void fight_flame_emperor_init()
{
    fight_flame_init();
}

void fight_flame_emperor_loop()
{
    f32 d;
    if (o->oTimer < 30)
    {
        o->oFaceAngleYaw += o->oTimer * 0x145;
        d = o->oTimer * 15.f;
    }
    else if (o->oTimer < 70)
    {
        o->oFaceAngleYaw += o->oTimer * 0x145 * (70 - o->oTimer) / 40.f;
        d = 450.f;
    }
    else
    {
        s32 t = 70 - o->oTimer;
        d = 450.f - 0.4f * t * t;
    }

    o->oPosX = o->oHomeX + d * sins(o->oFaceAngleYaw);
    o->oPosY = 10.f;
    o->oPosZ = o->oHomeZ + d * coss(o->oFaceAngleYaw);

    rgb* c = (rgb*) &o->oFightFlameColor;
    if (c->a > 255 - o->oFightFlameAlphaSpeed)
    {
        c->a = 255;
        obj_set_hitbox(o, &sFightBowserFlameHitbox);
    }
    else
    {
        c->a += o->oFightFlameAlphaSpeed;
    }
    obj_scale(o, o->oFlameScale);
    cur_obj_update_floor_and_walls();
    cur_obj_move_standard(78);
    o->oInteractStatus = 0;

    if (o->oTimer > 70)
    {
        f32 dist = o->oPosX * o->oPosX + o->oPosZ * o->oPosZ;
        if (dist > 2000.f * 2000.f)
            o->activeFlags = 0;
    }
}

void fight_flame_g_init()
{
    fight_flame_init();
}

void fight_flame_g_loop()
{
    int time = o->parentObj->oTimer / 2;
    if (time % 10)
    {
        // -
    }
    else
    {
        o->oForwardVel = 4.f;
        if (0 == (time % 20))
        {
            o->oForwardVel = 60.f + random_f32_around_zero(30.f); 
        }
    }

    fight_flame_loop();
}

extern Gfx mat_fight_arrow_f3d_material_004[];
void fight_bomb_ctl_init()
{
    f32 d;
    o->parentObj = cur_obj_find_nearest_object_with_behavior(bhvFightPlatformCtl, &d);
    
    u8* a = (u8*) segmented_to_virtual(mat_fight_arrow_f3d_material_004) + 8*19 + 7;
    *a = 0;
}

void fight_bomb_ctl_loop()
{
    if (0 == o->oAction)
    {
        if (2 == o->parentObj->oAction)
        {
            o->oAction = 1;
            o->oSubAction = 0;
            o->oFightCtlBombCooldown = 20;
            o->oPosX = -963.f;
            o->oVelX = -30.f;
            o->oVelZ = -40.f;
        }
    }
    else
    {
        if (3 == o->parentObj->oAction)
        {
            o->activeFlags = 0;
        }

        int bowserHp = o->parentObj->parentObj->oHealth; // yes

        // Bouncing around in the circles.
        // One of the velocities is constant, other one is gravitated towards the side bowser is moving along/
        // Initially it is X axis that is Bowser graviated to, Z speed is kept constant.
        s32 gravTowardsX = 0 == (o->oSubAction & 1);
        f32 accel        =      (o->oSubAction & 2) ? -8.f : 8.f;
        if (gravTowardsX)
        {
            // towards X
            o->oVelX -= accel;
        }
        else
        {
            // towards Z
            o->oVelZ -= accel;
        }
        
        // apply speed and check for clamping
        o->oPosX += o->oVelX;
        o->oPosZ += o->oVelZ;

        s32 clampX = -ArenaSize > o->oPosX || o->oPosX > ArenaSize;
        s32 clampZ = -ArenaSize > o->oPosZ || o->oPosZ > ArenaSize;

        // condition for bouncing moment
        if ((gravTowardsX && clampZ) || (!gravTowardsX && clampX))
        {
            // we need to switch directions
            // clamp both coordinates first, it will be fixed next frame if stuff goes raw
            o->oSubAction++;
            o->oPosX = CLAMP(o->oPosX, -ArenaSize, ArenaSize);
            o->oPosZ = CLAMP(o->oPosZ, -ArenaSize, ArenaSize);

            f32 newGravTowardsX = 0 == (o->oSubAction & 1);
            f32 newVelForAccel = (o->oSubAction & 2) ? 80.f : -80.f;
            s32 mask = o->oSubAction & 3;
            if (newGravTowardsX)
            {
                o->oVelX = newVelForAccel;
                o->oVelZ = (mask == 0 || mask == 3) ? -40.f : 40.f;
            }
            else
            {
                o->oVelZ = newVelForAccel;
                o->oVelX = (mask == 0 || mask == 3) ? -40.f : 40.f;
            }
        }
        else
        {
            // check for regular bouncing
            if (clampX)
            {
                o->oVelX = -o->oVelX;
                o->oPosX = CLAMP(o->oPosX, -ArenaSize, ArenaSize);
            }

            if (clampZ)
            {
                o->oVelZ = -o->oVelZ;
                o->oPosZ = CLAMP(o->oPosZ, -ArenaSize, ArenaSize);
            }

            if (bowserHp == 1 && o->oFightCtlBombIndicator && (o->oFightCtlBombIndicator->oTimer > 30) && (clampX || clampZ))
            {
                cur_obj_play_sound_2(SOUND_ACTION_METAL_BONK);
                struct Object* flame = spawn_object(o, MODEL_FIGHT_FLAME, bhvFightFlame);
                flame->oForwardVel = 50.f;
                flame->oPosY = 10.f;
                flame->oMoveAngleYaw = 0x4000 - 0x4000 * o->oSubAction; //  + 0x1000 * i
                rgb* c = (rgb*) &flame->oFightFlameColor;
                c->r = 100;
                c->g = 100;
                c->b = 255;
                c->a = 0;
                flame->oFightFlameAlphaSpeed = 30;
            }
        }

        if (o->oFightCtlBombIndicator)
        {
            if (bowserHp == 2)
            {
                o->oFightCtlBombIndicator->oPosX = sins(0x136 * o->oTimer) * 800.f;
                o->oFightCtlBombIndicator->oPosZ = coss(0x136 * o->oTimer) * 800.f;
            }
            if (bowserHp == 1)
            {
                o->oFightCtlBombIndicator->oPosX = o->oPosX;
                o->oFightCtlBombIndicator->oPosZ = o->oPosZ;
            }

            if (o->oFightCtlBombIndicator->oTimer < 150)
                fight_shadow_set_alpha(o->oFightCtlBombIndicator->oTimer * 1.5f);

            if (170 == o->oFightCtlBombIndicator->oTimer)
            {
                o->oFightCtlBomb = spawn_object(o, MODEL_BOWSER_BOMB, bhvBowserBomb);
                o->oFightCtlBomb->oPosX = o->oFightCtlBombIndicator->oPosX;
                o->oFightCtlBomb->oPosZ = o->oFightCtlBombIndicator->oPosZ;
                o->oFightCtlBomb->oBehParams2ndByte = 1;
                o->oFightCtlBomb->parentObj = o; // just in case lol
                o->oFightCtlBombIndicator = NULL;
            }
        }
        else if (!o->oFightCtlBomb)
        {
            if (o->oFightCtlBombCooldown)
            {
                o->oFightCtlBombCooldown--;
            }
            else
            {
                struct Object* plat;
                plat = spawn_object(o, MODEL_FIGHT_BOMB_SHADOW, bhvFightShadow);
                plat->oFaceAngleYaw = 0;
                plat->oBehParams2ndByte = 1;
                plat->oPosY = 10.f;
                if (bowserHp == 3)
                {
                    plat->oPosX = gMarioStates->pos[0] > 0 ? 800.f : -800.f;
                    plat->oPosZ = gMarioStates->pos[2] > 0 ? 800.f : -800.f;
                }
                else if (bowserHp == 2)
                {
                    plat->oPosX = sins(0x136 * o->oTimer) * 800.f;
                    plat->oPosZ = coss(0x136 * o->oTimer) * 800.f;
                }
                else if (bowserHp == 1)
                {
                    plat->oPosX = o->oPosX;
                    plat->oPosZ = o->oPosZ;
                }
                o->oFightCtlBombIndicator = plat;
                fight_shadow_set_alpha(0);
            }
        }
    }
}

void fight_spikes_loop()
{
    if (o->oTimer < 10)
    {
        o->oPosY += 30.f;
    }

    if (o->oTimer > 50)
    {
        o->oPosY -= 5.f;
    }

    if (o->oTimer == 150)
    {
        o->activeFlags = 0;
    }
}
