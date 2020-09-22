#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H
#pragma once

#include "prefix_code.h"
#include <SDL.h>
#include <vector>
#include <memory>
#include <iostream>
#include "Vector2D.h"

using namespace std;


class InputHandler {
    using type = InputHandler *;
    using mouse_buttons = enum {
        LEFT =0, MIDDLE, RIGHT
    };
public:
    static type _instance;

    bool get_mouse_button_states(unsigned button_index)const;

    uint32_t get_x(uint8_t joystick_id, uint8_t stick) const;

    uint32_t get_y(uint8_t joystick_id, uint8_t stick) const;

    void init_joysticks();

    bool joysticks_inited() const {
        return m_input_handler_init;
    }

    static type instance() {
//        SDL_JoyAxisEvent;
//        SDL_JOYAXISMOTION;
//        SDL_JoyButtonEvent;
//        SDL_JOYBUTTONDOWN;
        if (!_instance) {
            _instance = new InputHandler();
            return _instance;
        }

        return _instance;
    }

    void update();

    void handle_events(SDL_Event);

    void clean();

private:
    InputHandler();

    ~InputHandler();

//    shared_ptr<vector<bool>> m_mouse_button_states;
    vector<bool> m_mouse_button_states;
    vector<SDL_Joystick *> m_joysticks;
    vector<pair<Vector2D *, Vector2D *>> m_joystick_axis_movement;
    bool m_input_handler_init = false;
};


#endif //_INPUTHANDLER_H
