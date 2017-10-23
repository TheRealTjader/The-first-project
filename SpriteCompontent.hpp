//
//  SpriteCompontent.hpp
//  The first concept
//
//  Created by Edvin on 2017-10-17.
//  Copyright © 2017 Edvin. All rights reserved.
//

#ifndef SpriteCompontent_hpp
#define SpriteCompontent_hpp
#include "Components.hpp"
#include "SDL2/SDL.h"
#include "ECS.hpp"
#include "PositionComponent.hpp"

class SpriteComponent
{
private:
    SDL_Texture *Texture;
    SDL_Rect Source, Destination;
    PositionCompontent *Position;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* Path)
    {
        Texture = TextureManager::LoadTexture(Path);
    }
    
    void Init() 
    {
        Position = &Entity->GetComponent<PositionCompontent()>();
        Source.x = Source.y = 0;
        Source.x = Source.w = 32;
        Destination.w = Destination.h = 32;
    }
    
    void Update() 
    {
        Destination.x = Position->X();
        Destination.y = Position->Y();
    }
    
    void Draw() 
    {
        TextureManager::Draw(Texture, Source, Destination);
    }
};



#endif /* SpriteCompontent_hpp */
