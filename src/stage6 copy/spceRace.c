/*
Authours: Alexander Pham and Kushal Saini
*/
#include "spceRace.h"
#include <osbind.h>

const UINT8 secondBuff[SCREEN_BUFFER_SIZE];

int main() {

    gameLoop();

    return 0;

}

UINT8 *getBase(UINT8 *secondBuffer) {

    UINT8 *base;

    UINT16 difference;

    base = secondBuffer;

    difference = (int) base;

    difference %= 0x100;

    difference = 0x100 - difference;

    return base + difference;

}

void gameLoop()
{
    unsigned long timeThen, timeNow, timeElapsed;
    Model model;
    bool swapScreens = false;
    UINT8 *base = Physbase();
    UINT8 *screen2 = getBase(secondBuff);
    UINT8 *currScreen = base;

    gameSetup(&model, base);
    render(&model, screen2);

    while (!model.gameOver)
    {
        processAsyncEvents(&model);

        timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        if (timeElapsed > 0)
        {
            timeThen = timeNow;

            /*clearRocketship(&model.player, currScreen);
            clearAsteroids(model.asteroids, currScreen);*/

            processSyncEvents(&model);

            renderAsteroids(model.asteroids, currScreen);
            renderRocketship(&model.player, currScreen);

            Setscreen(-1, currScreen, -1);

            if (swapScreens)
            {
                currScreen = base;
                clearQuick(currScreen);
            }
            else
            {
                currScreen = screen2;
                clearQuick(currScreen);
            }

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
