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
extern UINT8 repeatedKey;

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

/*
FUNCTIONS 
*/
void vblReq();

void ikbdReq();

Vector installVector(int num, Vector vector);

void installVectors();

void removeVectors();

bool ikbdIsWaiting();

void writeToIkbdBuffer(UINT8 scancode);

unsigned long readFromIkbdBuffer();

void clearIkbdBuffer();

/*
mouse
*/
void initializeMouse(UINT16* base);

void updateMouseEvents(UINT16* base);

bool ikbdMouseMoved();

#endif