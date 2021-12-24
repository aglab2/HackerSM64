void scroll_bowser_1_dl_f2_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 26;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_f2_mesh_layer_1_vtx_3);

	deltaX = (int)(-0.16999995708465576 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bowser_1_dl_f2_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 30;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bowser_1_dl_f2_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.3400000333786011 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bowser_1() {
	scroll_bowser_1_dl_f2_mesh_layer_1_vtx_3();
	scroll_bowser_1_dl_f2_001_mesh_layer_5_vtx_0();
}
