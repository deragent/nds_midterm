#include "graphics_sub.h"
#include "game.h"

void configureGraphics_Sub() {
	// Configure the MAIN engine in Rotoscale Mode
	//...TO COMPLETE EXERCISE 2
	// Configure the corresponding VRAM memory bank correctly
	//...TO COMPLETE EXERCISE 2
}


void configBG2_Sub() {
	// Configure background BG2 in rotoscale mode using 8bit pixels
	//...TO COMPLETE EXERCISE 2

	// Transfer image and palette to the corresponding memory locations
	//...TO COMPLETE EXERCISE 2

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
