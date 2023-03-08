#ifndef SPACE_RACE
#define SPACE_RACE

#include <osbind.h>
#include "model.h"
#include "events.h"
#include "render.h"
#include "const.h"

void gameLoop();

void processAsyncEvents(Model* model, void* base);

void processSyncEvents(Model* model, void* base);

void setupGame(Model* model, void* base);

long getTime();

#endif