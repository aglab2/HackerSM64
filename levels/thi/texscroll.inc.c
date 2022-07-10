void scroll_sts_mat_thi_dl__9_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl__9_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl__8_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl__8_f3d);
	shift_t_down(mat, 11, PACK_TILESIZE(0, 4));
};

void scroll_sts_mat_thi_dl__10_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl__10_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl_Lava_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl_Lava_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl_PlatformsWaterfallRed_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl_PlatformsWaterfallRed_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl_PlatformsWaterfallBlue_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl_PlatformsWaterfallBlue_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl_PlatformsWaterfallGreen_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl_PlatformsWaterfallGreen_f3d);
	shift_t(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_sts_mat_thi_dl__auto_18_f3d() {
	Gfx *mat = segmented_to_virtual(mat_thi_dl__auto_18_f3d);
	shift_t_down(mat, 18, PACK_TILESIZE(0, 1));
};

void scroll_thi() {
	scroll_sts_mat_thi_dl__9_f3d();
	scroll_sts_mat_thi_dl__8_f3d();
	scroll_sts_mat_thi_dl__10_f3d();
	scroll_sts_mat_thi_dl_Lava_f3d();
	scroll_sts_mat_thi_dl_PlatformsWaterfallRed_f3d();
	scroll_sts_mat_thi_dl_PlatformsWaterfallBlue_f3d();
	scroll_sts_mat_thi_dl_PlatformsWaterfallGreen_f3d();
	scroll_sts_mat_thi_dl__auto_18_f3d();
}
