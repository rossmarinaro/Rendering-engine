#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "audio/audio.h"
#include "window/window.h"       

#include "inputs/inputs.h"
#include "assets/assets.h"
#include "entity.h"


/****** Application *****/

class Application 
{

	public:

		static Application* sInstance;
		Window* m_winMgr;
		Audio* m_audioMgr;
		Inputs* m_inputMgr;


		Sprite* background_image; 
		Sprite* sprite; 

	public:		
			
		Application();
	   ~Application();

		void draw(Window* window, Sprite* images[2]);
		void update(Sprite* entities[2]);

};