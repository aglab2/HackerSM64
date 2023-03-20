#include "src/game/envfx_snow.h"

const GeoLayout disaster_bridge_geo[] = {
   GEO_CULLING_RADIUS(0x7fff),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, disaster_bridge_briodge_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, disaster_bridge_briodge_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, disaster_bridge_material_revert_render_settings),
		// GEO_DISPLAY_LIST(LAYER_ALPHA, disaster_bridge_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
