#pragma once
#include <SFML/Graphics.hpp>


class Settings {
public:
    static const char* NAME;
    static const int WINDOW_W;
    static const int WINDOW_H;
    static const int FRAME_RATE;

    static const int MAX_ENTITY_PER_TYPE;
    static const int MAX_PARTICLE_COUNT;
};