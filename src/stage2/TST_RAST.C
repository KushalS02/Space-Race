/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: TST_RAST.C

Instructor: Paul Pospisil

*/
#include <osbind.h>
#include "raster.h"
#include "sprites.h"
#include "const.h"

int main()
{
	void *base = Physbase();
	
	short i;

	clearScreen(base);

	plotRectangle(base, 0, 0, 640, 400);

	plotBitmap8(base, astrv2, 10, 20, ASTRV2_HEIGHT);

	plotBitmap32(base, shipv2, ROCKETSHIP_STARTING_X, ROCKETSHIP_STARTING_Y, SHIPV2_HEIGHT);

	for(i = 0; i < 20; i++) {
		plotBitmap32(base, chkLine, i*32, 0, CHKLINE_HEIGHT);
	}

	printString(base, SCOREBOX_X, SCOREBOX_Y, "Score: 000");

	printString(base, HIGHSCOREBOX_X, HIGHSCOREBOX_Y, "Highscore: 999");

	return 0;
}
