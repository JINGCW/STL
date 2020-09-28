#include "MenuOption.h"

MenuOption::MenuOption(string text, int xpos, int ypos) {
    text = text;
    xpos = xpos;
    ypos = ypos;
}

MenuOption::~MenuOption() {

}

void MenuOption::set_text(string text) {
    text = text;
}

string MenuOption::get_text() {
    return text;
}

int MenuOption::get_xpos() {
    return xpos;
}

int MenuOption::get_ypos() {
    return ypos;
}
