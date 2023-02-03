#ifndef RASTER_H
#define RASTER_H

#include "types.h"


void plot_something_2(UINT32 *base, int x, int y, ...);

/* plotting funcions */

void plotPixel(UINT8* UINT8, int x, int y); 

void plotVerticalLine(UINT8* base, int x, int y, int height); 

void plotHorizontalLine(UINT8* base, int x, int y, int length); 

void plotBitmap8(UINT8* base, int x, int y, UINT8* bitmap, int height);

void plotBitmap16(UINT16* base, int x, int y, UINT16* bitmap, int height);

/* clearing functions */

void clearRegion(void* base, int x, int y, int width, int height);



#endif
