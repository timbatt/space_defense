#include "Entities.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

std::vector<Enemy> Entities::enemies;
std::vector<Bullet> Entities::bullets;


void Entities::update() {
    for (int i = 0; i < Entities::enemies.size(); i++) {
        Enemy& enemy = Entities::enemies.at(i);
        enemy.update();
    }

    for (int i = 0; i < Entities::bullets.size(); i++) {
        Bullet& bullet = Entities::bullets.at(i);
        bullet.update(i);
    }
}


void Entities::add(Enemy enemy) {
    Entities::enemies.push_back(enemy);
}

void Entities::add(Bullet bullet) {
    Entities::bullets.push_back(bullet);
}

void Entities::clear() {
    Entities::enemies.clear();
    Entities::bullets.clear();
}