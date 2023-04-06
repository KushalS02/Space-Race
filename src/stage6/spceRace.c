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

    gameLoop();

    return 0;

}

UINT8 *getBase(UINT8 *secondBuffer) {

    unsigned long add = (unsigned long) secondBuffer;
    unsigned long base = (add + 0xFF) & ~(unsigned long) 0xFF;

    return (UINT8*) base;

}

void gameLoop()
{
    unsigned long timeThen, timeNow, timeElapsed;
    Model model;
    bool swapScreens = false;
    UINT8 *base = Physbase();
    UINT8 *screen2 = getBase(secondBuff);
    UINT8 *currScreen = base;
    UINT8 currScore = 0;

    gameSetup(&model, base);
    render(&model, screen2);

    while (!model.gameOver)
    {

        processAsyncEvents(&model);

        if(currScore < model.scorebox.score) {
            renderNextRound(&model, base);
            renderNextRound(&model, screen2);
            currScore = model.scorebox.score;
        }

        timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        if (timeElapsed > 0)
        {
            if (swapScreens)
            {
                currScreen = base;
                clearG(currScreen);
            }
            else
            {
                currScreen = screen2;
                clearG(currScreen);
            }

            timeThen = timeNow;
            processSyncEvents(&model);

            renderAsteroids(model.asteroids, currScreen);
            renderRocketship(&model.player, (UINT32*)currScreen);

            Setscreen(-1, currScreen, -1);

            Vsync();
            swapScreens = !swapScreens;
        }
    }

    Setscreen(-1, base, -1);
    Vsync();
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

    clearScreen(base);

    render(model, base);

}

long getTime() {

    long* timer = (long*) SYSTEM_CLOCK;
    
    long oldSSP = Super(0);

    long timeNow = *timer;

    Super(oldSSP);

    return timeNow;

}
