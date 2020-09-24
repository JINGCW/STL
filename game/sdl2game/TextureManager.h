#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H
#pragma once

#include "prefix_code.h"
#include <string>
#include <map>
#include <type_traits>
#include <SDL.h>
#include <iostream>

using namespace std;

class TextureManager {
    using type = TextureManager;
public:
    static type &instance();

    ~TextureManager() = default;

    TextureManager(type const &) = delete;

    void operator=(type const &) = delete;

    bool load(const string &file, const string &texture_id, SDL_Renderer *renderer);

    void draw(const string &texture_id, int xpos, int ypos, uint16_t height, uint16_t width,
              SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void draw_frame(const string &texture_id, int xpos, int ypos, uint16_t height, uint16_t width,
                    uint16_t curr_row, uint16_t curr_frame,
                    SDL_Renderer *renderer, uint16_t offset = 70, SDL_RendererFlip flip = SDL_FLIP_NONE);


private:
    TextureManager() = default;

    map<string, SDL_Texture *> texture_map;
};

template<typename Type>
struct M_singleton {
    static Type &instance() {
        static Type _instance;
        return _instance;
    }

    using type = decltype(instance());
};


#endif //_TEXTUREMANAGER_H
