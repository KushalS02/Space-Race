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

    int existingMixerVal = readPSG(MIXER_REG);
    int channelVal;
    bool toneOnly = toneOn && !noiseOn;
    bool noiseOnly = !toneOn && noiseOn;
    bool toneAndNoise = toneOn && noiseOn;

    switch (channel) {

        case channelA:

            if (toneOnly) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & MIXER_TONE_CHANNEL_A : MIXER_TONE_CHANNEL_A;

            } else if (noiseOnly) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & MIXER_NOISE_CHANNEL_A : MIXER_NOISE_CHANNEL_A;

            } else if (toneAndNoise) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & (MIXER_TONE_CHANNEL_A & MIXER_NOISE_CHANNEL_A) : (MIXER_TONE_CHANNEL_A & MIXER_NOISE_CHANNEL_A);

            }

            break;

        case channelB:

            if (toneOnly) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & MIXER_TONE_CHANNEL_B : MIXER_TONE_CHANNEL_B;

            } else if (noiseOnly) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & MIXER_NOISE_CHANNEL_B : MIXER_NOISE_CHANNEL_B;

            } else if (toneAndNoise) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & (MIXER_TONE_CHANNEL_B & MIXER_NOISE_CHANNEL_B) : (MIXER_TONE_CHANNEL_B & MIXER_NOISE_CHANNEL_B);

            }

            break;

        case channelC:

            if (toneOnly) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & MIXER_TONE_CHANNEL_C : MIXER_TONE_CHANNEL_C;

            } else if (noiseOnly) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & MIXER_NOISE_CHANNEL_C : MIXER_NOISE_CHANNEL_C;

            } else if (toneAndNoise) {

                channelVal = existingMixerVal != -1 ? 
                    existingMixerVal & (MIXER_TONE_CHANNEL_C & MIXER_NOISE_CHANNEL_C) : (MIXER_TONE_CHANNEL_C & MIXER_NOISE_CHANNEL_C);

            }

            break;

    }

}

void stopSound() {

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