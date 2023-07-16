void bhv_player_init()
{
    if (0 == BPARAM1)
    {
        o->oAnimations = bobomb_seg8_anims_0802396C;
    }
    else
    {
        o->oAnimations = goomba_seg8_anims_0801DA4C;
        obj_scale(o, 1.5f);
    }

    cur_obj_init_animation(0);
}

void bhv_player_loop()
{

}

// OBJECT(MODEL_NONE, 27, 1183, -2945, 0, 0, 0, 0x00000000, bhv1Up),
void bhv_ctl_init()
{
    for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++)
    {
        struct Object* th = spawn_object(o, 0xf1 + i + 4*j, bhvStaticObject);
        th->oPosX = 107;
        th->oPosY = 1440 - 170 * i;
        th->oPosZ = -2945 + 340 * (j ? -1 : 1);
        th->oFaceAngleYaw = 0x8000;
        th->oFaceAngleRoll = 0x8000;
        th->oFaceAnglePitch = 0x8000;
        SET_BPARAM1(th->oBehParams, i);
        SET_BPARAM2(th->oBehParams, j);
    }
}

static void spawn_sparkles()
{
    if (0 == (o->oTimer % 4))
    {
        struct Object* spark = spawn_object(o, MODEL_NONE, bhvSparkleSpawn);
        spark->oPosX += random_f32_around_zero(100.f);
        spark->oPosY += random_f32_around_zero(100.f);
        spark->oPosZ += random_f32_around_zero(100.f);
    }
}

void bhv_ctl_loop()
{
    spawn_sparkles();
    print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);

    gCamera->cutscene = CUTSCENE_MAIN_SCENE;
}

void bhv_ctl_choice_init()
{

}

void bhv_ctl_choice_loop()
{
    spawn_sparkles();
    return;
    if (0 == BPARAM1)
    {
        gMarioStates->pos[0] = o->oPosX;
        gMarioStates->pos[1] = o->oPosY;
        gMarioStates->pos[2] = o->oPosZ;
        gMarioStates->faceAngle[1] = 0;
    }
}
