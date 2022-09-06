#include <windows.h>
#include <string>
#include <SDL.h>   
#include <stdio.h>
#include <SDL_mixer.h>
#include <SDL_image.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/gl.h> 

#if defined(IMGUI_IMPL_OPENGL_ES2)   
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif
