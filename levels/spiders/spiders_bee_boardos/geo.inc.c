#include "src/game/envfx_snow.h"

const GeoLayout spiders_bee_boardos_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_bee_boardos_waterfally_boardos_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_bee_boardos_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
