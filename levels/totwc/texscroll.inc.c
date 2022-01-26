void scroll_totwc_dl__bg_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 9;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(totwc_dl__bg_002_mesh_layer_5_vtx_0);

	deltaX = (int)(0.3100000023841858 * 0x20) % width;
	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_totwc_dl_s2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 70;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(totwc_dl_s2_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.07999992370605469 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_totwc_dl_s2_004_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(totwc_dl_s2_004_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.07999992370605469 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_totwc() {
	scroll_totwc_dl__bg_002_mesh_layer_5_vtx_0();
	scroll_totwc_dl_s2_mesh_layer_5_vtx_0();
	scroll_totwc_dl_s2_004_mesh_layer_5_vtx_0();
}
