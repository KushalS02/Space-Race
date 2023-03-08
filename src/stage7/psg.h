#ifndef PSG_H
#define PSG_H

#include <osbind.h>
#include "TYPES.H"

void writePSG(int reg, UINT8 val);

UINT8 readPSG(int reg);

void setTone(int channel, int tuning);

void setVolume(int channel, int volume);

void enableChannel(int channel, int toneOn, int noiseOn);

void stopSound();

#endif 