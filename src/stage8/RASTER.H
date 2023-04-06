/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: RASTER.H

Instructor: Paul Pospisil

*/
#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include "const.h"
#include "font.h"

/* plotting funcions */

/*

Name: plotPixel

Purpose: to plot a pixel anywhere on the screen

Parameters: 
	
	UINT8 *base - start of the frame buffer

	int x - the x location where the pixel is to be ploted

	int y - the y location where the pixel is to be ploted 

	1 << 7 - (x & 7) - the selected bit to plot the pixel 

	*(base + y * 80 + (x >> 3)) - get the address of the byte to modify 


*/
void plotPixel(UINT8* base, int x, int y);

/*

Name: plotVerticalLine

Purpose: to plot a vertical line on the screen

Parameters:

	UINT8 *base - start of the frame buffer

	int x - the x starting coordinate of the line

	int y - the y starting coordinate of the line

	int height - the height of the line that is being plotted

	1 << 7 - (x & 7) - the selected bit to plot the pixel 

	*(base + y * 80 + (x >> 3)) - get the address of the byte to modify 

*/
void plotVerticalLine(UINT8* base, int x, int y, int height); 

/*

Name: plotHorizontalLine

Purpose: plot a horizontal line on the screen

Parameters:

	UINT8 *base - start of the frame buffer

	int x - the x starting coordinate of the line

	int y - the y starting coordinate of the line

	int length - the length of the line that is being plotted

	1 << 7 - (x & 7) - the selected bit to plot the pixel 

	*(base + y * 80 + (x >> 3)) - get the address of the byte to modify 

*/
void plotHorizontalLine(UINT8* base, int x, int y, int length); 

/*

Name: plotBitmap8

Purpose: plot an 8 x height bitmap onto the screen

Parameters: 

    UINT8 *base - start of the frame buffer

    UINT8 *bitmap - the bitmap that is to be plotted

    int x - the top left corner of the bitmap (x value)

    int y = the top left corner of the bitmap (y value)

    int height - the height of the bitmap being plotted

*/
void plotBitmap8(UINT8* base, UINT8* bitmap, int x, int y, int height);

/*

Name: plotBitmap16

Purpose: plot an 16 x height bitmap onto the screen

Parameters: 

    UINT16 *base - start of the frame buffer

    bitmap - the bitmap that is to be plotted

    int x - the top left corner of the bitmap (x value)

    int y = the top left corner of the bitmap (y value)

    int height - the height of the bitmap being plotted

*/
void plotBitmap16(UINT16* base, UINT16* bitmap, int x, int y, int height);

/*

Name: plotBitmap32

Purpose: plot an 32 x height bitmap onto the screen

Parameters: 

    UINT32 *base - start of the frame buffer

    UINT32 *bitmap - the bitmap that is to be plotted

    int x - the top left corner of the bitmap (x value)

    int y = the top left corner of the bitmap (y value)

    int height - the height of the bitmap being plotted

*/
void plotBitmap32(UINT32* base, UINT32* bitmap, int x, int y, int height);

/*

Name: plotScreen

Purpose: plot a background/bitmap to the entire screen 

Parameters:

    UINT32 *base - start of the frame buffer

    UINT32 *bitmap - the bitmap that is to be plotted onto the screen

*/
void plotScreen(UINT32* base, UINT32* bitmap);

/*

Name: plotRectangle

Purpose: to plot a rectangle onto the screen 

Parameters:

    UINT8 *base - start of the frame buffer

    int x - the starting x location (top left corner) of the rectangle

    int y - the starting y location (top left corner) of the rectangle 

    int width - the width of the rectangle

    int height - the height of the rectangle

*/

void plotRectangle(UINT8* base, int x, int y, int width, int height);

/* 
Print char, string and number
*/

/*

Name: printChar 

Purpose: to print a single character onto the screen 

Parameters:

    UINT8 *base - start of the frame buffer

    int x - the starting x location of the character 

    int y - the starting y location of the character

    char ch - the character that is to be printed 

*/
void printChar(UINT8 *base, int x, int y, char ch);

/*

Name: printString 

Purpose: to print a string onto the screen 

Parameters:

    UINT8 *base - start of the frame buffer

    int x - the starting x location of the string 

    int y - the starting y location of the string

    char string - the string that is to be printed 

*/
void printString(UINT8 *base, int x, int y, char *string);

