Lights1 luigiman_moving_platform_Warning_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 luigiman_moving_platform_Grate_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Lights1 luigiman_moving_platform_Chain_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFE, 0xFE, 0xFE, 0x28, 0x28, 0x28);

Gfx luigiman_moving_platform__3395408_ci8_aligner[] = {gsSPEndDisplayList()};
u8 luigiman_moving_platform__3395408_ci8[] = {
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x01, 0x02, 
	0x06, 0x07, 0x08, 0x09, 0x09, 0x09, 0x09, 0x0a, 
	0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x08, 0x0b, 
	0x01, 0x01, 0x05, 0x04, 0x03, 0x02, 0x01, 0x00, 
	0x00, 0x02, 0x05, 0x00, 0x00, 0x00, 0x02, 0x02, 
	0x06, 0x07, 0x09, 0x0a, 0x0a, 0x09, 0x09, 0x09, 
	0x0a, 0x0a, 0x0c, 0x0a, 0x0a, 0x09, 0x0d, 0x0e, 
	0x01, 0x02, 0x00, 0x00, 0x05, 0x05, 0x02, 0x05, 
	0x05, 0x01, 0x00, 0x03, 0x00, 0x03, 0x02, 0x02, 
	0x06, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 0x09, 
	0x0a, 0x0a, 0x0a, 0x0c, 0x0a, 0x0d, 0x0e, 0x0f, 
	0x01, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 
	0x05, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 
	0x06, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 
	0x09, 0x09, 0x0a, 0x0a, 0x0d, 0x0e, 0x0f, 0x0f, 
	0x02, 0x02, 0x00, 0x03, 0x00, 0x00, 0x01, 0x05, 
	0x05, 0x01, 0x00, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x06, 0x07, 0x09, 0x09, 0x09, 0x09, 0x09, 0x0a, 
	0x0a, 0x09, 0x0a, 0x0d, 0x0e, 0x0f, 0x0f, 0x0f, 
	0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x05, 
	0x05, 0x01, 0x00, 0x03, 0x04, 0x03, 0x02, 0x02, 
	0x06, 0x07, 0x09, 0x09, 0x0a, 0x0c, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0d, 0x0e, 0x0f, 0x01, 0x0f, 0x0f, 
	0x02, 0x02, 0x00, 0x00, 0x00, 0x05, 0x01, 0x02, 
	0x05, 0x01, 0x00, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x06, 0x07, 0x09, 0x0a, 0x0c, 0x0c, 0x0a, 0x0a, 
	0x0a, 0x0d, 0x0e, 0x0f, 0x01, 0x0f, 0x0f, 0x0e, 
	0x01, 0x02, 0x00, 0x00, 0x05, 0x05, 0x0f, 0x02, 
	0x05, 0x01, 0x00, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x06, 0x07, 0x09, 0x0c, 0x0c, 0x0c, 0x0a, 0x0a, 
	0x0d, 0x0e, 0x0f, 0x01, 0x01, 0x0f, 0x0f, 0x0f, 
	0x01, 0x01, 0x00, 0x00, 0x00, 0x05, 0x0f, 0x02, 
	0x05, 0x01, 0x03, 0x04, 0x04, 0x04, 0x02, 0x02, 
	0x06, 0x07, 0x0a, 0x0c, 0x0c, 0x0c, 0x0c, 0x10, 
	0x11, 0x0f, 0x01, 0x01, 0x01, 0x0f, 0x0f, 0x0f, 
	0x01, 0x01, 0x03, 0x03, 0x00, 0x05, 0x0f, 0x02, 
	0x05, 0x01, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 
	0x06, 0x07, 0x0a, 0x0c, 0x0c, 0x0c, 0x10, 0x12, 
	0x13, 0x02, 0x02, 0x02, 0x01, 0x0f, 0x0f, 0x0f, 
	0x01, 0x01, 0x04, 0x03, 0x00, 0x00, 0x01, 0x01, 
	0x05, 0x01, 0x03, 0x04, 0x04, 0x04, 0x05, 0x14, 
	0x0d, 0x08, 0x0a, 0x0c, 0x0c, 0x10, 0x12, 0x13, 
	0x01, 0x02, 0x02, 0x02, 0x01, 0x01, 0x0f, 0x01, 
	0x01, 0x01, 0x04, 0x04, 0x03, 0x00, 0x0f, 0x02, 
	0x05, 0x01, 0x03, 0x04, 0x04, 0x04, 0x02, 0x15, 
	0x10, 0x08, 0x0a, 0x0c, 0x10, 0x12, 0x0f, 0x01, 
	0x01, 0x01, 0x02, 0x02, 0x02, 0x01, 0x01, 0x0f, 
	0x01, 0x02, 0x04, 0x04, 0x04, 0x00, 0x0f, 0x01, 
	0x05, 0x01, 0x03, 0x03, 0x03, 0x04, 0x05, 0x16, 
	0x17, 0x08, 0x0a, 0x10, 0x18, 0x0f, 0x0f, 0x01, 
	0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 
	0x01, 0x02, 0x03, 0x03, 0x03, 0x00, 0x0f, 0x02, 
	0x05, 0x02, 0x00, 0x02, 0x05, 0x00, 0x05, 0x19, 
	0x10, 0x08, 0x10, 0x12, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x01, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 
	0x01, 0x02, 0x00, 0x02, 0x02, 0x00, 0x01, 0x02, 
	0x05, 0x01, 0x0f, 0x01, 0x02, 0x02, 0x05, 0x19, 
	0x10, 0x0d, 0x11, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x02, 0x02, 0x01, 0x02, 0x02, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x0f, 0x0f, 0x05, 
	0x05, 0x0f, 0x01, 0x00, 0x00, 0x02, 0x02, 0x1a, 
	0x0b, 0x0f, 0x01, 0x01, 0x0f, 0x0f, 0x0f, 0x0f, 
	0x0f, 0x02, 0x02, 0x01, 0x02, 0x01, 0x0f, 0x0f, 
	0x01, 0x01, 0x02, 0x04, 0x00, 0x0f, 0x0f, 0x02, 
	0x05, 0x01, 0x02, 0x03, 0x03, 0x05, 0x02, 0x05, 
	0x0f, 0x0f, 0x01, 0x01, 0x01, 0x0f, 0x01, 0x01, 
	0x02, 0x02, 0x01, 0x01, 0x01, 0x0f, 0x11, 0x06, 
	0x14, 0x01, 0x05, 0x04, 0x03, 0x01, 0x0f, 0x02, 
	0x05, 0x02, 0x05, 0x00, 0x00, 0x00, 0x05, 0x02, 
	0x0f, 0x0f, 0x01, 0x01, 0x01, 0x0f, 0x01, 0x02, 
	0x05, 0x02, 0x01, 0x01, 0x0f, 0x12, 0x10, 0x07, 
	0x19, 0x02, 0x00, 0x00, 0x00, 0x05, 0x01, 0x05, 
	0x05, 0x01, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x0f, 0x0f, 0x01, 0x0f, 0x0f, 0x01, 0x0f, 0x01, 
	0x02, 0x02, 0x01, 0x13, 0x1b, 0x07, 0x08, 0x10, 
	0x19, 0x05, 0x04, 0x03, 0x03, 0x03, 0x01, 0x05, 
	0x05, 0x01, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x0f, 0x0e, 0x0f, 0x0f, 0x0f, 0x01, 0x0f, 0x0f, 
	0x01, 0x01, 0x13, 0x1b, 0x08, 0x0c, 0x08, 0x10, 
	0x19, 0x02, 0x03, 0x04, 0x03, 0x03, 0x01, 0x05, 
	0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x02, 0x02, 
	0x0e, 0x0e, 0x0f, 0x0f, 0x0f, 0x0f, 0x01, 0x0f, 
	0x0f, 0x13, 0x1b, 0x08, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x02, 0x03, 0x04, 0x03, 0x03, 0x01, 0x05, 
	0x00, 0x02, 0x03, 0x04, 0x03, 0x03, 0x02, 0x02, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x01, 0x0f, 
	0x0f, 0x12, 0x08, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x05, 0x04, 0x04, 0x04, 0x03, 0x01, 0x05, 
	0x00, 0x01, 0x03, 0x04, 0x03, 0x03, 0x02, 0x02, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f, 0x01, 0x13, 
	0x1b, 0x08, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x05, 0x04, 0x04, 0x04, 0x03, 0x01, 0x05, 
	0x00, 0x01, 0x03, 0x04, 0x04, 0x04, 0x02, 0x02, 
	0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x13, 0x1b, 
	0x08, 0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x05, 0x04, 0x04, 0x03, 0x00, 0x01, 0x05, 
	0x05, 0x02, 0x03, 0x04, 0x04, 0x04, 0x02, 0x02, 
	0x0e, 0x0e, 0x0f, 0x0e, 0x0e, 0x0f, 0x1b, 0x08, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x05, 0x04, 0x04, 0x03, 0x03, 0x01, 0x05, 
	0x05, 0x02, 0x03, 0x04, 0x04, 0x04, 0x02, 0x02, 
	0x0e, 0x0e, 0x0f, 0x0f, 0x0e, 0x12, 0x08, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x05, 0x03, 0x03, 0x04, 0x03, 0x01, 0x05, 
	0x05, 0x01, 0x04, 0x04, 0x04, 0x04, 0x02, 0x02, 
	0x0e, 0x0e, 0x0f, 0x0f, 0x12, 0x07, 0x0c, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x02, 0x03, 0x03, 0x04, 0x03, 0x01, 0x05, 
	0x00, 0x01, 0x04, 0x04, 0x04, 0x04, 0x02, 0x01, 
	0x0e, 0x0e, 0x0f, 0x12, 0x07, 0x0c, 0x0a, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x02, 0x03, 0x04, 0x04, 0x03, 0x01, 0x05, 
	0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 
	0x0e, 0x0e, 0x12, 0x07, 0x0c, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x08, 0x10, 
	0x19, 0x05, 0x03, 0x03, 0x03, 0x03, 0x0f, 0x05, 
	0x05, 0x02, 0x00, 0x02, 0x02, 0x00, 0x01, 0x01, 
	0x0e, 0x1c, 0x10, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 
	0x0a, 0x0a, 0x0c, 0x0a, 0x0c, 0x09, 0x08, 0x10, 
	0x19, 0x05, 0x03, 0x05, 0x02, 0x00, 0x01, 0x05, 
	0x05, 0x01, 0x0f, 0x01, 0x05, 0x02, 0x0f, 0x01, 
	0x0e, 0x0d, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x09, 0x08, 0x10, 
	0x19, 0x02, 0x02, 0x02, 0x02, 0x0f, 0x01, 0x05, 
	0x05, 0x01, 0x0f, 0x00, 0x04, 0x02, 0x0f, 0x01, 
	0x0b, 0x07, 0x09, 0x0a, 0x09, 0x0a, 0x0a, 0x0c, 
	0x0c, 0x0c, 0x0c, 0x0c, 0x0a, 0x09, 0x08, 0x10, 
	0x19, 0x01, 0x05, 0x03, 0x00, 0x0f, 0x0f, 0x05, 
	
};

