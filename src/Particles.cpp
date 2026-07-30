#include <memory>
#include <iostream>
#include "Game.hpp"
#include "Particles.hpp"


std::vector<std::unique_ptr<Particle>> Particles::all;
int Particles::totalCount = 0;

void Particles::init() {
    Particles::all.reserve(Game::MAX_PARTICLE_COUNT);
}


void Particles::update() {
    for (const auto& entity : Particles::all) {
        if (entity != nullptr) entity->update();
    }


    Particles::all.erase(
    std::remove_if(Particles::all.begin(), Particles::all.end(),
        [](const std::unique_ptr<Particle>& particle) {            
            return particle == nullptr || particle->isDead();   
        }),
    Particles::all.end());

}

void Particles::clear() {
    Particles::all.clear();
}