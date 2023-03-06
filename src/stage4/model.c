#include "model.h"
#include "TYPES.H"
#include <stdlib.h>

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

        break;
        
    }

}

void initializeRocketship(Rocketship* rocketship) {

    rocketship->x = ROCKETSHIP_STARTING_X;
    rocketship->y = ROCKETSHIP_STARTING_Y;
    rocketship->alive = true;

}

/*
Asteroid Functions
*/
void moveAsteroids(Asteroid* asteroids)
{

    UINT8 currAsteroid;
    asteroidDirecton direction;
    int deltaX;
    int currXPos;

    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid += 2)
    {
        direction = asteroids[currAsteroid].direction;
        deltaX = asteroids[currAsteroid].deltaX;
        currXPos = asteroids[currAsteroid].x;

        switch (direction)
        {
        case left:

            currXPos -= deltaX;

            /* If Asteroid is left of border, reset to right border*/
            if (currXPos < 0) {
                currXPos = SCREEN_WIDTH - abs(currXPos);
            }

            break;

        case right:

            currXPos += deltaX;

            /* If Asteroid is right of border, reset to left border*/
            if (currXPos > SCREEN_HEIGHT) {
                currXPos -= SCREEN_HEIGHT;
            }

            break;

        default:

            /* Error */    
            break;
        }
    }
}

void initializeAsteroids(Asteroid* asteroids) {


    UINT8 currAsteroid; /*array index*/
    UINT16 currXPos;
    UINT16 currYPos;

    /* Every other asteroid moves left */
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid += 2) {
        asteroids[currAsteroid].direction = left;
    }

    /* Every other asteroid moves right */
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid += 2) {
        asteroids[currAsteroid].direction = right;
    }

    /* Initializes starting positions */
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++) {
        currYPos = currAsteroid * ASTRV2_HEIGHT + CHKLINE_HEIGHT;
        currXPos = (rand() % HEIGHT_BYTES) * 16; /*40 possible starting postions (Byte 0 to 39)*/
        asteroids[currAsteroid].y = currYPos;
        asteroids[currAsteroid].x = currXPos;
        asteroids[currAsteroid].hitBoundary = false;
        asteroids[currAsteroid].deltaX = ASTEROID_SPEED;
    }

}

/*
Score Functions
*/
void initializeScore(Scorebox* scorebox) {

    scorebox->score = 0;
    scorebox->x = SCOREBOX_X;
    scorebox->y = SCOREBOX_Y;

}

void updateScore(Scorebox* scorebox, int playerScore) {
    
    scorebox->score += playerScore;

    if(scorebox->score > MAX_SCORE) {
        scorebox->score == MAX_SCORE;
    }
}

void initializeHighscore(HighscoreBox* highscoreBox) {

    highscoreBox->highscore = 0;
    highscoreBox->x = HIGHSCOREBOX_X;
    highscoreBox->y = HIGHSCOREBOX_Y;

}

void updateHighscore(HighscoreBox* highscoreBox, int playerHighScore) {


}

/*
Model Functions
*/
void initializeModel(Model* model) {

    model->playing = true;
    model->gameOver = false;
    initializeRocketship(&model->player);
    initializeAsteroids(model->asteroids);
    initializeScore(&model->scorebox);
    initializeHighscore(&model->highscorebox);

}

void pauseGame(Model* model) {

    model->playing = false;

}

void resumeGame(Model* model) {

    model->playing = true;

}

void gameOver(Model* model) {

    model->gameOver = true;
    model->playing = false;

}
