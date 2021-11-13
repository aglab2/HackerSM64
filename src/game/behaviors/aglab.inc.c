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

void bhv_death_fireball_loop()
{
    // move to Y with vel 20
    // move to X/Z with vel 10

    // to: 28, -385, 5090 

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

    if (gCurrentObject->oTimer < 200)
    {
        cur_obj_scale(1.f + sins(gCurrentObject->oTimer * 2370) * 0.04f);
    }
    else if (gCurrentObject->oTimer < 250)
    {
        // cur_obj_scale(1.f + sins(gCurrentObject->oTimer * 13370) * 0.2f);
        int left = (gCurrentObject->oTimer - 200) * (gCurrentObject->oTimer - 200);
        int leftMax = 2500;
        int diffW = 3000 - 2370;
        float diffA = 0.3f - 0.04f;
        cur_obj_scale(1.f + sins(gCurrentObject->oTimer * (2370 + diffW * left / leftMax)) * (0.04f + diffA * left / leftMax));
    }
    else
    {
        cur_obj_scale(1.f + (gCurrentObject->oTimer - 250) * 0.12f);
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
