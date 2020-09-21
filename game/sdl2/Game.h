#ifndef _GAME_H
#define _GAME_H
#pragma once

#include "prefix_code.h"
#include "Vector2D.h"
#include "TextureManager.h"

#include <string>
#include <iostream>
#include <memory>
#include <SDL.h>
#include <limits>

using namespace std;

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

class Game : public enable_shared_from_this<Game>
{
//    friend M_singleton<TextureManager>;
//    using type = M_singleton<TextureManager>::type;
public:
    using type = Game *;

    static type instance()
    {
        if (!_instance)
            _instance = new Game();
        return _instance;
    }

    Game() = default;

    ~Game() = default;

//    void init()
//    { mb_running = true; }

    bool init(const char *title, int xpos, int ypos, int height, int width,
              int flags);

    void render();

    void update(size_t n_sheets = 6);

    void handle_events();

    void clean();

    bool running()
    { return mb_running; }

    void mario_bmp_show();

    void animation_sprite_sheet(const char *file = "assets/char9.bmp");

private:
    //    TextureManager M_texture_mgr;
//    shared_ptr<Vector2D> m_vector2d;
    Vector2D m_vector2d, m_velocity{1, 1}, m_acceleration{0.1, 0.1};
    static type _instance;
    uint32_t M_curr_frame;
    SDL_Texture *mb_texture;
    SDL_Rect mb_src_rectangle;
    SDL_Rect mb_dest_rectangle;
    SDL_Window *mb_window;
    SDL_Renderer *mb_renderer;

    TextureManager &singleton = M_singleton<TextureManager>::M_instance();
    uint32_t M_curr_row = 1;
    bool mb_running = false;
};
/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif //_GAME_H
