#include "../headers/window.h"


    Window::Window()
	{
		////Initialize SDL

		if(SDL_Init( SDL_INIT_EVERYTHING) < 0) 
			Log::error(SDL_GetError());
		else
		{
			Log::write("window initialized");
		    // depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL is recommended!)

            // Decide GL+GLSL versions
            #if defined(IMGUI_IMPL_OPENGL_ES2)
                // GL ES 2.0 + GLSL 100
                const char* glsl_version = "#version 100";
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
            #elif defined(__APPLE__)
                // GL 3.2 Core + GLSL 150
                const char* glsl_version = "#version 150";
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
            #else
                // GL 3.0 + GLSL 130
                const char* glsl_version = "#version 130";
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
                SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
            #endif  

			//-------- Init GUI

			mGui = new Gui();
               
		 	mGui->Launch(glsl_version, mEvent);
				
		}
	};


	Window::~Window()
	{ 
        IMG_Quit();
        SDL_Quit();
        SDL_FreeSurface( mScreenSurface );

    // Cleanup
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

		SDL_GL_DeleteContext(mContext);

        delete mScreenSurface;
        delete mWindow; 
        delete mContext;   	
        delete mGui;

		Log::write("window closed");
	};


   