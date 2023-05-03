void scroll_hmc_dl_DL_hmc_1_0xe0284b0_Obj_002_mesh_layer_1_vtx_10() {
	int i = 0;
	int count = 24;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_DL_hmc_1_0xe0284b0_Obj_002_mesh_layer_1_vtx_10);

	deltaY = (int)(0.3700000047683716 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc() {
	scroll_hmc_dl_DL_hmc_1_0xe0284b0_Obj_002_mesh_layer_1_vtx_10();
};
