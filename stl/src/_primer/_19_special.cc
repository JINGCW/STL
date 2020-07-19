#include "_19_special.h"

namespace spec_19
{
    Screen &Screen::move(directions dr)
    {
        return (this->*menu[dr])();
    }

//    void screen_menu()
//    {
//        Screen::action_type Screen::menu[]{
//                &Screen::home,
//                &Screen::forward,
//                &Screen::back,
//                &Screen::up,
//                &Screen::down,
//        };
//    }

}