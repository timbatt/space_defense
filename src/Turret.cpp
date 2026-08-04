#include <iostream>
#include <math.h>
#include "Turret.hpp"
#include "Entity.hpp"
#include "Entities.hpp"
#include "Bullet.hpp"
#include "AudioLoader.hpp"
#include "Game.hpp"

Turret::Turret(int x, int y, int length) :
    Entity(Vec2f(x, y), Vec2f(0, 0), Vec2f(2, length), "resources/turret.png", "Turret")
{
    this->length = length;
    this->sprite.setOrigin(Vec2f(0, 0));
    this->hitbox.setOrigin(Vec2f(0, 0));
};

Vec2f Turret::getMuzzlePosition() {
    return Vec2f(
        this->pos.x + this->length * std::cos(this->angleRads), 
        this->pos.y + this->length * std::sin(this->angleRads)
    );
}

Vec2f Turret::getFiringVector() {
    return Vec2f(std::cos(this->angleRads), std::sin(this->angleRads));
}

void Turret::update() {
    Entity::update();

    Vec2i mousePos = sf::Mouse::getPosition(Game::window);

    // Optional: Convert mouse position to world coordinates if needed
    Vec2f worldMousePos = Game::window.mapPixelToCoords(mousePos);

    // Calculate angle in radians between line and mouse position
    this->angleRads = std::atan2(worldMousePos.y - pos.y, worldMousePos.x - pos.x);
    this->angle = angleRads * 180.0f / M_PI;
    this->muzzlePos = this->getMuzzlePosition();
    this->sprite.setRotation(this->angle);
    this->hitbox.setRotation(this->angle - 90);

    if (this->cooldown > sf::Time::Zero) {
        this->cooldown -= sf::seconds(Game::timeDelta);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->cooldown <= sf::Time::Zero) this->fire();
    }
}

void Turret::resetCooldown() {
    this->cooldown = sf::milliseconds(100);
}

void Turret::fire() {
    Vec2f muzzlePos = this->getMuzzlePosition();
    float bulletSpeed = 500;
    Entities::create<Bullet>(muzzlePos, this->getFiringVector(), bulletSpeed);
    AudioLoader::turretFire.play();
    this->resetCooldown();
}