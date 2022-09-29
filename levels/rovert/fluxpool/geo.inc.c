#include "src/game/envfx_snow.h"

const GeoLayout fluxpool_geo[] = {
	GEO_CULLING_RADIUS(1000),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fluxpool_poolmesh_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, fluxpool_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
