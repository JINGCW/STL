#include "Core.h"

bool Core::quit_game = false;

Core::Core() {
    quit_game = false;
    l_fps_time = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    window = SDL_CreateWindow("author: qiming.xie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800, 640, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window)
        quit_game = true;

    rR = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // ----- ICO
    string icon_filename = "files/images/ico.bmp";
    SDL_Surface *icon_surface = SDL_LoadBMP(icon_filename.c_str());
    SDL_SetColorKey(icon_surface, SDL_TRUE, SDL_MapRGB(icon_surface->format, 255, 0, 255));
    SDL_SetWindowIcon(window, icon_surface);
    SDL_FreeSurface(icon_surface);

    main_event = new SDL_Event();
    // ----- ICO
    otext = new Text();
    otext->setFont(rR, "font");

    omusic = new Music();
    omusic->PlayMusic(Music::mOVERWORLD);

    oSMBLOGO = new IMG("super_mario_bros", rR);
}

Core::~Core() {
    delete main_event;
    delete otext;
    SDL_DestroyRenderer(rR);
    SDL_DestroyWindow(window);
}

void Core::main_loop() {
    cout << quit_game << endl;
    l_fps_time = SDL_GetTicks();

    while (!quit_game && main_event->type != SDL_QUIT) {
        frame_time = SDL_GetTicks();
        SDL_PollEvent(main_event);
        SDL_RenderClear(rR);

        SDL_RenderFillRect(rR, NULL);
        oSMBLOGO->Draw(rR, 0,0);
//        Draw();

        SDL_RenderPresent(rR);
        if ((SDL_GetTicks() - frame_time) < min_frame_time)
            SDL_Delay(min_frame_time - (SDL_GetTicks() - frame_time));
    }
}

void Core::Draw() {
    auto img = new IMG("bowser0", rR);
    img->Draw(rR, 0, 0);
//    o_text->Draw(rR, "WORLD , ./ < >", 100, 100,16);
    otext->DrawWS(rR, "WORLD , ./ < >", 200, 200, 0, 0, 0);
}
