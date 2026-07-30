#pragma once
#include <memory>

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include <iostream>

class Entities
{
public:
    static std::vector<std::unique_ptr<Entity>> all;
    static int totalCount;

    static void update();
    static void clear();
    static void init();
    


    template<typename T, typename... Args>
    static T* create(Args&&... args) {
        auto entity = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = entity.get();

        Entities::all.push_back(std::move(entity));        
        
        Entities::totalCount++;

        return ptr;
    }
};
