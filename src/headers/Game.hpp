#pragma once
#include <SFML/Graphics.hpp>


class Game {
public:
    static sf::Clock clock;
    static float timeDelta;
    static sf::RenderWindow window;

    static void resetTimeDelta();
    
    static void init();
    static void update();
};