#pragma once
#include <SFML/Graphics.hpp>
#include "shorthand.hpp"


class Particle {
public:
    sf::Time lifetime;
    sf::Clock startTime;
    sf::RectangleShape hitbox;

    Vec2f vel;
    Vec2f pos;

    bool dead;


    Particle(Vec2f pos, Vec2f vel, Vec2f size, sf::Time lifetime);
    virtual ~Particle() = default;

    void die();
    bool isDead();

    Vec2f getPos();
    
    virtual void update();
    virtual void move();
    virtual void draw();
};




