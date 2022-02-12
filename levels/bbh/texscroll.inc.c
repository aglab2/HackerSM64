void scroll_bbh_dl_c5_mesh_layer_1_vtx_8() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bbh_dl_c5_mesh_layer_1_vtx_8);

	deltaX = (int)(0.40000003576278687 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bbh_dl_c5_001_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bbh_dl_c5_001_mesh_layer_1_vtx_2);

	deltaX = (int)(0.40000003576278687 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bbh_dl_c5_001_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 23;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bbh_dl_c5_001_mesh_layer_1_vtx_5);

	deltaY = (int)(-0.31999993324279785 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bbh_dl___mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 16;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bbh_dl___mesh_layer_1_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sts_mat_bbh_dl_laval_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bbh_dl_laval_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_bbh() {
	scroll_bbh_dl_c5_mesh_layer_1_vtx_8();
	scroll_bbh_dl_c5_001_mesh_layer_1_vtx_2();
	scroll_bbh_dl_c5_001_mesh_layer_1_vtx_5();
	scroll_bbh_dl___mesh_layer_1_vtx_0();
	scroll_sts_mat_bbh_dl_laval_layer1();
}
