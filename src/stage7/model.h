/*
* Authours: Alexander Pham and Kushal Saini
*
* Course: COMP 2659 - 001
*
* File name: model.h
*
* Instructor: Paul Pospisil
*
* model.h contains all the structs used in the game as well as functions to manipulate the structs.
* 
* structures:
*   - Hitbox: Holds the coordinates for screen elements. Used in collision detection and rendering.
*   - Rocketship: contains elements used for the rocketship
*   - Asteroid: contains elements used for the asteroid
*   - Scorebox: contains int x,y coords and int score
*   - HighscoreBox: contains int x,y coords and int highscore
*   - Model: contains all elements of the game (holds all the other structs).
*       - has an array of Asteroid structs
*/

#ifndef MODEL_H
#define MODEL_H

#include <osbind.h>
#include "const.h"
#include "TYPES.H"

/*
All the typedef for structures 
*/
typedef struct {

    UINT16 topLeftX;
    UINT16 topLeftY;
    UINT16 bottomRightX;
    UINT16 bottomRightY;

} Hitbox;

typedef struct {

    rocketShipDirection direction;
    Hitbox hitbox;
    bool alive;
    bool hitBoundary;

} Rocketship;

typedef struct {

    int deltaX;
    Hitbox hitbox;
    asteroidDirecton direction;
    bool hitBoundary;

} Asteroid;

typedef struct {

    unsigned int x, y, score;

} Scorebox;

typedef struct {

    unsigned int x, y, highscore;

} HighscoreBox;

typedef struct {

    Rocketship player;
    Asteroid asteroids[ASTEROID_MAX];
    Scorebox scorebox;
    HighscoreBox highscorebox;
    bool gameOver;
    bool playing;

} Model;

/*
Rocketship Functions
*/

/*
* Function: moveRocketship
* Purpose: moves the hitbox coordinates of the rocketship up or down depending on user input
* Input:
*   - Rocketship*: a pointer to the rocketship which is moved
*   - rocketShipDirection: the direction to move the rocketship (up/down)
*/
void moveRocketship(Rocketship* rocketship, rocketShipDirection direction);

/*
* Function: initializeRocketship
* Purpose: initializes all the members of the Rocketship strct
* Input:
*   - Rocketship*: pointer to the struct to initialize
*/
void initializeRocketship(Rocketship* rocketship);

/*
Asteroid Functions
*/

/*
* Function: moveAsteroids
* Purpose: moves all the asteroids in the array (left/right)
* Input:
*   - Asteroid*: pointer to the Asteroid array
*/
void moveAsteroids(Asteroid* asteroids);

/*
* Function: initializeAsteroids
* Purpose: Takes an array of Asteroid structs and initializes all members
* Input:
*   - Asteroid*: pointer to the Asteroid array
*/
void initializeAsteroids(Asteroid* asteroids);

/*
Score Functions
*/

/*
* Function: initializeScore
* Purpose: initialzes the members of the scorebox
* Input:
*   - Scorebox*: pointer to the Scorebox struct to initialize
*/
void initializeScore(Scorebox* scorebox);

/*
* Function: updateScore
* Purpose: increments score with the value of playerScore
*   - score is not incremented past MAX_SCORE
* Input:
*   - Scorebox*: pointer to the scorebox to update
*   - int: the value to increment the score by
*/
void updateScore(Scorebox* scorebox, int playerScore);

/*
* Function: intializeHighscore
* Purpose: initializes the members of the HighscoreBox struct
* Input:
*   - HighscoreBox*: pointer to the HighscoreBox struct to intalize
*/
void initializeHighscore(HighscoreBox* highscoreBox);

/*
* Function: updateHighscore
* Purpose: checks if the score is higher than the highscore and updates the highscore accordingly
* Input:
*   - HighscoreBox*: pointer to the highscoreBox to update
*   - int: the score value the highscore is compared to
*/
void updateHighscore(HighscoreBox* highscoreBox, int score);

/*
Model Functions
*/

/*
* Function: initializeModel
* Purpose: initializes all the members of model. This sets up the entire game.
*   - srand() is called here 
* Input:
* - Model*: pointer to the Model struct to initialize
*/
void initializeModel(Model* model);

/*
* Function: initializeNextRound
* Purpose: prepares all the structs for the next round
* Input:
*   - Rocketship*: The rocketship's coordinates are reset to the bottom of the screen
*   - Asteroid*: All asteroids are redrawn at random locations
*   - Scorebox*: The score is incremented by SCORE_INCREMENT
*   - HighscoreBox*: The highscore is updated if needed
*/
void initializeNextRound(Rocketship* rocketship, Asteroid* asteroids, Scorebox* scorebox, HighscoreBox* highscoreBox);

/*

Name: gameOver

Purpose: set the game state to game over (playing = false)

Input: Model* model - the game model 

*/
void gameOver(Model* model);

/*
Helper functions
*/

/*
* Function: hitboxCollision
* Purpose: checks if the inputted  hitboxes are colliding
* Input:
*   - Hitbox hb1: pointer to 1st hitbox
*   - Hitbox hb2: pointer to 2nd hitbox
* Output:
*   - bool: False = no collision, True = collision
*/
bool hitboxCollision(Hitbox* hb1, Hitbox* hb2);

#endif