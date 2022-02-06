
// #include <SDL_audio.h>
// #include <SDL_mixer.h>

#include "inputs.h"
// #include "../logs/logs.h"
// #include "../window/window.h"
// #include "../audio/audio.h"


// Inputs* Inputs::sInstance = NULL;
// Inputs* Inputs::Instance()
// {
// 	if (sInstance == NULL) new Inputs();
// 	return sInstance;
// }
// Inputs::Inputs()
// {
// 	Inputs* mInputMgr = Inputs::Instance();

// }
// Inputs::~Inputs()
// {

// }


/***** Select surfaces based on key press *****/
//    Inputs::Inputs()//Inputs* Inputs::init()
//    {

// 	// //Main loop flag
// 	// 	bool quit = false;  
// 	// //Event handler
// 	// 	SDL_Event event;
// 	// //While application is running
// 	// 	while( !quit )
// 	// 	{
// 	// 		//Handle events on queue
// 	// 		while( SDL_PollEvent( &event ) != 0 )
// 	// 		{ 
// 	// 		////User requests quit
// 	// 			if( event.type == SDL_QUIT ) 
// 	// 				quit = true;
// 	// 		////User presses a key
// 	// 			else if(event.type == SDL_KEYDOWN)
// 	// 			{
// 	// 				switch (event.key.keysym.sym)
// 	// 				{
// 	// 					case SDLK_1 : Audio::play_sound(Audio::load_audio("sine.wav")); break;
// 	// 					case SDLK_2 : new GUI(); break;
// 	// 					case SDLK_3 : quit = true; break;
// 	// 					default: Log::error(Mix_GetError()); 
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
//    }

	Inputs::~Inputs()
	{

	}



//    void Inputs::inputs()
//    {
	
//        enum keyPressSurfaces {
//             KEY_PRESS_SURFACE_DEFAULT,
//             KEY_PRESS_SURFACE_UP,
//             KEY_PRESS_SURFACE_DOWN,
//             KEY_PRESS_SURFACE_LEFT,
//             KEY_PRESS_SURFACE_RIGHT,
//             KEY_PRESS_SURFACE_TOTAL
//         };
//     //Load default surface
//     		char* input_type;
// 		switch (input_type)
// 		{
// 		  case KEY_PRESS_SURFACE_DEFAULTA//
// 		}
// 		gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] = loadSurface( "04_key_presses/press.bmp" );
// 		if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL )
// 		{
// 			Log::output( "Failed to load default image!\n" );
// 			success = false;
// 		}
// 	////Load up surface
// 		gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] = loadSurface( "04_key_presses/up.bmp" );
// 		if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL )
// 		{
// 			Log::output( "Failed to load up image!\n" );
// 			success = false;
// 		}
// 	////Load down surface
// 		gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] = loadSurface( "04_key_presses/down.bmp" );
// 		if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL )
// 		{
// 			Log::output( "Failed to load down image!\n" );
// 			success = false;
// 		}
// 	////Load left surface
// 		gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] = loadSurface( "04_key_presses/left.bmp" );
// 		if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL )
// 		{
//        			Log::output( "Failed to load left image!\n" );
// 			success = false;
// 		}
// 	////Load right surface
// 		gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] = loadSurface( "04_key_presses/right.bmp" );
// 		if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL )
// 		{
// 			Log::output( "Failed to load right image!\n" );
// 			success = false;
// 		}
//          switch(e.key.keysym.sym)
//         {
//             case SDLK_UP: Window::gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ]; break;
//             case SDLK_DOWN: Window::gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ]; break;
//             case SDLK_LEFT: Window::gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ]; break;
//             case SDLK_RIGHT: Window::gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ]; break;
//             default:  Window::gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ]; break;
//         }
//    }
