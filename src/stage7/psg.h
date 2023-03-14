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
void writePSG(int reg, UINT8 val);

UINT8 readPSG(int reg);

void setTone(int channel, int tuning);

void setVolume(int channel, int volume);

void enableChannel(int channel, int toneOn, int noiseOn);

void stopSound();

void setEnvelope(envelopeShapeType shape, UINT16 sustain);

void setNoise(int tuning);

#endif 