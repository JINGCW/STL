#include "PlayerState.h"

const string PlayerState::m_player_ID = "PLAY";

string PlayerState::get_state_ID() const
{
    return m_player_ID;
}

bool PlayerState::on_enter()
{
    cout << "enter play_state" << endl;
    return true;
}

bool PlayerState::on_exit()
{
    cout << "exit play_state" << endl;
    return true;
}

void PlayerState::update()
{

}

void PlayerState::render()
{

}

