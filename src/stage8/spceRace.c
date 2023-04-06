/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: spceRace.c

Instructor: Paul Pospisil

*/
#include "spceRace.h"
#include <osbind.h>

const UINT8 secondBuff[SCREEN_BUFFER_SIZE];

int main() {

    start();

    return 0;

}

void start() {

    /*
    void *base = Physbase();
    */
    UINT16* base;
    long oldSSP;
    oldSSP = Super(0);
    base = getVideoBase();
    Super(oldSSP);

    disableCursor();
    clearQuick(base);
    renderSplashscreen((UINT32*) base);
    menu();

}

UINT8 *getBase(UINT8 *secondBuffer) {

    unsigned long add = (unsigned long) secondBuffer;
    unsigned long base = (add + 0xFF) & ~(unsigned long) 0xFF;

    return (UINT8*) base;
}


void gameLoop() {
    
    long oldSSP;
    unsigned long timeThen, timeNow, timeElapsed;
    Model model;
    bool swapScreens = false;
    /*
    UINT8 *base = Physbase();
    */
    void *screen2;
    UINT16* base;
    UINT16 *currScreen = base;
    UINT8 currScore = 0;
    UINT32 prevCall;

    oldSSP = Super(0);
    base = getVideoBase();

    Super(oldSSP);

    screen2 = getBase(secondBuff);

    prevCall = getTime();

    gameSetup(&model, base);
    render(&model, screen2);
    startMusic();

    while (!model.gameOver) {

        processAsyncEvents(&model);
        startMusic();

        if(updateMusic(getTime() - prevCall)) {

            prevCall = getTime();
       }

        if(currScore < model.scorebox.score) {
            renderNextRound(&model, base);
            renderNextRound(&model, screen2);
            currScore = model.scorebox.score;
        }

        timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        
        if (timeElapsed > 0) {

            if (swapScreens){
                currScreen = base;
                clearGame(currScreen);
            } else {
                currScreen = screen2;
                clearGame(currScreen);
            }

            timeThen = timeNow;
            processSyncEvents(&model);

            renderAsteroids(model.asteroids, (UINT8*)currScreen);
            renderRocketship(&model.player, (UINT32*)currScreen);

            /*
            Setscreen(-1, currScreen, -1);
            */
            oldSSP = Super(0);
            setVideoBase((UINT16*)currScreen);
            Super(oldSSP);

            Vsync();
            swapScreens = !swapScreens;
            
        }

    }

    /*
    Setscreen(-1, base, -1);
    */
    oldSSP = Super(0);
    setVideoBase((UINT16*)base);
    Super(oldSSP);

    Vsync();
    stopSound();
    
}

void processAsyncEvents(Model *model) {

    unsigned long input;

    if(hasUserInput()) {

        rocketshipHitBoundary(&model->player);

        input = getUserInput();

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

    clearQuick(base);

    render(model, base);

}

long getTime() {

    long* timer = (long*) SYSTEM_CLOCK;
    
    long oldSSP = Super(0);

    long timeNow = *timer;

    Super(oldSSP);

    return timeNow;

}
