
#include "GameObject.hpp"
#include "Game.hpp"
#include "TextureManager.hpp"
GameObject::GameObject(const char* TextureSheet, int x, int y)
{
    ObjTexture = TextureManager::LoadTexture(TextureSheet);
    std::cout<<"gameobject"<<std::endl;
    Xpos = x;
    Ypos = y;
}

void GameObject::Update()
{
    Xpos++;
    Ypos++;
    
    ClipRect.w = 32;
    ClipRect.h = 32;
    ClipRect.x = 0;
    ClipRect.y = 0;
    
    InRect.x = Xpos;
    InRect.y = Ypos;
    InRect.w = ClipRect.w*2;
    InRect.h = ClipRect.h*2;
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::Renderer, ObjTexture, &ClipRect, &InRect);
}
