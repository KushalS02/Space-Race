#include <osbind.h>
#include "raster.h"
#include "sprites.h"
#include "const.h"
#include "background.h"

int main()
{
	void *base = Physbase();
	
	short i;

	clearScreen(base);

	plotScreen(base, background);

	plotPixel(base, 135, 120); 

	plotVerticalLine(base, 80, 80, 50);

	plotHorizontalLine(base, 120, 120, 80);

	plotRectangle(base, 200, 100, 100, 50);

	plotBitmap8(base, astrv2, 100, 100, ASTRV2_HEIGHT);

	plotBitmap32(base, shipv2, ROCKETSHIP_STARTING_X, ROCKETSHIP_STARTING_Y, SHIPV2_HEIGHT);

	for(i = 0; i < 20; i++) {
		plotBitmap32(base, chkLine, i*32, 0, CHKLINE_HEIGHT);
	}

	return 0;
}
