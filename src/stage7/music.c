#include "music.h"

static int currentNote = 0;

const noteType mainSong[] = {

    { 168, 20 },
    { 0,   20 },
    { 201, 20 },
    { 0,   20 },
    { 238, 20 },
    { 0,   20 },
    { 148, 20 },
    { 0,   20 }

} ;

void startMusic() {

    setEnvelope(triangleInvPeriod, 10);
    enableChannel(channelC, true, false);
    setVolume(channelC, 11);

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

    setTone(channelC, mainSong[currentNote].frequency);

    return updated;

}