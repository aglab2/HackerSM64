// 0x17000084

extern Gfx *geo_update_layer_transparency_envcolor(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout burn_smoke_geo[] = {
   GEO_NODE_START(),
   GEO_OPEN_NODE(),
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_envcolor),
      GEO_SWITCH_CASE(2, geo_switch_anim_state),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_SMOKE_TRANSPARENT /*bogus*/, burn_smoke_seg4_dl),
         GEO_DISPLAY_LIST(LAYER_SMOKE_ALPHA /*bogus*/, burn_smoke_seg4_dl),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
