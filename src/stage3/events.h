#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include <stdio.h>
#include "model.h"
#include "types.h"
#include "const.h"

void rocketshipMove(Rocketship* rocketship, unsigned long key);

void rocketshipHitBoundary(Rocketship* rocketship);
void asteroidHitBoundary(Asteroid* asteroid);

void onGameStart(Model* model);
void onGamePause(Model* model);
void onGameOver(Model* model);

#endif