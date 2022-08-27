

#include "../../headers/entities/sprite.h"



void Image::_init(GLuint &id, SDL_Window* &window, float x, float y)
{
    SDL_Surface* image = IMG_Load(mFilepath);

    if (image == NULL) 
        Log::error(SDL_GetError()); 

    else 
    { 
        Log::integer(id);

    //Get image dimensions and render

        posX = x;
        posY = y;	

    //render image as opengl texture
    
        //glActiveTexture(id);
        glBindTexture(GL_TEXTURE_2D, id);
        
        m_renderMode = GL_RGB;
        
        if (image->format->BytesPerPixel == 4) 
            m_renderMode = GL_RGBA;

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
        m_texture = image;

    }
}

void Image::_render()
{

    // srcWidth = mAssetMgr->w;
    // srcHeight = mAssetMgr->h;

    // mSrcQuad = { 0, 0, srcWidth, srcHeight};
    if (m_texture != NULL)
        glTexImage2D(GL_TEXTURE_2D, 0, m_renderMode, m_texture->w, m_texture->h, 0, m_renderMode, GL_UNSIGNED_BYTE /* GL_UNSIGNED_SHORT_5_6_5 */, m_texture->pixels); 

//render image as opengl texture
    
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(posX, posY, 0);
        glTexCoord2f(1, 0); glVertex3f(posX + srcWidth, posY, 0);
        glTexCoord2f(1, 1); glVertex3f(posX + srcWidth, posY + srcHeight, 0);
        glTexCoord2f(0, 1); glVertex3f(posX, posY + srcHeight, 0);
    glEnd();
 
    //SDL_FreeSurface(mAssetMgr);

//     mRenderQuad = { posX, posY, srcWidth, srcHeight };

// //set clip render dimensions

//     SDL_Rect* clip = nullptr;

//     if (clip != NULL)
//     {
//         mRenderQuad.w = clip->w;
//         mRenderQuad.h = clip->h;
//     }
}