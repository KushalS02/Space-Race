/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: render.c

Instructor: Paul Pospisil

*/
#include "render.h"

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

void renderHighscoreBox(const Model* model, UINT8 *base) {

    printString(base, model->highscorebox.x, model->highscorebox.y, "Highscore:");
    printNumber(base, model->highscorebox.x + 80, model->highscorebox.y, model->highscorebox.highscore);

}

void renderCheckeredLine(UINT32 *base) {

    short i; 

    for(i = 0; i < 20; i++) {

		plotBitmap32(base, chkLine, i*32, 0, CHKLINE_HEIGHT);

	}

}

void renderBackground(UINT8 *base) {

    plotRectangle(base, RECT_PLOT_X, RECT_PLOT_Y, SCREEN_WIDTH, SCREEN_HEIGHT);

}

void render(Model *model, void *base) {

    renderBackground((UINT8*) base);
    renderRocketship(&model->player, (UINT32*) base);
    renderCheckeredLine((UINT32*) base);
    renderAsteroids(model->asteroids, (UINT8*) base);
    renderScoreBox(model, (UINT8*) base);
    renderHighscoreBox(model, (UINT8*) base);

}

void renderNextRound(Model *model, void *base) {

    renderRocketship(&model->player, (UINT32*) base);
    renderCheckeredLine((UINT32*) base);
    renderAsteroids(model->asteroids, (UINT8*) base);
    renderScoreBox(model, (UINT8*) base);
    renderHighscoreBox(model, (UINT8*) base);
}

void disableCursor() {

    printf("\033f");
    fflush(stdout);

}