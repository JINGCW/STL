#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H
#pragma once

#include <vector>
#include <memory>
#include <SDL.h>

#include "Game.h"

using namespace std;

class InputHandler
{
    using type = InputHandler;
    using type_ptr = InputHandler *;
    using type_ref = InputHandler &;
    using MouseButtons = enum mouse_buttons
    {
        LEFT = 0,
        MIDDLE,
        RIGHT
    };
public:
    static type_ptr _instance;

    InputHandler();

    ~InputHandler() = default;

    static type_ptr instance();

    bool get_mouse_button_state(unsigned);

    void handle_event(SDL_Event &);

    void update();

    void clean();

    Vector2D *get_mouse_position();

    bool is_key_down(SDL_Scancode key);

    //handle keyboard events
    void on_key_down();

    void on_key_up();

    //handle mouse events
    void on_mouse_move(SDL_Event &event);

    void on_mouse_button_down(SDL_Event &event);

    void on_mouse_button_up(SDL_Event &event);

    //handle joysticks events
    void on_joystick_axis_move(SDL_Event &event);

    void on_joystick_axis_button_down(SDL_Event &event);

    void on_joystick_axis_button_up(SDL_Event &event);
private:
    /*use 0,1,2 for mouse left,middle and right*/
    vector<bool> m_mouse_button_states;
    Vector2D *m_mouse_position;//handle mouse motion
//    vector<unsigned > m_mouse_button_states_tmp;
    const uint8_t *m_key_state;
};


#endif //_INPUTHANDLER_H
