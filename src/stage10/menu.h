/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: menu.h

Instructor: Paul Pospisil

*/

#ifndef MENU_H
#define MENU_H

#include <osbind.h>
#include <stdio.h>
#include "TYPES.H"
#include "const.h"
#include "events.h"
#include "splash.h"
#include "spceRace.h"
#include "RASTER.H"
#include "sprites.h"

/*
Menu options 
*/
#define MENU_CHOICE_1_PLAYER 1
#define MENU_CHOICE_2_PLAYER 2
#define MENU_CHOICE_HELP 3
#define MENU_CHOICE_EXIT 4

#define INVALID_CHOICE -1

extern bool VALID_CLICK;
extern int MENU_STATE;
extern UINT16* MENU_BUFFER;

/*
mouse valid locations
*/
#define VALID_X_LEFT 272
#define VALID_X_RIGHT 368
#define VALID_1_PLAYER_TOP_Y 187
#define VALID_1_PLAYER_BOTTOM_Y 220
#define VALID_2_PLAYER_TOP_Y 230
#define VALID_2_PLAYER_BOTTOM_Y 263
#define VALID_TUTORIAL_TOP_Y 273
#define VALID_TUTORIAL_BOTTOM_Y 299
#define VALID_EXIT_TOP_Y 315
#define VALID_EXIT_BOTTOM_Y 341

/*
Menu functions 
*/

/*

    Function: menu

    Purpose: to control the main and loop it through

*/
int menu();

/*

    Function: processMenuChoice

    Purpose: based on the up and down arrows, update the 
             selection based on the user's choice

*/
void processMenuChoice();

/*

    Function: selectOption

    Purpose: selects one of the menu options by pressing enter

    Parameters:

        - int choice - the user will be able to select one of the
                       four options, 1 player, 2 player, tutorial 
                       or exit from 1 to 4

*/
void selectOption(int choice);

/*

    Function: drawChoiceSelector

    Purpose: draw the menu arrow based on user's choice

    Parameter: 

        - int choice - the menu choice number the user selects

*/
void drawChoiceSelector(int choice);

/*

    Function: clearChoiceSelector

    Purpose: clear the menu selector from the previous choice

    Parameter:

        - int choice - the previous menu choice that is to be 
                       cleared

*/
void clearChoiceSelector(int choice);

/*

    Function: mouseLocation

    Purpose: get the current location of where the mouse

    Returns: the menu choice if the mouse pointer is within the x and y of
             the menu options

*/
int mouseLocation();

#endif