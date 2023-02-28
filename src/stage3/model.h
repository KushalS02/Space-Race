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
    int topLeftX;
    int topLeftY;
    int bottomRightX;
    int bottomRightY;
    asteroidDirecton direction;
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
    Asteroid asteroids[ASTEROID_MAX];
    Scorebox scorebox;
    HighscoreBox highscorebox;
    bool gameOver;
    bool playing;

} Model;

/*
Rocketship Functions
*/
void moveRocketship(Rocketship* rocketship, rocketShipDirection direction);
void initializeRocketship(Rocketship* rocketship);

/*
Asteroid Functions
*/
void moveAsteroids(Asteroid* asteroids);
void initializeAsteroids(Asteroid* asteroids);

/*
Score Functions
*/
void initializeScore(Scorebox* scorebox);
void updateScore(Scorebox* scorebox, int playerScore);

void initializeHighscore(HighscoreBox* highscoreBox);
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