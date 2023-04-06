/*
Authours: Alexander Pham and Kushal Saini
Course: COMP 2659 - 001 
File name: psg.c
Instructor: Paul Pospisil
*/
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

    const UINT8 channelToneRegisters[] = {
        CHANNEL_A_TONE,
        CHANNEL_B_TONE,
        CHANNEL_C_TONE
    };
    
    if (channel >= channelA && channel <= channelC) {

        writePSG(channelToneRegisters[channel], (UINT8)tuning);

    }

}

void setVolume(channelType channel, int volume) {

    const UINT8 channelVolRegisters[] = {
        CHANNEL_A_VOL,
        CHANNEL_B_VOL,
        CHANNEL_C_VOL
    };
    
    if (channel >= channelA && channel <= channelC) {

        writePSG(channelVolRegisters[channel], (UINT8)volume);

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

    channelType channel;

    const UINT8 stopValue = 0x00;
    
    writePSG(MIXER_REG, stopValue);
    writePSG(NOISE_FREQUENCY_REG, stopValue);
    writePSG(ENVELOPE_FINE_REG, stopValue);
    writePSG(ENVELOPE_ROUGH_REG, stopValue);
    writePSG(ENVELOPE_SHAPE_CONTROL_REG, stopValue);
    
    for (channel = channelA; channel <= channelC; channel++) {

        setVolume(channel, 0);

    }

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