void scroll_bob_dl_golfer_mesh_layer_1_vtx_18() {
	int i = 0;
	int count = 59;
	int width = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bob_dl_golfer_mesh_layer_1_vtx_18);

	deltaX = (int)(0.12999999523162842 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_gfx_mat_bob_dl__17_f3d() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl__17_f3d);

	shift_t(mat, 15, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bob_dl__29_f3d() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl__29_f3d);

	shift_t(mat, 13, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bob_dl__50_f3d() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl__50_f3d);

	shift_s(mat, 13, PACK_TILESIZE(0, 1));

};

void scroll_bob() {
	scroll_bob_dl_golfer_mesh_layer_1_vtx_18();
	scroll_gfx_mat_bob_dl__17_f3d();
	scroll_gfx_mat_bob_dl__29_f3d();
	scroll_gfx_mat_bob_dl__50_f3d();
};
