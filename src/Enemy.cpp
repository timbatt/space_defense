#include <iostream>
#include "Enemy.hpp"
#include "TextureLoader.hpp"




Enemy::Enemy(Vec2f pos) :
    Entity(pos, Vec2f(0, 0), Vec2f(37, 22), TextureLoader::enemyTexture, "Enemy") {
    this->sprite.scale(Vec2f(2, 2));
    this->hitbox.scale(Vec2f(1.5, 1.5));
}


void Enemy::update() {
    this->vel = Vec2f(rand() % 50, rand() % 50);
    Entity::update();
}