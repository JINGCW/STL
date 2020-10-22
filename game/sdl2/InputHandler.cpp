#include "InputHandler.h"

InputHandler *InputHandler::_instance = nullptr;

bool InputHandler::is_key_down(SDL_Scancode key)
{
    if (m_key_state != 0)
    {
        if (m_key_state[key])
            return true;
        return false;
    }

    return true;
}

Vector2D *InputHandler::get_mouse_position()
{
    return m_mouse_position;
}

InputHandler *InputHandler::instance()
{
    if (!_instance)
        _instance = new InputHandler();
    return _instance;
}

bool InputHandler::get_mouse_button_state(unsigned int button_index)
{
    return m_mouse_button_states.at(button_index);
}

void InputHandler::update()
{
//    this->instance()->handle_event();
}

void InputHandler::clean()
{

}

void InputHandler::handle_event(SDL_Event &event)
{
    m_key_state = SDL_GetKeyboardState(0);

//    SDL_Event event;

//    while (SDL_PollEvent(&event))
//    if (SDL_PollEvent(&event))
//    {
//        if (event.type == SDL_QUIT)
//            Game::instance()->clean();
    if (event.type == SDL_MOUSEMOTION)
    {
        m_mouse_position->set_x(event.motion.x);
        m_mouse_position->set_y(event.motion.y);
    }
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
            m_mouse_button_states.at(LEFT) = true;
        if (event.button.button == SDL_BUTTON_MIDDLE)
            m_mouse_button_states.at(MIDDLE) = true;
        if (event.button.button == SDL_BUTTON_RIGHT)
            m_mouse_button_states.at(RIGHT) = true;
    }
    if (event.type == SDL_MOUSEBUTTONUP)
    {
        if (event.button.button == SDL_BUTTON_LEFT)
            m_mouse_button_states.at(LEFT) = false;
        if (event.button.button == SDL_BUTTON_MIDDLE)
            m_mouse_button_states.at(MIDDLE) = false;
        if (event.button.button == SDL_BUTTON_RIGHT)
            m_mouse_button_states.at(RIGHT) = false;
    }
//    }
}

InputHandler::InputHandler()
{
    m_mouse_button_states.assign(3, false);
//    m_mouse_button_states_tmp.assign(3, 0);
}
