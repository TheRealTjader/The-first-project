
#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "Components.hpp"
#include "ECS.hpp"
#include "SpriteCompontent.hpp"
SDL_Renderer* Game::Renderer = nullptr;

Map* GameMap;

Manager Manager;
auto& Player( Manager.AddEntity());
Game::Game()
{
    
}
Game::~Game()
{
    
}

void Game::Init(const char *Title, int x, int y, int Width, int Height, bool Fullscreen)
{
    int Flags = 0;
    IsRunning = true;
    if(Fullscreen)
    {
        Flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_INIT_EVERYTHING)
    {
        std::cout<<"SDL INIT working \n";
        
        Window = SDL_CreateWindow(Title, x, y, Width, Height, Flags);
        if(Window)
        {
            printf("Window created\n");
        }
        Renderer = SDL_CreateRenderer(Window, -1, 0);
        
        if(Renderer)
        {
            SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
            std::cout<<"Renderer created\n";
        }
        
    }
    else
    {
        IsRunning=false;
    }
GameMap = new Map();

    Player.AddComponent<PositionCompontent>();
    Player.AddComponent<SpriteComponent>("Assets/Player.png");
}

void Game::HandleEvents()
{
    SDL_Event Events;
    SDL_PollEvent(&Events);
    switch (Events.type)
    {
        case SDL_QUIT:
            IsRunning = false;
            break;
            
        default:
            break;
    }
}

void Game::Update()
{
    Counter++;
    std::cout<<Counter<<std::endl;
    Manager.Refresh();
    Manager.Update();
}

void Game::Render()
{
    SDL_RenderClear(Renderer);
    GameMap->DrawMap();
    
    SDL_RenderPresent(Renderer);
}

void Game::Clean()
{
    SDL_DestroyWindow(Window);
    SDL_DestroyRenderer(Renderer);
    SDL_Quit();
    printf("Everything cleaned\n");
}
