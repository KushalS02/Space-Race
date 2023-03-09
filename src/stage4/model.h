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
    UINT16 bottomRightX;
    UINT16 bottomRightY;
} Hitbox;

typedef struct 
{
    rocketShipDirection direction;
    Hitbox hitbox;
    bool alive;
    bool hitBoundary;

} Rocketship;

typedef struct 
{
    int deltaX;
    Hitbox hitbox;
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
void updateHighscore(HighscoreBox* highscoreBoxs, int score);

/*
Model Functions
*/
void initializeModel(Model* model);
void initializeNextRound(Rocketship* rocketship, Asteroid* asteroids, Scorebox* scorebox, HighscoreBox* highscoreBox);
void pauseGame(Model* model);
void resumeGame(Model* model);
void gameOver(Model* model);

/*
Helper functions
*/

bool hitboxCollision(Hitbox hb1, Hitbox hb2);

#endif