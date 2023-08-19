#include "src/game/envfx_snow.h"

const GeoLayout castle_inside_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, 1250, 32000, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_inside_dl_DL_castle_inside_1_0xe02daa0_Obj_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1250, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_inside_dl_DL_castle_inside_1_0xe02daa0_Obj_001_mesh_layer_1),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE(LAYER_TRANSPARENT_DECAL, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-32000, 32000, -32000, 1250, -32000, 32000, 0),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_ALPHA, castle_inside_dl_DL_castle_inside_1_0xe03c280_Obj_mesh_layer_4),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ASM(0, geo_envfx_main),
		GEO_ASM(0, geo_cannon_circle_base),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_inside_area_1[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(1, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_inside_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
