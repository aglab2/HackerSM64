const Collision spiders_cage_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(6),
	COL_VERTEX(-276, 457, -334),
	COL_VERTEX(-276, 0, -334),
	COL_VERTEX(276, 0, 334),
	COL_VERTEX(276, 453, 334),
	COL_VERTEX(111, 749, 135),
	COL_VERTEX(-111, 749, -135),
	COL_TRI_INIT(SURFACE_DEFAULT, 4),
	COL_TRI(0, 1, 2),
	COL_TRI(2, 3, 4),
	COL_TRI(4, 5, 0),
	COL_TRI(2, 4, 0),
	COL_TRI_STOP(),
	COL_END()
};