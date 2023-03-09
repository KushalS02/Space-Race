#include "spceRace.h"
#include <osbind.h>

const UINT8 secondBuffer[32256];

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

    bool swapScreens = true;

    Model model;

    UINT8 *base = Physbase();

    void *screen2;
    screen2 = getBase(secondBuffer);
    clearScreen(screen2);

    gameSetup(&model, base);

    while(!model.gameOver) {

        processAsyncEvents(&model, base);

        processSyncEvents(&model, base);

        if(!model.gameOver) {

            if(swapScreens) {

                render(&model, base);
                Setscreen(-1, base, -1);

            }
            else {

                render(&model, screen2);
                Setscreen(-1, screen2, -1);

            }

            Vsync();
            swapScreens !=swapScreens;

        } else {

            break;
        }

        render(&model, base);
        Setscreen(-1, base, -1);
        Vsync();

        

    }

    Setscreen(-1, base, -1);

}

void processAsyncEvents(Model *model, void *base) {

    unsigned long input;

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

        moveAsteroids(model);

        renderAsteroid(&model->asteroids[ASTEROID_MAX], base);

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
