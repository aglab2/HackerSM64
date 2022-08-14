#pragma once

#include "sm64.h"

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} rgb;

typedef struct {
    u16 h;         // mario angles
    u8  v;         // value as u8
    float s;       // a fraction between 0 and 1
} hsv;

void rgb2hsv(rgb* in, hsv* out);
void hsv2rgb(hsv* in, rgb* out);
