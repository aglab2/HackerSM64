void scroll_lll_dl_ending_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 57;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(lll_dl_ending_mesh_layer_1_vtx_11);

	deltaY = (int)(-0.43999993801116943 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_lll_dl_ending_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(lll_dl_ending_mesh_layer_5_vtx_0);

	deltaX = (int)(0.49000000953674316 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_lll() {
	scroll_lll_dl_ending_mesh_layer_1_vtx_11();
	scroll_lll_dl_ending_mesh_layer_5_vtx_0();
}
