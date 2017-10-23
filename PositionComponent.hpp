
#ifndef PosistionComponent_hpp
#define PosistionComponent_hpp

#include "ECS.hpp"
#include "PositionComponent.hpp"
#include "SpriteCompontent.hpp"
#include "TextureManager.hpp"
#include "Components.hpp"

class PositionCompontent
{
public:
    
    PositionCompontent()
    {
        Xpos = Ypos = 0;
    }
    
    PositionCompontent(int X, int Y)
    {
        Xpos = X;
        Ypos = Y;
    }
    
    int X() { return Xpos;}
    int Y() {return Ypos;}
    
    void X(int X){Xpos = X;}
    void Y(int Y){Ypos = Y;}
    void SetPos(int X, int Y){Xpos = X; Ypos = Y;}
    void Init() 
    {
        Xpos = 0;
        Ypos = 0;
    }
    
    void Update() 
    {
        Xpos++;
        Ypos++;
    }
private:
    int Xpos;
    int Ypos;
};

#endif /* PosistionComponent_hpp */
