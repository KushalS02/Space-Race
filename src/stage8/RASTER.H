#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include "const.h"
#include "font.h"

/* plotting funcions */

void plotPixel(UINT8* base, int x, int y); 

void plotVerticalLine(UINT8* base, int x, int y, int height); 

void plotHorizontalLine(UINT8* base, int x, int y, int length); 

void plotBitmap8(UINT8* base, UINT8* bitmap, int x, int y, int height);

void plotBitmap16(UINT16* base, UINT16* bitmap, int x, int y, int height);

void plotBitmap32(UINT32* base, UINT32* bitmap, int x, int y, int height);

void plotScreen(UINT32* base, UINT32* bitmap);

void plotRectangle(UINT8* base, int x, int y, int width, int height);

/* 
Print char, string and number
*/

void printChar(UINT8 *base, int x, int y, char ch);

void printString(UINT8 *base, int x, int y, char *string);

void printNumber(UINT8 *base, int x, int y, UINT16 num);

/* clearing functions */

void clearRegion(void* base, int x, int y, int width, int height);

void clearRegion8(UINT8 *base, int x, int y, int width, int height);

void clearRegion16(UINT16 *base, int x, int y, int width, int height);

void clearRegion32(UINT32 *base, int x, int y, int width, int height);

void clearScreen(UINT8 *base);

void clearHorizontalLine8(UINT8* base, int x, int y, int length);

void clearHorizontalLine16(UINT16* base, int x, int y, int length);

void clearHorizontalLine32(UINT32* base, int x, int y, int length);

void clearHorizontalLine(void *base, int x, int y, int length);

/*
Physbase()
*/
UINT16 *getVideoBase();

/*
Setscreen()
*/
void setVideoBase(UINT16 *);


#endif
