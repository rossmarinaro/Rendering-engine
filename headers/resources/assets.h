#pragma once

#include <map>

#include "../../vendors/nlohmann/json.hpp"


using string = std::string;
using json = nlohmann::json; 


namespace Assets {

    std::ifstream file("assets/json/preload/main.json");
    json data = json::parse(file);

   

    namespace Images {

        string __menu = data["assets"][0]["menu"]; 
        string __swanky_velvet = data["assets"][1]["swanky_velvet"]; 

        const char* _menu = __menu.c_str();
        const char* _swanky_velvet = __swanky_velvet.c_str();

        const char* menu[2] = {"menu", _menu};
        const char* swanky_velvet[2] = {"swanky_velvet", _swanky_velvet};
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