#include "menu.h"

int MENU_STATE = MENU_CHOICE_1_PLAYER;
bool VALID_CLICK = false;

void menu() {

    processMenuChoice();

}

void processMenuChoice() {

    unsigned long input;

    int userChoice = MENU_CHOICE_1_PLAYER;
    
    int prevChoice = userChoice;

    int mouseChoice, prevMouseChoice;

    long oldSSP = Super(0);

    UINT16 *base = getVideoBase();

    Super(oldSSP);

    initializeMouse(base);

    drawChoiceSelector(userChoice);

    while (MENU_STATE != MENU_CHOICE_EXIT) {

        updateMouseEvents(base);

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

                selectOption(userChoice);

            }

            if (input == ESC_KEY) {

                selectOption(MENU_CHOICE_EXIT);

            } 

        } else if (hasMouseInput()) {

            prevMouseChoice = mouseChoice;

            mouseChoice = mouseLocation();

            if (mouseChoice != INVALID_CHOICE) {

                if (VALID_CLICK && MOUSE_LEFT_CLICK) {

                    selectOption(mouseChoice);

                }

            }

        }

    }

}

void selectOption(int choice) {

    switch (choice) {

    case MENU_CHOICE_1_PLAYER:

        MENU_STATE = MENU_CHOICE_1_PLAYER;
        gameLoop();
        stopSound();
        break;

    case MENU_CHOICE_2_PLAYER:

        /* Two player mode goes here */
        MENU_STATE = MENU_CHOICE_2_PLAYER;

        break;  

    case MENU_CHOICE_HELP:

        MENU_STATE = MENU_CHOICE_HELP;

        break;
    
    case MENU_CHOICE_EXIT:
    default:

        /* Default option, QUIT */
        MENU_STATE = MENU_CHOICE_EXIT;
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

int mouseLocation() {

    int mouseLocation = INVALID_CHOICE;

    bool validX = (MOUSE_X = VALID_X_LEFT && MOUSE_X <= VALID_X_RIGHT);
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
