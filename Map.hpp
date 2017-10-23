
#ifndef Map_hpp
#define Map_hpp

#include "SDL2/SDL.h"
#include <iostream>

class Map
{
public:
    Map();
    ~Map();
    
    void LoadMap(int Array[20][25]);
    void DrawMap();
private:
    SDL_Rect Source, Destination;
    SDL_Texture* TileMap;
    SDL_Texture* Grass;
    SDL_Texture* Water;
    SDL_Texture* Road;
    int TheMap[20][25];
};

#endif /* Map_hpp */
