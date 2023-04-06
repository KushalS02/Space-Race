/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: effects.c

Instructor: Paul Pospisil

*/
#include "effects.h"

void collisionEffect() {

    int volume = 15;
    int noiseTone = 30;
    int sustain = 15;

    setNoise(noiseTone);
    
    enableChannel(channelB, false, true);

    setVolume(channelB, volume);

    setEnvelope(triangleInvPeriod, sustain);
    
}