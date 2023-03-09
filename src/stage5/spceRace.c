#include "spceRace.h"
#include <osbind.h>

int main() {

    return 0;

}

long getTime() {

    long* timer = (long*) SYSTEM_CLOCK;
    
    long oldSSP = Super(0);

    long timeNow = *timer;

    Super(oldSSP);

    return timeNow;

}
