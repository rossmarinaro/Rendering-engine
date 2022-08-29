#pragma once

#include <vector>

#include "../window.h"
#include "../inputs.h"

#include "../../headers/entities/sprite.h"

class Image {

    public:       

		int mX,
			mY,
			m_width,
			m_height,
			m_renderMode,
			m_srcWidth = 1, 
            m_srcHeight = 1;

		float m_posX, 
              m_posY;

		double mDegrees = 0; 

		const char* mFilepath; 
		SDL_Surface* m_texture;
		std::vector<int*> m_frames;

		void _init(GLuint &id, float x, float y, std::vector<int*> frames)
		{
			SDL_Surface* image = IMG_Load(mFilepath);

			if (image == NULL) 
				Log::error(SDL_GetError()); 

			else 
			{ 

			//Get image dimensions and render

				m_posX = x;
				m_posY = y;	

				m_texture = image;
				m_frames = frames;

			//render image as opengl texture
			
				glBindTexture(GL_TEXTURE_2D, id);
				
				m_renderMode = GL_RGB;
				
				if (image->format->BytesPerPixel == 4) 
				{ 
					m_renderMode = GL_RGBA; 
					Log::write("rgba enabled"); 
				}

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        		

			}
		}

		~Image()
		{
			SDL_FreeSurface(m_texture);
		}

	private:

		GLuint m_inst;

		void _setColor(Uint8 red, Uint8 green, Uint8 blue);
		void _setBlendMode( SDL_BlendMode blending );
		void _setAlpha(Uint8 alpha);
	
		int _getWidth() { return m_width; }
		int _getHeight() { return m_height; }
};



