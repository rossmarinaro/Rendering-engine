
#pragma once

#include "./entity.h"
#include "./game.h"

class MapManager {

    private:

        const char* m_mapTiles = {
            "T T X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            "X X X X X X X X X X"
            //"1, 1, 1, 1, 1, 1, 1, 1, 1, 1"
            "X X X X X X X X X X"
        };

        const uint32_t m_mapWidth = 10,
                       m_mapHeight = 10;//strlen(m_mapTiles) / m_mapWidth;


    public:

        std::vector<Entities::TileSprite*> m_tilesprites;
        std::unordered_map<char, Entities::TileSprite*> m_textureMap;

        MapManager(GLuint &textureID, GLuint &textureID2, AssetManager* assets);
        ~MapManager() = default;

};

