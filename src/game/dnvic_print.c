#include "src/game/memory.h"
#include "src/game/dnvic_print.h"
#include "area.h"
#include "game_init.h"
#include "level_update.h"
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

extern Texture dnvic_map_texture_07001600[];
extern Texture dnvic_mario_texture_07001600[];

extern u16 gDnvicCounter;
extern u16 gDnvicChamber;

void render_dnvic_map(u8 a)
{
    /*
    static int x = 0, y = 0;
    if (gPlayer1Controller->buttonDown & U_JPAD)
        y--;
    if (gPlayer1Controller->buttonDown & D_JPAD)
        y++;
    if (gPlayer1Controller->buttonDown & R_JPAD)
        x++;
    if (gPlayer1Controller->buttonDown & L_JPAD)
        x--;
    */

    int x, y;
    switch (gDnvicChamber)
    {
        case 1:
        {
            if (gCurrAreaIndex != 1)
            {
                if (gDnvicCounter > 1)
                {
                    x = 83 - gDnvicCounter; y = 78;
                }
                else
                {
                    x = 91; y = 103;
                }
            }
            else
            {
                x = 142; y = 111;
            }
        }
        break;
        case 2:
        {
            x = 142; y = 188;
        }
        break;
        case 3:
        {
            x = 93; y = 188;
        }
        break;
        case 4:
        {
            x = 45; y = 188;
        }
        break;
        case 5:
        {
            if (gDnvicCounter > 0)
            {
                x = 110 - 2 * gDnvicCounter; y = 225;
            }
            else
            {
                x = 120; y = 270;
            }
        }
        break;
        case 10:
        {
            x = 37; y = 92;
        }
        break;
        case 12:
        {
            x = 52; y = 277;
        }
        break;
    }

    print_set_envcolour(255, 255, 255, a);
    render_multi_image(dnvic_map_texture_07001600, 0, 0, 320, 240, 1, 1, G_CYC_1CYCLE);
    print_set_envcolour(255, 255, 255, 2*a);
    render_multi_image(dnvic_mario_texture_07001600, y, x, 32, 64, 0, 0, G_CYC_1CYCLE);
}
