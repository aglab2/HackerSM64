void scroll_sts_mat_pss_dl__auto_9_f3d() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl__auto_9_f3d);
	shift_s(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_pss() {
	scroll_sts_mat_pss_dl__auto_9_f3d();
}
