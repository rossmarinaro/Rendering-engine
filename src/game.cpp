#include "../headers/assets.h"
#include "../headers/game.h"


Sprite* m_background;
Sprite* m_sprite;

// SDL_Rect* m_currentClip;

Game::Game(SDL_Window* &window, Inputs* inputs, GLuint textures[])
{
 
    m_background = new Sprite(textures[0], window, -0.5, -0.5, IMAGES_menu);
    m_sprite = new Sprite(textures[1], window, -0.3, -0.3, IMAGES_swanky_velvet);
  //SDL_Rect* currentClip = &sprite->mSpriteClips[ sprite->mAnimFrame / 10 ];

   //m_currentClip = currentClip;

}

//-----------------------------------------------------

void Game::Update(Inputs* inputs)
{

    m_background->_render();//Update(inputs);
    m_sprite->_render();//Update(inputs);

}

Game::~Game()
{
    // if (sprite != NULL)
    //     delete sprite;
    // if (background != NULL)
    //     delete background;
}




