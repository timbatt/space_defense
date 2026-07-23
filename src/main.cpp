#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>

#include "Tower.hpp"
#include "Turret.hpp"
#include "Entities.hpp"
#include "Explosions.hpp"
#include "Enemy.hpp"

#include "Game.hpp"



int main()
{

    Game::init();
        
    Turret turret(Game::WINDOW_W / 2, Game::WINDOW_H / 2 + Game::WINDOW_H / 4, 64);
    turret.showHitbox();

    Enemy enemy(Vec2f(200, 200));
    Entities::add(enemy);

    /* Main Loop */
    while (Game::window.isOpen())
    {
        /* Events */
        sf::Event event;
        while (Game::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                Game::window.close();
                Entities::clear();
            }
        }

        /* Updates and display */

        Game::update();

        turret.update();
        Entities::update();
        Explosions::update();
    }
}