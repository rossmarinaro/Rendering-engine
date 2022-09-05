
#pragma once

#include "./entity.h"
#include "./game.h"

class MapManager {

    private:

        int m_tileWidth = 64,
            m_tileHeight = 64,
            m_mapWidth = 10, 
            m_mapHeight = 10;

    public:

        std::vector<Entities::TileSprite*> m_tilesprites;
        
        MapManager(GLuint &textureID, AssetManager* assets);
        ~MapManager() = default;

};

