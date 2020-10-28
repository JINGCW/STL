#pragma once
#ifndef STANDARD_TEMPLATE_LIBRARIES_LEVEL_H
#define STANDARD_TEMPLATE_LIBRARIES_LEVEL_H

#include <vector>
#include "MCC_config.h"
#include "Layer.h"
#include "LevelParser.h"

MCC_begin
    struct Tileset
    {
        MCC_Sint32 firstGridID;
        MCC_Sint32 tileWidth;
        MCC_Sint32 tileHeight;
        MCC_Sint32 spacing;
        MCC_Sint32 margin;
        MCC_Sint32 width;
        MCC_Sint32 height;
        MCC_Sint32 numColumns;
        string name;
    };

    class Level
    {
    public:
        ~Level();

        void render();

        void update();

        vector<Tileset > *get_tilesets();

        vector<Layer *> *get_layers();

    private:
        Level();
        friend class LevelParser;

        vector<Tileset > o_tilesets;
        vector<Layer *> o_layers;
    };

MCC_end
#endif //STANDARD_TEMPLATE_LIBRARIES_LEVEL_H
