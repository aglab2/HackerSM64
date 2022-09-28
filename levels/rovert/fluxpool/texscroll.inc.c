s32 time;
void scroll_fluxpool_poolmesh_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 64;
	int width = 64 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(fluxpool_poolmesh_mesh_layer_1_vtx_0);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		int mag = sqrtf(sqr(vertices[i].n.ob[0]) + sqr(vertices[i].n.ob[2]));
		vertices[i].n.ob[1] = sins((mag*300) + (time*1200))*50;
	}
	time--;
}

void scroll_rovert_level_geo_fluxpool() {
	scroll_fluxpool_poolmesh_mesh_layer_1_vtx_0();
}
