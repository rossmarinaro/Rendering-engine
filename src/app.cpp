	#pragma once

	#include "../headers/app.h"
	#include "../headers/entities/sprite.h"

    const char* IMAGES_menu = "assets/images/menu.png";
    const char* IMAGES_swanky_velvet = "assets/images/swanky_velvet.png";


//tmp
	// int m_frame = 1;
	// int mAnimFrame = 0; 
	// const int m_WALKING_ANIMATION_FRAMES = 4;  
	// SDL_Rect mSpriteClips[m_WALKING_ANIMATION_FRAMES];  
	
	
    
    Application::Application()
	{

		bool m_isRunning = true;

	//// init app

		m_audioMgr = new Audio();
		m_inputMgr = new Inputs();
		//m_winMgr = new Window(/* m_running */);

	//new thread for window / gui
	
		std::thread m_window_thread(&Window::Init, m_inputMgr); 
		m_window_thread.join();


	////sprites
	
		//background_image = new Sprite(m_winMgr, 0, 0, 640, 480, IMAGES_menu);
		//sprite = new Sprite(m_winMgr, 0, 0, 196, 250, IMAGES_swanky_velvet);

		Log::write("Application initialized");
												
		//Sprite* images[2] = { background_image, sprite };	

	// 	// SDL_Window* window = m_winMgr->mWindow;
	// 	// SDL_GLContext context = m_winMgr->mContext;

		
	 	update(m_isRunning/* m_winMgr */);    
		
	};

	Application::~Application()
	{
		delete m_audioMgr;
		//delete m_winMgr;
		delete m_inputMgr;
		
		std::terminate();

		Log::write("Application terminated");
	};



//----------------------- update

	void Application::update(bool &isRunning/* Window* &win */)
	{	

		//bool quit = false;  
		//SDL_Event event;

		while( isRunning == true )
		{			
			Log::write("Application updating!");
			// while( SDL_PollEvent( &event ) != 0 ) 
			// {
			// 	if( event.type == SDL_QUIT ) 
			// 		quit = true;
			// 	else 
			// 		{m_inputMgr -> pollInput(event, quit);    Log::write("yooo");}
			// }
			// ////move image  
			// 	SDL_SetRenderDrawColor(m_winMgr->mRenderer, 158, 108, 196, 255); //black
			// 	SDL_RenderClear(m_winMgr->mRenderer);

////Set sprite clips
				SDL_Rect* currentClip = &sprite->mSpriteClips[ sprite->mAnimFrame / 10 ];
				
				//background_image->_render( m_winMgr, background_image->mX, background_image->mY, &background_image->mSrcQuad, NULL, NULL );

				//sprite->_render( m_winMgr, sprite->mX, sprite->mY, currentClip, NULL, NULL );
				//sprite->update( m_winMgr, m_inputMgr);
///Go to next frame
				
			//draw to screen
				//SDL_RenderPresent(m_winMgr->mRenderer); 		

		}
	}