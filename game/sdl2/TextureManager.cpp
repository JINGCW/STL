#include "TextureManager.h"

TextureManager *TextureManager::_instance = nullptr;

TextureManager *TextureManager::M_instance()
{
    if (!_instance)
    {
        _instance = new TextureManager();
        return _instance;
    }
    return _instance;
}

void TextureManager::
draw_frame(const string &id, int xpos, int ypos, uint16_t height,
           uint16_t width, uint32_t curr_row, uint32_t curr_frame,
           SDL_Renderer *renderer, uint32_t offset, SDL_RendererFlip flip)
{
    SDL_Rect src_rect, dest_rect;

    src_rect.x = curr_frame * width;
    src_rect.y = (height - offset) * (curr_row - 1);//default is row 1
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = xpos;
    dest_rect.y = ypos;
#ifdef Game_DEBUG
    cout << "xpos: " << dest_rect.x << "\n"
         << "ypos: " << dest_rect.y << endl;
#endif

    SDL_RenderCopyEx(renderer, texture_map[id], &src_rect, &dest_rect,
                     0, nullptr, flip);
}

void TextureManager::
draw(const string &id, uint8_t xpos, uint8_t ypos,
     uint16_t height, uint16_t width,
     SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect src_rect, dest_rect;

    src_rect.x = src_rect.y = 0;
    dest_rect.x = xpos;
    dest_rect.y = ypos;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    SDL_RenderCopyEx(renderer, texture_map[id], &src_rect, &dest_rect,
                     0, nullptr, flip);
}

bool TextureManager::
load(const string &file, const string &id, SDL_Renderer *renderer)
{
    auto surface = SDL_LoadBMP(file.c_str());
    if (surface == nullptr)
        return false;

    auto _texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (_texture)
    {
        texture_map[id] = _texture;
        return true;
    }

    return false;
}
