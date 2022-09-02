#pragma once

#include "./image.h"

using json = nlohmann::json;

class Sprite : public Image {

    private:

		int m_frames,
			m_currentFrame;

		std::int64_t 
			m_currentFrameX,
			m_currentFrameY,
			m_currentFrameWidth,
			m_currentFrameHeight;

		json m_resourceData;

	public:  

		float m_scaleX = 0.425f,
			  m_scaleY = 0.85f;

		void Render();
		void Update(Inputs* inputs);
		void Animate(std::string animKey);
		
		Sprite(GLuint &id, float x, float y, const char* key[2]);
	   ~Sprite();
       
};




