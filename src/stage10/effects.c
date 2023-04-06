/*
Authours: Alexander Pham and Kushal Saini
*/
#include "effects.h"

void collisionEffect() {

    int volume = 14;
    int noiseTone = 30;
    int sustain = 200;

    setNoise(noiseTone);
    
    enableChannel(B, false, true);

    setVolume(B, volume);

    setEnvelope(triangle, sustain);

    MUSIC_TIMER = 0;
    while(MUSIC_TIMER < 70)
    ;
    
}

void rocketshipMoveEffect() {
    int volume = 14;
    int noiseTone = 30;
    int sustain = 1;

    setNoise(noiseTone);
    
    enableChannel(B, false, true);

    setVolume(B, volume);

    setEnvelope(saw, sustain);

}

void clearEffects() {
    setVolume(B, 0);
    enableChannel(B, false, false);
    enableChannel(A, true, false);
}