#include "src/game/envfx_snow.h"

const GeoLayout chiaki_geo[] = {
	GEO_CULLING_RADIUS(10000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chiaki_Plane_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, chiaki_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
