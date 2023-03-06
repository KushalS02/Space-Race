#include "events.h"

void rocketshipMove(Rocketship* rocketship, unsigned long key) {

    if (key == UP_KEY){

        moveRocketship(rocketship, up);

    } else if (key == DOWN_KEY) {

        moveRocketship(rocketship, down);

    }

}

void rocketshipHitBoundary(Rocketship* rocketship) {



}
 
void asteroidHitBoundary(Asteroid* asteroid) {



}

void rocketshipAsteroidCollision(Model *model) {

    

}

void onGameStart(Model* model){ 

    initializeModel(model);

}

void onGamePause(Model* model) {

    pauseGame(model);

}

void onGameOver(Model* model) {

    gameOver(model);

}

bool hasUserInput() {

    return Cconis();

}

unsigned long getUserInput() {

    return Cnecin() >> 16;

}