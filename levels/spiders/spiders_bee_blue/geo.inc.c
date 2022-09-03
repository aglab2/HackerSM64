#include "src/game/envfx_snow.h"

const GeoLayout spiders_bee_blue_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_bee_blue_waterfally_bee_blue_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, spiders_bee_blue_waterfally_bee_blue_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_bee_blue_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, spiders_bee_blue_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
