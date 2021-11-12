extern int gTriggerHell;

void bhv_death_fireball_loop()
{
    if (!gTriggerHell)
        return;

    if (!gCurrentObject->oAction)
    {
        gCurrentObject->oAction = 1;
        gCurrentObject->oTimer = 0;
    }

    print_text_fmt_int(20, 20, "%d", gCurrentObject->oTimer);

    // trap mario inside the cube
    if (gMarioStates->pos[2] > 5400.f)
        gMarioStates->pos[2] = 5400.f;
            
    if (gMarioStates->pos[0] < -1000.f)
        gMarioStates->pos[0] = -1000.f;
    if (gMarioStates->pos[0] > 500.f)
        gMarioStates->pos[0] = 500.f;
}
