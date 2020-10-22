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
        MCC_Uint32 firstGridID;
        MCC_Uint32 tileWidth;
        MCC_Uint32 tileHeight;
        MCC_Uint32 spacing;
        MCC_Uint32 margin;
        MCC_Uint32 width;
        MCC_Uint32 height;
        MCC_Uint32 numColumns;
        string name;
    };

    class Level
    {
    public:
        ~Level();

        void render();

        void update();

        vector<Tileset *> *get_tilesets();

        vector<Layer *> *get_layers();

    private:
        Level();
        friend class LevelParser;

        vector<Tileset *> o_tilesets;
        vector<Layer *> o_layers;
    };

MCC_end
#endif //STANDARD_TEMPLATE_LIBRARIES_LEVEL_H
