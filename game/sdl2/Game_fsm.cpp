#include "Game_fsm.h"

void Game_fsm::update()
{
    if (!m_game_states.empty())
        m_game_states.back()->update();
}

void Game_fsm::render()
{
    if (!m_game_states.empty())
        m_game_states.back()->render();
}

void Game_fsm::change(Game_state *L)
{
    if (!m_game_states.empty())
    {
        if (m_game_states.back()->get_state_ID() == L->get_state_ID())
        {
            return;
        }

        if (m_game_states.back()->on_exit())
        {
            delete m_game_states.back();
            m_game_states.pop_back();
        }
    }
    m_game_states.push_back(L);
    m_game_states.back()->on_enter();
}

void Game_fsm::push(Game_state *L)
{
    m_game_states.push_back(L);
    m_game_states.back()->on_enter();
}

void Game_fsm::pop(Game_state *L)
{
    if (!m_game_states.empty())
    {
        if (m_game_states.back()->on_exit())
        {
            delete m_game_states.back();
            m_game_states.pop_back();
        }
    }
}