Gfx luigiman_moving_platform__3395408_ci8_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 luigiman_moving_platform__3395408_ci8_pal_rgba16[] = {
	0x6a, 0xd5, 0x31, 0x4b, 0x39, 0xcd, 0x7b, 0x9b, 
	0x8c, 0x1f, 0x52, 0x51, 0x71, 0xc7, 0xc0, 0x4b, 
	0xd0, 0xcd, 0xfa, 0x0b, 0xfa, 0x8d, 0x49, 0x47, 
	0xfb, 0x0f, 0x71, 0x87, 0x10, 0x85, 0x21, 0x09, 
	0xa8, 0x0d, 0x28, 0xcb, 0x30, 0xcb, 0x31, 0x0b, 
	0x39, 0x8d, 0x49, 0x4f, 0x59, 0xd3, 0x71, 0x89, 
	0x18, 0x47, 0x61, 0x53, 0x52, 0x11, 0x40, 0xcd, 
	0x18, 0x87, 
};

Gfx luigiman_moving_platform__0E018C10_ia8_aligner[] = {gsSPEndDisplayList()};
u8 luigiman_moving_platform__0E018C10_ia8[] = {
	0xaf, 0xaf, 0xaf, 0x9f, 0x8f, 0x5f, 0x5f, 0x5f, 
	0x9f, 0x9f, 0x9f, 0xaf, 0x8f, 0x7f, 0x8f, 0x9f, 
	0x9f, 0xaf, 0xaf, 0xbf, 0xaf, 0x9f, 0x7f, 0x5f, 
	0x8f, 0xaf, 0xbf, 0xbf, 0xaf, 0xaf, 0xaf, 0x9f, 
	0x6f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x6f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x5f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x3f, 0x3f, 0x6f, 0x6f, 0x4f, 0x5f, 0x4f, 
	0x3f, 0x3f, 0x4f, 0x5f, 0x5f, 0x4f, 0x4f, 0x5f, 
	0x9f, 0x3f, 0x3f, 0x6f, 0x5f, 0x4f, 0x6f, 0x6f, 
	0x7f, 0x5f, 0x5f, 0x5f, 0x5f, 0x4f, 0x4f, 0x5f, 
	0x9f, 0x6f, 0x6f, 0x6f, 0x8f, 0x9f, 0x9f, 0x9f, 
	0x9f, 0x9f, 0x8f, 0x6f, 0x8f, 0x9f, 0x9f, 0x5f, 
	0x9f, 0x6f, 0x6f, 0x6f, 0x8f, 0x9f, 0x9f, 0x9f, 
	0x9f, 0x8f, 0x7f, 0x6f, 0x8f, 0x8f, 0x9f, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x3f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x3f, 
	0x6f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x7f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x7f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x7f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x7f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x6f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x5f, 0x5f, 0x4f, 0x4f, 0x4f, 0x4f, 0x4f, 0x5f, 
	0x8f, 0x7f, 0x7f, 0x6f, 0x6f, 0x3f, 0x3f, 0x3f, 
	0x3f, 0x4f, 0x6f, 0x6f, 0x4f, 0x3f, 0x3f, 0x5f, 
	0x8f, 0x7f, 0x7f, 0x6f, 0x4f, 0x3f, 0x3f, 0x4f, 
	0xaf, 0xaf, 0x8f, 0x8f, 0x7f, 0x5f, 0x5f, 0x5f, 
	0x9f, 0x9f, 0x9f, 0xbf, 0x8f, 0x7f, 0x8f, 0x9f, 
	0xaf, 0xaf, 0xaf, 0xbf, 0xaf, 0x5f, 0x5f, 0x4f, 
	0x9f, 0x9f, 0x9f, 0xaf, 0xaf, 0xaf, 0xaf, 0x9f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x6f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x3f, 0x3f, 0x6f, 0x6f, 0x5f, 0x4f, 0x4f, 
	0x3f, 0x3f, 0x3f, 0x6f, 0x6f, 0x4f, 0x4f, 0x5f, 
	0xaf, 0x3f, 0x3f, 0x6f, 0x6f, 0x4f, 0x4f, 0x4f, 
	0x4f, 0x5f, 0x3f, 0x6f, 0x6f, 0x4f, 0x4f, 0x5f, 
	0x9f, 0x5f, 0x5f, 0x7f, 0x8f, 0xaf, 0xaf, 0x9f, 
	0x9f, 0x7f, 0x5f, 0x7f, 0x8f, 0xaf, 0xaf, 0x5f, 
	0xaf, 0x5f, 0x5f, 0x7f, 0x8f, 0xaf, 0xaf, 0x9f, 
	0x9f, 0x7f, 0x5f, 0x7f, 0x8f, 0xaf, 0xaf, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x3f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x3f, 
	0x5f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x6f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0xaf, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x7f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x6f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x9f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x4f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x4f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x4f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x8f, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x5f, 
	0x4f, 0x4f, 0x4f, 0x5f, 0x5f, 0x5f, 0x3f, 0x6f, 
	0x8f, 0x4f, 0x4f, 0x5f, 0x5f, 0x4f, 0x5f, 0x4f, 
	0x4f, 0x4f, 0x4f, 0x6f, 0x5f, 0x3f, 0x4f, 0x4f, 
	0x8f, 0x4f, 0x5f, 0x6f, 0x5f, 0x4f, 0x4f, 0x4f, 
	
};

