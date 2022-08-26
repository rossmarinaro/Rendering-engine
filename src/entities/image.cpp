#include "../../headers/entities/sprite.h"

GLuint TextureID = 0;

GLuint Image::_instance()
{
    TextureID++; 

    Log::integer(TextureID);
        
    return TextureID;		

    //return sInstance;

    //if (sInstance == NULL) 
        //sInstance = new Image();
        
    //return sInstance;
}

void Image::_render()
{
            
    mWidth = mAssetMgr->w;
    mHeight = mAssetMgr->h;

    mSrcQuad = { 0, 0, mWidth, mHeight};

//render image as opengl texture
    
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &TextureID);
    glBindTexture(GL_TEXTURE_2D, TextureID);
    
    int Mode = GL_RGB;
    
    if(mAssetMgr->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, mAssetMgr->w, mAssetMgr->h, 0, Mode, GL_UNSIGNED_BYTE /* GL_UNSIGNED_SHORT_5_6_5 */, mAssetMgr->pixels);
    
    SDL_FreeSurface(mAssetMgr);

    mRenderQuad = { mX, mY, mWidth, mHeight };

//set clip render dimensions

    SDL_Rect* clip = nullptr;

    if (clip != NULL)
    {
        mRenderQuad.w = clip->w;
        mRenderQuad.h = clip->h;
    }
}