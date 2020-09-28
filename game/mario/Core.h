#ifndef _CORE_H
#define _CORE_H
#pragma once

#include "header.h"
#include "IMG.h"
#include "Text.h"
#include "Music.h"


class Core {
    IMG *oSMBLOGO;
    Music *omusic;
    Text *otext;
    // ---------------
    SDL_Window *window;
    SDL_Renderer *rR;
    SDL_Event *main_event;
    // ----- FPS -----
    static const int min_frame_time = 16;
    long frame_time;
    unsigned long l_fps_time;
public:
    static bool quit_game;

    Core();

    ~Core();

    void main_loop();

    void update();

    void Draw();
};


#endif //_CORE_H
