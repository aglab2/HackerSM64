#include "src/game/envfx_snow.h"

const GeoLayout rovert_gate_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, rovert_gate_Cylinder_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, rovert_gate_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
