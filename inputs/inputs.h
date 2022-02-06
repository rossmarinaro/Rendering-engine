#pragma once

#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>

#include "../logs/logs.h"
#include "../audio/audio.h"
#include "../window/window.h"



class Inputs{

    private:

        static int gKeyPressSurfaces[];
        static bool success;
        static Inputs* sInstance;
        Inputs* mInputs;                 

    public:

        bool m_left;
        bool m_right;
        bool m_up;
        bool m_down;

        enum keyPressSurfaces {
            KEY_PRESS_SURFACE_DEFAULT,
            KEY_PRESS_SURFACE_UP,
            KEY_PRESS_SURFACE_DOWN,
            KEY_PRESS_SURFACE_LEFT,
            KEY_PRESS_SURFACE_RIGHT,
            KEY_PRESS_SURFACE_TOTAL
        };
        void pollInput(SDL_Event &event, bool &quit)
        {
            if(event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_1 : Audio::play_sound(Audio::load_audio("sine.wav")); break;
                    case SDLK_2 : new Window(); 
                        /* system("gnome-terminal");
                        system("PAUSE"); */
                    break;
                    case SDLK_LEFT: m_left = true; break;
                    case SDLK_RIGHT: m_right = true; break;
                    case SDLK_UP: m_up = true; break;
                    case SDLK_DOWN: m_down = true; break;
                    case SDLK_3 : quit = true; break; 
                    default: 
                        Log::error(Mix_GetError());
                    break; 
                }
            }
            else{
                m_left = false; 
                m_right = false; 
                m_up = false;
                m_down = false;
            }
        };
  // Inputs() { pollInput(SDL_Event event); };
    ~Inputs();
};
    
//#endif 



