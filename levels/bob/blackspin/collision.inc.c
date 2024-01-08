const Collision blackspin_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(13),
	COL_VERTEX(0, 64, 0),
	COL_VERTEX(-103, 64, 60),
	COL_VERTEX(0, 64, 119),
	COL_VERTEX(-103, 64, -60),
	COL_VERTEX(0, 64, -119),
	COL_VERTEX(103, 64, -60),
	COL_VERTEX(149, -75, -86),
	COL_VERTEX(0, -75, -172),
	COL_VERTEX(-149, -75, -86),
	COL_VERTEX(-149, -75, 86),
	COL_VERTEX(0, -75, 172),
	COL_VERTEX(103, 64, 60),
	COL_VERTEX(149, -75, 86),
	COL_TRI_INIT(SURFACE_DEFAULT, 18),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 3, 1),
	COL_TRI(0, 4, 3),
	COL_TRI(5, 4, 0),
	COL_TRI(6, 4, 5),
	COL_TRI(4, 6, 7),
	COL_TRI(7, 3, 4),
	COL_TRI(3, 7, 8),
	COL_TRI(8, 1, 3),
	COL_TRI(1, 8, 9),
	COL_TRI(9, 2, 1),
	COL_TRI(2, 9, 10),
	COL_TRI(10, 11, 2),
	COL_TRI(11, 10, 12),
	COL_TRI(6, 11, 12),
	COL_TRI(11, 6, 5),
	COL_TRI(11, 5, 0),
	COL_TRI(11, 0, 2),
	COL_TRI_STOP(),
	COL_END()
};