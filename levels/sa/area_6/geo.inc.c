#include "src/game/envfx_snow.h"

const GeoLayout sa_area_6_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ASM(0x00, geo_render_INFBG),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1306, 1517, -941, sa_dl_Area6Visual_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, sa_dl_Area6Visual_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1515, 1734, -3520, 0, 38, -90, sa_dl_CCCCcannon_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1508, 1734, -1530, 0, -37, -90, sa_dl_CCCCcannon_004_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -172, 1734, -1538, 0, -141, -90, sa_dl_CCCCcannon_005_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -158, 1734, -3457, 0, 131, -90, sa_dl_CCCCcannon_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 2220, 2585, -3248, 0, 90, -90, sa_dl_CCCCcannon_007_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 3244, 3495, 164, 0, -90, -90, sa_dl_CCCCcannon_008_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1306, 1517, -941, sa_dl_EndArea6_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sa_area_6[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, -500000, 0, -100, -500000, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, sa_area_6_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, sa_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};