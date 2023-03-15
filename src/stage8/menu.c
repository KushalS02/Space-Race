#include "menu.h"

void menu() {

    processMenuChoice();

}

void processMenuChoice() {

    unsigned long input;

    int userChoice = MENU_CHOICE_1_PLAYER;
    
    int prevChoice = choice;

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

    switch (option) {

    case MENU_CHOICE_1_PLAYER:

        gameLoop();

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

            /* plot the selector bitmap */

            break;

        case 2:

            /* plot the selector bitmap */

            break;


        case 3:

            /* plot the selector bitmap */

            break;


        case 4:

            /* plot the selector bitmap */

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

            /* clear the selector */

            break;

        case 2:

            /* clear the selector */

            break;

        case 3:

            /* clear the selector */

            break;

        case 4:

            /* clear the selector */

            break;

    }

}