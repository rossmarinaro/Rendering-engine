
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
                // ++m_animFrame;
                // if ( m_animFrame / 3 >= 4 )
                //     m_animFrame = 0;


            // m_currentFrameX = frs[0][0],
			// m_currentFrameY = frs[0][1],
			// m_currentFrameWidth = frs[0][2],
			// m_currentFrameHeight = frs[0][3];
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
    


    if (inputs -> m_right == true)
    {
        m_posX += 1;    
        Animate("walk");
    }
    if (inputs -> m_left == true)
    {
        m_posX -= 1;
        Animate("walk");
    }
    if (inputs -> m_down == true)
    {
        m_posY += 1; 
        Animate("jump");
    }
    if (inputs -> m_up == true)
    {
        m_posY -= 1;
        Animate("jump"); 
    }

    // _render();

};

//-----------------render image as opengl texture

void Sprite::Render()
{
    if (m_texture != NULL)
    {

        glPixelStorei(GL_UNPACK_ROW_LENGTH, m_texture->w);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, m_currentFrameX);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, m_currentFrameY);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_currentFrameWidth, m_currentFrameHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_texture->pixels);
        
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        
        glBegin(GL_QUADS);

            glTexCoord2f(0, 1); glVertex3f(m_posX, m_posY, 0);
            glTexCoord2f(1, 1); glVertex3f(m_posX + m_srcWidth * m_scale, m_posY, 0);
            glTexCoord2f(1, 0); glVertex3f(m_posX + m_srcWidth * m_scale, m_posY + m_srcHeight * m_scale, 0);
            glTexCoord2f(0, 0); glVertex3f(m_posX, m_posY + m_srcHeight * m_scale, 0); 

        glEnd();
    }

}

Sprite::Sprite(GLuint &id, float x, float y, const char* key[2])
{
    std::vector<int*> frs/* frs */ = Assets::Spritesheets::GenerateFrames(key[0]); 
Log::integer(frs[1][2]);
    m_filepath = key[1];
    m_currentFrameX = frs[1][0];
    m_currentFrameY = frs[1][1];
    m_currentFrameWidth = frs[1][2];
    m_currentFrameHeight = frs[1][3];

    // _init(id, x, y);

        
    Log::write("Sprite instantiated");
};

Sprite::~Sprite()
{
    Log::write("Sprite Destroyed");
};