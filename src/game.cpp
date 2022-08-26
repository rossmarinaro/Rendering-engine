#include "../headers/assets.h"
#include "../headers/game.h"

//Game* Game::sInstance = NULL;
    Sprite* m_background;
    Sprite* m_sprite;
    SDL_Rect* m_currentClip;


Game::Game(SDL_Window* &window, Inputs* inputs)
{
   //TextureID++;
    // if (sInstance == NULL) 
    //     sInstance = new Game();

    // return sInstance;
    Render(window, inputs);
}

void Game::Render(SDL_Window* &window, Inputs* inputs)
{
    Sprite* background = new Sprite(window, 0, 0, 196, 250, IMAGES_menu);
    Sprite* sprite = new Sprite(window, 0, 0, 196, 250, IMAGES_swanky_velvet);

    SDL_Rect* currentClip = &sprite->mSpriteClips[ sprite->mAnimFrame / 10 ];

    m_background = background;
    m_sprite = sprite;
    m_currentClip = currentClip;
 
}

//-----------------------------------------------------

void Game::Update(Inputs* inputs)
{

    m_sprite->Update(inputs);

    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(scaleX, scaleY, 0);
        glTexCoord2f(1, 0); glVertex3f(scaleX + srcWidth, scaleY, 0);
        glTexCoord2f(1, 1); glVertex3f(scaleX + srcWidth, scaleY + srcHeight, 0);
        glTexCoord2f(0, 1); glVertex3f(scaleX, scaleY + srcHeight, 0);
    glEnd();
}




