#include "src/game/envfx_snow.h"

const GeoLayout triarc_rock_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, triarc_rock_rock_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, triarc_rock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
