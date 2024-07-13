void scroll_gfx_mat_castle_courtyard_dl_f3dlite_material_layer1_area1() {
	Gfx *mat = segmented_to_virtual(mat_castle_courtyard_dl_f3dlite_material_layer1_area1);

	shift_t(mat, 21, PACK_TILESIZE(0, 4));

};

void scroll_castle_courtyard() {
	scroll_gfx_mat_castle_courtyard_dl_f3dlite_material_layer1_area1();
};
