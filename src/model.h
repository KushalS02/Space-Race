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
    Hitbox hitbox;

} Asteroid;

typedef struct 
{

    unsigned int x, y, score;

} Score;

typedef struct 
{

    unsigned int x, y, highscore;

} Highscore;

/*
The other functions
*/
void moveRocketShip(Rocketship *rocketShip, rocketShipDirection direction);


#endif