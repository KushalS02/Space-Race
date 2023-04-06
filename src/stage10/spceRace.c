/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: spceRace.c

Instructor: Paul Pospisil

*/
#include "spceRace.h"
#include <osbind.h>
#include <string.h>

const UINT8 secondBuff[SCREEN_BUFFER_SIZE];

extern int MUSIC_TIMER;
extern bool RENDER_REQUEST;
extern bool KEY_REPEATED;
UINT8 currScore;

bool quit = false;

int main() {

    installVectors();    
    start();
    removeVectors();
    return 0;

}

void start() {

    UINT16* base;
    long oldSSP;
    int userChoice;

    oldSSP = Super(0);
    base = getVideoBase();
    Super(oldSSP);

    disableCursor();

    while (quit == false) {
        RENDER_MOUSE_REQUEST = false;
        renderSplashscreen((UINT32 *)base);
        clearIkbdBuffer();
        userChoice = menu();

        switch (userChoice)
        {
        case MENU_CHOICE_1_PLAYER:

            gameLoop();
            clearIkbdBuffer();
            quit = displayGameOver(base);

            break;

        case MENU_CHOICE_2_PLAYER:

            /* Two player mode goes here */

            break;

        case MENU_CHOICE_HELP:

            break;

        case MENU_CHOICE_EXIT:
        default:

            /* Default option, QUIT */
            quit = true;
            break;

        }

    }

}

UINT8 *getBase(UINT8 *secondBuffer) {

    unsigned long add = (unsigned long) secondBuffer;
    unsigned long base = (add + 0xFF) & ~(unsigned long) 0xFF;

    return (UINT8*) base;

}


void gameLoop() {
    
    long oldSSP;
    Model model;
    bool swapScreens = false;
    void *screen2;
    UINT16* base;
    UINT16 *currScreen = base;
    UINT32 prevCall;
    currScore = 0;

    oldSSP = Super(0);
    base = getVideoBase();

    Super(oldSSP);

    screen2 = getBase(secondBuff);

    gameSetup(&model, base);
    memcpy(screen2, base, 32000);
    startMusic();

    while (!model.gameOver && model.scorebox.score <= MAX_SCORE) {

        if(updateMusic(MUSIC_TIMER)) {

            MUSIC_TIMER = 0;
        }

        if(currScore < model.scorebox.score) {
            renderNextRound(&model, base);
            renderNextRound(&model, screen2);
            currScore = model.scorebox.score;
        }

        if (RENDER_REQUEST == true) {

            if (swapScreens) {

                currScreen = base;
                clearGame(currScreen);

            } else {

                currScreen = screen2;
                clearGame(currScreen);
                
            }

            processAsyncEvents(&model);
            processSyncEvents(&model);

            renderAsteroids(model.asteroids, (UINT8*)currScreen);
            renderRocketship(&model.player, (UINT32*)currScreen);

            oldSSP = Super(0);
            setVideoBase((UINT16*)currScreen);
            Super(oldSSP);

            RENDER_REQUEST = false;
            swapScreens = !swapScreens;

        }

    }

    oldSSP = Super(0);
    setVideoBase((UINT16*)base);
    Super(oldSSP);

    stopSound();
    
}

void processAsyncEvents(Model *model) {

    unsigned long input;

    if(hasUserInput() || KEY_REPEATED == true) {

        rocketshipHitBoundary(&model->player);

        if (hasUserInput()) {

            input = getUserInput();

        } else {

            input = repeatedKey;
        
        }

        rocketshipMove(&model->player, input);

        if (rocketshipHitFinish(&model->player)) {

            initializeNextRound(&(model->player), model->asteroids, &(model->scorebox), &(model->highscorebox));
        }

        if (input == ESC_KEY) {

            onGameOver(model);

        }

    }

}

void processSyncEvents(Model *model) {

    onAsteroidsMove(model);
    rocketshipAsteroidCollision(model);

}

void gameSetup(Model* model, void *base) {

    disableCursor();

    onGameStart(model);

    render(model, base);

}

bool displayGameOver(void* base) {

    unsigned long input;

    renderGameOver(base, currScore);

    while (input != ESC_KEY) {

        if (hasUserInput()) {

            input = getUserInput();

        }

        if (input == ENTER_KEY){

            return false;

        }
    }

    return true;

}

