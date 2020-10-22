#ifndef _GAME_STATE_H
#define _GAME_STATE_H
#pragma once

#include "prefix_code.h"


class Game_state
{
public:
    virtual void update() = 0;

    virtual void render() = 0;

    virtual bool on_enter() = 0;

    virtual bool on_exit() = 0;

    virtual string get_state_ID() const = 0;
};


#endif //_GAME_STATE_H
