#include <memory>
#include <iostream>
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

void Entities::checkCollisions() {
    Entities::checkBulletEnemyCollisions();
}


void Entities::checkBulletEnemyCollisions() {
    auto bulletIt = Entities::map.find("Bullet");
    if (bulletIt == Entities::map.end()) return;

    for (auto& bullet : bulletIt->second) {
        auto enemyIt = Entities::map.find("Enemy");
        if (enemyIt == Entities::map.end()) continue;

        for (auto& enemy : enemyIt->second) {
            if (bullet->hitbox.getGlobalBounds().intersects(enemy->hitbox.getGlobalBounds()))
            {
                enemy->takeDamage(50);
                bullet->die();
            }
        }

    }
}

void Entities::update() {
    Entities::checkCollisions();

    for (std::string entityType : Entities::names) {
        auto it = Entities::map.find(entityType);
        if (it == Entities::map.end()) continue;

        for (auto& entity : it->second) {
            if (entity != nullptr) entity->update();
        }

        Entities::clearDeadEntitiesByType(entityType);
  
    }
}


void Entities::clearDeadEntitiesByType(std::string entityType) {
    Entities::map[entityType].erase(
    std::remove_if(Entities::map[entityType].begin(), Entities::map[entityType].end(),
        [](const std::unique_ptr<Entity>& entity) {     
            // Condition based cleanup. Remove if it's dead or null       
            return entity == nullptr || entity->isDead();   
        }),
    Entities::map[entityType].end());  
}


void Entities::clear() {
    Entities::map.clear();
}