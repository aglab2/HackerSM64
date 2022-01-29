// 0x16000EA0

extern Gfx *omm_geo_star_enable_effects(s32 callContext, struct GraphNode *node, int context);
extern Gfx *omm_geo_star_update_ray(s32 callContext, struct GraphNode *node, void* context);
extern Gfx *omm_geo_star_update_glow(s32 callContext, struct GraphNode *node, void* context);

static const GeoLayout omm_geo_star_effects[] = {
    GEO_ASM(0, omm_geo_star_enable_effects),
    GEO_SCALE(0, 0x10000),
    GEO_OPEN_NODE(),
        GEO_SCALE(0, 0x4000),
        GEO_OPEN_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(0, omm_geo_star_update_glow),
                GEO_TRANSLATE_NODE(0, 0, 0, 0),
                GEO_OPEN_NODE(),
                    GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_glow_gfx),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(0, omm_geo_star_update_ray),
                GEO_SCALE(0, 0x10000),
                GEO_OPEN_NODE(),
                    GEO_ROTATION_NODE(0, 0, 0, 0),
                    GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_ray_0_gfx),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(1, omm_geo_star_update_ray),
                GEO_SCALE(0, 0x10000),
                GEO_OPEN_NODE(),
                    GEO_ROTATION_NODE(0, 0, 0, 0),
                    GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_ray_1_gfx),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(2, omm_geo_star_update_ray),
                GEO_SCALE(0, 0x10000),
                GEO_OPEN_NODE(),
                    GEO_ROTATION_NODE(0, 0, 0, 0),
                    GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_ray_2_gfx),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(3, omm_geo_star_update_ray),
                GEO_SCALE(0, 0x10000),
                GEO_OPEN_NODE(),
                    GEO_ROTATION_NODE(0, 0, 0, 0),
                    GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_ray_3_gfx),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(4, omm_geo_star_update_ray),
                GEO_SCALE(0, 0x10000),
                GEO_OPEN_NODE(),
                    GEO_ROTATION_NODE(0, 0, 0, 0),
                    GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_ray_4_gfx),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
            GEO_OPEN_NODE(),
                GEO_ASM(5, omm_geo_star_update_ray),
                GEO_SCALE(0, 0x10000),
                GEO_OPEN_NODE(),
                    GEO_ROTATION_NODE(0, 0, 0, 0),
                    GEO_OPEN_NODE(),
                        GEO_DISPLAY_LIST(LAYER_TRANSPARENT, omm_star_ray_5_gfx),
                    GEO_CLOSE_NODE(),
                GEO_CLOSE_NODE(),
            GEO_CLOSE_NODE(),
        GEO_CLOSE_NODE(),
    GEO_CLOSE_NODE(),
    GEO_RETURN(),
};

const GeoLayout star_geo[] = {
   GEO_SHADOW(SHADOW_CIRCLE_4_VERTS, 0x9B, 100),
   GEO_OPEN_NODE(),
      GEO_SCALE(0x00, 16384),
      GEO_OPEN_NODE(),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_OPAQUE, star_seg3_dl_body),
         GEO_DISPLAY_LIST(LAYER_OCCLUDE_SILHOUETTE_ALPHA, star_seg3_dl_eyes),
      GEO_CLOSE_NODE(),
	  GEO_CULL(10, -10, -20000, 20000, -20000, 20000),
      GEO_OPEN_NODE(),
        GEO_BILLBOARD(),
        GEO_OPEN_NODE(),
            GEO_BRANCH(1, omm_geo_star_effects),
        GEO_CLOSE_NODE(),
      GEO_CLOSE_NODE(),
   GEO_CLOSE_NODE(),
   GEO_END(),
};
