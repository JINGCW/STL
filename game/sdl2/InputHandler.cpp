#include "InputHandler.h"

InputHandler *InputHandler::_instance = nullptr;

InputHandler *InputHandler::instance()
{
    if (!_instance)
        _instance = new InputHandler();
    return _instance;
}

bool InputHandler::get_mouse_button_state(unsigned int button_index)
{
    return m_mouse_button_states->at(button_index);
}

void InputHandler::update()
{
    this->instance()->handle_event();
}

void InputHandler::clean()
{

}

void InputHandler::handle_event()
{
    SDL_Event event;

//    while (SDL_PollEvent(&event))
    if (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
            Game::instance()->clean();

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
                m_mouse_button_states->at(LEFT) = true;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                m_mouse_button_states->at(MIDDLE) = true;
            if (event.button.button == SDL_BUTTON_RIGHT)
                m_mouse_button_states->at(RIGHT) = true;
        }
        if (event.type == SDL_MOUSEBUTTONUP)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
                m_mouse_button_states->at(LEFT) = false;
            if (event.button.button == SDL_BUTTON_MIDDLE)
                m_mouse_button_states->at(MIDDLE) = false;
            if (event.button.button == SDL_BUTTON_RIGHT)
                m_mouse_button_states->at(RIGHT) = false;
        }
    }
}

InputHandler::InputHandler()
{
    m_mouse_button_states->assign(3, false);
    m_mouse_button_states_tmp->assign(3, 0);
}
