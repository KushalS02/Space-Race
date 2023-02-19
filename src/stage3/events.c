#include "events.h"

void rocketshipMove(Rocketship* rocketship, unsigned long key) {

    if (key == UP_KEY){

        moveRocketShip(rocketship, up);

    } else if (key == DOWN_KEY) {

        moveRocketShip(rocketship, down)

    }

}

void rocketshipHitBoundary(Rocketship* rocketship) {



}
 
void asteroidHitBoundary(Asteroid* asteroid) {



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