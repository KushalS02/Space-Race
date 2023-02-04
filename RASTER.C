#include "raster.h"


void plotPixel(UINT8* base, int x, int y) {

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7); 
	}

}

void plotVerticalLine(UINT8* base, int x, int y, int height) {

}

void plotHorizontalLine(UINT8* base, int x, int y, int length) {

}
