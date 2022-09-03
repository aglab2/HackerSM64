#include "src/game/envfx_snow.h"

const GeoLayout spiders_waterfally_nest_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_waterfally_nest_waterfally_nest_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, spiders_waterfally_nest_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
