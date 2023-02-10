#include <osbind.h>
#include "raster.h"
#include "sprites.h"

int main()
{
	void *base = Physbase();
	short i;

	clearScreen(base);

	/* plotPixel(base, 50, 50); */

	plotBitmap8(base, astrv2, 100, 100, ASTRV2_HEIGHT);


	/*
	plotRectangle(base, 0, 0, 640, 400);
	*/

	plotBitmap32(base, shipv2, 304, 353, SHIPV2_HEIGHT);

	for(i = 0; i < 20; i++) {
		plotBitmap32(base, chkLine, i*32, 0, CHKLINE_HEIGHT);
	}

	return 0;
}
