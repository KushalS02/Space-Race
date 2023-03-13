#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"
#include "TYPES.H"

typedef struct {

    int frequency;
    int duration;

} noteType;


void startMusic();

bool updateMusic(UINT32 timeElapsed);

#endif