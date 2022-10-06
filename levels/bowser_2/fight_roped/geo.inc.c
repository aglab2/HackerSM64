#include "src/game/envfx_snow.h"

const GeoLayout fight_roped_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, fight_roped_fight_004_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, fight_roped_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
