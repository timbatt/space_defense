#include "Game.hpp"
#include "Entity.hpp"
#include <iostream>
#include <memory>


Entity::Entity(Vec2f pos, Vec2f vel, Vec2f size, std::string texturePath, std::string name)
    : pos(pos), vel(vel), size(size), dead(false), health(100)
{
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
    this->hitbox.setSize(size);
    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setOutlineThickness(1.0f);

    if (!texturePath.empty()) {
        if (!this->texture.loadFromFile(texturePath)) {
            std::cerr << "ERROR: Failed to load texture from " << texturePath << std::endl;
        } else {
            this->sprite.setTexture(this->texture);
        }
    }
    
    this->name = name.empty() ? "Entity" : name;
}


void Entity::update() {
    this->move();
    this->draw();
}


void Entity::draw() {
    if (Game::doShowHitboxes) Game::window.draw(hitbox);
    Game::window.draw(sprite);
}


void Entity::die() {
    this->dead = true;
}


bool Entity::isDead() {
    return this->dead;
}


void Entity::move() {
    this->sprite.move(this->vel * Game::timeDelta);
    this->hitbox.move(this->vel * Game::timeDelta);
    this->pos = this->getPos();
}


Vec2f Entity::getPos() {
    return this->hitbox.getPosition();;
}


void Entity::setPos(Vec2f pos) {
    this->pos = pos;
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
}

void Entity::takeDamage(int damageValue) {
    this->health -= damageValue;
    if (this->health <= 0) this->die();
}