Gfx luigiman_moving_platform__0E00B010_ia8_aligner[] = {gsSPEndDisplayList()};
u8 luigiman_moving_platform__0E00B010_ia8[] = {
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x2f, 0x2f, 0x2f, 0x2f, 
	0x2f, 0x3f, 0x3f, 0x3f, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x1f, 0x1f, 0x1f, 0x2f, 0x2f, 0x3f, 
	0x3f, 0x3f, 0x3f, 0x3f, 0x4f, 0x3f, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x1f, 0x1f, 0x3f, 0x5f, 0x7f, 0x7f, 
	0x7f, 0x6f, 0x4f, 0x3f, 0x4f, 0x5f, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x1f, 0x1f, 0x3f, 0x8f, 0x9f, 0x7f, 0x5f, 
	0x5f, 0x4f, 0x3f, 0x2f, 0x2f, 0x5f, 0x6f, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x1f, 0x2f, 0x6f, 0xaf, 0x8f, 0x30, 0x30, 
	0x30, 0x30, 0x2f, 0x1f, 0x1f, 0x5f, 0x7f, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x9f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x1f, 0x1f, 0x5f, 0x7f, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x8f, 0x9f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x1f, 0x1f, 0x4f, 0x8f, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x8f, 0x8f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x1f, 0x1f, 0x5f, 0x8f, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x3f, 0x8f, 0x8f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x6f, 0x9f, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x3f, 0x8f, 0x7f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x6f, 0xbf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x3f, 0x7f, 0x6f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x7f, 0xbf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x6f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x6f, 0xaf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x6f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x6f, 0xaf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x6f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x6f, 0xbf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x6f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x1f, 0x6f, 0xbf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x7f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x0f, 0x2f, 0x7f, 0xbf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x2f, 0x7f, 0x7f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x1f, 0x1f, 0x6f, 0xcf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x1f, 0x5f, 0x6f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x1f, 0x1f, 0x7f, 0xcf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x1f, 0x3f, 0x4f, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x1f, 0x3f, 0x8f, 0xdf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x0f, 0x0f, 0x2f, 0x2f, 0x2f, 0x30, 0x30, 
	0x30, 0x30, 0x1f, 0x2f, 0x6f, 0xcf, 0xdf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x1f, 0x1f, 0x1f, 0x1f, 0x2f, 0x1f, 0x1f, 
	0x1f, 0x1f, 0x3f, 0x6f, 0xbf, 0xef, 0xdf, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x1f, 0x1f, 0x1f, 0x1f, 0x2f, 0x2f, 
	0x2f, 0x4f, 0x7f, 0xbf, 0xff, 0xef, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x3f, 0x4f, 0x5f, 0x6f, 0x8f, 0x9f, 
	0x9f, 0xcf, 0xff, 0xff, 0xef, 0xcf, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x8f, 0xaf, 0xbf, 0xdf, 
	0xdf, 0xef, 0xef, 0xcf, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
	
};

