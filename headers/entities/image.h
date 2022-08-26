#pragma once

#include "../window.h"
#include "../inputs.h"

	

class Image {

	private:

		
		SDL_Texture* mTexture; 
        SDL_Surface* mAssetMgr;

		GLuint _instance();
		void _setColor(Uint8 red, Uint8 green, Uint8 blue);
		void _setBlendMode( SDL_BlendMode blending );
		void _setAlpha(Uint8 alpha);
	
		int _getWidth() { return mWidth; }
		int _getHeight() { return mHeight; }

    public:

		int mX;
		int mY;
		int mWidth; 
		int mHeight;
		double mDegrees = 0;

		const char* mFilepath;
		SDL_Rect mSrcQuad;
		SDL_Rect mRenderQuad;
		SDL_RendererFlip mFliptype;

		void _init(SDL_Window* &window, int x, int y, int width, int height)
		{
			mAssetMgr = IMG_Load(mFilepath);

			if (mAssetMgr == NULL) 
				Log::error(SDL_GetError()); 

			else 
			{

			//Get image dimensions and render

				mX = x;
				mY = y;	

				_instance();
				_render();
			}
		}

		void _render();
		
		Image(SDL_Rect src_rect = { 0, 0, 0, 0})
		{
			mSrcQuad = src_rect; 
			mFliptype = SDL_FLIP_NONE;

			Log::write("Image created");
		}
       ~Image()
	    {	
			delete mAssetMgr;
			delete mTexture;
			Log::write("Image destroyed");
	   	}
};



