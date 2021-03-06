#ifndef _GAME_H
#define _GAME_H
#pragma once

#include "prefix_code.h"
#include <SDL.h>
//#include <SDL_image.h>
#include <string>
#include <iostream>
#include "TextureManager.h"
#include "Vector2D.h"
#include "InputHandler.h"

using namespace std;

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif
class MGame {
    using type = MGame *;
    using mouse_buttons = enum MouseButtons {
        LEFT = 0, MIDDLE, RIGHT
    };
public:
    static type _instance;

    MGame() = default;

    ~MGame() = default;

    static type instance() {
        if (!_instance)
            _instance = new MGame();
        return _instance;
    }

    bool init(const char *title, int xpos, int ypos, int height, int width, int flags);

    void render(SDL_Event);

    virtual void update(std::size_t n_sheets = 6);

    void handle_events(SDL_Event event);

    void clean();

    bool running() { return m_running; }

    Vector2D get_mouse_position() const;

    void key_board_event_handle();

private:
    void texture_shown();

    void animating_sprite_sheet(const string &file = "assets/char9.bmp", Uint8 n_sheets = 6);

//    TextureManager M_texture_manager;
    Vector2D M_vector2d{500, 500}, m_velocity{0,0}, m_acceleration{0, 0}, m_mouse_position;
    uint16_t M_curr_frame, M_curr_row;
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
