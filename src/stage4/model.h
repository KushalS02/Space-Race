#ifndef MODEL_H
#define MODEL_H

#include "TYPES.H"
#include "const.h"

/*
All the typedef for structures 
*/
typedef struct 
{
    UINT16 topLeftX;
    UINT16 topLeftY;
    UINT16 topRightX;
    UINT16 topRightY;
    UINT16 bottomLeftX;
    UINT16 bottomLeftY;
    UINT16 bottomRightX;
    UINT16 bottomRightY;
    UINT16 width;
    UINT16 height;

} Hitbox;

typedef struct 
{

    unsigned int x, y;
    int deltaY;
    rocketShipDirection direction;
    Hitbox hitbox;
    bool alive;
    bool hitBoundary;

} Rocketship;

typedef struct 
{

    unsigned int x, y;
    int deltaX;
    int row;
    int col;
    int topLeftX;
    int topLeftY;
    int bottomRightX;
    int bottomRightY;
    asteroidDirecton direction;
    Asteroid asteroids[ASTEROID_MAX];
    bool hitBoundary;

} Asteroid;

typedef struct 
{

    unsigned int x, y, score;

} Scorebox;

typedef struct 
{

    unsigned int x, y, highscore;

} HighscoreBox;

typedef struct {

    Rocketship player;
    Asteroid asteroid;
    Scorebox scorebox;
    HighscoreBox highscorebox;
    bool gameOver;
    bool playing;

} Model;

/*
Rocketship Functions
*/
void moveRocketship(Rocketship* rocketship, rocketShipDirection direction);
void initalizeRocketship(Rocketship* rocketship);

/*
Asteroid Functions
*/
void moveAsteroid(Asteroid* asteroid, asteroidDirecton direction);
void initalizeAsteroid(Asteroid* asteroid);

/*
Score Functions
*/
void initalizeScore(Scorebox* scorebox);
void updateScore(Scorebox* scorebox, int playerScore);

void initalizeHighscore(HighscoreBox* highscoreBox);
void updateHighscore(HighscoreBox* highscoreBox, int playerHighScore);

/*
Model Functions
*/
void initializeModel(Model* model);
void pauseGame(Model* model);
void resumeGame(Model* model);
void gameOver(Model* model);

/*
Helper functions
*/


#endif