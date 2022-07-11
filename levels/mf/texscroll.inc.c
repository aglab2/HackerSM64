void scroll_sts_mat_mf_dl_Lava_f3d() {
	Gfx *mat = segmented_to_virtual(mat_mf_dl_Lava_f3d);
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_mf_dl_Waterfall_f3d() {
	Gfx *mat = segmented_to_virtual(mat_mf_dl_Waterfall_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_mf_dl_water() {
	Gfx *mat = segmented_to_virtual(mat_mf_dl_water);
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_mf_dl_f3d_material_001() {
	Gfx *mat = segmented_to_virtual(mat_mf_dl_f3d_material_001);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

int gMFCurrentScrollY = 0;
void scroll_mf_dl_mlavaline_mesh_layer_6_vtx_0() {
	int i = 0;
	int count = 424;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	int deltaY;
	Vtx *vertices = segmented_to_virtual(mf_dl_mlavaline_mesh_layer_6_vtx_0);

	deltaY = (int)(0.1599999964237213 * 0x20) % height;

	if (absi(gMFCurrentScrollY) > height) {
		deltaY -= (int)(absi(gMFCurrentScrollY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	gMFCurrentScrollY += deltaY;
}

void scroll_mf() {
	scroll_sts_mat_mf_dl_Lava_f3d();
	scroll_sts_mat_mf_dl_Waterfall_f3d();
	scroll_sts_mat_mf_dl_water();
	scroll_sts_mat_mf_dl_f3d_material_001();
	scroll_mf_dl_mlavaline_mesh_layer_6_vtx_0();
}
