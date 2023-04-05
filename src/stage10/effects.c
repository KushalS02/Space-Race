/*
Authours: Alexander Pham and Kushal Saini
*/
#include "effects.h"

void collisionEffect() {

    int volume = 14;
    int noiseTone = 30;
    int sustain = 15;

    setNoise(noiseTone);
    
    enableChannel(channelB, false, true);

    setVolume(channelB, volume);

    setEnvelope(triangleInvPeriod, sustain);

    MUSIC_TIMER = 0;
    while(MUSIC_TIMER < 70)
    ;
    
}

void rocketshipMoveEffect() {
    int volume = 14;
    int noiseTone = 999;
    int sustain = 5;

    setNoise(noiseTone);
    
    enableChannel(channelB, false, true);

    setVolume(channelB, volume);

    setEnvelope(triangleInvPeriod, sustain);

}

void clearEffects() {
    setVolume(channelB, 0);
    enableChannel(channelB, false, false);
    enableChannel(channelA, true, false);
}