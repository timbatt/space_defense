#include "AudioLoader.hpp"


ConcurrentAudio AudioLoader::explosion;
ConcurrentAudio AudioLoader::ShipFire;

void AudioLoader::load() {
    explosion.load("resources/audio/shotgun.wav");
    ShipFire.load("resources/audio/turret.wav");
}