#include "src/game/envfx_snow.h"

const GeoLayout luigiman_airlock_door_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, luigiman_airlock_door_Airlock_Door_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, luigiman_airlock_door_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
