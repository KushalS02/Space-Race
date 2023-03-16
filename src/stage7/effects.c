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

    setTone(channelB, 248);

    enableChannel(channelB, true, false);

    setVolume(channelB, volume);

    setEnvelope(triangleInvPeriod, sustain);

}