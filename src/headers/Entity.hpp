#pragma once

#include <SFML/Graphics.hpp>
#include "shorthand.hpp"

class Entity {
private:
    int frameCount;
    int frameSize;
    int currentFrameIdx;
    int animationTime;
    sf::Clock animationClock;
    sf::IntRect currentFrame;


public:
    Vec2f pos;
    Vec2f size;
    Vec2f vel;
    bool dead = false;
    bool hasSpriteAnimation = false;


    int health;

    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;

    Entity(Vec2f pos, Vec2f vel, Vec2f size, std::string texturePath, std::string name);
    Entity(
        Vec2f pos, Vec2f vel, Vec2f size, std::string texturePath, std::string name, 
        int frameCount, int frameSize, Vec2i frameStart, int animationTime
    );

    virtual ~Entity() = default;
    
    virtual void update();
    virtual void animateFrames();
    virtual void die();

    void draw();
    void move();
    
    void setPos(Vec2f pos);
    Vec2f getPos();

    bool isDead();

    void takeDamage(int damageValue);
    
    void setAnimation(int frameCount, int frameSize, Vec2i frameStart, int animationTime);
};
