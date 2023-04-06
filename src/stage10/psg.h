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
Valid ranges
*/
#define REG_MAX 0xF
#define REG_MIN 0
#define VAL_MAX 0xFF
#define VAL_MIN 0
#define NOISE_FREQ_MAX 31
#define NOISE_FREQ_MIN 0
#define TONE_MAX 0x0FFF
#define TONE_MIN 0
#define VOL_MAX 0xF
#define VOL_MIN 0
#define ENV_FREQ_MAX 0xFFFF
#define ENV_FREQ_MIN 0

/*
Addresses of PSG select and write 
*/
extern volatile char* psgRegSelect = 0xFF8800;
extern volatile char* psgRegWrite = 0xFF8802;

/*
Channel A, B, C tone registers
*/
#define A_FINE_TONE 0x0
#define B_FINE_TONE 0x2
#define C_FINE_TONE 0x4

#define A_ROUGH_TONE 0x1
#define B_ROUGH_TONE 0x3
#define C_ROUGH_TONE 0x5

/*
Channel A, B, C volume registers
*/
#define A_VOL 0x8
#define B_VOL 0x9
#define C_VOL 0xa

/*
Mixer registers
*/
#define MIXER_REG 0x7

/*
Mixer masks
*/
#define MIXER_ALL_OFF 0xff
#define MIXER_TONE_A 0x3e
#define MIXER_TONE_B 0x3d
#define MIXER_TONE_C 0x3b
#define MIXER_NOISE_A 0x37
#define MIXER_NOISE_B 0x2f
#define MIXER_NOISE_C 0x1f

/*
Envelope registers
*/
#define ENVELOPE_FINE 0xb
#define ENVELOPE_ROUGH 0xc
#define ENVELOPE_SHAPE 0xd

/*
Shape masks
*/
#define SAW_SHAPE 0xc
#define TRIANGLE_SHAPE 0xe

/* 
Noise registers
*/
#define NOISE_FREQ 0x6

/*
Functions for PSG 
*/

/*

    Function: writePSG

    Purpose: write the byte value to a PSG register 

    Parameters: 

        UINT16 reg - the number of a PSG register that is
                  being written to

        UINT8 val - the value that is written to the PSG
                    the register 

*/
void writePSG(UINT16 reg, UINT8 val);

/*

    Function: readPSG

    Purpose: read the value in the given register

    Parameter:

        UINT16 reg - the register number

    Returns: it returns the value that is stored in the 
             register 
                  

*/
UINT8 readPSG(UINT16 reg);

/*

    Function: setTone

    Purpose: loads the tone registers for one of the channels
             with the 12 bit tuning

    Parameters:

        int channel - the channel to set tone on

        int tuning - the 12 bit tuning
            - low 4 bits: rough adjustment
            - bits 11-4: fine adjustment
            - bits 15-12: unused

*/
void setTone(Channel channel, UINT16 tuning);

/*

    Function: setVolume

    Purpose: to load the volume register for one of
             the three channels 

    Parameters:

        UINT16 channel - the channel to set the volume to

        UINT16 volume - the volume value 

*/
void setVolume(Channel channel, UINT16 volume);

/*

    Function: enableChannel

    Purpose: to turn the given channel tone/noise on or off

    Parameters:

        UINT16 channel - the channel to turn on/off the tone or noise

        UINT16 toneOn - value on tone one

        UINT16 noiseOn - value of noise on

*/
void enableChannel(Channel channel, bool toneOn, bool noiseOn);

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

        envelopeShape shape - the envelope shape type

        UINT16 sustain - 16 bit value of the sustain 

*/
void setEnvelope(envelopeShape shape, UINT16 sustain);

/*

    Function: setNoise

    Purpose: load the register (noise) with the given 
             tuning value

    Parameters:

        UINT16 tuning - the tuning value 
            - Low 8 bits: fine adjustment
            - High 8 bits: rought adjustment

*/
void setNoise(UINT16 tuning);

#endif 