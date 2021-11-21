#include "src/game/envfx_snow.h"

const GeoLayout core_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -11, 1, -29, core_Icosphere_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, core_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
