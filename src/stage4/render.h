#ifndef RENDER_H
#define RENDER_H

#include <osbind.h>

#include "model.h"
#include "TYPES.H"
#include "const.h"
#include "events.h"
#include "RASTER.H"
#include "sprites.h"
#include "font.h"

void renderRocketship(const Rocketship *rocketship, UINT32 *base);

void renderAsteroids(const Asteroid *asteroids, UINT8 *base);

void renderScoreBox(const Model* model, UINT16 *base);

void renderHighscoreBox(const Model* model, UINT16 *base);

void renderCheckeredLine(UINT32 *base);

void renderBackground(UINT8 *base);

void render(Model *model, void *base);

#endif 