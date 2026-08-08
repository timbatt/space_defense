#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <string.h>
#include <iostream>

#include "Game.hpp"
#include "Entities.hpp"
#include "Particles.hpp"
#include "Turret.hpp"
#include "Enemy.hpp"



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
    Particles::init();

    Game::showHitboxes();
        
    Entities::create<Turret>(Settings::WINDOW_W / 2, Settings::WINDOW_H / 2 + Settings::WINDOW_H / 4, 64);

    

    /**
     * Test animation
     */
    // int frameSize = 16;
    // int frameCount = 7;
    // int animationTime = 75;
    // Vec2i frameStart = Vec2i(0, 0);
    // sf::Clock animationClock;

    // Entity* fire = Entities::create<Entity>(
    //     Vec2f(200, 200), Vec2f(0, 0), Vec2f(frameSize * 3, frameSize * 3), "resources/fire.png", "Fire"
    // );

    // fire->setAnimation(frameCount, frameSize, frameStart, animationTime);
    // fire->sprite.scale(Vec2f(3, 3));

    for (int i = 1; i <= 20; i++) {
        Enemy* enemy = Entities::create<Enemy>(Vec2f((50 * i) - 200, 100));
        // enemy->setAnimation(frameCount, frameSize, frameStart, animationTime);
    }

    /* Main Loop */
    while (Game::window.isOpen())
    {
        print_memory_usage();

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
        Particles::update();
    }
}