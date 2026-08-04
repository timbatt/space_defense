#include "Enemy.hpp"
#include <iostream>




Enemy::Enemy(Vec2f pos) :
    Entity(pos, Vec2f(0, 0), Vec2f(20, 20), "", "Enemy") {
}


void Enemy::update() {
    this->vel = Vec2f(rand() % 20, rand() % 20);
    Entity::update();
}