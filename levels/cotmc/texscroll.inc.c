void scroll_cotmc_dl_s1_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 36;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(cotmc_dl_s1_mesh_layer_1_vtx_11);

	deltaY = (int)(0.1899999976158142 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_cotmc_dl_s1_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 37;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(cotmc_dl_s1_002_mesh_layer_5_vtx_0);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_cotmc() {
	scroll_cotmc_dl_s1_mesh_layer_1_vtx_11();
	scroll_cotmc_dl_s1_002_mesh_layer_5_vtx_0();
}
