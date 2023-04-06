/*
Authours: Alexander Pham and Kushal Saini
Course: COMP 2659 - 001 
File name: psg.h
Instructor: Paul Pospisil
*/
#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include "TYPES.H"

/*
Check if the register of PSG is valid and in range
*/
#define regIsValid(reg) (reg >= 0 && reg <= 15)

/*
Addresses of PSG select and write 
*/
extern volatile char* psgRegSelect = 0xFF8800;
extern volatile char* psgRegWrite = 0xFF8802;

/*
Channel A, B, C tones
*/
#define CHANNEL_A_TONE 0x0
#define CHANNEL_B_TONE 0x2
#define CHANNEL_C_TONE 0x4

#define CHANNEL_A_ROUGH_TONE 0x1
#define CHANNEL_B_ROUGH_TONE 0x3
#define CHANNEL_C_ROUGH_TONE 0x5

/*
Channel A, B, C volume
*/
#define CHANNEL_A_VOL 0x8
#define CHANNEL_B_VOL 0x9
#define CHANNEL_C_VOL 0xa

/*
Channels 
*/
#define MIXER_ALL_OFF 0xff
#define MIXER_TONE_CHANNEL_A 0x3e
#define MIXER_TONE_CHANNEL_B 0x3d
#define MIXER_TONE_CHANNEL_C 0x3b
#define MIXER_NOISE_CHANNEL_A 0x37
#define MIXER_NOISE_CHANNEL_B 0x2f
#define MIXER_NOISE_CHANNEL_C 0x1f

/*
Envelope 
*/
#define ENVELOPE_FINE_REG 0xb
#define ENVELOPE_ROUGH_REG 0xc
#define ENVELOPE_SHAPE_CONTROL_REG 0xd

#define ENVELOPE_SAW_SHAPE 0xc
#define ENVELOPE_SAW_SHAPE_INV 0x8
#define ENVELOPE_SAW_PERIOD_SHAPE  0xf
#define ENVELOPE_TRIANGLE_SHAPE 0xe
#define ENVELOPE_TRIANGLE_INV_SHAPE 0xa
#define ENVELOPE_TRIANGLE_PERIOD_SHAPE  0xd
#define ENVELOPE_TRIANGLE_INV_PERIOD_SHAPE 0x00

/* 
Regs
*/
#define NOISE_FREQUENCY_REG 0x6
#define MIXER_REG 0x7

/*
Functions for PSG 
*/

/*
    Function: writePSG
    Purpose: write the byte value to a PSG register 
    Parameters: 
        int reg - the number of a PSG register that is
                  being written to
        UINT8 val - the value that is written to the PSG
                    the register 
*/
void writePSG(int reg, UINT8 val);

/*
    Function: readPSG
    Purpose: read the value in the given register
    Parameter:
        int reg - the register number
    Returns: it returns the value that is stored in the 
             register 
                  
*/
int readPSG(int reg);

/*
    Function: setTone
    Purpose:
*/
void setTone(int channel, int tuning);

/*
    Function: setVolume
    Purpose: to load the volume register for one of
             the three channels 
    Parameters:
        int channel - the channel to set the volume to
        int volume - the volume value 
*/
void setVolume(int channel, int volume);

/*
    Function: enableChannel
    Purpose: to turn the given channel tone/noise on or off
    Parameters:
        int channel - the channel to turn on/off the tone or noise
        int toneOn - value on tone one
        int noiseOn - value of noise on
*/
void enableChannel(int channel, int toneOn, int noiseOn);

/*
    Function: stopSound
    Purpose: to stop all the sound on the PSG
*/
void stopSound();

/*
    Function: setEnvelope
    Purpose: loads the PSG envelope control register with
             one of the envelopes
    Parameters:
        envelopeShapeType shape - the envelope shape type
        UINT16 sustain - 16 bit value of the sustain 
*/
void setEnvelope(envelopeShapeType shape, UINT16 sustain);

/*
    Function: setNoise
    Purpose: load the register (noise) with the given 
             tuning value
    Parameters:
        int tuning - the tuning value 
*/
void setNoise(int tuning);

#endif 