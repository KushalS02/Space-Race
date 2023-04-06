/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: isr.c

Instructor: Paul Pospisil

*/

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
unsigned long repeatedKey;

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
    
    if (RENDER_MOUSE_REQUEST) {

        restoreMouseBackground(MENU_BUFFER, PREV_MOUSE_X, PREV_MOUSE_Y);
        saveMouseBackground(MENU_BUFFER, MOUSE_X, MOUSE_Y);
        renderMouse(MENU_BUFFER, MOUSE_X, MOUSE_Y);

        PREV_MOUSE_X = MOUSE_X;
        PREV_MOUSE_Y = MOUSE_Y;

        RENDER_MOUSE_REQUEST = false;

    }
    
    MUSIC_TIMER++;

    RENDER_REQUEST = true;

}

void ikbdReq() {

    UINT8 scancode = 0;

    *ikbdControl = 0x16;

    if (*ikbdStatus & 0x1) {
        scancode = *ikbdReader;

        switch (mouseState) {

            case MOUSE_STATE_FIRST_PACKET:

                if (scancode >= MOVE_MOUSE_CODE) {

                    /* Scancode represents a mouse movement or button press */
                    MOUSE_BUTTON = scancode;
                    mouseState = MOUSE_STATE_DELTA_X;
                    MOUSE_MOVED = scancode == MOVE_MOUSE_CODE;

                } else if ((scancode & 0x80) == 0x00) {

                    /* Scancode represents a key press */
                    writeToIkbdBuffer(scancode);
                    KEY_REPEATED = true;

                } else if ((scancode & 0x80) == 0x80){

                    /* Scancode represents a key release */
                    KEY_REPEATED = false;

                }

                break;

            case MOUSE_STATE_DELTA_X:

                MOUSE_DELTA_X = scancode;
                mouseState = MOUSE_STATE_DELTA_Y;
                break;

            case MOUSE_STATE_DELTA_Y:

                MOUSE_DELTA_Y = scancode;
                mouseState = MOUSE_STATE_FIRST_PACKET;
                break;

        }

        /* Clear bit 6 of ISRB MFP register */
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
    ikbdVector = installVector(IKBD_ISR, ikbdISR);

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
    

    if (bufferHead >= IKBD_BUFFER_SIZE - 1) {

        bufferHead = 0;

    }

    *isrbMfpRegister &= MFB_BIT_6_MASK_OFF;

    character = ikbdBuffer[bufferHead];
    character <<= 16;
    character += *(ASCII_TABLE + ikbdBuffer[bufferHead++]);
    repeatedKey = character;

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

void initializeMouse(UINT16* base) {

    MOUSE_X = 200;
    MOUSE_Y = 200;

    PREV_MOUSE_X = MOUSE_X;
    PREV_MOUSE_Y = MOUSE_Y;

    saveMouseBackground(base, MOUSE_X, MOUSE_Y);
    renderMouse(base, MOUSE_X, MOUSE_Y);

}

void updateMouseEvents(UINT16* base) {

    RENDER_MOUSE_REQUEST = false;

    MOUSE_X += (int) ((char) MOUSE_DELTA_X);
    MOUSE_Y += (int) ((char) MOUSE_DELTA_Y);

    if (MOUSE_X < 0) {

        MOUSE_X = 0;

    } else if (MOUSE_X > 624) {

        MOUSE_X = 624;

    }

    if (MOUSE_Y < MOUSE_MAX_Y) {

        MOUSE_Y = MOUSE_MAX_Y;

    } else if (MOUSE_Y > 384) {

        MOUSE_Y = 384;

    }

    MOUSE_LEFT_CLICK = MOUSE_BUTTON == MOUSE_LEFT_BUTTON_CODE;

    MOUSE_DELTA_X = 0;
    MOUSE_DELTA_Y = 0;

    RENDER_MOUSE_REQUEST = true;

}

bool ikbdMouseMoved() {

    return MOUSE_MOVED;

}