
#include "../../headers/entities/sprite.h"
#include "../../headers/resources/spritesheets.h"


void Sprite::Animate(std::string animKey)
{
    switch (parseString(animKey))
    {
        case idle:

        break;
        case jump: 
        
        break;
        case walk:

            //Go to next frame 	/ Cycle animation
                ++mAnimFrame;
                if( mAnimFrame / 3 >= m_WALKING_ANIMATION_FRAMES )
                    mAnimFrame = 0;
        break;
    }
};


void Sprite::Update(Inputs* inputs)
{
    // Uint32 ticks = SDL_GetTicks();
    // Uint32 seconds = ticks / 1000;
    // Uint32 spriteFrame = seconds % 3;//4;          
    // mSrcQuad.x = spriteFrame * 196; 
    // if (mSrcQuad.x >= 784)
    // 	mSrcQuad.x = 196;
    


    // if (inputs -> m_right == true)
    // {
    //     posX += 1;    
    //     Animate("walk");
    // }
    // if (inputs -> m_left == true)
    // {
    //     posX -= 1;
    //     Animate("walk");
    // }
    // if (inputs -> m_down == true)
    // {
    //     posY += 1; 
    //     Animate("jump");
    // }
    // if (inputs -> m_up == true)
    // {
    //     posY -= 1;
    //     Animate("jump"); 
    // }

    // _render();

};

//render image as opengl texture

void Sprite::Render()
{

    if (m_texture != NULL)
        glTexImage2D(GL_TEXTURE_2D, 0, m_renderMode, m_texture->w, m_texture->h, 0, m_renderMode, GL_UNSIGNED_BYTE /* GL_UNSIGNED_SHORT_5_6_5 */, m_texture->pixels); 

//full sheet

    glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(m_posX, m_posY, 0);
        glTexCoord2f(1, 1); glVertex3f(m_posX + m_srcWidth, m_posY, 0);
        glTexCoord2f(1, 0); glVertex3f(m_posX + m_srcWidth, m_posY + m_srcHeight, 0);
        glTexCoord2f(0, 0); glVertex3f(m_posX, m_posY + m_srcHeight, 0);
    glEnd();

//full sheet w scale down

    // glBegin(GL_QUADS);

    //     glTexCoord2f(0, 1); glVertex3f(m_posX, m_posY, 0);
    //     glTexCoord2f(1, 1); glVertex3f(m_posX + m_srcWidth * 0.196, m_posY, 0);
    //     glTexCoord2f(1, 0); glVertex3f(m_posX + m_srcWidth * 0.196, m_posY + m_srcHeight * 0.25, 0);
    //     glTexCoord2f(0, 0); glVertex3f(m_posX, m_posY + m_srcHeight * 0.25, 0);

    // glEnd();



//smthing m_frames

    // glBegin(GL_QUADS);

    //     glTexCoord2f(0, 0.1); glVertex3f(m_posX, m_posY, 0);
    //     glTexCoord2f(1, 1); glVertex3f(m_posX + m_srcWidth, m_posY, 0);
    //     glTexCoord2f(0.5, 0); glVertex3f(m_posX + m_srcWidth, m_posY + m_srcHeight, 0);
    //     glTexCoord2f(0, 0); glVertex3f(m_posX, m_posY + m_srcHeight, 0);

    // glEnd();


}

Sprite::Sprite(GLuint &id, float x, float y, const char* key[2])
{

    mFilepath = key[1];

    std::vector<int*> frames = Assets::Spritesheets::GenerateFrames(key[0]);

    _init( id, x, y, frames);

        
    Log::write("Sprite instantiated");
};

Sprite::~Sprite()
{
    Log::write("Sprite Destroyed");
};