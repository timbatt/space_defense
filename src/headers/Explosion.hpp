#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "Entity.hpp"
#include "shorthand.hpp"


class Explosion : public Entity {
private:
    int maxParticleCount;
    float particleSpeed;
    sf::Time lifeDecrease;
    sf::Clock startTime;
    sf::Time lifetime;

public:
    Explosion(Vec2f pos, int particleNum, float particleSpeed, sf::Time lifetime);
    void update();
    void randomParticle();
};