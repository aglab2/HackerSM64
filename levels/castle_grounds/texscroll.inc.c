void scroll_sts_mat_castle_grounds_dl_TowerGround_f3d_layer1() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_TowerGround_f3d_layer1);
	shift_t(mat, 21, PACK_TILESIZE(0, 1));
};

void scroll_castle_grounds_dl_Lake_of_the_East_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 4;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Lake_of_the_East_mesh_layer_5_vtx_0);

	deltaX = (int)(-0.13999998569488525 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_sts_mat_castle_grounds_dl__32_f3d() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl__32_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_castle_grounds_dl_Sphere_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 58;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Sphere_mesh_layer_5_vtx_0);

	deltaY = (int)(0.2200000286102295 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_grounds_dl_Sphere_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 58;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_grounds_dl_Sphere_mesh_layer_5_vtx_1);

	deltaY = (int)(-0.16999995708465576 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_grounds() {
	scroll_sts_mat_castle_grounds_dl_TowerGround_f3d_layer1();
	scroll_castle_grounds_dl_Lake_of_the_East_mesh_layer_5_vtx_0();
	scroll_sts_mat_castle_grounds_dl__32_f3d();
	scroll_castle_grounds_dl_Sphere_mesh_layer_5_vtx_0();
	scroll_castle_grounds_dl_Sphere_mesh_layer_5_vtx_1();
}
