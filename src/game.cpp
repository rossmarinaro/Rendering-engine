
#include "../headers/game.h"
#include "../headers/resources/assets.h"

Entities::Sprite* background;
Entities::Player* sprite;


Game::Game(Inputs* inputs, GLuint textures[])
{

    //background = new Entities::Sprite(textures[0], -0.5, -0.5, Assets::Images::menu);
    sprite = new Entities::Player(textures[1], -0.3, -0.3, Assets::Images::swanky_velvet);

}

//-----------------------------------------------------

void Game::Update(Inputs* inputs)
{

    //background->Render();
    sprite->Update(inputs);

}

Game::~Game()
{

    delete sprite;
    //delete background;

    Log::write("game closed.");
}




