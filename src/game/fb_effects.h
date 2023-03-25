#pragma once

void render_fb_effects(void);
void set_fb_effect_col(u8 r, u8 g, u8 b, u8 a);

typedef struct FBEffects {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} FBEffects;
