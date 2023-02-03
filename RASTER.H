#ifndef RASTER_H
#define RASTER_H

#include "types.h"


void plot_something_2(UINT32 *base, int x, int y, ...);

/*our functions here*/
void plotPixel(UINT8* UINT8, int x, int y); /*plot pixel*/

void plotVerticalLine(UINT8* base, int x, int y, int height); /*plot a vertical line*/

void plotHorizontalLine(UINT8* base, int x, int y, int length); /*plot horizontal line */

void clearRegion(void* base, int x, int y, int width, int height);



#endif
