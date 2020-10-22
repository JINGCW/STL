#include "TileLayer.h"

MCC_begin
    void TileLayer::Set_TileIDs(const vector<vector<MCC_Uint32>> &ids)
    {
        o_tileIDs = ids;
    }

    void TileLayer::Set_TileSize(MCC_Uint32 TileSize)
    {
        tile_size = TileSize;
    }

    Tileset *TileLayer::Get_TileSet_By_ID(MCC_Uint32 TileID)
    {
        return o_tilesets[TileID];
    }
MCC_end
