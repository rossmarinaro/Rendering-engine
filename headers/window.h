#pragma once

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <GL/glew.h>
#include <GL/gl.h> 
#include "./inputs.h"

#include "./logs.h"
//#include "./gui.h"

#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_sdl.h"
#include "../vendors/imgui/imgui_impl_opengl3.h"

#include <stdio.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)   
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif


class Gui {

    public:
       
    void Launch(const char* glsl_version, Inputs* inputs, SDL_Event event);
    Gui();
   ~Gui(){};

};


class Window {

	private:    
		
	
	public:
			SDL_Surface* mScreenSurface;
			SDL_Window* mWindow; 
			SDL_Renderer* mRenderer;
			SDL_GLContext mContext;
			SDL_Event mEvent;

			Gui* mGui;
		
			static const int SCREEN_WIDTH = 640;
			static const int SCREEN_HEIGHT = 480;      

		//-----------------------------------

			//Deallocate surfaces
			// for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i )
			// {
			// 	SDL_FreeSurface( gKeyPressSurfaces[ i ] );
			// 	gKeyPressSurfaces[ i ] = NULL;
			// }
	
		//----------------------------------

			void updateWindow(SDL_Surface* mAssetMgr)
			{
			////Update the surface
				SDL_UpdateWindowSurface(mWindow);
			}


		Window(Inputs* inputs);
	    ~Window();
};


