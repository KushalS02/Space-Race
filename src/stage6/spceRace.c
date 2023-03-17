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

void gameLoop() {

    Model model;

    bool swapScreens = true; /* stage 6 */

    UINT8 *base = Physbase();

    void *screen2; /* stage 6 */

    gameSetup(&model, base);

    screen2 = getBase(secondBuff); /* stage 6 */

    while(!model.gameOver) {

        if (!model.gameOver) {

            if (swapScreens) {

                /*clearG(base);*/

                processAsyncEvents(&model, base);

                processSyncEvents(&model, base);
                
                Setscreen(-1, base, -1);

            } else {

                /*clearG(screen2);*/

                processAsyncEvents(&model, screen2);

                processSyncEvents(&model, screen2);

                Setscreen(-1, screen2, -1);

            }

            Vsync();

            swapScreens = swapScreens;

        } 

    }

    processAsyncEvents(&model, base);

    processSyncEvents(&model, base);

    Setscreen(-1, base, -1);
        
    Vsync();

}

void processAsyncEvents(Model *model, void *base) {

    unsigned long input;

    if(hasUserInput()) {

        rocketshipHitBoundary(&model->player);

        input = getUserInput();

        clearRocketship(&model->player, base);
        rocketshipMove(&model->player, input);
        renderRocketship(&model->player, base);

        if (rocketshipHitFinish(model)) {

            clearAsteroids(model->asteroids, base);
            clearRocketship(&model->player, base);
            initializeNextRound(&(model->player), model->asteroids, &(model->scorebox), &(model->highscorebox));
            renderRocketship(&model->player, base);
            renderNextRound(model, base);
        }

        if (input == ESC_KEY) {

            onGameOver(model);

        }

    }

}

void processSyncEvents(Model *model, void *base) {

    unsigned long timeThen, timeNow, timeElapsed;

    timeNow = getTime();

    timeElapsed = timeNow - timeThen;

    if (timeElapsed > 0) {

        clearAsteroids(model->asteroids, base);

        asteroidsHitBoundary(model->asteroids);
        
        moveAsteroids(model->asteroids);

        renderAsteroids(model->asteroids, base);

        rocketshipAsteroidCollision(model);

        timeThen = timeNow;

    }

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
