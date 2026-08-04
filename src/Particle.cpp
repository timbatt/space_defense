#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Game.hpp"
#include "Particle.hpp"
#include "shorthand.hpp"


Particle::Particle(Vec2f pos, Vec2f vel, Vec2f size, sf::Time lifetime) {
    this->pos = pos;
    this->vel = vel;
    this->lifetime = lifetime;
    this->startTime = sf::Clock();
    this->dead = false;

    this->hitbox.setPosition(pos);
    this->hitbox.setSize(size);
    this->hitbox.setFillColor(sf::Color(235, 97, 52));
}


void Particle::draw() {
    Game::window.draw(this->hitbox);
}

void Particle::move() {
    this->hitbox.move(this->vel * Game::timeDelta);
    this->pos = this->getPos();
}

Vec2f Particle::getPos() {
    return this->hitbox.getPosition();
}


void Particle::update() {
    if (this->isDead()) return;

    this->move();
    this->draw();

    if (this->startTime.getElapsedTime() >= this->lifetime) this->die();
}


bool Particle::isDead() {
    return this->dead;
}

void Particle::die() {
    this->dead = true;
}