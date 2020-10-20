#pragma once

#ifndef STANDARD_TEMPLATE_LIBRARIES_CFG_H
#define STANDARD_TEMPLATE_LIBRARIES_CFG_H
#include "Text.h"
#include "Music.h"
#include "IMG.h"

class CFG {
    static Text *obj_text;
    static Music *obj_music;
    static IMG *obj_SMBLOGO;
public:
    CFG();

    ~CFG();

    static int GAME_WIDTH, GAME_HEIGHT;
    static bool keySpace;
    static int keyIDA, keyIDS, keyIDD, keyIDSpace, keyIDShift;

    static string
    getKeyString(int keyID);

    static IMG *
    getSMBLOGO();

    static Text *getText();

    static Music *getMusic();

    static bool can_move_backward;
};


#endif //STANDARD_TEMPLATE_LIBRARIES_CFG_H
