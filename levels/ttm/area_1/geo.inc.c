#include "src/game/envfx_snow.h"

const GeoLayout ttm_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_b_mesh_layer_1),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 5700, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ttm_dl_b_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_c_mesh_layer_1),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 5700, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, ttm_dl_c_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_c5_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_DL_ttm_1_0xe030390_Obj_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_DL_ttm_1_0xe030390_Obj_001_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_DL_ttm_1_0xe030390_Obj_003_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_OPAQUE, 90, 0, 0, ttm_dl_DL_ttm_1_0xe030390_Obj_004_mesh_layer_1),
		GEO_ROTATION_NODE_WITH_DL(LAYER_ALPHA, 90, 0, 0, ttm_dl_DL_ttm_1_0xe03a660_Obj_mesh_layer_4),
		GEO_ROTATION_NODE(LAYER_TRANSPARENT, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 5700, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, ttm_dl_DL_ttm_1_0xe03a660_Obj_001_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_ALPHA, 90, 0, 0, ttm_dl_DL_ttm_1_0xe03c6d8_Obj_mesh_layer_4),
		GEO_ASM(0, geo_cannon_circle_base),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout ttm_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND(BACKGROUND_C4, geo_skybox_main),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(14, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, ttm_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_LAVA_BUBBLES, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};