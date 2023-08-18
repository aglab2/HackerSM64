void scroll_ddd_dl_DL_ddd_1_0xe02c100_Obj_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 13;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ddd_dl_DL_ddd_1_0xe02c100_Obj_001_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.31999993324279785 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ddd() {
	scroll_ddd_dl_DL_ddd_1_0xe02c100_Obj_001_mesh_layer_5_vtx_0();
};
