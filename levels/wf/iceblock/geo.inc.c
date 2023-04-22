#include "src/game/envfx_snow.h"

const GeoLayout iceblock_geo[] = {
   GEO_CULLING_RADIUS(1200),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, iceblock_iceblock_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, iceblock_iceblock_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, iceblock_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, iceblock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
