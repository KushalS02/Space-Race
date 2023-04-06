/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: spceRace.c

Instructor: Paul Pospisil

*/
#include "spceRace.h"
#include <osbind.h>

int main() {

    gameLoop();

    return 0;

}

void gameLoop() {

    Model model;

    void* base = Physbase();

    gameSetup(&model, base);

    while(!model.gameOver) {

        processAsyncEvents(&model, base);

        processSyncEvents(&model, base);

        Vsync();

    }

}

void processAsyncEvents(Model *model, void *base) {

    unsigned long input;

    rocketshipHitBoundary(&(model->player), model->asteroids, &(model->scorebox), &(model->highscorebox));

    if(hasUserInput()) {

        input = getUserInput();

        rocketshipMove(&model->player, input);

    }

    renderRocketship(&model->player, base);

}

void processSyncEvents(Model *model, void *base) {

    unsigned long timeThen, timeNow, timeElapsed;

    timeNow = getTime();

    timeElapsed = timeNow - timeThen;

    if (timeElapsed > 0) {

        moveAsteroids(model->asteroids);

        renderAsteroids(model->asteroids, (UINT8*)base);

        timeThen = timeNow;

    }

}

void gameSetup(Model*model, void *base) {

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
