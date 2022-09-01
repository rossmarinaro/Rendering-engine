#pragma once

#include <string>
#include <vector>

namespace Assets {

    namespace Spritesheets {

    
        std::vector<int*> GenerateFrames(std::string key)
        {
            //if (key == "swanky_velvet")
            //{
               
          
                int fr1[4] = { 0, 0, 196, 250 },
                    fr2[4] = { 192, 0, 196, 250 },
                    fr3[4] = { 383, 0, 196, 250 },
                    fr4[4] = { 588, 0, 196, 250 };

                
                return { fr1, fr2, fr3, fr4 };

            //}
         
        }
    }
}

