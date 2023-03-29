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

int readPSG(int reg) {

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

    int mixerVal = readPSG(MIXER_REG);
    int toneMask, noiseMask;

    switch (channel) {

        case channelA:

            toneMask = MIXER_TONE_CHANNEL_A;
            noiseMask = MIXER_NOISE_CHANNEL_A;

            break;

        case channelB:

            toneMask = MIXER_TONE_CHANNEL_B;
            noiseMask = MIXER_NOISE_CHANNEL_B;

            break;

        case channelC:

            toneMask = MIXER_TONE_CHANNEL_C;
            noiseMask = MIXER_NOISE_CHANNEL_C;

            break;

        default:
            
            break;

    }

    
    if (!toneOn && !noiseOn) {
        
        /*
        Disable both tone and noise
        */
        mixerVal &= ~(toneMask | noiseMask);

    } else if (toneOn && !noiseOn) {
        
        /*
        enable tone only
        */
        mixerVal |= toneMask;
        mixerVal &= ~noiseMask;

    } else if (!toneOn && noiseOn) {
        
        /*
        enable noise only
        */
        mixerVal |= noiseMask;
        mixerVal &= ~toneMask;

    } else {
        
        /*
        enable both tone and noise
        */
        mixerVal |= toneMask | noiseMask;

    }

    writePSG(MIXER_REG, mixerVal);

}  

void stopSound() {

    writePSG(MIXER_REG, 0x00);

    writePSG(NOISE_FREQUENCY_REG, 0x00);

    writePSG(ENVELOPE_FINE_REG, 0x00);

    writePSG(ENVELOPE_ROUGH_REG, 0x00);

    writePSG(ENVELOPE_SHAPE_CONTROL_REG, 0x00);

    setVolume(channelA, 0);

    setVolume(channelB, 0);

    setVolume(channelC, 0);

}

void setEnvelope(envelopeShapeType shape, UINT16 sustain) {

    int shapeVal;

    writePSG(ENVELOPE_FINE_REG, sustain);
    
    writePSG(ENVELOPE_ROUGH_REG, sustain);

    switch (shape) {

        case saw:

            shapeVal = ENVELOPE_SAW_SHAPE;

            break;

        case sawInv:

            shapeVal = ENVELOPE_SAW_SHAPE_INV;

            break;

        case sawPeriod:

            shapeVal = ENVELOPE_SAW_PERIOD_SHAPE;

            break;

        case triangle:

            shapeVal = ENVELOPE_TRIANGLE_SHAPE;

            break;

        case triangleInv:

            shapeVal = ENVELOPE_TRIANGLE_INV_SHAPE;
            
            break;

        case trianglePeriod:

            shapeVal = ENVELOPE_TRIANGLE_PERIOD_SHAPE;

            break;

        case triangleInvPeriod:

            shapeVal = ENVELOPE_TRIANGLE_INV_PERIOD_SHAPE;

            break;

    }

}

void setNoise(int tuning) {

    writePSG(NOISE_FREQUENCY_REG, tuning);
    
}