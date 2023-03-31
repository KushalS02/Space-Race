/*
Authours: Alexander Pham and Kushal Saini
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