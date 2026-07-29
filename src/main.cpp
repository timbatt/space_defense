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
    Entities::init();
        
    Entities::create<Turret>(Game::WINDOW_W / 2, Game::WINDOW_H / 2 + Game::WINDOW_H / 4, 64);
    Entities::create<Enemy>(Vec2f(200, 200));

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
        Entities::update();
        Explosions::update();
    }
}