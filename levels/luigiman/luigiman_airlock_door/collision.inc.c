const Collision luigiman_airlock_door_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-332, -299, 43),
	COL_VERTEX(330, -299, 43),
	COL_VERTEX(330, 159, 43),
	COL_VERTEX(-1, 159, 43),
	COL_VERTEX(-332, 159, 43),
	COL_VERTEX(330, 159, -30),
	COL_VERTEX(330, -299, -30),
	COL_VERTEX(-332, -299, -30),
	COL_VERTEX(-332, 159, -30),
	COL_VERTEX(-1, 159, -30),
	COL_VERTEX(-1, 402, 43),
	COL_VERTEX(-1, 402, -30),
	COL_TRI_INIT(SURFACE_DEFAULT, 14),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 0),
	COL_TRI(2, 3, 0),
	COL_TRI(5, 6, 7),
	COL_TRI(7, 8, 9),
	COL_TRI(7, 9, 5),
	COL_TRI(10, 4, 3),
	COL_TRI(2, 10, 3),
	COL_TRI(11, 9, 8),
	COL_TRI(5, 9, 11),
	COL_TRI(2, 5, 11),
	COL_TRI(2, 11, 10),
	COL_TRI(10, 11, 8),
	COL_TRI(10, 8, 4),
	COL_TRI_STOP(),
	COL_END()
};