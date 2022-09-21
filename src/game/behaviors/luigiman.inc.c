void luigiman_rings_init()
{

}

extern const Collision luigiman_rings_collision[];
void luigiman_rings_loop(void) {
    o->oMoveAngleYaw += 0x2F;

    load_object_collision_model();
}