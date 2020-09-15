#ifndef _GAME_H
#define _GAME_H
#pragma once

#include <SDL.h>
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

class Game
{
public:
    Game() = default;

    ~Game()
    {};

//    void init()
//    { mb_running = true; }

    bool init(const char *title, int xpos, int ypos, int height, int width,
            int flags);

    void render();

    void update()
    {};

    void handle_events();

    void clean();

    bool running()
    { return mb_running; }

private:
    SDL_Texture *mb_texture;
    SDL_Rect mb_src_rectangle;
    SDL_Rect mb_dest_rectangle;
    SDL_Window *mb_window;
    SDL_Renderer *mb_renderer;
    bool mb_running = false;
};
/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif //_GAME_H
