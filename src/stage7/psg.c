#include "psg.h"

void writePSG(int reg, UINT8 val) {

    long oldSSP;

    if (regIsValid(reg)) {

        oldSSP = Super(0);

        *psgRegSelect = reg;

        *psgRegWrite = val;

        Super(oldSSP);

    }

}

UINT8 readPSG(int reg) {

    long oldSSP;

    int val = -1;

    oldSSP = Super(0);

    if (regIsValid(reg)) {

        *psgRegSelect = reg;

        val = *psgRegSelect;

    }

    Super(oldSSP);

    return val;

}

void setTone(channelType channel, int tuning) {

    switch (channel) {
        
        case channelA:

            writePSG(CHANNEL_A_TONE, tuning);

            break;

        case channelB:

            writePSG(CHANNEL_B_TONE, tuning);

            break;

        case channelC:

            writePSG(CHANNEL_C_TONE, tuning);

            break;

    }

}

void setVolume(channelType channel, int volume) {

    switch (channel) {

        case channelA:

            writePSG(CHANNEL_A_VOL, volume);

            break;
        
        case channelB:

            writePSG(CHANNEL_B_VOL, volume);

            break;

        case channelC:

            writePSG(CHANNEL_C_VOL, volume);

            break;

    }

}

void enableChannel(channelType channel, bool toneOn, bool noiseOn) {

    switch (channel) {

        case channelA:

            

            break;

        case channelB:



            break;

        case channelC:



            break;

    }

}

void stopSound() {

    setVolume(channelA, 0);

    setVolume(channelB, 0);

    setVolume(channelC, 0);

}