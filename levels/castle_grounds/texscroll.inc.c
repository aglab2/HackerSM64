void scroll_gfx_mat_castle_grounds_dl_Shape_259_f3d() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_Shape_259_f3d);

	shift_s(mat, 12, PACK_TILESIZE(0, -1));

};

void scroll_gfx_mat_castle_grounds_dl_Shape_258_f3d() {
	Gfx *mat = segmented_to_virtual(mat_castle_grounds_dl_Shape_258_f3d);

	shift_s(mat, 12, PACK_TILESIZE(0, -1));

};

void scroll_castle_grounds() {
	scroll_gfx_mat_castle_grounds_dl_Shape_259_f3d();
	scroll_gfx_mat_castle_grounds_dl_Shape_258_f3d();
};
