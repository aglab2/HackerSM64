void scroll_luigiman_dl_Koopa_Interior_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 55;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(luigiman_dl_Koopa_Interior_mesh_layer_1_vtx_5);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_luigiman_dl_Toad_Interior_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 39;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(luigiman_dl_Toad_Interior_mesh_layer_1_vtx_0);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_luigiman() {
	scroll_luigiman_dl_Koopa_Interior_mesh_layer_1_vtx_5();
	scroll_luigiman_dl_Toad_Interior_mesh_layer_1_vtx_0();
}
