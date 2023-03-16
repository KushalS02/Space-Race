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

void rocketshipMovingEffect() {

    /*
    CAN CHANGE VALUES
    */
    int volume = 16;
    int noiseTone = 30;
    int sustain = 10;

    setTone(channelB, 248);

    enableChannel(channelB, true, false);

    setVolume(channelB, volume);

    setEnvelope(triangleInvPeriod, sustain);

}