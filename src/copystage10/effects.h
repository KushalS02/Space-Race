/*
Authours: Alexander Pham and Kushal Saini
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

#endif