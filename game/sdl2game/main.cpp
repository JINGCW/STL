#include "Game.h"

int main(int argc, char **argv) {
    auto *game = new MGame();
    game->init("Chapter 1", 100, 100, 640, 400,
               SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    while (game->running()) {
        game->handle_events();
        game->update();
        game->render();
    }
    game->clean();

    return 0;
}

//#include <SDL.h>
//
//SDL_Window *gp_window = 0;
//SDL_Renderer *gp_renderer = 0;
//
//int main(int argc,char **argv)
//{
//    //initialize SDL
//    if (SDL_Init(SDL_INIT_EVERYTHING)>=0)
//    {
//        //succeeded create window
//        gp_window = SDL_CreateWindow("chapter1: setting up sdl",
//                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//                640,480, SDL_WINDOW_SHOWN
//                );
//        //if window creation succeeded create renderer
//        if (gp_window!=0)
//            gp_renderer = SDL_CreateRenderer(gp_window, -1, 0);
//    } else
//        return 1;//sdl could not initialize
//    //everything succeeded lets draw the window
//    //set to black //this function expects Red, Green, Blud and Alpha as color values
//    SDL_SetRenderDrawColor(gp_renderer, 0, 0, 0, 255);
//    //clear the window to black
//    SDL_RenderClear(gp_renderer);
//    //show the window
//    SDL_RenderPresent(gp_renderer);
//    //set a delay before quitting
//    SDL_Delay(5000);
//
//    //clean up sdl
//    SDL_Quit();
//    return 0;
//}
