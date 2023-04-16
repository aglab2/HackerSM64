#include "src/game/envfx_snow.h"

const GeoLayout tree_root_shadow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tree_root_shadow_tree_root_001_mesh_layer_6),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, tree_root_shadow_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
