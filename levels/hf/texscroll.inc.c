void scroll_sts_mat_hf_dl_Green2_f3d() {
	Gfx *mat = segmented_to_virtual(mat_hf_dl_Green2_f3d);
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hf_dl__Color_005_2_f3d() {
	Gfx *mat = segmented_to_virtual(mat_hf_dl__Color_005_2_f3d);
	shift_t(mat, 17, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_hf_dl_ice_001() {
	Gfx *mat = segmented_to_virtual(mat_hf_dl_ice_001);
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_hf() {
	scroll_sts_mat_hf_dl_Green2_f3d();
	scroll_sts_mat_hf_dl__Color_005_2_f3d();
	scroll_sts_mat_hf_dl_ice_001();
}
