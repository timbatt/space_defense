#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <string.h>
#include <iostream>

#include "Tower.hpp"
#include "Turret.hpp"
#include "Entities.hpp"
#include "Enemy.hpp"
#include "Game.hpp"



void print_memory_usage() {
    FILE* fp = fopen("/proc/self/status", "r");
    if (!fp) return;

    char line[128];
    while (fgets(line, sizeof(line), fp)) {
        // VmRSS tracks the actual physical RAM in use
        if (strncmp(line, "VmRSS:", 6) == 0) {
            std::cout << line;
            break;
        }
    }
    fclose(fp);
}


int main()
{

    Game::init();
    Entities::init();
        
    Entities::create<Turret>(Game::WINDOW_W / 2, Game::WINDOW_H / 2 + Game::WINDOW_H / 4, 64);

    Enemy* enemy = Entities::create<Enemy>(Vec2f(200, 200));
    


    /* Main Loop */
    while (Game::window.isOpen())
    {
        // print_memory_usage();

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
    }
}