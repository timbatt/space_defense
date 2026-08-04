#pragma once

#include <SFML/Audio.hpp>
#include "Audio.hpp"


class AudioLoader {
public:
    static ConcurrentAudio explosion;
    static ConcurrentAudio turretFire;

    static void load();
};