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

    if(hasUserInput()) {

        rocketshipHitBoundary(&model->player);

        input = getUserInput();

        clearRocketship(&model->player, base);
        rocketshipMove(&model->player, input);
        renderRocketship(&model->player, base);

        if (rocketshipHitFinish(model)) {
            renderHighscoreBox(model, base);
            renderScoreBox(model, base);
            clearAsteroids(model->asteroids, base);
        }

    }

}

void processSyncEvents(Model *model, void *base) {

    unsigned long timeThen, timeNow, timeElapsed;

    timeNow = getTime();

    timeElapsed = timeNow - timeThen;

    if (timeElapsed > 0) {
        clearAsteroids(&model->asteroids, base);

        moveAsteroids(&model->asteroids);

        renderAsteroids(&model->asteroids, base);

        rocketshipAsteroidCollision(model);

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
