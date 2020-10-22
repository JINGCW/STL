#include "MenuState.h"

const string MenuState::m_menu_ID = "MENU";

void MenuState::update()
{

}

void MenuState::render()
{

}

bool MenuState::on_enter()
{
    cout << "enter menu_state..." << endl;
    return true;
}

bool MenuState::on_exit()
{
    cout << "exit menu_state..." << endl;
    return true;
}

string MenuState::get_state_ID() const
{
    return m_menu_ID;
}
