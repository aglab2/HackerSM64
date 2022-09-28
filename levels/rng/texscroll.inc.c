void scroll_sts_mat_rng_dl_f3d_material_001() {
	Gfx *mat = segmented_to_virtual(mat_rng_dl_f3d_material_001);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_rng_dl__6_f3d() {
	Gfx *mat = segmented_to_virtual(mat_rng_dl__6_f3d);
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_rng_dl_rbd_004_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 149;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(rng_dl_rbd_004_mesh_layer_1_vtx_5);

	deltaY = (int)(-0.13999998569488525 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_sts_mat_rng_dl__66_f3d() {
	Gfx *mat = segmented_to_virtual(mat_rng_dl__66_f3d);
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_rng_dl__63_f3d() {
	Gfx *mat = segmented_to_virtual(mat_rng_dl__63_f3d);
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_rng() {
	scroll_sts_mat_rng_dl_f3d_material_001();
	scroll_sts_mat_rng_dl__6_f3d();
	scroll_rng_dl_rbd_004_mesh_layer_1_vtx_5();
	scroll_sts_mat_rng_dl__66_f3d();
	scroll_sts_mat_rng_dl__63_f3d();
}
