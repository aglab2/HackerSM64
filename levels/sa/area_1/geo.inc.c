#include "src/game/envfx_snow.h"

const GeoLayout sa_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
<<<<<<< Updated upstream
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -503, 1345, -1777, sa_dl_Cube_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_Cylinder_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_Cylinder_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 565, 510, -880, -6, 0, 0, sa_dl_Cylinder_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_Cylinder_002_mesh_layer_5),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 1279, 2471, 85, 0, 0, -9, sa_dl_Cylinder_003_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, 777, 176, -114, 0, -2, 0, sa_dl_Cylinder_006_mesh_layer_1),
		GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_OPAQUE, -96, 59, 139, -8, -2, 70, sa_dl_Cylinder_007_mesh_layer_1),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 1205, 2471, 85),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, -794, 4331, 85, sa_dl_Shaft_Horizontal_Collision_mesh_layer_5),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT, 100, 3443, 85, sa_dl_Shaft_Vertical_Collision_mesh_layer_5),
=======
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_Cube_mesh),
>>>>>>> Stashed changes
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout sa_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
<<<<<<< Updated upstream
				GEO_BACKGROUND_COLOR(0x0001),
=======
				GEO_BACKGROUND(BACKGROUND_OCEAN_SKY, geo_skybox_main),
>>>>>>> Stashed changes
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, sa_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sa_dl_material_revert_render_settings),
<<<<<<< Updated upstream
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sa_dl_material_revert_render_settings),
=======
>>>>>>> Stashed changes
	GEO_CLOSE_NODE(),
	GEO_END(),
};
