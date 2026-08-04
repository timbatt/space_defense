#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <iostream>
#include "Entity.hpp"
#include "Settings.hpp"

#define EntityVector std::vector<std::unique_ptr<Entity>>
#define EntityPtr_Vector_Map std::unordered_map<std::string, EntityVector>

class Entities
{
public:
    static std::vector<std::string> names;
    static EntityPtr_Vector_Map map;
    
    static int totalCount;

    static void update();
    static void clear();
    static void init();

    static void checkCollisions();
    static void checkBulletEnemyCollisions();

    static void clearDeadEntitiesByType(std::string entityType);


    template<typename T, typename... Args>
    static T* create(Args&&... args) {
        auto entity = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = entity.get();
        
        if (Entities::map.find(entity->name) == Entities::map.end()) {
            map[entity->name] = EntityVector();
            map[entity->name].reserve(Settings::MAX_ENTITY_PER_TYPE);
            Entities::names.push_back(entity->name);
        } 
        
        Entities::map[entity->name].push_back(std::move(entity));        
        
        Entities::totalCount++;

        return ptr;
    }
};
