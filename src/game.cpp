
#include "../headers/game.h"
#include "../headers/resources/assets.h"

Entities::Sprite* background;
Entities::Player* player;


Game::Game(Inputs* inputs, GLuint textures[]) 
{
 
    background = new Entities::Sprite(textures[0], -0.5, -0.5, Assets::Images::menu);

    player = new Entities::Player(textures[1], -0.3, -0.3, Assets::Images::swanky_velvet);
    player->SetScale(0.325f, 0.75f);

}


void Game::Update(Inputs* inputs)
{

    background->Render();
    player->Update(inputs);

}

Game::~Game()
{

    delete player;
    delete background;

    Log::write("game closed.");
}




