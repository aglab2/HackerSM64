#include "src/game/envfx_snow.h"

const GeoLayout warrow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, warrow_arrow_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, warrow_arrow_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};