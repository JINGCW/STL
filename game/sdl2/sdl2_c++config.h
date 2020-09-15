#ifndef _SDL2_C_CONFIG_H
#define _SDL2_C_CONFIG_H
#pragma once

#include <string>
#include <xstddef>
#include <SDL.h>

using namespace std;

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

static bool gp_running = false;//this will create a loop
static SDL_Window *gp_window = nullptr;
static SDL_Renderer *gp_renderer = nullptr;

bool init(const char *title, int xpos, int ypos, int height, int width, int flags)
{
    //initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
    {
        //succeeded create window
        gp_window = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
        if (gp_window != 0)
            gp_renderer = SDL_CreateRenderer(gp_window, -1, 0);
    } else
        return false;

    return true;
}

void render(int _delay = 500)
{
    //set to black
    SDL_SetRenderDrawColor(gp_renderer, 0, 0, 0, 255);
    //clear the window to black
    SDL_RenderClear(gp_renderer);
    //show the window
    SDL_RenderPresent(gp_renderer);
    //set a delay before quitting
    if (_delay != 0)
        SDL_Delay(_delay);
}

void update()
{

}

void handle_events()
{

}

void clean()
{

}

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif //_SDL2_C_CONFIG_H
