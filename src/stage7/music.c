#include "music.h"

static int currentNote = 0;

const noteType mainSong[] = {

}

void startMusic() {

    enableChannel(channelC, true, false);
    setVolume(channelC, 11);

}

bool updateMusic(UINT32 timeElapsed) {

    bool updated = false;

    if (timeElapsed >= mainSong[currentNote].duration) {

        currentNote++;

        updated = true;

    }

    

}