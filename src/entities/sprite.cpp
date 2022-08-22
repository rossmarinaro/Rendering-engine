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


    void Sprite::Update(Window* &window, Inputs* inputs)
    {
        // Uint32 ticks = SDL_GetTicks();
        // Uint32 seconds = ticks / 1000;
        // Uint32 spriteFrame = seconds % 3;//4;          
        // mSrcQuad.x = spriteFrame * 196; 
        // if (mSrcQuad.x >= 784)
        // 	mSrcQuad.x = 196;
        


        if (inputs -> m_right == true)
        {
            mX += 1;    
            animate("walk");
        }
        if (inputs -> m_left == true)
        {
            mX -= 1;
            animate("walk");
        }
        if (inputs -> m_down == true)
        {
            mY += 1; 
            animate("jump");
        }
        if (inputs -> m_up == true)
        {
            mY -= 1;
            animate("jump"); 
        }
    


    };

    Sprite::Sprite(Window* &window, int _x, int _y, int _width, int _height, const char* filepath)
    {

        mFilepath = filepath;
        mSrcQuad.x = _x;
        mSrcQuad.y = _y;
        
    
        _init( window, _x, _y, _width, _height);


        if (filepath != "assets/images/menu.png")
        {
            mSpriteClips[ 0 ].x =   0;
            mSpriteClips[ 0 ].y =   0;
            mSpriteClips[ 0 ].w =  196;
            mSpriteClips[ 0 ].h = 250;

            mSpriteClips[ 1 ].x =  192;
            mSpriteClips[ 1 ].y =   0;
            mSpriteClips[ 1 ].w =  196;
            mSpriteClips[ 1 ].h = 250;
            
            mSpriteClips[ 2 ].x = 384;
            mSpriteClips[ 2 ].y =   0;
            mSpriteClips[ 2 ].w =  196;
            mSpriteClips[ 2 ].h = 250;

            mSpriteClips[ 3 ].x = 588;
            mSpriteClips[ 3 ].y =   0;
            mSpriteClips[ 3 ].w =  196;
            mSpriteClips[ 3 ].h = 250;
        }
        else 
        {
            mSpriteClips[ 1 ].x = 0;
            mSpriteClips[ 1 ].y =   0;
            mSpriteClips[ 1 ].w =  640;
            mSpriteClips[ 1 ].h = 480;
        }
            
        Log::write("Sprite instantiated");
    };
