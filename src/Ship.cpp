#include <iostream>
#include <math.h>
#include "Ship.hpp"
#include "Entity.hpp"
#include "Entities.hpp"
#include "Bullet.hpp"
#include "AudioLoader.hpp"
#include "Game.hpp"
#include "TextureLoader.hpp"

Ship::Ship(int x, int y, int length) :
    Entity(Vec2f(x, y), Vec2f(0, 0), Vec2f(30, 30), TextureLoader::ShipTexture, "Ship")
{
    this->length = 30;
    this->sprite.scale(Vec2f(2, 2));
    this->hitbox.scale(Vec2f(1.75, 1.75));
    this->sprite.setOrigin(Vec2f(15, 25));
    this->hitbox.setOrigin(Vec2f(15, 25));
};

Vec2f Ship::getMuzzlePosition() {
    return Vec2f(
        this->pos.x + this->length * std::cos(this->angleRads), 
        this->pos.y + this->length * std::sin(this->angleRads)
    );
}

Vec2f Ship::getFiringVector() {
    return Vec2f(std::cos(this->angleRads), std::sin(this->angleRads));
}


void Ship::update() {
    Entity::update();


    Vec2i mousePos = sf::Mouse::getPosition(Game::window);

    // Optional: Convert mouse position to world coordinates if needed
    Vec2f worldMousePos = Game::window.mapPixelToCoords(mousePos);

    // Calculate angle in radians between line and mouse position
    this->angleRads = std::atan2(worldMousePos.y - pos.y, worldMousePos.x - pos.x);
    this->angle = angleRads * 180.0f / M_PI;
    this->sprite.setRotation(this->angle + 90);
    this->hitbox.setRotation(this->angle);

    this->muzzlePos = this->getMuzzlePosition();

    this->hitbox.move(this->getFiringVector());
    this->sprite.move(this->getFiringVector());

    if (this->cooldown > sf::Time::Zero) {
        this->cooldown -= sf::seconds(Game::timeDelta);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->cooldown <= sf::Time::Zero) this->fire();
    }
}

void Ship::resetCooldown() {
    this->cooldown = sf::milliseconds(100);
}

void Ship::fire() {
    Vec2f muzzlePos = this->getMuzzlePosition();
    float bulletSpeed = 500;
    Entities::create<Bullet>(muzzlePos, this->getFiringVector(), bulletSpeed);
    AudioLoader::ShipFire.play();
    this->resetCooldown();
}