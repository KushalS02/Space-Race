#include "raster.h"

void plot_something_1(UINT16 *base, int x, int y, ...)
{
	/* [TO DO] delete this example function */
}

void plotPixel(UINT8* base, int x, int y) {

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_WIDTH) {

		*(base + y * 80 + (x >> 3)) |= 1 << 7 - (x & 7);

	}

}

void plotVerticalLine(UINT8* base, int x, int y, int height) {



}

void plotHorizontalLine(UINT8* base, int x, int y, int length) {

	 

}