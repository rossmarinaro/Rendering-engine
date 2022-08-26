#include "../headers/assets.h"
#include "../headers/game.h"


Sprite* m_background;
Sprite* m_sprite;

// SDL_Rect* m_currentClip;


Game::Game(SDL_Window* &window, Inputs* inputs)
{
    Sprite* background = new Sprite(window, 0, 0, 196, 250, IMAGES_menu);
  //  Sprite* sprite = new Sprite(window, 0, 100, 160, 200, IMAGES_swanky_velvet);

  //  SDL_Rect* currentClip = &sprite->mSpriteClips[ sprite->mAnimFrame / 10 ];

    m_background = background;
   // m_sprite = sprite;
   // m_currentClip = currentClip;
}

//-----------------------------------------------------

void Game::Update(Inputs* inputs)
{

    m_background->Update(inputs);
  //  m_sprite->Update(inputs);

}




