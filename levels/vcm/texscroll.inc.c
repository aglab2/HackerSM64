void scroll_sts_mat_vcm_dl_scrollnum3_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollnum3_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_vcm_dl_scrollnum2_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollnum2_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_vcm_dl_scrollnum1_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollnum1_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_vcm_dl_scrollred_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollred_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_vcm_dl_scrollblue_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollblue_f3d);
	shift_t(mat, 11, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_vcm_dl_scrollredpipe_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollredpipe_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_vcm_dl_scrollwaves_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollwaves_f3d);
	shift_t(mat, 11, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_vcm_dl_arrow1() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_arrow1);
	shift_t_down(mat, 18, PACK_TILESIZE(0, 3));
};

void scroll_sts_mat_vcm_dl_arrow2() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_arrow2);
	shift_t_down(mat, 18, PACK_TILESIZE(0, 3));
};

void scroll_sts_mat_vcm_dl_scrollgray_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scrollgray_f3d);
	shift_t(mat, 11, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_vcm_dl_scroller() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl_scroller);
	shift_s(mat, 18, PACK_TILESIZE(0, 2));
};

void scroll_sts_mat_vcm_dl__3_f3d() {
	Gfx *mat = segmented_to_virtual(mat_vcm_dl__3_f3d);
	shift_t(mat, 11, PACK_TILESIZE(0, 2));
};

void scroll_vcm() {
	scroll_sts_mat_vcm_dl_scrollnum3_f3d();
	scroll_sts_mat_vcm_dl_scrollnum2_f3d();
	scroll_sts_mat_vcm_dl_scrollnum1_f3d();
	scroll_sts_mat_vcm_dl_scrollred_f3d();
	scroll_sts_mat_vcm_dl_scrollblue_f3d();
	scroll_sts_mat_vcm_dl_scrollredpipe_f3d();
	scroll_sts_mat_vcm_dl_scrollwaves_f3d();
	scroll_sts_mat_vcm_dl_arrow1();
	scroll_sts_mat_vcm_dl_arrow2();
	scroll_sts_mat_vcm_dl_scrollgray_f3d();
	scroll_sts_mat_vcm_dl_scroller();
	scroll_sts_mat_vcm_dl__3_f3d();
}
