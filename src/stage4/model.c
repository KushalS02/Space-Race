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

    rocketship->x = ROCKETSHIP_STARTING_X;
    rocketship->y = ROCKETSHIP_STARTING_Y;
    rocketship->alive = true;

}

/*
Asteroid Functions
*/
void moveAsteroid(Asteroid* asteroid, asteroidDirecton direction) {

    switch (direction)
    {
    case left:



        break;
    
    case right:



        break;

    default:
        break;
    }

}
void initalizeAsteroid(Asteroid* asteroid) {

    int i = 0;

    UINT16 asteroidStartY = ASTEROID_STARTING_Y;

    for (i = 0; i < ASTEROID_MAX; i + 2) {
       
       for(i = 1; i < ASTEROID_MAX; i + 2) {

            asteroid->direction = left;
            asteroid->y = i;      
            asteroidStartY += ASTEROID_BOX_SIZE;
            asteroid->asteroids[i] = asteroid;

        }

        asteroid->asteroids[i] = asteroid;
        asteroid->direction = right;
        asteroid->y = i;
        asteroidStartY += ASTEROID_BOX_SIZE;

    } 

}

/*
Score Functions
*/
void initalizeScore(Scorebox* scorebox) {

    scorebox->score = 0;
    scorebox->x = SCOREBOX_X;
    scorebox->y = SCOREBOX_Y;

}

void updateScore(Scorebox* scorebox, int playerScore) {

    if (scorebox->score < MAX_SCORE) {

        scorebox->score += playerScore;    

    } else {

        scorebox->score = MAX_SCORE;

    }

}

void initalizeHighscore(HighscoreBox* highscoreBox) {

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
    initalizeRocketship(&model->player);
    initalizeAsteroid(&model->asteroid);
    initalizeScore(model);
    initalizeHighscore(model);

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
