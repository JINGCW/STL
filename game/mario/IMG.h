#ifndef _IMG_H
#define _IMG_H
#pragma once

#include "header.h"


class IMG {
    SDL_Texture *tIMG;
    SDL_Rect rRect;
public:
    IMG(){};

    IMG(string file_name, SDL_Renderer *rR);

    ~IMG() { SDL_DestroyTexture(tIMG); };

    void Draw(SDL_Renderer *rR, int iXOffset, int iYOffset);

    void Draw(SDL_Renderer *rR, int iXOffset, int iYOffset, bool bRotate);

    void DrawVert(SDL_Renderer *rR, int iXOffset, int iYOffset);

    void Draw(SDL_Renderer *rR, SDL_Rect rCrop, SDL_Rect rRect);

    /* ----- get & set ----- */
    SDL_Texture *getIMG();

    void setIMG(string file_name, SDL_Renderer *rR);

    SDL_Rect getRect();
};


#endif //IMG_H
