/*
Authours: Alexander Pham and Kushal Saini
*/
#include "psg.h"

void writePSG(UINT16 reg, UINT8 val) {

    long oldSSP;

    if (reg <= REG_MAX && reg >= REG_MIN) {

        oldSSP = Super(0);

        *psgRegSelect = reg;

        *psgRegWrite = val;

        Super(oldSSP);

    }

}

UINT8 readPSG(UINT16 reg) {

    long oldSSP;

    UINT8 val;

    oldSSP = Super(0);

    if (reg <= REG_MAX && reg >= REG_MIN) {

        *psgRegSelect = reg;

        val = *psgRegSelect;

    }

    Super(oldSSP);

    return val;

}

void setTone(Channel channel, UINT16 tuning)
{
    UINT8 fine;
    UINT8 rough;
    const UINT8 roughRegisters[] = {
            A_FINE_TONE,
            B_FINE_TONE,
            C_FINE_TONE};

    const UINT8 fineRegisters[] = {
            A_ROUGH_TONE,
            B_ROUGH_TONE,
            C_ROUGH_TONE};

    if (tuning < TONE_MAX && tuning > TONE_MIN)
    {

        /*Extract 4 bit fine val and 8 bit rough val from tuning*/
        fine = (UINT8) (tuning % 0x000F);
        rough = (UINT8) (tuning >> 4);

        if (channel >= A && channel <= C)
        {

            writePSG(roughRegisters[channel], rough);
            writePSG(fineRegisters[channel], fine);
        }
    }
}

void setVolume(Channel channel, UINT16 volume) {

    const UINT8 volRegisters[] = {
        A_VOL,
        B_VOL,
        C_VOL
    };
    
    if (channel >= A && channel <= C) {

        writePSG(volRegisters[channel], (UINT8)volume);

    }
}

void enableChannel(Channel channel, bool toneOn, bool noiseOn) {

    UINT16 mixerVal = readPSG(MIXER_REG);
    UINT16 toneMask, noiseMask;

    switch (channel) {

        case A:

            toneMask = MIXER_TONE_A;
            noiseMask = MIXER_NOISE_A;

            break;

        case B:

            toneMask = MIXER_TONE_B;
            noiseMask = MIXER_NOISE_B;

            break;

        case C:

            toneMask = MIXER_TONE_C;
            noiseMask = MIXER_NOISE_C;

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

    Channel channel;

    const UINT8 stopValue = 0x00;
    
    writePSG(MIXER_REG, stopValue);
    writePSG(NOISE_FREQUENCY_REG, stopValue);
    writePSG(ENVELOPE_FINE_REG, stopValue);
    writePSG(ENVELOPE_ROUGH_REG, stopValue);
    writePSG(ENVELOPE_SHAPE_CONTROL_REG, stopValue);
    
    for (channel = A; channel <= C; channel++) {

        setVolume(channel, 0);

    }

}

void setEnvelope(envelopeShapeType shape, UINT16 sustain) {

    UINT16 shapeVal;

    writePSG(ENVELOPE_FINE_REG, sustain);
    
    writePSG(ENVELOPE_ROUGH_REG, sustain);

    switch (shape) {

        case triangle:

            writePSG(ENVELOPE_SHAPE_CONTROL_REG, ENVELOPE_TRIANGLE_SHAPE);

            break;

        case saw:
        
            writePSG(ENVELOPE_SHAPE_CONTROL_REG, ENVELOPE_SAW_SHAPE);

            break;
    }

}

void setNoise(UINT16 tuning) {

    if (tuning < NOISE_FREQ_MAX && tuning >> NOISE_FREQ_MIN) {
        writePSG(NOISE_FREQUENCY_REG, tuning);
    }
}