#include "src/game/memory.h"
#include "src/game/dnvic_print.h"
#include "string.h"


struct DnvicLabel {
    s32 x;
    s32 y;
    s32 align;
    s32 amount;
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    char buffer[50];
};

struct DnvicLabel *sDnvicLabels[52];
s16 sDnvicLabelsCount = 0;


void dnvic_print_text(s32 x, s32 y, const char *str, s32 align, s32 amount, s32 r, s32 g, s32 b, s32 a) {
    s32 srcIndex = 0;
    char c = 0;

    // Don't continue if there is no memory to do so
    if ((sDnvicLabels[sDnvicLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct DnvicLabel))) == NULL) {
        return;
    }

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sDnvicLabels[sDnvicLabelsCount]->buffer[srcIndex] = c;
        srcIndex++;
        c = str[srcIndex];
    }

    sDnvicLabels[sDnvicLabelsCount]->x = x;
    sDnvicLabels[sDnvicLabelsCount]->y = y;
    sDnvicLabels[sDnvicLabelsCount]->align = align;
    sDnvicLabels[sDnvicLabelsCount]->amount = amount;
    sDnvicLabels[sDnvicLabelsCount]->r = r;
    sDnvicLabels[sDnvicLabelsCount]->g = g;
    sDnvicLabels[sDnvicLabelsCount]->b = b;
    sDnvicLabels[sDnvicLabelsCount]->a = a;
    sDnvicLabelsCount++;
}


// most of the time you'll be printing white text not another color so this is a shortcut for cleaner/faster code
void dnvic_print_white_text(s32 x, s32 y, const char *str, s32 align, s32 amount, s32 a) {
    dnvic_print_text(x, y, str, align, amount, 0xFF, 0xFF, 0xFF, a);
}


void render_dnvic_labels() {
    s32 i;

    
    //Mtx *mtx;

    if (sDnvicLabelsCount == 0) {
        return;
    }

    /*mtx = alloc_display_list(sizeof(*mtx));

    if (mtx == NULL) {
        sDnvicLabelsCount = 0;
        return;
    }*/

    for(i = 0; i < sDnvicLabelsCount; i++) {
        


        print_set_envcolour(sDnvicLabels[i]->r, sDnvicLabels[i]->g, sDnvicLabels[i]->b, sDnvicLabels[i]->a);
        print_small_text(sDnvicLabels[i]->x, sDnvicLabels[i]->y, sDnvicLabels[i]->buffer, sDnvicLabels[i]->align, sDnvicLabels[i]->amount, FONT_DEFAULT /*puppyprint updated and too lazy to add this in as an option */);

        mem_pool_free(gEffectsMemoryPool, sDnvicLabels[i]);
    }
    sDnvicLabelsCount = 0;
}