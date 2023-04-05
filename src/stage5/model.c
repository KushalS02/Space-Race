/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: model.c

Instructor: Paul Pospisil

*/
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
        
            rocketship->hitbox.topLeftY -= ROCKETSHIP_SPEED;
            rocketship->hitbox.bottomRightY -= ROCKETSHIP_SPEED;

        break;

    case down:

            rocketship->hitbox.topLeftY += ROCKETSHIP_SPEED;
            rocketship->hitbox.bottomRightY += ROCKETSHIP_SPEED;

        break;
        
    }

    }

void initializeRocketship(Rocketship* rocketship) {

    rocketship->hitbox.topLeftX = ROCKETSHIP_STARTING_X;
    rocketship->hitbox.topLeftY = ROCKETSHIP_STARTING_Y;
    rocketship->hitbox.bottomRightX = ROCKETSHIP_STARTING_X + SHIPV2_WIDTH;
    rocketship->hitbox.bottomRightY = ROCKETSHIP_STARTING_Y + SHIPV2_HEIGHT;
    rocketship->alive = true;

}

/*
Asteroid Functions
*/
void moveAsteroids(Asteroid *asteroids)
{

    UINT8 currAsteroid;
    asteroidDirecton direction;
    int deltaX;

    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++)
    {
        direction = asteroids[currAsteroid].direction;
        deltaX = asteroids[currAsteroid].deltaX;

        switch (direction)
        {
        case left:

            asteroids[currAsteroid].hitbox.topLeftX -= deltaX;
            asteroids[currAsteroid].hitbox.bottomRightX -= deltaX;

            break;

        case right:

            asteroids[currAsteroid].hitbox.topLeftX += deltaX;
            asteroids[currAsteroid].hitbox.bottomRightX += deltaX;

            break;
        }


    }
}

void initializeAsteroids(Asteroid * asteroids) {

    UINT8 currAsteroid; /*array index*/
    UINT16 currXPos;
    UINT16 currYPos;

    /* Every other asteroid moves left */
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid += 2) {

        asteroids[currAsteroid].direction = left;

    }

    /* Every other asteroid moves right */
    for (currAsteroid = 1; currAsteroid < ASTEROID_MAX; currAsteroid += 2) {

            asteroids[currAsteroid].direction = right;

    }

    /* Initializes starting positions */
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++) {

            currYPos = currAsteroid * ASTRV2_HEIGHT + CHKLINE_HEIGHT;
            currXPos = (rand() % HEIGHT_BYTES) * 16; /*40 possible starting postions (Byte 0 to 39)*/
            asteroids[currAsteroid].hitbox.topLeftY = currYPos;
            asteroids[currAsteroid].hitbox.bottomRightY = currYPos + ASTRV2_HEIGHT;
            asteroids[currAsteroid].hitbox.topLeftX = currXPos;
            asteroids[currAsteroid].hitbox.bottomRightX = currXPos + ASTRV2_WIDTH;
            asteroids[currAsteroid].hitBoundary = false;
            asteroids[currAsteroid].deltaX = ASTEROID_SPEED;

        }

}

/*
Score Functions
*/
void initializeScore(Scorebox * scorebox) {

    scorebox->score = 0;
    scorebox->x = SCOREBOX_X;
    scorebox->y = SCOREBOX_Y;

}

void updateScore(Scorebox * scorebox, int playerScore) {

    scorebox->score += playerScore;

    if (scorebox->score > MAX_SCORE) {

            scorebox->score == MAX_SCORE;

    }

}

void initializeHighscore(HighscoreBox * highscoreBox) {

    highscoreBox->highscore = 0;
    highscoreBox->x = HIGHSCOREBOX_X;
    highscoreBox->y = HIGHSCOREBOX_Y;

}

void updateHighscore(HighscoreBox * highscoreBox, int score) {

    if(score > highscoreBox->highscore) {

        highscoreBox->highscore = score;
        
    }

}

void initializeNextRound(Rocketship * rocketship, Asteroid * asteroids, Scorebox * scorebox, HighscoreBox* highscoreBox) {

    initializeRocketship(rocketship);
    initializeAsteroids(asteroids);
    updateHighscore(highscoreBox, scorebox->score);
    initializeScore(scorebox);

}

/*
Model Functions
*/
void initializeModel(Model * model)
{

    model->playing = true;
    model->gameOver = false;
    initializeRocketship(&model->player);
    initializeAsteroids(model->asteroids);
    initializeScore(&model->scorebox);
    initializeHighscore(&model->highscorebox);

}

void pauseGame(Model * model) {

    model->playing = false;

}

void resumeGame(Model * model) {

    model->playing = true;

}

void gameOver(Model * model) {

    model->gameOver = true;
    model->playing = false;

}

bool hitboxCollision(Hitbox hb1, Hitbox hb2) {

        return hb1.topLeftX < hb2.bottomRightX &&
               hb1.bottomRightX > hb2.topLeftX &&
               hb1.topLeftY < hb2.bottomRightY &&
               hb1.bottomRightY > hb2.topLeftY;

}
