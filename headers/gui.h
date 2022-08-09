//tmp
#pragma once

#include <stdio.h>
#include <SDL_opengl.h> 

#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_sdl.h"
#include "../vendors/imgui/imgui_impl_opengl3.h"
//#include "../imgui_impl_sdlrenderer.h"

#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <GL/gl.h> 
//#include <GL/glew.h>
#include <SDL_image.h>
#include "./logs.h"
#include "./window.h"

// typedef struct Point {
// 	int x; 
// 	int y;
// } Point;
// //Point p1; Log::get_size(p1.x);






class Gui {

    public:
       // ImGuiIO& io;

        //IMGUI_CHECKVERSION(); Log::get_size(IMGUI_CHECKVERSION());
        //ImGui::CreateContext();
//ImGuiIO& io = ImGui::GetIO(); (void)io;

        Gui(SDL_Window* &win, SDL_GLContext &con);
       ~Gui(){};
     void Launch(SDL_Window* &win, bool &done);

};