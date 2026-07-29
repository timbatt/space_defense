#pragma once
#include <SFML/Graphics.hpp>
#include "shorthand.hpp"


class Particle {
public:
    sf::Time lifetime;
    sf::Clock startTime;
    Vec2f velocity;
    Vec2f pos;

    bool dead;


    Particle(Vec2f pos, Vec2f velocity, sf::Time lifetime);
    virtual ~Particle() = default;

    void update();

    void die();
    bool isDead();
};




