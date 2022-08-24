#pragma once

#include "./window.h"

//tmp
	// int m_frame = 1;
	// int mAnimFrame = 0; 
	// const int m_WALKING_ANIMATION_FRAMES = 4;  
	// SDL_Rect mSpriteClips[m_WALKING_ANIMATION_FRAMES];  

//GLuint TextureID = 0;
//const char* IMAGES_menu = "assets/images/menu2.png";
//const char* IMAGES_swanky_velvet = "assets/images/swanky_velvet.png";

class Game {

public: 

    static constexpr float scaleX = -0.5, 
                       scaleY = -0.5;

    static constexpr int srcWidth = 1, 
                     srcHeight = 1;


    static void Render(SDL_Window* &window/* GLuint TextureID */);
    static void Update(float x, float y, int w, int h);

};
