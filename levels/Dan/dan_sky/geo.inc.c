#include "src/game/envfx_snow.h"

const GeoLayout dan_sky_geo[] = {
	GEO_CULLING_RADIUS(32767),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dan_sky_sky_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, dan_sky_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
