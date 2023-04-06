/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: music.c

Instructor: Paul Pospisil

*/
#include "music.h"

static int currentNote = 0;

const noteType mainSong[] = {

  /* {frequency, duration} */

    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10},
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10},
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {349, 10}, 
    {293, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {261, 10}, 
    {220, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {196, 10}, 
    {165, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10}, 
    {123, 10}, 
    {147, 10},


} ;

void startMusic() {

  int sustain = 8;

  int volume = 10;

    setEnvelope(triangleInvPeriod, sustain);

    enableChannel(channelA, true, false);

    setVolume(channelA, volume);

}

bool updateMusic(UINT32 timeElapsed) {

    bool updated = false;

    if (timeElapsed >= mainSong[currentNote].duration) {

        currentNote++;

        updated = true;

    }

    if (currentNote > (NOTES_SIZE - 1)) {

        currentNote = 0;

    }

    setTone(channelA, mainSong[currentNote].frequency);

    return updated;

}