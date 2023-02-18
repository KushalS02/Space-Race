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

}

void moveAsteroid(Model *model) {

    Asteroid *asteroid = &model->asteroid;
    Hitbox *hitbox = &asteroid->hitbox;

    switch (asteroid->direction) {

        case right:


        break; 

        case left:


        break;

        default:
        break:


    }

}

void initializeAsteroid(Asteroid *asteroid) {



}

void collides(Hitbox hitbox) {


}

void initAsteroid(Asteroid* asteroid, int x, int y, int row, int col) {

    asteroid->x = x;
    asteroid->y = y;
    asteroid->row = row;
    asteroid->col = col;

}

void initializeScoreBox(Model *model) {

    model->scorebox.score = 0;
    model->scorebox.x = SCOREBOX_X;
    model->scorebox.y = SCOREBOX_Y;

}

void initializeHighscoreBox(Model *model) {

    model->highscorebox.highscore = 0;
    model->highscorebox.x = HIGHSCOREBOX_X;
    model->highscorebox.y = HIGHSCOREBOX_Y;

}

void gameOver(Model *model) {

    model->playing = false;
    model->gameOver = true;

}