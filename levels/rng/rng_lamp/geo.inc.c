#include "src/game/envfx_snow.h"

const GeoLayout rng_lamp_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rng_lamp_lamp_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rng_lamp_lamp_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rng_lamp_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, rng_lamp_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
