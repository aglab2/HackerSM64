const Collision luigiman_airlock_door_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(12),
	COL_VERTEX(-331, -296, 42),
	COL_VERTEX(331, -296, 42),
	COL_VERTEX(331, 161, 42),
	COL_VERTEX(0, 161, 42),
	COL_VERTEX(-331, 161, 42),
	COL_VERTEX(331, 161, -31),
	COL_VERTEX(331, -296, -31),
	COL_VERTEX(-331, -296, -31),
	COL_VERTEX(-331, 161, -31),
	COL_VERTEX(0, 161, -31),
	COL_VERTEX(0, 405, 42),
	COL_VERTEX(0, 405, -31),
	COL_TRI_INIT(SURFACE_DEFAULT, 12),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 4, 0),
	COL_TRI(2, 3, 0),
	COL_TRI(5, 6, 7),
	COL_TRI(7, 8, 9),
	COL_TRI(7, 9, 5),
	COL_TRI(0, 7, 6),
	COL_TRI(0, 6, 1),
	COL_TRI(10, 4, 3),
	COL_TRI(2, 10, 3),
	COL_TRI(11, 9, 8),
	COL_TRI(5, 9, 11),
	COL_TRI_STOP(),
	COL_END()
};
