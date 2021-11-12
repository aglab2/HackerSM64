void scroll_castle_inside_dl_level_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 89;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_level_mesh_layer_1_vtx_11);

	deltaY = (int)(-0.6499999761581421 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_level_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 188;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_level_001_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.07999995350837708 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_inside_dl_level_002_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 46;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_level_002_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.3199999928474426 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_inside() {
	scroll_castle_inside_dl_level_mesh_layer_1_vtx_11();
	scroll_castle_inside_dl_level_001_mesh_layer_5_vtx_0();
	scroll_castle_inside_dl_level_002_mesh_layer_5_vtx_0();
}
