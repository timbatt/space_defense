#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "shorthand.hpp"
#include "Game.hpp"
#include "Particle.hpp"


Particle::Particle(Vec2f pos, Vec2f vel, Vec2f size, sf::Time lifetime) {
    this->pos = pos;
    this->vel = vel;
    this->lifetime = lifetime;
    this->startTime = sf::Clock();

    this->hitbox.setPosition(pos);
    this->hitbox.setSize(size);
    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setFillColor(sf::Color(100, 50, 50));
    this->hitbox.setOutlineThickness(1.0f);
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