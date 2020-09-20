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
public:
    static type _instance;

    uint32_t get_x(uint8_t joystick_id, uint8_t stick)const;
    uint32_t get_y(uint8_t joystick_id, uint8_t stick)const;

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

    static void update();

    void clean();

private:
    InputHandler() = default;

    ~InputHandler() = default;

    shared_ptr<vector<SDL_Joystick *>> m_joysticks;
    shared_ptr<vector<pair<Vector2D *, Vector2D *>>> m_joystick_axis_movement;
    bool m_input_handler_init = false;
};


#endif //_INPUTHANDLER_H
