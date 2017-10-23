//
//  main.cpp
//  The first concept
//
//  Created by Edvin on 2017-10-03.
//  Copyright © 2017 Edvin. All rights reserved.
//

#include <iostream>
#include "Game.hpp"
#include "TextureManager.hpp"

Game *game = nullptr;


int main(int argc, const char* argv[])
{
    game = new Game();
    //initializes the game
    game->Init("Project Icarus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    //A thousand milliseconds (1sec) divided by target FPS
    const int FrameDelay = 1000/60;
    Uint32 StartingFrames;
    int FrameTime = NULL;
    while(game->Running())
    {
        std::cout<<"Game is running"<<std::endl;
        StartingFrames = SDL_GetTicks();
        game->HandleEvents();
        game->Update();
        game->Render();
        FrameTime = SDL_GetTicks() - StartingFrames;
        if(FrameTime<FrameDelay)
        {
            SDL_Delay(FrameDelay-FrameTime);
        }
    }
    game->Clean();
    return 0;
}
