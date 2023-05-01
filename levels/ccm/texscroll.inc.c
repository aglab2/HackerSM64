void scroll_ccm_dl_Plane_mesh_layer_7_vtx_0() {
	int i = 0;
	int count = 8;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Plane_mesh_layer_7_vtx_0);

	deltaX = (int)(0.2800000309944153 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm_dl_Plane_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 9;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ccm_dl_Plane_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.3100000023841858 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ccm() {
	scroll_ccm_dl_Plane_mesh_layer_7_vtx_0();
	scroll_ccm_dl_Plane_001_mesh_layer_5_vtx_0();
};
