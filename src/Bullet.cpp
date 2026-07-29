#include <iostream>
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "TextureLoader.hpp"
#include "AudioLoader.hpp"
#include "Game.hpp"
#include "Entities.hpp"

Bullet::Bullet(Vec2f pos, Vec2f vector, float speed) :
    Entity(pos, vector, Vec2f(5, 5), "", "Bullet"),
    speed(speed)
{
    this->vel = Vec2f(vector.x * speed, vector.y * speed);
    this->sprite.setTexture(TextureLoader::particleTexture);
    this->showHitbox();
}

void Bullet::update() {
    Entity::update();
    if (this->hasHitWall()) {
        this->explode();
        this->die();
    }
}

bool Bullet::hasHitWall() {
    bool isCollision = !(
        (this->pos.x <= Game::WINDOW_W && this->pos.x > 0) && 
        (this->pos.y <= Game::WINDOW_H && this->pos.y > 0));

    return isCollision;
}

void Bullet::explode() {
    int particleCount = 200;
    int particleSpeed = 200;
    
    Entities::create<Explosion>(this->pos, particleCount, particleSpeed, sf::milliseconds(250));
    AudioLoader::explosion.play();
}