void scroll_sts_mat_ab_dl_water_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ab_dl_water_layer5);
	shift_t_down(mat, 13, PACK_TILESIZE(0, 1));
	shift_s(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_ab_dl__16_f3d_layer5() {
	Gfx *mat = segmented_to_virtual(mat_ab_dl__16_f3d_layer5);
	shift_s(mat, 13, PACK_TILESIZE(0, 2));
	shift_t_down(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_ab_dl_Plane_001_mesh_layer_1_vtx_20() {
	int i = 0;
	int count = 7;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ab_dl_Plane_001_mesh_layer_1_vtx_20);

	deltaY = (int)(0.40000003576278687 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_ab_dl__9_f3d() {
	Gfx *mat = segmented_to_virtual(mat_ab_dl__9_f3d);
	shift_s(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_ab_dl_Plane_002_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ab_dl_Plane_002_mesh_layer_1_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ab_dl_Plane_003_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 12;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ab_dl_Plane_003_mesh_layer_1_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ab_dl_Plane_004_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ab_dl_Plane_004_mesh_layer_1_vtx_0);

	deltaX = (int)(0.3400000333786011 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ab_dl_Plane_007_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 52;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ab_dl_Plane_007_mesh_layer_6_vtx_0);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ab_dl_zw_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 177;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ab_dl_zw_mesh_layer_5_vtx_0);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ab_dl_zw_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 12;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ab_dl_zw_mesh_layer_5_vtx_1);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ab_dl_Azure_Abyss2_010_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 783;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(ab_dl_Azure_Abyss2_010_mesh_layer_1_vtx_6);

	deltaY = (int)(0.40000003576278687 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_ab_dl_Plane_005_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 24;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(ab_dl_Plane_005_mesh_layer_1_vtx_0);

	deltaX = (int)(0.3400000333786011 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_ab() {
	scroll_sts_mat_ab_dl_water_layer5();
	scroll_sts_mat_ab_dl__16_f3d_layer5();
	scroll_ab_dl_Plane_001_mesh_layer_1_vtx_20();
	scroll_sts_mat_ab_dl__9_f3d();
	scroll_ab_dl_Plane_002_mesh_layer_1_vtx_1();
	scroll_ab_dl_Plane_003_mesh_layer_1_vtx_1();
	scroll_ab_dl_Plane_004_mesh_layer_1_vtx_0();
	scroll_ab_dl_Plane_007_mesh_layer_6_vtx_0();
	scroll_ab_dl_zw_mesh_layer_5_vtx_0();
	scroll_ab_dl_zw_mesh_layer_5_vtx_1();
	scroll_ab_dl_Azure_Abyss2_010_mesh_layer_1_vtx_6();
	scroll_ab_dl_Plane_005_mesh_layer_1_vtx_0();
}
