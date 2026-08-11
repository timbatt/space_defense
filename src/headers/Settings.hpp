#pragma once

#include <SFML/Graphics.hpp>
#include "utils.hpp"

class Settings {
public:
    static json JSON;
    static std::string SETTINGS_PATH;
    static std::string NAME;
    static int WINDOW_W;
    static int WINDOW_H;
    static int FRAME_RATE;
    static int MAX_ENTITY_PER_TYPE;
    static int MAX_PARTICLE_COUNT;

    static void init();
};