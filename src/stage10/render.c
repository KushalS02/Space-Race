/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: render.c

Instructor: Paul Pospisil

*/
#include "render.h"
#include <string.h>

void renderRocketship(const Rocketship *rocketship, UINT32 *base) {

    plotBitmap32(base, shipv2, rocketship->hitbox.topLeftX, rocketship->hitbox.topLeftY, SHIPV2_HEIGHT);

}

void clearRocketship(const Rocketship *rocketship, UINT32* base) {

    clearRegion32(base, rocketship->hitbox.topLeftX, rocketship->hitbox.topLeftY, SHIPV2_WIDTH, SHIPV2_HEIGHT);

}

void renderAsteroids(const Asteroid *asteroids, UINT8 *base) {

   UINT8 currAstr;

   for (currAstr = 0; currAstr < ASTEROID_MAX; currAstr++) {

        plotBitmap8(base, astrv2, asteroids[currAstr].hitbox.topLeftX, asteroids[currAstr].hitbox.topLeftY, ASTRV2_HEIGHT);

    }

}

void clearAsteroids(const Asteroid *asteroids, UINT8* base) {

    short currAstr;

    for (currAstr = 0; currAstr < ASTEROID_MAX; currAstr++) {

        plotRectangle(base, asteroids[currAstr].hitbox.topLeftX, asteroids[currAstr].hitbox.topLeftY, ASTRV2_WIDTH, ASTRV2_HEIGHT);

    }
    
}

void renderScoreBox(const Model* model, UINT8 *base) {

    printString(base, model->scorebox.x, model->scorebox.y, "Score:");
    printNumber(base, model->scorebox.x + 50, model->scorebox.y, model->scorebox.score);

}



void renderCheckeredLine(UINT32 *base) {

    short i; 

    for(i = 0; i < 20; i++) {

		plotBitmap32(base, chkLine, i*32, 0, CHKLINE_HEIGHT);

	}

}

void renderBackground(UINT8 *base) {

    clearQuick(base);

}

void render(Model *model, void *base) {

    renderBackground((UINT8*) base);
    renderRocketship(&model->player, (UINT32*) base);
    renderCheckeredLine((UINT32*) base);
    renderAsteroids(model->asteroids, (UINT8*) base);
    renderScoreBox(model, (UINT8*) base);

}

void renderNextRound(Model *model, void *base) {

    renderRocketship(&model->player, (UINT32*) base);
    renderCheckeredLine((UINT32*) base);
    renderAsteroids(model->asteroids, (UINT8*) base);
    renderScoreBox(model, (UINT8*) base);
}

void disableCursor() {

    printf("\033f");
    fflush(stdout);

}

void renderSplashscreen(UINT32* base) {

    memcpy(base, splashScreen, 32000); 

}

void renderGameOver(void* base, UINT8 currScore) {

    memcpy(base, endGameScreen, 32000);
    printNumber((UINT8*)base, END_GAME_SCORE_X, END_GAME_SCORE_X, currScore);

}

void renderMouse(UINT16* base, int x, int y) {

    plotBitmap16(base, mousePointer, x, y, SPRITE_HEIGHT);

}

void saveMouseBackground(UINT16* base, int x, int y) {

    int i, j;

    for (i = 0, j = 0; i < MOUSE_BACKGROUND_SIZE; i++) {

        mouseBackground[j++] = *(base + (y + i) * 40 + (x >> 4));

    }

}

void restoreMouseBackground(UINT16* base, int x, int y) {

    int i, j;

    for (i = 0, j = 0; i < MOUSE_BACKGROUND_SIZE; i++) {

        *(base + (y + i) * 40 + (x >> 4)) = mouseBackground[j++];

    }

}