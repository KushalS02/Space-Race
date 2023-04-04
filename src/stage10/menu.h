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
int menu();

void processMenuChoice();

void selectOption(int choice);

void drawChoiceSelector(int choice);

void clearChoiceSelector(int choice);

int mouseLocation();

#endif