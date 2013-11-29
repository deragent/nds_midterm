#include "graphics_main.h"

#define QUART_WIDTH SCREEN_WIDTH/4

void configureGraphics_Main() {
	// Configure the MAIN engine in Framebuffer Mode
    REG_DISPCNT = MODE_FB0;
	// Configure the corresponding VRAM memory bank correctly
    VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD;
}

void fillRegion_Main(int region, u16 color){
    int x, y;
    int stop = (region+1)*QUART_WIDTH;
    for(y = 0; y<SCREEN_HEIGHT; y++)
    {
        for(x = region*QUART_WIDTH; x<stop; x++)
        {
            VRAM_A[y*SCREEN_WIDTH + x] = color;
        }
    }
}
