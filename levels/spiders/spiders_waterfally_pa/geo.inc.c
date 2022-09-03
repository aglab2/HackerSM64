#include "src/game/envfx_snow.h"

const GeoLayout spiders_waterfally_pa_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_waterfally_pa_waterfally_pa_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_waterfally_pa_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
