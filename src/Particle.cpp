#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "shorthand.hpp"
#include "Game.hpp"
#include "Particle.hpp"


Particle::Particle(Vec2f pos, Vec2f velocity, sf::Time lifetime) {
    this->pos = pos;
    this->velocity = velocity;
    this->lifetime = lifetime;
    this->startTime = sf::Clock();
}

void Particle::update() {
    this->pos.x += this->velocity.x * Game::timeDelta;
    this->pos.y += this->velocity.y * Game::timeDelta;

    sf::Time elapsed = this->startTime.getElapsedTime();
    if (elapsed >= this->lifetime) this->die();

}

bool Particle::isDead() {
    return this->dead;
}

void Particle::die() {
    this->dead = true;
}