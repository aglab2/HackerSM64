void scroll_ccm_dl_c4_mesh_layer_1_vtx_14() {
	int i = 0;
	int count = 14;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ccm_dl_c4_mesh_layer_1_vtx_14);

	deltaY = (int)(-0.7099999189376831 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ccm_dl__auto_8_f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl__auto_8_f3d_layer1);
	shift_t(mat, 35, PACK_TILESIZE(0, 1));
};

void scroll_ccm_dl_water_thing_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 50;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 1.4800000190734863;
	float frequencyX = 0.19000017642974854;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 0.8799999952316284;
	float frequencyY = -0.14000001549720764;
	float offsetY = 0.41999998688697815;
	Vtx *vertices = segmented_to_virtual(ccm_dl_water_thing_mesh_layer_5_vtx_0);

	deltaX = (int)(amplitudeX * frequencyX * coss((frequencyX * timeX + offsetX) * (1024 * 16 - 1) / 6.28318530718) * 0x20);
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	timeX += 1;	currentY += deltaY;	timeY += 1;
}

void scroll_ccm() {
	scroll_ccm_dl_c4_mesh_layer_1_vtx_14();
	scroll_sts_mat_ccm_dl__auto_8_f3d_layer1();
	scroll_ccm_dl_water_thing_mesh_layer_5_vtx_0();
}
