// 0x07029508 - 0x070295F8
const Collision rr_seg7_collision_07029508[] = {
    COL_INIT(),
    COL_VERTEX_INIT(0x10),
    COL_VERTEX(-578, 0, -578), // 0
    COL_VERTEX(-578, 205, -578), // 1
    COL_VERTEX(0, 205, -818),  // 2
    COL_VERTEX(0, 0, -818), // 3
    COL_VERTEX(579, 0, 579), // 4
    COL_VERTEX(819, 0, 0), // 5
    COL_VERTEX(819, 205, 0), // 6
    COL_VERTEX(579, 205, 579), // 7
    COL_VERTEX(-818, 205, 0), // 8
    COL_VERTEX(-818, 0, 0), // 9
    COL_VERTEX(0, 205, 819), // 10
    COL_VERTEX(-578, 0, 579), // 11
    COL_VERTEX(0, 0, 819), // 12
    COL_VERTEX(-578, 205, 579), // 13
    COL_VERTEX(579, 205, -578), // 14
    COL_VERTEX(579, 0, -578), // 15
    COL_TRI_INIT(SURFACE_VERY_SLIPPERY, 22 + 6),
    COL_TRI(10, 11, 12),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),
    COL_TRI(4, 5, 6),
    COL_TRI(4, 6, 7),
    COL_TRI(0, 8, 1),
    COL_TRI(0, 9, 8),
    COL_TRI(14, 2, 1), // !
    COL_TRI(10, 13, 11),
    COL_TRI(4, 7, 10),
    COL_TRI(4, 10, 12),
    COL_TRI(14, 7, 6), // !
    COL_TRI(14, 10, 7), // !
    COL_TRI(14, 13, 10), // !
    COL_TRI(14, 8, 13), // !
    COL_TRI(14, 1, 8), // !
    COL_TRI(13, 8, 9),
    COL_TRI(13, 9, 11),
    COL_TRI(2, 14, 3),
    COL_TRI(14, 15, 3),
    COL_TRI(5, 14, 6),
    COL_TRI(5, 15, 14),

    // 1 -> 0
    // 2 -> 3
    // 6 -> 5
    // 7 -> 4
    // 8 -> 9
    // 10 -> 12
    // 13 -> 0
    // 14 -> 15
    COL_TRI(3, 15, 0), // !
    COL_TRI(4, 15, 5), // !
    COL_TRI(12, 15, 4), // !
    COL_TRI(0, 15, 12), // !
    COL_TRI(9, 15, 0), // !
    COL_TRI(0, 15, 9), // !

    COL_TRI_STOP(),
    COL_END(),
};
