#include "graphics_sub.h"
#include "game.h"

#include "bottom.h"

void configureGraphics_Sub() {
    // Configure the SUB engine in Rotoscale Mode
    REG_DISPCNT_SUB = MODE_5_2D | DISPLAY_BG2_ACTIVE;

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



// Custom empty tile
//...TO COMPLETE EXERCISE 5

// Custom full tile
//...TO COMPLETE EXERCISE 5

void configBG0_Sub() {

	// Configure background BG0 in tiled mode using a 32x32 grid and 256 colors
	//...TO COMPLETE EXERCISE 5

	// Transfer custom tiles to the proper memory locations
	//...TO COMPLETE EXERCISE 5

	// Assign color to the used components of the palette
	//...TO COMPLETE EXERCISE 5

	// Create map to show a separation of 16 pixels (2 tiles) between regions
	//...TO COMPLETE EXERCISE 5
}
