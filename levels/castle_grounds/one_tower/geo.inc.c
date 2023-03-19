#include "src/game/envfx_snow.h"

const GeoLayout one_tower_geo[] = {
   GEO_CULLING_RADIUS(0x7fff),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, one_tower_one_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, one_tower_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