Vtx luigiman_moving_platform_Moving_Platform_mesh_layer_1_vtx_0[64] = {
	{{{-277, -32, 277},0, {96, -4004},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-277, 32, 277},0, {896, -4004},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-277, 32, -277},0, {896, 4996},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-277, -32, -277},0, {96, 4996},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-277, -32, -277},0, {96, -4004},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-277, 32, -277},0, {896, -4004},{0x0, 0x0, 0x81, 0xFF}}},
	{{{277, 32, -277},0, {896, 4996},{0x0, 0x0, 0x81, 0xFF}}},
	{{{277, -32, -277},0, {96, 4996},{0x0, 0x0, 0x81, 0xFF}}},
	{{{277, -32, -277},0, {96, 4996},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{277, 32, -277},0, {896, 4996},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{277, 32, 277},0, {896, -4004},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{277, -32, 277},0, {96, -4004},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{277, -32, 277},0, {96, 4996},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{277, 32, 277},0, {896, 4996},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-277, 32, 277},0, {896, -4004},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-277, -32, 277},0, {96, -4004},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{277, 32, 277},0, {4996, 4996},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{277, 32, -277},0, {4996, -4004},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, 32, -227},0, {4191, -3199},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, 32, 227},0, {4191, 4191},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, 227},0, {883, -3999},{0x0, 0x0, 0x81, 0xFF}}},
	{{{227, 32, 227},0, {883, 4991},{0x0, 0x0, 0x81, 0xFF}}},
	{{{227, -32, 227},0, {109, 4991},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-227, -32, 227},0, {109, -3999},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-277, 32, -277},0, {-4004, -4004},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-277, 32, 277},0, {-4004, 4996},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, 227},0, {-3199, 4191},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, -227},0, {-3199, -3199},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-277, 32, 277},0, {94, 94},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{277, 32, 277},0, {94, 9093},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, 32, 227},0, {898, 8288},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, 227},0, {898, 898},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{277, 32, -277},0, {94, -8101},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-277, 32, -277},0, {94, 898},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, -227},0, {898, 94},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, 32, -227},0, {898, -7296},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, 32, -227},0, {883, 4991},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-227, 32, -227},0, {883, -3999},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-227, -32, -227},0, {109, -3999},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{227, -32, -227},0, {109, 4991},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{227, 32, 227},0, {883, -3999},{0x81, 0x0, 0x0, 0xFF}}},
	{{{227, 32, -227},0, {883, 4991},{0x81, 0x0, 0x0, 0xFF}}},
	{{{227, -32, -227},0, {109, 4991},{0x81, 0x0, 0x0, 0xFF}}},
	{{{227, -32, 227},0, {109, -3999},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-227, 32, -227},0, {883, 4991},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-227, 32, 227},0, {883, -3999},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-227, -32, 227},0, {109, -3999},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-227, -32, -227},0, {109, 4991},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-277, -32, 277},0, {-4004, 4996},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-277, -32, -277},0, {-4004, -4004},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-227, -32, -227},0, {-3199, -3199},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-227, -32, 227},0, {-3199, 4191},{0x0, 0x81, 0x0, 0xFF}}},
	{{{277, -32, -277},0, {898, 898},{0x0, 0x81, 0x0, 0xFF}}},
	{{{227, -32, -227},0, {94, 94},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-227, -32, -227},0, {94, -7296},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-277, -32, -277},0, {898, -8101},{0x0, 0x81, 0x0, 0xFF}}},
	{{{277, -32, 277},0, {4996, 4996},{0x0, 0x81, 0x0, 0xFF}}},
	{{{227, -32, 227},0, {4191, 4191},{0x0, 0x81, 0x0, 0xFF}}},
	{{{227, -32, -227},0, {4191, -3199},{0x0, 0x81, 0x0, 0xFF}}},
	{{{277, -32, -277},0, {4996, -4004},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-277, -32, 277},0, {94, 94},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-227, -32, 227},0, {898, 898},{0x0, 0x81, 0x0, 0xFF}}},
	{{{227, -32, 227},0, {898, 8288},{0x0, 0x81, 0x0, 0xFF}}},
	{{{277, -32, 277},0, {94, 9093},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx luigiman_moving_platform_Moving_Platform_mesh_layer_1_tri_0[] = {
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_1_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_1_vtx_0 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_1_vtx_0 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_1_vtx_0 + 48, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPEndDisplayList(),
};

Vtx luigiman_moving_platform_Moving_Platform_mesh_layer_4_vtx_0[8] = {
	{{{227, 32, 227},0, {3078, 3078},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, 32, -227},0, {3078, -2086},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, -227},0, {-2086, -2086},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-227, 32, 227},0, {-2086, 3078},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{227, -32, 227},0, {3078, 3078},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-227, -32, 227},0, {-2086, 3078},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-227, -32, -227},0, {-2086, -2086},{0x0, 0x81, 0x0, 0xFF}}},
	{{{227, -32, -227},0, {3078, -2086},{0x0, 0x81, 0x0, 0xFF}}},
};

