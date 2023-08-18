void scroll_lll_dl_DL_lll_1_0xe0387b0_Obj_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 10;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(lll_dl_DL_lll_1_0xe0387b0_Obj_002_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.19999992847442627 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_lll() {
	scroll_lll_dl_DL_lll_1_0xe0387b0_Obj_002_mesh_layer_5_vtx_0();
};
