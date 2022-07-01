void scroll_wmotr_dl_Chireiden_Yukari_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 91;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Yukari_mesh_layer_1_vtx_0);

	deltaY = (int)(3.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_wmotr_dl__3_f3d() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl__3_f3d);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_wmotr_dl_Chireiden_Yukari_011_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 47;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Yukari_011_mesh_layer_1_vtx_0);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_wmotr_dl__8_f3d() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl__8_f3d);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_wmotr_dl_Chireiden_Yukari_012_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 83;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int timeX;
	float amplitudeX = 5.0;
	float frequencyX = 0.019999999552965164;
	float offsetX = 0.0;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 5.0;
	float frequencyY = 0.019999999552965164;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Yukari_012_mesh_layer_1_vtx_0);

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

void scroll_wmotr_dl_Chireiden_Patchouli_012_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 123;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Patchouli_012_mesh_layer_1_vtx_0);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr_dl_Chireiden_Nitori_007_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 57;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Nitori_007_mesh_layer_1_vtx_0);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_7() {
	int i = 0;
	int count = 39;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_7);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_10() {
	int i = 0;
	int count = 56;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_10);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 39;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_11);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_12() {
	int i = 0;
	int count = 53;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_12);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_wmotr_dl__16_f3d_002() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl__16_f3d_002);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_wmotr_dl__18_f3d_002() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl__18_f3d_002);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_wmotr_dl__19_f3d_001() {
	Gfx *mat = segmented_to_virtual(mat_wmotr_dl__19_f3d_001);
	shift_s(mat, 10, PACK_TILESIZE(0, 1));
	shift_t(mat, 10, PACK_TILESIZE(0, 1));
};

void scroll_wmotr_dl_chireiden_alice_mesh_layer_1_vtx_7() {
	int i = 0;
	int count = 9;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wmotr_dl_chireiden_alice_mesh_layer_1_vtx_7);

	deltaY = (int)(0.75 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_wmotr() {
	scroll_wmotr_dl_Chireiden_Yukari_mesh_layer_1_vtx_0();
	scroll_sts_mat_wmotr_dl__3_f3d();
	scroll_wmotr_dl_Chireiden_Yukari_011_mesh_layer_1_vtx_0();
	scroll_sts_mat_wmotr_dl__8_f3d();
	scroll_wmotr_dl_Chireiden_Yukari_012_mesh_layer_1_vtx_0();
	scroll_wmotr_dl_Chireiden_Patchouli_012_mesh_layer_1_vtx_0();
	scroll_wmotr_dl_Chireiden_Nitori_007_mesh_layer_1_vtx_0();
	scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_7();
	scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_10();
	scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_11();
	scroll_wmotr_dl_Chireiden_Aya_mesh_layer_1_vtx_12();
	scroll_sts_mat_wmotr_dl__16_f3d_002();
	scroll_sts_mat_wmotr_dl__18_f3d_002();
	scroll_sts_mat_wmotr_dl__19_f3d_001();
	scroll_wmotr_dl_chireiden_alice_mesh_layer_1_vtx_7();
}
