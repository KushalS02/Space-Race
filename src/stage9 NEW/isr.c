#include "isr.h"

/*
vectors
*/
Vector vblVector;
Vector ikbdVector;

/*
ikbd stuff
*/
volatile UINT8* const ikbdControl = 0xfffc00;
volatile UINT8* const ikbdStatus = 0xfffc00;
volatile UINT8* const ikbdReader = 0xfffc02;
volatile UINT8* const isrbMfpRegister = 0xfffa11;
volatile UINT8* const ASCII_TABLE = 0xFFFE829C;

/*
timer
*/
int MUSIC_TIMER = 0;
int GAME_TIMER = 0;
int ASTEROIDS_TIMER = 0;
int KEY_REPEAT_TICKS = 0;

/*
buffer
*/
UINT8 ikbdBuffer[IKBD_BUFFER_SIZE];
unsigned int bufferHead = 0;
unsigned int bufferTail = 0;
UINT8 repeatedKey = 0;

void vblReq() {

    MUSIC_TIMER++;
    KEY_REPEAT_TICKS++;
    GAME_TIMER++;
    ASTEROIDS_TIMER++;

    RENDER_REQUEST = true;

}

void ikbdReq() {

    UINT8 scancode;

    *ikbdControl = 0x16;

    if (*ikbdStatus & 0x1) {

        scanecode = *ikbdReader;

        /* finish this */

    }

}

Vector installVector(int num, Vector vector) {

    Vector* vectp = (Vector *) ((long) num << 2);
    Vector orig;
    long oldSSP = Super(0);

    orig = *vectp;
    *vectp = vector;

    Super(oldSSP);

    return orig;

}

void installVectors() {

    vblVector = installVector(VBL_ISR, vblISR());
    ikbdVector = installVector(IKBD_ISR, ikbdISR());

}

void removeVectors() {

    installVector(VBL_ISR, vblVector);
    installVector(IKBD_ISR, ikbdVector); 

}

bool ikbdIsWaiting() {

    return bufferHead != bufferTail;

}

void writeToIkbdBuffer(UINT8 scancode) {

    if (bufferTail == IKBD_BUFFER_SIZE - 1) {

        bufferTail = 0;

    }

    ikbdBuffer[bufferTail] = scancode;
    bufferTail++;

}

unsigned long readFromIkbdBuffer() {

    unsigned long character;

    long oldSSP = Super(0);

    if (bufferHead == IKBD_BUFFER_SIZE - 1) {

        bufferHead = 0;

    } 

    *isrbMfpRegister &= MFB_BIT_6_MASK_OFF;

    character = ikbdBuffer[bufferHead];
    character = character << 16;
    character = character + *(ASCII_TABLE + ikbdBuffer[bufferHead++]);

    *isrbMfpRegister |= MFB_BIT_6_MASK_ON;

    Super(oldSSP);

    return character;

}

void clearIkbdBuffer() {

    while (ikbdIsWaiting()) {

        bufferHead++;

    }

    ikbdBuffer[bufferTail] = 0x00;

}