void ctl_init()
{

}

extern const BehaviorScript bhvBat[];
void ctl_loop()
{
    gMarioStates->pos[2] = 0.f;

    if (0 == (o->oTimer % 2))
    {
        struct Object* bat = spawn_object(o, MODEL_SWOOP, bhvBat);
        bat->oPosX = random_f32_around_zero(6000.f);
        bat->oPosY = 30.f;
        bat->oPosZ = -5000.f;
    }
}

void bat_init()
{

}

void bat_loop()
{
    cur_obj_init_animation_with_accel_and_sound(0, 2.0f);
    o->oPosZ += 30.f;
    if (o->oPosZ > 5000.f)
        o->activeFlags = 0;
}
