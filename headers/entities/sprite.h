#pragma once

#include "./image.h"

///------------------- Sprite 


class Sprite : public Image {

    private:

	////anims enumerations / parsing

		enum anims {
			jump, 
			walk,
			idle
		};

		anims parseString(std::string const &string)
		{
			if (string == "jump") return jump;
			if (string == "walk") return walk;
			if (string == "idle") return idle;
		}

	public:  

		int m_frame = 1;
		int mAnimFrame = 0; 
		static const int m_WALKING_ANIMATION_FRAMES = 4;  
		SDL_Rect mSpriteClips[m_WALKING_ANIMATION_FRAMES]; 

		void Update(/* Window* &window,  */Inputs* inputs);
		void Animate(std::string animKey);
		Sprite(SDL_Window* &window, int _x, int _y, int _width, int _height, const char* filepath);
	   ~Sprite();
       
};




