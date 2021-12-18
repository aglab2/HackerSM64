void scroll_wf_dl_zbg_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 16;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_zbg_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.07999998331069946 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wf() {
	scroll_wf_dl_zbg_mesh_layer_5_vtx_0();
}
