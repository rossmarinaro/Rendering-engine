
#pragma once

#include "./entities/sprite.h"

class MapManager {

    private:


    public:

        Entities::TileSprite* m_ts;
        MapManager(GLuint textures[]);
        ~MapManager() = default;

};