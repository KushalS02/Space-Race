#include "isr.h"

int MUSIC_TIMER = 0;
int GAME_TIMER = 0;
int ROCKET_TIMER = 0;
int ASTEROID_TIMER = 0;
int KEY_REPEAT_TICKS = 0;
bool RENDER_REQUEST = true;
bool RENDER_MOUSE_REQUEST = false;

/*
defines
*/
Vector vblVector;
Vector ikbdVector;

volatile UINT8* const IKBD_CONTROL = 0xfffc00;
volatile UINT8* const IKBD_STATUS = 0xfffc00;
volatile UINT8* const IKBD_READER = 0xfffc02;
volatile UINT8* const ISRB_MFP_REGISTER = 0xfffa11;

volatile UINT8* const ASCII_TABLE = 0xFFFE829C;




void vblReq() {

    MUSIC_TIMER++;

    KEY_REPEAT_TICKS++;

    GAME_TIMER++;
    ROCKET_TIMER++;
    ASTEROID_TIMER++;

    RENDER_REQUEST = true;
    RENDER_MOUSE_REQUEST = false;

}

void ikbdReq() {



}

Vector installVector(int num, Vector vector) {

    Vectorr original; 

    Vector* vect = (Vector *) ((long) num << 2);

    long oldSSP = Super(0);

    original = *vect;
    *vect = vector;

    Super(oldSSP);

    return original;


}

void installVectors() {

    vblVector = installVector(VBL_ISR, vblVector);
    ikbdVector = installVector(IKBD_ISR, ikbdISR);

}

void removeVectors() {

    installVector(VBL_ISR, vblVector);
    installVector(IKBD_ISR, ikbdVector);

}

bool ikbdIsWaiting() {

    return buffHead != buffTail;

}

void writeToIkbdBuffer(UINT8 scancode) {

    if (buffTail == IKBD_BUFFER_SIZE - 1) {

        buffTail = 0;

    }

    ikbdBuffer[buffTail] = scancode;
    buffTail++;

}

unsigned long readFrromIkbdBuffer() {

    unsigned long ch;

    long oldSSP = Super(0);

    if (buffHead == IKBD_BUFFER_SIZE - 1) {

        buffHead = 0;

    }

    *ISRB_MFP_REGISTER &= MFB_BIT_6_MASK_OFF;

    ch = ikbdBuffer[buffHead];
    ch = ch << 16;
    ch = ch + *(ASCII_TABLE + ikbdBuffer[buffHead++]);

    *ISRB_MFP_REGISTER |= MFB_BIT_6_MASK_ON;

    Super(oldSSP);

    return ch;

}

void clearIkbdBuffer() {

    while (ikbdIsWaiting()) {

        buffHead++;
    }

    ikbdBuffer[buffTail] = 0x00;

}