void scroll_castle_inside_dl_tower_mesh_layer_1_vtx_23() {
	int i = 0;
	int count = 8;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_tower_mesh_layer_1_vtx_23);

	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_tower_005_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 12;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_tower_005_mesh_layer_4_vtx_0);

	deltaY = (int)(0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_tower_006_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 14;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_tower_006_mesh_layer_5_vtx_0);

	deltaY = (int)(-0.28999996185302734 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_tower_007_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 5;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_tower_007_mesh_layer_5_vtx_0);

	deltaY = (int)(0.3100000023841858 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_water_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_water_mesh_layer_5_vtx_0);

	deltaY = (int)(0.2200000286102295 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside_dl_waterbox2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 12;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(castle_inside_dl_waterbox2_mesh_layer_5_vtx_0);

	deltaY = (int)(0.2200000286102295 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_castle_inside() {
	scroll_castle_inside_dl_tower_mesh_layer_1_vtx_23();
	scroll_castle_inside_dl_tower_005_mesh_layer_4_vtx_0();
	scroll_castle_inside_dl_tower_006_mesh_layer_5_vtx_0();
	scroll_castle_inside_dl_tower_007_mesh_layer_5_vtx_0();
	scroll_castle_inside_dl_water_mesh_layer_5_vtx_0();
	scroll_castle_inside_dl_waterbox2_mesh_layer_5_vtx_0();
};
