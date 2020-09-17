#ifndef _GAME_H
#define _GAME_H
#pragma once

#include <SDL.h>
//#include <SDL_image.h>
#include <string>
#include <iostream>
#include "TextureManager.h"

using namespace std;

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif
class MGame {
public:
    MGame() = default;

    ~MGame() = default;

    bool init(const char *title, int xpos, int ypos, int height, int width, int flags);

    void render();

    void update(std::size_t n_sheets=6);

    void handle_events();

    void clean();

    bool running() { return m_running; }

private:
    void texture_shown();

    void animating_sprite_sheet(const string &file="assets/char9.bmp",Uint8 n_sheets=6);

    TextureManager M_texture_manager;
    uint16_t M_curr_frame,M_curr_row;
    SDL_Texture *m_texture;
    SDL_Rect m_src_rect;
    SDL_Rect m_dest_rect;
    SDL_Renderer *m_renderer;
    SDL_Window *m_window;
    bool m_running = false;
};

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif //_GAME_H
