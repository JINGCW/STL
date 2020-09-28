#include "header.h"
#include "Core.h"

int main(int argc, char *argv[]) {
    SDL_SetMainReady();

    auto oCore = new Core();

    oCore->main_loop();

    return 0;
}
