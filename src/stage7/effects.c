#include "effects.h"

void collisionEffect() {


    
}

void rocketshipMovingEffect() {

    /*
    CAN CHANGE VALUES
    */
    int volume = 16;
    int noiseTone = 30;
    int sustain = 10;

    setTone(channelA, 248);

    enableChannel(channelA, true, false);

    setVolume(channelA, volume);

    setEnvelope(triangleInvPeriod, sustain);

}