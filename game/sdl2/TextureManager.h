#ifndef _TEXTUREMANAGER_H
#define _TEXTUREMANAGER_H
#pragma once
/* Set up for C function definitions, even when using C++ */
#include "prefix_code.h"

#include <SDL.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;

//#ifdef __cplusplus
//extern "C" {
//#endif

template<typename T>
struct M_singleton
{
    static T &M_instance()
    {
        static T _t;// Guaranteed to be destroyed.
        // Instantiated on first use.
        return _t;
    }

    using type = T &;
    type value = M_instance();
};

class TextureManager
{
    friend M_singleton<TextureManager>;

public:
    ~TextureManager() = default;

    bool load(const string &file = "default_filepath",
              const string &id = "default_id", SDL_Renderer *renderer = nullptr);

    void draw(const string &id, uint8_t xpos, uint8_t ypos,
              uint16_t height, uint16_t width, SDL_Renderer *renderer,
              SDL_RendererFlip flip = SDL_FLIP_NONE);

    void draw_frame(const string &id, uint8_t xpos, uint8_t ypos,
                    uint16_t height, uint16_t width, uint32_t curr_row,
                    uint32_t curr_frame, SDL_Renderer *renderer,
                    uint32_t offset = 70,
                    SDL_RendererFlip flip = SDL_FLIP_NONE);

    static TextureManager *M_instance();

private:
    TextureManager() = default;;

    static TextureManager *_instance;

    SDL_Texture *texture{};
    map<string, SDL_Texture *> texture_map;
};

///* Ends C function definitions when using C++ */
//#ifdef __cplusplus
//}
//#endif

#endif //_TEXTUREMANAGER_H
