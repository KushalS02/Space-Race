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
bool RENDER_REQUEST = true;
bool RENDER_MOUSE_REQUEST = false;

/*
buffer
*/
UINT8 ikbdBuffer[IKBD_BUFFER_SIZE];
unsigned int bufferHead = 0;
unsigned int bufferTail = 0;
UINT8 repeatedKey = 0;

/*
mouse
*/
int mouseState = 0;
UINT8 MOUSE_BUTTON;
UINT8 MOUSE_DELTA_X;
UINT8 MOUSE_DELTA_Y;
bool MOUSE_LEFT_CLICK = false;
bool KEY_REPEATED = false;
bool MOUSE_MOVED = false;

int MOUSE_X = 0;
int MOUSE_Y = 0;
int PREV_MOUSE_X = 0;
int PREV_MOUSE_Y = 0;


void vblReq() {

    MUSIC_TIMER++;
    KEY_REPEAT_TICKS++;
    GAME_TIMER++;
    ASTEROIDS_TIMER++;

    RENDER_REQUEST = true;
    RENDER_MOUSE_REQUEST = true;

}

void ikbdReq() {

    UINT8 scancode;

    *ikbdControl = 0x16;

    if (*ikbdStatus & 0x1) {

        scancode = *ikbdReader;

        if (mouseState == MOUSE_STATE_FIRST_PACKET) {

            if (scancode >= MOVE_MOUSE_CODE) {

                MOUSE_BUTTON = scancode;
                mouseState = MOUSE_STATE_DELTA_X;
                MOUSE_MOVED = scancode == MOVE_MOUSE_CODE;

            } else if ((scancode & 0x80) == 0x00) {

                writeToIkbdBuffer(scancode);
                KEY_REPEATED = true;

            } else if ((scancode & 0x80) == 0x80) {

                KEY_REPEATED = false;

            } 
            
            } else if (mouseState == MOUSE_STATE_DELTA_X) {

                mouseState = MOUSE_STATE_DELTA_Y;
                MOUSE_DELTA_X = scancode;

            } else if (mouseState == MOUSE_STATE_DELTA_Y) {

                mouseState = MOUSE_STATE_FIRST_PACKET;
                MOUSE_DELTA_Y = scancode;

            }

        *isrbMfpRegister &= MFB_BIT_6_MASK_OFF;

    }

    *ikbdControl = 0x96;

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

    vblVector = installVector(VBL_ISR, vblISR);
    /*ikbdVector = installVector(IKBD_ISR, ikbdISR);*/

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

UINT8 getRepeatedKey() {

    return repeatedKey;

}