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



}

void setTone(int channel, int tuning) {



}

void setVolume(int channel, int volume) {



}

void enableChannel(int channel, int toneOn, int noiseOn) {




}

void stopSound() {



}