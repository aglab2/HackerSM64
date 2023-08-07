extern s32 gTatums;
extern s16 sHandheldShakeRoll;
extern const BehaviorScript bhvBat[];

void ctl_init()
{
    gTatums = 0;
    for (int i = 0; i < 70; i++)
    {
        struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBat);
        bat->oPosX = random_f32_around_zero(6000.f);
        bat->oPosY = 30.f;
        bat->oPosZ = -5000.f + 32.f * i;
        bat->oVelZ = random_u16() & 1 ? 32.f : 40.f;
    }
}

void ctl_loop()
{
    print_text_fmt_int(20, 20, "%d", gTatums);
    sHandheldShakeRoll = 0x2000;
    gMarioStates->pos[2] = 0.f;

    if (0 == (o->oTimer % 2))
    {
        struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBat);
        bat->oPosX = random_f32_around_zero(6000.f);
        bat->oPosY = 30.f;
        bat->oPosZ = -5000.f;
        bat->oVelZ = random_u16() & 1 ? 32.f : 40.f;
    }
}

void bat_init()
{

}

// 2048 - first beep
// 6350 - second beep
// 7100 - turn 1
// 8200 - turn 2
// 9200 - turn 3
// 10100 - turn 3
// 14000 - drop
// 17200 - go closer
// 20730 : 22000 - go far
// 24000 - go
// 27500 - go
// 31000 - ?
// 31800 - bam rotate
// 33360 - bam rotate
// 35000 - bam rotate
// 37000 - bam rotate
// 37900 - bam rotate
// 38500 - cam down

// 48000 - drop
// 50600 - stop
// 52400 : 54100 - swoosh
// 55800 : 57400 - swoosh
// 59000 : 60700 - swoosh
// 62600 - slight turn
// 64300 - slight turn

void bat_loop()
{
    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);
    o->oPosZ += o->oVelZ;
    if (o->oPosZ > 5000.f)
        o->activeFlags = 0;
    
    if (o->oDistanceToMario < 100.f)
    {
        o->activeFlags = 0;
    }
}
