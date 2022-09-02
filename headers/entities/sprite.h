#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "../window.h"

#include "../../vendors/nlohmann/json.hpp"

using string = std::string;
using json = nlohmann::json;

namespace Entities {


	class Sprite {

    private:

		int m_frames;

		std::int64_t 
			m_currentFrameX,
			m_currentFrameY,
			m_currentFrameWidth,
			m_currentFrameHeight;

		json m_resourceData;

		GLuint m_inst;

		void _setColor(Uint8 red, Uint8 green, Uint8 blue);
		void _setBlendMode( SDL_BlendMode blending );
		void _setAlpha(Uint8 alpha);

	public:  

		int m_renderMode,
			m_currentFrame;

		float m_posX, 	
              m_posY,
			  m_srcWidth = 1.0, 
			  m_srcHeight = 1.0,
			  m_scaleX = 0.425f,
			  m_scaleY = 0.85f;

		double m_degrees = 0; 

		SDL_Surface* m_texture;
		void Render();

       	Sprite(GLuint &id, float x, float y, const char* key[2]);
	   ~Sprite();
	};


	class Player : public Sprite {

		public:

			void Update(Inputs* inputs);
			void Animate(string animKey);

			Player(GLuint &id, float x, float y, const char* key[2]) : Sprite(id, x, y, key){};
			//~Player();
	};
}