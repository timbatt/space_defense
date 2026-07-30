#include <memory>
#include <iostream>

#include "Game.hpp"
#include "Entities.hpp"
#include "Entity.hpp"
#include <algorithm>


std::vector<std::unique_ptr<Entity>> Entities::all;
int Entities::totalCount = 0;

void Entities::init() {
    Entities::all.reserve(Game::MAX_ENTITY_COUNT);
}


void Entities::update() {
    for (const auto& entity : Entities::all) {
        if (entity != nullptr) entity->update();
    }


    Entities::all.erase(
    std::remove_if(Entities::all.begin(), Entities::all.end(),
        [](const std::unique_ptr<Entity>& entity) {            
            return entity == nullptr || entity->isDead();   
        }),
    Entities::all.end());

}

void Entities::clear() {
    Entities::all.clear();
}