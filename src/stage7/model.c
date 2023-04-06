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

    switch (direction) {
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
void moveAsteroids(Asteroid *asteroids) {

    UINT8 currAsteroid;
    asteroidDirecton direction;
    int deltaX;
    int topLeftX;

    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++) {
        direction = asteroids[currAsteroid].direction;
        deltaX = asteroids[currAsteroid].deltaX;
        topLeftX = asteroids[currAsteroid].hitbox.topLeftX;

        switch (direction) {

        case left:

            /*prevents negative x values*/
            if (topLeftX - deltaX < 0) {

                asteroids[currAsteroid].hitbox.topLeftX = 0;
                
            }
            else {

                asteroids[currAsteroid].hitbox.topLeftX -= deltaX;

            }

            break;

        case right:

            /* add check for > 640*/
            if (topLeftX + deltaX > SCREEN_WIDTH - 1 - ASTRV2_WIDTH) {

                asteroids[currAsteroid].hitbox.topLeftX = SCREEN_WIDTH - ASTRV2_WIDTH;

            }
            else {

                asteroids[currAsteroid].hitbox.topLeftX += deltaX;

            }

            break;
        }

        asteroids[currAsteroid].hitbox.bottomRightX = asteroids[currAsteroid].hitbox.topLeftX + ASTRV2_WIDTH;

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
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++){

        currYPos = (currAsteroid * (ASTRV2_HEIGHT + ASTEROID_SPACING) ) + ASTEROID_MAX_Y;
        currXPos = (rand() % WIDTH_BYTES) * 8; /*80 possible starting postions (Byte 0 to 79)*/
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

void updateHighscore(HighscoreBox * highscoreBox, int score)
{

    if(score > highscoreBox->highscore) {

        highscoreBox->highscore = score;

    }

}

void initializeNextRound(Rocketship * rocketship, Asteroid * asteroids, Scorebox * scorebox, HighscoreBox* highscoreBox) {

    initializeRocketship(rocketship);
    initializeAsteroids(asteroids);
    updateScore(scorebox, SCORE_INCREMENT);
    updateHighscore(highscoreBox, scorebox->score);

}

/*
Model Functions
*/
void initializeModel(Model * model) {

    model->playing = true;
    model->gameOver = false;
    initializeRocketship(&model->player);
    initializeAsteroids(model->asteroids);
    initializeScore(&model->scorebox);
    initializeHighscore(&model->highscorebox);
    /*replace SEED with call to getTime function for random(ish) value*/
    srand(SEED);

}

void gameOver(Model * model) {

    model->gameOver = true;
    model->playing = false;

}


/*
https://silentmatt.com/rectangle-intersection/
*/
bool hitboxCollision(Hitbox* hb1, Hitbox* hb2) {

    return hb1->topLeftX < hb2->bottomRightX &&
            hb1->bottomRightX > hb2->topLeftX &&
            hb1->topLeftY < hb2->bottomRightY &&
            hb1->bottomRightY > hb2->topLeftY;
            
}
