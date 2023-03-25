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

#endif