#include "TextureLoader.hpp"


sf::Texture TextureLoader::particleTexture;
sf::Texture TextureLoader::enemyTexture;
sf::Texture TextureLoader::turretTexture;
sf::Texture TextureLoader::nullTexture;

void TextureLoader::loadTextures() {
    TextureLoader::particleTexture.loadFromFile("resources/particle.png");
    TextureLoader::turretTexture.loadFromFile("resources/turret.png");
    TextureLoader::enemyTexture.loadFromFile("resources/ufo.png");
}