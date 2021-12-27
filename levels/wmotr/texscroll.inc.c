void scroll_wmotr_dl_mc_mesh_layer_1_vtx_10() {
	int i = 0;
	int count = 103;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_mc_mesh_layer_1_vtx_10);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wmotr_dl_mc_mesh_layer_1_vtx_19() {
	int i = 0;
	int count = 6;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_mc_mesh_layer_1_vtx_19);

	deltaY = (int)(0.5199999809265137 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr() {
	scroll_wmotr_dl_mc_mesh_layer_1_vtx_10();
	scroll_wmotr_dl_mc_mesh_layer_1_vtx_19();
}
