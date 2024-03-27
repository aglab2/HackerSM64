static int gCurrentHole = 0;

void bhv_hole_init()
{

}

void bhv_hole_loop()
{

}

void bhv_start_init()
{

}

void bhv_start_loop()
{

}

void bhv_ctl_init()
{

}

void bhv_ctl_loop()
{
    print_text_fmt_int(20, 20, "%x", gMarioStates->action);
}
