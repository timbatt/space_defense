#include <memory>
#include <iostream>

#include "Game.hpp"
#include "Entities.hpp"
#include "Entity.hpp"
#include <algorithm>
#include <ranges>
#include <unordered_map>


EntityPtr_Vector_Map Entities::map;
std::vector<std::string> Entities::names;


int Entities::totalCount = 0;

void Entities::init() {
    // Currently not needed, however will probably instantiate entities map with static values in the future.
}


void Entities::update() {
    for (std::string key : Entities::names) {
        auto it = Entities::map.find(key);
        if (it == Entities::map.end()) continue;

        for (auto& entity : it->second) {
            // Update
            if (entity != nullptr) entity->update();
        }

        // Remove dead entities
        Entities::map[key].erase(
        std::remove_if(Entities::map[key].begin(), Entities::map[key].end(),
            [](const std::unique_ptr<Entity>& entity) {            
                return entity == nullptr || entity->isDead();   
            }),
        Entities::map[key].end());    
    }
}

void Entities::clear() {
    Entities::map.clear();
}