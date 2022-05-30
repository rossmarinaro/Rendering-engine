#pragma once

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <GL/gl.h> 
//#include <GL/glew.h>
#include <SDL_image.h>

#include "../headers/logs.h"


//tmp

#include <stdio.h>
#include <SDL_opengl.h> 

#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_sdl.h"
#include "../vendors/imgui/imgui_impl_opengl3.h"
//#include "../imgui_impl_sdlrenderer.h"




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
				{
					mScreenSurface = SDL_GetWindowSurface(mWindow);
					mContext = SDL_GL_CreateContext(mWindow);  

					//GLuint VertexArrayID;


				//---------- open gl

					//glGenVertexArrays(1, &VertexArrayID);
					//glBindVertexArray(VertexArrayID);
					//glNewList(1, GL_COMPILE); glBegin(GL_TRIANGLES); glColor3f(1.0, 0.0, 0.0); 



				//---------- IMGui

					IMGUI_CHECKVERSION(); Log::get_size(IMGUI_CHECKVERSION());
					ImGui::CreateContext();
					ImGuiIO& io = ImGui::GetIO(); (void)io;
					io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
					io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

					//Setup Dear ImGui style
					ImGui::StyleColorsDark();
					ImGui::StyleColorsClassic();

					//Setup Platform/Renderer backends
					ImGui_ImplSDL2_InitForOpenGL(mWindow, mContext);
					ImGui_ImplOpenGL3_Init();

				


				}
			}
		};
	   ~Window()
	   { 
		   IMG_Quit();
		   SDL_Quit();
		   SDL_FreeSurface( mScreenSurface );
		   delete mScreenSurface;
		   delete mWindow; 
		   delete mContext;   	

		   Log::write("window closed");
	   };

	   
};




	


