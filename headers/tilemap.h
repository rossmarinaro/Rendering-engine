
#pragma once

#include "./entity.h"
#include "./game.h"

class MapManager {

    private:


    public:

        Entities::TileSprite* m_ts;
        MapManager(GLuint &textureID, AssetManager* assets);
        ~MapManager() = default;

};

