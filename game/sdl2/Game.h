#ifndef _GAME_H
#define _GAME_H
#pragma once

#include "prefix_code.h"
#include "Vector2D.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Game_fsm.h"
#include "MenuState.h"
#include "PlayerState.h"
#include "Music.h"

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
    using GameStates = enum _game_states
    {
        MENU, PLAY, GAMEOVER
    };
    using type = Game *;
    static type _instance;
    using mouse_buttons = enum MouseButtons
    {
        LEFT, MIDDLE, RIGHT
    };

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

    void keyboard_event_handle();

    void jump(SDL_Event &);

    bool is_key_down(SDL_Scancode key);

private:
    Music *m_music;
    const uint8_t *this_m_key_state;
    Game_fsm * m_game_state_machine;
    GameStates m_curr_game_state;
    //    TextureManager M_texture_mgr;
//    shared_ptr<Vector2D> m_vector2d;
    // --- jump
    float start_jump_speed = 7.65f, jump_height, current_jump_height = 0,
            current_jump_speed, gravity = 2.f;
    int jump_state = 0;
    // --- jump
    Vector2D m_vector2d, m_velocity{0, 0}, m_acceleration{0.1, 0.1};
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
