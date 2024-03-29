#pragma once


#include "./renderer.h"
#include "./inputs.h"
#include "./logs.h"
#include "./game.h"

#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_sdl.h"
#include "../vendors/imgui/imgui_impl_opengl3.h"




void InitializeWindow(Inputs* inputs);
