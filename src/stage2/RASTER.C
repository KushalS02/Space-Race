/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: RASTER.C

Instructor: Paul Pospisil

*/
#include "raster.h"
#include "const.h"
#include "font.h"

void plotPixel(UINT8* base, int x, int y) {

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {

		*(base + y * 80 + (x >> 3)) ^= 1 << 7 - (x & 7); 

	}

}

void clearPixel(UINT8* base, int x, int y) {

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {

		*(base + y * 80 + (x >> 3)) &= 0 << 7 - (x & 7); 

	}

}

void plotVerticalLine(UINT8* base, int x, int y, int height) {

	int i;

	for (i = 0; i < height; i++) {

		*(base + ((y + i) * 80) + (x >> 3)) ^= 1 << 7 - (x & 7);

	}

}

void plotHorizontalLine(UINT8* base, int x, int y, int length) {

	int i;
	int counter = length >> 3;

	UINT8 *drawLine = base + (y * 80) + (x >> 3);

	for (i = 0; i < counter; i++){

		*(drawLine++) ^= 0xff;
	}

}

void plotBitmap8(UINT8* base, UINT8* bitmap, int x, int y, int height) {

int i;

UINT8 *plotLocation = base + (y * 80) + (x >> 3);

	for (i = 0; i < height; i++) {

		*plotLocation ^= *(bitmap++);

		plotLocation += 80;

	}

}

void plotBitmap16(UINT16* base, UINT16* bitmap, int x, int y, int height) {

int i;

UINT16 *plotLocation = base + (y * 40) + (x >> 4);

for (i = 0; i < height; i++) {

	*plotLocation ^= *(bitmap++);

	plotLocation += 40;

}
}

void plotBitmap32(UINT32* base, UINT32* bitmap, int x, int y, int height) {
	
	int i = 0;
	
	UINT32 *plotLocation = base + (y * 20) + (x >> 5);

	for (i = 0; i < height; i++) {
		*plotLocation ^= *(bitmap++);
		plotLocation += 20;
	}
}

void plotScreen(UINT32* base, UINT32* bitmap) {

	int i;

	for (i = 0; i < SCREEN_BYTE_SIZE; i++) {

		*(base + i) = bitmap[i];

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

void clearHorizontalLine8(UINT8* base, int x, int y, int length) {

	int i;
	int counter = length >> 3;

	UINT8 *clearLine = base + (y * 80) + (x >> 3);

	for (i = 0; i < counter; i++){

		*(clearLine++) &= 0x00;
	}

}

void clearHorizontalLine16(UINT16* base, int x, int y, int length) {

	int i;

	int counter = length >> 4;

	UINT16 *clearLine = base + (y * 40) + (x >> 4);

	for(i = 0; i < counter; i++) {

		*(clearLine) = 0xffff;

	}

}

void clearHorizontalLine32(UINT32* base, int x, int y, int length) {

	int i;

	int counter = length >> 5;

	UINT32 *clearLine = base + (y * 20) + (x >> 5);

	for(i = 0; i < counter; i++) {

		*(clearLine) = 0xffffffff;
		
	}
}

void clearHorizontalLine(void *base, int x, int y, int length) {

	if (length <= 8) {

		clearHorizontalLine8(base, x, y, length);

	} else if (length <= 16) {

		clearHorizontalLine16(base, x, y, length);

	} else {

		clearHorizontalLine32(base, x, y, length);

	}

}

void clearRegion8(UINT8 *base, int x, int y, int width, int height) {

	int i;

	UINT8 *clearArea = base;

	for (i = 0; i < height; i++) {

		clearHorizontalLine(clearArea, x, y, width);

		clearArea += 80;

	}

}

void clearRegion16(UINT16 *base, int x, int y, int width, int height) {

	int i;

	UINT16 *clearArea = base;

	for (i = 0; i < height; i++) {

		clearHorizontalLine(clearArea, x, y, width);

		clearArea += 40;

	}

}

void clearRegion32(UINT32 *base, int x, int y, int width, int height) {

	int i;

	UINT32 *clearArea = base;

	for (i = 0; i < height; i++) {

		clearHorizontalLine(clearArea, x, y, width);

		clearArea += 20;

	}

}

void clearRegion(void* base, int x, int y, int width, int height) {

	if (width <= 8) {
		
		clearRegion8(base, x, y, width, height);

	} else if (width <= 16) {

		clearRegion16(base, x, y, width, height);

	} else {

		clearRegion32(base, x, y, width, height);

	}

}


void clearScreen(UINT8 *base) {
	
	int i = 0;

	UINT8 *newBase = base;

	for (i = 0; i < SCREEN_HEIGHT; i++) {

		clearHorizontalLine8(newBase, 0, 0, SCREEN_WIDTH);
		
		newBase += 80;
	}
}

void printChar(UINT8 *base, int x, int y, char ch) {

	int i;

		UINT8 *charHexCode = GLYPH_START(ch); 

	for (i = 0; i < 8; i++, charHexCode++) {

		*(base + (y + i) * 80 + (x >> 3)) = *charHexCode;

	}

}

void printString(UINT8 *base, int x, int y, char *string) {

  int i = 0;

  while (string[i] != '\0') {

	 printChar(base, x, y, string[i]); 
	i++;
	x += 8;

  }

}

void printNumber(UINT8 *base, int x, int y, UINT16 num) {

	char a, b, c, d;
	
	d = (num % 10) + '0';
  	num /= 10;

  	c = (num % 10) + '0';
  	num /= 10;

  	b = (num % 10) + '0';
  	num /= 10;

  	a = (num % 10) + '0';

	printChar(base, x, y, a);
  	printChar(base, x + 8, y, b);
  	printChar(base, x + 16, y, c);
  	printChar(base, x + 24, y, d);
	

}
