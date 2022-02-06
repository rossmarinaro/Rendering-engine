#include "window/window.h"
//#include "inputs/inputs.h"

class Asset {

    public://protected://private:

        SDL_Surface* mAssetMgr;
		SDL_Texture* mTexture;
        SDL_Rect mImagePosition = {
            .x = 0,
            .y = 0,
            .w = 75,
            .h = 76
        };
		// SDL_Rect src_rect = { 0, 0, 144, 250 };
		// SDL_Rect dest_rect = { 10, 10, 144, 250 };
		SDL_Rect src_rect[4];
		SDL_Rect dest_rect[4];
    public:

        void _init(Window* &window, int _width, int _height, const char* filepath)
        {
            mAssetMgr = IMG_Load(filepath);
            if (mAssetMgr == NULL) 
                Log::error(SDL_GetError()); 
            else 
			{
				SDL_Rect src_rect = { 0, 0, 144, 250 };
				SDL_Rect dest_rect = { 10, 10, 144, 250 };
				Log::write("asset created");
				mTexture = SDL_CreateTextureFromSurface(window -> mRenderer, mAssetMgr);
				SDL_RenderCopy(window -> mRenderer, mTexture, &src_rect, &src_rect);
				SDL_RenderPresent(window -> mRenderer);
				//SDL_BlitSurface(mAssetMgr, nullptr, window -> mScreenSurface, &mImagePosition  /* or: nullptr */);
			}
        };
	   
       ~Asset()
       {
            delete mAssetMgr;
			delete mTexture;

            Log::write("asset destroyed");
       };
};



////------------------- Sprite 


class Sprite : public Asset {

    private:
		unsigned int m_frame = 1;

	public:  

		void update(Inputs* inputs)
		{
			if (inputs -> m_right == true)
				mImagePosition.x += 1;
			if (inputs -> m_left == true)
				mImagePosition.x -= 1;
			if (inputs -> m_down == true)
				mImagePosition.y += 1;
			if (inputs -> m_up == true)
				mImagePosition.y -= 1;

			std::string rawPath = "assets/images/" + std::to_string(m_frame++) + ".png";
			if (m_frame >= 4)
				m_frame = 1;
			const char* filepath = rawPath.c_str();

			//if moving
				//mTexture = IMG_Load(filepath);
				
		};

		Sprite(int _x, int _y, int _width, int _height, Window* &window, const char* filepath) 
		{ 
			_init(window, _width, _height, filepath); 

			mImagePosition.x = _x;
			mImagePosition.y = _y;
			
			Log::write("Sprite instantiated");
		};
	   ~Sprite()
	   {
		   	delete mAssetMgr;
            Log::write("asset destroyed");
	   };
       
};