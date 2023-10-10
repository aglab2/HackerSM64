#include "src/game/envfx_snow.h"

extern Gfx *geo_update_layer_transparency_envcolor2(s32 callContext, struct GraphNode *node, UNUSED void *context);
const GeoLayout death_penguin_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
         GEO_ASM(GEO_TRANSPARENCY_MODE_NORMAL, geo_update_layer_transparency_envcolor2),
         GEO_SWITCH_CASE(2, geo_switch_anim_state),
         GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, death_penguin_Plane_001_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, death_penguin_Plane_001_mesh_layer_5),
         GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
