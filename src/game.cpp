
#include "../headers/game.h"
#include "../headers/tilemap.h"

Entities::Sprite* background;
Entities::Player* player;
MapManager* map;


Game::Game(Inputs* inputs, GLuint textures[]) 
{
 

    //MapManager* map = new MapManager(textures);

    //background = new Entities::Sprite(textures[0], -0.5, -0.5, Assets::Images::menu);

    //player = new Entities::Player(textures[1], -0.3, -0.3, Assets::Images::swanky_velvet);
    //player->SetScale(0.325f, 0.75f);

}


void Game::Update(Inputs* inputs)
{

    //background->Render();
    //player->Update(inputs);
    //map->m_ts->Render();
}

Game::~Game()
{

    //delete player;
    //delete background;
    //delete ts;
    delete map;
    Log::write("game closed.");
}




