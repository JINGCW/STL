#ifndef _FSM_H
#define _FSM_H
#pragma once

#include "prefix_code.h"
#include "Game_state.h"


class Game_fsm
{
public:
    void push(Game_state *L);

    void change(Game_state *L);

    void pop(Game_state *L);

    void update();

    void render();

private:
    vector<Game_state *> m_game_states;
};


#endif //_FSM_H
