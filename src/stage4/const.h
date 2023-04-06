/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: const.h

Instructor: Paul Pospisil

*/
#ifndef CONST_H
#define CONST_H

#include "TYPES.H"

/*
Screen stuff
*/
#define SCREEN_WIDTH 640
#define MIN_XPOS 0
#define WIDTH_BYTES 40
#define SCREEN_HEIGHT 400
#define HEIGHT_BYTES 25
#define SCREEN_BYTE_SIZE 8000
#define RECT_PLOT_X 0
#define RECT_PLOT_Y 0

/*
Sprites Constants
*/
#define SHIPV2_HEIGHT 47
#define SHIPV2_WIDTH 32
#define ASTRV2_HEIGHT 8
#define ASTRV2_WIDTH 8
#define CHKLINE_HEIGHT 6

/*
Rocketship Constants 
*/
#define ROCKETSHIP_STARTING_X 304
#define ROCKETSHIP_STARTING_Y 353
#define ROCKETSHIP_SPEED 1 

/*
Asteroids Constants
*/
#define ASTEROID_SPEED 1
#define ASTEROID_MAX 20
#define ASTEROID_STARTING_Y 32
#define ASTEROID_BOX_SIZE 16 /* ACTUAL SIZE OF THE ASTEROID NOT HITBOX*/

/*
Scorebox Position
*/
#define SCOREBOX_X 10
#define SCOREBOX_Y 0

/*
Highscore box Position
*/
#define HIGHSCOREBOX_X 525
#define HIGHSCOREBOX_Y 0

/*
Score Stuff
*/
#define MAX_SCORE 999

/*
Keyboard key codes
*/
#define UP_KEY 0x48
#define DOWN_KEY 0x50
#define ESC_KEY 0x01

/*
Other stuff
*/
#define SPRITE_SIZE 16
#define SPRITE_HEIGHT 16

#endif