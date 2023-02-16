#include "model.h"

void moveRocketShip(Rocketship *rocketShip, rocketShipDirection direction) {

    switch (direction) {
        
        case up:

        if (positionInBound(rocketShip->Y - ROCKETSHIP_SPEED, ROCKETSHIP_STARTING_Y)) {
            rocketShip->y -= ROCKETSHIP_SPEED;
        }

            break;

        case down:

        if (positionInBound(rocketShip->Y + ROCKETSHIP_SPEED, ROCKETSHIP_STARTING_Y)) {
            rocketShip->y += ROCKETSHIP_SPEED;
        }

            break;

        default;
        break;
    }


}

void initializeRocketship(Rocketship *rocketship) {

rocketship->x = ROCKETSHIP_STARTING_X;
rocketship->y =  ROCKETSHIP_STARTING_Y;
rocketship->isHit = true;


}

void moveAsteroid(Asteroid *asteroid) {



}

void initializeAsteroid(Asteroid *asteroid) {



}

void collides(Hitbox hitbox) {


}

void initializeScore(Model *model) {



}

void gameOver(Model *model) {

    model->playing = false;
    model->gameOver = true;

}