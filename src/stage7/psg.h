#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include "TYPES.H"

#define regIsValid(reg) (reg >= 0 && reg <= 15)

volatile char* psgRegSelect = 0xFF8800;
volatile char* psgRegWrite  = 0xFF8802;

void writePSG(int reg, UINT8 val);

UINT8 readPSG(int reg);

void setTone(int channel, int tuning);

void setVolume(int channel, int volume);

void enableChannel(int channel, int toneOn, int noiseOn);

void stopSound();

#endif 