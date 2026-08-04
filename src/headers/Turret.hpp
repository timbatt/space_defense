#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Audio.hpp"
#include "shorthand.hpp"

class Turret : public Entity {
private:
    sf::Time cooldown = sf::milliseconds(0);
    
public:
    float angle;
    float angleRads;
    int length;
    Vec2f muzzlePos;


    Turret(int x, int y, int length);
    void update();

    Vec2f getMuzzlePosition();
    Vec2f getFiringVector();
    void fire();
    void resetCooldown();
};