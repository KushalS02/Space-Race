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

                selectOption(choice);

            }

            if (input == ESC_KEY) {

                selectOption(MENU_CHOICE_EXIT);

            }

        }

    }

}

void selectOption(int choice) {



}

void drawChoiceSelector(int choice) {



}

void clearChoiceSelector(int choice) {



}