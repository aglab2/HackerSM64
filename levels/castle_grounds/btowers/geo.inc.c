#include "src/game/envfx_snow.h"

const GeoLayout btowers_geo[] = {
   GEO_CULLING_RADIUS(0x7fff),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, btowers_Untitled_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, btowers_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
