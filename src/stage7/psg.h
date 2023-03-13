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
volatile char* psgRegSelect = 0xFF8800;
volatile char* psgRegWrite  = 0xFF8802;

/*
Noise frequency register 
*/
#define NOISE_FREQUENCY_REG 0x6

/*
Channel A, B, C tones
*/
#define CHANNEL_A_TONE 0x0
#define CHANNEL_B_TONE 0x2
#define CHANNEL_C_TONE 0x4

/*
Channel A, B, C volume
*/
#define CHANNEL_A_VOL 0x8
#define CHANNEL_B_VOL 0x9
#define CHANNEL_C_VOL 0xa

/*
Functions for PSG 
*/
void writePSG(int reg, UINT8 val);

UINT8 readPSG(int reg);

void setTone(int channel, int tuning);

void setVolume(int channel, int volume);

void enableChannel(int channel, int toneOn, int noiseOn);

void stopSound();

void setEnvelope(envelopeShapeType shape, UINT16 sustain);

void setNoise(int tuning);

#endif 