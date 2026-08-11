#include <iostream>
#include "Settings.hpp"
#include "TextureLoader.hpp"
#include "Entities.hpp"
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "AudioLoader.hpp"
#include "TextureLoader.hpp"

Bullet::Bullet(Vec2f pos, Vec2f vector, float speed) :
    Entity(pos, vector, Vec2f(5, 5), TextureLoader::particleTexture, "Bullet"),
    speed(speed)
{
    this->vel = Vec2f(vector.x * speed, vector.y * speed);
    this->sprite.setTexture(TextureLoader::particleTexture);
}

void Bullet::update() {
    Entity::update();

    if (this->hasHitWall()) {
        this->die();
    }
}

bool Bullet::hasHitWall() {
    bool isCollision = !(
        (this->pos.x <= Settings::WINDOW_W && this->pos.x > 0) && 
        (this->pos.y <= Settings::WINDOW_H && this->pos.y > 0));

    return isCollision;
}

void Bullet::die() {
    this->explode();
    Entity::die();
}


void Bullet::explode() {
    int particleCount = 100;
    int particleSpeed = 50;
    
    Entities::create<Explosion>(this->pos, particleCount, particleSpeed, sf::milliseconds(50));
    AudioLoader::explosion.play();
}