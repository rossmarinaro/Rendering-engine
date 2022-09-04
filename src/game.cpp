
#include "../headers/game.h"
#include "../headers/resources/assets.h"

Sprite* background;
Player* player;
static std::vector<Sprite*> currentEntities;

Game::Game(Inputs* inputs, GLuint textures[]) 
{

    AssetManager* m_assMgr = new AssetManager();
    MapManager* m_mapMgr = new MapManager(textures[0], m_assMgr);

    background = new Sprite(textures[1], -0.5, -0.5, m_assMgr->menu);
    player = new Player(textures[2], -0.3, -0.3, m_assMgr->swanky_velvet);
    player->SetScale(0.325f, 0.75f);

    currentEntities.push_back(background);
    currentEntities.push_back(player);
}


void Game::Update(Inputs* inputs)
{
    for (auto &ent : currentEntities)
    {
        Log::write(ent);
        ent == player ? 
            player->Update(inputs) : ent->Render();
    }
    
}

Game::~Game()
{
    for (auto &ent : currentEntities)
        delete ent;

    delete m_mapMgr;
    delete m_assMgr;   
    
    Log::write("game closed.");
}




