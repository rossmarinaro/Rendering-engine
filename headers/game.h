#pragma once

#include "./window.h"
// #include "./entities/sprite.h"
// #include "./entities/player.h"


class Game {
    
    private:

        static const bool gameState = true;
        const char* currentStage;


    public: 

        static Inputs* inputs;

        static void Update(Inputs* inputs);

        Game(Inputs* inputs, GLuint TextureID[]);
    ~Game();

};
