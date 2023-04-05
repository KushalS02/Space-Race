/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: tstModel.c

Instructor: Paul Pospisil

*/
#include <osbind.h>
#include <stdlib.h>
#include "const.h"
#include "model.h"
#include "RASTER.H"
#include "sprites.h"
#include "events.h"
#include "TYPES.H"

int main() {


    Model model;
    int currAstr;
    unsigned long keyInput;
    int i;
    initializeModel(&model);

    printf("rocket top left X: %d \n", model.player.hitbox.topLeftX);
    printf("rocket top left Y: %d \n", model.player.hitbox.topLeftY);
    printf("rocket bottom right X: %d \n", model.player.hitbox.bottomRightX);
    printf("rocket bottom right Y: %d \n", model.player.hitbox.bottomRightY);

    printf("Asteroid coordinates: \n");
    for (currAstr = 0; currAstr < ASTEROID_MAX; currAstr++)
    {
        printf("%d: Top Left: (%d,%d) Top Right: (%d,%d)\n",
               currAstr,
               model.asteroids[currAstr].hitbox.topLeftX,
               model.asteroids[currAstr].hitbox.topLeftY,
               model.asteroids[currAstr].hitbox.bottomRightX,
               model.asteroids[currAstr].hitbox.bottomRightY);
    }

   return 0;
}