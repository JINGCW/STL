#include "LevelParser.h"

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
MCC_end