Gfx luigiman_moving_platform_Moving_Platform_mesh_layer_4_tri_0[] = {
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_4_vtx_0 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Vtx luigiman_moving_platform_Moving_Platform_mesh_layer_4_vtx_1[32] = {
	{{{-275, -7, -250},0, {163, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-225, -7, -250},0, {829, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-225, 3329, -250},0, {829, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-275, 3329, -250},0, {163, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-250, 28, -224},0, {163, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 28, -275},0, {829, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 3364, -275},0, {829, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 3364, -224},0, {163, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{225, -7, -250},0, {163, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{276, -7, -250},0, {829, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{276, 3329, -250},0, {829, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{225, 3329, -250},0, {163, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{251, 28, -224},0, {163, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{251, 28, -275},0, {829, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{251, 3364, -275},0, {829, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{251, 3364, -224},0, {163, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-275, -7, 248},0, {163, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-225, -7, 248},0, {829, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-225, 3329, 248},0, {829, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-275, 3329, 248},0, {163, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-250, 28, 273},0, {163, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 28, 223},0, {829, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 3364, 223},0, {829, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-250, 3364, 273},0, {163, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{225, -7, 248},0, {163, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{276, -7, 248},0, {829, -17503},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{276, 3329, 248},0, {829, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{225, 3329, 248},0, {163, 31643},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{251, 28, 273},0, {163, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{251, 28, 223},0, {829, -17503},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{251, 3364, 223},0, {829, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{251, 3364, 273},0, {163, 31643},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx luigiman_moving_platform_Moving_Platform_mesh_layer_4_tri_1[] = {
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_4_vtx_1 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(luigiman_moving_platform_Moving_Platform_mesh_layer_4_vtx_1 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPEndDisplayList(),
};


Gfx mat_luigiman_moving_platform_Warning[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, luigiman_moving_platform__3395408_ci8_pal_rgba16),
	gsDPTileSync(),
	gsDPSetTile(0, 0, 0, 256, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadSync(),
	gsDPLoadTLUTCmd(7, 28),
	gsDPPipeSync(),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, luigiman_moving_platform__3395408_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(luigiman_moving_platform_Warning_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_luigiman_moving_platform_Warning[] = {
	gsDPPipeSync(),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_luigiman_moving_platform_Grate[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 1, luigiman_moving_platform__0E018C10_ia8),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(luigiman_moving_platform_Grate_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_luigiman_moving_platform_Grate[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx mat_luigiman_moving_platform_Chain[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, ENVIRONMENT, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 1, luigiman_moving_platform__0E00B010_ia8),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 511, 512),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(luigiman_moving_platform_Chain_lights),
	gsSPEndDisplayList(),
};

Gfx mat_revert_luigiman_moving_platform_Chain[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_CULL_BACK),
	gsSPEndDisplayList(),
};

Gfx luigiman_moving_platform_Moving_Platform_mesh_layer_1[] = {
	gsSPDisplayList(mat_luigiman_moving_platform_Warning),
	gsSPDisplayList(luigiman_moving_platform_Moving_Platform_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_luigiman_moving_platform_Warning),
	gsSPEndDisplayList(),
};

Gfx luigiman_moving_platform_Moving_Platform_mesh_layer_4[] = {
	gsSPDisplayList(mat_luigiman_moving_platform_Grate),
	gsSPDisplayList(luigiman_moving_platform_Moving_Platform_mesh_layer_4_tri_0),
	gsSPDisplayList(mat_revert_luigiman_moving_platform_Grate),
	gsSPDisplayList(mat_luigiman_moving_platform_Chain),
	gsSPDisplayList(luigiman_moving_platform_Moving_Platform_mesh_layer_4_tri_1),
	gsSPDisplayList(mat_revert_luigiman_moving_platform_Chain),
	gsSPEndDisplayList(),
};

Gfx luigiman_moving_platform_material_revert_render_settings[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};
