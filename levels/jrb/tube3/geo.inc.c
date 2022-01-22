#include "src/game/envfx_snow.h"

const GeoLayout tube3_geo[] = {
	GEO_CULLING_RADIUS(20000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tube3_c3_tube_002_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, tube3_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
