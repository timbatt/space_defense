#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

class Entities
{
public:
    static std::vector<Enemy> enemies;
    static std::vector<Bullet> bullets;
    static void update();

    static void add(Enemy enemy);
    static void add(Bullet bullet);

    static void clear();
};
