#pragma once
#ifndef STANDARD_TEMPLATE_LIBRARIES_LEVELPARSER_H
#define STANDARD_TEMPLATE_LIBRARIES_LEVELPARSER_H

#include <vector>
#include "MCC_config.h"
#include "tinyxml.h"
#include "Level.h"
#include "Layer.h"

MCC_begin
    class LevelParser
    {
    public:
        Level *Parse_Level(const char *File);

    private:
        void Parse_TileSets(TiXmlElement *TileSetRoot, vector<Tileset *> *TileSets);

        void Parse_TileLayer(TiXmlElement *TileElement, vector<Layer *> *Layers,
                             const vector<Tileset *> *TileSets);

        int tile_size;
        int height, width;
    };

MCC_end
#endif //STANDARD_TEMPLATE_LIBRARIES_LEVELPARSER_H
