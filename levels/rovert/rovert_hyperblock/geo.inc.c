#include "src/game/envfx_snow.h"

const GeoLayout rovert_hyperblock_geo[] = {
	GEO_CULLING_RADIUS(200),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, rovert_hyperblock_Cube_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rovert_hyperblock_Cube_002_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_ALPHA, rovert_hyperblock_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, rovert_hyperblock_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
