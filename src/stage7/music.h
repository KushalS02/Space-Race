#ifndef MUSIC_H
#define MUSIC_H

#include "psg.h"
#include "TYPES.H"

#define NOTE_C_FLAT 478
#define NOTE_C 451
#define NOTE_D_FLAT 428 
#define NOTE_D 402
#define NOTE_E_FLAT 379
#define NOTE_F_FLAT 358
#define NOTE_F 338
#define NOTE_G_FLAT 319
#define NOTE_G 301
#define NOTE_A_FLAT 284
#define NOTE_A 268
#define NOTE_B_FLAT 253

#define NOTES_SIZE 168

typedef struct {

    int frequency;
    int duration;

} noteType;

void startMusic();

bool updateMusic(UINT32 timeElapsed);

#endif