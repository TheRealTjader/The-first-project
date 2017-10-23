//
//  TextureManager.hpp
//  The first concept
//
//  Created by Edvin on 2017-10-04.
//  Copyright © 2017 Edvin. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2_image/SDL_image.h"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* FileName);
    static void Draw(SDL_Texture* Texture, SDL_Rect Source, SDL_Rect Destination);
};
#endif /* TextureManager_hpp */
