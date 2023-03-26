#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "ikbd.h"
#include "vbl.h"
#include "music.h"
#include "render.h"
#include "TYPES.H"

/* 
constants
*/
#define VBL_ISR 28
#define IKBD_ISR 70

typedef void (*Vector) ();

#define IKBD_RX_DEFAULT 0xfffc96
#define IKBD_RX_INTERRUPT_OFF 0xfffc16

#define MFB_BIT_6_MASK_ON 0x40
#define MFB_BIT_6_MASK_OFF 0xbf

#define MOUSE_STATE_FIRST_PACKET 0
#define MOUSE_STATE_DELTA_X 1
#define MOUSE_STATE_DELTA_Y 2

#define MOUSE_MOVE_CODE 0xf8
#define MOUSE_LEFT_BUTTON_CODE 0xfa

#define IKBD_BUFFER_SIZE 256

/*
VBL timers
*/
extern int MUSIC_TIMER;
extern int GAME_TIMER;
extern int ASTEROID_TIMER;
extern int KEY_REPEAT_TICKS;

/*
render
*/
extern bool RENDER_REQUEST;
extern bool RENDER_MOUSE_REQUEST;

/*
Mouse globals
*/
extern int MOUSE_X;
extern int MOUSE_Y;

extern UINT8 mouseButton;
extern UINT8 mouseDeltaY;
extern UINT8 mouseDeltaX;
extern int prevMouseX;
extern int prevMouseY;
extern bool keyRepeat;
extern bool mouseMoved;

/*
Vectors
*/
extern Vector vblVector;
extern Vector ikbdVector;

extern UINT8 ikbdBuffer[IKBD_BUFFER_SIZE];
extern unsigned int buffHead;
extern unsigned int buffTail;
extern UINT8 repeatedKey;

/*

    Function: vblReq

    Purpose: Update the VBL IRQ timer

        - time the page flipping for double buffer 
        - time the playing of music 
        - time the sync events needed

*/
void vblReq();

/*

    Function: ikbdReq

    Purpose: process the keyboard and mouse input on the IKBD IQR

        - handles incoming mouse input 
        - handles key scancodes

*/
void ikbdReq();

/*

    Function: installVector

    Purpose: installs a single vector

    Parameters:

        int num - the trap number

        Vector vector - vector to be installed for the given trap number 

    Returns the original vector 

*/
Vector installVector(int num, Vector vector);

/*

    Function: installVectors
    
    Purpose: install the VBL and IKBD vectors

*/
void installVectors();

/*

    Function: removeVectors

    Purpose: removes the vectors installed

*/
void removeVectors();

/*

    Function: ikbdIsWaiting

    Purpose: check if the keyboard is waiting for input

*/
bool ikbdIsWaiting();

/*

    Function writeToIkbdBuffer

    Purpose: write the keyboard value to the keyboard buffer

*/
void writeToIkbdBuffer(UINT8 scancode);

/*

    Function: readFrromIkbdBuffer

    Purpose: read the keyboard value from keyboard buffer

    Returns the keyboard scancode

*/
unsigned long readFrromIkbdBuffer();

/*

    Function: clearIkbdBuffer

    Purpose: clears the keyboard buffer

*/
void clearIkbdBuffer();

#endif