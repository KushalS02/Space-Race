#include "raster.h"


void plotPixel(UINT8* base, int x, int y) {

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {

		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7); 

	}

}

void plotVerticalLine(UINT8* base, int x, int y, int height) {

	int i;

	for (i = 0; i < height; i++) {

		*(base + ((y + i) * 80) + (x >> 3)) |= 1 << 7 - (x & 7);

	}

}

void plotHorizontalLine(UINT8* base, int x, int y, int length) {

	int i;
	int counter = length >> 3;

	UINT8 *drawLine = base + (y * 80) + (x >> 3);

	for (i = 0; i < counter; i++){

		*(drawLine++) |= 0xff;
	}

}

void plotBitmap8(UINT8* base, UINT8* bitmap, int x, int y, int height) {

int i;

UINT8 *plotLocation = base + (y * 80) + (x >> 3);

for (i = 0; i < height; i++) {

	*plotLocation |= *(bitmap++);

	plotLocation += 40;

}

}

void plotBitmap16(UINT16* base, UINT16* bitmap, int x, int y, int height) {

int i;

UINT16 *plotLocation = base + (y * 40) + (x >> 4);

for (i = 0; i < height; i++) {

	*plotLocation &= *(bitmap++);

	plotLocation += 40;

}

}

void plotScreen(UINT32* base, UINT32* bitmap) {

	int i;

	for (i = 0; i < SCREEN_BYTE_SIZE; i++) {
		*(base + 1) = bitmap[i];
	}

}

void plotRectangle(UINT8* base, int x, int y, int width, int height) {

	register int i = 0;

	UINT8 *newBase = base;

	for (i = 0; i < height; i++) {

		plotHorizontalLine(newBase, x, y, width);
		
		newBase += 80;

	}


}

void clearRegion8(UINT8 *base, int x, int y, int width, int height) {



}

void clearRegion16(UINT16 *base, int x, int y, int width, int height) {



}

void clearRegion32(UINT32 *base, int x, int y, int width, int height) {



}

void clearRegion(void* base, int x, int y, int width, int height) {



}