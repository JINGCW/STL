#include "LevelParser.h"
#include "TextureManager.h"

MCC_begin
    Level *LevelParser::Parse_Level(const char *File)
    {
        //create a TinyXML document and load the map XML
        TiXmlDocument doc;
        doc.LoadFile(File);
        //create level object
        Level *level = new Level();

        //get the root node
        TiXmlElement *root = doc.RootElement();
        root->Attribute("tilewidth", &tile_size);
        root->Attribute("width", &width);
        root->Attribute("height", &height);

        //parse tilesets
        //parse any object layers
        for (auto e = root->FirstChildElement(); e != NULL;
             e = e->NextSiblingElement())
        {
            if (e->Value() == string("tileset").c_str())
                Parse_TileSets(e, level->get_tilesets());
            if (e->Value() == string("layer").c_str())
                Parse_TileLayer(e, level->get_layers(), level->get_tilesets());
        }

        return level;
    }

    void LevelParser::Parse_TileSets(TiXmlElement *TileSetRoot,
                                     vector<Tileset *> *TileSets)
    {
    //first add the tileset to texture manager
        TextureManager::Instance()->load(
                TileSetRoot->FirstChildElement()->Attribute("source"),
                TileSetRoot->Attribute("name"),
                nullptr//todo SDL_Renderer
        );
        //create a tileset object
        Tileset tileset;
        TileSetRoot->FirstChildElement()->Attribute(
                "width", SDL_static_cast(int*,&tileset.width)
                );
        TileSetRoot->FirstChildElement()->Attribute(
                "height", static_cast<int *>(&tileset.height)
        );
        TileSetRoot->Attribute("firstgrid", &tileset.firstGridID);
        TileSetRoot->Attribute("tilewidth", &tileset.tileWidth);
        TileSetRoot->Attribute("tileheight", &tileset.tileHeight);
        TileSetRoot->Attribute("spacing")
    }
MCC_end
