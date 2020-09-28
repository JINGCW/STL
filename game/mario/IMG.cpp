#include "IMG.h"

IMG::IMG(string file_name, SDL_Renderer *rR) {
    { setIMG(file_name, rR); }
}

void IMG::Draw(SDL_Renderer *rR, SDL_Rect rCrop, SDL_Rect rRect) {
    SDL_RenderCopy(rR, tIMG, &rCrop, &rRect);
}

void IMG::Draw(SDL_Renderer *rR, int iXOffset, int iYOffset) {
    rRect.x = iXOffset;
    rRect.y = iYOffset;
    SDL_RenderCopy(rR, tIMG, nullptr, &rRect);
}

/*https://zhidao.baidu.com/question/558188103.html*/
void IMG::Draw(SDL_Renderer *rR, int iXOffset, int iYOffset, bool bRotate) {
    rRect.x = iXOffset;
    rRect.y = iYOffset;

    if (!bRotate)
        Draw(rR, iXOffset, iYOffset);
    SDL_RenderCopyEx(rR, tIMG, nullptr, &rRect, 180.0, nullptr, SDL_FLIP_VERTICAL);
}

void IMG::DrawVert(SDL_Renderer *rR, int iXOffset, int iYOffset) {
    rRect.x = iXOffset;
    rRect.y = iYOffset;
    SDL_RenderCopyEx(rR, tIMG, nullptr, &rRect, 180.0, nullptr, SDL_FLIP_HORIZONTAL);
}

/* ******************************************** */

void IMG::setIMG(string file_name, SDL_Renderer *rR) {
    file_name = "files/images/" + file_name + ".bmp";
    auto loaded_surface = SDL_LoadBMP(file_name.c_str());
    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 255, 0, 255));

    tIMG = SDL_CreateTextureFromSurface(rR, loaded_surface);
    rRect.x = rRect.y = 0;
    SDL_QueryTexture(tIMG, nullptr, nullptr, &rRect.w, &rRect.h);
    SDL_FreeSurface(loaded_surface);
}


SDL_Texture *IMG::getIMG() {
    return tIMG;
}

SDL_Rect IMG::getRect() {
    return rRect;
}
