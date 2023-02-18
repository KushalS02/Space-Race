#include "model.h"

/*
Rocketship Functions
*/
void moveRocketship(Rocketship* rocketship, rocketShipDirection direction) {

    switch (direction)
    {
    case up:
        
        if (positionInBound(rocketship->y - ROCKETSHIP_SPEED, ROCKETSHIP_STARTING_Y)) {

            rocketship->y -= ROCKETSHIP_SPEED;

        }

        break;

    case down:

    if (positionInBound(rocketship->y + ROCKETSHIP_SPEED, ROCKETSHIP_STARTING_Y)) {

            rocketship->y += ROCKETSHIP_SPEED;

        }

    default:
        break;
    }

}

void initalizeRocketship(Rocketship* rocketship) {



}

/*
Asteroid Functions
*/
void moveAsteroid(Asteroid* asteroid, asteroidDirecton direction) {



}
void initalizeAsteroid(Asteroid* asteroid) {



}

/*
Score Functions
*/
void setScore(Scorebox* scorebox, UINT16 score) {



}

UINT16 getScore(Scorebox* scorebox) {



}

void updateScore(Scorebox* scorebox) {



}

/*
Model Functions
*/
void initializeModel(Model* model) {



}

void pauseGame(Model* model) {



}

void resumeGame(Model* model) {



}

void gameOver(Model* model) {



}
