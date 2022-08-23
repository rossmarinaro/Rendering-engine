#pragma once

#include "../window.h"
#include "../inputs.h"

		

class Image {

	private:

		SDL_Texture* mTexture; 
        SDL_Surface* mAssetMgr;
	
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
	

    public:

		Image(SDL_Rect src_rect = { 0, 0, 0, 0})
		{
			mSrcQuad = src_rect; 
			mFliptype = SDL_FLIP_NONE;
			Log::write("Image created");
		};
       ~Image()
	    {	
			delete mAssetMgr;
			delete mTexture;
			Log::write("Image destroyed");
	   	};
	//// tmp methods
		void _setColor(Uint8 red, Uint8 green, Uint8 blue);
		void _setBlendMode( SDL_BlendMode blending );
		void _setAlpha(Uint8 alpha);
		
		int _getWidth()
		{
   			return mWidth;
		};

		int _getHeight()
		{
			return mHeight;
		};

		void _init(SDL_Window* &window, SDL_Renderer* renderer, int x, int y, int width, int height)
		{
			mAssetMgr = IMG_Load(mFilepath);

			if (mAssetMgr == NULL) 
				Log::error(SDL_GetError()); 
			else 
			{

				//mWidth = width; 
				//mHeight = height;
				mX = x;
				mY = y;				


				//mSrcQuad = { 0, 0, width, height };
				//mTexture = SDL_CreateTextureFromSurface(window->mRenderer, mAssetMgr);
				mTexture = SDL_CreateTextureFromSurface(renderer, mAssetMgr);
				
			//Get image dimensions
				mWidth = mAssetMgr->w;
				mHeight = mAssetMgr->h;

				mSrcQuad = { 0, 0, mWidth, mHeight};

	
			//render image
				//_render( window, (window->SCREEN_WIDTH - this->_getWidth() ) / 2, (window->SCREEN_HEIGHT - this->_getHeight() ) / 2, NULL, mDegrees, NULL, mFliptype);
				_render( window, renderer, 100, 100, NULL, mDegrees, NULL, mFliptype);

			}
		}

		void _render(SDL_Window* &window, SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE)
		{

			mRenderQuad = { x, y, mWidth, mHeight };

		//set clip render dimensions

			if (clip != NULL)
			{
				mRenderQuad.w = clip->w;
				mRenderQuad.h = clip->h;
			}
		//render to screen
		
			//SDL_RenderCopyEx(window->mRenderer, mTexture, clip , &mRenderQuad, angle, center, flip);
			SDL_RenderCopyEx(renderer, mTexture, clip , &mRenderQuad, angle, center, flip);

	
		}

};



