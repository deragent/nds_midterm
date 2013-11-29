#include "graphics_sub.h"
#include "game.h"

#include "bottom.h"

void configureGraphics_Sub() {
    // Configure the SUB engine in Rotoscale Mode
    REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG0_ACTIVE;

	// Configure the corresponding VRAM memory bank correctly
    VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;
}


void configBG2_Sub() {
	// Configure background BG2 in rotoscale mode using 8bit pixels
    BGCTRL_SUB[2] = BG_MAP_BASE(0) | BgSize_B8_256x256;

	// Transfer image and palette to the corresponding memory locations

    // I needed help here because I had source and dest confused!!!

    swiCopy(bottomPal, BG_PALETTE_SUB, bottomPalLen/2);
    swiCopy(bottomBitmap, BG_GFX_SUB, bottomBitmapLen/2);

    // Set up affine matrix
    REG_BG2PA_SUB = 256;
    REG_BG2PC_SUB = 0;
    REG_BG2PB_SUB = 0;
    REG_BG2PD_SUB = 256;
}



u8 tileEmpty[64] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};

u8 tileFull[64] = {
    255, 255, 255, 255, 255, 255, 255, 255,
    255, 254, 254, 254, 254, 254, 254, 255,
    255, 254, 255, 255, 255, 255, 254, 255,
    255, 254, 255, 254, 254, 255, 254, 255,
    255, 254, 255, 254, 254, 255, 254, 255,
    255, 254, 255, 255, 255, 255, 254, 255,
    255, 254, 254, 254, 254, 254, 254, 255,
    255, 255, 255, 255, 255, 255, 255, 255
};

// Custom full tile
//...TO COMPLETE EXERCISE 5

void configBG0_Sub() {

	// Configure background BG0 in tiled mode using a 32x32 grid and 256 colors
    BGCTRL_SUB[0] = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(25) | BG_TILE_BASE(4);

	// Transfer custom tiles to the proper memory locations
    swiCopy(&tileEmpty, &BG_TILE_RAM_SUB(4)[0], 32);
    swiCopy(&tileFull, &BG_TILE_RAM_SUB(4)[32], 32);

	// Assign color to the used components of the palette
    BG_PALETTE_SUB[254] = GREY;
    BG_PALETTE_SUB[255] = BLACK;

	// Create map to show a separation of 16 pixels (2 tiles) between regions
    int v, h;
    for(v = 0; v<32 ; v++)
    {
        for(h = 0; h<32; h++)
            BG_MAP_RAM_SUB(25)[v*32 + h] = 0;
    }
    for(v = 0; v<32; v++)
    {
        BG_MAP_RAM_SUB(25)[v*32 + 7] = 1;
        BG_MAP_RAM_SUB(25)[v*32 + 8] = 1;

        BG_MAP_RAM_SUB(25)[v*32 + 15] = 1;
        BG_MAP_RAM_SUB(25)[v*32 + 16] = 1;

        BG_MAP_RAM_SUB(25)[v*32 + 23] = 1;
        BG_MAP_RAM_SUB(25)[v*32 + 24] = 1;
    }
}
