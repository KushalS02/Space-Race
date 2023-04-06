/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: clear.h

Instructor: Paul Pospisil

*/
#ifndef CLEAR_H
#define CLEAR_H

/*

Name: clearG

Purpose: clears everything on the screen except the 
         checkered line and score box

Input: void base* - the screen to be cleared

*/
void clearGame(void *base);

/*
Name: clearQuick

Purpose: clears only a section of the screen 

Input: void *base - screen to be cleared
*/
void clearQuick(void *base);

#endif