void scroll_jrb_dl_DL_jrb_1_0xe032860_Obj_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 23;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(jrb_dl_DL_jrb_1_0xe032860_Obj_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.23000001907348633 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_jrb() {
	scroll_jrb_dl_DL_jrb_1_0xe032860_Obj_mesh_layer_5_vtx_0();
};
