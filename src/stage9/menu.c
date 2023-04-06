/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: menu.c

Instructor: Paul Pospisil

*/
#include "menu.h"

bool VALID_CLICK = false;

void menu() {

    processMenuChoice();

}

void processMenuChoice() {

    unsigned long input;

    int userChoice = MENU_CHOICE_1_PLAYER;
    
    int prevChoice = userChoice;

    int mouseChoice, prevMouseChoice;

    drawChoiceSelector(userChoice);

    while (input != ESC_KEY && input != ENTER_KEY) {

        if (hasUserInput()) {

            input = getUserInput();

            prevChoice = userChoice;
            
            switch (input) {

                case UP_KEY:

                    if (userChoice > MENU_CHOICE_1_PLAYER) {

                        userChoice--;

                    }

                    break;

                case DOWN_KEY:

                    if (userChoice < MENU_CHOICE_EXIT) {

                        userChoice++;

                    }

                    break;

                default:

                    break;

            }

            clearChoiceSelector(prevChoice);

            drawChoiceSelector(userChoice);

            if (input == ENTER_KEY) {

                selectOption(userChoice);

            }

            if (input == ESC_KEY) {

                selectOption(MENU_CHOICE_EXIT);

            } 

        }

    }

}

void selectOption(int choice) {

    switch (choice) {

    case MENU_CHOICE_1_PLAYER:

        gameLoop();
        stopSound();
        break;

    case MENU_CHOICE_2_PLAYER:

        /* Two player mode goes here */

        break;  

    case MENU_CHOICE_HELP:

        /* Help choice goes here */  

        break;
    
    default:
        /* Default option, QUIT */
        break;
    }

}

void drawChoiceSelector(int choice) {

    long oldSSP = Super(0);

    UINT16 *base = getVideoBase();

    Super(oldSSP);

    switch (choice) {

        default:

        case 1:

            plotBitmap16(base, menuArrow, ARROW_X, ARROW_1_PLAYER_Y, ARROW_HEIGHT);

            break;

        case 2:

            plotBitmap16(base, menuArrow, ARROW_X, ARROW_2_PLAYER_Y, ARROW_HEIGHT);

            break;


        case 3:

            plotBitmap16(base, menuArrow, ARROW_X, ARROW_TUTORIAL_Y, ARROW_HEIGHT);

            break;


        case 4:

            plotBitmap16(base, menuArrow, ARROW_X, ARROW_HELP_Y, ARROW_HEIGHT);

            break;

    }

}

void clearChoiceSelector(int choice) {

    long oldSSP = Super(0);

    UINT16 *base = getVideoBase();

    Super(oldSSP);

    switch (choice) {

        default:

        case 1:

            clearRegion16(base, ARROW_X, ARROW_1_PLAYER_Y, ARROW_WIDTH, ARROW_HEIGHT);

            break;

        case 2:

            clearRegion16(base, ARROW_X, ARROW_2_PLAYER_Y, ARROW_WIDTH, ARROW_HEIGHT);

            break;

        case 3:

            clearRegion16(base, ARROW_X, ARROW_TUTORIAL_Y, ARROW_WIDTH, ARROW_HEIGHT);

            break;

        case 4:

            clearRegion16(base, ARROW_X, ARROW_HELP_Y, ARROW_WIDTH, ARROW_HEIGHT);

            break;

    }

}

