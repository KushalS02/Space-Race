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

void plotBitmap8(UINT8* base, int x, int y, UINT8* bitmap, int height) {



}

void plotBitmap16(UINT16* base, int x, int y, UINT16* bitmap, int height) {



}

void plotScreen(UINT32* base, UINT32* bitmap) {

	int i;

	for (i = 0; i < SCREEN_BYTE_SIZE; i++) {
		*(base + 1) = bitmap[i];
	}

}

void clearRegion(void* base, int x, int y, int width, int height) {



}