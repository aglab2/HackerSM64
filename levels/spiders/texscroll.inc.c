void scroll_sts_mat_spiders_dl_Material4_f3d() {
	Gfx *mat = segmented_to_virtual(mat_spiders_dl_Material4_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_spiders_dl_Material14_f3d() {
	Gfx *mat = segmented_to_virtual(mat_spiders_dl_Material14_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_spiders_dl_Material21_f3d() {
	Gfx *mat = segmented_to_virtual(mat_spiders_dl_Material21_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_spiders_dl__22_f3d() {
	Gfx *mat = segmented_to_virtual(mat_spiders_dl__22_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 2));
};

void scroll_spiders() {
	scroll_sts_mat_spiders_dl_Material4_f3d();
	scroll_sts_mat_spiders_dl_Material14_f3d();
	scroll_sts_mat_spiders_dl_Material21_f3d();
	scroll_sts_mat_spiders_dl__22_f3d();
}
