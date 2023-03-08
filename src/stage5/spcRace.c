#include "spcRace.h"

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

void processAsyncEvents(Model* model, void* base) {

    unsigned long userInput;

    if (hasUserInput()) {
        
        userInput = getUserInput();

        rocketshipMove(&model->player, userInput);

    }

    renderRocketship(&model->player, base);

}

void processSyncEvents(Model* model, void* base) {

    UINT32 timeThen, timeNow, timeElapsed;

    int prevScore = model->scorebox.score;

    timeNow = getTime();

    timeElapsed = timeNow - timeThen;

}

void gameSetup(Model* model, void* base) {

    onGameStart(model);

    render(model, base);

}

long getTime() {

    long* timer = (long*) SYSTEM_CLOCK;

    long oldSSP = Super(0);

    long timeNow = *timer;

    Super(oldSSP);

    return timeNow;

}