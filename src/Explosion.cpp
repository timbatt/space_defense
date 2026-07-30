#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Particle.hpp"
#include "Particles.hpp"
#include "Explosion.hpp"
#include "shorthand.hpp"
#include "TextureLoader.hpp"
#include "Game.hpp"
#include "Entity.hpp"

Explosion::Explosion(Vec2f pos, int maxParticleCount, float particleSpeed, sf::Time lifetime) :
Entity(pos, Vec2f(0, 0), Vec2f(0, 0), "", "Explosion") {
    this->pos = pos;
    this->maxParticleCount = maxParticleCount;
    this->particleSpeed = particleSpeed;
    this->lifetime = lifetime;
    
    this->startTime = sf::Clock();

    for (int i = 0; i < this->maxParticleCount; i++ ) {
        this->randomParticle();
    }
}


void Explosion::randomParticle() {
    float angle = (rand() % 360) * 3.14f / 180.0f;
    float speed = (rand() % 360) + this->particleSpeed;
    Vec2f vel = Vec2f(std::cos(angle) * speed, std::sin(angle) * speed);
    sf::Time particleLifetime = sf::milliseconds(rand() % this->lifetime.asMilliseconds() + 200);
    Particles::create<Particle>(this->pos, vel, Vec2f(5, 5), particleLifetime);
}

void Explosion::update() {
    if (this->isDead()) return;
    if (this->startTime.getElapsedTime() >= this->lifetime) this->die();
}
