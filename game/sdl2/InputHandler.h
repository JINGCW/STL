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
        LEFT = 1,
        MIDDLE,
        RIGHT
    };
public:
    static type_ptr _instance;

    InputHandler();

    ~InputHandler() = default;

    static type_ptr instance();

    bool get_mouse_button_state(unsigned);

    void handle_event();

    void update();

    void clean();

private:
    /*use 0,1,2 for mouse left,middle and right*/
    shared_ptr<vector<bool>> m_mouse_button_states;
    shared_ptr<vector<unsigned >> m_mouse_button_states_tmp;
};


#endif //_INPUTHANDLER_H
