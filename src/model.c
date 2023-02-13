#include "model.h"

void moveRocketShip(Rocketship *rocketShip, rocketShipDirection direction) {

    switch (direction) {
        
        case up;


            break;

        case down;

            break;

        default;
        break;
    }


}

void initializeRocketship(Rocketship *rocketship) {



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