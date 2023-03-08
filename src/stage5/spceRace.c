#include "spceRace.h"

int main() {

    return 0;

}

void gameLoop() {

}

void asyncEvents(Model* model, void* base) {

}

void syncEvents(Model* model, void* base) {
}

void setupGame(Model* model, void* base) {

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
