#pragma once

#include "./window.h"

//tmp
	// int m_frame = 1;
	// int mAnimFrame = 0; 
	// const int m_WALKING_ANIMATION_FRAMES = 4;  
	// SDL_Rect mSpriteClips[m_WALKING_ANIMATION_FRAMES];  


class Game {

private:

    //static Game* sInstance;

public: 

    static Sprite* background;
    static Sprite* sprite;
    static SDL_Rect* currentClip;
    static Inputs* inputs;

    static constexpr float posX = -0.5, 
                           posY = -0.5;

    static constexpr int srcWidth = 1, 
                         srcHeight = 1;

    static void Update(Inputs* inputs);

    Game(SDL_Window* &window, Inputs* inputs, GLuint TextureID[]);
   ~Game();

};
