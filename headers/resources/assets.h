#pragma once

#include <map>

#include "../../vendors/nlohmann/json.hpp"
#include "../../vendors/tileson/tileson.hpp"

using string = std::string;
using json = nlohmann::json; 


namespace Assets {


    namespace Images {


        const char* menu[2] = { "menu", "assets/images/menu.png" };
        const char* swanky_velvet[2] = { "swanky_velvet", "assets/images/swanky_velvet.png" };
            
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