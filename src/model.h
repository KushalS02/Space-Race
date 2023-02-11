#ifndef MODEL_H
#define MODEL_H

#include "types.h"

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

#endif