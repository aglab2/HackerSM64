void scroll_wmotr_dl_mc_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 76;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_mc_mesh_layer_1_vtx_4);

	deltaX = (int)(0.40000009536743164 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wmotr_dl_mc_mesh_layer_1_vtx_13() {
	int i = 0;
	int count = 6;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_mc_mesh_layer_1_vtx_13);

	deltaY = (int)(0.5199999809265137 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_wmotr_dl___f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl___f3d_layer1);
	shift_s(mat, 35, PACK_TILESIZE(0, 1));
};

void scroll_wmotr_dl_mc_004_mesh_layer_1_vtx_7() {
	int i = 0;
	int count = 21;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_mc_004_mesh_layer_1_vtx_7);

	deltaX = (int)(0.40000009536743164 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wmotr() {
	scroll_wmotr_dl_mc_mesh_layer_1_vtx_4();
	scroll_wmotr_dl_mc_mesh_layer_1_vtx_13();
	scroll_sts_mat_wmotr_dl___f3d_layer1();
	scroll_wmotr_dl_mc_004_mesh_layer_1_vtx_7();
}
