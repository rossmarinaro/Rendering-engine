#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "./renderer.h"
#include "./inputs.h"

#include "../vendors/nlohmann/json.hpp" 

using string = std::string;
using json = nlohmann::json;

namespace Entities {


	class Sprite {

		private:

			int m_frames;
			bool m_isSpritesheet = false;

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
				m_scaleX = 1.0,
				m_scaleY = 1.0;

			double m_degrees = 0; 

			SDL_Surface* m_texture;
			void Render();
			void SetScale(float scaleX, float scaleY);

			Sprite(GLuint &id, float x, float y, const char* key[2]);
			~Sprite()
			{
				SDL_FreeSurface(m_texture);
				Log::write("Sprite Destroyed");
			}
	};


	class Player : public Sprite {

		public:

			void Update(Inputs* inputs);
			void Animate(string animKey);

			Player(GLuint &id, float x, float y, const char* key[2]) : Sprite(id, x, y, key){};
			~Player() = default;
	};


	class TileSprite : public Sprite {

		private:

			int type;

			float width = 64, 
				  height = 64;

		public:

			void ShowTile();
			int GetType();
			SDL_Rect GetBox();
			
			TileSprite(GLuint &id, std::tuple<int, int> tileType, float x, float y, const char* key[2]) 
			: Sprite(id, x, y, key)
			{
				//Log::write("X:"); Log::write(x);//this-> SetScale();
			}
			~TileSprite() = default;
	};
}