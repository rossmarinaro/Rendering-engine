//compile:  mingw32-make.exe

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
//#include <SDL_image.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();


SDL_Window* gWindow = nullptr;

SDL_Surface* gScreenSurface = nullptr;

SDL_Surface* gMitch = nullptr;

////key presses

enum keyPressSurfaces {
	KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
}



bool init()
{

 //init flag
 	bool success = true;
//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
//Create window
	else
	{
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == nullptr )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		//Get window surface
		else gScreenSurface = SDL_GetWindowSurface( gWindow );
	}
	return success;
};
//load img
bool loadMedia()
{
	bool success = true;
//png
	// int imgFlags = IMG_INIT_PNG;
	// if (!(IMG_Init( imgFlags ) & imgFlags ) )
	// {
	// 	printf( "didn't work lol %s err: %s", "mitch.bmp", SDL_GetError() );
	//  	success = false;
	// }
	// else
//bmp
	gMitch = SDL_LoadBMP( "mitch.bmp" );
	if (gMitch == nullptr) 
	{
		printf( "didn't work lol %s err: %s", "mitch.bmp", SDL_GetError() );
		success = false;
	}
	return success;
};
void close()
{
	SDL_FreeSurface( gMitch );
	gMitch = nullptr;
	SDL_DestroyWindow( gWindow );
	gWindow = nullptr;
	SDL_Quit();
};


int main( int argc, char* args[] )
{
	if (!init()) printf("failed to inish lmaoo! \n");
	else{
		if (!loadMedia()) printf("failed to inish lmaoo! \n");
		else{
			//SDL_Delay(5000);
			bool quit = false;
		//event handler
			SDL_Event e;
			while (!quit)
			{
				while( SDL_PollEvent( &e ) != 0)
				{
					if (e.type == SDL_QUIT) quit = true;
				}
				SDL_BlitSurface( gMitch, nullptr, gScreenSurface, nullptr);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return 0;
}