#include "src/game/envfx_snow.h"

const GeoLayout watergate_geo[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, watergate_Plane_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, watergate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
