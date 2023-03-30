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
Menu functions 
*/
void menu();

void processMenuChoice();

void selectOption(int choice);

void drawChoiceSelector(int choice);

void clearChoiceSelector(int choice);

int mouseLocation();

#endif