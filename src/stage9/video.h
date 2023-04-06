/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: video.h

Instructor: Paul Pospisil

*/
#ifndef VIDEO_H
#define VIDEO_H

#include "TYPES.H"

/* Physbase() */

/*

    Function: getVideoBase

    Purpose: equivalent to calling Physbase() 
        - gets the screen buffer

    Returns: the screen buffer starting address

*/
UINT16* getVideoBase();

/* Setscreen */

/*

    Function: equivalent to calling Setscreen

    Purpose: sets the current screen base to the address

    Parameter:

        - UINT16* base - the screen base 

*/
void setVideoBase(UINT16* base);

#endif