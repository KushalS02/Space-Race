/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: TYPES.H

Instructor: Paul Pospisil

*/
#ifndef TYPES_H
#define TYPES_H

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

#define positionInBound(x, y) (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)

typedef int bool;
#define false 0
#define true 1

/* 

The directions that the rocketship is allowed to move, up or down

*/
typedef enum {

    up, down

} rocketShipDirection;

/*

The directions that asteroids are allowed to move, left and right

*/
typedef enum {

    left, right

} asteroidDirecton;

/*

The three channels for PSG

*/
typedef enum {

    A, B, C

} Channel;

/*

The envelope shapes

*/
typedef enum {

    saw, triangle

} envelopeShape;

#endif
