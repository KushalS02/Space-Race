/*
Authours: Alexander Pham and Kushal Saini
*/
#ifndef SPACE_RACE_H
#define SPACE_RACE_H

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "events.h"
#include "render.h"
#include "const.h"
#include "RASTER.H"
#include "sprites.h"
#include "TYPES.H"
#include "clearG.h"
#include "clearQK.h"

/*

Name: gameLoop

Purpose: process async and sync events as well as double buffering

Details: as long as the game is not over, it will process the async and sync events along 
         with double buffer

*/
void gameLoop();

/*

Name: processAsyncEvents

Purpose: process the asynchronous events

Parameters:

    Model *model - process the async events based from the model
    
    void *base - start of the frame buffer

*/
void processAsyncEvents(Model *model, void *base);

/*

Name: processSyncEvents

Purpose: process the synchronous events

Parameters:

    Model *model - process the sync events based from the model

*/
void processSyncEvents(Model *model);

/*

Name: gameSetup

Purpose: setup the initial state of the game

Parameters:

    Model* model - game model that is to be setup 
    
    void *base -  screen, start of the frame buffer

*/
void gameSetup(Model* model, void *base);

/*

Name: getTime

Purpose: get the time of the system

*/
long getTime();

/*

Name getBase

Purpose: get 256 byte aligned base

Parameter: 256 byte alinged screen based used for the second buffer 

*/
UINT8 *getBase(UINT8 *secondBuffer);

#endif