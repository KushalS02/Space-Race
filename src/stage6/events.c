#include "events.h"
#include "model.h"
#include "const.h"
#include "TYPES.H"

void rocketshipMove(Rocketship *rocketship, unsigned long key)
{

    if (key == UP_KEY)
    {

        moveRocketship(rocketship, up);
    }
    /* Check if rocket is hitting bottom boundry*/
    else if (key == DOWN_KEY && rocketship->hitBoundary == false)
    {
            moveRocketship(rocketship, down);
    }
}

void rocketshipHitBoundary(Rocketship* rocketship) {

    if (rocketship->hitbox.topLeftY >= SCREEN_HEIGHT-SHIPV2_HEIGHT) {
        rocketship->hitBoundary = true;
    } else {
        rocketship->hitBoundary = false;
    }

}

bool rocketshipHitFinish(Rocketship* rocketship)
{
    if (rocketship->hitbox.topLeftY <= CHKLINE_HEIGHT)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void asteroidsHitBoundary(Asteroid* asteroids) {
    UINT8 currAsteroid;
    
    /*Check left boundry for left moving asteroids*/
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid+=2) {
        if(asteroids[currAsteroid].hitbox.topLeftX <= 0) {
            asteroids[currAsteroid].hitbox.topLeftX = SCREEN_WIDTH-1;
        }
    }
    /*Check right boundry for right moving asteroids*/
    for (currAsteroid = 1; currAsteroid < ASTEROID_MAX; currAsteroid+=2) {
        if(asteroids[currAsteroid].hitbox.topLeftX >= SCREEN_WIDTH-1){
            asteroids[currAsteroid].hitbox.topLeftX=0;
        }
    }

}

void rocketshipAsteroidCollision(Model *model) {
    UINT8 currAsteroid;
    /* Check collision for each asteroid*/
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++) {
        
        if (hitboxCollision(&model->player.hitbox, &model->asteroids[currAsteroid].hitbox)) {
            onGameOver(model);
        }

    }

}

void onGameStart(Model* model){ 

    initializeModel(model);

}

void onGamePause(Model* model) {

    pauseGame(model);

}

void onGameOver(Model* model) {

    gameOver(model);

}

bool hasUserInput() {

    return Cconis();

}

unsigned long getUserInput() {

    return Cnecin() >> 16;

}