#include "src/game/envfx_snow.h"

const GeoLayout spiders_bee_angy_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_bee_angy_waterfally_bee_angy_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_bee_angy_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
