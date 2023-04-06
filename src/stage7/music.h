/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: music.h

Instructor: Paul Pospisil

*/
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

/*
    Structure to hold the notes of the music

    frequency - the frequency of the note

    duration - how long the note is played for

*/
typedef struct {

    int frequency;
    int duration;

} noteType;

/*

    Function: startMusic

    Purpose: starts playing music by loading the first note of the
             circular array into the PSG 

*/
void startMusic();

/*

    Function: updateMusic

    Purpose: goes to the next note of the song based on the time elapsed 
             from the previous call

    Parameter: 

        - UINT32 timeElapsed - the time that is elapsed since
                               the last call

*/
bool updateMusic(UINT32 timeElapsed);

#endif