//
//  Game.hpp
//  The first concept
//
//  Created by Edvin on 2017-10-03.
//  Copyright © 2017 Edvin. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"
class Game
{
public:
    Game();
    ~Game();
    
    void Init(const char* Title, int x, int y, int Width, int Height, bool Fullscreen);
    void HandleEvents();
    void Update();
    void Render();
    void Clean();
    bool Running() { return IsRunning;}
    
    static SDL_Renderer *Renderer;
    
private:
    bool IsRunning;
    int Counter = 0;
    SDL_Window *Window;
};



#endif /* Game_hpp */
