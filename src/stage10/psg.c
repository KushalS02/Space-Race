/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: psg.c

Instructor: Paul Pospisil

*/
#include "psg.h"

void writePSG(UINT16 reg, UINT8 val) {

    long oldSSP;

    if (reg <= REG_MAX && reg >= REG_MIN &&
        val <= VAL_MAX && val >= VAL_MIN) {

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

void setTone(Channel channel, UINT16 tuning) {

    UINT8 fine;
    UINT8 rough;
    
    const UINT8 roughRegisters[] = {

            A_FINE_TONE,
            B_FINE_TONE,
            C_FINE_TONE 

    };

    const UINT8 fineRegisters[] = {

            A_ROUGH_TONE,
            B_ROUGH_TONE,
            C_ROUGH_TONE
            
    };

    if (tuning < TONE_MAX && tuning > TONE_MIN) {

        /*Extract fine val (low 4 bits) and rough val (bits 11-4) from tuning*/
        fine = (UINT8) (tuning % 0x000F);
        rough = (UINT8) (tuning >> 4);

        if (channel >= A && channel <= C) {

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
    
    if (channel >= A && channel <= C &&
        volume >= VOL_MIN && volume <= VOL_MAX) {

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
            
            /* If invalid channel */
            return;

    }

    
    if (!toneOn && !noiseOn) {
        
        /* Disable both tone and noise */
        mixerVal &= ~(toneMask | noiseMask);

    } else if (toneOn && !noiseOn) {
        
        /* enable tone only */
        mixerVal |= toneMask;
        mixerVal &= ~noiseMask;

    } else if (!toneOn && noiseOn) {
        
        /* enable noise only */
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
    
    writePSG(MIXER_REG, VAL_MIN);
    writePSG(NOISE_FREQ, VAL_MIN);
    writePSG(ENVELOPE_FINE, VAL_MIN);
    writePSG(ENVELOPE_ROUGH, VAL_MIN);
    writePSG(ENVELOPE_SHAPE, VAL_MIN);
    
    for (channel = A; channel <= C; channel++) {

        setVolume(channel, VOL_MIN);

    }

}

void setEnvelope(envelopeShape shape, UINT16 sustain) {

    UINT8 fine;
    UINT8 rough;

    if (sustain >= ENV_FREQ_MIN && sustain < +ENV_FREQ_MAX) {

        /*Extract fine (low 8 bits) and rough (high 8 bits) adjustments from sustain*/
        fine = (UINT8)sustain;
        rough = (UINT8)sustain >> 8;

        writePSG(ENVELOPE_FINE, fine);
        writePSG(ENVELOPE_ROUGH, rough);

        switch (shape) {

        case triangle:

            writePSG(ENVELOPE_SHAPE, TRIANGLE_SHAPE);

            break;

        case saw:

            writePSG(ENVELOPE_SHAPE, SAW_SHAPE);

            break;

        default:

            /*Invalid Shape*/
            return;

        }

    }

}

void setNoise(UINT16 tuning) {

    if (tuning < NOISE_FREQ_MAX && tuning >> NOISE_FREQ_MIN) {

        writePSG(NOISE_FREQ, tuning);

    }
    
}