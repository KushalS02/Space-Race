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

} Rocketship;

typedef struct 
{

    unsigned int x, y;
    int deltaX;
    int row;
    int col;
    Hitbox hitbox;
    asteroidDirecton direction;
    Asteroid asteroids[ASTEROID_ROWS][ASTEROID_COL];

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
void setScore(Scorebox* scorebox, UINT16 score);
UINT16 getScore(Scorebox* scorebox);
void updateScore(Scorebox* scorebox);

/*
Model Functions
*/
void initializeModel(Model* model);
void pauseGame(Model* model);
void resumeGame(Model* model);
void gameOver(Model* model);

#endif