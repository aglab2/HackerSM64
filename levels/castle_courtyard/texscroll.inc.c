void scroll_castle_courtyard_dl_ow3_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 20;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_courtyard_dl_ow3_mesh_layer_1_vtx_4);

	deltaX = (int)(-0.04999995231628418 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_courtyard_dl_ow3_mesh_layer_1_vtx_20() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_courtyard_dl_ow3_mesh_layer_1_vtx_20);

	deltaY = (int)(0.1600000262260437 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_courtyard() {
	scroll_castle_courtyard_dl_ow3_mesh_layer_1_vtx_4();
	scroll_castle_courtyard_dl_ow3_mesh_layer_1_vtx_20();
}
