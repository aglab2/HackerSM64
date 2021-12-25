#include "src/game/envfx_snow.h"

const GeoLayout gate20_geo[] = {
	GEO_CULLING_RADIUS(2000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, gate20_Plane_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gate20_Plane_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, gate20_Plane_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, gate20_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, gate20_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, gate20_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
