const Collision hf_bridge2_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(14),
	COL_VERTEX(-2309, 127, 401),
	COL_VERTEX(-1760, 436, 401),
	COL_VERTEX(-1760, 436, -349),
	COL_VERTEX(-2309, 127, -324),
	COL_VERTEX(-902, 585, 401),
	COL_VERTEX(-902, 585, -370),
	COL_VERTEX(1541, 585, -401),
	COL_VERTEX(1541, 585, 401),
	COL_VERTEX(1925, 395, 401),
	COL_VERTEX(1925, 395, -401),
	COL_VERTEX(2309, -266, -401),
	COL_VERTEX(2309, -266, 401),
	COL_VERTEX(2309, -585, -401),
	COL_VERTEX(2309, -585, 401),
	COL_TRI_INIT(SURFACE_HARD_NOT_SLIPPERY, 12),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(2, 1, 4),
	COL_TRI(2, 4, 5),
	COL_TRI(6, 5, 4),
	COL_TRI(6, 4, 7),
	COL_TRI(7, 8, 9),
	COL_TRI(7, 9, 6),
	COL_TRI(10, 9, 8),
	COL_TRI(10, 8, 11),
	COL_TRI(12, 10, 11),
	COL_TRI(12, 11, 13),
	COL_TRI_STOP(),
	COL_END()
};