void scroll_castle_inside_dl_sphgeres_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 4858;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_sphgeres_mesh_layer_6_vtx_0);

	deltaX = (int)(0.06999999284744263 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_inside_dl_sphgeres_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 184;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_sphgeres_mesh_layer_1_vtx_2);

	deltaY = (int)(-0.04999995976686478 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_Triarc_Bridge_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 241;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_Triarc_Bridge_mesh_layer_6_vtx_0);

	deltaX = (int)(0.06999999284744263 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_castle_inside() {
	scroll_castle_inside_dl_sphgeres_mesh_layer_6_vtx_0();
	scroll_castle_inside_dl_sphgeres_mesh_layer_1_vtx_2();
	scroll_castle_inside_dl_Triarc_Bridge_mesh_layer_6_vtx_0();
}
