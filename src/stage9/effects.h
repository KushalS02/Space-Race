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

/*
    Function: collisionEffect

    Purpose: when an asteroid and the player's rocketship collide, 
             an "crash" effect will be played 
        
    Details: sets the noise tone along with the channel being used, 
             volume and the envelope
*/
void collisionEffect();

#endif