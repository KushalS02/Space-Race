/*
Authours: Alexander Pham and Kushal Saini

Course: COMP 2659 - 001 

File name: tstRend.c

Instructor: Paul Pospisil

*/
#include <osbind.h>
#include "render.h"

int main() {
    
    Model model;
    void *base = Physbase();

    onGameStart(&model);
    clearScreen(base);
    render(&model, base);

    return 0;

}