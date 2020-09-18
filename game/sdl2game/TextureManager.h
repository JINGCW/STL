#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H
#pragma once

#include <string>
#include <map>
#include <SDL.h>

using namespace std;

class TextureManager {
public:
    TextureManager() = default;

    ~TextureManager() = default;

    bool load(const string &file, const string &texture_id, SDL_Renderer *renderer);

    void draw(const string &texture_id, uint8_t xpos, uint8_t ypos, uint16_t height, uint16_t width,
              SDL_Renderer *renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

    void draw_frame(const string &texture_id, uint8_t xpos, uint8_t ypos, uint16_t height, uint16_t width,
                    uint16_t curr_row, uint16_t curr_frame,
                    SDL_Renderer *renderer, uint16_t offset=70,SDL_RendererFlip flip = SDL_FLIP_NONE);


private:
    map<string, SDL_Texture *> texture_map;
};


#endif //_TEXTUREMANAGER_H
