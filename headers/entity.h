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

			bool m_isSpritesheet = false;
			bool m_isAtlas = false;

			int m_renderMode;

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
			void _storePixel()
			{
				glPixelStorei(GL_UNPACK_ROW_LENGTH, m_texture->w);
				glPixelStorei(GL_UNPACK_SKIP_PIXELS, m_currentFrameX);
				glPixelStorei(GL_UNPACK_SKIP_ROWS, m_currentFrameY);

				glTexImage2D(GL_TEXTURE_2D, 0, m_renderMode, m_currentFrameWidth, m_currentFrameHeight, 0, m_renderMode, GL_UNSIGNED_BYTE, m_texture->pixels);
				
				glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
				glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
				glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
			};

		public:  

			int m_frames,
				m_currentFrame;

			float m_posX, 	
				m_posY,
				m_srcWidth = 1.0, 
				m_srcHeight = 1.0,
				m_scaleX = 1.0,
				m_scaleY = 1.0,
				m_degrees = 0; 

			SDL_Surface* m_texture;

			void Render();
			void SetScale(float scaleX, float scaleY)
			{
				m_scaleX = scaleX;
				m_scaleY = scaleY;
			}
			void SetRotation(float degrees)
			{
				m_degrees = degrees;
			}

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
				//this->SetScale(0.5f, 0.5f);
			}
			~TileSprite() = default;
	};
}