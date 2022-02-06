/******* MAIN ******/

#include "main.h"
#include "logs/logs.h"



		bool CoinFlip(void)
		{
			srand(time(NULL)); //reset rand
			float randNum = rand() % 10;
			return randNum >= 6 ? true : false;
			//return rand() % 2 == 1 ? true : false;
		}

		Application::Application()
		{

		//// init app

			m_audioMgr = new Audio();
			m_winMgr = new Window(); 
			m_inputMgr = new Inputs();

			background_image = new Sprite(0, 0, 100, 100, m_winMgr, IMAGES_menu);
			sprite = new Sprite(150, 300, 100, 100, m_winMgr, "assets/images/swanky_velvet.png");
	
			Log::write("Application initialized");
													
			Sprite* images[2] = { background_image, sprite };	
			update(images);
			
			
		};

	   Application::~Application()
	   {
		   	delete m_audioMgr;
			delete m_winMgr;
			delete m_inputMgr;
			//delete sInstance
			
			Log::write("Application terminated");
	   };

//----------------------- draw

		void Application::draw(Window* window, Sprite* images[2])
		{
			// SDL_Surface* surface = window -> mScreenSurface;
			// SDL_SetRenderDrawColor(window -> mRenderer, 168, 230, 255, 255);
			// // SDL_RenderClear(window -> mRenderer);
			// //SDL_FillRect(surface, nullptr, SDL_MapRGB(surface -> format, 0, 0, 0));
			// for (int i = 0; i < 2; ++i)
			// {
			//     SDL_RenderCopy(window -> mRenderer, images[i] -> mTexture, &images[i] -> src_rect, &images[i] -> dest_rect);
			// 	SDL_RenderPresent(window -> mRenderer);
			// 	//SDL_BlitSurface(images[i] -> mAssetMgr, nullptr, surface, &images[i] -> mImagePosition  /* or: nullptr */);
			// 	m_winMgr -> updateWindow(images[i] -> mAssetMgr); 
			// }
		}

//----------------------- update

		void Application::update(Sprite* entities[2])
		{
		//Main loop flag
			bool quit = false;  
		//Event handler
			SDL_Event event;
		//While application is running
			while( !quit )
			{			
			//Handle events on queue
				while( SDL_PollEvent( &event ) != 0 )
				{ 

				//User requests quit
					if( event.type == SDL_QUIT ) 
						quit = true;
					else 
						m_inputMgr -> pollInput(event, quit); 
				}
				//move image
					sprite -> update(m_inputMgr);
				//draw to screen
					Application::draw(m_winMgr, entities);
			}
		}


	//-------------------------------------- main


	int main(int argc, char* args[])
	{   
		Log::write(CoinFlip() == true ? "coin flipped true" : "coin flipped false");


		Application* app = new Application();      
		delete app;
		return 0;
		
	}


