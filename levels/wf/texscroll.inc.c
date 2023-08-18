void scroll_wf_dl_z_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 68;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_z_001_mesh_layer_5_vtx_0);

	deltaX = (int)(0.3100000023841858 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf() {
	scroll_wf_dl_z_001_mesh_layer_5_vtx_0();
};
