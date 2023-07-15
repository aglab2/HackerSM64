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

void bhv_ctl_init()
{

}

void bhv_ctl_loop()
{
    print_text_fmt_int(20, 60, "X %d", (int) gMarioStates->pos[0]);
    print_text_fmt_int(20, 40, "Y %d", (int) gMarioStates->pos[1]);
    print_text_fmt_int(20, 20, "Z %d", (int) gMarioStates->pos[2]);
}
