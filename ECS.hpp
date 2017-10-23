//
//  ECS.hpp
//  The first concept
//
//  Created by Edvin on 2017-10-16.
//  Copyright © 2017 Edvin. All rights reserved.
//

#ifndef ECS_hpp
#define ECS_hpp

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "Components.hpp"
#include "ECS.hpp"
#include "SpriteCompontent.hpp"

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID GetCompenentTypeID()
{
    static ComponentID LastID = 0;
    return LastID++;
}

template <typename T> inline ComponentID GetCompenentTypeID() noexcept
{
    static ComponentID TypeID = GetCompenentTypeID();
    return TypeID;
}

constexpr std::size_t MaxComponents = 32;

using ComponentBitSet = std::bitset<MaxComponents>;
using ComponentArray = std::array<Component*, MaxComponents>;

class Component
{
public:
    Entity* entitiy;
    virtual void Init() {}
    virtual void Update() {}
    virtual void Draw() {}
    
    virtual ~Component() {}
};

class Entity
{
public:
    void Update()
    {
        for(auto& c: ListComponents) c->Update();
    }
    void Draw()
    {
        for(auto& c: ListComponents) c->Draw();
    }

    bool IsActive()
    {
        return Active;
    }
    void Destroy()
    {
        Active = false;
    }
    
    template <typename T> bool HasComponent() const
    {
        return ComponentBitSet[GetCompenentTypeID<T>];
    }
    
    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        ListComponents.emplace_back( std::move(uPtr));
        ComponentArray[GetCompenentTypeID<T>()] = c;
        ComponentBitSet[GetCompenentTypeID<T>()] = true;
        c->Init();
        return *c;
    }
    template<typename T>T& GetComponent()
    {
        auto ptr(ComponentArray[GetCompenentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
protected:
    bool Active = true; //why not private
    std::vector<std::unique_ptr<Component>> ListComponents;
    ComponentArray ComponentArray;
    ComponentBitSet ComponentBitSet;

};

class Manager
{
public:
    void Update()
    {
        for(auto& e:Entities) e->Update();
    }
    void Draw()
    {
        for(auto& e:Entities) e->Draw();
    }
    void Refresh()
    {
        Entities.erase(std::remove_if(std::begin(Entities), std::end(Entities) , [](const std::unique_ptr<Entity>&mEntity)
            {
                return !mEntity->IsActive();
            }),
                       std::end(Entities));
    }
    Entity& AddEntity()
    {
        Entity* e = new Entity();
        std::unique_ptr<Entity> uPtr{e};
        Entities.emplace_back(std::move(uPtr));
        return *e;
    }
private:
    std::vector<std::unique_ptr<Entity>> Entities;
};
#endif /* ECS_hpp */
