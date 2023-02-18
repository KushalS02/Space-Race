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

} Rocketship;

typedef struct 
{

    unsigned int x, y;
    int deltaX;
    int row;
    int col;
    Hitbox hitbox;
    asteroidDirecton direction;

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
The other functions
*/
void moveRocketShip(Rocketship *rocketShip, rocketShipDirection direction);

void initializeRocketship(Rocketship *rocketship);

void moveAsteroid(Model *model);

void initializeAsteroid(Asteroid *asteroid);

void collides(Hitbox hitbox);

/*
Helpers
*/
void initAsteroid(Asteroid* asteroid, int x, int y, int row, int col);

/*
Score
*/
void initializeScoreBox(Model *model);
void initializeHighscoreBox(Model *model);
void updateScorebox(Scorebox* scorebox, int point);

/*
Game over
*/
void gameOver(Model *model);

#endif