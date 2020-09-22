#include "Game.h"
//#include <windows.h>

//#undef main

int main(int argc, char **argv) {
//    SDL_SetMainReady();
//    HWND windowHandle = GetConsoleWindow();
//    ShowWindow(windowHandle,SW_SHOW);
    auto *game = new MGame();
    M_Uint32 M_frame_begin, M_frame_interval;
    SDL_Event event;

//    game->init("Chapter 1", 100, 100, 640, 400,
    game->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               1600, 800,
               SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    while (game->running()) {
        SDL_PollEvent(&event);
//        M_frame_begin = SDL_GetTicks();
        frame_delay_begin

        game->handle_events(event);
        game->update();
        game->render(event);

//        M_frame_interval = SDL_GetTicks() - M_frame_begin;
//        if (M_frame_interval < M_delay_time)
//            SDL_Delay(static_cast<M_Uint32>(M_delay_time - M_frame_interval));
        frame_delay_end
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
