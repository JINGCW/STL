#ifndef _PLAYER0_H
#define _PLAYER0_H
#pragma once

#include "Game.h"


class Player0:public MGame {
public:
    void update(std::size_t n_sheets = 6) override;
};


#endif //_PLAYER0_H
