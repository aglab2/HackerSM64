#include "src/game/envfx_snow.h"

const GeoLayout rng_cactus2_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, rng_cactus2_cactus2_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rng_cactus2_cactus2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, rng_cactus2_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, rng_cactus2_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};