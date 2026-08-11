#pragma once

#include <SFML/Graphics.hpp>


class TextureLoader {
public:
    static sf::Texture particleTexture;
    static sf::Texture ShipTexture;
    static sf::Texture enemyTexture;
    static sf::Texture nullTexture;

    static void loadTextures();
};