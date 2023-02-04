#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_something_2(UINT32 *base, int x, int y, ...);

<<<<<<< HEAD
/* plotting funcions */

void plotPixel(UINT8* UINT8, int x, int y); 

void plotVerticalLine(UINT8* base, int x, int y, int height); 

void plotHorizontalLine(UINT8* base, int x, int y, int length); 

void plotBitmap8(UINT8* base, int x, int y, UINT8* bitmap, int height);

void plotBitmap16(UINT16* base, int x, int y, UINT16* bitmap, int height);

/* clearing functions */

void clearRegion(void* base, int x, int y, int width, int height);

=======
//our functions here
void plotPixel(UINT8* base, int x, int y); //plot pixel
void plotVerticalLine(UINT8* base, int x, int y, int height); //plot a vertical line
void plotHorizontalLine(UINT8* base, int x, int y, int length); //plot horizontal line
>>>>>>> a5d3618565b94f05715b4bdac5b3c049cab88de9


#endif
