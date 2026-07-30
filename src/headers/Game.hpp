#pragma once
#include <SFML/Graphics.hpp>


class Game {
public:
    static const char* NAME;
    static int WINDOW_W;
    static int WINDOW_H;
    static int FRAME_RATE;

    static int MAX_ENTITY_COUNT;
    static int MAX_PARTICLE_COUNT;

    static sf::Clock clock;
    static float timeDelta;
    static sf::RenderWindow window;

    static void resetTimeDelta();
    
    static void init();
    static void update();
};