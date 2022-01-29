void scroll_bob_dl_level_02_004_mesh_layer_1_vtx_2() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_02_004_mesh_layer_1_vtx_2);

	deltaY = (int)(-0.25999999046325684 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_02_004_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 6;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_02_004_mesh_layer_1_vtx_5);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_02_004_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_02_004_mesh_layer_1_vtx_6);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_1_mesh_layer_1_vtx_7() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_1_mesh_layer_1_vtx_7);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_2_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_2_mesh_layer_1_vtx_1);

	deltaY = (int)(-1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_2_001_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 6;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_2_001_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.16999995708465576 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_level_3_s_mesh_layer_1_vtx_1() {
	int i = 0;
	int count = 52;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_3_s_mesh_layer_1_vtx_1);

	deltaY = (int)(-0.25999999046325684 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_3_s_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 5;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_3_s_mesh_layer_1_vtx_3);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_c1_a2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 20;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_c1_a2_mesh_layer_1_vtx_0);

	deltaX = (int)(0.6700000166893005 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_c1_a2_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 4;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_c1_a2_mesh_layer_1_vtx_4);

	deltaY = (int)(0.4300000071525574 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_c1_a2_mesh_layer_1_vtx_6() {
	int i = 0;
	int count = 11;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_c1_a2_mesh_layer_1_vtx_6);

	deltaX = (int)(0.6700000166893005 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bob_dl_c1_a3_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_c1_a3_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.16999995708465576 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob_dl_level_02_008_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_level_02_008_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.25999999046325684 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bob() {
	scroll_bob_dl_level_02_004_mesh_layer_1_vtx_2();
	scroll_bob_dl_level_02_004_mesh_layer_1_vtx_5();
	scroll_bob_dl_level_02_004_mesh_layer_1_vtx_6();
	scroll_bob_dl_level_1_mesh_layer_1_vtx_7();
	scroll_bob_dl_level_2_mesh_layer_1_vtx_1();
	scroll_bob_dl_level_2_001_mesh_layer_5_vtx_0();
	scroll_bob_dl_level_3_s_mesh_layer_1_vtx_1();
	scroll_bob_dl_level_3_s_mesh_layer_1_vtx_3();
	scroll_bob_dl_c1_a2_mesh_layer_1_vtx_0();
	scroll_bob_dl_c1_a2_mesh_layer_1_vtx_4();
	scroll_bob_dl_c1_a2_mesh_layer_1_vtx_6();
	scroll_bob_dl_c1_a3_mesh_layer_1_vtx_0();
	scroll_bob_dl_level_02_008_mesh_layer_1_vtx_0();
}
