/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: events.c

Instructor: Paul Pospisil

*/
#include "events.h"
#include "model.h"
#include "const.h"
#include "TYPES.H"

void rocketshipMove(Rocketship *rocketship, unsigned long key)
{

    if (key == UP_KEY) {

        moveRocketship(rocketship, up);

    }

    /* Check if rocket is hitting bottom boundry*/
    else if (key == DOWN_KEY && rocketship->hitBoundary == false) {

            moveRocketship(rocketship, down);

    }

}

void rocketshipHitBoundary(Rocketship* rocketship, Asteroid* asteroids, Scorebox* scorebox, HighscoreBox* highscoreBox) {

    /* Start next round when rocket hits top boundry*/
    if (rocketship->hitbox.topLeftY <= CHKLINE_HEIGHT) {

        initializeNextRound(rocketship, asteroids, scorebox, highscoreBox);

    } else if (rocketship->hitbox.topLeftY >= SCREEN_HEIGHT-SHIPV2_HEIGHT) {

        rocketship->hitBoundary = true;

    } else {

        rocketship->hitBoundary = false;

    }

} 
 
void asteroidsHitBoundary(Asteroid* asteroids) {

    UINT8 currAsteroid;
    
    /*Check left boundry for left moving asteroids*/
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid += 2) {

        if(asteroids[currAsteroid].hitbox.topLeftX <= 0) {

            asteroids[currAsteroid].hitbox.topLeftX = SCREEN_WIDTH - 1;

        }

    }

    /*Check right boundry for right moving asteroids*/
    for (currAsteroid = 1; currAsteroid < ASTEROID_MAX; currAsteroid += 2) {

        if(asteroids[currAsteroid].hitbox.topLeftX >= SCREEN_WIDTH - 1){

            asteroids[currAsteroid].hitbox.topLeftX = 0;

        }

    }
    
}

void rocketshipAsteroidCollision(Model *model) {
    
    UINT8 currAsteroid;

    /* Check collision for each asteroid*/
    for (currAsteroid = 0; currAsteroid < ASTEROID_MAX; currAsteroid++) {
        
        if (hitboxCollision(model->player.hitbox, model->asteroids[currAsteroid].hitbox)) {

            onGameOver(model);
            
        }

    }

}

void onGameStart(Model* model){ 

    initializeModel(model);

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