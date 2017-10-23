
#ifndef GameObject_hpp
#define GameObject_hpp
#include "Game.hpp"
#include <stdio.h>
class GameObject
{
public:
    
    GameObject(const char* TextureSheet, int x, int y);
    ~GameObject();
    
    void Update();
    void Render();
    
private:
    
    int Xpos, Ypos;
    
    SDL_Texture* ObjTexture;
    SDL_Rect ClipRect, InRect; //ClipRect is dimensions on the picture, Inrect is where and how it lloks on the screen
    
};




#endif /* GameObject_hpp */
