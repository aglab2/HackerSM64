#include "src/game/envfx_snow.h"

const GeoLayout dan_bp_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dan_bp_MainBP_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, dan_bp_MainBP_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dan_bp_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, dan_bp_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
