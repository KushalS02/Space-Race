#include "render.h"

void renderRocketship(const Rocketship *rocketship, UINT32 *base) {

    plotBitmap32(base, shipv2, rocketship->x, rocketship->y, SHIPV2_HEIGHT);

}

void renderAsteroid(const Asteroid *asteroid, UINT8 *base) {

    

}

void renderScoreBox(const Model* model, UINT16 *base) {

    printString(&base, model->scorebox.x, model->scorebox.y, "Score: ");
    printNumber(&base, model->scorebox.x, model->scorebox.y, model->scorebox.score);

}

void renderHighscoreBox(const Model* model, UINT16 *base) {

    printString(&base, model->highscorebox.x, model->highscorebox.y, "Highscore: ");
    printNumber(&base, model->highscorebox.x, model->highscorebox.y, model->highscorebox.highscore);

}

void renderCheckeredLine(UINT32 *base) {

    short i; 

    for(i = 0; i < 20; i++) {

		plotBitmap32(&base, chkLine, i*32, 0, CHKLINE_HEIGHT);

	}

}

void render(Model *model, UINT16 *base) {

    renderRocketship(&model->player, base);
   /* renderAsteroid(&model->asteroid, base); */
    renderScoreBox(&model->scorebox, base);
    renderHighscoreBox(&model->highscorebox, base);

}