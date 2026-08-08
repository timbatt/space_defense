#include <iostream>
#include <memory>
#include "Game.hpp"
#include "Entity.hpp"


Entity::Entity(Vec2f pos, Vec2f vel, Vec2f size, sf::Texture& texture, std::string name):
pos(pos), vel(vel), size(size), dead(false), health(100)
{
    
    this->name = name.empty() ? "Entity" : name;

    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
    this->hitbox.setSize(size);
    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setOutlineThickness(1.0f);

    this->sprite.setTexture(texture);

}

// Animation constructor
Entity::Entity(
    Vec2f pos, Vec2f vel, Vec2f size, sf::Texture& texture, std::string name, 
    int frameCount, int frameSize, Vec2i frameStart, int animationTime
):
Entity(pos, vel, size, texture, name)
{   
    this->frameSize = frameSize;
    this->frameCount = frameCount; 
    this->animationTime = animationTime;
    this->currentFrame = sf::IntRect(frameStart, Vec2i(frameSize, frameSize));
    this->animationClock = sf::Clock();
}


void Entity::animateFrames() {
    this->currentFrame.top = this->currentFrameIdx * this->frameSize;
    this->sprite.setTextureRect(this->currentFrame);

    if (this->animationClock.getElapsedTime().asMilliseconds() > this->animationTime) {
        this->currentFrameIdx++;
        this->animationClock.restart();
    }

    if (this->currentFrameIdx > this->frameCount) {
        this->currentFrameIdx = 0;
    }
}

void Entity::setAnimation(int frameCount, int frameSize, Vec2i frameStart, int animationTime) {
    this->currentFrameIdx = 0;
    this->hasSpriteAnimation = true;
    this->frameCount = frameCount;
    this->frameSize = frameSize;
    this->currentFrame = sf::IntRect(frameStart, Vec2i(frameSize, frameSize));
    this->animationTime = animationTime;
    this->animationClock = sf::Clock();
}

void Entity::update() {
    if (this->hasSpriteAnimation) this->animateFrames();
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
