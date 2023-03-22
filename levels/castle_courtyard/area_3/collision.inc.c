const Collision castle_courtyard_area_3_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(4),
	COL_VERTEX(-276, 0, -273),
	COL_VERTEX(-276, 0, 273),
	COL_VERTEX(270, 0, 273),
	COL_VERTEX(270, 0, -273),
	COL_TRI_INIT(SURFACE_DEFAULT, 2),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI_STOP(),
	COL_END()
};
