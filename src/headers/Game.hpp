#pragma once

#include <SFML/Graphics.hpp>


class Game {
public:
    static sf::Clock clock;
    static float timeDelta;
    static sf::RenderWindow window;
    static sf::FloatRect windowViewRect;

    static bool doShowHitboxes;

    static void resetTimeDelta();
    
    static void init();
    static void update();


    static void showHitboxes();
    static void hideHitboxes();
};