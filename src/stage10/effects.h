/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: effects.h

Instructor: Paul Pospisil

*/

#ifndef EFFECTS_H
#define EFFECTS_H

#include "psg.h"
#include "TYPES.H"
#include "spcerace.h"

/*
    Function: collisionEffect

    Purpose: when an asteroid and the player's rocketship collide, 
             an "crash" effect will be played 
        
    Details: sets the noise tone along with the channel being used, 
             volume and the envelope

*/
void collisionEffect();

/*

    Function: rocketshipMoveEffect

    Prupose: when the rocketship is moved (player pressing up
             or down key), it will play a sound effect

*/
void rocketshipMoveEffect();

/*

    Function: clearEffects

    Purpose: to clear the sound effects that were played

*/
void clearEffects();

#endif