#ifndef _MENUOPTION_H
#define _MENUOPTION_H
#pragma once

#include "header.h"


class MenuOption {
    string text;
    int xpos, ypos;
public:
    MenuOption(string text, int xpos, int ypos);

    ~MenuOption();

    string get_text();

    void set_text(string text);

    int get_xpos();

    int get_ypos();
};


#endif //_MENUOPTION_H
