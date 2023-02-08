#ifndef RASTER_H
#define RASTER_H

#include "types.h"

/* plotting funcions */

void plotPixel(UINT8* UINT8, int x, int y); 

void plotVerticalLine(UINT8* base, int x, int y, int height); 

void plotHorizontalLine(UINT8* base, int x, int y, int length); 

void plotBitmap8(UINT8* base, UINT8* bitmap, int x, int y, int height);

void plotBitmap16(UINT16* base, UINT16* bitmap, int x, int y, int height);

void plotScreen(UINT32* base, UINT32* bitmap);

void plotRectangle(UINT8* base, int x, int y, int width, int height);

/* clearing functions */

void clearRegion(void* base, int x, int y, int width, int height);

void clearRegion8(UINT8 *base, int x, int y, int width, int height);

void clearRegion16(UINT16 *base, int x, int y, int width, int height);

void clearRegion32(UINT32 *base, int x, int y, int width, int height);

#endif
