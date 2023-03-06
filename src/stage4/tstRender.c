#include <osbind.h>
#include "render.h"

int main() {

    void *base = Physbase();
    
    Model model;
    UINT16 *base = (UINT16*) Physbase();
    UINT32 *screen = (UINT32) Physbase();

    onGameStart(&model);
    clearScreen(base);
    render(&model, base);

    return 0;

}