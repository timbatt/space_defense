#pragma once

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Particle.hpp"

class Particles
{
public:
    static std::vector<std::unique_ptr<Particle>> all;
    static int totalCount;

    static void update();
    static void clear();
    static void init();
    
    template<typename T, typename... Args>
    static T* create(Args&&... args) {
        auto particle = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = particle.get();

        Particles::all.push_back(std::move(particle));        
        
        Particles::totalCount++;

        return ptr;
    }
};
