#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"




class Enemy : public Entity {
public:
    Enemy(Vec2f pos);

    void update();
};
