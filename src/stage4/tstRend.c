/*
Authours: Alexander Pham and Kushal Saini
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