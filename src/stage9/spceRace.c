/*
Authours: Alexander Pham and Kushal Saini
*/
#include "spceRace.h"
#include <osbind.h>

const UINT8 secondBuff[SCREEN_BUFFER_SIZE];

extern int MUSIC_TIMER;
extern int GAME_TIMER;
extern int ASTEROIDS_TIMER;
extern int KEY_REPEAT_TICKS;
extern bool RENDER_REQUEST;
extern bool KEY_REPEATED;

int main() {

    installVectors();    
    start();
    removeVectors();
    return 0;

}

void start() {

    UINT16* base;
    long oldSSP;

    oldSSP = Super(0);

    base = getVideoBase();

    Super(oldSSP);

    disableCursor();
    clearQuick(base);
    renderSplashscreen((UINT32*) base);
    menu();

}

UINT8 *getBase(UINT8 *secondBuffer) {

    UINT8 *base;

    UINT16 difference;

    base = secondBuffer;

    difference = (int) base;

    difference %= 0x100;

    difference = 0x100 - difference;

    return base + difference;

}

void gameLoop() {
    
    long oldSSP;
    Model model;
    bool swapScreens = false;
    void *screen2;
    UINT16* base;
    UINT16 *currScreen = base;
    UINT8 currScore = 0;
    UINT32 prevCall;

    oldSSP = Super(0);
    base = getVideoBase();

    Super(oldSSP);

    screen2 = getBase(secondBuff);

    /*prevCall = getTime();*/

    gameSetup(&model, base);
    render(&model, screen2);
    startMusic();

    while (!model.gameOver && model.scorebox.score <= MAX_SCORE) {

        processAsyncEvents(&model);
        startMusic();

        if(updateMusic(MUSIC_TIMER)) {

            MUSIC_TIMER = 0;
       }

        if(currScore < model.scorebox.score) {
            renderNextRound(&model, base);
            renderNextRound(&model, screen2);
            currScore = model.scorebox.score;
        }

        /*timeNow = getTime();
        timeElapsed = timeNow - timeThen;
        
        
        if (timeElapsed > 0) {

            if (swapScreens){
                currScreen = base;
                clearGame(currScreen);
            } else {
                currScreen = screen2;
                clearGame(currScreen);
            }

            timeThen = timeNow;
            processSyncEvents(&model);

            renderAsteroids(model.asteroids, (UINT8*)currScreen);
            renderRocketship(&model.player, (UINT32*)currScreen);

            oldSSP = Super(0);
            setVideoBase((UINT16*)currScreen);
            Super(oldSSP);

            Vsync();
            swapScreens = !swapScreens;
            
        }
        */
        if (GAME_TIMER > 0) {

            if (swapScreens){

                currScreen = base;
                clearGame(currScreen);

            } else {

                currScreen = screen2;
                clearGame(currScreen);
                
            }

            processSyncEvents(&model);

            renderAsteroids(model.asteroids, (UINT8*)currScreen);
            renderRocketship(&model.player, (UINT32*)currScreen);

            oldSSP = Super(0);
            setVideoBase((UINT16*)currScreen);
            Super(oldSSP);

            Vsync();
            swapScreens = !swapScreens;

        }

    }

    oldSSP = Super(0);
    setVideoBase((UINT16*)base);
    Super(oldSSP);

    Vsync();
    stopSound();
    
}

void processAsyncEvents(Model *model) {

    unsigned long input;

    if(hasUserInput()) {

        rocketshipHitBoundary(&model->player);

        input = getUserInput();

        rocketshipMove(&model->player, input);

        if (rocketshipHitFinish(&model->player)) {

            initializeNextRound(&(model->player), model->asteroids, &(model->scorebox), &(model->highscorebox));
        }

        if (input == ESC_KEY) {

            onGameOver(model);

        }

    }

}

void processSyncEvents(Model *model) {

    onAsteroidsMove(model);
    rocketshipAsteroidCollision(model);

}

void gameSetup(Model* model, void *base) {

    disableCursor();

    onGameStart(model);

    clearQuick(base);

    render(model, base);

}

/*long getTime() {

    long* timer = (long*) SYSTEM_CLOCK;
    
    long oldSSP = Super(0);

    long timeNow = *timer;

    Super(oldSSP);

    return timeNow;

}*/
