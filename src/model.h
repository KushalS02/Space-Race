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
    bool isHit;
    Hitbox hitbox;

} Rocketship;

typedef struct 
{
    int row;
    unsigned int x, y;
    int deltaX;
    Hitbox hitbox;

} Asteroid;

typedef struct 
{

    int x, y;
    unsigned int score;

} Score;

typedef struct 
{

    int x, y;
    unsigned int highscore;

} Highscore;

typedef struct {

    Rocketship player;
    Asteroid asteroid;
    Score score;
    Highscore highscore;
    bool isGameOver;
    bool playing;

} Model;

/*
The other functions
*/
void moveRocketShip(Rocketship *rocketShip, rocketShipDirection direction);

void initializeRocketship(Rocketship *rocketship);

void moveAsteroid(Asteroid *asteroid);

void initializeAsteroid(Asteroid *asteroid);

void collides(Hitbox hitbox);

/*
Score
*/
void initializeScore(Model *model);

/*
Game over
*/
void gameOver(Model *model);

#endif