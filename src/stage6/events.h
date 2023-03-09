#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include "model.h"

void rocketshipMove(Rocketship* rocketship, unsigned long key);

void rocketshipHitBoundary(Rocketship* rocketship, Asteroid* asteroids, Scorebox* scorebox, HighscoreBox* highscoreBox);
void asteroidsHitBoundary(Asteroid* asteroid);
void rocketshipAsteroidCollision(Model *model);

void onGameStart(Model* model);
void onGamePause(Model* model);
void onGameOver(Model* model);

bool hasUserInput();
unsigned long getUserInput();

#endif