#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <chrono>
#include "./audio.h"
#include "./window.h"       

#include "./inputs.h"
#include "./assets.h"
#include "./entities/sprite.h"


/****** Application *****/

class Application 
{

	public:

		static Application* s_instance;
		Window* m_winMgr;
		Audio* m_audioMgr;
		Inputs* m_inputMgr;

		Sprite* background_image; 
		Sprite* sprite; 

	public:		
			
		Application();
	   ~Application();

		void update();

};