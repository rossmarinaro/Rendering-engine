#include "../headers/assets.h"
#include "../headers/game.h"


void Game::Render(SDL_Window* &window)
{
    Sprite* sprite = new Sprite(window, 0, 0, 196, 250, IMAGES_menu);
    //SDL_Rect* currentClip = &sprite->mSpriteClips[ sprite->mAnimFrame / 10 ];

    //sprite->_render( window, renderer, 100, 100, currentClip, NULL, NULL );
    //sprite->Update( /* window, */ inputs);

   //TextureID++;
}

//-----------------------------------------------------

void Game::Update(float x, float y, int w, int h)
{
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(x, y, 0);
        glTexCoord2f(1, 0); glVertex3f(x + w, y, 0);
        glTexCoord2f(1, 1); glVertex3f(x + w, y + h, 0);
        glTexCoord2f(0, 1); glVertex3f(x, y + h, 0);
    glEnd();
}




