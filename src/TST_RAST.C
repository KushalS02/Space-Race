#include <osbind.h>
#include "raster.h"
#include "sprites.h"

int main()
{
	void *base = Physbase();

	clearScreen(base);

	/* plotPixel(base, 50, 50); */

	plotBitmap8(base, astrv1, 120, 120, ASTRV1_HEIGHT);

	plotBitmap8(base, astrv2, 100, 100, ASTRV2_HEIGHT);


	/*
	plotRectangle(base, 0, 0, 640, 400);
	*/

	plotBitmap32(base, shipv2, 0, 0, SHIPV2_HEIGHT);

	return 0;
}
