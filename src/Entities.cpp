#include <memory>
#include <iostream>

#include "Game.hpp"
#include "Entities.hpp"
#include "Entity.hpp"
#include <algorithm>


std::vector<std::unique_ptr<Entity>> Entities::entities;
int Entities::totalCount = 0;

void Entities::init() {
    Entities::entities.reserve(Game::MAX_ENTITY_COUNT);
}


void Entities::update() {
    for (const auto& entity : Entities::entities) {
        if (entity != nullptr) entity->update();
    }


    Entities::entities.erase(
    std::remove_if(Entities::entities.begin(), Entities::entities.end(),
        [](const std::unique_ptr<Entity>& entity) {            
            return entity == nullptr || entity->isDead();   
        }),
    Entities::entities.end());

}

void Entities::clear() {
    Entities::entities.clear();
}