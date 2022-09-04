#pragma once

#include <map>

namespace Assets {


    namespace Images {


        const char* menu[2] = { "menu", "assets/images/menu.png" };
        const char* swanky_velvet[2] = { "swanky_velvet", "assets/images/swanky_velvet.png" };
        const char* map[2] = { "map", "assets/images/platformer.png" };
        const char* brick[2] = { "brick", "assets/images/brick.png" };
        //std::map<const char*, string> asset {{"menu", _menu}};
    }
}

// class AssetManager
// {
//     public:

//         static Assets& get(){
//             static Assets self;
//             return self;
//         } 

//         Assets(Assets const&) = delete;

//         void operator= (Assets const&) = delete;

//         Sprite* getSprite(std::string name)
//         {
//             return m_mapAsset[name];
//         }

//     private: 
//         Assets();
//         ~Assets();

//         std::map<std::string, Sprite*> m_mapAsset;
// };