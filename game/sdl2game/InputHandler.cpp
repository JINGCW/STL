#include "InputHandler.h"
#include "Game.h"

InputHandler *InputHandler::_instance = nullptr;

uint32_t InputHandler::get_y(uint8_t joystick_id, uint8_t stick) const {
    if (m_joystick_axis_movement->empty())
        return 0;
    if (stick == 1)
        return m_joystick_axis_movement->at(joystick_id).first->get_y();
    if (stick == 2)
        return m_joystick_axis_movement->at(joystick_id).second->get_y();
    return 0;
}

/*1 for left stick and 2 for right stick*/
uint32_t InputHandler::get_x(uint8_t joystick_id, uint8_t stick) const {
    if (m_joystick_axis_movement->empty())
        return 0;
    if (stick == 1)
        return m_joystick_axis_movement->at(joystick_id).first->get_x();
    if (stick == 2)
        return m_joystick_axis_movement->at(joystick_id).second->get_x();
    return 0;
}

void InputHandler::update() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            MGame::instance()->clean();
    }
}


void InputHandler::init_joysticks() {
    if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    auto _num_joysticks = SDL_NumJoysticks();
    if (_num_joysticks > 0) {
        for (auto i = 0; i < _num_joysticks; i++)
//        {
//            auto joy = SDL_JoystickOpen(i);
//            m_joysticks.push_back(shared_ptr<*joy>);
//        }{
        {
            m_joysticks->push_back(SDL_JoystickOpen(i));\
            m_joystick_axis_movement->push_back(make_pair(
                    new Vector2D(0, 0), new Vector2D(0, 0)));
        }

        SDL_JoystickEventState(SDL_ENABLE);
        m_input_handler_init = true;
        cout << "Initialized " << m_joysticks->size() << " joystick(s).";
    }
    cout << "No joystick was initialized..." << endl;
}
