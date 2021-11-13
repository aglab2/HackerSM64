#include "src/game/envfx_snow.h"

const GeoLayout fireball_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, fireball_fireball_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_TRANSPARENT, 90, 0, 0, fireball_fireball_001_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fireball_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, fireball_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
