#pragma once

#include "./window.h"

#include "./entities/sprite.h"
#include "./entities/player.h"

//tmp
	// int m_frame = 1;
	// int mAnimFrame = 0; 
	// const int m_WALKING_ANIMATION_FRAMES = 4;  
	// SDL_Rect mSpriteClips[m_WALKING_ANIMATION_FRAMES];  


class Game {
    
public: 

    static Inputs* inputs;

    static void Update(Inputs* inputs);

    Game(Inputs* inputs, GLuint TextureID[]);
   ~Game();

};
