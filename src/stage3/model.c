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



}
void initalizeAsteroid(Asteroid* asteroid) {

    int row, col;

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
