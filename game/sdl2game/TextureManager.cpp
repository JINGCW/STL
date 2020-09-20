#include "TextureManager.h"

TextureManager &TextureManager::instance() {
    static type _instance;
    return _instance;
}

void TextureManager::
draw_frame(const string &texture_id, uint8_t xpos, uint8_t ypos, uint16_t height, uint16_t width,
           uint16_t curr_row, uint16_t curr_frame, SDL_Renderer *renderer, uint16_t offset,
           SDL_RendererFlip flip) {
    SDL_Rect src_rect, dest_rect;

    src_rect.x = curr_frame * width;
    src_rect.y = (height - offset) * (curr_row - 1);
//    src_rect.y = 130 * (curr_row - 1);
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = xpos;
    dest_rect.y = ypos;

    SDL_RenderCopyEx(renderer, texture_map[texture_id], &src_rect, &dest_rect,
                     0, nullptr, flip);

}

void TextureManager::
draw(const string &texture_id, uint8_t xpos, uint8_t ypos, uint16_t height, uint16_t width,
     SDL_Renderer *renderer, SDL_RendererFlip flip) {
    SDL_Rect src_rect, dest_rect;

    src_rect.x = src_rect.y = 0;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = xpos;
    dest_rect.y = ypos;

    SDL_RenderCopyEx(renderer, texture_map[texture_id], &src_rect, &dest_rect,
                     0, nullptr, flip);
}

bool TextureManager::load(const string &file, const string &texture_id, SDL_Renderer *renderer) {
    auto surface = SDL_LoadBMP(file.c_str());
    if (surface == nullptr)
        return false;

    auto texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture != nullptr) {
        texture_map[texture_id] = texture;
        return true;
    }

    return false;
}
