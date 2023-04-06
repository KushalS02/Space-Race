/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: menu.c

Instructor: Paul Pospisil

*/
#include "menu.h"

int MENU_STATE = MENU_CHOICE_1_PLAYER;
bool VALID_CLICK = false;
UINT16* MENU_BUFFER;

int menu() {

    unsigned long input;

    int userChoice = MENU_CHOICE_1_PLAYER;
    
    int prevChoice = userChoice;

    int mouseChoice, prevMouseChoice;

    long oldSSP = Super(0);

    MENU_BUFFER = getVideoBase();

    Super(oldSSP);

    initializeMouse(MENU_BUFFER);

    drawChoiceSelector(userChoice);

    while (MENU_STATE != MENU_CHOICE_EXIT) {

        updateMouseEvents(MENU_BUFFER);

        if (hasUserInput()) {

            clearChoiceSelector(mouseChoice);

            prevChoice = userChoice;

            input = getUserInput();
            
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

                return userChoice;

            }

            if (input == ESC_KEY) {

                return MENU_CHOICE_EXIT;

            } 

        } else if (hasMouseInput()) {

            prevMouseChoice = mouseChoice;

            mouseChoice = mouseLocation();

            if (mouseChoice != INVALID_CHOICE) {

                if (VALID_CLICK && MOUSE_LEFT_CLICK) {

                    return mouseChoice;

                }

            }

        }

    }

}

void drawChoiceSelector(int choice) {
    
    /* 1 player */
    if (choice == 1) {

        plotBitmap16(MENU_BUFFER, menuArrow, ARROW_X, ARROW_1_PLAYER_Y, ARROW_HEIGHT);

    } else if (choice == 2) { /* 2 player */

        plotBitmap16(MENU_BUFFER, menuArrow, ARROW_X, ARROW_2_PLAYER_Y, ARROW_HEIGHT);

    } else if (choice == 3) { /* tutorial */

        plotBitmap16(MENU_BUFFER, menuArrow, ARROW_X, ARROW_TUTORIAL_Y, ARROW_HEIGHT);

    } else if (choice == 4) { /* exit */

        plotBitmap16(MENU_BUFFER, menuArrow, ARROW_X, ARROW_HELP_Y, ARROW_HEIGHT);

    } 

}


void clearChoiceSelector(int choice) {
    
    int arrowY;

    if (choice == 1) { /* 1 player */

        arrowY = ARROW_1_PLAYER_Y;

    } else if (choice == 2) { /* 2 player */

        arrowY = ARROW_2_PLAYER_Y;

    } else if (choice == 3) { /* tutorial */

        arrowY = ARROW_TUTORIAL_Y;

    } else if (choice == 4) { /* exit */

        arrowY = ARROW_HELP_Y;

    } 

    clearRegion16(MENU_BUFFER, ARROW_X, arrowY, ARROW_WIDTH, ARROW_HEIGHT);

}


int mouseLocation() {

    int mouseLocation = INVALID_CHOICE;

    bool validX = (MOUSE_X >= VALID_X_LEFT && MOUSE_X <= VALID_X_RIGHT);
    bool validOnePlayer = (MOUSE_Y >= VALID_1_PLAYER_TOP_Y && MOUSE_Y <= VALID_1_PLAYER_BOTTOM_Y);
    bool validTwoPlayer = (MOUSE_Y >= VALID_2_PLAYER_TOP_Y && MOUSE_Y <= VALID_2_PLAYER_BOTTOM_Y);
    bool validTutorial = (MOUSE_Y >= VALID_TUTORIAL_TOP_Y && MOUSE_Y <= VALID_TUTORIAL_BOTTOM_Y);
    bool validExit = (MOUSE_Y >= VALID_EXIT_TOP_Y && MOUSE_Y <= VALID_EXIT_BOTTOM_Y);
    
    if (validX && validOnePlayer) {

        mouseLocation = MENU_CHOICE_1_PLAYER;

    } else if (validX && validTwoPlayer) {

        mouseLocation = MENU_CHOICE_2_PLAYER;
        
    } else if (validX && validTutorial) {

        mouseLocation = MENU_CHOICE_HELP;
        
    } else if (validX && validExit) {

        mouseLocation = MENU_CHOICE_EXIT;
        
    }

    VALID_CLICK = (validX && validOnePlayer) || 
                  (validX && validTwoPlayer) ||
                  (validX && validTutorial) ||
                  (validX && validExit);

    return mouseLocation;

}
