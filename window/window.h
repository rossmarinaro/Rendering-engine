#pragma once

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <GL/gl.h> 
#include <SDL_image.h>


#include "../logs/logs.h"


class Window {

	private:    
			//SDL_Window* mWindow;	
			//SDL_Surface* mScreenSurface;
			//SDL_GLContext mContext;
		
	public:
			SDL_Surface* mScreenSurface;
			SDL_Window* mWindow; 
			SDL_Renderer* mRenderer;
			SDL_GLContext mContext;
			

			static const int SCREEN_WIDTH = 640;
			static const int SCREEN_HEIGHT = 480;      

		//-----------------------------------

			static void close(SDL_Window* window, SDL_GLContext context)
			{
				//Deallocate surfaces
				// for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
				// {
				// 	SDL_FreeSurface( gKeyPressSurfaces[ i ] );
				// 	gKeyPressSurfaces[ i ] = NULL;
				// }
			////Destroy window
				SDL_GL_DeleteContext(context);
				SDL_DestroyWindow(window);
				window = nullptr;
			//Quit SDL subsystems
				IMG_Quit();
				SDL_Quit();
			};

		//----------------------------------

			void updateWindow(SDL_Surface* mAssetMgr)
			{
			////Update the surface
				SDL_UpdateWindowSurface(mWindow);
			}


		Window()
		{
		////Initialize SDL
				if(SDL_Init( SDL_INIT_EVERYTHING) < 0) 
					Log::error(SDL_GetError());
				else
				{
					Log::write("window initialized");
			////set open gl context
					SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
					SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
					SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
					SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
			////Create window
					mWindow = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

			////GPU RENDERING
					mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);     
				
			////Get window surface
					if (mWindow == nullptr) 
						Log::error(SDL_GetError());
					else 
						mScreenSurface = SDL_GetWindowSurface(mWindow); 

			////create context
					mContext = SDL_GL_CreateContext(mWindow);  
					//glNewList(1, GL_COMPILE); glBegin(GL_TRIANGLES); glColor3f(1.0, 0.0, 0.0);
				}
		};
	   ~Window()
	   { 
		   close(mWindow, mContext);
		   SDL_FreeSurface( mScreenSurface );
		   delete mScreenSurface;
		   delete mWindow; 
		   delete mContext;   	

		   Log::write("window closed");
	   };

	   
};




	


