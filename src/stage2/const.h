#ifndef CONST_H
#define CONST_H

#include "TYPES.H"

/*
Screen stuff
*/
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define SCREEN_BYTE_SIZE 8000

/*
Sprites Constants
*/
#define SHIPV2_HEIGHT 47
#define ASTRV2_HEIGHT 8
#define CHKLINE_HEIGHT 8

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
#define ASTEROID_ROWS 20

/*
Scorebox Position
*/
#define SCOREBOX_X 10
#define SCOREBOX_Y 10

/*
Highscore box Position
*/
#define HIGHSCOREBOX_X 384
#define HIGHSCOREBOX_Y 10

/*
Keyboard key codes
*/
#define UP_KEY 0x00480000
#define DOWN_KEY 0x00500000

#endif