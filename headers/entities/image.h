#pragma once

#include "../window.h"
#include "../inputs.h"

		

class Image {

	private:

		SDL_Texture* mTexture; 
        SDL_Surface* mAssetMgr;
	
    public:

		GLuint TextureID = 0;
	
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

		void _init(SDL_Window* &window, int x, int y, int width, int height)
		{
			mAssetMgr = IMG_Load(mFilepath);

			if (mAssetMgr == NULL) 
				Log::error(SDL_GetError()); 
			else 
			{
				
			//Get image dimensions

				mX = x;
				mY = y;				
				
				mWidth = mAssetMgr->w;
				mHeight = mAssetMgr->h;

				mSrcQuad = { 0, 0, mWidth, mHeight};
	
			//render image as opengl texture
				
				glEnable(GL_TEXTURE_2D);
				glGenTextures(1, &TextureID);
				glBindTexture(GL_TEXTURE_2D, TextureID);
				
				int Mode = GL_RGB;
				
				if(mAssetMgr->format->BytesPerPixel == 4) {
					Mode = GL_RGBA;
				}

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				
				glTexImage2D(GL_TEXTURE_2D, 0, Mode, mAssetMgr->w, mAssetMgr->h, 0, Mode, GL_UNSIGNED_BYTE /* GL_UNSIGNED_SHORT_5_6_5 */, mAssetMgr->pixels);
				
				SDL_FreeSurface(mAssetMgr);

				mRenderQuad = { x, y, mWidth, mHeight };

			//set clip render dimensions
			
				SDL_Rect* clip = nullptr;

				if (clip != NULL)
				{
					mRenderQuad.w = clip->w;
					mRenderQuad.h = clip->h;
				}
			}
		}
};



