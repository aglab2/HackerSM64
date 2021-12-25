#include "src/game/envfx_snow.h"

const GeoLayout gate_rotat[] = {
	GEO_CULLING_RADIUS(0x1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, gate_rotat_gate_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, gate_rotat_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
