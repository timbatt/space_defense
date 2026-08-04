#pragma once

#include <SFML/Graphics.hpp>
#include "shorthand.hpp"

class Entity {
public:
    Vec2f pos;
    Vec2f size;
    Vec2f vel;
    bool dead = false;

    int health;

    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;

    Entity(Vec2f pos, Vec2f vel, Vec2f size, std::string texturePath, std::string name);
    virtual ~Entity() = default;
    
    virtual void update();
    virtual void die();

    void draw();
    void move();
    
    void setPos(Vec2f pos);
    Vec2f getPos();

    bool isDead();

    void takeDamage(int damageValue);
};
