// 0x16000FE8

extern Gfx tree_grass_Tree_temp_climate_008_mesh[];
extern Gfx tree_grass2_Tree_temp_climate_018_mesh[];
extern Gfx tree_grass3_Tree_temp_climate_017_mesh[];
extern Gfx tree_grass4_Tree_temp_climate_010_mesh[];
extern Gfx tree_tropics__Tree_Tropic_001_mesh[];
extern Gfx tree_winter__Tree_Winter_015_mesh[];
extern Gfx tree_winter2__Tree_Winter_004_mesh[];

extern Gfx *geo_update_layer_transparency_hd_tree(s32 callContext, struct GraphNode *node, UNUSED void *context);

const GeoLayout bubbly_tree_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_bubbly),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_bubbly_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_grass_Tree_temp_climate_008_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_grass_Tree_temp_climate_008_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16001000
const GeoLayout spiky_tree_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_spiky),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_spiky_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_grass2_Tree_temp_climate_018_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_grass2_Tree_temp_climate_018_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};

const GeoLayout spiky_tree2_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_spiky2),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_spiky2_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_grass3_Tree_temp_climate_017_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_grass3_Tree_temp_climate_017_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16001018
const GeoLayout snow_tree_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_snowy_pine),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_snowy_pine_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_winter2__Tree_Winter_004_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_winter2__Tree_Winter_004_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};

const GeoLayout snow_tree2_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_snowy_pine2),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_snowy_pine2_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_winter__Tree_Winter_015_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_winter__Tree_Winter_015_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16001048
const GeoLayout palm_tree_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_palm2),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_palm2_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_tropics__Tree_Tropic_001_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_tropics__Tree_Tropic_001_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};

// 0x16001048
const GeoLayout palm_tree2_geo[] = {
   GEO_CULLING_RADIUS(800),
   GEO_OPEN_NODE(),
#ifdef OBJ_OPACITY_BY_CAM_DIST
      GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_hd_tree),
      GEO_SWITCH_CASE(4, geo_switch_anim_state),
      GEO_OPEN_NODE(),
#endif
         GEO_DISPLAY_LIST(LAYER_ALPHA, tree_seg3_dl_palm2),
#ifdef OBJ_OPACITY_BY_CAM_DIST
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_seg3_dl_palm2_transparent),
         
         GEO_DISPLAY_LIST(LAYER_OPAQUE, tree_grass4_Tree_temp_climate_010_mesh),
         GEO_DISPLAY_LIST(LAYER_TRANSPARENT, tree_grass4_Tree_temp_climate_010_mesh),
      GEO_CLOSE_NODE(),
#endif
   GEO_CLOSE_NODE(),
   GEO_END(),
};