/*

Name: printNumber 

Purpose: to print a number onto the screen 

Parameters:

    UINT8 *base - start of the frame buffer

    int x - the starting x location of the number 

    int y - the starting y location of the number

    UINT16 num - the number that is to be printed 

*/
void printNumber(UINT8 *base, int x, int y, UINT16 num);

/* clearing functions */

/*

Name: clearPixel 

Purpose: to turn off (clear) the pixel that is on

Parameters:

	base - start of the frame buffer

	int x - the x location where the pixel is to be ploted

	int y - the y location where the pixel is to be ploted 

	1 << 7 - (x & 7) - the selected bit to plot the pixel 

	*(base + y * 80 + (x >> 3)) - get the address of the byte to modify 

*/
void clearPixel(UINT8* base, int x, int y);

/*

Name: clearRegion

Purpose: clears a specific region on the screen based on what is needed, 8, 16 or 32 bits

Parameters:

    void* base - start of the frame buffer

    int x - starting x (top left corner) 

    int y - starting y (top left corner)

    int width - width of the region to be cleared

    int height - height of the region to be cleared

*/
void clearRegion(void* base, int x, int y, int width, int height);

/*

Name: clearRegion8

Purpose: clears an 8 bit region on the screen

Parameters:

    UINT8 *base - start of the frame buffer

    int x - starting x (top left corner) 

    int y - starting y (top left corner)

    int width - width of the region to be cleared

    int height - height of the region to be cleared

*/
void clearRegion8(UINT8 *base, int x, int y, int width, int height);

/*

Name: clearRegion16

Purpose: clears an 16 bit region on the screen

Parameters:

    UINT16 *base - start of the frame buffer

    int x - starting x (top left corner) 

    int y - starting y (top left corner)

    int width - width of the region to be cleared

    int height - height of the region to be cleared

*/
void clearRegion16(UINT16 *base, int x, int y, int width, int height);

/*

Name: clearRegion32

Purpose: clears an 32 bit region on the screen

Parameters:

    UINT32 *base - start of the frame buffer

    int x - starting x (top left corner) 

    int y - starting y (top left corner)

    int width - width of the region to be cleared

    int height - height of the region to be cleared

*/
void clearRegion32(UINT32 *base, int x, int y, int width, int height);

/*

Name: clearScreen

Purpose: clears the entire screen 

Parameters:

    UINT8 *base - start of the frame buffer

*/
void clearScreen(UINT8 *base);

/*

Name: clearHorizontalLine8

Purpose: clear a horizontal line on the screen if it is 8 bits

Parameter:

    UINT8* base - start of the frame buffer

    int x - starting x of the line to be cleared

    int y - starting y of the line to be cleared

    int length - the length of the line to be cleared

*/
void clearHorizontalLine8(UINT8* base, int x, int y, int length);

/*

Name: clearHorizontalLine16

Purpose: clear a horizontal line on the screen if it is 16 bits

Parameter:

    UINT16* base - start of the frame buffer

    int x - starting x of the line to be cleared

    int y - starting y of the line to be cleared

    int length - the length of the line to be cleared

*/
void clearHorizontalLine16(UINT16* base, int x, int y, int length);

/*

Name: clearHorizontalLine32

Purpose: clear a horizontal line on the screen if it is 32 bits

Parameter:

    UINT32* base - start of the frame buffer

    int x - starting x of the line to be cleared

    int y - starting y of the line to be cleared

    int length - the length of the line to be cleared

*/
void clearHorizontalLine32(UINT32* base, int x, int y, int length);

/*

Name: clearHorizontalLine

Purpose: clear a horizontal line on the screen based on if its 8, 16 or 32 bits

Parameter:

    void *base - start of the frame buffer

    int x - starting x of the line to be cleared

    int y - starting y of the line to be cleared

    int length - the length of the line to be cleared

*/
void clearHorizontalLine(void *base, int x, int y, int length);

/* Physbase() */

/*

    Function: getVideoBase

    Purpose: equivalent to calling Physbase() 
        - gets the screen buffer

    Returns: the screen buffer starting address

*/
UINT16* getVideoBase();

/* Setscreen */

/*

    Function: equivalent to calling Setscreen

    Purpose: sets the current screen base to the address

    Parameter:

        - UINT16* base - the screen base 

*/


#endif
