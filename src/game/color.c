#include "color.h"

void rgb2hsv(rgb* in, hsv* out)
{
    u8 min = in->r < in->g ? in->r : in->g;
    min = min  < in->b ? min  : in->b;

    u8 max = in->r > in->g ? in->r : in->g;
    max = max  > in->b ? max  : in->b;

    out->v = max;
    if (min == max)
    {
        out->s = 0;
        out->h = 0; // undefined, maybe nan?
        return;
    }
    
    f32 delta = max - min;
    if( max > 0 ) { // NOTE: if Max is == 0, this divide would cause a crash
        out->s = (delta / max);                  // s
    } else {
        // if max is 0, then r = g = b = 0              
        // s = 0, h is undefined
        out->s = 0.0;
        out->h = 0;
    }

    float h;
    if( in->r >= max )                           // > is bogus, just keeps compilor happy
        h = ( in->g - in->b ) / delta;        // between yellow & magenta
    else
    if( in->g >= max )
        h = 2.0f + ( in->b - in->r ) / delta;  // between cyan & yellow
    else
        h = 4.0f + ( in->r - in->g ) / delta;  // between magenta & cyan

    out->h = h * 10923;
}

void hsv2rgb(hsv* in, rgb* out)
{
    if(in->s <= 0.0) {       // < is bogus, just shuts up warnings
        out->r = in->v;
        out->g = in->v;
        out->b = in->v;
        return;
    }
    f32 hh = in->h / 10923.f;
    int i = (int) hh;
    f32 ff = hh - i;
    u8 p = in->v * (1.0 - in->s);
    u8 q = in->v * (1.0 - (in->s * ff));
    u8 t = in->v * (1.0 - (in->s * (1.0 - ff)));

    switch(i) {
    case 0:
        out->r = in->v;
        out->g = t;
        out->b = p;
        break;
    case 1:
        out->r = q;
        out->g = in->v;
        out->b = p;
        break;
    case 2:
        out->r = p;
        out->g = in->v;
        out->b = t;
        break;

    case 3:
        out->r = p;
        out->g = q;
        out->b = in->v;
        break;
    case 4:
        out->r = t;
        out->g = p;
        out->b = in->v;
        break;
    case 5:
    default:
        out->r = in->v;
        out->g = p;
        out->b = q;
        break;
    }
}
