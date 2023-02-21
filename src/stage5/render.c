#include "render.h"

void renderRocketship(const Rocketship *rocketship, UINT32 *base) {

    plotBitmap32(base, shipv2, rocketship->x, rocketship->y, SHIPV2_HEIGHT);

}

void renderAsteroid(const Asteroid *asteroid, UINT8 *base) {

    

}

void renderScoreBox(const Scorebox *scorebox, UINT16 *base) {



}

void renderHighscoreBox(const HighscoreBox *highscore, UINT16 *base) {



}

void render(Model *model, UINT16 *base) {

    renderRocketship(&model->player, base);
    renderAsteroid(&model->asteroid, base);
    renderScoreBox(&model->scorebox, base);
    renderHighscoreBox(&model->highscorebox, base);

}