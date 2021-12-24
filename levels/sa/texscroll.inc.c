void scroll_sa_dl_eye_002_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 16;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(sa_dl_eye_002_mesh_layer_1_vtx_2);

	deltaX = (int)(0.1899999976158142 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sa() {
	scroll_sa_dl_eye_002_mesh_layer_1_vtx_2();
}
