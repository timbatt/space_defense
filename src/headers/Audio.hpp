#pragma once

#include <SFML/Audio.hpp>

#define SOUND_LIMIT 32

class Audio {
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    Audio(const char* audioFilePath);
    Audio();

    bool isDone();
    void play();
};

class ConcurrentAudio {
private:
    int soundIndex = 0;
    Audio* sounds[SOUND_LIMIT];
    void updateSoundIndex();

public:
    ConcurrentAudio(const char* audioFilePath);
    ConcurrentAudio();
    void play();
    void load(const char* audioFilePath);
};