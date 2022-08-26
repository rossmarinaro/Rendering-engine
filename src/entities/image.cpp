

#include "../../headers/entities/sprite.h"

GLuint TextureID = 0;

GLuint _instance()
{
    TextureID++; 

    Log::integer(TextureID);
        
    return TextureID;		

}

void Image::_init(SDL_Window* &window, int x, int y, int width, int height)
{
    mAssetMgr = IMG_Load(mFilepath);

    if (mAssetMgr == NULL) 
        Log::error(SDL_GetError()); 

    else 
    { 

    //Get image dimensions and render

        //posX = x;
        //posY = y;	

        GLuint m_inst = _instance();

//render image as opengl texture
    
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &m_inst);
    glBindTexture(GL_TEXTURE_2D, m_inst);
    
    int Mode = GL_RGB;
    
    if(mAssetMgr->format->BytesPerPixel == 4) {
        Mode = GL_RGBA;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0, Mode, mAssetMgr->w, mAssetMgr->h, 0, Mode, GL_UNSIGNED_BYTE /* GL_UNSIGNED_SHORT_5_6_5 */, mAssetMgr->pixels);

        _render();
    }
}

void Image::_render()
{

    // srcWidth = mAssetMgr->w;
    // srcHeight = mAssetMgr->h;

    // mSrcQuad = { 0, 0, srcWidth, srcHeight};

// //render image as opengl texture
    
//     glEnable(GL_TEXTURE_2D);
//     glGenTextures(1, &m_inst);
//     glBindTexture(GL_TEXTURE_2D, m_inst);
    
//     int Mode = GL_RGB;
    
//     if(mAssetMgr->format->BytesPerPixel == 4) {
//         Mode = GL_RGBA;
//     }

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
//     glTexImage2D(GL_TEXTURE_2D, 0, Mode, mAssetMgr->w, mAssetMgr->h, 0, Mode, GL_UNSIGNED_BYTE /* GL_UNSIGNED_SHORT_5_6_5 */, mAssetMgr->pixels);

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