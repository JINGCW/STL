#include "Level.h"

MCC_begin
    vector<Tileset *>* Level::get_tilesets()
    {
        return &o_tilesets;
    }

    vector<Layer *> *Level::get_layers()
    {
        return &o_layers;
    }

    void Level::render()
    {
        for (const auto &m:o_layers)
            m->render();
    }

    void Level::update()
    {
        for (const auto &m:o_layers)
            m->update();
    }
MCC_end
