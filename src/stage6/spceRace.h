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

void gameLoop();

void processAsyncEvents(Model *model, void *base);

void processSyncEvents(Model *model, void *base);

void gameSetup(Model*model, void *base);

long getTime();

UINT8 *getBase(UINT8 *secondBuffer);

#endif