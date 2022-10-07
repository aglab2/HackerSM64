#include "src/game/envfx_snow.h"

const GeoLayout sphere_sphere_geo[] = {
	GEO_CULLING_RADIUS(30000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sphere_sphere_sphere_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sphere_sphere_sphere_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sphere_sphere_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sphere_sphere_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
