#include <iostream>
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "TextureLoader.hpp"
#include "AudioLoader.hpp"
#include "Settings.hpp"
#include "Entities.hpp"

Bullet::Bullet(Vec2f pos, Vec2f vector, float speed) :
    Entity(pos, vector, Vec2f(5, 5), "", "Bullet"),
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
    int particleCount = 200;
    int particleSpeed = 200;
    
    Entities::create<Explosion>(this->pos, particleCount, particleSpeed, sf::milliseconds(250));
    AudioLoader::explosion.play();
}