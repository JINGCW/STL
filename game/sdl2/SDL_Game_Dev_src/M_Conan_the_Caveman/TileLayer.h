#pragma once
#ifndef STANDARD_TEMPLATE_LIBRARIES_TILELAYER_H
#define STANDARD_TEMPLATE_LIBRARIES_TILELAYER_H

#include <vector>
#include "MCC_config.h"
#include "Layer.h"
#include "Level.h"
#include "Vector2D.h"

MCC_begin
    class TileLayer : public Layer
    {
    public:
        TileLayer(MCC_Uint32 tile_size, const vector<Tileset *> &tile_sets);

        virtual void update();

        virtual void render();

        void Set_TileIDs(const vector<vector<MCC_Uint32>> &ids);

        void Set_TileSize(MCC_Uint32 TileSize);

        Tileset *Get_TileSet_By_ID(MCC_Uint32 TileID);

    private:
        MCC_Uint32 num_columns;
        MCC_Uint32 num_rows;
        MCC_Uint32 tile_size;

        Vector2D position;
        Vector2D velocity;

        const vector<Tileset *> &o_tilesets;
        vector<vector<MCC_Uint32>> o_tileIDs;
    };

MCC_end
#endif //STANDARD_TEMPLATE_LIBRARIES_TILELAYER_H
