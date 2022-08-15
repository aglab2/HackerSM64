#include "game/color.h"

extern Gfx mat_wmotr_dl_wood_001_layer1[]; //+14
extern Gfx mat_wmotr_dl_instant_warp_to_area_2_layer1[];
extern Gfx mat_wmotr_dl_brick_001_layer1[];
extern Gfx mat_wmotr_dl_down_instant_warp_layer1[];
extern Gfx mat_wmotr_dl_up_instant_warp_layer1[];
extern Gfx mat_wmotr_dl_wood_layer1[];
extern Gfx mat_wmotr_dl_brick_layer1[];
extern Gfx mat_wmotr_dl_wood_002_layer1[];
extern Gfx mat_wmotr_dl_instant_warp_to_area__layer1[];
extern Gfx mat_wmotr_dl_brick_002_layer1[];
extern Gfx mat_wmotr_dl_wood_003_layer1[]; //+13
extern Gfx mat_wmotr_dl_brick_003_layer1[];

extern hsv gDnvicColor;
extern u8 gDnvicPlayEffect;

hsv gDnvicCurrentColor = 
{    
    .h = 0.052028f * 0x10000,
    .v = 250,
    .s = 0.826638f,
};

static void dnvic_write_rgb(Gfx* gfx, int off, rgb* c)
{
    u8* d = ((u8*) segmented_to_virtual(gfx)) + 8*off + 4;
    d[0] = c->r;
    d[1] = c->g;
    d[2] = c->b;
}

void bhv_dnvic_color_reset_init(void) 
{
    // -
}

void bhv_dnvic_color_reset_loop(void) 
{ 
    gDnvicCurrentColor.h = approach_angle(gDnvicCurrentColor.h, gDnvicColor.h, 300);
    approach_f32_asymptotic_bool(&gDnvicCurrentColor.s, gDnvicColor.s, 0.1f);
    gDnvicCurrentColor.v = approach_s16(gDnvicCurrentColor.v, gDnvicColor.v, 1, 1);
    rgb color;
    hsv2rgb(&gDnvicCurrentColor, &color);

    /*
    print_text_fmt_int(20, 20, "R %d", color.r);
    print_text_fmt_int(20, 40, "G %d", color.g);
    print_text_fmt_int(20, 60, "B %d", color.b);

    print_text_fmt_int(20, 100, "H %d", gDnvicCurrentColor.h);
    print_text_fmt_int(20, 120, "S %d", (int) (1000 * gDnvicCurrentColor.s));
    print_text_fmt_int(20, 140, "V %d", gDnvicCurrentColor.v);

    print_text_fmt_int(100, 100, "H %d", gDnvicColor.h);
    print_text_fmt_int(100, 120, "S %d", (int) (1000 * gDnvicColor.s));
    print_text_fmt_int(100, 140, "V %d", gDnvicColor.v);
    */

    dnvic_write_rgb(mat_wmotr_dl_wood_001_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_instant_warp_to_area_2_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_brick_001_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_down_instant_warp_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_up_instant_warp_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_wood_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_brick_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_wood_002_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_instant_warp_to_area__layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_brick_002_layer1, 14, &color);
    dnvic_write_rgb(mat_wmotr_dl_wood_003_layer1, 13, &color);
    dnvic_write_rgb(mat_wmotr_dl_brick_003_layer1, 14, &color);

    if (gDnvicPlayEffect)
    {
        if (1 == gDnvicPlayEffect)
        {
            play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gGlobalSoundSource);
        }
        else
        {
            play_sound(SOUND_MENU_CAMERA_BUZZ, gGlobalSoundSource);
        }
        gDnvicPlayEffect = 0;
    }
}
