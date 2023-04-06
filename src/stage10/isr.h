/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: isr.h

Instructor: Paul Pospisil

*/

#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include "vbl.h"
#include "ikbd.h"
#include "music.h"
#include "render.h"
#include "TYPES.H"

/*
VBL and ISR stuff
*/
#define VBL_ISR 28
#define IKBD_ISR 70

#define IKBD_RX_DEFAULT 0xfffc96
#define IKBD_RX_INTERRUPT_OFF 0xfffc16

#define MFB_BIT_6_MASK_ON 0x40
#define MFB_BIT_6_MASK_OFF 0xbf

#define IKBD_BUFFER_SIZE 256

#define MOUSE_STATE_FIRST_PACKET 0
#define MOUSE_STATE_DELTA_X 1
#define MOUSE_STATE_DELTA_Y 2
#define MOVE_MOUSE_CODE 0xf8
#define LEFT_BUTTOM_MOUSE_CODE 0xfa

typedef void (*Vector) ();

/*
VBL timers
*/
extern int MUSIC_TIMER;
extern int GAME_TIMER;
extern int ASTEROIDS_TIMER;
extern int KEY_REPEAT_TICKS;

/*
render flags
*/
extern bool RENDER_REQUEST;
extern bool RENDER_MOUSE_REQUEST;

/*
IKBD buffer stuff
*/
extern UINT8 ikbdBuffer[IKBD_BUFFER_SIZE];
extern unsigned int bufferHead;
extern unsigned int bufferTail;
extern unsigned long repeatedKey;

/*
vectors
*/
extern Vector vblVector;
extern Vector ikbdVector;

/*
mouse stuff
*/
extern int MOUSE_X;
extern int MOUSE_Y;

extern bool MOUSE_LEFT_CLICK;

extern UINT8 MOUSE_BUTTON;
extern UINT8 MOUSE_DELTA_X;
extern UINT8 MOUSE_DELTA_Y;
extern int PREV_MOUSE_X;
extern int PREV_MOUSE_Y;
extern bool MOUSE_MOVED;
extern bool KEY_REPEATED;

#define MOUSE_MOVE_CODE 0xf8
#define MOUSE_LEFT_BUTTON_CODE 0xfa

/*
FUNCTIONS 
*/

/*

    Function: vblReq

    Purpose: updates the VBL IQR to time the page flipping of 
             double buffered graphics, timing of music and
             synchronous events

*/
void vblReq();

/*

    Function: ikbdReq

    Purpose: processes the keyboard and mouse input
             on the IKBD IRQ

*/
void ikbdReq();

/*

    Function: installVector

    Purpose: installs a single vector 

    Parameters:

        - int num - the trap number to be installed

        - Vector vector - the vector to be installed
                          for the trap number

*/
Vector installVector(int num, Vector vector);

/*

    Function: installVectors

    Purpose: to intsall the VBL and IKBD vectors

*/
void installVectors();

/*

    Function: removeVectors 

    Purpose: remove the VBL and IKBD vectors 

*/
void removeVectors();

/*

    Function: ikbdIsWaiting

    Purpose: check to see if the keyboard 
             is waiting for input

    Return: if true or false if the keyboard is waiting

*/
bool ikbdIsWaiting();

/*

    Function: writeToIkbdBuffer

    Purpose: write the keyboard valye to the 
             keyboard buffer

    Parameter:

        - UINT8 scancode - the key code of the keyboard

*/
void writeToIkbdBuffer(UINT8 scancode);

/*

    Function: readFrormIkbdBuffer

    Purpose: read the keyboard value from the keyboard buffer

    Returns: the keyboard scancode

*/
unsigned long readFromIkbdBuffer();

/*

    Function: clearIkbdBuffer

    Purpose: clears the ikbd buffer

*/
void clearIkbdBuffer();

/*
mouse
*/
/*

    Function: initializeMouse

    Purpose: initialize the mouse as well as save the background
             and render the cursor bitmap

    Parameter:

        - UINT16* base - the start address of the frame buffer

*/
void initializeMouse(UINT16* base);

/*

    Function: updateMouseEvents

    Purpose: update the mouse position and draw the updated
             cursor location

    Parameter:

        - UINT16* base - the start address of the frame buffer

*/
void updateMouseEvents(UINT16* base);

/*

    Function: ikbdMouseMoved

    Purpose: check if the mouse has been moved

    Returns: true if the mouse moved or false if it hasn't moved

*/
bool ikbdMouseMoved();

#endif