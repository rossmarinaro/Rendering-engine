#include "../../headers/game.h"
#include "../../headers/logs.h"
#include "../../headers/tilemap.h"

#include "../../vendors/nlohmann/json.hpp"
#include "../../vendors/tileson/tileson.hpp" 

using json = nlohmann::json;

MapManager::MapManager(GLuint &textureID, GLuint &textureID2, AssetManager* assets)
{

    for (uint32_t y = 0; y < m_mapHeight; y++)
    {
        for (uint32_t x = 0; x < m_mapWidth; x++)
        {
            char tileType = m_mapTiles[x + y * m_mapWidth]; 

            float posX = x - m_mapWidth / 2.0f,
                  posY = y - m_mapHeight / 2.0f;
                    
            if (m_textureMap.find(tileType) != m_textureMap.end())
                m_textureMap[tileType];

            else 
            {
    
                //std::tuple<int, int> id = {1, 1};
                m_textureMap['T'] = new Entities::TileSprite(textureID, /* id, */ posX, posY, 640, 640, assets->map);
                m_textureMap['X'] = new Entities::TileSprite(textureID2, /* id, */ posX, posY, 0, 0, assets->menu);

                m_tilesprites.push_back(m_textureMap['T']); 
                m_tilesprites.push_back(m_textureMap['X']);
                //Log::write(posX);
  
            }
          
        }
    }

    // tson::Tileson t;
    // std::unique_ptr<tson::Map> map = t.parse("assets/json/preload/maps/cave.json"/* tson_files::_ULTIMATE_TEST_JSON, tson_files::_ULTIMATE_TEST_JSON_SIZE */);

    // if(map->getStatus() == tson::ParseStatus::OK)
    // {
    //     //Get color as an rgba color object
    //     tson::Colori bgColor = map->getBackgroundColor(); //RGBA with 0-255 on each channel

    //     //This color can be compared with Tiled hex string
    //     //if (bgColor == "#ffaa07")
    //         //Log::write(bgColor);

    //     //Or you can compare them with other colors
    //     tson::Colori otherColor{255, 170, 7, 255};
    //     //if (bgColor == otherColor)
    //         //Log::write(otherColor);

    //     //You can also get the color as float, transforming values if they are already in their int form, from max 255 to 1.f
    //     tson::Colorf bgColorFloat = bgColor.asFloat();

    //     //Or the other way around
    //     tson::Colori newBg = bgColorFloat.asInt();

    //     //You can loop through every container of objects
    //     // for (auto &layer : map->getLayers())
    //     // {
    //     //     if (layer.getType() == tson::LayerType::ObjectGroup)
    //     //     {
    //     //         for (auto &obj : layer.getObjects())
    //     //         {
    //     //             //Just iterate through all the objects
    //     //         }
    //     //         //Or use these queries:

    //     //         //Gets the first object it finds with the name specified
    //     //         tson::Object *player = layer.firstObj("player"); //Does not exist in demo map->..

    //     //         //Gets all objects with a matching name
    //     //         std::vector<tson::Object> enemies = layer.getObjectsByName("goomba"); //But we got two of those

    //     //         //Gets all objects of a specific type
    //     //         std::vector<tson::Object> objects = layer.getObjectsByType(tson::ObjectType::Object);

    //     //         //Gets an unique object by its name.
    //     //         tson::Object *uniqueObj = layer.getObj(2);
    //     //     }
    //     // }

    //     //Or get a specific object if you know its name (or id)
    //     tson::Layer *layer = map->getLayer("world");
    //     tson::Tileset *tileset = map->getTileset("platformer"); 
    //     tson::Tile *tile = tileset->getTile(1); //Tileson tile-IDs starts with 1, to be consistent
   
    //     // with IDs in data lists. This is in other words the
    //     //first tile.
    //     //For tile layers, you can get the tiles presented as a 2D map by calling getTileData()
    //     //Using x and y positions in tile units.

    //     if(layer->getType() == tson::LayerType::TileLayer)
    //     {
    //         //When the map is of a fixed size, you can get the tiles like this
    //         if(!map->isInfinite())
    //         {
    //             std::map<std::tuple<int, int>, tson::Tile *> tileData = layer->getTileData();

    //             //Unsafe way to get a tile
    //             tson::Tile *invalidTile = tileData[{0, 4}]; // x:0,  y:4  - There is no tile here, so this will be nullptr.
    //                                                                // Be careful with this, as it expands the map with an ID of {0,4} pointing
    //                                                                // to a nullptr...

    //             //Individual tiles should be retrieved by calling the safe version:
    //             tson::Tile *safeInvalid = layer->getTileData(0, 5); //Another non-existent tile, but with safety check.
    //                                                                      //Will not expand the map with a nullptr

    //             tson::Tile *tile1 = layer->getTileData(4, 4);       //x:4,  y:4  - Points to tile with ID 1 (Tiled internal ID: 0)
    //             tson::Tile *tile2 = layer->getTileData(5, 4);       //x:5,  y:4  - Points to tile with ID 3 (Tiled internal ID: 2)
    //             tson::Tile *tile3 = layer->getTileData(8, 14);      //x:8,  y:14 - Points to tile with ID 2 (Tiled internal ID: 1)
    //             tson::Tile *tile4 = layer->getTileData(17, 5);      //x:17, y:5  - Points to tile with ID 5 (Tiled internal ID: 4)

    //             //New in v1.2.0
    //             //You can now get tiles with positions and drawing rect via tson::TileObject
    //             //Drawing rects are also accessible through tson::Tile.
    //             tson::TileObject *tileobj1 = layer->getTileObject(4, 4);
    //             tson::Vector2f position = tileobj1->getPosition();
    //             tson::Rect drawingRect = tileobj1->getDrawingRect();

    //         //x: -1 = screen left
    //         //y: 0 = top;
            
          
    //     //You can of course also loop through every tile!

    //             int x = 0, 
    //                 y = 0;

    //             for (const auto &[id, tile] : tileData)
    //             {   
    //                 //Must check for nullptr, due to how we got the first invalid tile (pos: 0, 4)
    //                 //Would be unnecessary otherwise.

    //                 if(tile != nullptr)
    //                 {
    //                     //int tileId = tile->getId(); //A bit verbose, as this is the same as id from the key, but you get the idea.

    //                     if (x < 11) x++; 
    //                     if (y < 11) y++;
    //                     if (x > 11 && y > 11)
    //                         return;

    //                     // tson::Vector2f pos = tile->getPosition({x, y}); 
    //                     // float posX = -pos.x / 1000,//-pos.x / 1000 - m_mapWidth / 2.0f, 
    //                     //       posY = -pos.y / 1000;//-pos.y / 1000 - m_mapHeight / 2.0f;

    //                     // if (pos.x == 64)
    //                     //     posX = -1;
    //                     // if (pos.x == 128)
    //                     //     posX = -0.36;

    //                     // if (pos.y == 64)
    //                     //     posX = -1;
    //                     // if (pos.y == 128)
    //                     //     posX = -0.36;

    //                     // char tileType = m_mapTiles[x + y * m_mapWidth];

    //                     // if (m_textureMap.find(tileType) != m_textureMap.end())
    //                     //     m_textureMap[tileType];

    //                     // else 
    //                     // {
    //                     //     m_textureMap['1'] = new Entities::TileSprite(textureID, id, posX, posY, assets->map);
    //                     //     m_tilesprites.push_back(m_textureMap['1']);
    //                     //       Log::write(posX); 
    //                     //       Log::write(posX);
    //                     // }
    //                 }
           
    //             }
    //         }
    //     }

    //     ////If an object supports properties, you can easily get a property value by calling get<T>() or the property itself with getProp()
    //     // int myInt = layer->get<int>("my_int");
    //     // float myFloat = layer->get<float>("my_float");
    //     // bool myBool = layer->get<bool>("my_bool");
    //     // std::string myString = layer->get<std::string>("my_string");
    //     // tson::Colori myColor = layer->get<tson::Colori>("my_color");

    //      fs::path file = layer->get<fs::path>("path to file"); 

    //     // tson::Property *prop = layer->getProp("my_property");
    // }
    // else //Error occured
    //    Log::write(map->getStatusMessage());
}