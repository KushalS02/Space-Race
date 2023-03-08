#include "render.h"

void renderRocketship(const Rocketship *rocketship, UINT32 *base) {

    plotBitmap32(base, shipv2, rocketship->x, rocketship->y, SHIPV2_HEIGHT);

}

void renderAsteroid(const Asteroid *asteroid, UINT8 *base) {

    

}

void renderScoreBox(const Model* model, UINT16 *base) {

    printString(base, model->scorebox.x, model->scorebox.y, "Score:");
    printNumber(base, model->scorebox.x + 50, model->scorebox.y, model->scorebox.score);

}

void renderHighscoreBox(const Model* model, UINT16 *base) {

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

void render(Model* model, void* base) {

    renderBackground((UINT32*) base);
    renderRocketship(&model->player, (UINT32*) base);
    renderCheckeredLine((UINT32*) base);
    /*renderAsteroid(&model->asteroid, base);*/
    renderScoreBox(model, (UINT16*) base);
    renderHighscoreBox(model, (UINT16*) base);

}