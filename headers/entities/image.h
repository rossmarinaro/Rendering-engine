#pragma once

#include "../window.h"
#include "../inputs.h"

	

class Image {

	private:

		GLuint m_inst;
		//SDL_Texture* mTexture; 
        SDL_Surface* m_texture;

		void _setColor(Uint8 red, Uint8 green, Uint8 blue);
		void _setBlendMode( SDL_BlendMode blending );
		void _setAlpha(Uint8 alpha);
	
		int _getWidth() { return mWidth; }
		int _getHeight() { return mHeight; }

    public:

		double mDegrees = 0;
		int mX;
		int mY;
		int mWidth; 
		int mHeight;

		int m_renderMode,
			srcWidth = 1, 
            srcHeight = 1;
		float posX = -0.5, 
              posY = -0.5;

		const char* mFilepath;
		SDL_Rect mSrcQuad;
		SDL_Rect mRenderQuad;
		SDL_RendererFlip mFliptype;    

		void _render();
		void _init(GLuint &id, SDL_Window* &window, float x, float y);
		
		Image(SDL_Rect src_rect = { 0, 0, 0, 0})
		{
			mSrcQuad = src_rect; 
			mFliptype = SDL_FLIP_NONE;

			Log::write("Image created");
		}
       ~Image()
	    {	
			//delete mAssetMgr;
			//delete mTexture;
			Log::write("Image destroyed");
	   	}
};



