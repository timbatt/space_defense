#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Particle.hpp"
#include "Explosion.hpp"
#include "shorthand.hpp"
#include "TextureLoader.hpp"
#include "Game.hpp"
#include "Entity.hpp"

Explosion::Explosion(Vec2f pos, int particleCount, float particleSpeed, sf::Time lifetime) :
Entity(pos, Vec2f(0, 0), Vec2f(0, 0), "", "Explosion") {
    this->pos = pos;
    this->particleCount = particleCount;
    this->particleSpeed = particleSpeed;
    this->lifetime = lifetime;

    this->startTime = sf::Clock();
    this->particleSprite.setOrigin(particleTexture.getSize().x / 2.0f, particleTexture.getSize().y / 2.0f);
    this->particleSprite.setTexture(TextureLoader::particleTexture);
}



void Explosion::draw() { 
    for (size_t i = 0; i < particles.size(); ++i) {
        Particle& particle = particles[i];
        float alpha = particle.lifetime.asMilliseconds() / 10 / (float)this->startTime.getElapsedTime().asMilliseconds();
        particleSprite.setPosition(particle.pos);
        particleSprite.setColor(sf::Color(255, 255, 255, alpha * 255));
        Game::window.draw(particleSprite);
    }

}

Particle Explosion::randomParticle() {
    Vec2f particlePos = this->pos;
    float particleAngle = (rand() % 360) * 3.14f / 180.0f;
    float particleSpeed = (rand() % 360) + this->particleSpeed;
    Vec2f particleVelocity = Vec2f(std::cos(particleAngle) * particleSpeed, std::sin(particleAngle) * particleSpeed);
    sf::Time particleLifetime = sf::milliseconds(rand() % this->lifetime.asMilliseconds() + 200);

    Particle particle(particlePos, particleVelocity, particleLifetime);
    return particle;
}

void Explosion::initParticles() {
    if (this->particles.size() >= this->particleCount) return;
    for (int i = 0; i < this->particleCount; ++i) {
        Particle randParticle = this->randomParticle();
        particles.push_back(randParticle);
    }
}

void Explosion::update() {
    if (this->isDead()) return;

    this->initParticles();
    
    this->draw();
    
    for (size_t i = 0; i < particles.size(); ++i) {
        Particle& particle = particles[i];
        particle.update();
    }
    
    if (this->startTime.getElapsedTime() >= this->lifetime) {
        this->die();
        this->particles.clear();
    }

    particles.erase(
    std::remove_if(particles.begin(), particles.end(),
        [](Particle& particle) {            
            return particle.isDead();
        }),
    particles.end());
}
