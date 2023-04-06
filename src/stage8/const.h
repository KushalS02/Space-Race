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
#define WIDTH_BYTES 80
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
#define CHKLINE_HEIGHT 8

/*
Rocketship Constants 
*/
#define ROCKETSHIP_STARTING_X 288
#define ROCKETSHIP_STARTING_Y 353
#define ROCKETSHIP_SPEED 8

/*
Asteroids Constants
*/
#define ASTEROID_SPEED 2
#define ASTEROID_MAX 20
#define ASTEROID_STARTING_Y 32
#define ASTEROID_BOX_SIZE 16 /* ACTUAL SIZE OF THE ASTEROID NOT HITBOX*/
#define ASTEROID_SPACING 8
#define ASTEROID_MAX_Y CHKLINE_HEIGHT + 4
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
#define SCORE_INCREMENT 1

/*
Keyboard key codes
*/
#define UP_KEY 0x48
#define DOWN_KEY 0x50
#define ESC_KEY 0x01
#define ENTER_KEY 0x1C

/*
Other stuff
*/
#define SPRITE_SIZE 16
#define SPRITE_HEIGHT 16
#define SEED 1

/*
System stuff
*/
#define SYSTEM_CLOCK 0x462
#define SCREEN_BUFFER_SIZE 32256

/*
Menu stuff
*/
#define ARROW_WIDTH 16
#define ARROW_HEIGHT 16
#define ARROW_X 253
#define ARROW_1_PLAYER_Y 192
#define ARROW_2_PLAYER_Y 235
#define ARROW_TUTORIAL_Y 277
#define ARROW_HELP_Y 320

#endif