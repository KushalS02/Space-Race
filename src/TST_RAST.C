#include <osbind.h>
#include "raster.h"
#include "sprites.h"

int main()
{
	void *base = Physbase();

	clearScreen(base);

	plotRectangle(base, 0, 0, 640, 400);

	plotBitmap32(base, shipv2, 0, 0, SHIPV2_HEIGHT);

	return 0;
}
