#ifndef _PLAYERSTATE_H
#define _PLAYERSTATE_H
#pragma once

#include "prefix_code.h"
#include "Game_state.h"


class PlayerState : public Game_state
{
public:
    virtual void update() override;

    virtual void render() override;

    bool on_enter() override;

    bool on_exit() override;

    string get_state_ID() const override;

private:
    static const string m_player_ID;
};


#endif //_PLAYERSTATE_H
