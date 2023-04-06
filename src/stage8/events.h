/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: events.h

Instructor: Paul Pospisil

*/
#ifndef EVENTS_H
#define EVENTS_H

#include <osbind.h>
#include "model.h"
#include "psg.h"
#include "effects.h"

/*
* Function: rocketshipMove
* Purpose: moves rocketship up or down depending on key press
* Input:
*   - Rocketship*: the rocketship to be moved
*   - unsigned long: the code of the pressed key
*/
void rocketshipMove(Rocketship* rocketship, unsigned long key);

/*
* Function: rocketshipHitBoundry
* Purpose: checks if the rocketship is hitting the bottom boundry
*   and sets the bool hitBoundry member of Rocketship accordingly.
* Input:
*   - Rocketship*: the rocketship being checked
*/
void rocketshipHitBoundary(Rocketship* rocketship);

/*
* Function: rocketshipHitFinish
* Purpose: checks if the rocketship has reached the finish line
* Input:
*   - Rocketship*: rocketship being checked
* Output:
*   - bool: False = has not reached finish, True = reached finish
*/
bool rocketshipHitFinish(Rocketship* rocketship);

/*
* Function: asteroidsHitBoundry
* Purpose: If any of the asteroids in the array are at or past the screen boundry,
*   the are reset to the other side of the screen
* Input: 
*   - Asteroid*: pointer to the array of asteroids
*/
void asteroidsHitBoundary(Asteroid* asteroid);

/*
* Funciton: rocketshipAsteroidCollision
* Purpose: Checks for collisions between the rocketship and asteroids.
*   If ther are any collisions, the gameOver flag in model is set to true.
* Input:
*   - Model*: the game model
*/
void rocketshipAsteroidCollision(Model *model);

/*
 Function: onAsteroidsMove

 Purpose: event to move asteroids on the screen

 Input: Model *model - the game model

*/
void onAsteroidsMove(Model *model);

/*
 Function: onGameStart

 Purpose: event that is called when game starts

 Input: 
    - Model*: the game model
*/
void onGameStart(Model* model);

/*
 Function: onGameOver

 Purpose: event that is called when game ends

 Input: 
    - Model*: the game model
*/
void onGameOver(Model* model);

/*
 Function hasUserInput
 Purpose: check if a key is being pressed 
 Output:
    - bool: True = key is pressed, False = key not pressed
*/
bool hasUserInput();

/*
 Function: getUserInput
 Purpose: get the key code that is being pressed
*/
unsigned long getUserInput();

#endif